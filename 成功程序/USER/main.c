#include "delay.h"
#include "sys.h"
#include "stdio.h"
#include "usart.h"
#include "FDC2214.h"
#include "key.h"
#include "led.h"
#include "lcd.h"
// 已经引入
//#include "mydraw.h"
//#include "caiquan.h"
//#include "huaquan.h"

u8 flag=0;
u32 ch0,ch1,ch2,ch3,ch4,ch5,ch6,ch7;

// FDC2214获取数据
void FDC2214_GetData2(void)
{
  FDC2214_GetChannelData(slave_ADDR1,FDC2214_Channel_0, &ch0); 
  FDC2214_GetChannelData(slave_ADDR1,FDC2214_Channel_1, &ch1);
  FDC2214_GetChannelData(slave_ADDR1,FDC2214_Channel_2, &ch2);
  FDC2214_GetChannelData(slave_ADDR1,FDC2214_Channel_3, &ch3);
	FDC2214_GetChannelData(slave_ADDR2,FDC2214_Channel_0, &ch4);
  FDC2214_GetChannelData(slave_ADDR2,FDC2214_Channel_1, &ch5);
  FDC2214_GetChannelData(slave_ADDR2,FDC2214_Channel_2, &ch6);
  FDC2214_GetChannelData(slave_ADDR2,FDC2214_Channel_3, &ch7);
}

int main(void)
{		 
	u8 key_mode;
	u8 pic_num = -1;
	 
	delay_init();
	uart_init(9600);	 
	KEY_Init();
	IIC_Init();
	FDC2214_Init(slave_ADDR1);
	FDC2214_Init(slave_ADDR2);
	LCD_Init();
	LED_Init();
	//Draw();
	 
	POINT_COLOR=RED;
	LCD_ShowString(16,40,200,24,24,(u8*)"WELCOME TO TRAIN");	
//	LCD_ShowString(30,80,200,16,16,(u8*)"KEY1: Caiquan Model");
//	LCD_ShowString(30,100,200,16,16,(u8*)"KEY0: Huaquan Model");
		LCD_ShowString(20,60,300,16,16,"Press keys to select mode ");
	LCD_ShowString(16,80,310,16,16,"Key0:caiquan  Key1:Huaquan");
	 
//	while(0){
//		FDC2214_GetData2();
//		printf("%d %d %d %d %d %d %d %d\r\n",ch0,ch1,ch2,ch3,ch4,ch5,ch6,ch7);
//		delay_ms(100);
//	}
		
	while(1){
		
		
		
		if(WK_UP==1){ // 判决模式
			
			if(flag==0){ // 猜拳模式
				
				flag=1;
				LCD_Fill(5,5,235,315,0xDFFF);
				LCD_ShowString(20,60,200,16,16,(u8*)"===== Judge caiquan =====");
				LCD_ShowString(20,80,200,16,16,(u8*)"Press KEY0 to judge.");
				LCD_ShowString(20,100,200,16,16,(u8*)"Press KEY1 to exit.");
				testCaiquan();
				LCD_ShowString(96,30,200,24,24,(u8*)"WELCOME");	
				LCD_ShowString(30,60,200,16,16,(u8*)"WK_UP: Judge Model");
				LCD_ShowString(30,80,200,16,16,(u8*)"KEY1: Caiquan Model");
				LCD_ShowString(30,100,200,16,16,(u8*)"KEY0: Huaquan Model");
				delay_ms(1000);
				
			}else{
				flag=0;
				
			}
		}else if(KEY0==0){ // 猜拳训练判决模式
			
			delay_ms(100);
			LCD_Fill(5,5,235,315,0xDFFF);
//			LCD_ShowString(20,60,200,16,16,(u8*)"===== Train caiquan =====");
			Caiquan();
			LCD_ShowString(96,30,200,24,24,(u8*)"WELCOME");	
			LCD_ShowString(30,60,200,16,16,(u8*)"WK_UP: Judge Model");
			LCD_ShowString(30,80,200,16,16,(u8*)"KEY1: Caiquan Model");
			LCD_ShowString(30,100,200,16,16,(u8*)"KEY0: Huaquan Model");
			delay_ms(1000);
			
		}else if(KEY1==0){ // 划拳训练判决模式
			
			delay_ms(100);
			LCD_Fill(5,5,235,315,0xDFFF);
			//LCD_ShowString(20,60,200,16,16,(u8*)"===== Train huaquan =====");
			Huaquan();
			LCD_ShowString(96,30,200,24,24,(u8*)"WELCOME TO TEST");	
		//	LCD_ShowString(30,60,200,16,16,(u8*)"WK_UP: Judge Model");
//			LCD_ShowString(30,80,200,16,16,(u8*)"KEY1: Caiquan Model");
//			LCD_ShowString(30,100,200,16,16,(u8*)"KEY0: Huaquan Model");
				LCD_ShowString(15,80,310,16,16,"Key0:caiquan  Key1:Huaquan");
			delay_ms(1000);
			
		}
		delay_ms(10);			
	}
}
 



