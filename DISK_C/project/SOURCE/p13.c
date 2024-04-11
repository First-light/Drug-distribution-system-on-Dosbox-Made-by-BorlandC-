#include <common.h>
#define p13_button_num 5
/*————————————————————————
				【医生登入界面】 
编写人：徐哲轩
此界面实现了医生进入系统时需要输入密码的过程。
————————————————————————*/


void p13_screen(void)
{
/*—————————————————
		【初始化绘图函数】 
		编写人：徐哲轩
		函数会画出界面的背景。
——————————————————*/
	setcolor(DARKGRAY);
	setlinestyle(0, 0, 1);
	setfillstyle(11,YELLOW);
	bar(0,0,640,480);
    frameline2();
	setfillstyle(1,LIGHTBLUE);
	bar(319-150,133,319+150,133+220);
	setfillstyle(1,LIGHTGRAY);
	bar(319-150+2,133+2,319+150-2,133+220-2);
	setfillstyle(1,WHITE);
	bar(319-60,133-60,319+60,133+60);
	bar(319-150+4,133+4,319+150-4,133+220-4);
    Pic_Draw(1,289,100,1);
    setcolor(LIGHTBLUE);
    circle(319,133,55);
    setcolor(LIGHTGRAY);
    circle(319,133,54);
}



int p13(void)
{
/*——————————————————
		【医生登入页面函数】 
		编写人：徐哲轩
。
———————————————————*/
	int button[p13_button_num] = {1,1,1,1,1};
	int page = 0;
	int page_t = 0;
	int buttondata[4] = {425,230,30,30};
	int buttondata2[9] ={220+5,220,190,50,25,8,6,1,4};
	int buttondata3[9] = {220-3+5,280,1,190+6,30+20,24,32,-25,0};
	int key = 0;
	int keyold = key;
	char password[9] = {0};
	int lock = 1;

	clrmous(MouseX,MouseY);
	MouseS = 0;
	cleardevice();
	setbkcolor(WHITE);
	p13_screen();
	delay(300);
	
	while(page == 0)
	{
		int in = 0;
		newmouse(&MouseX,&MouseY,&press);
		
			
		page_t = CreateButton_OUT(600,0,-1,&button[1]);
			//返回按钮
			if(page_t)
			{
				//数据中转并检测，若按钮函数输出改变的页面跳转量到page_t，则page赋值，并且跳出页面循环，退出页面函数，然后重新选择页面
				page = page_t;
				break;
			}		
			
		CreateButton_open  (buttondata,&button[3],&key);
			if(keyold != key)
			{
				keyold = key;
				button[2] = 1;
			}
			
		CreateButton_INPUT_3(buttondata2,&button[2],password,"请输入管理员密码：",key);
			
		in = CreateButton_4("登录",buttondata3,&button[4]);
		button[4] = Button_4_Lock(button[4],&lock,&buttondata3[8],password,1);
			if(in)
			{
				setfillstyle(1,WHITE);
				bar(240,370,420,450);
				if(Password_Check(password))
				{
					page = 14 ;
					puthz(260,390,"密码正确",24,32,BLUE);
					delay(1000);
					break;
				}
				else
				{
					puthz(260,390,"密码错误",24,32,RED);
					delay(500);
				}
			}
			
			if(page_t)
			{
				page = page_t;
				break;
			}	
		delay(2);
	}
	return page;    
	//退出页面，返回改变的页面值
}
