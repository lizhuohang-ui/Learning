#include "nixie.h"

unsigned char table[11] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f, 0x40};


void Nixie_display(int num){
    if((table[num] >> 0) & 0x01){HAL_GPIO_WritePin(nixie_A_GPIO_Port, nixie_A_Pin, GPIO_PIN_SET);}else{HAL_GPIO_WritePin(nixie_A_GPIO_Port, nixie_A_Pin, GPIO_PIN_RESET);}
    if((table[num] >> 1) & 0x01){HAL_GPIO_WritePin(nixie_B_GPIO_Port, nixie_B_Pin, GPIO_PIN_SET);}else{HAL_GPIO_WritePin(nixie_B_GPIO_Port, nixie_B_Pin, GPIO_PIN_RESET);}
    if((table[num] >> 2) & 0x01){HAL_GPIO_WritePin(nixie_C_GPIO_Port, nixie_C_Pin, GPIO_PIN_SET);}else{HAL_GPIO_WritePin(nixie_C_GPIO_Port, nixie_C_Pin, GPIO_PIN_RESET);}
    if((table[num] >> 3) & 0x01){HAL_GPIO_WritePin(nixie_D_GPIO_Port, nixie_D_Pin, GPIO_PIN_SET);}else{HAL_GPIO_WritePin(nixie_D_GPIO_Port, nixie_D_Pin, GPIO_PIN_RESET);}
    if((table[num] >> 4) & 0x01){HAL_GPIO_WritePin(nixie_E_GPIO_Port, nixie_E_Pin, GPIO_PIN_SET);}else{HAL_GPIO_WritePin(nixie_E_GPIO_Port, nixie_E_Pin, GPIO_PIN_RESET);}
    if((table[num] >> 5) & 0x01){HAL_GPIO_WritePin(nixie_F_GPIO_Port, nixie_F_Pin, GPIO_PIN_SET);}else{HAL_GPIO_WritePin(nixie_F_GPIO_Port, nixie_F_Pin, GPIO_PIN_RESET);}
    if((table[num] >> 6) & 0x01){HAL_GPIO_WritePin(nixie_G_GPIO_Port, nixie_G_Pin, GPIO_PIN_SET);}else{HAL_GPIO_WritePin(nixie_G_GPIO_Port, nixie_G_Pin, GPIO_PIN_RESET);}
}

void Nixie_east_run(void){
  HAL_GPIO_WritePin(nixie_1_GPIO_Port, nixie_1_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(nixie_2_GPIO_Port, nixie_2_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(nixie_3_GPIO_Port, nixie_3_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(nixie_4_GPIO_Port, nixie_4_Pin, GPIO_PIN_SET);
  Nixie_display(10);
  HAL_Delay(200);
  HAL_GPIO_WritePin(nixie_1_GPIO_Port, nixie_1_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(nixie_2_GPIO_Port, nixie_2_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(nixie_3_GPIO_Port, nixie_3_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(nixie_4_GPIO_Port, nixie_4_Pin, GPIO_PIN_SET);
}

void Nixie_west_run(void){
  HAL_GPIO_WritePin(nixie_1_GPIO_Port, nixie_1_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(nixie_2_GPIO_Port, nixie_2_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(nixie_3_GPIO_Port, nixie_3_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(nixie_4_GPIO_Port, nixie_4_Pin, GPIO_PIN_SET);
  Nixie_display(10);
  HAL_Delay(200);
  HAL_GPIO_WritePin(nixie_1_GPIO_Port, nixie_1_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(nixie_2_GPIO_Port, nixie_2_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(nixie_3_GPIO_Port, nixie_3_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(nixie_4_GPIO_Port, nixie_4_Pin, GPIO_PIN_SET);
}

void Nixie_south_run(void){
  HAL_GPIO_WritePin(nixie_1_GPIO_Port, nixie_1_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(nixie_2_GPIO_Port, nixie_2_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(nixie_3_GPIO_Port, nixie_3_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(nixie_4_GPIO_Port, nixie_4_Pin, GPIO_PIN_SET);
  Nixie_display(10);
  HAL_Delay(200);
  HAL_GPIO_WritePin(nixie_1_GPIO_Port, nixie_1_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(nixie_2_GPIO_Port, nixie_2_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(nixie_3_GPIO_Port, nixie_3_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(nixie_4_GPIO_Port, nixie_4_Pin, GPIO_PIN_SET);
}

void Nixie_north_run(void){
  HAL_GPIO_WritePin(nixie_1_GPIO_Port, nixie_1_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(nixie_2_GPIO_Port, nixie_2_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(nixie_3_GPIO_Port, nixie_3_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(nixie_4_GPIO_Port, nixie_4_Pin, GPIO_PIN_RESET);
  Nixie_display(10);
  HAL_Delay(200);
  HAL_GPIO_WritePin(nixie_1_GPIO_Port, nixie_1_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(nixie_2_GPIO_Port, nixie_2_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(nixie_3_GPIO_Port, nixie_3_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(nixie_4_GPIO_Port, nixie_4_Pin, GPIO_PIN_SET);
}

void Nixie_display_count(int east_count, int west_count, int south_count, int north_count){
    for(int i = 0; i < 10; i++){
    HAL_GPIO_WritePin(nixie_1_GPIO_Port, nixie_1_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(nixie_2_GPIO_Port, nixie_2_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(nixie_3_GPIO_Port, nixie_3_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(nixie_4_GPIO_Port, nixie_4_Pin, GPIO_PIN_SET);
    Nixie_display(east_count / 4);
    HAL_Delay(5);
    HAL_GPIO_WritePin(nixie_1_GPIO_Port, nixie_1_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(nixie_2_GPIO_Port, nixie_2_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(nixie_3_GPIO_Port, nixie_3_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(nixie_4_GPIO_Port, nixie_4_Pin, GPIO_PIN_SET);
    Nixie_display(west_count / 4);
    HAL_Delay(5);
    HAL_GPIO_WritePin(nixie_1_GPIO_Port, nixie_1_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(nixie_2_GPIO_Port, nixie_2_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(nixie_3_GPIO_Port, nixie_3_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(nixie_4_GPIO_Port, nixie_4_Pin, GPIO_PIN_SET);
    Nixie_display(south_count / 4);
    HAL_Delay(5);
    HAL_GPIO_WritePin(nixie_1_GPIO_Port, nixie_1_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(nixie_2_GPIO_Port, nixie_2_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(nixie_3_GPIO_Port, nixie_3_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(nixie_4_GPIO_Port, nixie_4_Pin, GPIO_PIN_RESET);
    Nixie_display(north_count / 4);
    HAL_Delay(5);
    }
    HAL_GPIO_WritePin(nixie_1_GPIO_Port, nixie_1_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(nixie_2_GPIO_Port, nixie_2_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(nixie_3_GPIO_Port, nixie_3_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(nixie_4_GPIO_Port, nixie_4_Pin, GPIO_PIN_SET);
}
