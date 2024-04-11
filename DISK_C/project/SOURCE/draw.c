#include <graphics.h>
#include <stdio.h>

/******************************************************************
		【绘图函数】
编写人：徐哲轩
传入：int picnum,int x,int y,int index
传出：void
函数功能：在指定位置画出预制图案
*******************************************************************/
void Pic_Draw(int picnum,int x,int y,int index)
{
int x_length = 60;
int y_length = 60;
if(index){}
	switch (picnum) 
	{
		case 1:
			index = 1;
			setfillstyle(1,WHITE);
			bar(x,y,x+x_length,y+y_length);
			setfillstyle(1,LIGHTBLUE);
			setcolor(LIGHTBLUE);
			setlinestyle(0, 0, 3);
			line(x,y+y_length,x,y+y_length-20);
			line(x+x_length,y+y_length,x+x_length,y+y_length-20);
			line(x,y+y_length-20,x+5,y+y_length-20-5);
			line(x+x_length,y+y_length-20,x+x_length-5,y+y_length-20-5);
			bar(x+10,y+12,x+x_length-10,y+y_length);
			setfillstyle(1,WHITE);
			bar(x+12+2,y+12+2,x+x_length-12-2,y+y_length-2);
			setfillstyle(1,LIGHTBLUE);
			bar(x+25,y-3,x+x_length-25,y+18+4);
			bar(x+18,y+7+2-5,x+x_length-18,y+7+2+5);
			bar(x+20,y_length+y-17,x+x_length-20,y+y_length);
			setfillstyle(1,WHITE);
			bar(x+25+2,y-3+2,x+x_length-25-2,y+18+4-2);
			bar(x+18+2,y+7+2-5+2,x+x_length-18-2,y+7+2+5-2);
			bar(x+22+2,y_length+y-17+2,x+x_length-22-2,y+y_length-2);
			line(x+20,y+30-2,x+x_length-20,y+30-2);
			line(x+20,y+35+2,x+x_length-20,y+35+2);
			setfillstyle(1,LIGHTBLUE);
			bar(x,y+y_length,x+x_length,y+y_length-3);
			break;
		default:
			break;
	}
}
/******************************************************************
		【界面边框函数】
编写人：樊范
传入：void
传出：void
函数功能：画出界面边框
*******************************************************************/
void frameline()
{
    setfillstyle(1,RED);
    bar(600, 0, 600+40 , 0 + 40);
	setcolor(DARKGRAY);
	setlinestyle(0, 0, 3);
	line(605,5,635,35);
	line(605,35,635,5);
	setcolor(DARKGRAY);
	setlinestyle(0, 0, 3);
	line(605,35,635,5);
	line(0,0,600,0) ;
	line(0,10,600,10) ;
	line(0,0,0,480) ;
	line(10,0,10,480) ;
	line(0,470,640,470) ;
	line(0,480,640,480) ;
	line(630,40,630,480) ;
	line(640,40,640,480) ;
}

/******************************************************************
		【界面边框函数2号】
编写人：徐哲轩
传入：void
传出：void
函数功能：画出另一种形式的界面边框
*******************************************************************/
void frameline2(void)
{	
	setfillstyle(1,DARKGRAY);
	bar(600,0, 640,40);
	setfillstyle(1,WHITE);
	bar(600+2, 0+2, 640-2,40-2);
	setcolor(DARKGRAY);
	setlinestyle(0, 0, 3);
	line(605,5,635,35);
	line(605,35,635,5);
	setcolor(DARKGRAY);
	setlinestyle(0, 0, 3);
	line(605,35,635,5);
	line(0,0,600,0) ;
	line(0,10,600,10) ;
	line(0,0,0,480) ;
	line(10,0,10,480) ;
	line(0,470,640,470) ;
	line(0,480,640,480) ;
	line(630,40,630,480) ;
	line(640,40,640,480) ;
}
