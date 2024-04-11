#include "struct.h"
#include <stdio.h>
#ifndef _LVUP_H_
#define _LVUP_H_

int INT_CHAR_Change(char* ar);
int INT_CHAR_Change2(char* ar,int n);
void CHAR_INT_Change(char* ar2,int b);
void CHAR_INT_Change2(char* ar2,int b,int n);

void TimeOut (char *time0);
int TimeCheck(char* input,char* check);
void DoctorShow(char* input,char* output,int mode);
int DoctorCheck(char* input,char* check);


void frameline(void);
void frameline2(void);
void Pic_Draw(int picnum,int x,int y,int index);

void Number_no_same(PatientData* m,int start);

void ListInput(PatientData* m,int n,FILE* pf,int state);
int ListRead(PatientData* p,FILE* pf);
void deletall(PatientData* list);
void delet(PatientData* list,int n);
void insert(PatientData* list,int n);
PatientData* creat(int n);
void Listchange(PatientData* list,PatientData* input,int n,int state);

PatientData* findpat(char* inputc,PatientData* head,int style);
void NO_XY_flash(MED* m);

#endif
