#include "figure.h"
#include "lcd.h"

u16 i;

// ��ȡʯͷ����
void showRock(){
	for(i = 0; i < 1158; i++){
		LCD_DrawPoint(rockX[i],rockY[i]);
	}
}


// ��ȡ��������
void showScissor(){
	for(i = 0; i < 1194; i++){
		LCD_DrawPoint(scissorX[i],scissorY[i]);
	}
}


// ��ȡ������
void showPaper(){
	for(i = 0; i < 1036; i++){
		LCD_DrawPoint(paperX[i],paperY[i]);
	}
}

//// ��ȡ1����
//void showOne(){
//	for(i = 0; i < 768; i++){
//		LCD_DrawPoint(oneX[i],oneY[i]);
//	}
//}


//// ��ȡ2����
//void showTwo(){
//	for(i = 0; i < 841; i++){
//		LCD_DrawPoint(twoX[i],twoY[i]);
//	}
//}


//// ��ȡ3����
//void showThree(){
//	for(i = 0; i < 1079; i++){
//		LCD_DrawPoint(threeX[i],threeY[i]);
//	}
//}


//// ��ȡ4����
//void showFour(){
//	for(i = 0; i < 1000; i++){
//		LCD_DrawPoint(fourX[i],fourY[i]);
//	}
//}


//// ��ȡ5����
//void showFive(){
//	for(i = 0; i < 847; i++){
//		LCD_DrawPoint(fiveX[i],fiveY[i]);
//	}
//}