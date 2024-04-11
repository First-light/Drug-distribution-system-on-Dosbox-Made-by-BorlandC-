#include <common.h>
/******************************************************************
	【医生问诊函数】 
编写人：樊范 
传入：PatientData* p（病人信息） 
传出：int choose（病人根据对应病症的选择） 
函数功能：实现医生模拟问诊，并传出别人的选择 
*******************************************************************/

int Diagnos_dotor(PatientData* p)
{ 
    int x = 160;
	int y = 120;
	int choose = 0;
	clrmous(MouseX,MouseY); 
	setlinestyle(0,0,5);
    setcolor(DARKGRAY);
    setfillstyle(1,WHITE);
    bar(x,y,x+320,y+240);
    setfillstyle(1,BROWN);
    bar(x,y,x+320,y+40);
    puthz(x+5, y+5, "医生问诊", 32, 32, DARKGRAY);
	puthz(x+5,y+ 55, "您现在感觉怎么样？", 24, 24, DARKGRAY);
	rectangle(x,y,x+320,y+240);
	rectangle(x+30,y+140,x+150,y+200);
	rectangle(x+170,y+140,x+290,y+200);
		
	if(p->doctor[1] == '1')
	{
		puthz(x+35,y+ 145, "流鼻涕", 24, 24, DARKGRAY);
		puthz(x+175,y+ 145, "浑身发热", 24, 24, DARKGRAY);
	}
	else if(p->doctor[1] == '2')
	{
		puthz(x+35,y+ 145, "呼吸不畅", 24, 24, DARKGRAY);
		puthz(x+35,y+ 170, "喘气", 24, 24, DARKGRAY);
		puthz(x+175,y+ 145, "胸痛心悸", 24, 24, DARKGRAY);
	}
	else if(p->doctor[1] == '3')
	{
		puthz(x+35,y+ 145, "肢体经磕碰", 24, 24, DARKGRAY);
		puthz(x+35,y+ 170, "剧烈疼痛", 24, 24, DARKGRAY);
		puthz(x+175,y+ 145, "伤口化脓", 24, 24, DARKGRAY);
	}
	else if(p->doctor[1] == '4')
	{
		puthz(x+35,y+ 145, "月经期腹部", 24, 24, DARKGRAY);
		puthz(x+35,y+ 170, "剧烈疼痛", 24, 24, DARKGRAY);
		puthz(x+175,y+ 145, "阴道分泌物", 24, 24, DARKGRAY);
		puthz(x+175,y+ 170, "异常", 24, 24, DARKGRAY);
	}
	else if(p->doctor[1] == '5')
	{
		puthz(x+35,y+ 145, "小朋友", 24, 24, DARKGRAY);
		puthz(x+35,y+ 170, "呼吸困难", 24, 24, DARKGRAY);
		puthz(x+175,y+ 145, "小朋友", 24, 24, DARKGRAY);
		puthz(x+175,y+ 170, "经常拉肚子", 24, 24, DARKGRAY);
	}
	else if(p->doctor[1] == '6')
	{
		puthz(x+35,y+ 145, "心情", 24, 24, DARKGRAY);
		puthz(x+35,y+ 170, "持续低落", 24, 24, DARKGRAY);
		puthz(x+175,y+ 145, "时而亢奋", 24, 24, DARKGRAY);
		puthz(x+175,y+ 170, "时而消极", 24, 24, DARKGRAY);
	}
	else if(p->doctor[1] == '7')
	{
		puthz(x+35,y+ 145, "头晕多汗", 24, 24, DARKGRAY);
		puthz(x+35,y+ 170, "四肢湿冷", 24, 24, DARKGRAY);
		puthz(x+175,y+ 145, "剧烈呕吐", 24, 24, DARKGRAY);
		puthz(x+175,y+ 170, "腹痛痉挛", 24, 24, DARKGRAY);
	}//问诊界面的绘制 

	while(choose == 0)
	{
		newmouse(&MouseX,&MouseY,&press);

		while(1)
		{
			if (MouseX > x+30 && MouseY > y+140 && MouseX < x+150 && MouseY < y+200)
			{
				MouseS = 1;
				break;
			}// 选择一 
			else if (MouseX > x+170 && MouseY > y+140 && MouseX < x+290 && MouseY < y+200)
			{
				MouseS = 1;
				break;
			}//选择二 
			else
			{
				MouseS = 0;
				break;
			}
		}

		if(mouse_press(x+30,y+140,x+150,y+200) == 1)
		{
		  choose = 1;
		  delay(200);
		  break; 
		}//离开 
		else if(mouse_press(x+170,y+140,x+290,y+200) == 1)
		{
		  choose = 2;
		  delay(200);
		  break; 
		}//离开 
	}
	clrmous(MouseX,MouseY);
	return choose; //返回选择 
}


/******************************************************************
	【医生诊断中函数】 
编写人：樊范 
传入：PatientData* p（病人信息） 
传出：int choose（病人根据对应病症的选择） 
函数功能：实现医生模拟诊断全流程，并传出病人的选择 
*******************************************************************/


int Diagnos_screen(PatientData* p)
{

	int i=11;
	int choose=0;
	char nowchar[4]="\0";//百分比记录
	char nowchar_d[4]="\0";//患者年龄char型
	cleardevice();
	setbkcolor(WHITE);
	setfillstyle(11,YELLOW);
	bar(0, 0, 640 , 480);
	puthz(35, 35, "诊断中。。。。。", 48, 48, DARKGRAY);
	settextstyle(1,0,3);
	setcolor(DARKGRAY);
	rectangle(69,369,571,421);
	for(i=0;i<100;i++)
	{
		setfillstyle(4,LIGHTBLUE);
		bar(70,370,75+5*i,420);
		int_trans_char(i+1,nowchar);
		outtextxy(500,340,nowchar);
		outtextxy(550,340,"%");
		delay(100);
		if(i==99)
		{
			break;
		}
		else if(i==10)
		{
			puthz(35, 100, "姓名：", 24, 24, DARKGRAY);
			outtextxy(110,100,p->name);

		}
		else if(i==20)
		{
			puthz(35, 140, "年龄：", 24, 24, DARKGRAY);
			int_trans_char(p->age,nowchar_d);
			outtextxy(110,140,nowchar_d);
		}
		else if(i==25)
		{
				choose = Diagnos_dotor(p);
					cleardevice();
			   setbkcolor(WHITE);
			  setfillstyle(11,YELLOW);
				  bar(0, 0, 640 , 480);
			 puthz(35, 35, "诊断中。。。。。", 48, 48, DARKGRAY);
		 settextstyle(1,0,3);
			setcolor(DARKGRAY);
		  rectangle(69,369,571,421);
			puthz(35, 100, "姓名：", 24, 24, DARKGRAY);
			outtextxy(110,100,p->name);

			puthz(35, 140, "年龄：", 24, 24, DARKGRAY);
			int_trans_char(p->age,nowchar_d);
			outtextxy(110,140,nowchar_d);
	}//显示患者基本信息
		else if(i==30)
		{
			puthz(35, 180, "病症：", 24, 24, DARKGRAY);
		}
		else if(i==60)
		{
			if(p->doctor[1] == '1')
			{
				if(choose == 1)
				{
					puthz(110, 180, "感冒", 24, 24, DARKGRAY);
				}
				else if(choose == 2)
				{
					puthz(110, 180, "发烧", 24, 24, DARKGRAY);
				}
			}
			else if(p->doctor[1] == '2')
			{
				if(choose == 1)
				{
					puthz(110, 180, "哮喘", 24, 24, DARKGRAY);
				}
				else if(choose == 2)
				{
					puthz(110, 180, "冠心病", 24, 24, DARKGRAY);
				}
			}
			else if(p->doctor[1] == '3')
			{
				if(choose == 1)
				{
					puthz(110, 180, "骨折", 24, 24, DARKGRAY);
				}
				else if(choose == 2)
				{
					puthz(110, 180, "伤口感染", 24, 24, DARKGRAY);
				}
			}
			else if(p->doctor[1] == '4')
			{
				if(choose == 1)
				{
					puthz(110, 180, "痛经", 24, 24, DARKGRAY);
				}
				else if(choose == 2)
				{
					puthz(110, 180, "阴道炎", 24, 24, DARKGRAY);
				}
			}
			else if(p->doctor[1] == '5')
			{
				if(choose == 1)
				{
					puthz(110, 180, "呼吸道感染", 24, 24, DARKGRAY);
				}
				else if(choose == 2)
				{
					puthz(110, 180, "腹泻", 24, 24, DARKGRAY);
				}
			}
			else if(p->doctor[1] == '6')
			{
				if(choose == 1)
				{
					puthz(110, 180, "抑郁症", 24, 24, DARKGRAY);
				}
				else if(choose == 2)
				{
					puthz(110, 180, "双相情感障碍", 24, 24, DARKGRAY);
				}
			}
			else if(p->doctor[1] == '7')
			{
				if(choose == 1)
				{
					puthz(110, 180, "热射病", 24, 24, RED);
				}
				else if(choose == 2)
				{
					puthz(110, 180, "食物中毒", 24, 24,RED);
				}
			}
		}//显示所诊断的病症
		else if(i==80)
		{
			if(p->doctor[1] == '7'){
				puthz(35, 240, "正在进行紧急评估和救治！经处理后解除紧急情况。。。", 24, 24,RED);
			}else{
				puthz(35, 240, "正在进行其他检查，并开具药单。。。。", 24, 24, DARKGRAY);
			}
		}//显示急诊救治
		else if(i==80)
		{
			puthz(35, 240, "正在进行其他诊断，并开具药单。。。。", 24, 24, DARKGRAY);
		}//显示其他流程
		else if(i==90)
		{
			puthz(35, 300, "医生建议：", 24, 24, DARKGRAY);
		}
		else if(i==98)
		{
			if(p->doctor[1] == '1')
			{
				if(choose == 1)
				{
					puthz(160, 300, "注意休息，避免长时间熬夜，保证充足的睡眠，", 16, 16, DARKGRAY);
					puthz(160, 320, "使体力得到恢复，多吃高维生素高蛋白食物", 16, 16, DARKGRAY);
				}
				else if(choose == 2)
				{
					puthz(160, 300, "多喝水，勤排尿，呼吸新鲜空气，避免劳累受凉，", 16, 16, DARKGRAY);
					puthz(160, 320, "一定要多休息，清淡饮食，保持心情愉快舒畅", 16, 16, DARKGRAY);
				}
			}
			else if(p->doctor[1] == '2')
			{
				if(choose == 1)
				{
					puthz(160, 300, "避免接触过敏原，注意锻炼，提高免疫力，用药方面，", 16, 16, DARKGRAY);
					puthz(160, 320, "患者不要擅自停药", 16, 16, DARKGRAY);
				}
				else if(choose == 2)
				{
					puthz(160, 300, "患者必须坚持服药，控制血压，血糖，血脂。", 16, 16, DARKGRAY);
					puthz(160, 320, "戒烟限酒，以及改善生活方式，适当进行活动", 16, 16, DARKGRAY);
				}
			}
			else if(p->doctor[1] == '3')
			{
				if(choose == 1)
				{
					puthz(160, 300, "应保持骨折稳定性，避免做影响骨折愈合的暴力活动、", 16, 16, DARKGRAY);
					puthz(160, 320, "被动牵拉、过早负重，以及过大范围活动等", 16, 16, DARKGRAY);
				}
				else if(choose == 2)
				{
					puthz(160, 300, "清创引流，去除坏死的组织，充分的引流，定期进行换药，", 16, 16, DARKGRAY);
					puthz(160, 320, "注意饮食调理，适当的补充营养", 16, 16, DARKGRAY);
				}
			}
			else if(p->doctor[1] == '4')
			{
				if(choose == 1)
				{
					puthz(160, 300, "建议可以喝一些热的红糖生姜水，也可以用热水", 16, 16, DARKGRAY);
					puthz(160, 320, "袋热敷腹部，必要时在医生的指导下服用镇痛的药物", 16, 16, DARKGRAY);
				}
				else if(choose == 2)
				{
					puthz(160, 300, "建议中和局部用药和口服用药，保持感觉卫生，", 16, 16, DARKGRAY);
					puthz(160, 320, "提升睡眠质量", 16, 16, DARKGRAY);
				}
			}
			else if(p->doctor[1] == '5')
			{
				if(choose == 1)
				{
					puthz(160, 300, "可遵医嘱服用阿莫西林、罗红霉素等抗生素类药物，", 16, 16, DARKGRAY);
					puthz(160, 320, "在呼吸道感染期间要保证充足的休息时间", 16, 16, DARKGRAY);
				}
				else if(choose == 2)
				{
					puthz(160, 300, "注意情绪，注意饮食，合理服用药物并适当休息，", 16, 16, DARKGRAY);
					puthz(160, 320, "可以辅以按摩治疗", 16, 16, DARKGRAY);
				}
			}
			else if(p->doctor[1] == '6')
			{
				if(choose == 1)
				{
					puthz(160, 300, "接受专业的心理医生的心理疏导，可多和家人、朋友", 16, 16, DARKGRAY);
					puthz(160, 320, "进行沟通，保持积极乐观的心态，必要时辅以药物治疗", 16, 16, DARKGRAY);
				}
				else if(choose == 2)
				{
					puthz(160, 300, "消减压力，接受适当积极的心理疏导，多去室外", 16, 16, DARKGRAY);
					puthz(160, 320, "活动放松身心，清淡饮食", 16, 16, DARKGRAY);
				}
			}
			else if(p->doctor[1] == '7')
			{
				puthz(160, 300, "接受进一步检查和治疗", 24, 24, RED);
			}
		}//显示医生建议
		setfillstyle(11,YELLOW);
		bar(500,345,530,365);
	}//全流程加载界面各个节点的信息显示
	setfillstyle(11,YELLOW);
	bar(35,35,500,100);
	puthz(35, 35, "诊断完成，请查询结果", 48, 48, DARKGRAY);
	setfillstyle(1,LIGHTBLUE);
	bar(470,430,590,470);
	puthz(480, 440, "确认知晓", 24, 24, WHITE);
	rectangle(470,430,590,470);
	return choose;
}

/******************************************************************
	【医生诊断结束后的操作函数】
编写人：樊范 
传入：PatientData* p（病人信息） 
传出：int choose（病人根据对应病症的选择） 
函数功能：实现医生模拟诊断全流程结束后的操作，并传出病人的选择 
*******************************************************************/

int diagnosising(PatientData* p)
{
	int page = 0;
	int choose = Diagnos_screen(p);
	clrmous(MouseX,MouseY);
	while(page == 0)
	{
		newmouse(&MouseX,&MouseY,&press);

		while(1)
		{
			if (MouseX > 470 && MouseY > 430 && MouseX < 590 && MouseY < 470)
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

		if(mouse_press(470,430,590,470) == 1)
		{
		  page = 0;
		  delay(200);
		  break; 
		}//离开 
	}
	return choose;
}   
