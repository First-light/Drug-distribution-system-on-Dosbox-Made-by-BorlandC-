#include <common.h>
#define p15_button_num 7
/******************************************************************
		【挂号记录检索界面】
编写人：徐哲轩
*******************************************************************/
void Registered2(PatientData* change);
void Notice_Page_p15(void);


/******************************************************************
		【挂号记录检索画面界面】
编写人：徐哲轩
传入：void
传出：void
函数功能：画出页面
*******************************************************************/
void p15_screen(void)
{
	setfillstyle(11,YELLOW);
	bar(0,0,640,480);
	setcolor(DARKGRAY);
	setlinestyle(0, 0, 3);
	setfillstyle(1,WHITE);
	bar(0,61+3,190-45,64+3);	
	frameline2();
}

/******************************************************************
		【挂号记录检索界面逻辑函数】
编写人：徐哲轩
传入：void
传出：int （跳转页面）
函数功能：能够检索指定状态的挂号数据，能够查看表格，
		能够选择指定患者查看详细数据，能够进行错挂修改
*******************************************************************/
int p15(void)
{

	int button[p15_button_num] = {1,1,1,1,1,1,1};
	int button2[3] = {1,1,1};
	int page = 0;
	int page_t = 0;
	int check2[12] = {1,1,1,1,1,1,1,1,1,1,1,1};
	int show = -1;
	int show2 = -1;
	int show3 = 0;
	int sheet_1_page = 1;
	int data2[9] = {245,405+13,1,130,45,24,36,-30,3};
	int data3[9] = {410,405+13,1,130,45,24,24,0,3};
	int data1[9] = {450,21,1,90,35,16,17,-8,4};
	int data4[9] = {13,13,14,120,50,24,48,-32,2};
	int sheetdata[12] = {24,30,60,70,90,60,20+20+20+40,40,30,0,80,90};
	char input2[5]={0};
	int buttondata2[9] ={160,21,280,35,18,5,12,2,7};
	int buttondata3[9] ={100,410+13,110,35,18,5,4,2,8};
	char input[21] = {'#','9'};
	PatientData* p15_patient = creat(0);
	PatientData* p15_patient_head = p15_patient;
	Patient_Setup (p15_patient_head);
	p15_patient = p15_patient->next;//跳过头节点
	clrmous(MouseX,MouseY);
	MouseS = 0;
	cleardevice();
	setbkcolor(WHITE);
	p15_screen();

	delay(300);
	
	while(page == 0)
	{
		newmouse(&MouseX,&MouseY,&press);
		
		page_t = CreateButton_OUT(600,0,14,&button[0]);
			//返回按钮
			if(page_t)
			{
				//数据中转并检测，若按钮函数输出改变的页面跳转量到page_t，则page赋值，并且跳出页面循环，退出页面函数，然后重新选择页面
				page = page_t;
				break;
			}		
				
		show = CreateButton_4  ("详情",data2,&button[3]);
		show2 = CreateButton_4  ("错挂修改",data3,&button[4]);
			if(show ||show2)
			{
				PatientData* m = NULL;
				m = findpat(input2,p15_patient_head,1);
				if(m == NULL)
				{
					setfillstyle(1,WHITE);
					bar(0, 0,640 ,480);
		  			setfillstyle(3,DARKGRAY);
		  			bar(230, 390,260+153 ,400+34);
		  			setfillstyle(1,WHITE);
		  			bar(235, 395,255+153 ,395+34);
		  			puthz(260,400,"查无此号",24,32,RED);
		  			delay(500);					
				}
				else
				{
					if(show)
					{
						show = Result_List(m);
					}
					if(show2)
					{
						if(m->payreg >= 1)
						{
							setfillstyle(1,WHITE);
							bar(0, 0,640 ,480);
			  				setfillstyle(1,WHITE);
			  				bar(235, 395,255+153 ,395+34);
			  				puthz(210-40,400,"已经诊断，无法修改",24,32,RED);
			  				delay(1000);	
						}
						else
						{
							Registered2(m);
							Patient_Output(p15_patient_head);
						}
					}				
				}
				show = 0;
				page = 15;
				break;
			}			

		show3 = CreateButton_4  ("指令表",data1,&button[6]);
			if(show3){
				Notice_Page_p15();
				show3 = 0;
				page = 15;
				break;
			}
			
		page_t = CreateButton_4  ("首页",data4,&button[5]);
			if(page_t)
			{
				page = page_t;
				break;
			}	
			
		CreateButton_INPUT_3(buttondata2,&button[1],input,"请输入姓名或者指令进行检索：",1);
			if(button[1] == 1){
				int i=0 ;
				for(;i<12;i++){
					check2[i] = 1;
				}				
			}
			
		CreateButton_INPUT_3(buttondata3,&button[2],input2,"输入编号",1);
			if(CreateButton_pagechange (sheetdata[10],sheetdata[11]+12*sheetdata[0],button2,&sheet_1_page,10+50+70+90+60+20+20+20+20+50+40+0+30))
			{
				int i=0 ;
				for(;i<12;i++){
					check2[i] = 1;
				}
			}	
		show = SheetCreate_4 (sheetdata,p15_patient,sheet_1_page,check2,input);
			delay(3);
	}
	deletall(p15_patient_head);
	return page;    
	//退出页面，返回改变的页面值
}

/******************************************************************
		【错挂修改画图函数】
编写人：徐哲轩
传入：void
传出：void
函数功能：画出界面
*******************************************************************/
void Registered_Page2(void)
{
	int i=0;
	int x=20;
	int y=20;
    setlinestyle(0,0,5);
    setcolor(DARKGRAY);
    setfillstyle(1,WHITE);
    bar(0,0,640,480);
    frameline();
    puthz(x+200, y, "错挂修改", 32, 50, RED);
    puthz(x, y+50, "门诊类型", 24, 24, DARKGRAY);
    puthz(x+205, y+50, "科室种类", 24, 24, DARKGRAY);
    puthz(x+410, y+50, "医生", 24, 24, DARKGRAY);
	rectangle(x,y+75,x+190,y+75+54*3);
    rectangle(x+205,y+75,x+395,y+399);
    rectangle(x+410,y+75,x+600,y+399);
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
    puthz(x+415,y+415, "确认并修改", 24, 24, WHITE);
    setlinestyle(1,0,1);
    line(x,y+30,x+600,y+30);
    line(x,y+35,x+600,y+35);
}
/******************************************************************
		【错挂修改函数】
编写人：徐哲轩
传入：PatientData* change
传出：void
函数功能：对挂错科室的患者修改挂号
*******************************************************************/
void Registered2(PatientData* change)
{
	int page = 0;
	int x=20;
	int y=20;
	int i=0;
	int Outpatient[3]={0}; 
	int Department[6]={0};
	int De=0;
	char INdoctor[5] = {0};
	int money = 0;
	int flash = 1;
	char han[8] = {0};
	clrmous(MouseX,MouseY); 
	Registered_Page2();
	if(x||y||i){}
    while(page == 0)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(flash)
		{
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
		}
			if(mouse_press(x+410, y+410,x+550,y+ 440) == 1 )
			{
				if(INdoctor[0] == 0 || INdoctor[3] == 0)
				{
					puthz(x+420,y+325, "信息填写不全！", 24, 24, RED);
					delay(1000);
					setfillstyle(1,WHITE);
					bar(x+420,y+320,x+590,y+380);
				}
				else
				{
						strcpy((change)->doctor,INdoctor);
						(change)->paymed = money;
						page = load();
						setfillstyle(1,WHITE);
						bar(0, 0,640 ,480);
			  			setfillstyle(3,DARKGRAY);
			  			bar(230, 390,260+153 ,400+34);
			  			setfillstyle(1,WHITE);
			  			bar(235, 395,255+153 ,395+34);
			  			puthz(260,400,"修改完毕",24,32,BLUE);
			  			delay(500);	
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
		if(INdoctor[0] != '3'){
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
		
		if(INdoctor[0] != '3'){
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
		if(INdoctor[0] != '3'){
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
		if(INdoctor[0] != '3'){
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
		if(INdoctor[0] != '3'){
		INdoctor[1] = '6';
		flash = 1;
		}
	  }
	}
 }
 
 /******************************************************************
 		【指令表函数】
 编写人：徐哲轩
 传入：void
 传出：void
 函数功能：展示指令表
 *******************************************************************/
 void Notice_Page_p15(void)
 {

     setfillstyle(1,WHITE);
     bar(160,0,480,480);
 	setcolor(DARKGRAY);
 	setlinestyle(0, 0, 3);
     setfillstyle(1,RED);
     bar(440,0,480,40);
     setfillstyle(11,DARKGRAY);
     bar(160,0,440,40);
    line(445,5,475,35);
	line(445,35,475,5);
	settextstyle(2,0,7);
     puthz(170+2, 50+2, "检索指令表", 32,34, LIGHTGRAY);
    puthz(170, 50, "检索指令表", 32,34, DARKGRAY);
     puthz(170, 100, "直接输入", 24, 24, DARKGRAY);
     puthz(170+15, 100+30, "：检索患者姓名", 24, 24, DARKGRAY);
    puthz(170, 180, "输入井号加数字零到五", 24, 24, DARKGRAY);
     puthz(170+15, 180+30, "：检索处于特定状态的患者", 24, 24, DARKGRAY);
      puthz(170, 260, "输入艾特符号加数字", 24, 24, DARKGRAY);
       puthz(170+15, 260+30, "：检索挂号号码", 24, 24, DARKGRAY);
      puthz(170, 340, "输入百分号加时间", 24, 24, DARKGRAY);
       puthz(170+15, 340+30, "：检索特定时间挂号的患者", 24, 24, DARKGRAY);
    puthz(170, 420, "例如：", 16, 16, DARKGRAY);
	outtextxy(170+55,420,"%20230418") ;
     puthz(170, 450, "这将会显示二零二三年四月十八日的信息", 16, 16, DARKGRAY);
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
