/******************************************************************
		【按钮集成模块文件】
编写人：徐哲轩
文件功能：包含大部分按钮功能函数的文件
*******************************************************************/
#ifndef __CBUTT_H__
#define __CBUTT_H__

int CreateButton_4  (char* text,int* data,int* button);
int CreateButton_OUT  (int x,int y,int change,int* button);

int Password_Check(char* input);



void CreateButton_open  (int* data,int* button,int* key);

void INPUTbutton_3 (int* data,char* input,int key);
void INPUTbutton_Write_3(int x,int y,int length_x,int length_y);
void CreateButton_INPUT_3  (int *data,int* button,char* input,char* text,int key);

int Button_4_Lock(int old,int* count,int* change,char*check,int style);
#endif
