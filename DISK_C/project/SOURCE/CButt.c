#include <common.h>

/******************************************************************
		【按钮集成.C文件】
编写人：徐哲轩
文件功能：包含大部分按钮功能函数的文件
*******************************************************************/

//——————————————————————————————————————

//          【 按钮函数的使用规范 】

//			创建按钮：
//			page_t = CreateButton_1("返回",240,300,1,&button[0]);

//			添加逻辑：
//			if(page_t)
//			{
//				page = page_t;
//				break;
//			}

//				编写人 ：徐哲轩
//——————————————————————————————————————


/******************************************************************
		【按钮点亮样式函数】
编写人：徐哲轩
传入：text(按钮的显示文本)，data（按钮的参数）
传出：void
函数功能：点亮按钮，保存了按钮的不同样式，可以根据样式改变按钮色彩和文本
*******************************************************************/
void Button_Light(char* text,int* data)
{
	int style = 0;
	int x = data[0];
	int y = data[1];
	int length_x = data[3];
	int length_y = data[4];
	int textsize = data[5];
	int textlength = data[6];
	
	if(data[8] < 10 && data[8] > 0)//限制样式范围
	{
		style = data[8];
	}
	clrmous(MouseX,MouseY);
	MouseS = 1;
	switch (style)
	{
	case 5:
		setfillstyle(1,LIGHTGRAY);
		bar(x, y, x+length_x,y+length_y);
		puthz(x+length_x/2-textlength-textsize-data[7],y+length_y/4,text,textsize,textlength,DARKGRAY);
		break;
	case 4:
		setfillstyle(1,YELLOW);
		bar(x, y, x+length_x,y+length_y);
		setfillstyle(1,DARKGRAY);
		bar(x+1, y+1, x+length_x-1,y+length_y-1);
		puthz(x+length_x/2-textlength-textsize-data[7] +1,y+length_y/4+1,text,textsize,textlength,LIGHTGRAY);
		puthz(x+length_x/2-textlength-textsize-data[7],y+length_y/4,text,textsize,textlength,YELLOW);
		break;
	case 3:
		
		setfillstyle(1,DARKGRAY);
		bar(x, y, x+length_x,y+length_y);
		setfillstyle(1,CYAN);
		bar(x+3, y+3, x+length_x-3,y+length_y-3);
		puthz(x+length_x/2-textlength-textsize-data[7] +2,y+length_y/4+2,text,textsize,textlength,DARKGRAY);
		puthz(x+length_x/2-textlength-textsize-data[7],y+length_y/4,text,textsize,textlength,YELLOW);
		break;
	case 2:
		setfillstyle(1,BLUE);
		bar(x, y, x+length_x,y+length_y);
		puthz(x+length_x/2-textlength-textsize-data[7],y+length_y/4,text,textsize,textlength,LIGHTBLUE);
		break;
	case 1:
		setfillstyle(1,BLUE);
		bar(x, y, x+length_x,y+length_y);
		puthz(x+length_x/2-textlength-textsize-data[7],y+length_y/4,text,textsize,textlength,WHITE);
		break;
	default:
		setfillstyle(1,LIGHTGRAY);
		bar(x, y, x+length_x,y+length_y);
		puthz(x+length_x/2-textlength-textsize-data[7],y+length_y/4,text,textsize,textlength,DARKGRAY);
		break;
	}
}

/******************************************************************
		【按钮恢复样式函数】
编写人：徐哲轩
传入：text(按钮的显示文本)，data（按钮的参数）
传出：void
函数功能：恢复按钮颜色，保存了按钮的不同样式，可以根据样式改变按钮色彩和文本
*******************************************************************/
void Button_Recover(char* text,int* data)
{
	int style = 0;
	int x = data[0];
	int y = data[1];
	int length_x = data[3];
	int length_y = data[4];
	int textsize = data[5];
	int textlength = data[6];
	
	if(data[8] < 10 && data[8] > 0)//限制样式范围
	{
		style = data[8];
	}
	clrmous(MouseX,MouseY);
	MouseS = 0;
	switch (style)
	{
		case 4:
			setfillstyle(1,LIGHTGRAY);
			bar(x, y, x+length_x,y+length_y);
			setfillstyle(1,DARKGRAY);
			bar(x+1, y+1, x+length_x-1,y+length_y-1);
			puthz(x+length_x/2-textlength-textsize-data[7] +1,y+length_y/4+1,text,textsize,textlength,LIGHTGRAY);
			puthz(x+length_x/2-textlength-textsize-data[7],y+length_y/4,text,textsize,textlength,WHITE);
		break;
		case 3:
			setfillstyle(1,LIGHTGRAY);
			bar(x, y, x+length_x,y+length_y);
			setfillstyle(1,LIGHTBLUE);
			bar(x+3, y+3, x+length_x-3,y+length_y-3);
			puthz(x+length_x/2-textlength-textsize-data[7] +2,y+length_y/4+2,text,textsize,textlength,DARKGRAY);
			puthz(x+length_x/2-textlength-textsize-data[7],y+length_y/4,text,textsize,textlength,YELLOW);
			break;
		case 2:
			setfillstyle(1,BLUE);
			bar(x, y, x+length_x,y+length_y);
			puthz(x+length_x/2-textlength-textsize-data[7],y+length_y/4,text,textsize,textlength,WHITE);
		break;
		case 1:
			setfillstyle(1,BLUE);
			bar(x, y, x+length_x,y+length_y);
			puthz(x+length_x/2-textlength-textsize-data[7],y+length_y/4,text,textsize,textlength,WHITE);
		break;
		default:
			setfillstyle(1,LIGHTGRAY);
			bar(x, y, x+length_x,y+length_y);
			puthz(x+length_x/2-textlength-textsize-data[7],y+length_y/4,text,textsize,textlength,DARKGRAY);
		break;
	}
}

/******************************************************************
		【按钮函数】(第四次优化)
编写人：徐哲轩
传入：text(按钮的显示文本)，data（按钮的参数），button（按钮的状态）
传出：int（可设置的返回值）
函数功能：在指定位置生成指定大小和样式的按钮，按钮具有点亮功能，按钮返回的int
		可以实现页面跳转，状态改变，触发,弹出窗口的功能
*******************************************************************/
int CreateButton_4  (char* text,int* data,int* button)
//data容量9
//1，2坐标，3是返回值，4，5是按钮大小，6字号，7字间距，8字的开始位置，9为样式
//传入button是为了查看按钮的状态，防止按钮闪烁，影响体验
{
	int back = 0;
	int x = data[0];
	int y = data[1];
	int change = data[2];
	int length_x = data[3];
	int length_y = data[4];

	if(*button != 3)//检测按钮是否被锁定
	{
		if(mouse_press(x, y, x+length_x,y+length_y) != *button)//如果鼠标的位置关系改变
		{
			if(mouse_press(x, y, x+length_x,y+length_y) == 2)//区域内
			{
				Button_Light(text,data);//点亮
				*button = 2;//修正状态
			}
			else//区域外
			{	
				Button_Recover(text,data);//恢复
				*button = 0;		
			}
		}
		if(mouse_press(x, y, x+length_x,y+length_y) == 1)//如果按下
		{
			int t = data[8];
			data[8] = 5;//切换样式
			Button_Light(text,data);//切换按下的样式
			data[8] = t;
			back = change;//设置返回值
		}	
	}
	//返回设置的返回值
	return back;
}

/******************************************************************
		【开关函数】
编写人：徐哲轩
传入：data（开关的参数）button（鼠标关于开关的状态）key(开关控制的变量指针)，
传出：void
函数功能：在指定位置生成指定大小的开关，开关具有点亮功能，
		开关可以修改指定的int值,配合其他函数可以实现按钮解锁,
		叫号状态转变的功能
*******************************************************************/
void CreateButton_open  (int* data,int* button,int* key)
//data容量4
//1,2坐标.	3,4,大小
//传入button是为了查看上次开关的状态，防止开关闪烁，影响体验
{
	int x =data[0];
	int y= data[1];
	int length_x = data[2];
	int length_y = data[3];
	
	if(mouse_press(x, y, x+length_x,y+length_y) != *button)//如果鼠标的位置关系改变
	{
		if(mouse_press(x, y, x+length_x,y+length_y) == 0)//区域外
		{
			clrmous(MouseX,MouseY);
			MouseS = 0;
			setfillstyle(1,DARKGRAY);
			bar(x, y, x+length_x,y+length_y);
			setfillstyle(1,WHITE);
			bar(x+1, y+1, x+length_x-1,y+length_y-1);
			setfillstyle(1,LIGHTGRAY);
			bar(x+7, y+7, x+length_x-7,y+length_y-7);
			if(*key)//如果开关状态为 1
			{
				setfillstyle(1,WHITE);
				bar(x+7+1, y+7+1, x+length_x-7+1,y+length_y-7+1);
			}
			*button = 0;			
		}
		else//区域内
		{
			clrmous(MouseX,MouseY);
			MouseS = 1;
			setfillstyle(1,DARKGRAY);
			bar(x, y, x+length_x,y+length_y);
			setfillstyle(1,LIGHTBLUE);
			bar(x+1, y+1, x+length_x-1,y+length_y-1);
			setfillstyle(1,BLUE);
			bar(x+7, y+7, x+length_x-7,y+length_y-7);
			if(*key)//如果开关状态为 1
			{
				setfillstyle(1,LIGHTBLUE);
				bar(x+7+1, y+7+1, x+length_x-7+1,y+length_y-7+1);
			}
			*button = 2;	
		}
	}
	if(mouse_press(x, y, x+length_x,y+length_y) == 1)//如果鼠标在区域按下
	{
		*key = !(*key); //改变开关控制的变量
		delay(300);//延迟防止短时连按
	}	
}


/******************************************************************
		【返回键画图函数】
编写人：徐哲轩
传入：x , y（坐标）
传出：void 
函数功能：画出返回键
*******************************************************************/
void CreateButton_OUT_Draw(int x,int y,int style)
{
	int length_x  = 40;
	int length_y = 40;
	int xt = length_x/6;
	int yt = length_y/6;

	switch(style){
		case 1://恢复
			clrmous(MouseX,MouseY);
			MouseS = 0;
			setfillstyle(1,DARKGRAY);
			bar(x, y, x+length_x,y+length_y);
			setfillstyle(1,WHITE);
			bar(x+2, y+2, x+length_x-2,y+length_y-2);
			setcolor(DARKGRAY);
			setlinestyle(0, 0, 3);
			line(x+xt,y+yt,x+length_x-xt,y+length_y-yt);
			line(x+xt,y+length_y-yt,x+length_x-xt,y+yt);
		break;
		case 2://点亮
			clrmous(MouseX,MouseY);
			MouseS = 1;
			setfillstyle(1,RED);
			bar(x, y, x+length_x,y+length_y);
			setcolor(WHITE);
			setlinestyle(0, 0, 3);
			line(x+xt,y+yt,x+length_x-xt,y+length_y-yt);
			line(x+xt,y+length_y-yt,x+length_x-xt,y+yt);
		break;	
		default://返回中转
			yt = 0;
			setfillstyle(1,WHITE);
			bar(0, 395-10+yt,640,395+34+10+yt);
			setfillstyle(11,DARKGRAY);
			bar(0, 395-10+yt,640,395+34+10+yt);
			setfillstyle(1,WHITE);
			bar(0, 395-5+yt,640,395+34+5+yt);
			setfillstyle(1,WHITE);
			bar(235-5, 395+yt,255+153-5,395+34+yt);
			setlinestyle(2,0,5);
			setcolor(RED);
			line(0,412+yt,230-10+20,412+yt);
			line(260+153+10-20,412+yt,640,412+yt);
			frameline2();
			puthz(260-2,400+yt,"正在返回",24,32,RED);
			delay(500);			
		break;	
	}
}

/******************************************************************
		【返回键函数】
编写人：徐哲轩
传入：x , y（坐标）button（鼠标关于按钮的状态）
		change(设置的返回量)
传出：int 
函数功能：在指定位置生成返回键,进行返回上一个页面的操作
*******************************************************************/
int CreateButton_OUT  (int x,int y,int change,int* button)
{
	int back = 0;
	int length_x  = 40;
	int length_y = 40;//设置固定大小
 
	if(mouse_press(x, y, x+length_x,y+length_y) != *button)//如果鼠标关于按键状态改变
	{
		if(mouse_press(x, y, x+length_x,y+length_y) == 0)
		{
			CreateButton_OUT_Draw(x,y,1);
			*button = 0;	
		}
		else
		{
			CreateButton_OUT_Draw(x,y,2);
			*button = 2;		
		}
	}
	if(mouse_press(x, y, x+length_x,y+length_y) == 1)
	{
		CreateButton_OUT_Draw(x,y,0); //画出返回提示
		back = change;
	}	
	return back;//返回上级页面的序号
}


/******************************************************************
		【密码检测函数】
编写人：徐哲轩
传入：input(输入的内容)
传出：int (是否符合)
函数功能：检查密码是否正确
*******************************************************************/
int Password_Check(char* input)
{
	int back = 0;
	if(!strcmp(input,PASSWORD))
	{
		back = 1;
	}
	return back;
}
/******************************************************************
		【输入框绘图边框函数】
编写人：徐哲轩
传入：x y坐标,长度高度
传出：void
函数功能：画出边框
*******************************************************************/
void INPUTbutton_Write_3(int x,int y,int length_x,int length_y)
{		
	setfillstyle(1,DARKGRAY);
	bar(x -3, y-3, x+length_x+3,y+length_y+3);
	setfillstyle(1,WHITE);
	bar(x, y, x+length_x,y+length_y);
}

/******************************************************************
		【输入框绘图函数】
编写人：徐哲轩
传入：data(按钮参数),style(样式)
		input(储存输入的内容),text(输入框显示的文本)
		key(是否以*符号展示)
传出：void
函数功能：在指定位置生成指定样式和大小的输入框,
*******************************************************************/
void CreateButton_INPUT_3_Draw(int *data,char* input,char* text,int key,int style)
{
	int length_x =data[2];
	int length_y =data[3];
	int textlenth = data[4];
	int textstart = data[5];
	int textsize = data[8];
	int x = data[0];
	int y = data[1];
	
	switch (style)
	{
		case 1:
			clrmous(MouseX,MouseY);
			MouseS = 0;
			setfillstyle(1,LIGHTGRAY);
			bar(x -3, y-3, x+length_x+3,y+length_y+3);
			setfillstyle(1,WHITE);
			bar(x, y, x+length_x,y+length_y);
			settextstyle(data[7],0,textsize);
			setcolor(LIGHTGRAY);
			if(input[0] != 0)
			{
				if(key)
				{
					outtextxy(textstart + x, y , input);//输入只能是字符串
				}
				else
				{
					int i=0;
					for(;i < (int)strlen(input);i++)
					{
						outtextxy(textstart + x + i * textlenth, y + 8, "*");//输入只能是字符串	
					}
				}				
			}
			else
			{
				puthz(textstart + x+5,y+length_y/2-8, text, 16, 19, LIGHTGRAY);
			}
		break;
		default:
			clrmous(MouseX,MouseY);
			MouseS = 2;
			setfillstyle(1,DARKGRAY);
			bar(x -3, y-3, x+length_x+3,y+length_y+3);
			setfillstyle(1,WHITE);
			bar(x, y, x+length_x,y+length_y);
			settextstyle(data[7],0,textsize);
			setcolor(DARKGRAY);
			if(input[0] != 0){
				if(key){
					outtextxy(textstart + x, y , input);//输入只能是字符串
				}else{
					int i=0;
					for(;i < strlen(input);i++){
					outtextxy(textstart + x + i * textlenth, y + 8, "*");//输入只能是字符串	
					}
				}		
			}else{
				puthz(textstart + x+5,y+length_y/2-8, text, 16, 19, DARKGRAY);
			}			
		break;
	}
}

/******************************************************************
		【输入模式函数】
编写人：徐哲轩
传入：data(按钮参数)
		input(储存输入的内容)
		key(是否以*符号展示)
传出：void
函数功能：进入输入模式,读入键盘状态,并且展示输入的字符
*******************************************************************/
void INPUTbutton_3 (int* data,char* input,int key)
{
	char password[NAME_MAX_LENGTH] = {0};//临时存储输入值
	int i = 0;//检测输入的字符个数
	char a[2] = {"\0"};//存储单个输入字符,防止直接输出整个字符串出现乱码
	int textlenth = data[4];
	int x = data[0];
	int y = data[1];
	int maxlenth = data[6];
	int textstart = data[5];
	int length_x = data[2];
	int length_y = data[3];
	int textsize =data[8];
	
	strcpy(input,"\0");//将之前的输入清空
	clrmous(MouseX, MouseY);
	INPUTbutton_Write_3(x,y,length_x,length_y);
	settextstyle(data[7],0,textsize);
	setcolor(DARKGRAY);
	line(textstart + x + 3,y+7,textstart + x + 3,y+length_y-7);//画出光标
	while (1)//进入输入循环
	{
		a[0] = bioskey(0);//读入键盘
		if (i < maxlenth)//检测是否到达最大输入上线
		{
			if (a[0] != '\n' && a[0] != '\r')//033是esc
			{
				if (a[0] != '\b')
				{
					bar(textstart + x + (i) * textlenth-2, y ,textstart + x + (i+1) * textlenth +10, y + length_y);
					password[i] = a[0];
					password[i + 1] = '\0';
					if(key)//检测是否需要隐藏密码
					{
						outtextxy(textstart + x + i * textlenth, y, a);//输入只能是字符串
					}
					else
					{
						outtextxy(textstart + x + i * textlenth, y + 8, "*");//输入只能是字符串
					}				
					line(textstart + x + (i+1) * textlenth,y+5,textstart + x + (i+1) * textlenth,y+length_y-5);
					i++;
				}
				else if (a[0] == '\b' && i > 0)
				{
					bar(x + i * textlenth - textlenth, y , x + (i+1) * textlenth +10, y + length_y);
					i--;
					line(textstart + x + (i) * textlenth,y+5,textstart + x + (i) * textlenth,y+length_y-5);
					password[i] = '\0';//清除
				}
			}
			else
			{
				break;
			}
		}
		else
		{
			if (a[0] != '\n' && a[0] != '\r')//按下回车
			{
				if (a[0] == '\b' && i > 0)
				{
					bar(x + i * textlenth - textlenth, y , x + (i+1) * textlenth +10, y + length_y);
					i--;
					line(textstart + x + (i) * textlenth,y+5,textstart + x + (i) * textlenth,y+length_y-5);
					password[i] = '\0';//清除
				}
			}
			else
			{
				break;
			}
		}
	}
	strcpy(input,password);//展示输入内容
}
/******************************************************************
		【输入框函数】(第三次修改)
编写人：徐哲轩
传入：data(按钮参数),button(鼠标关于按钮的历史状态)
		input(储存输入的内容),text(输入框显示的文本)
		key(是否以*符号展示)
传出：void
函数功能：在指定位置生成指定样式和大小的输入框,
*******************************************************************/
void CreateButton_INPUT_3  (int *data,int* button,char* input,char* text,int key)
//如果鼠标没按按钮，函数返回0，按下，函数返回跳转的页面编号
//have 8 data
//传入button是为了查看上次按钮的状态,防止闪烁
//1.2定位，3.4大小，5字间距，6字的开始位置，7字的最大输入个数，8字的字体，9字的大小
{
	int length_x = data[2];
	int length_y = data[3];
	int x = data[0];
	int y = data[1];

	if(mouse_press(x, y, x+length_x,y+length_y) != *button)
	{
		if(mouse_press(x, y, x+length_x,y+length_y) == 0)
		{
			CreateButton_INPUT_3_Draw(data,input,text,key,1);
			*button = 0;			
		}
		else
		{
			CreateButton_INPUT_3_Draw(data,input,text,key,0);
			*button = 2;	
		}
	}
	if(mouse_press(x, y, x+length_x,y+length_y) == 1)
	{
		char t;
		for(;bioskey(1);)
		{
			t = bioskey(0);
			if(t){}
		}//清楚键盘缓冲区
		INPUTbutton_3(data,input,key);
		*button = 1;
		clrmous(MouseX,MouseY);
		newmouse(&MouseX,&MouseY,&press);
	}	
}

/******************************************************************
		【按钮锁定函数】
编写人：徐哲轩
传入：old(按钮的历史状态)，count（是否锁定），
		change 按钮样式，check 检测的目标，style 检测模式
传出：int（修改按钮的状态，1为解锁，3为锁定）
函数功能：检测输入框是否有内容，有的话则解锁按钮，
		改变按钮样式，没有的话则锁定按钮，禁止点击
*******************************************************************/
int Button_4_Lock(int old,int* count,int* change,char*check,int style)
{
	int back;
	back = old;
	if(style == 1)//是否检测
	{
		if(check[0] == 0)//输入框为空
		{
			if(*count == 0)
			{//处于即将锁定状态
				back = 3;//给按钮传入3，锁定
			}
			if(*count == 1)
			{//处于未锁定状态
				*change = 0;//改变按钮样式
				back = 1;//按钮刷新，让样式改变
				*count = 0;//进入即将锁定状态
			}
		}
		else
		{
			if(old == 3)
			{//处于锁定状态
				*change = 1;//改变按钮样式
				back = 1;//按钮刷新，让样式改变
				*count = 1;//进入解锁状态
			}
		}		
	}
	//返回状态
	return back;
}
