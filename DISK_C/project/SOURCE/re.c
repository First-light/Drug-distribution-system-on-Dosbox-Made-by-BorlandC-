#include <common.h>

/******************************************************************
	【挂号页面绘制函数】 
编写人：樊范 
传入：void 
传出： void 
函数功能：绘制挂号页面 
*******************************************************************/

void Registered_Page(void)
{
	int i=0;
	int x=20;
	int y=20;
	cleardevice();
	setbkcolor(WHITE);
    frameline();
    setlinestyle(0,0,5);
    setcolor(DARKGRAY);
    puthz(x, y, "姓名：", 24, 24, DARKGRAY);
    puthz(x+200, y, "性别：", 24, 24, DARKGRAY);
    puthz(x+280, y, "男", 24, 24, DARKGRAY);
    puthz(x+335, y, "女", 24, 24, DARKGRAY);
    puthz(x+400, y, "年龄：", 24, 24, DARKGRAY);
    puthz(x, y+50, "门诊类型", 24, 24, DARKGRAY);
    puthz(x+205, y+50, "科室种类", 24, 24, DARKGRAY);
    puthz(x+410, y+50, "医生", 24, 24, DARKGRAY);
	rectangle(x,y+75,x+190,y+75+54*3);
    rectangle(x+205,y+75,x+395,y+399);
    rectangle(x+410,y+75,x+600,y+399);
    rectangle(x+305,y,x+330,y+25);
    rectangle(x+360,y,x+385,y+25);
    for(i=0;i<5;i++)
    {
    	line(x+205,y+75+54*(i+1),x+395,y+75+54*(i+1));
	}
	for(i=0;i<3;i++)
    {
    	line(x,y+75+54*(i+1),x+190,y+75+54*(i+1));
	}
	puthz(x+215, y+85, "全科医学科", 24, 24, DARKGRAY);
	puthz(x+215, y+85+54, "内科", 24, 24, DARKGRAY);
	puthz(x+215, y+85+54*2, "外科", 24, 24, DARKGRAY);
	puthz(x+215, y+85+54*3, "妇科", 24, 24, DARKGRAY);
	puthz(x+215, y+85+54*4, "儿科", 24, 24, DARKGRAY);
	puthz(x+215, y+85+54*5, "心理门诊", 24, 24, DARKGRAY);
	puthz(x+10, y+85, "普通门诊", 24, 24, DARKGRAY);
	puthz(x+10, y+85+54, "专家门诊", 24, 24, DARKGRAY);
	puthz(x+10, y+85+54*2, "急诊", 24, 24, DARKGRAY);
	puthz(x, y+240, "挂号价格：", 24, 24, RED);
	puthz(x, y+270, "普通门诊：捌元", 24, 24, RED);
	puthz(x, y+300, "专家门诊：贰拾元", 24, 24, RED);
	puthz(x, y+330, "急诊：拾元", 24, 24, RED);
    setfillstyle(1,LIGHTBLUE);
    bar(x+410,y+410,x+550,y+440);
    puthz(x+415,y+415, "确认并缴费", 24, 24, WHITE);
    setlinestyle(1,0,1);
    line(x,y+30,x+600,y+30);
    line(x,y+35,x+600,y+35);
    setcolor(RED);
    settextstyle(2,0,5);
	outtextxy(x,y+405,"Patients enter their complete personal information " );
	outtextxy(x,y+415,"and select the type of registration, department and"); 
	outtextxy(x,y+360,"If you register the  ");
	outtextxy(x,y+370,"emergency outpatient clinic");
	outtextxy(x,y+380,"you do not need to choose");
	outtextxy(x,y+390,"a department and a doctor");
}

/******************************************************************
	【挂号页面操作函数】 
编写人：樊范  徐哲轩 
传入：void 
传出： void 
函数功能：挂号页面操作 ，个性化选择挂号 
*******************************************************************/

int Registered(int* IDnumber)

{

	int page = 0;
	int x=20;
	int y=20;
	int i=0;
	int flag=0;
	int data1[9]={100,20,110,25,10,2,9,2,6};
	int data2[9]={500,20,90,25,10,2,3,2,6};
	int Outpatient[3]={0};
	int Department[6]={0};//输入框使用参数
	int m=1;
	int n=1;
	char name[15] = {0};
	int De=0;
	char Data_Age[4]={'\0'};
	char INdoctor[5] = {'1','1','0','1'};
	char tim[13] = {0};
	int ID = 1;
	int money = 0;
	int flash = 1;
	char han[8] = {0};
	clrmous(MouseX,MouseY);
	Registered_Page();//绘制界面
	while(page == 0)
	{
		newmouse(&MouseX,&MouseY,&press);
		
		if(flash){
			DoctorShow(INdoctor,han,3);
			setfillstyle(1,WHITE);
			bar(x+410,y+75,x+600,y+399);
			puthz(x+420+2,y+100+2,han,24,26,LIGHTGRAY);
			puthz(x+420,y+100,han,24,26,BLUE);
			flash = 0;
		}
		
		while(1)
		{
			if (MouseX > 600 && MouseY > 0 && MouseX < 640 && MouseY < 40)
			{
				MouseS = 1;
				break;
			}
			else if(MouseX > x && MouseY > y+75 && MouseX < x+190 && MouseY < y+75+54*3)
			{
				MouseS = 1;
				break;
			}
			else if(MouseX > x+205 && MouseY > y+75 && MouseX < x+395 && MouseY < y+399)
			{
				MouseS = 1;
				break;
			}
			else if(MouseX > x+410 && MouseY > y+75 && MouseX < x+600 && MouseY < y+399)
			{
				MouseS = 1;
				break;
			}
			else if(MouseX > x+305 && MouseY > y && MouseX < x+330 && MouseY < y+25)
			{
				MouseS = 1;
				break;
			}
			else if(MouseX > x +360&& MouseY > y && MouseX < x+385 && MouseY < y+25)
			{
				MouseS = 1;
				break;
			}
			else if(MouseX > x +410&& MouseY > y+410 && MouseX < x+550 && MouseY < y+440)
			{
				MouseS = 1;
				break;
			}
			else if(MouseX > 100 && MouseY > y && MouseX < 210 && MouseY < y+25)
			{
				MouseS = 2;
				break;
			}
			else if(MouseX > 500&& MouseY > y && MouseX < x+590 && MouseY < y+25)
			{
				MouseS = 2;
				break;
			}
			else
			{
				MouseS = 0;
				break;
			}
		}//鼠标状态显示 
		
		

			if(mouse_press(x+410, y+410,x+550,y+ 440) == 1 )
			{
				if(flag == 0 ||Data_Age[0] == '\0' || name[0] == '\0')
				{
					puthz(x+420,y+325, "信息填写不全！", 24, 24, RED);
					delay(1000);
					setfillstyle(1,WHITE);
					bar(x+420,y+320,x+590,y+380);
				}
				else
				{
						PatientData* p_patient = creat(0);
						PatientData* p_patient_head = p_patient;
						PatientData* p = p_patient_head->next;
						p_patient = p_patient->next;//跳过头节点
						Patient_Setup (p_patient_head);
						insert(p_patient_head,0);
						p = p_patient_head->next;
						while((p) != NULL)
						{
							if((p)->numreg == ID)
							{
								ID++;
								p = p_patient_head->next;
							}
							p = p->next;
						}
						p_patient = p_patient_head->next;
						p_patient->numreg = ID;
						*IDnumber = ID;
						TimeOut(tim);
						strcpy((p_patient)->timer,tim);
						strcpy((p_patient)->name,name);
						(p_patient)->age = INT_CHAR_Change(Data_Age);
						if(flag == 1)
						{
							(p_patient)->sexual = 0;
						}
						else
						{
							(p_patient)->sexual = 1;
						}
						strcpy((p_patient)->doctor,INdoctor);
						(p_patient)->paymed += money;
						page = load();
						page = Re_List(p_patient);
						Patient_Output(p_patient_head);
						deletall(p_patient_head);
						page = 1;
						delay(500);
						break;
				}
			}
		if(mouse_press(600, 0, 600+40 , 0 + 40) == 1)
		{
			page = 1;
		  delay(500);
		  break;
		}//关闭
		else if(mouse_press(x+305,y,x+330,y+25) == 1)
		{
			if(flag == 2)
			{
			  setfillstyle(1,WHITE);
			  bar(x+360,y,x+385,y+25);
			  rectangle(x+360,y,x+385,y+25);
			}
			flag = 1;//转换 
			clrmous(MouseX,MouseY);
			setlinestyle(0,0,4);
			setcolor(RED);
			line(x+305,y+12,x+317,y+25);
			line(x+330,y,x+317,y+25);
		}//男性
		else if(mouse_press(x+360,y,x+385,y+25) == 1)
		{
			if(flag == 2)
			{
			  setfillstyle(1,WHITE);
			  bar(x+305,y,x+330,y+25);
			  rectangle(x+305,y,x+330,y+25);
			}
		  flag = 2;//转换 
		  clrmous(MouseX,MouseY);
		  setlinestyle(0,0,4);
		  setcolor(RED);
		  line(x+360,y+12,x+372,y+25);
		  line(x+385,y,x+372,y+25);
		}//女性

		else if(mouse_press(x,y+75,x+190,y+75+54) == 1)
		{
			setlinestyle(0,0,5);
			setcolor(DARKGRAY);
			Outpatient[1]=0;
			Outpatient[2]=0;
			INdoctor[0] = '1';
			INdoctor[2] = '1';
			INdoctor[3] = '1';
			money = 8;
		  if(Outpatient[0]==0&&Outpatient[1]==0&&Outpatient[2]==0)
		  {
			Outpatient[0]=1;
			clrmous(MouseX,MouseY);
			setfillstyle(1,LIGHTGRAY);
			bar(x,y+75,x+190,y+75+54);
			puthz(x+10, y+85, "普通门诊", 24, 24, WHITE);

			setfillstyle(1,WHITE);
			bar(x,y+75+54,x+190,y+75+54*2);
			puthz(x+10, y+85+54, "专家门诊", 24, 24, DARKGRAY);

			setfillstyle(1,WHITE);
			bar(x,y+75+54*2,x+190,y+75+54*3);
			puthz(x+10, y+85+54*2, "急诊", 24, 24, DARKGRAY);

			rectangle(x,y+75,x+190,y+75+54);
			rectangle(x,y+75+54,x+190,y+75+54*2);
			rectangle(x,y+75+54*2,x+190,y+75+54*3);
		  }
		  flash = 1;
		}//门诊选择1
		else if(mouse_press(x,y+75+54,x+190,y+75+54*2) == 1)
		{
			setlinestyle(0,0,5);
			setcolor(DARKGRAY);
			Outpatient[0]=0;
			Outpatient[2]=0;
			INdoctor[0] = '2';
			INdoctor[2] = '0';
			INdoctor[3] = '1';
			money = 20;
		  if(Outpatient[0]==0&&Outpatient[1]==0&&Outpatient[2]==0)
		  {
			Outpatient[1]=1;
			clrmous(MouseX,MouseY);
			setfillstyle(1,LIGHTGRAY);
			bar(x,y+75+54,x+190,y+75+54*2);
			puthz(x+10, y+85+54, "专家门诊", 24, 24, WHITE);

			setfillstyle(1,WHITE);
			bar(x,y+75,x+190,y+75+54);
			puthz(x+10, y+85, "普通门诊", 24, 24, DARKGRAY);

			setfillstyle(1,WHITE);
			bar(x,y+75+54*2,x+190,y+75+54*3);
			puthz(x+10, y+85+54*2, "急诊", 24, 24, DARKGRAY);

			rectangle(x,y+75,x+190,y+75+54);
			rectangle(x,y+75+54,x+190,y+75+54*2);
			rectangle(x,y+75+54*2,x+190,y+75+54*3);
		  }
		  flash = 1;
		}//门诊选择2
		else if(mouse_press(x,y+75+54*2,x+190,y+75+54*3) == 1)
		{
			setlinestyle(0,0,5);
			setcolor(DARKGRAY);
			Outpatient[1]=0;
			Outpatient[0]=0;
			strcpy(INdoctor,"3701");
			money = 10;
		  if(Outpatient[0]==0&&Outpatient[1]==0&&Outpatient[2]==0)
		  {
			Outpatient[2]=1;
			clrmous(MouseX,MouseY);
			setfillstyle(1,LIGHTGRAY);
			bar(x,y+75+54*2,x+190,y+75+54*3);
			puthz(x+10, y+85+54*2, "急诊", 24, 24, WHITE);

			setfillstyle(1,WHITE);
			bar(x,y+75,x+190,y+75+54);
			puthz(x+10, y+85, "普通门诊", 24, 24, DARKGRAY);

			bar(x,y+75+54,x+190,y+75+54*2);
			puthz(x+10, y+85+54, "专家门诊", 24, 24, DARKGRAY);


			rectangle(x,y+75,x+190,y+75+54);
			rectangle(x,y+75+54,x+190,y+75+54*2);
			rectangle(x,y+75+54*2,x+190,y+75+54*3);

			bar(x+205,y+75,x+395,y+399);
			rectangle(x+205,y+75,x+395,y+399);
			for(i=0;i<5;i++)
		   {
			   line(x+205,y+75+54*(i+1),x+395,y+75+54*(i+1));
		   }

			puthz(x+215, y+85, "全科医学科", 24, 24, DARKGRAY);
			puthz(x+215, y+85+54, "内科", 24, 24, DARKGRAY);
			puthz(x+215, y+85+54*2, "外科", 24, 24, DARKGRAY);
			puthz(x+215, y+85+54*3, "妇科", 24, 24, DARKGRAY);
			puthz(x+215, y+85+54*4, "儿科", 24, 24, DARKGRAY);
			puthz(x+215, y+85+54*5, "心理门诊", 24, 24, DARKGRAY);

			for(i=0;i<6;i++)
			{
			  Department[i]=0;
			}
		  }//门诊选择3
		  flash = 1;
		}
		else if(mouse_press(x+205,y+75,x+395,y+75+54) == 1)
	  {
		De=Department_Choose(1,Outpatient,Department);
		for(i=0;i<6;i++)
		{
			Department[i]=0;
		}
		Department[De-1]=1;
		if(INdoctor[0] != '3')
		{
			INdoctor[1] = '1';
			//bar(0,0,100,100);
			flash = 1;
		}
	  }
	  else if(mouse_press(x+205,y+75+54,x+395,y+75+54*2) == 1)
	  {
		De=Department_Choose(2,Outpatient,Department);
		for(i=0;i<6;i++)
		{
			Department[i]=0;
		}
		Department[De-1]=1;
		
		if(INdoctor[0] != '3')
		{
		INdoctor[1] = '2';
		flash = 1;
		}
	  }
	  else if(mouse_press(x+205,y+75+54*2,x+395,y+75+54*3) == 1)
	  {
		De=Department_Choose(3,Outpatient,Department);
		for(i=0;i<6;i++)
		{
			Department[i]=0;
		}
		Department[De-1]=1;
		if(INdoctor[0] != '3'){
		INdoctor[1] = '3';
		flash = 1;
		}
	  }
	  else if(mouse_press(x+205,y+75+54*3,x+395,y+75+54*4) == 1)
	  {
		De=Department_Choose(4,Outpatient,Department);
		for(i=0;i<6;i++)
		{
			Department[i]=0;
		}
		Department[De-1]=1;
		if(INdoctor[0] != '3')
		{
		INdoctor[1] = '4';
		flash = 1;
		}
	  }
	  else if(mouse_press(x+205,y+75+54*4,x+395,y+75+54*5) == 1)
	  {
		De=Department_Choose(5,Outpatient,Department);
		for(i=0;i<6;i++)
		{
			Department[i]=0;
		}
		
		Department[De-1]=1;
		if(INdoctor[0] != '3')
		{
		INdoctor[1] = '5';
		flash = 1;
		}
	  }
	  else if(mouse_press(x+205,y+75+54*5,x+395,y+75+54*6) == 1)
	  {
		De=Department_Choose(6,Outpatient,Department);
		for(i=0;i<6;i++)
		{
			Department[i]=0;
		}
		Department[De-1]=1;
		if(INdoctor[0] != '3')
		{
		INdoctor[1] = '6';
		flash = 1;
		}
	  }
		CreateButton_INPUT_3  (data1,&m,name,"请输入：",1);
		CreateButton_INPUT_3  (data2,&n,Data_Age,"请输入：",1);//输入框模块 
	}
	return page;
 }
