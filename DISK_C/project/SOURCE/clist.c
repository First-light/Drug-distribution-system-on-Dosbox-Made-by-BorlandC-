#include "LVup.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/******************************************************************
		【诊断方案导入函数】
编写人：徐哲轩
传入：PatientData* p,FILE * pf
传出：int
函数功能：将文件的患者诊断数据导入链表
*******************************************************************/
int ListRead(PatientData* p,FILE * pf)
{
	int i = 0;//计数
	for( ;i < 6 ;)
	{//循环输入诊断方案，不超过6个方案，防止数组越界！！
		char in = fgetc(pf);
		if( in == '&')
		{//检测到&输入方案
		fscanf(pf,"%d %d %d",
		&((p)->medicine_list[i][0]),
		&((p)->medicine_list[i][1]),
		&((p)->medicine_list[i][2]));
		i++;
		}
		else if(in == '$'||in == -1)
		{//如果到了文件结尾，或者到了结束符号
			for(;i<6;i++)
			//i<6防止数组越界
			{//将剩下的数组单元初始化为0，防止输出未初始化的数据导致崩溃！
			(p)->medicine_list[i][0] = 0;
			(p)->medicine_list[i][1] = 0;
			(p)->medicine_list[i][2] = 0;
			}
			break;//退出循环
		}
	}	
	return -1;//给in2赋值，退出循环
}

/******************************************************************
		【链表创建函数】
编写人：徐哲轩
传入：int n除头节点以外的节点个数
传出：头节点
函数功能：创建指定大小的链表
*******************************************************************/
PatientData* creat(int n)
{
	int i;//循环计数
	PatientData *head, *conti , *end;//定义头节点，普通节点，尾部节点
	head = (PatientData *)malloc(sizeof(PatientData));//分配地址
	end = head;//如果是空链表则头尾节点一样
	for(i = 0 ; i < n ;i++)
	{
		conti = (PatientData*) malloc(sizeof(PatientData));//创建一个新的节点
		end->next = conti;//将尾节点的next等于新的节点
		end = conti;//将新的节点定义为尾节点
	}
	end->next = NULL;//将尾节点的next成员封死，封装链表
	return head;
}

/******************************************************************
		【链表数据导入函数】
编写人：徐哲轩
传入：PatientData* p,int n,FILE * pf,int state（模式）
传出：void
函数功能：将文件数据按照指定格式导入链表
*******************************************************************/
void ListInput(PatientData* p,int n,FILE * pf,int state)
{//链表读取函数
//n为要修改的第n个节点
//state 表示搜素模式
	char in2 = 0;
	if(p != NULL)
	{//检测节点是否存在，防止崩溃
		for(;in2 != -1;)
		{//如果文件结束，停止读取
			in2 = fgetc(pf);//按char读取文件，检测输入
			if( in2 == '#')
			{//读到#开始输入
				char p_name[20] = {0};
				fscanf(pf,
					" %s %d %d %d %d %d %s %s %d %d $",
					p_name,
					&((p)->payreg),
					&((p)->paymed),
					&((p)->numreg),
					&((p)->nummed),
					&((p)->window),
					(p)->doctor,
					(p)->timer,
					&((p)->sexual),
					&((p)->age)
				);//格式化读取
				strcpy( (p)->name, p_name);
				switch (state)
				{//模式检测
					case 1:
						if((p)->numreg == n)
						{//此数据符合要求
						in2 = ListRead(p,pf);//读入数据，并将-1赋值给in2，退出循环，退出函数
						}
						break;
					case 0:
						//读入数据，并将-1赋值给in2，退出循环，退出函数
						in2 = ListRead(p,pf);
						break;
					default:
						break;
				}
			}
			else if(in2 == -1)
			{//如果到文件结束时也没找到符合要求的数据，则保留空链表，初始化为0，防止程序直接输出没有初始化导致崩溃
				int i3=0;
				strcpy( (p)->name, "\0");
				strcpy( (p)->doctor, "\0");
				strcpy( (p)->timer, "\0");
				((p)->payreg) = 0;
				((p)->paymed)= 0;
				((p)->numreg)= 0;
				((p)->nummed)= 0;
				((p)->window)= 0;
				((p)->sexual) = 0;
				((p)->age) = 0;
				for(;i3<6;i3++){
				(p)->medicine_list[i3][0] = 0;
				(p)->medicine_list[i3][1] = 0;
				(p)->medicine_list[i3][2] = 0;
				}
			break;//文件结束退出循环
			}
		}
	}
}



/******************************************************************
		【删除链表函数】
编写人：徐哲轩
传入：PatientData* list
传出：void
函数功能：将链表删除
*******************************************************************/
void deletall(PatientData* list)
{
	int i = 0;
	PatientData* m = list;
	for(; m != NULL;i++)
	{
		list = (list)->next;
		free(m);
		m = list;
	}
}
//void delet(PatientData* list,int n){
//	PatientData*p = (list)->next;
//	PatientData*in = list;
//	int i = 0;//定义循环计数
//	while(i<n && (p)->next != NULL){
//		in = p;
//		p = p->next;
//		i ++;
//	}
//	if(p != NULL){
//		in->next = p->next;
//		free(p);
//	}
//	else{
//	}
//}


/******************************************************************
		【链表插入节点函数】
编写人：徐哲轩
传入：PatientData* list,int n
传出：void
函数功能：在链表的指定位置插入节点
*******************************************************************/
void insert(PatientData* list,int n)
{
	PatientData*p = list;
	PatientData*in;
	int i = 0;
	while(i<n && (p) != NULL)
	{
		p = p->next;
		i ++;
	}
	in = (PatientData*) malloc(sizeof(PatientData));
	{
		//插入初始化为0的节点
		int i3=0;
		strcpy( (in)->name, "A");
		strcpy( (in)->doctor, "A");
		strcpy( (in)->timer, "A");
		((in)->payreg) = 0;
		((in)->paymed)= 0;
		((in)->numreg)= 0;
		((in)->nummed)= 0;
		((in)->window)= 0;
		((in)->sexual)= 0;
		((in)->age)= 0;
		for(;i3<6;i3++)
		{
			(in)->medicine_list[i3][0] = 0;
			(in)->medicine_list[i3][1] = 0;
			(in)->medicine_list[i3][2] = 0;
		}
	}
	in->next = p->next;
	p->next = in;
}

/******************************************************************
		【链表节点修改函数】
编写人：徐哲轩
传入：PatientData* list,PatientData* input,int n,int state
传出：void
函数功能：节点数据更改
*******************************************************************/
void Listchange(PatientData* list,PatientData* input,int n,int state)
{
	PatientData*p = list;
	int i = 0;
	switch (state)
	{//模式检测
		case 1:
			while((p)->next != NULL)
			{
				if((p)->numreg == n)
				{//此数据符合要求
					break;
				}else{
				p = p->next;
				}
			}
		case 0:
			while(i<n && p != NULL)
			{
				p = p->next;
				i ++;
			}
			break;
		default:
			break;
	}
	if(p!=NULL)
	{
	int i3 = 0;
			 strcpy( (p)->name, (input)->name);
			 strcpy( (p)->doctor, (input)->doctor);
			 strcpy( (p)->timer, (input)->timer);
			((p)->payreg) = ((input)->payreg);
			((p)->paymed)=((input)->paymed);
			((p)->numreg)= ((input)->numreg);
			((p)->nummed)= ((input)->nummed);
			((p)->window)= ((input)->window);
			((p)->sexual)= ((input)->sexual);
			((p)->age)= ((input)->age);
			for(;i3<6;i3++)
			{
				(p)->medicine_list[i3][0] = (input)->medicine_list[i3][0];/////////////
				(p)->medicine_list[i3][1] = (input)->medicine_list[i3][1];///////////////
				(p)->medicine_list[i3][2] = (input)->medicine_list[i3][2];///////////////
			}
	}
}
