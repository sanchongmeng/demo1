#include "mydraw.h"
#include "lcd.h"

// 自己写的，画图
void DrawColorLineX(u16 x1,u16 y1,u16 x2, u16 y2){
	for(;x1<x2;x1+=40){
		LCD_Fill(x1,y1,x1+40,y2,BLUE);
		x1+=40;
		LCD_Fill(x1,y1,x1+40,y2,RED);
	}
}


// 自己写的，画图
void DrawColorLineY(u16 x1,u16 y1,u16 x2, u16 y2){
	for(;y1<y2;y1+=40){
		LCD_Fill(x1,y1,x2,y1+40,BLUE);
		y1+=40;
		LCD_Fill(x1,y1,x2,y1+40,RED);
	}
}


// 画图
void Draw(){
	LCD_Fill(0,0,240,320,0xDFFF);
	DrawColorLineX(0,0,240,5);
	DrawColorLineY(0,0,5,320);
	DrawColorLineX(0,315,240,320);
	DrawColorLineY(235,0,240,320);
	POINT_COLOR=RED;
}	