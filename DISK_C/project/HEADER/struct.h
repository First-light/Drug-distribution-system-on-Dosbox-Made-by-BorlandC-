#define NAME_MAX_LENGTH 20
#ifndef _STRUCT_H_
#define _STRUCT_H_
struct robot
{
	int x;
	int y;
	int x2;
	int y2;
	int state;
	int medi;
	int count;
	int ystart;
	int pat;
};

typedef struct patient{
		char name[NAME_MAX_LENGTH];//用户名
		int payreg;//是否诊断（1或0） 
		int paymed;//是否付药费（1或0） 
		int numreg;//挂号号码 
		int nummed;//取药号码 
		int window;//取药窗口 
		int medicine_list[6][3];//诊断方案
		char doctor[5];
		char timer[13];
		int sexual;
		int age;
		struct patient *next;//链表
} PatientData ;

typedef struct MedData
{
	int ID;//每一个药的专属信息 
	int Store_No;//药品所在药格序号 
	char name[25];//药品名 
	int margin;//余量 
	int inventory;//库存上限 
	int price;//单价 
	int x;//x坐标 
	int y;//y坐标 
	struct MedData *next;//指针域
} MED;



#endif 
