import torch
import torch.nn as nn
import time

def main():
    test_tensor = torch.rand((1, 1, 7, 7))
    conv1 = nn.Conv2d(in_channels=1, out_channels=1, kernel_size=3, stride=1, bias=False)
    conv2 = nn.Conv2d(in_channels=1, out_channels=1, kernel_size=3, stride=1, bias=False)
    conv3 = nn.Conv2d(in_channels=1, out_channels=1, kernel_size=3, stride=1, bias=False)
    conv4 = nn.Conv2d(in_channels=1, out_channels=1, kernel_size=7, stride=1, bias=False)
    # W = weight1 = conv1.weight[0][0]
    # P = weight2 = conv2.weight[0][0]
    # print(weight1.shape)
    # print(weight2.shape)
    # new_weight = torch.zeros(1, 1, 5, 5)
    # for i in range(5):
    #     for j in range(5):
    #         for x in range(i):
    #             for y in range(j):
    #                 new_weight[i][j] += W[x][y] * P[(i + j) - x][y]
    a = time.time()
    test1 = conv3(conv2(conv1(test_tensor)))
    b = time.time()
    print(b - a)
    c = time.time()
    test2 = conv4(test_tensor)
    d = time.time()
    print(d - c)


if __name__ == '__main__':
    main()

