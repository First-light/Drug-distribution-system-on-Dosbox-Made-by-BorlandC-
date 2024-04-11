#include "LVup.h"
#include <stdio.h>
#include <string.h>


/******************************************************************
		【科室医生检索函数】
编写人：徐哲轩
传入：char* input,char* check
传出：int（比较结果）
函数功能：将科室医生与输入对比，输出是否符合要求
*******************************************************************/
int DoctorCheck(char* input,char* check)
{
	int back = 0;
	char KS; 
	char* doctor;
	int DC;
	char MZ_2 ;
	char KS_2; 
	char* doctor_2;
	int DC_2;
	MZ_2 = input[0];
	KS_2 = input[1]; 
	doctor_2 = &input[1];
	DC_2 = INT_CHAR_Change2(doctor_2,3);
	KS = check[1]; 
	doctor = &check[1];
	DC = INT_CHAR_Change2(doctor,3);
	if(DC_2%100  == 0)
	{
		if(KS_2 == '0')
		{
			if(MZ_2 == '0')
			{
				back = 1;
			}
			else if(MZ_2 == '1')
			{
				if((DC%100)/10 == 1)
				{
					back = 1;
				}
			}
			else if(MZ_2 == '2')
			{
				if((DC%100)/10 == 0)
				{
					back = 1;
				}
			}
			else if(MZ_2 == '3')
			{
				if(DC == 701)
				{
					back = 1;
				}
			}	
		}
		else
		{
			if(KS_2 == KS)
			{	
				back = 1;
			}			
		}
	}
	else
	{
		if(DC == DC_2)
		{	
			back = 1;
		}
	}
	return back;
}

/******************************************************************
		【科室医生展示函数】
编写人：徐哲轩
传入：char* input,char* output,int mode
传出：void
函数功能：将科室医生在结构体中的储存量（char）转化为汉字，并赋予output
*******************************************************************/
void DoctorShow(char* input,char* output,int mode)
{
	char MZ ;
	char KS; 
	char* doctor;
	int DC;
	MZ = input[0];
	KS = input[1]; 
	doctor = &input[1];
	DC = INT_CHAR_Change2(doctor,3);
	strcpy(output,"\0");
	switch (mode) 
	{
	case 1:
		switch (MZ) 
		{
			case '1':strcpy(output,"普通门诊");break;
			case '2':strcpy(output,"专家门诊");break;
			case '3':strcpy(output,"急诊");break;
			default:strcpy(output,"未知");break;
		}
		break;
	case 2:
		switch (KS) 
		{
			case '1':strcpy(output,"全科医学科");break;
			case '2':strcpy(output,"内科");break;
			case '3':strcpy(output,"外科");break;
			case '4':strcpy(output,"妇科");break;
			case '5':strcpy(output,"儿科");break;
			case '6':strcpy(output,"心理门诊");break;
			case '7':strcpy(output,"急诊");break;
			default:strcpy(output,"未知");break;
		}		
		break;
	case 3:
		switch (DC) 
		{
			case 701:strcpy(output,"肖红艳");break;
			
			case 101:strcpy(output,"周飞鹏");break;
			case 102:strcpy(output,"王砾");break;
			case 103:strcpy(output,"詹继东");break;
			case 111:strcpy(output,"刘青松");break;
			case 112:strcpy(output,"肖婷");break;
			case 113:strcpy(output,"王雅娜");break;
			case 114:strcpy(output,"冯幼兰");break;
			
			case 201:strcpy(output,"桂元");break;
			case 202:strcpy(output,"李娥");break;
			case 211:strcpy(output,"杜彬彬");break;
			case 212:strcpy(output,"马娟娟");break;
			case 213:strcpy(output,"郭亚岚");break;
			case 214:strcpy(output,"黄沁");break;
			
			case 301:strcpy(output,"金曜");break;
			case 302:strcpy(output,"鲁达飞");break;
			case 311:strcpy(output,"郝杰");break;
			case 312:strcpy(output,"杨帆");break;
			case 313:strcpy(output,"李盛");break;
			case 314:strcpy(output,"张弦");break;
			
			case 401:strcpy(output,"陈踩");break;
			case 411:strcpy(output,"王丽华");break;
			case 412:strcpy(output,"舒娴");break;
			
			case 501:strcpy(output,"周毅");break;
			case 502:strcpy(output,"钟严艳");break;
			case 511:strcpy(output,"林晶");break;
			case 512:strcpy(output,"王琼玉");break;
			
			case 601:strcpy(output,"陈运平");break;
			case 602:strcpy(output,"袁光雷");break;
			case 603:strcpy(output,"肖强");break;
			case 604:strcpy(output,"方赫");break;
			case 605:strcpy(output,"陈蕾");break;
			case 606:strcpy(output,"白汉平");break;			
			case 611:strcpy(output,"吴娜");break;
			case 612:strcpy(output,"黄璐");break;
			default:strcpy(output,"未知");break;
		}	
		break;
	default:
		break;
	}
}
