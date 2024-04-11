#include "string.h"
#include "LVup.h"
#include "struct.h"
#include <stdio.h>

/******************************************************************
		【查找患者函数】
编写人：徐哲轩
传入：int* input,char* inputc,PatientData* head,int style
传出：PatientData*
函数功能：查找到指定挂号号码的患者
*******************************************************************/
PatientData* findpat(char* inputc,PatientData* head,int style)//head
{
	PatientData* back = NULL;
	PatientData* m = head->next;
	int ruler = 0;
	int check = 0;
	while(m != NULL)
	{
		if(style)
		{
			char rulerc[5] = {0};
			strcpy(rulerc,inputc);
			ruler = INT_CHAR_Change(rulerc);
			check = (m)->numreg; 
			if(check == ruler)//>_<) 
			{//此数据符合要求
				back = m;
				break;
			}
		}
		m = m->next;
	}		
	return back;
}

/******************************************************************
		【取药次序整理函数】
编写人：徐哲轩
传入：PatientData* m,int start
传出：void
函数功能：按要求整理患者的取药号码，并进行链表重排序，保证次序，且从1开始
*******************************************************************/
void Number_no_same(PatientData* m,int start)//head
{
	PatientData*p2 = m;
	PatientData*p = m->next;
	int n = 0;
	do{//冒泡排序法
		n = 0;
		p2 = m;
		p = p2->next;
		while((p->next)->next != NULL && p->next != NULL)
		{
			if(p->nummed > (p->next)->nummed)
			{
				PatientData* t1 = p;
				PatientData* t2 = p->next;
				PatientData* t3 = (p->next)->next;
				p2->next = t2;
				t2 ->next = t1;
				t1 ->next = t3;
				p = p2->next;
				n = 1;
			}
			p2 = p2->next;
			p = p2->next;
		}	
	}while(n != 0);
	p = m->next;
	n = start;
	while(p != NULL)
	{
		if(p->payreg >= 2 &&p->nummed != 0)//将取药号码不为0的患者重新排列
		{
			p->nummed = n;
			n++;
		}
		else
		{
			p->nummed = 0;
		}
		p = p->next;
	}
}


/******************************************************************
		【药格坐标转变函数函数】
编写人：徐哲轩
传入：MED* m
传出：void
函数功能：将药的药格数据读取并转换为x y坐标位置，用于机器人动画
*******************************************************************/
void NO_XY_flash(MED* m)
{
	MED* m2 = m;
	while(m2 != NULL)
	{
		(m2)->x =((m2)->Store_No) % 6 ;
		(m2)->y =((m2)->Store_No) / 6 ;
		if((m2)-> Store_No >= 18) 
		{
		 	(m2)->y += 2;
		}
		m2 = m2->next;
	}
}

/******************************************************************
		【char转int函数】
编写人：徐哲轩
传入：char* ar
传出：void
函数功能：数值类型转化
*******************************************************************/
int INT_CHAR_Change(char* ar)
{
	int i = 0;
	int back = 0;
	int m = 0;
	
	while(ar[i] != '\0')
	{
		i++;
	}
	for(;i>0;i--)
	{
		int num = 1;
		int j = 0;
		for(j=i;j>1;j--)
		{
			num *= 10;
		}
		back += num*(ar[m] - '0');
		
		m++;
	}
	return back;
}
/******************************************************************
		【带‘0’的char转int函数】
编写人：徐哲轩
传入：char* ar，n读取位数
传出：void
函数功能：数值类型转化
*******************************************************************/
int INT_CHAR_Change2(char* ar,int n)
{
	int i = 0;
	int back = 0;
	int m = 0;
	while(ar[i] == '0' && ar[i] != '\0'&& i<n)
	{
		i++;
	}
	while(ar[i] != '\0'&& i<n)
	{
		i++;
	}
	for(;i>0;i--)
	{
		int num = 1;
		int j = 0;
		for(j=i;j>1;j--)
		{
			num *= 10;
		}
		back += num*(ar[m] - '0');
		m++;
	}
	return back;
}

/******************************************************************
		【int转带‘0’的char函数】
编写人：徐哲轩
传入：char* ar2,int b,int n读取位数
传出：void
函数功能：数值类型转化
*******************************************************************/
void CHAR_INT_Change2(char* ar2,int b,int n)
{//int转char*类型函数
	int i;
	int j;
	char ar[30] = {0};
	for(i=0;i <n;i++)
	{//将int按位转换为char型
		ar[i] = '0' + (b % 10);
		b /= 10;
		if(b == 0)
		{//如果int读完，结束循环
			break;
		}
	}
	strcpy(ar2,"\0");
	i = 0;
	for(j = n-1;j>=0;j--,i++)
	{
		ar2[j] = ar[i];//将数组倒置
		if(ar[i] == 0){
			ar2[j] = '0';
		}
	} 
}//最后修改：2023/4/13

/******************************************************************
		【int转char函数】
编写人：徐哲轩
传入：char* ar2,int b
传出：void
函数功能：数值类型转化
*******************************************************************/
void CHAR_INT_Change(char* ar2,int b)
{//int转char*类型函数

	int i;
	int j;
	char ar[30] = {0};
	for(i=0;i <30;i++)
	{//将int按位转换为char型
		ar[i] = '0' + (b % 10);
		b /= 10;
		if(b == 0)
		{//如果int读完，结束循环
			break;
		}
	}
	strcpy(ar2,"\0");
	for(j = 0;i>=0;i--,j++){
		ar2[i] = ar[j];//将数组倒置
	} 
}//最后修改：2023/4/1
