#include "common.h"
/******************************************************************
	【挂号单绘制函数】
编写人：樊范   徐哲轩
传入：PatientData* p（患者数据）
传出： void 
函数功能：挂号页面操作 ，个性化选择挂号 
*******************************************************************/

void Re_List_Page(PatientData* p)
{
	int x=196;
	int y=40;
	char number[5] = {0};
	char hanzi[8] = {0};
	CHAR_INT_Change2(number,p->numreg,4);


	cleardevice();
	setbkcolor(WHITE);
	setfillstyle(11,LIGHTBLUE);
	bar(0,0,640,480);
	frameline();
	setfillstyle(1,WHITE);
	bar(x,y,x+248,y+400);
	setfillstyle(1,LIGHTBLUE);
	bar(x+280,y+360,x+420,y+400);
	puthz(x+285, y+365, "我已知晓", 32, 32, WHITE);
	setlinestyle(0,0,5);
	setcolor(DARKGRAY);
	rectangle(x+280,y+360,x+420,y+400);
	puthz(x+55, y+30, "华中科技大学校医院", 16, 16, DARKGRAY);
	puthz(x+56, y+31, "华中科技大学校医院", 16, 16, DARKGRAY);
	puthz(x+35, y+50, "门诊挂号凭证", 24, 32, DARKGRAY);
	puthz(x+36, y+51, "门诊挂号凭证", 24, 32, DARKGRAY);

	settextstyle(1,0,2);
	puthz(x+26, y+90, "单号：", 24, 24, DARKGRAY);
	outtextxy(x+26+24*3+5,y+90-3,number);

	puthz(x+26, y+130, "姓名：", 16, 16, DARKGRAY);
	outtextxy(x+26+16*3+5,y+130-6,p->name);

	puthz(x+26, y+150, "门诊类别：", 16, 16, DARKGRAY);
	DoctorShow(p->doctor,hanzi,1);
	puthz(x+26+16*5+5, y+150-3, hanzi, 16, 16, DARKGRAY);

	puthz(x+26, y+170, "科室类别：", 16, 16, DARKGRAY);
	DoctorShow(p->doctor,hanzi,2);
	puthz(x+26+16*5+5, y+170-3, hanzi, 16, 16, DARKGRAY);

	puthz(x+26, y+190, "医师：", 16, 16, DARKGRAY);
	DoctorShow(p->doctor,hanzi,3);
	puthz(x+26+16*3+5, y+190-3, hanzi, 16, 16, DARKGRAY);

	puthz(x+26, y+210, "支付金额：", 16, 16, DARKGRAY);
	CHAR_INT_Change2(number,p->paymed,4);
	outtextxy(x+26+16*5+5,y+210-3,number);

	puthz(x+26, y+230, "支付方式：线上支付", 16, 16, DARKGRAY);
	puthz(x+26, y+250, "挂号日期：", 16, 16, DARKGRAY);
	settextstyle(1,0,1);
	outtextxy(x+26+16*5,y+250-3,p->timer);

	puthz(x+26, y+270, "就诊位置：门诊二楼", 16, 16, DARKGRAY);
	setlinestyle(1,0,1);
	line(x+10,y+290,x+238,y+290);
	setlinestyle(0,0,3);
	line(x+10,y+358,x+33,y+358);
	line(x+238,y+358,x+215,y+358);

	settextstyle(2,0,4);
	outtextxy(x+26,y+295,"If you miss your call,please wait " );
	outtextxy(x+26,y+305,"patiently for a new call " );
	outtextxy(x+26,y+315,"After seeing a doctor, patients " );
	outtextxy(x+26,y+325,"can voluntarily choose to print bills" );
	outtextxy(x+26,y+335,"at the window" );


	puthz(x+36, y+350, "凭此券就诊", 16, 16, DARKGRAY);
	puthz(x+36, y+350, "凭此券就诊", 16, 16, DARKGRAY);
	puthz(x+146, y+350, "当日有效", 16, 16, DARKGRAY);
	puthz(x+37, y+351, "凭此券就诊", 16, 16, DARKGRAY);
	puthz(x+147, y+351, "当日有效", 16, 16, DARKGRAY);

}

/******************************************************************
	【挂号单操作函数】
编写人：樊范
传入：PatientData* p（患者数据）
传出： int page(页面跳转）
函数功能：挂号单页面操作，并进行页面跳转
*******************************************************************/

int Re_List(PatientData* p)

{
	int x=196;
	int y=40;
	int page = 0;
	clrmous(MouseX,MouseY);
	Re_List_Page(p);//绘制挂号单
	while(page == 0)
	{
		newmouse(&MouseX,&MouseY,&press);
		while(1)
		{
			if (MouseX > 600 && MouseY > 0 && MouseX < 640 && MouseY < 40)
			{
				MouseS = 1;
				break;
			}
			else if (MouseX > x+280 && MouseY > y+360 && MouseX < x+420 && MouseY < y+400)
			{
				MouseS = 1;
				break;
			}
			else
			{
				MouseS = 0;
				break;
			}
		}

		if(mouse_press(600, 0, 600+40 , 0 + 40) == 1)
		{
		  page = 0;
		  delay(200);
		  break; 
		}//关闭 
		else if(mouse_press(x+280,y+360,x+420,y+400) == 1)
		{
		  page = 0;
		  delay(200);
		  break; 
		}//关闭
	}
	return page;
 }
