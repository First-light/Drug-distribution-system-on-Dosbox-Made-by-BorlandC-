#include <common.h>

/******************************************************************
		【患者选择界面绘图函数】
编写人：樊范
传入：void
传出：void
函数功能：画出界面
*******************************************************************/
void p1_screen(void)
{
	int x = 160;
	int y = 0;
	int i = 0;
	cleardevice();
	setbkcolor(WHITE);
	setcolor(DARKGRAY);
	setlinestyle(0, 0, 3);
	setfillstyle(11,YELLOW);
    bar(0, 0, 640 , 480);
    rectangle(x,y+210,x+30,y+245);
    rectangle(x,y+255,x+30,y+290);
	rectangle(x,y,x+80,y+200);
	puthz(x+15, y+80, "药房", 24, 24, DARKGRAY);
    rectangle(x,y+300,x+120,y+480);
    puthz(x+25, y+380, "挂号处", 24, 24, DARKGRAY);
	rectangle(x+140,y,x+320,y+200);
	puthz(x+200, y+80, "门诊", 24, 24, DARKGRAY);
    rectangle(x+200,y+300,x+320,y+480);
    puthz(x+220, y+380, "收费处", 24, 24, DARKGRAY);
    rectangle(x+220,y+200,x+320,y+300);
    puthz(x+235, y+235, "护士站", 24, 24, DARKGRAY);
	setcolor(DARKGRAY);
	setlinestyle(0, 0, 3);
	line(160,0,160,480);
	line(480,0,480,480);
	puthz(20, 40, "您的序号：", 16, 16, DARKGRAY);
	rectangle(20,100,140,160);
	puthz(30, 115, "我要取药", 24, 24, DARKGRAY);
	rectangle(20,220,140,280);
	puthz(30, 235, "查询状态", 24, 24, DARKGRAY);
	rectangle(20,360,140,420);
	puthz(30, 375, "我要挂号", 24, 24, DARKGRAY);
	rectangle(500,60,620,120);
	puthz(510, 75, "我要就诊", 24, 24, DARKGRAY);
	rectangle(500,360,620,420);
	puthz(510, 375, "我要缴费", 24, 24, DARKGRAY);
	rectangle(500,y+220,620,y+280);
	puthz(510, y+235, "我要咨询", 24, 24, DARKGRAY);
	setfillstyle(11,LIGHTRED);
	bar(280,420,360,480);
	rectangle(280,420,360,480);
	puthz(295, 435, "离开", 24, 24, DARKGRAY);
	setlinestyle(0, 0, 1);
	for(i=0;i<10;i++)
	{
		line(x+110,y+5*(i+1),x+140,y+5*(i+1));
	}
	line(x+110,y,x+110,y+50);
}

/******************************************************************
		【就医流程提示函数】
编写人：樊范
传入：void
传出：void
函数功能：展示就医流程
*******************************************************************/
void Notice_Page_p1(void)
{
	int y = 0;
	cleardevice();
	setbkcolor(WHITE);
	setfillstyle(11,YELLOW);
    bar(0, 0, 640 , 480);
    setfillstyle(1,WHITE);
    bar(160,0,480,480);
	setcolor(DARKGRAY);
	setlinestyle(0, 0, 3);
	line(160,40,480,40);
	line(160,0,160,480);
	line(480,0,480,480);
	rectangle(20,100,140,160);
	puthz(30, 115, "我要取药", 24, 24, DARKGRAY);
	rectangle(20,220,140,280);
	puthz(30, 235, "查询状态", 24, 24, DARKGRAY);
	rectangle(20,360,140,420);
	puthz(30, 375, "我要挂号", 24, 24, DARKGRAY);
	rectangle(500,60,620,120);
	puthz(510, 75, "我要就诊", 24, 24, DARKGRAY);
	rectangle(500,360,620,420);
	puthz(510, 375, "我要缴费", 24, 24, DARKGRAY);
	rectangle(500,y+220,620,y+280);
	puthz(510, y+235, "我要咨询", 24, 24, DARKGRAY);
	
    setfillstyle(1,RED);
    bar(440,0,480,40);
    setfillstyle(11,DARKGRAY);
    bar(160,0,440,40);
    line(445,5,475,35);
	line(445,35,475,5);
    
    puthz(165, 5, "温馨提示", 32, 32, DARKGRAY);
    puthz(245, 45, "就医取药流程", 24, 24, DARKGRAY);
    
    puthz(270, 75, "门诊挂号", 24, 24, DARKGRAY);
    puthz(270, 125, "医生诊断", 24, 24, DARKGRAY);
    puthz(270, 175, "药品缴费", 24, 24, DARKGRAY);
    puthz(270, 225, "等待取药", 24, 24, DARKGRAY);
    
    rectangle(270,70,370,100);
	rectangle(270,120,370,150);
	rectangle(270,170,370,200);
	rectangle(270,220,370,250);
    
    line(320,100,320,120);
    line(315,95,320,120);
    line(325,95,320,120);
    
    line(320,150,320,170);
    line(315,145,320,170);
    line(325,145,320,170);
    
    line(320,200,320,220);
    line(315,195,320,220);
    line(325,195,320,220);
    
    puthz(170, 260, "请遵从以上流程进行就诊", 16, 16, DARKGRAY);
    puthz(170, 280, "患者若不清楚自己的就诊状态，可到大厅左", 16, 16, DARKGRAY);
    puthz(170, 300, "侧查询机器上凭号码查询", 16, 16, DARKGRAY);
    puthz(170, 320, "疫情期间，请佩戴好口罩，保持两米以上安", 16, 16, RED);
    puthz(170, 340, "全距离", 16, 16, RED);
    puthz(170, 380, "谢谢配合！", 16, 16, DARKGRAY);
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		
		while(1)
		{
			if (MouseX > 280 && MouseY > 420 && MouseX < 360 && MouseY < 480)
			{
				MouseS = 1;
				break;
			}//离开 

			else
			{
				MouseS = 0;
				break;
			}
		}

		if(mouse_press(440,0,480,40) == 1)
		{
		  clrmous(MouseX,MouseY);
		  delay(200);
		  break;
		}//离开
	}
}

/******************************************************************
		【状态查询函数】
编写人：樊范
传入：int ID 
传出：void
函数功能：展示患者当前状态
*******************************************************************/
void Inquire_Page_p2(int ID)
{
	int y = 0;
	int j = 0;
	PatientData* head = creat(0);
	PatientData* p = head->next;
	char nowchar[4]={'\0'};
	cleardevice();

	Patient_Setup (head);
	p = head->next;
	while(1)
	{
		if(p->numreg == ID)
		{
			break;
		}
		else if(p->next ==NULL)
		{
			j =1;
			break;
		}
		p = p->next;
	}

	setbkcolor(WHITE);
	setfillstyle(11,YELLOW);
	bar(0, 0, 640 , 480);
	setfillstyle(1,WHITE);
	bar(160,0,480,480);
	setcolor(DARKGRAY);
	setlinestyle(0, 0, 3);
	line(160,40,480,40);
	line(160,0,160,480);
	line(480,0,480,480);
	rectangle(20,100,140,160);
	puthz(30, 115, "我要取药", 24, 24, DARKGRAY);
	rectangle(20,220,140,280);
	puthz(30, 235, "查询状态", 24, 24, DARKGRAY);
	rectangle(20,360,140,420);
	puthz(30, 375, "我要挂号", 24, 24, DARKGRAY);
	rectangle(500,60,620,120);
	puthz(510, 75, "我要就诊", 24, 24, DARKGRAY);
	rectangle(500,360,620,420);
	puthz(510, 375, "我要缴费", 24, 24, DARKGRAY);
	rectangle(500,y+220,620,y+280);
	puthz(510, y+235, "我要咨询", 24, 24, DARKGRAY);

	setfillstyle(1,RED);
	bar(440,0,480,40);
	setfillstyle(11,DARKGRAY);
	bar(160,0,440,40);
	line(445,5,475,35);
	line(445,35,475,5);

	if(j == 0)
	{
	int_trans_char(ID,nowchar);
	settextstyle(1,0,4);
	puthz(165, 5, "温馨提示", 32, 32, DARKGRAY);
	puthz(165, 45, "您好！", 48, 48, DARKGRAY);
	puthz(166, 46, "您好！", 48, 48, DARKGRAY);
	puthz(165, 105, "您的单号为：", 24, 24, DARKGRAY);
	outtextxy(315,95,nowchar);
	puthz(165, 150, "您的状态为：", 24, 24, DARKGRAY);
	puthz(335, 155, "挂号", 24, 24, DARKGRAY);
	puthz(335, 200, "经医生诊断", 24, 24, DARKGRAY);
	puthz(335, 245, "缴药费", 24, 24, DARKGRAY);
	puthz(335, 290, "取药品", 24, 24, DARKGRAY);
	puthz(165, 335, "给您的建议：", 24, 24, DARKGRAY);

	while(1)
	{
		if(p->numreg == ID)
		{
			break;
		}
		p = p->next;
	}

	if(p->payreg == 0)
	{
		puthz(310, 155, "已", 24, 24, GREEN);
		puthz(310, 200, "未", 24, 24, RED);
		puthz(310, 245, "未", 24, 24, RED);
		puthz(310, 290, "未", 24, 24, RED);

		puthz(200, 370, "请先到门诊进行就诊", 16, 16, DARKGRAY);
		puthz(200, 390, "以获取诊断结果和药单", 16, 16, DARKGRAY);

		puthz(185, 420, "祝您身体健康，生活愉快！", 24, 24, DARKGRAY);
		puthz(186, 421, "祝您身体健康，生活愉快！", 24, 24, DARKGRAY);
	}
	else if(p->payreg == 1)
	{
		puthz(310, 155, "已", 24, 24, GREEN);
		puthz(310, 200, "已", 24, 24, GREEN);
		puthz(310, 245, "未", 24, 24, RED);
		puthz(310, 290, "未", 24, 24, RED);

		puthz(200, 370, "请先到收费处完成药品缴费", 16, 16, DARKGRAY);
		puthz(200, 390, "以等待无人自主取药", 16, 16, DARKGRAY);

		puthz(185, 420, "祝您身体健康，生活愉快！", 24, 24, DARKGRAY);
		puthz(186, 421, "祝您身体健康，生活愉快！", 24, 24, DARKGRAY);
	}
	else if(p->payreg == 2 || p->payreg == 3 ||p->payreg == 4|| (p->payreg == 5 && p->nummed != 0))
	{
		puthz(310, 155, "已", 24, 24, GREEN);
		puthz(310, 200, "已", 24, 24, GREEN);
		puthz(310, 245, "已", 24, 24, GREEN);
		puthz(310, 290, "未", 24, 24, RED);

		puthz(200, 370, "请去药房等待取药，取走您的药品", 16, 16, DARKGRAY);
		puthz(200, 390, "结束本次就诊流程", 16, 16, DARKGRAY);

		puthz(185, 420, "祝您身体健康，生活愉快！", 24, 24, DARKGRAY);
		puthz(186, 421, "祝您身体健康，生活愉快！", 24, 24, DARKGRAY);
	}
	else if(p->nummed == 0 && p->payreg == 5 )
	{
		puthz(310, 155, "已", 24, 24, GREEN);
		puthz(310, 200, "已", 24, 24, GREEN);
		puthz(310, 245, "已", 24, 24, GREEN);
		puthz(310, 290, "已", 24, 24, GREEN);

		puthz(200, 370, "恭喜你完成您的诊断流程", 16, 16, DARKGRAY);
		puthz(200, 390, "本次就诊流程结束", 16, 16, DARKGRAY);

		puthz(185, 420, "祝您身体健康，生活愉快！", 24, 24, DARKGRAY);
		puthz(186, 421, "祝您身体健康，生活愉快！", 24, 24, DARKGRAY);
	}

	}
	else
	{
		puthz(165, 150, "您尚未挂号", 32, 32, DARKGRAY);
		puthz(165, 190, "请退出到挂号窗口", 32, 32, DARKGRAY);
		puthz(165, 230, "先进行挂号", 32, 32, DARKGRAY);

	}

	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);

		while(1)
		{
			if (MouseX > 280 && MouseY > 420 && MouseX < 360 && MouseY < 480)
			{
				MouseS = 1;
				break;
			}//离开

			else
			{
				MouseS = 0;
				break;
			}
		}

		if(mouse_press(440,0,480,40) == 1)
		{
		  clrmous(MouseX,MouseY);
		  delay(200);
		  break;
		}//离开
	}
}



/******************************************************************
		【患者选择函数】
编写人：樊范
传入：int *IDnumber
传出：int page 
函数功能：进入患者选择界面，患者可以选择检查自己的状态，也可以改变自己的身份
*******************************************************************/
int p1plus( int *IDnumber)
{
	int page = 0;
	int data[9]={20,60,120,25,10,8,3,2,6};
	char Data_Num[4]={'\0'};
	int m=1;
	clrmous(MouseX,MouseY);
	p1_screen(); 
	CHAR_INT_Change(Data_Num,*IDnumber);
	while(page == 0)
	{
		newmouse(&MouseX,&MouseY,&press);
		
		while(1)
		{
			if (MouseX > 280 && MouseY > 420 && MouseX < 360 && MouseY < 480)
			{
				MouseS = 1;
				break;
			}//离开 
			else if (MouseX > 20 && MouseY > 100 && MouseX < 140 && MouseY < 160)
			{
				MouseS = 1;
				break;
			}//我要取药 
			else if (MouseX > 20 && MouseY > 360 && MouseX < 140 && MouseY < 420)
			{
				MouseS = 1;
				break;
			}//我要挂号 
			else if (MouseX > 500 && MouseY > 60 && MouseX < 620 && MouseY < 120)
			{
				MouseS = 1;
				break;
			}//我要就诊 
			else if (MouseX > 500 && MouseY > 360 && MouseX < 620 && MouseY < 420)
			{
				MouseS = 1;
				break;
			}//我要缴费
			else if (MouseX > 500 && MouseY > 220 && MouseX < 620 && MouseY < 280)
			{
				MouseS = 1;
				break;
			}//我要咨询 
		    else if (MouseX > 20 && MouseY > 220 && MouseX < 140 && MouseY < 280)
			{
				MouseS = 1;
				break;
			}//查询状态
			else
			{
				MouseS = 0;
				break;
			}
		}

		if(mouse_press(280,420,360,480) == 1)
		{
		  page = -1;
		  delay(200);
		  break; 
		}//离开 
		else if(mouse_press(20,360,140,420) == 1)
		{
		  page = 2;
		  delay(200);
		  break; 
		}//挂号 
		else if(mouse_press(500,60,620,120) == 1)
		{
		  page = 4;
		  delay(200);
		  break; 
		}//就诊 
		else if(mouse_press(500,360,620,420) == 1)
		{
		  page = 6;
		  delay(200);
		  break; 
		}//缴费 
		else if(mouse_press(20,100,140,160) == 1)
		{
		  page = 7;
		  delay(200);
		  break; 
		}//取药 
		else if(mouse_press(20,220,140,280) == 1)
		{
		  Inquire_Page_p2(*IDnumber);
		  m = 1;
		  delay(200);
		  p1_screen(); 
		}//状态查询 
        else if(mouse_press(500,220,620,280) == 1)
		{
		  Notice_Page_p1(); 
		  m = 1;
		  delay(200);
		  p1_screen();
		}//咨询 
       CreateButton_INPUT_3  (data,&m,Data_Num,"\0",1);
       if(m == 1)
	   {
       		*IDnumber =	INT_CHAR_Change(Data_Num);
	   }
	}
	return page;
}   
