#include <struct.h>
#ifndef _PAGE_H_
#define _PAGE_H_


int p0(void);
int p1(int* IDnumber);
int p4(int* IDnumber);
int p6(int* IDnumber);
int p7(int *IDnumber);

int p13(void);
int p14(void);
int p15(void);
int p16(void);
int load(void);

void Notice_Page_p1(void);
int p1plus( int *IDnumber);
int Registered(int* IDnumber);

int drstma(void);
int adddrug(void);
int Re_List(PatientData* p);
int DrugOutAnalyse(void);
void p16_screen(void);
#endif 
