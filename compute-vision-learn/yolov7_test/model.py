import torch
import torch.nn as nn
import torch.optim as optim

def autopad(k, p=None):
    if p is None:
        p = k // 2 if isinstance(k, int) else [x // 2 for x in k]
    return p

class SiLU(nn.Module):
    @staticmethod
    def forward(x):
        return x * torch.sigmoid(x)

class Conv(nn.Module):
    def __init__(self, c1, c2, k=1, s=1, p=None, g=1, bias=False,
                 act=SiLU()):
        super(Conv, self).__init__()
        self.conv = nn.Conv2d(c1, c2, k, s, autopad(k, p),
                              groups=g, bias=bias)
        self.bn = nn.BatchNorm2d(c2, eps=0.001, momentum=0.03)
        self.activation = nn.LeakyReLU(0.1, inplace=True) if act is True else \
            (act if isinstance(act, nn.Module) else nn.Identity())

    def forward(self, x):
        return self.activation(self.bn(self.conv(x)))

    def fuseforward(self, x):
        return self.activation(self.conv(x))


class Multi_Concat_Block(nn.Module):
    def __init__(self, c1, c2, c3, n=4, e=1, ids=None):
        super(Multi_Concat_Block, self).__init__()
        if ids is None:
            ids = [0]
        c_ = int(c2 * e)

        self.ids = ids
        self.cv1 = Conv(c1, c_, 1, 1)
        self.cv2 = Conv(c1, c_, 1, 1)
        self.cv3 = nn.ModuleList([Conv(c_ if i == 0 else c2, c2, 3, 1) for i in range(n)])
        self.cv4 = Conv(c_ * 2 + c2 * (len(ids) - 2), c3, 1, 1)

    def forward(self, x):
        x_1 = self.cv1(x)
        x_2 = self.cv2(x)
        x_all = [x_1, x_2]
        for i in range(len(self.cv3)):
            x_2 = self.cv3[i](x_2)
            x_all.append(x_2)

        out = self.cv4(torch.cat([x_all[id] for id in self.ids], 1))
        return out


e = 1
n = 6
ids = [-1, -3, -5, -7, -8]
image = torch.rand(1, 160, 80, 80)
test_model = Multi_Concat_Block(160, 160, 128, n=n, e=e, ids=ids)
# print(test_model)
# print(image.shape)
print(test_model(image).shape)