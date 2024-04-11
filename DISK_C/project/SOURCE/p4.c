#include <common.h>

/******************************************************************
	【患者诊断函数】 
编写人：樊范 徐哲轩
传入：int* IDnumber
传出：int
函数功能： 进行患者诊断
*******************************************************************/
int p4(int* IDnumber)
{
	int page = 0;
	MED*medicine = (MED*)malloc(sizeof(MED));//创建一个工具结构 
	int pan = 0;
	int no = 0;
	PatientData* p_patient = creat(0);
	PatientData* p_patient_head = p_patient;
	PatientData* p = p_patient_head->next;
	p_patient = p_patient->next;//跳过头节点
	page = 5;
	Patient_Setup (p_patient_head);
	no = *IDnumber;//INT_CHAR_Change(name);
	Patient_Setup (p_patient_head);
	p = p_patient_head->next;
	while(p != NULL)
	{
		if((p)->numreg == no && (p)->numreg > 0 )
		{//此数据符合要求
			if((p)->payreg >= 1)
			{
				cleardevice();
				setfillstyle(1,WHITE);
				bar(0, 0,640 ,480);
				setfillstyle(3,DARKGRAY);
				bar(230, 390,260+153 ,400+34);
				setfillstyle(1,WHITE);
				bar(235, 395,255+153 ,395+34);
				puthz(260,400,"您已诊断",24,32,RED);
				page = 1;
				delay(500);
				Notice_Page_p1();
				pan = 1;
				break;
			}
			else
			{
				int choose = 0;
				int num;
				FILE*fp;
				if(p->age>=0&&p->age<=6)
				{
					num = 1;
				}
				else if(p->age>6&&p->age<=12)
				{
					num = 2;
				}
				else if(p->age>12&&p->age<18)
				{
					num = 3;
				}
				else if(p->age>=18&&p->age<=50)
				{
					num = 4;
				}
				else if(p->age>50&&p->age<=60)
				{
					num = 3;
				}
				else if(p->age>60)
				{
					num =2;
				}
				choose = diagnosising(p);
				(p)->paymed = 0;
				p->window = choose;
				(p)->medicine_list[0][0] = p->doctor[1] -'0';
				(p)->medicine_list[0][1] = num;
				(p)->medicine_list[0][2] = 1;
				fp=fopen("C:\\project\\DATABASE\\drugdata.txt","r");
				for(; ;)
				{	
					fscanf(fp,"%d\t%d\t%s\t%d\t%d\t%d\n",&medicine->ID,&medicine->Store_No,medicine->name,&medicine->price,&medicine->margin,&medicine->inventory);
					if(medicine->ID == (p)->medicine_list[0][0])
					{		
						if(medicine->margin < (p)->medicine_list[0][1] && (p)->medicine_list[0][1] != 0)
						{
							(p)->medicine_list[0][0] += 1;
							(p)->medicine_list[0][1] -= 1;
							rewind(fp);
						}
						else
						{
							(p)->paymed += (p)->medicine_list[0][1] * medicine->price;
							break;
						}	
					}
					if(feof(fp))
					{
						(p)->medicine_list[0][0] = 0;
						(p)->medicine_list[0][2] = 0;
						(p)->medicine_list[0][1] = 0;
						break;
					}
				}
				fclose(fp);	
				(p)->medicine_list[1][2] = 1;
				(p)->medicine_list[1][1] = num;
				(p)->medicine_list[1][0] = p->doctor[1] + p->window -'0';
				fp=fopen("C:\\project\\DATABASE\\drugdata.txt","r");
				for(; ;)
				{	
					fscanf(fp,"%d\t%d\t%s\t%d\t%d\t%d\n",&medicine->ID,&medicine->Store_No,medicine->name,&medicine->price,&medicine->margin,&medicine->inventory);
					if(medicine->ID == (p)->medicine_list[1][0] && medicine->margin> (p)->medicine_list[1][1])
					{		
						if(medicine->margin < (p)->medicine_list[1][1] && (p)->medicine_list[1][1] != 0)
						{
							(p)->medicine_list[1][0] += 1;
							(p)->medicine_list[1][1] -= 1;
							rewind(fp);
						}
						else
						{
							(p)->paymed += (p)->medicine_list[0][1] * medicine->price;
							break;
						}
					}
					if(feof(fp))
					{
						(p)->medicine_list[1][0] = 0;
						(p)->medicine_list[1][2] = 0;
						(p)->medicine_list[1][1] = 0;
						break;
					}
				}
				fclose(fp);		
				(p)->medicine_list[2][0] = p->doctor[1]-'0'+6+p->doctor[0]-'0';
				(p)->medicine_list[2][2] = 1;
				(p)->medicine_list[2][1] = num;
				fp=fopen("C:\\project\\DATABASE\\drugdata.txt","r");
				for(; ;)
				{	
					fscanf(fp,"%d\t%d\t%s\t%d\t%d\t%d\n",&medicine->ID,&medicine->Store_No,medicine->name,&medicine->price,&medicine->margin,&medicine->inventory);
					if(medicine->ID == (p)->medicine_list[2][0] && medicine->margin> (p)->medicine_list[2][1])
					{		
						if(medicine->margin < (p)->medicine_list[2][1] && (p)->medicine_list[2][1] != 0)
						{
							(p)->medicine_list[2][0] += 1;
							(p)->medicine_list[2][1] -= 1;
							rewind(fp);
						}
						else
						{
							(p)->paymed += (p)->medicine_list[2][1] * medicine->price;
							break;
						}
					}
					if(feof(fp))
					{
						(p)->medicine_list[2][0] = 0;
						(p)->medicine_list[2][2] = 0;
						(p)->medicine_list[2][1] = 0;
						break;
					}
				}
				fclose(fp);								
				(p)->payreg = 1;
				pan = 1;
				page = Result_List(p);
				page = 1;
				break;	
			}
		}
		p = p->next;
	}
	if(!pan)
	{
		cleardevice();
		setfillstyle(1,WHITE);
		bar(0, 0,640 ,480);
		setfillstyle(3,DARKGRAY);
		bar(230, 390,260+153 ,400+34);
		setfillstyle(1,WHITE);
		bar(235, 395,255+153 ,395+34);
		puthz(260,400,"查无此号",24,32,RED);
		page = 1;
		delay(500);
		Notice_Page_p1();
	}		
	Patient_Output(p_patient_head);
	deletall(p_patient_head);
	delay(200);
	free(medicine);
	return page;
}   
