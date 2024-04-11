#include <common.h>
/******************************************************************
		【取药消耗分析表头函数】
编写人：徐哲轩
传入：void
传出：void
函数功能：画出表头
*******************************************************************/
void analyse_screen(void)
{
	setfillstyle(11,YELLOW);
	bar(0,0,640,480);
	setcolor(DARKGRAY);
	setlinestyle(0, 0, 3);
	setfillstyle(1,WHITE);
	bar(0,61+3,190-45,64+3);
	frameline2();
	setfillstyle(1,DARKGRAY);
	bar(100+40,85-15,30 + 10+70+90+60+20+50+0+30+70+40,110-15);
	puthz(100+40+5,90-15,"编号",16,16,WHITE);
	puthz(80+20+40+70,90-15,"药品名",16,16,WHITE);
	puthz(130+70+40+20+10+70+15,90-15,"消耗",16,16,WHITE);
	puthz(200+50+40+25+70+15,90-15,"当前余量",16,16,WHITE);
}

/******************************************************************
		【查找消耗最大函数】
编写人：徐哲轩
传入：int* input,MED* head
传出：MED
函数功能：从int数组中找出最大项，并返回找到的链表节点
*******************************************************************/
MED* FindMaxDrug(int* input,MED* head)//head
{
	MED* back = NULL;
	MED* m = head->next;
	int max = 0;
	int ID = 0;
	int i = 0;
	while(i<=34)
	{
		if(input[i] > max)
		{
			max = input[i];
			ID = i;
		}
		i++;
	}
	while(m != NULL)
	{
		if(m->ID == ID)
		{
			back = m;
			break;
		}
		m = m->next;
	}
	return back;
}

/******************************************************************
		【药品消耗分析界面函数】
编写人：徐哲轩
传入：void
传出：int（跳转界面号）
函数功能：创建页面，具有分析药品在某个时间里的药品消耗数据，并找到最大消耗的药品
*******************************************************************/
int DrugOutAnalyse(void)
{
	int button[7] = {1,1,1,1,1,1,1};//按钮
	int button2[3] = {1,1,1};
	int page = 0;
	int page_t = 0;
	int check2[12] = {1,1,1,1,1,1,1,1,1,1,1,1};
	int show = -1;
	int data4[9] = {13,13,14,120,50,24,24,-32,2};
	int sheetdata[13] = {24,30,10,70,90,60,0,40,30,0,100+40,110-15,1};
	int buttondata2[9] ={160,21,280,35,18,5,12,2,7};
	char input[21] = {0};
	int consume_data[36] ={0};

	MED* med = (MED*)malloc(sizeof(MED));
	MED* medi_head =reopen(med);
	MED* mt = medi_head->next;

	PatientData* p_patient = creat(0);
	PatientData* p_patient_head = p_patient;
	Patient_Setup (p_patient_head);
	p_patient = p_patient->next;

	clrmous(MouseX,MouseY);
	MouseS = 0;
	cleardevice();
	setbkcolor(WHITE);
	analyse_screen();

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

			show = SheetCreate_4_MED(sheetdata,p_patient,consume_data,check2,input);

			show = CreateButton_4("分析",data4,&button[5]);
			if(show)//如果按下分析按钮
			{
				int i=0 ;
				MED* temp = NULL;
				for(;i<12;i++)
				{
					check2[i] = 1;
				}
				setfillstyle(11,DARKGRAY);
				bar(0+100,400+20,640-100,440+20);
				puthz(100+5,410+20,"消耗量最大的药品：",24,24,RED);
				temp =  FindMaxDrug(consume_data,medi_head);
				if(temp != NULL)
				{
					settextstyle(1,0,3);
					setcolor(RED);
					outtextxy(100+24*10,403+20,temp->name);
				}
				else
				{
					settextstyle(1,0,3);
					setcolor(RED);
					outtextxy(100+24*10,403+20,"NULL");
				}
			}

			CreateButton_INPUT_3(buttondata2,&button[4],input,"请按格式输入时间：",1);
			if(button[4] == 1)
			{
				int i=0 ;
				for(;i<12;i++)
				{
					check2[i] = 1;
				}
			}

			show = CreateButton_pagechange(sheetdata[10],sheetdata[11]+12*sheetdata[0],button2,&sheetdata[12],10+70+90+60+20+50+0+30);
			if(show)
			{
				int i=0 ;
				for(;i<12;i++)
				{
					check2[i] = 1;
				}
			}
		delay(3);
	}
	deletall(p_patient_head);
	mt = medi_head->next;
	while(mt != NULL)
	{
		free(medi_head);
		medi_head = mt;
		mt = mt->next;
	}
	free(medi_head);
	free(med);
	return page;
	//退出页面，返回改变的页面值
}
