#include "traffic_light.h"

extern uint8_t east_flag;
extern uint8_t west_flag;
extern uint8_t south_flag;
extern uint8_t north_flag;
extern uint8_t check_flag;
extern int east_count;
extern int west_count;
extern int south_count;
extern int north_count;

uint8_t east_red_flag;
uint8_t west_red_flag;
uint8_t south_red_flag;
uint8_t north_red_flag;

//东西红灯、南北绿灯
void traffic_light_east_west(void){
    east_red_flag = 1;
    west_red_flag = 1;
    south_red_flag = 0;
    north_red_flag = 0;
    for(int i = 0; i < 10000; i++){
        //东西黄灯灭
        HAL_GPIO_WritePin(east_yellow_GPIO_Port, east_yellow_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(west_yellow_GPIO_Port, west_yellow_Pin, GPIO_PIN_SET);
        //东西红灯亮
        HAL_GPIO_WritePin(east_red_GPIO_Port, east_red_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(west_red_GPIO_Port, west_red_Pin, GPIO_PIN_RESET);
        //南北红灯灭
        HAL_GPIO_WritePin(south_red_GPIO_Port, south_red_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(north_red_GPIO_Port, north_red_Pin, GPIO_PIN_SET);
        //南北绿灯亮
        HAL_GPIO_WritePin(south_green_GPIO_Port, south_green_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(north_green_GPIO_Port, north_green_Pin, GPIO_PIN_RESET);
        if(east_flag == 1){
        east_flag = 0;
        Nixie_east_run();
        }
        if(west_flag == 1){
        west_flag = 0;
        Nixie_west_run();
        }
        if(south_flag == 1){
        south_flag = 0;
        Nixie_south_run();
        }
        if(north_flag == 1){
        north_flag = 0;
        Nixie_north_run();
        }
        if(check_flag == 1){
        check_flag = 0;
        Nixie_display_count(east_count, west_count, south_count, north_count);
        }
        HAL_Delay(1);   
    }
}

//东西红灯、南北黄灯
void traffic_light_east_west_to_south_north(void){
    east_red_flag = 1;
    west_red_flag = 1;
    south_red_flag = 0;
    north_red_flag = 0;
    //南北绿灯灭
    HAL_GPIO_WritePin(south_green_GPIO_Port, south_green_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(north_green_GPIO_Port, north_green_Pin, GPIO_PIN_SET); 
    //南北向黄灯闪烁3次
    for(unsigned char i = 0; i < 3; i++){
        for(int j = 0; j < 500; j++){
            HAL_GPIO_WritePin(south_yellow_GPIO_Port, south_yellow_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(north_yellow_GPIO_Port, north_yellow_Pin, GPIO_PIN_RESET);
            if(east_flag == 1){
            east_flag = 0;
            Nixie_east_run();
            }
            if(west_flag == 1){
            west_flag = 0;
            Nixie_west_run();
            }
            if(south_flag == 1){
            south_flag = 0;
            Nixie_south_run();
            }
            if(north_flag == 1){
            north_flag = 0;
            Nixie_north_run();
            }
            if(check_flag == 1){
            check_flag = 0;
            Nixie_display_count(east_count, west_count, south_count, north_count);
            }
            HAL_Delay(1); 
        }
        for(int j = 0; j < 500; j++){
            HAL_GPIO_WritePin(south_yellow_GPIO_Port, south_yellow_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(north_yellow_GPIO_Port, north_yellow_Pin, GPIO_PIN_SET);
            if(east_flag == 1){
            east_flag = 0;
            Nixie_east_run();
            }
            if(west_flag == 1){
            west_flag = 0;
            Nixie_west_run();
            }
            if(south_flag == 1){
            south_flag = 0;
            Nixie_south_run();
            }
            if(north_flag == 1){
            north_flag = 0;
            Nixie_north_run();
            }
            if(check_flag == 1){
            check_flag = 0;
            Nixie_display_count(east_count, west_count, south_count, north_count);
            }
            HAL_Delay(1);
        } 
    }
}

//东西绿灯、南北红灯
void traffic_light_south_north(void){
    east_red_flag = 0;
    west_red_flag = 0;
    south_red_flag = 1;
    north_red_flag = 1;
    for(int i = 0; i < 10000; i++){
    //南北黄灯灭
    HAL_GPIO_WritePin(south_yellow_GPIO_Port, south_yellow_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(north_yellow_GPIO_Port, north_yellow_Pin, GPIO_PIN_SET);
    //南北红灯亮
    HAL_GPIO_WritePin(south_red_GPIO_Port, south_red_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(north_red_GPIO_Port, north_red_Pin, GPIO_PIN_RESET);
    //东西红灯灭
    HAL_GPIO_WritePin(east_red_GPIO_Port, east_red_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(west_red_GPIO_Port, west_red_Pin, GPIO_PIN_SET);
    //东西绿灯亮
    HAL_GPIO_WritePin(east_green_GPIO_Port, east_green_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(west_green_GPIO_Port, west_green_Pin, GPIO_PIN_RESET);   
    HAL_Delay(1);
    if(east_flag == 1){
    east_flag = 0;
    Nixie_east_run();
    }
    if(west_flag == 1){
    west_flag = 0;
    Nixie_west_run();
    }
    if(south_flag == 1){
    south_flag = 0;
    Nixie_south_run();
    }
    if(north_flag == 1){
    north_flag = 0;
    Nixie_north_run();
    }
    if(check_flag == 1){
    check_flag = 0;
    Nixie_display_count(east_count, west_count, south_count, north_count);
    }
    }
}

//东西黄灯、南北红灯
void traffic_light_south_north_to_east_west(void){
    east_red_flag = 0;
    west_red_flag = 0;
    south_red_flag = 1;
    north_red_flag = 1;
    //东西绿灯灭
    HAL_GPIO_WritePin(east_green_GPIO_Port, east_green_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(west_green_GPIO_Port, west_green_Pin, GPIO_PIN_SET); 
    //东西向黄灯闪烁3次
    for(unsigned char i = 0; i < 3; i++){
        for(int j = 0; j < 500; j++){
            HAL_GPIO_WritePin(east_yellow_GPIO_Port, east_yellow_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(west_yellow_GPIO_Port, west_yellow_Pin, GPIO_PIN_RESET);
            HAL_Delay(1);
            if(east_flag == 1){
            east_flag = 0;
            Nixie_east_run();
            }
            if(west_flag == 1){
            west_flag = 0;
            Nixie_west_run();
            }
            if(south_flag == 1){
            south_flag = 0;
            Nixie_south_run();
            }
            if(north_flag == 1){
            north_flag = 0;
            Nixie_north_run();
            if(check_flag == 1){
            check_flag = 0;
            Nixie_display_count(east_count, west_count, south_count, north_count);
            }
            }
        } 
        for(int j = 0; j < 500; j++){
            HAL_GPIO_WritePin(east_yellow_GPIO_Port, east_yellow_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(west_yellow_GPIO_Port, west_yellow_Pin, GPIO_PIN_SET);
            if(east_flag == 1){
            east_flag = 0;
            Nixie_east_run();
            }
            if(west_flag == 1){
            west_flag = 0;
            Nixie_west_run();
            }
            if(south_flag == 1){
            south_flag = 0;
            Nixie_south_run();
            }
            if(north_flag == 1){
            north_flag = 0;
            Nixie_north_run();
            }
            if(check_flag == 1){
            check_flag = 0;
            Nixie_display_count(east_count, west_count, south_count, north_count);
            }
            HAL_Delay(1);
        } 
    }
}

void traffic_light_loop(void){
    traffic_light_east_west();
    traffic_light_east_west_to_south_north();
    traffic_light_south_north();
    traffic_light_south_north_to_east_west();
}

