#include <common.h>
#define p14_button_num 5
/*————————————————————————
				【医生选择界面】 
编写人：徐哲轩
此界面为医生选择不同系统功能的页面
————————————————————————*/


void p14_screen(void)
{
/*—————————————————
		【初始化绘图函数】
编写人：樊范
函数会画出界面的背景。
——————————————————*/
	int data[9] = {10+3,10+3,14,120,50,24,48,-28,2};
	int x;
	int y;
	int length_x;
	int length_y;
	int textsize;
	int textlength;
	x =data[0];
	y = data[1];
	length_x = data[3];
	length_y = data[4];
	textsize = data[5];
	textlength = data[6];
	setcolor(DARKGRAY);
	setlinestyle(0, 0, 3);
	setfillstyle(1,BLUE);
	bar(0,0,190-45,480);
	setfillstyle(1,WHITE);
	bar(0,61+3,190-45,64+3);
	puthz(160,40,"您好医生",32,40,RED);
	puthz(161,41,"您好医生",32,40,RED);
	puthz(160,80,"欢迎进入系统导航页面！",32,40,RED);
	puthz(161,81,"欢迎进入系统导航页面！",32,40,RED);
	setlinestyle(0,0,3);
	setcolor(DARKGRAY);
	line(160,120,600,120);
	line(160,30,310,30);
	puthz(180,130,"挂号统计",24,24,DARKGRAY);
	rectangle(155,130,175,150);
	puthz(180,160,"根据不同的关键词检索患者就诊信息，并可查询单一患者的详细信息，也可为挂号但未诊断患者修改挂号选择",16,16,DARKGRAY);

	puthz(180,210,"药库管理",24,24,DARKGRAY);
	rectangle(155,210,175,230);
	puthz(180,240,"进行药库管理，可查看药库中所有药品的信息，实现出库入库，增添删除，并获取药品库存告急信息",16,16,DARKGRAY);

	puthz(180,290,"配药模拟",24,24,DARKGRAY);
	rectangle(155,290,175,310);
	puthz(180,320,"观察实时立体药库运行，了解取药机器人运行状态，并可呼叫机器人取完药的患者前来窗口取药",16,16,DARKGRAY);

	puthz(180,370,"取药记录",24,24,DARKGRAY);
	rectangle(155,370,175,390);
	puthz(180,400,"根据日期查询药品消耗状况并得知消耗最大的药品，以更加系统科学地管理药库，满足患者需求",16,16,DARKGRAY);
	frameline2();
	setfillstyle(1,BLUE);
	bar(x, y, x+length_x,y+length_y);
	puthz(x+length_x/2-textlength-textsize-data[7],y+length_y/4,"首页",textsize,textlength,LIGHTBLUE);
}


int p14(void)
{
/*——————————————————
		【医生选择界面函数】
		编写人：徐哲轩
———————————————————*/
	int button[p14_button_num] = {1,1,1,1,1};
	int page = 0;
	int page_t = 0;
	
	int data2[9] = {10+3,150+3,26,120,70,24,26,3,2};
	int data3[9] = {10+3,220+3,16,120,70,24,26,3,2};
	int data1[9] = {10+3,80+3,15,120,70,24,26,3,2};
	int data4[9] = {10+3,290+3,23,120,70,24,26,3,2};
	clrmous(MouseX,MouseY);
	MouseS = 0;
	cleardevice();
	setbkcolor(WHITE);
	p14_screen();
	delay(300);
	while(page == 0)
	{
		newmouse(&MouseX,&MouseY,&press);
			
			page_t = CreateButton_OUT(600,0,-1,&button[0]);
			//返回按钮
			if(page_t)
			{
				//数据中转并检测，若按钮函数输出改变的页面跳转量到page_t，则page赋值，并且跳出页面循环，退出页面函数，然后重新选择页面
				page = page_t;
				break;
			}		

			page_t = CreateButton_4  ("挂号统计",data1,& button[1]);
			if(page_t)
			{
				page = page_t;
				break;
			}			

			page_t = CreateButton_4  ("药库管理",data2,& button[2]);
			if(page_t)
			{
				page = page_t;
				break;
			}			
			page_t = CreateButton_4  ("配药模拟",data3,& button[3]);
			if(page_t)
			{
				page = page_t;
				break;
			}
			page_t = CreateButton_4  ("取药记录",data4,& button[4]);
			if(page_t)
			{
				page = page_t;
				break;
			}				

		delay(3);
	}
	return page;    
	//退出页面，返回改变的页面值
}
