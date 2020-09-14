#include "caiquan.h"
#include "sys.h"
#include "stdio.h"
#include "key.h"
#include "lcd.h"
#include "FDC2214.h"

// 8个通道每个通道采集10次
u32 back0[10][8],back1[10][8],back2[10][8];
u32 data_a0[10][8],data_a1[10][8],data_a2[10][8];
u32 data_b0[10][8],data_b1[10][8],data_b2[10][8];
u32 data_c0[10][8],data_c1[10][8],data_c2[10][8];
//测试数据
u32 test_data[8];
u16 i,k;

// 猜拳函数
void Caiquan()
{
	float distance[12];
	u8 item;
	char *str;
	
	printf("Get in Caiquan...\r\n");
	
	Ges_Train(); // 进入训练
	delay_ms(1000);
	
	LCD_Fill(5,5,235,315,0xDFFF);
//	LCD_ShowString(20,60,200,16,16,(u8*)"===== Judge caiquan =====");
	LCD_ShowString(20,80,200,16,16,(u8*)"Press KEY1 to judge.");
	LCD_ShowString(20,100,200,16,16,(u8*)"Press KEY0 to exit.");
	
	while(KEY0!=0){
	
		if(KEY1==0){
			delay_ms(500);
		
			// 进入测试
			FDC2214_GetData(3,0);	
				
			//计算距离
			calculate_proc(distance);
				
			//排序
			item=Bubble_sort3(distance);
				
			//显示结果
			printf("SORT : %d" , item);
		
			LCD_Fill(5,120,235,315,0xDFFF);
			if(item==0){showRock();}
			else if(item==1){showScissor();}
			else if(item==2){showPaper();}
			else if(item==-1){LCD_Fill(5,120,235,315,0xDFFF);}
		}
	}
				
}


// 训练手势函数
void Ges_Train()
{
	u8 train_time,ges_time;
	char *str;
	
	printf("Get in Train...\r\n");
	
	//获取背景值
	FDC2214_GetData(4,0);
	FDC2214_GetData(4,1);
	FDC2214_GetData(4,2);
	
	printf("\r\n----5----\r\n");
	
	// 训练石头
	LCD_Fill(5,60,235,200,0xDFFF);
	LCD_ShowString(15,60,200,16,16,(u8*)"Key1 gesture 1");
	while(KEY_Scan(0) != KEY1_PRES);
	delay_ms(600);
	FDC2214_GetData(0,0);
//	LCD_Fill(5,80,235,200,0xDFFF);
//	LCD_ShowString(15,60,200,16,16,(u8*)"the second time");
//	delay_ms(1000);
//	
//	printf("\r\n----123----\r\n");
	
	LCD_Fill(5,80,235,200,0xDFFF);
	LCD_ShowString(15,80,200,16,16,(u8*)"Key1:The second time");
	while(KEY_Scan(0) != KEY1_PRES);
	delay_ms(600);
	FDC2214_GetData(0,1);
//	LCD_Fill(5,60,235,200,0xDFFF);
//	LCD_ShowString(20,60,200,16,16,(u8*)"Shitou 2 Done!");
//	delay_ms(1000);
//	
	printf("\r\n----123----\r\n");
	
	LCD_Fill(5,100,235,200,0xDFFF);
	LCD_ShowString(20,100,200,16,16,(u8*)"Key1:The third time");
	while(KEY_Scan(0) != KEY1_PRES);
	delay_ms(600);
	FDC2214_GetData(0,2);
//	LCD_Fill(5,80,235,200,0xDFFF);
//	LCD_ShowString(20,80,200,16,16,(u8*)"Shitou 3 Done!");
//	delay_ms(1000);
	
	printf("\r\n----5----\r\n");
	
	// 训练剪刀
	LCD_Fill(5,60,235,200,0xDFFF);
	LCD_ShowString(20,60,200,16,16,(u8*)"Key1 gesture 2");
	while(KEY_Scan(0) != KEY1_PRES);
	delay_ms(600);
	FDC2214_GetData(1,0);
//	LCD_Fill(5,80,235,200,0xDFFF);
//	LCD_ShowString(20,80,200,16,16,(u8*)"Jiandao 1 Done!");
//	delay_ms(1000);
	
	printf("\r\n----123----\r\n");
	
	LCD_Fill(5,80,235,200,0xDFFF);
	LCD_ShowString(20,80,200,16,16,(u8*)"Key1:The second time");
	while(KEY_Scan(0) != KEY1_PRES);
	delay_ms(600);
	FDC2214_GetData(1,1);
//	LCD_Fill(5,80,235,200,0xDFFF);
//	LCD_ShowString(20,80,200,16,16,(u8*)"Jiandao 2 Done!");
//	delay_ms(1000);
	
	printf("\r\n----123----\r\n");
	
	LCD_Fill(5,100,235,200,0xDFFF);
	LCD_ShowString(20,100,200,16,16,(u8*)"Key1:The third time");
	while(KEY_Scan(0) != KEY1_PRES);
	delay_ms(600);
	FDC2214_GetData(1,2);
//	LCD_Fill(5,80,235,200,0xDFFF);
//	LCD_ShowString(20,80,200,16,16,(u8*)"Jiandao 3 Done!");
//	delay_ms(1000);
	
	printf("\r\n----5----\r\n");
	
	// 训练布
	LCD_Fill(5,60,235,200,0xDFFF);
	LCD_ShowString(20,60,200,16,16,(u8*)"Key1 gesture 3");
	while(KEY_Scan(0) != KEY1_PRES);
	delay_ms(600);
	FDC2214_GetData(2,0);
//	LCD_Fill(5,80,235,200,0xDFFF);
//	LCD_ShowString(20,80,200,16,16,(u8*)"Bu 1 Done!");
//	delay_ms(1000);
//	
	printf("\r\n----123----\r\n");
	
	LCD_Fill(5,80,235,200,0xDFFF);
	LCD_ShowString(20,80,200,16,16,(u8*)"Key1:The second time");
	while(KEY_Scan(0) != KEY1_PRES);
	delay_ms(600);
	FDC2214_GetData(2,1);
//	LCD_Fill(5,80,235,200,0xDFFF);
//	LCD_ShowString(20,80,200,16,16,(u8*)"Key1:The third time");
//	delay_ms(1000);
	
	printf("\r\n----123----\r\n");
	
	LCD_Fill(5,100,235,200,0xDFFF);
	LCD_ShowString(20,100,200,16,16,(u8*)"Key1:The third time");
	while(KEY_Scan(0) != KEY1_PRES);
	delay_ms(600);
	FDC2214_GetData(2,2);
//	LCD_Fill(5,80,235,200,0xDFFF);
//	LCD_ShowString(20,80,200,16,16,(u8*)"Bu 3 Done!");
//	delay_ms(1000);
	
	printf("\r\n----5----\r\n");
}


// 手势函数获取
void FDC2214_GetData(u8 ges_time,u8 train_time)
{
	//8个通道的值每个通道获取10次
	u32 ch[10][8];
	u8 i;
	
	if(ges_time!=3){
		for(k=0;k<10;k++){
			FDC2214_GetChannelData(slave_ADDR1,FDC2214_Channel_0, &ch[k][0]);
			printf("\r\n ch[%d] = %08x \r\n",0 ,ch[k][0]);
			FDC2214_GetChannelData(slave_ADDR1,FDC2214_Channel_1, &ch[k][1]);
			printf("\r\n ch[%d] = %08x \r\n",1 ,ch[k][1]);
			FDC2214_GetChannelData(slave_ADDR1,FDC2214_Channel_2, &ch[k][2]);
			printf("\r\n ch[%d] = %08x \r\n",2 ,ch[k][2]);
			FDC2214_GetChannelData(slave_ADDR1,FDC2214_Channel_3, &ch[k][3]);
			printf("\r\n ch[%d] = %08x \r\n",3 ,ch[k][3]);
			FDC2214_GetChannelData(slave_ADDR2,FDC2214_Channel_0, &ch[k][4]);
			printf("\r\n ch[%d] = %08x \r\n",4 ,ch[k][4]);
			FDC2214_GetChannelData(slave_ADDR2,FDC2214_Channel_1, &ch[k][5]);
			printf("\r\n ch[%d] = %08x \r\n",5 ,ch[k][5]);
			FDC2214_GetChannelData(slave_ADDR2,FDC2214_Channel_2, &ch[k][6]);
			printf("\r\n ch[%d] = %08x \r\n",6 ,ch[k][6]);
			FDC2214_GetChannelData(slave_ADDR2,FDC2214_Channel_3, &ch[k][7]);
			printf("\r\n ch[%d] = %08x \r\n",7 ,ch[k][7]);
		}
//		//获取8个通道的值
//		for(k=0;k<10;k++){
//			for(i=0;i<4;i++){
//				FDC2214_GetChannelData(slave_ADDR1,FDC2214_Channel_0, &ch[k][i]);
//				printf("\r\n ch[%d] = %08x \r\n",i ,ch[k][i]);
//			}
//			for(i=0;i<4;i++){
//				FDC2214_GetChannelData(slave_ADDR2,FDC2214_Channel_0, &ch[k][i+4]);  
//				printf("\r\n ch[%d] = %08x \r\n",i+4 ,ch[k][i+4]);
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
	
	//将获取的数据存入对应训练的buffer
	if(ges_time==0){
		switch(train_time)
		{
			case 0:	for(i=0;i<8;i++) for(k=0;k<10;k++) data_a0[k][i]=ch[k][i]; break;
			case 1:	for(i=0;i<8;i++) for(k=0;k<10;k++) data_a1[k][i]=ch[k][i]; break;
			case 2:	for(i=0;i<8;i++) for(k=0;k<10;k++) data_a2[k][i]=ch[k][i]; break;
			default: LCD_ShowString(0,0,240,10,10,"traning time segmen fault... "); break;
		}
	}else if(ges_time==1){
		switch(train_time)
		{
			case 0:	for(i=0;i<8;i++) for(k=0;k<10;k++) data_b0[k][i]=ch[k][i]; break;
			case 1:	for(i=0;i<8;i++) for(k=0;k<10;k++) data_b1[k][i]=ch[k][i]; break;
			case 2:	for(i=0;i<8;i++) for(k=0;k<10;k++) data_b2[k][i]=ch[k][i]; break;
			default: LCD_ShowString(0,0,240,10,10,"traning time segmen fault... "); break;
		}
	}else if(ges_time==2){
		switch(train_time)
		{
			case 0:	for(i=0;i<8;i++) for(k=0;k<10;k++) data_c0[k][i]=ch[k][i]; break;
			case 1:	for(i=0;i<8;i++) for(k=0;k<10;k++) data_c1[k][i]=ch[k][i]; break;
			case 2:	for(i=0;i<8;i++) for(k=0;k<10;k++) data_c2[k][i]=ch[k][i]; break;
			default: LCD_ShowString(0,0,240,10,10,"traning time segmen fault... "); break;
		}
	}else if(ges_time==3){
		printf("\r\n JUDGE MODE\r\n");
		for(i=0;i<8;i++) test_data[i]=ch[0][i];
	}else if(ges_time==4){
		switch(train_time)
		{
			case 0:	for(i=0;i<8;i++) for(k=0;k<10;k++) back0[k][i]=ch[k][i]; break;
			case 1:	for(i=0;i<8;i++) for(k=0;k<10;k++) back1[k][i]=ch[k][i]; break;
			case 2:	for(i=0;i<8;i++) for(k=0;k<10;k++) back2[k][i]=ch[k][i]; break;
			default: LCD_ShowString(0,0,240,10,10,"traning time segmen fault... "); break;
		}
		
	}
}


// 排序
u8 Bubble_sort3(float data[])
{
	u8 i,j;
	float temp;
	u8 temp_order;
	u8 order[120] = {0,0,0,1,1,1,2,2,2,3,3,3,0,0,0,1,1,1,2,2,2,3,3,3,0,0,0,1,1,1,2,2,2,3,3,3,0,0,0,1,1,1,2,2,2,3,3,3,0,0,0,1,1,1,2,2,2,3,3,3,0,0,0,1,1,1,2,2,2,3,3,3,0,0,0,1,1,1,2,2,2,3,3,3,0,0,0,1,1,1,2,2,2,3,3,3,0,0,0,1,1,1,2,2,2,3,3,3,0,0,0,1,1,1,2,2,2,3,3,3};
	u8 a=0,b=0,c=0,back=0;
	
		for(i = 0; i < 120; i++)
	{
		for(j = 0; j < 120-i; j++)
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
	
	for(i = 0 ; i < 40 ; i++)
		printf(" %d ",order[i]);
	
	for(i=0;i<40;i++)
	{
			switch(order[i])
			{
				case 0: a+=1;break;
				case 1:	b+=1;break;
				case 2:	c+=1;break;
				case 3:	back+=1;break;
			}
			if(a>=10) return 0;
			else if(b>=10) return 1;
			else if(c>=10) return 2;
			else if(back>=10) return -1;
	}
	
	return -1;
}


// 计算距离
void calculate_proc(	float distance[])
{
	for(i=0,k=0;k<10;k++){
		distance[i++]=l2_distance(test_data,data_a0[k]);
		distance[i++]=l2_distance(test_data,data_a1[k]);
		distance[i++]=l2_distance(test_data,data_a2[k]);
		distance[i++]=l2_distance(test_data,data_b0[k]);
		distance[i++]=l2_distance(test_data,data_b1[k]);
		distance[i++]=l2_distance(test_data,data_b2[k]);
		distance[i++]=l2_distance(test_data,data_c0[k]);
		distance[i++]=l2_distance(test_data,data_c1[k]);
		distance[i++]=l2_distance(test_data,data_c2[k]);
		distance[i++]=l2_distance(test_data,back0[k]);
		distance[i++]=l2_distance(test_data,back1[k]);
		distance[i++]=l2_distance(test_data,back2[k]);
	}
}


// 计算欧式距离
float l2_distance(u32 x[],u32 y[])
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


// 猜拳模式
void testCaiquan(){
	float distance[12];
	u8 item;
	
	while(KEY1!=0){
		
		if(KEY0==0){
			delay_ms(500);
		
			// 进入测试
			FDC2214_GetData(3,0);	
				
			//计算距离
			for(i=0,k=0;k<10;k++){
				distance[i++]=l2_distance(test_data,data_a0[k]);
				distance[i++]=l2_distance(test_data,data_a1[k]);
				distance[i++]=l2_distance(test_data,data_a2[k]);
				distance[i++]=l2_distance(test_data,data_b0[k]);
				distance[i++]=l2_distance(test_data,data_b1[k]);
				distance[i++]=l2_distance(test_data,data_b2[k]);
				distance[i++]=l2_distance(test_data,data_c0[k]);
				distance[i++]=l2_distance(test_data,data_c1[k]);
				distance[i++]=l2_distance(test_data,data_c2[k]);
				distance[i++]=l2_distance(test_data,back0[k]);
				distance[i++]=l2_distance(test_data,back1[k]);
				distance[i++]=l2_distance(test_data,back2[k]);
			}
			//排序
			item=Bubble_sort3(distance);
				
			//显示结果
			printf("SORT : %d" , item);
		
			LCD_Fill(5,120,235,315,0xDFFF);
			if(item==0){showRock();}
			else if(item==1){showScissor();}
			else if(item==2){showPaper();}
			else if(item==-1){LCD_Fill(5,120,235,315,0xDFFF);}
		}
	}
}


// 获取石头数据
void showRock(){
	for(i = 0; i < 1158; i++){
		LCD_DrawPoint(rockX[i],rockY[i]+80);
	}
}


// 获取剪刀数据
void showScissor(){
	for(i = 0; i < 1194; i++){
		LCD_DrawPoint(scissorX[i],scissorY[i]+80);
	}
}


// 获取布数据
void showPaper(){
	for(i = 0; i < 1036; i++){
		LCD_DrawPoint(paperX[i],paperY[i]+80);
	}
}