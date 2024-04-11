#include <common.h>
/******************************************************************
		【表格集成.C文件】
编写人：徐哲轩
文件功能：包含大部分按钮功能函数的文件
*******************************************************************/
//——————————————————————————————————————

//          【 表格函数的使用规范 】

//			定义参数
//		int sheetdata[12] = {24,30,60,70,90,60,20+20+20+40,40,30,0,80,90};

//			创建表格
//		show = SheetCreate_4 (sheetdata,p15_patient,sheet_1_page,check2,input);

//				编写人 ：徐哲轩
//——————————————————————————————————————

/******************************************************************
		【页数控制器绘图函数】
编写人：徐哲轩
传入：x , y（坐标）length_x(控制器长度)
传出：void
函数功能：画出页数控制器
*******************************************************************/
void CreateButton_pagechange_Draw(int x,int y,int length_x,int* sheetpage)
{
		int length_x_small = 40;
		int length_y = 30;
		char pageshow[4] = {0};//展示页数
		setfillstyle(1,DARKGRAY);
		bar(x, y, x+length_x,y+length_y);
		setcolor(DARKGRAY);
		rectangle(x, y, x+length_x,y+length_y);
		puthz(x+length_x-70,y+10,"页数",16,18,WHITE);
		setfillstyle(1,GREEN);
		settextstyle(3,0,1);
		setcolor(YELLOW);
		setlinestyle(0,0,3);
		CHAR_INT_Change(pageshow,*sheetpage);
		outtextxy(x+length_x-24,y,pageshow);//输入只能是字符串
		bar(x+10,y+5, x+length_x_small,y+length_y-5);
		bar(x+length_x_small+10,y+5, x+2*length_x_small,y+length_y-5);
		bar(x+2*length_x_small+10,y+5, x+3*length_x_small,y+length_y-5);
		line(x+17,y+8, x+17,y+length_y-8);
		line(x+20,y+length_y/2, x+length_x_small-15,y+8);
		line(x+20,y+length_y/2, x+length_x_small-15,y+length_y-8);
		line(x+20+5,y+length_y/2, x+length_x_small-10,y+8);
		line(x+20+5,y+length_y/2, x+length_x_small-10,y+length_y-8);
		line(x+20+5+length_x_small,y+length_y/2, x+length_x_small*2-10,y+8);
		line(x+20+5+length_x_small,y+length_y/2, x+length_x_small*2-10,y+length_y-8);
		line(x+20+5+length_x_small*2,y+length_y/2, x+20+5+length_x_small+35,y+8);
		line(x+20+5+length_x_small*2,y+length_y/2, x+20+5+length_x_small+35,y+length_y-8);	
}

/******************************************************************
		【表格页数控制器函数】
编写人：徐哲轩
传入：x , y（坐标）button（鼠标关于按钮的状态）
		sheetpage(控制的表格页数变量)，length_x(控制器长度)
传出：int (是否修改表格页数)
函数功能：在指定位置生成指定大小的控制器，控制器可以对表格页数进行
		增加,减少,返回到首页的操作,如果有修改页数,函数返回1,配合
		其他函数可以让表格数据刷新
*******************************************************************/
int CreateButton_pagechange (int x,int y,int*button,int* sheetpage,int length_x)
{
	int length_x_small = 40;//定义大小
	int length_y = 30;
	int back = 0;
	int old = *sheetpage;//检测页数的历史状态

	if(mouse_press(x+10,y+5, x+length_x_small,y+length_y-5) == 1)//检测返回首页按钮是否按下
	{
			clrmous(MouseX,MouseY);
			MouseS = 1;
			(*sheetpage) = 1;
	}
	if(mouse_press(x+length_x_small+10,y+5, x+2*length_x_small,y+length_y-5) == 1)//检测上一页按钮是否按下
	{
			clrmous(MouseX,MouseY);
			MouseS = 1;			
			(*sheetpage)--;
			(*sheetpage) = max(1,(*sheetpage));//防止页数小于1
	}
	if(mouse_press(x+2*length_x_small+10,y+5, x+3*length_x_small,y+length_y-5) == 1)//检测下一页按钮是否按下
	{
			clrmous(MouseX,MouseY);
			MouseS = 1;
			(*sheetpage)++;
			(*sheetpage) = min(99,(*sheetpage));//防止页数大于99
	}
	
	if(old !=(*sheetpage))*button = 1;//如果页数改变,重画
	
	if(*button == 1)
	{
		CreateButton_pagechange_Draw(x,y,length_x,sheetpage);//画出
		*button = 0;
		back = 1;
		delay(300);//防止翻页频繁
	}
	return back;//返回页数改变的信息
}


/******************************************************************
		【患者等待列表表头函数】（第三次优化）
编写人：徐哲轩
传入：x , y（坐标）length_x(控制器长度)
传出：void
函数功能：画出表头
*******************************************************************/
void SheetTitle_3(int x,int y,int length_x)
{
	char* title1 = "患者等待列表";
	int length_y = 30;
	settextstyle(3,0,2);
	setfillstyle(1,DARKGRAY);
	bar(x, y-10, x+length_x,y+length_y);
	setfillstyle(1,BLUE);
	bar(x+3, y-10+3, x+length_x-3,y+length_y-3);
	puthz(x+15+2,y+2-4,title1,24,26,DARKGRAY);
	puthz(x+15,y-4,title1,24,26,YELLOW);
} //最后修改：2023/4/1


/******************************************************************
		【等待列表单元格函数】
编写人：徐哲轩
传入：x , y（坐标）p链表头结点的下一位 n 指定的取药序号length_x(控制器长度)
传出：void
函数功能：按要求查找到取药序号为n的患者数据，并生成指定位置的单元格
*******************************************************************/
void SheetCell_3(PatientData* p,int n,int x,int y,int *length_x)
{
	int length_y = 30;
	char a[10] = {0};
	char a2[10] = {0};
	PatientData* m = p;
	setfillstyle(1,LIGHTBLUE);
	bar(x, y, x+length_x[0]+length_x[1]+length_x[2],y+length_y);
	setlinestyle(0,0,2);
	setcolor(WHITE);
	rectangle(x, y,x+length_x[0],y+length_y);
	rectangle(x+length_x[0], y, x+length_x[0]+length_x[1],y+length_y);
	rectangle(x+length_x[0]+length_x[1], y, x+length_x[0]+length_x[1]+length_x[2],y+length_y);
	while(m!= NULL){
		if((m)->nummed == n)
		{//此数据符合要求
			if(m != NULL){
				settextstyle(3,0,2);
				strcpy(a,(m)->name);
				CHAR_INT_Change(a2,(m)->numreg);
				setcolor(WHITE);
				outtextxy(x+5, y +3,a2 );//输出编号
				outtextxy(x+length_x[0]+5, y +3,a );//输出姓名
				
				if((m)->payreg == 4){//输出状态
					puthz(x+length_x[0]-10+length_x[1]+15,y+length_y/4+2,"配药完成",16,16,LIGHTGREEN);
				}else if((m)->payreg == 3){
					puthz(x+length_x[0]-10+length_x[1]+15,y+length_y/4+2,"正在配药",16,16,WHITE);
				}else if((m)->payreg == 5){
					puthz(x+length_x[0]-10+length_x[1]+15,y+length_y/4+2,"等待取药",16,16,LIGHTCYAN);
				}else{
					puthz(x+length_x[0]-10+length_x[1]+15,y+length_y/4+2,"未完成",16,16,LIGHTRED);
				}
			}	
			break;
		}else{
			if(m->next == NULL){
				break;
			}
			m = m->next;
		}
	}
}

/******************************************************************
		【等待列表单元格点亮函数】
编写人：徐哲轩
传入：x , y（坐标）p链表头结点的下一位 n 指定的取药序号length_x(控制器长度)
传出：void
函数功能：按要求查找到取药序号为n的患者数据，并生成指定位置的点亮状态的单元格
*******************************************************************/
void SheetCell_3_on(PatientData* p,int n,int x,int y,int *length_x)
{
	int length_y = 30;
	char a[10] = {0};
	char a2[10] = {0};
	PatientData* m = p;
	setfillstyle(1,WHITE);
	bar(x, y, x+length_x[0]+length_x[1]+length_x[2],y+length_y);
	setlinestyle(0,0,2);
	setcolor(YELLOW);
	rectangle(x, y,x+length_x[0],y+length_y);
	rectangle(x+length_x[0], y, x+length_x[0]+length_x[1],y+length_y);
	rectangle(x+length_x[0]+length_x[1], y, x+length_x[0]+length_x[1]+length_x[2],y+length_y);

	while(m != NULL){
		if((m)->nummed == n) 
		{//此数据符合要求
			if(m != NULL){
				settextstyle(3,0,2);
				strcpy(a,(m)->name);
				CHAR_INT_Change(a2,(m)->numreg);
				
				setcolor(DARKGRAY);
				outtextxy(x+5, y +3,a2 );//输出挂号号码
				outtextxy(x+length_x[0]+5, y +3,a );//输出姓名
				
				if((m)->payreg == 4){//输出状态
					puthz(x+length_x[0]-10+length_x[1]+15,y+length_y/4+2,"配药完成",16,16,DARKGRAY);
				}else if((m)->payreg == 3){
					puthz(x+length_x[0]-10+length_x[1]+15,y+length_y/4+2,"正在配药",16,16,DARKGRAY);
				}else if((m)->payreg == 5){
					puthz(x+length_x[0]-10+length_x[1]+15,y+length_y/4+2,"等待取药",16,16,DARKGRAY);
				}else{
					puthz(x+length_x[0]-10+length_x[1]+15,y+length_y/4+2,"未完成",16,16,DARKGRAY);
				}
			}
			break;
		}else{
			if(m->next == NULL){
				break;
			}
			m = m->next;
		}
	}
}

/******************************************************************
		【等待列表函数】
编写人：徐哲轩
传入：data（参数）p链表头结点的下一位 page，check（单元格关于鼠标状态）
函数功能：按要求查找到取药序号为n的患者数据，并生成指定位置的点亮状态的单元格
*******************************************************************/
int SheetCreate_3 (int* data,PatientData* p,int page,int* check)
//这个样式的表格的单元具有按钮功能
//初步估计生成八个单元，底层可翻页
//1,高度 2 3 4三个单元格长度 56定位 ，7样式
{
	int style;
	int back = -1;
	int length_y = data[0];
	int length_xs[3] = {1,1,1};
	int x = data[4];int y = data[5];
	int length_x;//集成数据输入
	int cell_num = 8;
	int i=0  ;
	int pass = 0;
	length_xs[0] = data[1];
	length_xs[1] = data[2];
	length_xs[2] = data[3];
	length_x = length_xs[0]+length_xs[1]+length_xs[2];//集成数据输入
	style = data[6];
	if(style == 1){
		pass = 1;
	}
	if(check[0]==1)
	{
		SheetTitle_3(x,y-length_y,length_x);
	}
	for( i=0;i<cell_num;i++)
	{
		if(check[i] == 3){
			continue;
		}
		if((mouse_press(x, y+length_y*i, x+length_x,y+length_y*(i+1)) != check[i]))
		{
			int XY[2] = {0};XY[0] = x;XY[1] = y+length_y*i;
			if( mouse_press(x, y+length_y*i, x+length_x,y+length_y*(i+1)) == 0)
			{
				clrmous(MouseX,MouseY);
				MouseS = 0;
				setfillstyle(1,LIGHTGRAY);
				bar(x, y+length_y*i, x+length_x,y+length_y*(i+1));
				SheetCell_3(p,i+cell_num*(page-1)+1,x,y+length_y*i,length_xs);
				check[i] = 0;
			}
			else
			{
				clrmous(MouseX,MouseY);
				MouseS = 1;
				setfillstyle(1,BLUE);
				bar(x, y+length_y*i, x+length_x,y+length_y*(i+1));
				SheetCell_3_on(p,i+cell_num*(page-1)+1,x,y+length_y*i,length_xs);
				check[i] = 2;
			}
		}
		if(mouse_press(x, y+length_y*i, x+length_x,y+length_y*(i+1)) == 1)
		{
			back = i+cell_num*(page-1)+1;
		}
		if(pass)
		{
			check[i] = 3;
		}
	}
	return back;
}//最后修改：2023/4/1


/******************************************************************
		【挂号查询列表表头函数】
编写人：徐哲轩
传入：data（参数）length_x
函数功能：画出表头
*******************************************************************/
void SheetCreate_4_Title(int *data,int* length_x)
{
	int y2 = 3;
	int x2 = 5;
	int x = data[0];
	int y = data[1];
	int length_x_1 = length_x[0]+length_x[1]+length_x[2]+length_x[3] +length_x[4];
		settextstyle(2,0,4);
		setcolor(DARKGRAY);
		puthz(x+x2, y +y2,"编号",16,16,DARKGRAY);
		outtextxy(x+length_x[0]+x2+15, y +y2,"Name");
		puthz(x+length_x[0]+length_x[1]+x2, y +y2,"门诊类型",16,16,DARKGRAY);
		puthz(x+length_x[0]+length_x[1]+length_x[2]+x2, y +y2,"科室",16,16,DARKGRAY);
		puthz(x+length_x[0]+length_x[1]+length_x[2]+length_x[3]+x2, y +y2,"医生",16,16,DARKGRAY);
		outtextxy(x+length_x_1+x2, y +y2,"Time");
		outtextxy(x+length_x_1+length_x[5]-20-20+x2, y +y2,"Sexual");
		outtextxy(x+length_x_1+length_x[5]+5+x2+10-15, y +y2,"Money");
		outtextxy(x+length_x_1+length_x[5]+length_x[6]+x2, y +y2,"Age");
}	


/******************************************************************
		【挂号查询列表函数】（第四次优化）
编写人：徐哲轩
传入：data（参数）p头节点，page，check，input（输入框输入）
传出 int
函数功能：能够在指定位置生成指定大小的表格，同时具有按照输入内容进行数据筛选的功能
*******************************************************************/
int SheetCreate_4 (int* data,PatientData* p,int page,int* check,char* input)
//这个样式的表格的单元具有按钮功能
//初步估计生成12个单元，底层可翻页
//data容量为12
//1,高度 2 到10单元格长度 11，12定位
{
	int back = -1;
	int length_y = data[0];
	int x = data[10];
	int y = data[11];
	int length_x = 0;//集成数据输入
	int cell_num = 12;
	int i=0 ;
	int *length_xs = &data[1];
	for(i=0;i<9;i++)
	{
		length_x += length_xs[i];//集成数据输入//data1 --- data9
	}
	for( i=0;i<cell_num;i++)
	{
		if((mouse_press(x, y+length_y*i, x+length_x,y+length_y*(i+1)) != check[i]))
		{
			int XY[2] = {0};XY[0] = x;XY[1] = 68;
			if(check[0] == 1)
			{
				SheetCreate_4_Title(XY,length_xs);
			}
			XY[0] = x;XY[1] = y+length_y*i;
			if( mouse_press(x, y+length_y*i, x+length_x,y+length_y*(i+1)) == 0)
			{
				clrmous(MouseX,MouseY);
				MouseS = 0;
				setfillstyle(1,LIGHTGRAY);
				bar(x, y+length_y*i, x+length_x,y+length_y*(i+1));
				setfillstyle(1,LIGHTBLUE);
				bar(x+2, y+length_y*i+2, x+length_x-2,y+length_y*(i+1)-2);
				SheetCell_5(p,i+cell_num*(page-1)+1,XY,length_xs,input);
				check[i] = 0;
			}
			else
			{
				clrmous(MouseX,MouseY);
				MouseS = 1;
				setfillstyle(1,YELLOW);
				bar(x, y+length_y*i, x+length_x,y+length_y*(i+1));
				setfillstyle(1,CYAN);
				bar(x+2, y+length_y*i+2, x+length_x-2,y+length_y*(i+1)-2);
				SheetCell_5(p,i+cell_num*(page-1)+1,XY,length_xs,input);
				check[i] = 2;
			}
		}
		if(mouse_press(x, y+length_y*i, x+length_x,y+length_y*(i+1)) == 1)
		{
			back = i+cell_num*(page-1)+1;
			break;
		}
	 }
	return back;
}//最后修改：2023/4/1


/******************************************************************
		【挂号查询列表单元格函数】（第四次优化）
编写人：徐哲轩
传入：data（参数）p头节点，page，check，input2（输入框输入）
传出 void
函数功能：按要求查找到指定的患者数据，并生成指定位置的单元格
*******************************************************************/
void SheetCell_5(PatientData* p,int n,int *data,int* length_x,char* input2)
{

	int y2 = 3;
	int x2 = 5;
	int x = data[0];
	int y = data[1];
	char a[21] = {0};
	int state0 = 0;
	char a2[20] = {0};
	int length_x_1 = length_x[0]+length_x[1]+length_x[2]+length_x[3] +length_x[4];
	PatientData* m = p;
	int num = 0;
	if(input2[1]<='9'&&input2[1]>='0' &&input2[0] == '#')
	{
		state0 = INT_CHAR_Change2(&input2[1],1);
	}
	else if(input2[0] == '@')
	{
		char input3[5] ={0};
		strcpy(input3,&input2[1]);
		state0 = INT_CHAR_Change(input3);
	}
	else if(input2[0] == '%')
	{
	}
			while(m!= NULL)
			{
				if(  (state0 == (m)->payreg  && input2[0] == '#')|| (state0 == 9) || strcmp((m)->name,input2) == 0
				||( state0 == (m)->numreg &&input2[0] == '@')||(TimeCheck(&input2[1],(m)->timer) == 0 && input2[0] == '%'))
				{
					num++;
				}
				if(n == num && num != 0 )
				{
					if(m != NULL)
					{
						int color = YELLOW;
						char z1[4] ={0};
						char input[21] = {0};
						char money[6] = {0};
						char* t = input;
						strcpy(input,(m)->doctor);
						strcat(input,(m)->timer);
						settextstyle(2,0,4);
						strcpy(a,(m)->name);
						CHAR_INT_Change2(a2,(m)->numreg,4);
						setcolor(color);
						outtextxy(x+x2, y +y2,a2 );
						outtextxy(x+length_x[0]+x2, y +y2,a );
						DoctorShow(t,a,1);
						puthz(x+length_x[0]+length_x[1]+x2, y +y2,a,16,16,color);
						DoctorShow(t,a,2);
						puthz(x+length_x[0]+length_x[1]+length_x[2]+x2, y +y2,a,16,16,color);
						DoctorShow(t,a,3);
						puthz(x+length_x[0]+length_x[1]+length_x[2]+length_x[3]+x2, y +y2,a,16,16,color);
						strcpy(a2,"\0");
						t = &input[4];
						outtextxy(x+length_x_1+x2, y +y2,t);
						if(m->sexual == 0)
						{
							outtextxy(x+length_x_1+length_x[5]-20+x2, y +y2,"Man");
						}else{
							outtextxy(x+length_x_1+length_x[5]-20+x2, y +y2,"Woman");
						}
						CHAR_INT_Change(money,m->paymed);
						outtextxy(x+length_x_1+length_x[5]+5+x2+10, y +y2,money);
						CHAR_INT_Change(z1,m->age);
						outtextxy(x+length_x_1+length_x[5]+length_x[6]+x2, y +y2,z1);
					}
					break;
				}
				m = m->next;
			}
	}
	
	

/******************************************************************
		【药品消耗列表函数】（第四次优化）
编写人：徐哲轩
传入：data（参数）p头节点，page，check，input（输入框输入）
传出 int
函数功能：能够在指定位置生成指定大小的表格，同时具有按照输入内容进行数据筛选的功能
*******************************************************************/
int SheetCreate_4_MED (int* data,PatientData* p,int* output,int* check,char* input)
//这个样式的表格的单元具有按钮功能
//初步估计生成12个单元，底层可翻页
//data容量为12
//1,高度 2 到10单元格长度 11，12定位
{
	int back = -1;
	int length_y = data[0];
	int x = data[10];
	int y = data[11];
	int length_x = 0;
	int cell_num = 12;
	int i=0 ;
	int *length_xs = &data[1];
	int page = data[12];
	for(i=0;i<9;i++)
	{
		length_x += length_xs[i];//集成数据输入//data1 --- data9
	}
	for( i=0;i<cell_num;i++)
	{
		if((mouse_press(x, y+length_y*i, x+length_x,y+length_y*(i+1)) != check[i]))
		{
			int XY[4] = {0};XY[0] = x;XY[1] = y+length_y*i;XY[2] = i;XY[3] = page;
			if( mouse_press(x, y+length_y*i, x+length_x,y+length_y*(i+1)) == 0)
			{
				clrmous(MouseX,MouseY);
				MouseS = 0;
					setfillstyle(1,LIGHTGRAY);
					bar(x, y+length_y*i, x+length_x,y+length_y*(i+1));
					setfillstyle(1,LIGHTBLUE);
					bar(x+2, y+length_y*i+2, x+length_x-2,y+length_y*(i+1)-2);
					SheetCell_MED(p,output,XY,length_xs,input);
				check[i] = 0;
			}
			else
			{
				clrmous(MouseX,MouseY);
				MouseS = 1;
						setfillstyle(1,YELLOW);
						bar(x, y+length_y*i, x+length_x,y+length_y*(i+1));
						setfillstyle(1,CYAN);
						bar(x+2, y+length_y*i+2, x+length_x-2,y+length_y*(i+1)-2);
						SheetCell_MED(p,output,XY,length_xs,input);
				check[i] = 2;
			}
		}
		if(mouse_press(x, y+length_y*i, x+length_x,y+length_y*(i+1)) == 1)
		{
			back = i+cell_num*(page-1)+1;
			break;
		}
	 }
	return back;
}//最后修改：2023/4/1

/******************************************************************
		【药品消耗列表单元格函数】（第四次优化）
编写人：徐哲轩
传入：data（参数）p头节点，page，check，input（输入框输入）
传出 int
函数功能：按照要求生成药品单元格
*******************************************************************/
void SheetCell_MED(PatientData* p,int *output,int *data,int* length_x,char* input2)
{
   //	int length_y = data[0];
	int y2 = -2;
	int x2 = 5;
	int x = data[0];
	int y = data[1];
	char a[21] = {0};
   //	int length_x_1 = length_x[0]+length_x[1]+length_x[2]+length_x[3] +length_x[4];
	PatientData* m = p;
	int i = 0;
	int num = 0;
	int n = data[2];
	int k = data[3];
	MED*medicine = (MED*)malloc(sizeof(MED));//创建一个工具结构 
	FILE*fp; 
	fp=fopen("C:\\project\\DATABASE\\drugdata.txt","r");
	for(i=0;i<=n+12*(k-1);i++)
	{
		if(feof(fp))
		{
			medicine->ID = 0;
			break;
		}
		else
		{
			fscanf(fp,"%d\t%d\t%s\t%d\t%d\t%d\n",&medicine->ID,&medicine->Store_No,medicine->name,&medicine->price,&medicine->margin,&medicine->inventory);
		}
	}
	if(medicine->ID != 0)
	{
		char number[6] = {0};
	//	char input[21] = {0};
		int i2 = 0;
		while(m!= NULL)
		{
			for(i2=0;i2<6;i2++)
			{
				if(m->medicine_list[i2][2] == 2 && m->medicine_list[i2][0] == medicine->ID && TimeCheck(input2,(m)->timer) == 0)
				{
					num += m->medicine_list[i2][1];
				}
			}
			m = m->next;
		}
		settextstyle(1,0,2);
		setcolor(YELLOW);
		CHAR_INT_Change(a,i);
		outtextxy(x+x2, y +y2,a);
		settextstyle(1,0,2);
		outtextxy(x+length_x[0]+length_x[1]+x2, y +y2,medicine->name);
		settextstyle(1,0,2);
		CHAR_INT_Change(number,num);
		outtextxy(x+length_x[0]+length_x[1]+length_x[2]+length_x[3]+x2+20, y +y2,number);
		CHAR_INT_Change(number,medicine->margin);
		outtextxy(x+length_x[0]+length_x[1]+length_x[2]+length_x[3]+x2+60+15, y +y2,number);
		output[medicine->ID] = num;
	}
	free(medicine);
	fclose(fp);
}
