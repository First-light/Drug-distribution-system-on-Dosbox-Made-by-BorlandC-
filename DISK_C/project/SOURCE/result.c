#include <common.h>

/******************************************************************
	【诊断结果绘制函数】 
编写人：樊范   徐哲轩 
传入：PatientData* p（患者数据） int choose（问诊结果） 
传出： void 
函数功能：绘制诊断结果页面并显示结果 
*******************************************************************/

void Result_Page(PatientData* p)
{
	int i=0;
	int x=50;
	int y=73;
	int choose;
	MED*medicine = (MED*)malloc(sizeof(MED));//创建一个工具结构 
	char number[5] = {0};
	char old[4] = {0};
	char hanzi[8] = {0};
	cleardevice();
	setbkcolor(WHITE);
	setfillstyle(11,LIGHTBLUE);
	bar(0,0,640,480);
	frameline();
    setfillstyle(1,WHITE);
    bar(x,y,x+540,y+334);
    setlinestyle(0,0,1);
    setcolor(DARKGRAY);
    for(i=0;i<30;i++)
    {
    	line(x+3*i+5,y+5,x+3*i+5,y+30+5);
	}
    setlinestyle(0,0,3);
    line(x+5,y+5,x+5,y+30+5);
    line(x+3*29+5,y+5,x+3*29+5,y+30+5);
    line(x+3*9+5,y+5,x+3*9+5,y+30+5);//二维码 
	puthz(x+105, y+30, "华中科技大学校医院门诊处方笺", 24, 24, DARKGRAY); 
	puthz(x+106, y+31, "华中科技大学校医院门诊处方笺", 24, 24, DARKGRAY); 
	setcolor(DARKGRAY);
    settextstyle(2,0,2);
	outtextxy(x+5,y+35,"*2  0  2  3  A  I  A  *" );
	setlinestyle(0,0,1);
	line(x+5,y+73,x+535,y+73);
	settextstyle(1,0,2);
	CHAR_INT_Change2(number,p->numreg,4);
	puthz(x+5, y+55, "序号：", 16, 16, DARKGRAY);
	outtextxy(x+5+16*3+5,y+55-5,number);
	
	puthz(x+5, y+75, "姓名：", 16, 16, DARKGRAY);
	outtextxy(x+5+16*3+5,y+75-5,p->name);
	
	puthz(x+220, y+75, "性别：", 16, 16, DARKGRAY);
	if(p->sexual)
	{
		puthz(x+220+16*3+5, y+75, "女", 16, 16, DARKGRAY);
	}else
	{
		puthz(x+220+16*3+5, y+75, "男", 16, 16, DARKGRAY);
	}
	
	puthz(x+320, y+75, "年龄：", 16, 16, DARKGRAY);
	CHAR_INT_Change(old,p->age);
	outtextxy(x+320+16*3+5,y+75-3,old);
	
	puthz(x+270, y+95, "开据日期：", 16, 16, DARKGRAY);
	outtextxy(x+270+16*5+5,y+95-3,p->timer);
	
	puthz(x+5, y+95, "科室：", 16, 16, DARKGRAY);
	DoctorShow(p->doctor,hanzi,2);
	puthz(x+5+16*3+5, y+95,hanzi, 16, 16, DARKGRAY);
	
	puthz(x+5, y+115, "临床诊断：", 16, 16, DARKGRAY);
	choose = p->window;
			if(p->doctor[1] == '1')
			{
				if(choose == 1)
				{
					puthz(x+130, y+115, "感冒", 16, 16, DARKGRAY);
				}
				else if(choose == 2)
				{
					puthz(x+130, y+115, "发烧", 16, 16, DARKGRAY);
				}
			}
			else if(p->doctor[1] == '2')
			{
				if(choose == 1)
				{
					puthz(x+130, y+115, "哮喘", 16, 16, DARKGRAY);
				}
				else if(choose == 2)
				{
					puthz(x+130, y+115, "冠心病", 16, 16, DARKGRAY);
				}
			}
			else if(p->doctor[1] == '3')
			{
				if(choose == 1)
				{
					puthz(x+130, y+115, "骨折", 16, 16, DARKGRAY);
				}
				else if(choose == 2)
				{
					puthz(x+130, y+115, "伤口感染", 16, 16, DARKGRAY);
				}
			}
			else if(p->doctor[1] == '4')
			{
				if(choose == 1)
				{
					puthz(x+130, y+115, "痛经", 16, 16, DARKGRAY);
				}
				else if(choose == 2)
				{
					puthz(x+130, y+115, "阴道炎", 16, 16, DARKGRAY);
				}
			}
			else if(p->doctor[1] == '5')
			{
				if(choose == 1)
				{
					puthz(x+130, y+115, "呼吸道感染", 16, 16, DARKGRAY);
				}
				else if(choose == 2)
				{
					puthz(x+130, y+115, "腹泻", 16, 16, DARKGRAY);
				}
			}
			else if(p->doctor[1] == '6')
			{
				if(choose == 1)
				{
					puthz(x+130, y+115, "抑郁症", 16, 16, DARKGRAY);
				}
				else if(choose == 2)
				{
					puthz(x+130, y+115, "双相情感障碍", 16, 16, DARKGRAY);
				}
			}
			else if(p->doctor[1] == '7') 
			{
				if(choose == 1)
				{
					puthz(x+130, y+115, "热射病", 16, 16, DARKGRAY);
				}
				else if(choose == 2)
				{
					puthz(x+130, y+115, "食物中毒", 16, 16, DARKGRAY);
				}
			}
	
	
	
	line(x+5,y+132,x+535,y+132);
	settextstyle(3,0,4);
	outtextxy(x+5,y+135,"RP" );
	outtextxy(x+4,y+134,"RP" );
	line(x+5,y+300,x+535,y+300);
	puthz(x+5, y+302, "诊断医师：", 16, 16, DARKGRAY);
	DoctorShow(p->doctor,hanzi,3);
	puthz(x+5+16*5+5, y+302,hanzi, 16, 16, DARKGRAY);
	
	puthz(x+200, y+302, "药品总金额：", 16, 16, DARKGRAY);
	CHAR_INT_Change2(number,p->paymed,4);
	settextstyle(1,0,3);
	outtextxy(x+200+6*16+5,y+302-5,number);
	puthz(x+200+6*16+5+60, y+302, "元", 16, 16, DARKGRAY);
	
	puthz(x+400, y+302, "缴费：", 16, 16, DARKGRAY);
	setcolor(DARKGRAY); 
	settextstyle(3,0,1);
	for(i=0;i<5;i++)
	{
		if(p->medicine_list[i][0] != 0){
			char output[25] ={0}; 
			char count[2] = {0};
			char moneyout[4] = {0};
			FILE*fp; 
			fp=fopen("C:\\project\\DATABASE\\drugdata.txt","r");
			for(; ;)
			{	
				fscanf(fp,"%d\t%d\t%s\t%d\t%d\t%d\n",&medicine->ID,&medicine->Store_No,medicine->name,&medicine->price,&medicine->margin,&medicine->inventory);
				if(medicine->ID == (p)->medicine_list[i][0] && (p)->medicine_list[i][1] != 0)
				{		
					strcpy(output,medicine->name);
					CHAR_INT_Change2(count,(p)->medicine_list[i][1],1);
					CHAR_INT_Change2(moneyout,medicine->price,3);
						outtextxy(x+280,y+135+30*i,moneyout);
						outtextxy(x+360,y+135+30*i," *  " );
						outtextxy(x+140,y+135+30*i,output);
						outtextxy(x+400,y+135+30*i,count);
					break;
				}
				if(feof(fp))break;
			}
			fclose(fp);	
		}
	}
	
	
	if(p->payreg >= 2)
	{
		setcolor(RED);
		setlinestyle(0,0,3);
		circle(x+470, y+282,50) ;
		delay(500);
		circle(x+470, y+282,45) ;
		delay(500);
		puthz(x+445, y+278, "已缴费", 16, 16, RED);//已缴费印章 
		delay(1000);
	}
	 free(medicine);
}


/******************************************************************
	【诊断结果主函数】 
编写人：樊范
传入：PatientData* p（患者数据） int choose（患者在问诊时的选择） 
传出： int page(页面跳转） 
函数功能：挂号单页面操作，并进行页面跳转 
*******************************************************************/

int Result_List(PatientData* p)

{
    int x=196;
	int y=40;
	int page=0;
	clrmous(MouseX,MouseY); 
	Result_Page(p);//绘制诊断界面 
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
