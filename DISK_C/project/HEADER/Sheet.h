#ifndef _SHEET_H_
#define _SHEET_H_


void SheetCell_1 (PatientData* p,int n,int x,int y,int *length_x);
void SheetCreate_1 (int x,int y,PatientData* p,int page,int* check);
void SheetTitle_1(int x,int y,int length_x);
int SheetCreate_2 (int x,int y,PatientData* p,int page,int* check);
void SheetCell_2_on(PatientData* p,int n,int x,int y,int *length_x);
int SheetCreate_3 (int* data,PatientData* p,int page,int* check);
void SheetCell_3(PatientData* p,int n,int x,int y,int *length_x);
void SheetCell_3_on(PatientData* p,int n,int x,int y,int *length_x);
void SheetTitle_4(int x,int y,int length_x);
void SheetTitle_3(int x,int y,int length_x);
void SheetTail_4(int x,int y,int length_x);
void SheetCell_4(PatientData* p,int n,int *data,int* length_x,int style);

int SheetCreate_4 (int* data,PatientData* p,int page,int* check,char* input);
void SheetCell_5(PatientData* p,int n,int *data,int* length_x,char* input);

void SheetCell_MED(PatientData* p,int *output,int *data,int* length_x,char* input2);
int SheetCreate_4_MED (int* data,PatientData* p,int* output,int* check,char* input);

int CreateButton_pagechange (int x,int y,int*button,int* sheetpage,int length_x);

#endif 
