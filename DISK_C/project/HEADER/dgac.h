/*
¡¾Ò©Æ·Ìí¼ÓÄ£¿é¡¿ 
±àÐ´ÈË£º·®·¶ 
*/
#include "struct.h"

#ifndef __DGAC_H__
#define __DGAC_H__
MED*creatlist();
MED*creatNode(MED*medicine);

void printlist_FILE(MED *headNode);

void insertNodeByHead(MED*medicine,MED*headNode);

void insertNodeByTail(MED*medicine,MED*headNode);

MED*reopen(MED*medicine) ;

int add(MED*medicine,MED*headNode); 

void int_trans_char(int number,char*nowchar);

int char_trans_int(char*num); 

void deletNode(MED*headNode,int*Delet_Item);
int check_em( MED* medicine);
void DrugDelet(MED*medicine ,int* markout);

void plus(MED*medicine);
void minus(MED*medicine);
void Notice(void);

void DrugStorManagePg(MED*medicine);
int Department_Choose(int num,int*Outpatient,int*Department);
int diagnosising(PatientData* p);

int Result_List(PatientData* p);
#endif
