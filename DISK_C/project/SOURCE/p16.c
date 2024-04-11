#include "common.h"
#define p16_button_num 4
/*————————————————————————
				【医生登入界面】 
编写人：徐哲轩
此界面实现了医生进入系统时需要输入密码的过程。
————————————————————————*/


void p16_screen()
{
/*—————————————————
		【初始化绘图函数】 
		编写人：徐哲轩
		函数会画出界面的背景。
——————————————————*/
	setfillstyle(11,YELLOW);
	bar(0,0,640,480);
	setcolor(DARKGRAY);
	setlinestyle(0, 0, 3);
	frameline2();
}



int p16()
{
/*——————————————————
		【医生登入页面函数】
		编写人：徐哲轩
。
———————————————————*/
	int button[p16_button_num] = {1,1,1,1};
	int page = 0;
	int page_t = 0;
	int robotflash = 1;
	int robotflash2 = 1;
	int show = -1;
	int button2[3]={1,1,1};
	int sheet_1_page = 1;
	int sheet_1_data[7]= {30,30,120,80,380,185,0};
	int buttondata3[9] = {485,70,1,127,62,24,32,-25,2};
	int buttondata[4] = {485,15,90,25};
		int key = 1;
		int keyold = key;
	int check[10] = {1,1,1,1,1,1,1,1,1,1};
	struct robot ro[2] =
	{
	{0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0}
	};
	int timing = 201;
	int drawdata[2] = {20,140};
	char a[7] = {0};
	int yes = 0;
	int yes2 = 1;
	int show2 = 0;
	int IDpat = -1;
	int yes_t = 0;
	MED* medicine = (MED*)malloc(sizeof(MED));
	MED* medi_head =reopen(medicine);
	MED* mt = medi_head->next;
	
	PatientData* p16_patient = creat(0);
	PatientData* p16_patient_head = p16_patient;
	p16_patient = p16_patient->next;//跳过头节点
	
	Patient_Setup (p16_patient_head);

	Number_no_same(p16_patient_head,1);
	p16_patient = p16_patient_head->next;

	Robot_Setup (&ro[0],0);
	Robot_Setup (&ro[1],1);
	clrmous(MouseX,MouseY);
	MouseS = 0;
	cleardevice();	
	setbkcolor(WHITE);
	p16_screen();
	setfillstyle(1,YELLOW);
	bar(485,45,485+16*8,65);
	puthz(485,45,"叫号患者来取药",16,16,BLUE);
	NO_XY_flash(medi_head->next);

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

			if
			(CreateButton_pagechange (sheet_1_data[4],sheet_1_data[5]+8*sheet_1_data[0],
			button2,&sheet_1_page,
			sheet_1_data[1]+sheet_1_data[2]+sheet_1_data[3]))
			{
				int i=0 ;
				for(;i<10;i++){
					check[i] = 1;
				}
			}
			
			
			
			CreateButton_open  (buttondata,&button[3],&key);
			if(keyold != key)
			{
				keyold = key;
				yes2 = key;
				if(key == 0){
					setfillstyle(1,YELLOW);
					bar(485,45,485+16*8,65);
					puthz(485,45,"叫号患者不来取药",16,16,RED);
				}else{
					setfillstyle(1,YELLOW);
					bar(485,45,485+16*8,65);
					puthz(485,45,"叫号患者来取药",16,16,BLUE);					
				}
			}

			show = SheetCreate_3 (sheet_1_data,p16_patient,sheet_1_page,check);
			if(show != -1){
				show2 = 1;
				IDpat = show;
			}
			if(show2){
				yes_t = CreateButton_4  ("叫号",buttondata3,&button[4]);
				if(yes_t){
					yes = 1;
				}
			}
			
			if(timing >  100){
				int t1 = 0;
				timing = 0;
				Robot_analyse(medi_head->next,&page/*没有用*/,p16_patient,&ro[0],&ro[1]);
				Store_draw (drawdata,medi_head->next);
				Robot_draw (drawdata,&ro[0]);
				Robot_draw (drawdata,&ro[1]);
				Robotstate_Show(30,13,&ro[0],"配药机器人一号",&robotflash);
				Robotstate_Show(260,13,&ro[1],"配药机器人二号",&robotflash2);
				settextstyle(3,0,2);
				for(t1 = 0;t1<10;t1++){
					check[t1] = 1;
				}
				if(yes){
					PatientData*m = p16_patient_head->next;
					settextstyle(3,0,2);
					while(m!= NULL){
						if(m != NULL &&	m->payreg >= 4 && m->nummed == IDpat){
								setfillstyle(11,LIGHTGRAY);
								bar(80,150,80+200,350);
									setcolor(RED);
									puthz(100,160,"（叫号）请患者：",24,24,RED);
									outtextxy(100,200,m->name);
									puthz(100,240,"到窗口取药",24,24,RED);
									delay(2000);
									m->payreg = 5;
								if(yes2){
									m->nummed = 0;
									setcolor(BLUE);
									puthz(100,280,"患者已取走",24,24,BLUE);
									outtextxy(100,310,m->name);
									delay(1000);
								}
							}	
							m = m->next;
						}
						Number_no_same(p16_patient_head,1);
						p16_patient = p16_patient_head->next;
						delay(5);	
					yes = 0;			
				}
				delay(5);
			}else{
				timing++;
				delay(5);
			}
			

//——————————————————————————————————————

//			page_t = CreateButton_1("返回",240,300,1,&button[0]);
//			if(page_t)
//			{
//				page = page_t;
//				break;
//			}		

//          【 按钮函数的使用规范 】

//				编写人 ：徐哲轩
//——————————————————————————————————————
		
	}
		Robot_Output (ro,2);
		printlist_FILE(medi_head);
		Patient_Output(p16_patient_head);
		deletall(p16_patient_head);
		mt = medi_head->next;
		while(mt != NULL){
			free(medi_head);
			medi_head = mt;
			mt = mt->next;
		}
		free(medi_head);
		free(medicine);
	return page;    
	//退出页面，返回改变的页面值
}
