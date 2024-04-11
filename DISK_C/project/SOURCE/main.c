#include <common.h>

/******************************************************************
	【主函数】 
编写人：樊范，徐哲轩
传入：void
传出：void
函数功能：页面跳转，程序主循环，记录数据，初始化绘图函数，退出程序
*******************************************************************/
void main(void)
{

	int page = -1;//页面
	int graphdriver = VGA;
    int	graphmode = VGAHI;
    int IDnumber = 0; //储存挂号号码
	int flash = 1;//初次进入患者线
	//初始化图形界面
    initgraph(&graphdriver, &graphmode, "C:\\BORLANDC\\BGI");
	mouseinit();
	setbkcolor(WHITE);
	setviewport(0,0,MAX_X_LENGTH,MAX_Y_LENGTH,1);
	setfillstyle(BKSLASH_FILL,LIGHTGRAY);
	setlinestyle(0,0,3);
	setcolor(BROWN);
	settextstyle(0,HORIZ_DIR,2);
	
	while(1)
	{
		switch(page)//页面选择
		{
			case -1:
				//主界面
				page = p0();
				break;		
			case 1:
				//患者选择界面
				if(flash == 1)
				{//患者线第一次进入展示就医流程
					Notice_Page_p1();
					flash = 0;
				}
				page = p1plus(&IDnumber) ;
				break;		
			case 2:
				//患者挂号界面
				page = Registered(&IDnumber);
				break;
			case 4:
				//患者诊断界面
				page = p4(&IDnumber);
				break;
			case 6:
				//患者缴费界面
				page = p6(&IDnumber);
				break;
			case 7:
				//患者模拟取药界面
				page = p7(&IDnumber);
				break;
			case 19:
				//加载过度页面
				page = load();
				break;			
			case 13:
				//医生登录页面
				page = p13();
				break;
			case 14:
				//医生选择页面
				page = p14();
				break;
			case 15:
				//挂号记录检索页面
				page = p15();
				break;
			case 16:
				//医生模拟叫号页面
				page = p16();
				break;					
			case 23:
				//医生药品消耗查看页面
				page = DrugOutAnalyse();
				break;
			case 26:
				//药库管理页面
				page =drstma();
				break;	
			case 30:
				//药库添加新药界面
				page =adddrug();
				break;				
			case 20://退出界面 
				closegraph();
				exit(0);
				break;
		}
	}
}
