#include <struct.h>
#ifndef _ROBOT_H_
#define _ROBOT_H_

void Robot_Setup (struct robot* r,int n);
void Robot_Output (struct robot* r,int n);
MED* Robot_workdelieve(struct robot* ro,PatientData* p,int* n,MED* me);
int Robot_ifwork(PatientData* p);
int Robot_move(struct robot* ro,int xn,int yn);
void Robot_analyse(MED* m,int* output,PatientData* p,struct robot* ro1,struct robot* ro2);


void normal_block(int x,int y);
void medicine_block(int x,int y,MED* m,int i,int j);
void Store_draw (int* data,MED* m);
void Robot_draw (int* data,struct robot* ro);

void Robot_Working(struct robot* ro1,PatientData* p,MED* m);
void Robotstate_Show(int x,int y,struct robot* ro,char* text,int* flash);
#endif 
