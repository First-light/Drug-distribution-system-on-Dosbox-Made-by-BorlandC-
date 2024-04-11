#include <common.h>

/******************************************************************
	【管理界面缺药个数统计函数】 
编写人：樊范
传入：MED*medicine（工具结构空指针） 
传出：int j(缺药个数显示) 
函数功能：统计缺药的药品个数 
*******************************************************************/

int check_em( MED* medicine)
{
		int j = 0; 
		FILE*fp; 
		fp=fopen("C:\\project\\DATABASE\\drugdata.txt","r");
			while(1)
			{
			    while(1)
			    {
			    	if(feof(fp))
	                {	
	                	break;
					}
			    	fscanf(fp,"%d\t%d\t%s\t%d\t%d\t%d\n",&medicine->ID,&medicine->Store_No,medicine->name,&medicine->price,&medicine->margin,&medicine->inventory);
			    	if(medicine->inventory/10>=medicine->margin)
		            {
		            	j++;
                        break;
	                }//检测到一个缺药j加一进入往后循环 
	                else if(feof(fp))
	                {	
	                	break;
					}//到文件末尾退出 
				}
                if(feof(fp))
				break;//文件末尾退出整个函数 
           }
		fclose(fp);	
		return j;
}

/******************************************************************
	【缺药提醒界面绘制函数】 
编写人：樊范
传入： int x,int y（页面显示的左上角坐标）,int mark（刷新药单的页面数）
传出：void 
函数功能：缺药提醒界面绘制
*******************************************************************/


void Notice_Page(int x,int y,int mark)
{
	int i = 0;
	char nowchar[2]={0};
	setlinestyle(0,0,5);
    setcolor(DARKGRAY);
    setfillstyle(1,LIGHTBLUE);
    bar(x,y,x+360,y+320);
    setfillstyle(1,BLUE);
    bar(x,y,x+360,y+30);
    setfillstyle(1,RED);
    bar(x+330,y,x+360,y+30);
    line(x,y,x,y+320);
    line(x,y,x+360,y);
    line(x+360,y,x+360,y+320);
    line(x,y+320,x+360,y+320);
    setlinestyle(0,0,3);
    setcolor(WHITE);
    line(x+335,y+5,x+355,y+25);
    line(x+335,y+25,x+355,y+5);
    puthz(x+5, y+5, "药品告急提醒", 24, 24, WHITE);
    puthz(x+5, y+45, "序号", 16, 16, YELLOW);
    puthz(x+45, y+45, "药品名称", 16, 16, YELLOW);
    puthz(x+315, y+45, "余量", 16, 16, YELLOW);
    puthz(x+120,y+280, "请尽快根据提示", 16, 16, RED);
    puthz(x+120,y+300, "信息补齐药品！", 16, 16, RED);
    puthz(x+260,y+290, "页面：", 16, 16, WHITE);
    setlinestyle(1,0,1);
    setcolor(WHITE);
    for(i=0;i<6;i++)
    {
		line(x+10,y+30+40*(i+1),x+350,y+30+40*(i+1));
	}
	setfillstyle(1,LIGHTGRAY);
    bar(x+10,y+290,x+50,y+310);
    bar(x+60,y+290,x+100,y+310);
    int_trans_char(mark,nowchar);//将传入页数转化为char 
    setcolor(WHITE);
    settextstyle(1,0,2) ;
    outtextxy(x+310,y+283,nowchar);//让char显示在界面上 
    strcpy(nowchar,"\0");
}

/******************************************************************
	【缺药提醒界面操作函数】 
编写人：樊范
传入：void 
传出：void 
函数功能：缺药提醒界面的翻页，退出，鼠标显示操作 
*******************************************************************/

void Notice(void)
{
	int mark=1;//指示每一页药库显示的标记 
	int check = 1;
	MED*medicine = (MED*)malloc(sizeof(MED));//创建一个工具结构
	int i;//常规操作的参数
	int x=120;//小界面的左上角x坐标 
	int y=80; //小界面的左上角y坐标
	Notice_Page(x,y,mark);	
    while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		while(1)
		{
			if (MouseX > 600 && MouseY > 0 && MouseX < 640 && MouseY < 40)
			{
				MouseS = 1;
				break;
			}
			else if (MouseX > x+250 && MouseY > y && MouseX < x+280 && MouseY < y+30)
			{
				MouseS = 1;
				break;
			}
			else if (MouseX > x+10 && MouseY > y+290 && MouseX < x+50 && MouseY < 310)
			{
				MouseS = 1;
				break;
			}
			else if (MouseX > x+60 && MouseY > y+290 && MouseX < x+100 && MouseY < 310)
			{
				MouseS = 1;
				break;
			}
			else
			{
				MouseS = 0;
				break;
			}
		}//while根据鼠标位置显示鼠标状态 
		
		
		if(check)
		{
			char nowchar[6]={0};//数据类型转换空数组 
			int cell_num = 5;//页面最大条目上限 
			FILE*fp;
			int k = 0; 
			fp=fopen("C:\\project\\DATABASE\\drugdata.txt","r");
			clrmous(MouseX,MouseY);
			settextstyle(1,0,2);
			Notice_Page(x,y,mark); //重新绘制界面 
			for(i= 1;i < cell_num + (mark-1)*cell_num +1 ;i++)
			{	
			    while(1)
			    {
			    	fscanf(fp,"%d\t%d\t%s\t%d\t%d\t%d\n",&medicine->ID,&medicine->Store_No,medicine->name,&medicine->price,&medicine->margin,&medicine->inventory);
			    	if(medicine->inventory/10>=medicine->margin)
		            {
                        break;
	                }
	                else if(feof(fp))
	                {
	                	
	                	break;
					}
				}//找寻缺药的条目 
			if(!feof(fp)||medicine->inventory/10>=medicine->margin)
			{
					if( i < (mark-1)*cell_num +1 )
				{		
				}
				else
				{
					if(medicine->ID<1000&&medicine->ID>0)
					{
						int_trans_char(i/*5*(mark-1)+k+1*/,nowchar);
						outtextxy(x+15,y+85+40*k,nowchar);
						strcpy(nowchar,"\0");
						outtextxy(x+45,y+85+40*k,medicine->name);
						int_trans_char(medicine->margin,nowchar);
						outtextxy(x+315,y+85+40*k,nowchar);
						strcpy(nowchar,"\0");						
					}
					k++ ;
				}
			}//将缺药条目进行输出 
				if(feof(fp))break;
			}
			fclose(fp);		
			check = 0;//重置状态 
		}
		
        if(mouse_press(x+330,y,x+360,y+30) == 1)
		{
		  delay(200);
		  break; 
		}//退出小界面 
        else if(mouse_press(x+10,y+290,x+50,y+310) == 1)
		{
			mark--;//mark减fscanf读取数目减少，文件指针提前，刷新时实现翻页 
			mark = max(mark,1);//防止mark变成0 
		  strcpy(medicine->name,"\0");
		  medicine->margin=0;
		  medicine->price=0;
		  medicine->inventory=0;//翻页时重置工具指针 
		  check = 1;//传递要改变状态 
		  delay(200);
		  continue; 
		}//左翻药单 
		else if(mouse_press(x+60,y+290,x+100,y+310) == 1)
		{
			mark++;//mark增fscanf读取数目增加，文件指针靠后，刷新时实现翻页 
		  strcpy(medicine->name,"\0");
		  medicine->margin=0;
		  medicine->price=0;
		  medicine->inventory=0;//翻页时重置工具指针 
		  delay(200);
		  check = 1;//传递要改变状态 
		  continue; 
		}//右翻药单 
  }
}
