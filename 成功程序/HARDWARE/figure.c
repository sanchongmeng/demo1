#include "figure.h"
#include "lcd.h"

u16 i;

// 获取石头数据
void showRock(){
	for(i = 0; i < 1158; i++){
		LCD_DrawPoint(rockX[i],rockY[i]);
	}
}


// 获取剪刀数据
void showScissor(){
	for(i = 0; i < 1194; i++){
		LCD_DrawPoint(scissorX[i],scissorY[i]);
	}
}


// 获取布数据
void showPaper(){
	for(i = 0; i < 1036; i++){
		LCD_DrawPoint(paperX[i],paperY[i]);
	}
}

//// 获取1数据
//void showOne(){
//	for(i = 0; i < 768; i++){
//		LCD_DrawPoint(oneX[i],oneY[i]);
//	}
//}


//// 获取2数据
//void showTwo(){
//	for(i = 0; i < 841; i++){
//		LCD_DrawPoint(twoX[i],twoY[i]);
//	}
//}


//// 获取3数据
//void showThree(){
//	for(i = 0; i < 1079; i++){
//		LCD_DrawPoint(threeX[i],threeY[i]);
//	}
//}


//// 获取4数据
//void showFour(){
//	for(i = 0; i < 1000; i++){
//		LCD_DrawPoint(fourX[i],fourY[i]);
//	}
//}


//// 获取5数据
//void showFive(){
//	for(i = 0; i < 847; i++){
//		LCD_DrawPoint(fiveX[i],fiveY[i]);
//	}
//}