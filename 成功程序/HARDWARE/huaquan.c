#include "huaquan.h"
#include "sys.h"
#include "stdio.h"
#include "key.h"
#include "lcd.h"
#include "FDC2214.h"

//18个训练值
u32 back0_hq[10][8],back1_hq[10][8],back2_hq[10][8];
u32 data_a0_hq[10][8],data_a1_hq[10][8],data_a2_hq[10][8];
u32 data_b0_hq[10][8],data_b1_hq[10][8],data_b2_hq[10][8];
u32 data_c0_hq[10][8],data_c1_hq[10][8],data_c2_hq[10][8];
u32 data_d0_hq[10][8],data_d1_hq[10][8],data_d2_hq[10][8];
u32 data_e0_hq[10][8],data_e1_hq[10][8],data_e2_hq[10][8];
//1个测试值
u32 test_data_hq[8];
u16 j,p;

// 划拳函数
void Huaquan()
{
	float distance[12];
	u8 item;
	char *str;
	
	printf("Get in Huaquan...\r\n");
	
	Ges_Train_hq(); // 进入训练
	delay_ms(1000);
	
LCD_Fill(5,5,235,315,0xDFFF);
//	LCD_ShowString(20,60,200,16,16,(u8*)"===== Judge caiquan =====");
	LCD_ShowString(20,80,200,16,16,(u8*)"Press KEY1 to judge.");
	LCD_ShowString(20,100,200,16,16,(u8*)"Press KEY0 to exit.");
	
	while(KEY0!=0){
		
		if(KEY1==0){
			delay_ms(300);
		
			// 进入测试
			FDC2214_GetData_hq(5,0);	
				
			//计算距离
			calculate_proc_hq(distance);
				
			//排序
			item=Bubble_sort3_hq(distance);
				
			//显示结果
			printf("SORT : %d" , item);
		
			LCD_Fill(5,120,235,315,0xDFFF);
			if(item==1){showOne();}
			else if(item==2){showTwo();}
			else if(item==3){showThree();}
			else if(item==4){showFour();}
			else if(item==5){showFive();}
			else if(item==-1){LCD_Fill(5,120,235,315,0xDFFF);}
		}
	}
				
}


// 训练手势函数
void Ges_Train_hq()
{
	u8 train_time,ges_time;
	char *str;
	
	printf("Get in Train...\r\n");
	
	//获取背景值
	FDC2214_GetData_hq(6,0);
	FDC2214_GetData_hq(6,1);
	FDC2214_GetData_hq(6,2);
	
	// 训练1
	LCD_Fill(5,60,235,200,0xDFFF);
	LCD_ShowString(20,60,200,16,16,(u8*)"Key1 gesture 1");
	while(KEY_Scan(0) != KEY1_PRES);
	delay_ms(600);
	FDC2214_GetData_hq(0,0);
//	LCD_Fill(5,80,235,200,0xDFFF);
//	LCD_ShowString(20,80,200,16,16,(u8*)"1 1 Done!");
//	delay_ms(1000);
//	
	LCD_Fill(5,80,235,200,0xDFFF);
	LCD_ShowString(20,80,200,16,16,(u8*)"Key1 The second time");
	while(KEY_Scan(0) != KEY1_PRES);
	delay_ms(600);
	FDC2214_GetData_hq(0,1);
//	LCD_Fill(5,80,235,200,0xDFFF);
//	LCD_ShowString(20,80,200,16,16,(u8*)"1 2 Done!");
//	delay_ms(1000);
	
	LCD_Fill(5,100,235,200,0xDFFF);
	LCD_ShowString(20,100,200,16,16,(u8*)"Key1 The third time");
	while(KEY_Scan(0) != KEY1_PRES);
	delay_ms(600);
	FDC2214_GetData_hq(0,2);
//	LCD_Fill(5,80,235,200,0xDFFF);
//	LCD_ShowString(20,80,200,16,16,(u8*)"1 3 Done!");
//	delay_ms(1000);
	
	// 训练2
	LCD_Fill(5,60,235,200,0xDFFF);
	LCD_ShowString(20,60,200,16,16,(u8*)"Key1 gesture 2");
	while(KEY_Scan(0) != KEY1_PRES);
	delay_ms(600);
	FDC2214_GetData_hq(1,0);
//	LCD_Fill(5,80,235,200,0xDFFF);
//	LCD_ShowString(20,80,200,16,16,(u8*)"2 1 Done!");
//	delay_ms(1000);
	
	LCD_Fill(5,80,235,200,0xDFFF);
	LCD_ShowString(20,80,200,16,16,(u8*)"Key1 The second time");
	while(KEY_Scan(0) != KEY1_PRES);
	delay_ms(600);
	FDC2214_GetData_hq(1,1);
//	LCD_Fill(5,80,235,200,0xDFFF);
//	LCD_ShowString(20,80,200,16,16,(u8*)"2 2 Done!");
//	delay_ms(1000);
	
	LCD_Fill(5,100,235,200,0xDFFF);
	LCD_ShowString(20,100,200,16,16,(u8*)"Key1 The third time");
	while(KEY_Scan(0) != KEY1_PRES);
	delay_ms(600);
	FDC2214_GetData_hq(1,2);
//	LCD_Fill(5,80,235,200,0xDFFF);
//	LCD_ShowString(20,80,200,16,16,(u8*)"2 3 Done!");
//	delay_ms(1000);
	
	// 训练3
	LCD_Fill(5,60,235,200,0xDFFF);
	LCD_ShowString(20,60,200,16,16,(u8*)"Key1 gesture 3");
	while(KEY_Scan(0) != KEY1_PRES);
	delay_ms(600);
	FDC2214_GetData_hq(2,0);
//	LCD_Fill(5,80,235,200,0xDFFF);
//	LCD_ShowString(20,80,200,16,16,(u8*)"3 1 Done!");
//	delay_ms(1000);
//	
	LCD_Fill(5,80,235,200,0xDFFF);
	LCD_ShowString(20,80,200,16,16,(u8*)"Key1 The second time");
	while(KEY_Scan(0) != KEY1_PRES);
	delay_ms(600);
	FDC2214_GetData_hq(2,1);
//	LCD_Fill(5,80,235,200,0xDFFF);
//	LCD_ShowString(20,80,200,16,16,(u8*)"3 2 Done!");
//	delay_ms(1000);
	
	LCD_Fill(5,100,235,200,0xDFFF);
	LCD_ShowString(20,100,200,16,16,(u8*)"Key1 The third time");
	while(KEY_Scan(0) != KEY1_PRES);
	delay_ms(600);
	FDC2214_GetData_hq(2,2);
//	LCD_Fill(5,80,235,200,0xDFFF);
//	LCD_ShowString(20,80,200,16,16,(u8*)"3 3 Done!");
//	delay_ms(1000);
	
	// 训练4
	LCD_Fill(5,60,235,200,0xDFFF);
	LCD_ShowString(20,60,200,16,16,(u8*)"Key1 gesture 4");
	while(KEY_Scan(0) != KEY1_PRES);
	delay_ms(600);
	FDC2214_GetData_hq(3,0);
//	LCD_Fill(5,80,235,200,0xDFFF);
//	LCD_ShowString(20,80,200,16,16,(u8*)"4 1 Done!");
//	delay_ms(1000);
	
	LCD_Fill(5,80,235,200,0xDFFF);
	LCD_ShowString(20,80,200,16,16,(u8*)"Key1:The second time");
	while(KEY_Scan(0) != KEY1_PRES);
	delay_ms(600);
	FDC2214_GetData_hq(3,1);
//	LCD_Fill(5,80,235,200,0xDFFF);
//	LCD_ShowString(20,80,200,16,16,(u8*)"4 2 Done!");
//	delay_ms(1000);
	
	LCD_Fill(5,100,235,200,0xDFFF);
	LCD_ShowString(20,100,200,16,16,(u8*)"Key1:The third time");
	while(KEY_Scan(0) != KEY1_PRES);
	delay_ms(600);
	FDC2214_GetData_hq(3,2);
//	LCD_Fill(5,80,235,200,0xDFFF);
//	LCD_ShowString(20,80,200,16,16,(u8*)"4 3 Done!");
//	delay_ms(1000);
	
	// 训练5
	LCD_Fill(5,60,235,200,0xDFFF);
	LCD_ShowString(20,60,200,16,16,(u8*)"Key1 gesture 5");
	while(KEY_Scan(0) != KEY1_PRES);
	delay_ms(600);
	FDC2214_GetData_hq(4,0);
//	LCD_Fill(5,80,235,200,0xDFFF);
//	LCD_ShowString(20,80,200,16,16,(u8*)"5 1 Done!");
//	delay_ms(1000);
	
	LCD_Fill(5,80,235,200,0xDFFF);
	LCD_ShowString(20,80,200,16,16,(u8*)"Key1:The second time");
	while(KEY_Scan(0) != KEY1_PRES);
	delay_ms(600);
	FDC2214_GetData_hq(4,1);
//	LCD_Fill(5,80,235,200,0xDFFF);
//	LCD_ShowString(20,80,200,16,16,(u8*)"5 2 Done!");
//	delay_ms(1000);
	
	LCD_Fill(5,100,235,200,0xDFFF);
	LCD_ShowString(20,100,200,16,16,(u8*)"Key1:The third time");
	while(KEY_Scan(0) != KEY1_PRES);
	delay_ms(600);
	FDC2214_GetData_hq(4,2);
//	LCD_Fill(5,80,235,200,0xDFFF);
//	LCD_ShowString(20,80,200,16,16,(u8*)"5 3 Done!");
//	delay_ms(1000);
//	
}


// 划拳函数获取
void FDC2214_GetData_hq(u8 ges_time,u8 train_time)
{
	
	//8个通道
	u32 ch[10][8];
	u8 i;
	
	//获取8个通道值
	if(ges_time!=5){
		for(p=0;p<10;p++){
			FDC2214_GetChannelData(slave_ADDR1,FDC2214_Channel_0, &ch[p][0]);
			printf("\r\n ch[%d] = %08x \r\n",0 ,ch[p][0]);
			FDC2214_GetChannelData(slave_ADDR1,FDC2214_Channel_1, &ch[p][1]);
			printf("\r\n ch[%d] = %08x \r\n",1 ,ch[p][1]);
			FDC2214_GetChannelData(slave_ADDR1,FDC2214_Channel_2, &ch[p][2]);
			printf("\r\n ch[%d] = %08x \r\n",2 ,ch[p][2]);
			FDC2214_GetChannelData(slave_ADDR1,FDC2214_Channel_3, &ch[p][3]);
			printf("\r\n ch[%d] = %08x \r\n",3 ,ch[p][3]);
			FDC2214_GetChannelData(slave_ADDR2,FDC2214_Channel_0, &ch[p][4]);
			printf("\r\n ch[%d] = %08x \r\n",4 ,ch[p][4]);
			FDC2214_GetChannelData(slave_ADDR2,FDC2214_Channel_1, &ch[p][5]);
			printf("\r\n ch[%d] = %08x \r\n",5 ,ch[p][5]);
			FDC2214_GetChannelData(slave_ADDR2,FDC2214_Channel_2, &ch[p][6]);
			printf("\r\n ch[%d] = %08x \r\n",6 ,ch[p][6]);
			FDC2214_GetChannelData(slave_ADDR2,FDC2214_Channel_3, &ch[p][7]);
			printf("\r\n ch[%d] = %08x \r\n",7 ,ch[p][7]);
		}
		//获取8个通道的值
//		for(p=0;p<10;p++){
//			for(i=0;i<4;i++){
//				FDC2214_GetChannelData(slave_ADDR1,FDC2214_Channel_0, &ch[p][i]);
//				printf("\r\n ch[%d] = %08x \r\n",i ,ch[p][i]);
//			}
//			for(i=0;i<4;i++){
//				FDC2214_GetChannelData(slave_ADDR2,FDC2214_Channel_0, &ch[p][i+4]);  
//				printf("\r\n ch[%d] = %08x \r\n",i+4 ,ch[p][i+4]);
//			}
//		}
	}else{
		FDC2214_GetChannelData(slave_ADDR1,FDC2214_Channel_0, &ch[0][0]);
		printf("\r\n ch[%d] = %08x \r\n",0 ,ch[0][0]);
		FDC2214_GetChannelData(slave_ADDR1,FDC2214_Channel_1, &ch[0][1]);
		printf("\r\n ch[%d] = %08x \r\n",1 ,ch[0][1]);
		FDC2214_GetChannelData(slave_ADDR1,FDC2214_Channel_2, &ch[0][2]);
		printf("\r\n ch[%d] = %08x \r\n",2 ,ch[0][2]);
		FDC2214_GetChannelData(slave_ADDR1,FDC2214_Channel_3, &ch[0][3]);
		printf("\r\n ch[%d] = %08x \r\n",3 ,ch[0][3]);
		FDC2214_GetChannelData(slave_ADDR2,FDC2214_Channel_0, &ch[0][4]);
		printf("\r\n ch[%d] = %08x \r\n",4 ,ch[0][4]);
		FDC2214_GetChannelData(slave_ADDR2,FDC2214_Channel_1, &ch[0][5]);
		printf("\r\n ch[%d] = %08x \r\n",5 ,ch[0][5]);
		FDC2214_GetChannelData(slave_ADDR2,FDC2214_Channel_2, &ch[0][6]);
		printf("\r\n ch[%d] = %08x \r\n",6 ,ch[0][6]);
		FDC2214_GetChannelData(slave_ADDR2,FDC2214_Channel_3, &ch[0][7]);
		printf("\r\n ch[%d] = %08x \r\n",7 ,ch[0][7]);
//		for(i=0;i<4;i++){
//			FDC2214_GetChannelData(slave_ADDR1,FDC2214_Channel_0, &ch[0][i]);
//			printf("\r\n ch[%d] = %08x \r\n",i ,ch[0][i]);
//		}
//		for(i=0;i<4;i++){
//			FDC2214_GetChannelData(slave_ADDR2,FDC2214_Channel_0, &ch[0][i+4]);  
//			printf("\r\n ch[%d] = %08x \r\n",i+4 ,ch[0][i+4]);
//		}
	}
	
	//存储
	if(ges_time==0){
		switch(train_time)
		{
			case 0:	for(i=0;i<8;i++) for(p=0;p<10;p++)data_a0_hq[p][i]=ch[p][i]; break;
			case 1:	for(i=0;i<8;i++) for(p=0;p<10;p++)data_a1_hq[p][i]=ch[p][i]; break;
			case 2:	for(i=0;i<8;i++) for(p=0;p<10;p++)data_a2_hq[p][i]=ch[p][i]; break;
			default: LCD_ShowString(0,0,240,10,10,"traning time segmen fault... "); break;
		}
	}else if(ges_time==1){	
		switch(train_time)
		{
			case 0:	for(i=0;i<8;i++) for(p=0;p<10;p++)data_b0_hq[p][i]=ch[p][i]; break;
			case 1:	for(i=0;i<8;i++) for(p=0;p<10;p++)data_b1_hq[p][i]=ch[p][i]; break;
			case 2:	for(i=0;i<8;i++) for(p=0;p<10;p++)data_b2_hq[p][i]=ch[p][i]; break;
			default: LCD_ShowString(0,0,240,10,10,"traning time segmen fault... "); break;
		}
	}else if(ges_time==2){
		switch(train_time)
		{
			case 0:	for(i=0;i<8;i++) for(p=0;p<10;p++)data_c0_hq[p][i]=ch[p][i]; break;
			case 1:	for(i=0;i<8;i++) for(p=0;p<10;p++)data_c1_hq[p][i]=ch[p][i]; break;
			case 2:	for(i=0;i<8;i++) for(p=0;p<10;p++)data_c2_hq[p][i]=ch[p][i]; break;
			default: LCD_ShowString(0,0,240,10,10,"traning time segmen fault... "); break;
		}
	}else if(ges_time==3){
		switch(train_time)
		{
			case 0:	for(i=0;i<8;i++) for(p=0;p<10;p++)data_d0_hq[p][i]=ch[p][i]; break;
			case 1:	for(i=0;i<8;i++) for(p=0;p<10;p++)data_d1_hq[p][i]=ch[p][i]; break;
			case 2:	for(i=0;i<8;i++) for(p=0;p<10;p++)data_d2_hq[p][i]=ch[p][i]; break;
			default: LCD_ShowString(0,0,240,10,10,"traning time segmen fault... "); break;
		}
	}else if(ges_time==4){
		switch(train_time)
		{
			case 0:	for(i=0;i<8;i++) for(p=0;p<10;p++)data_e0_hq[p][i]=ch[p][i]; break;
			case 1:	for(i=0;i<8;i++) for(p=0;p<10;p++)data_e1_hq[p][i]=ch[p][i]; break;
			case 2:	for(i=0;i<8;i++) for(p=0;p<10;p++)data_e2_hq[p][i]=ch[p][i]; break;
			default: LCD_ShowString(0,0,240,10,10,"traning time segmen fault... "); break;
		}
	}else if(ges_time==5){
		printf("\r\n JUDGE MODE\r\n");
		for(i=0;i<8;i++) test_data_hq[i]=ch[0][i];
	}else if(ges_time==6){
		switch(train_time)
		{
			case 0:	for(i=0;i<8;i++) for(p=0;p<10;p++)back0_hq[p][i]=ch[p][i]; break;
			case 1:	for(i=0;i<8;i++) for(p=0;p<10;p++)back1_hq[p][i]=ch[p][i]; break;
			case 2:	for(i=0;i<8;i++) for(p=0;p<10;p++)back2_hq[p][i]=ch[p][i]; break;
			default: LCD_ShowString(0,0,240,10,10,"traning time segmen fault... "); break;
		}
	}
}


// 排序
u8 Bubble_sort3_hq(float data[])
{
	u8 i,j;
	float temp;
	u8 temp_order;
	u8 order[180] = {0,0,0,1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,0,0,0,1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,0,0,0,1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,0,0,0,1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,0,0,0,1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,0,0,0,1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,0,0,0,1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,0,0,0,1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,0,0,0,1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,0,0,0,1,1,1,2,2,2,3,3,3,4,4,4,5,5,5};
	u8 a=0,b=0,c=0,d=0,e=0,back=0;
	
	for(i = 0; i < 180; i++)
	{
		for(j = 0; j < 180 - i; j++)
		{
			if(data[j]>data[j+1])
			{	
				temp = data[j];			
				data[j]= data[j+1];			
				data[j+1] = temp;
				
				temp_order = order[j];			
				order[j]= order[j+1];			
				order[j+1] = temp_order;
			}
		}
	}
	
	printf("\r\n \r\n");
	
	for(i = 0 ; i < 48 ; i++)
		printf(" %d ",order[i]);
	
	for(i=0;i<48;i++)
	{
			switch(order[i])
			{
				case 0: a+=1;break;
				case 1:	b+=1;break;
				case 2:	c+=1;break;
				case 3:	d+=1;break;
				case 4:	e+=1;break;
				case 5:	back+=1;break;
			}
			if(a>=8) return 1;
			else if(b>=8) return 2;
			else if(c>=8) return 3;
			else if(d>=8) return 4;
			else if(e>=8) return 5;
			else if(back>=8) return -1;
	}
	
	return -1;
}


void calculate_proc_hq(float distance[])
{
	for(j=0,p=0;p<10;p++){
		distance[j++]=l2_distance_hq(test_data_hq,data_a0_hq[p]);
		distance[j++]=l2_distance_hq(test_data_hq,data_a1_hq[p]);
		distance[j++]=l2_distance_hq(test_data_hq,data_a2_hq[p]);
		distance[j++]=l2_distance_hq(test_data_hq,data_b0_hq[p]);
		distance[j++]=l2_distance_hq(test_data_hq,data_b1_hq[p]);
		distance[j++]=l2_distance_hq(test_data_hq,data_b2_hq[p]);
		distance[j++]=l2_distance_hq(test_data_hq,data_c0_hq[p]);
		distance[j++]=l2_distance_hq(test_data_hq,data_c1_hq[p]);
		distance[j++]=l2_distance_hq(test_data_hq,data_c2_hq[p]);
		distance[j++]=l2_distance_hq(test_data_hq,data_d0_hq[p]);
		distance[j++]=l2_distance_hq(test_data_hq,data_d1_hq[p]);
		distance[j++]=l2_distance_hq(test_data_hq,data_d2_hq[p]);
		distance[j++]=l2_distance_hq(test_data_hq,data_e0_hq[p]);
		distance[j++]=l2_distance_hq(test_data_hq,data_e1_hq[p]);
		distance[j++]=l2_distance_hq(test_data_hq,data_e2_hq[p]);
		distance[j++]=l2_distance_hq(test_data_hq,back0_hq[p]);
		distance[j++]=l2_distance_hq(test_data_hq,back1_hq[p]);
		distance[j++]=l2_distance_hq(test_data_hq,back2_hq[p]);
	}
}

float l2_distance_hq(u32 x[],u32 y[])
{
	
	float result=0;
    result += (x[0]-y[0]) * (x[0]-y[0]) * 0.25;
    result += (x[1]-y[1]) * (x[1]-y[1]) * 0.25;
    result += (x[2]-y[2]) * (x[2]-y[2]) * 0.5;
    result += (x[3]-y[3]) * (x[3]-y[3]) * 0.5;
    result += (x[4]-y[4]) * (x[4]-y[4]) * 0.5;
    result += (x[5]-y[5]) * (x[5]-y[5]);
    result += (x[6]-y[6]) * (x[6]-y[6]);
    result += (x[7]-y[7]) * (x[7]-y[7]);
	
    return result;

}

// 获取1数据
void showOne(){
	for(j = 0; j < 768; j++){
		LCD_DrawPoint(oneX[j],oneY[j]+80);
	}
}


// 获取2数据
void showTwo(){
	for(j = 0; j < 841; j++){
		LCD_DrawPoint(twoX[j],twoY[j]+80);
	}
}


// 获取3数据
void showThree(){
	for(j = 0; j < 1079; j++){
		LCD_DrawPoint(threeX[j],threeY[j]+80);
	}
}


// 获取4数据
void showFour(){
	for(j = 0; j < 1000; j++){
		LCD_DrawPoint(fourX[j],fourY[j]+80);
	}
}


// 获取5数据
void showFive(){
	for(j = 0; j < 847; j++){
		LCD_DrawPoint(fiveX[j],fiveY[j]+80);
	}
}
