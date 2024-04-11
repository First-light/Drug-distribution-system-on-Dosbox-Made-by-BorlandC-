#include <common.h>

/******************************************************************
	【科室选择点亮过渡函数】 
编写人：樊范
传入：int num,int*Outpatient（门诊信息检测是否选择）,int*Department（科室信息） 
传出：int num（将所选的科室号码过渡传出） 
函数功能：更新各个门诊按钮的状态并传出所选科室的号码 
*******************************************************************/
int Department_Choose(int num,int*Outpatient,int*Department)
{
	int x=20;
	int y=20;
	int i=0;
	if(Outpatient[2]==0&&(Outpatient[0]==1||Outpatient[1]==1))
		{
			  
			setlinestyle(0,0,5);
            setcolor(DARKGRAY);
            for(i=0;i<6;i++)
		    {
				Department[i] = 0;
			}
		  	Department[num-1]=1;//各个科室根据选择状态重置 
		  	clrmous(MouseX,MouseY);
		  	if(Department[0]==0)
		    {
		  			setfillstyle(1,WHITE);
		  	        bar(x+205,y+75,x+395,y+75+54);
			        puthz(x+215, y+85, "全科医学科", 24, 24, DARKGRAY);
			}
			else 
		    {
		  			setfillstyle(1,LIGHTGRAY);
		  	        bar(x+205,y+75,x+395,y+75+54);
			        puthz(x+215, y+85, "全科医学科", 24, 24, WHITE);
			}
            if(Department[1]==0)
		    {
		  			setfillstyle(1,WHITE);
		  	        bar(x+205,y+75+54,x+395,y+75+54*2);
			        puthz(x+215, y+85+54, "内科", 24, 24, DARKGRAY);
			}
			else 
		    {
		  			setfillstyle(1,LIGHTGRAY);
		  	        bar(x+205,y+75+54,x+395,y+75+54*2);
			        puthz(x+215, y+85+54, "内科", 24, 24, WHITE);
			}
			if(Department[2]==0)
		    {
		  			setfillstyle(1,WHITE);
		  	        bar(x+205,y+75+54*2,x+395,y+75+54*3);
			        puthz(x+215, y+85+54*2, "外科", 24, 24, DARKGRAY);
			}
			else 
		    {
		  			setfillstyle(1,LIGHTGRAY);
		  	        bar(x+205,y+75+54*2,x+395,y+75+54*3);
			        puthz(x+215, y+85+54*2, "外科", 24, 24, WHITE);
			}
			if(Department[3]==0)
		    {
		  			setfillstyle(1,WHITE);
		  	        bar(x+205,y+75+54*3,x+395,y+75+54*4);
			        puthz(x+215, y+85+54*3, "妇科", 24, 24, DARKGRAY);
			}
			else 
		    {
		  			setfillstyle(1,LIGHTGRAY);
		  	        bar(x+205,y+75+54*3,x+395,y+75+54*4);
			        puthz(x+215, y+85+54*3, "妇科", 24, 24, WHITE);
			}
			if(Department[4]==0)
		    {
		  			setfillstyle(1,WHITE);
		  	        bar(x+205,y+75+54*4,x+395,y+75+54*5);
			        puthz(x+215, y+85+54*4, "儿科", 24, 24, DARKGRAY);
			}
			else 
		    {
		  			setfillstyle(1,LIGHTGRAY);
		  	        bar(x+205,y+75+54*4,x+395,y+75+54*5);
			        puthz(x+215, y+85+54*4, "儿科", 24, 24, WHITE);
			}
			if(Department[5]==0)
		    {
		  			setfillstyle(1,WHITE);
		  	        bar(x+205,y+75+54*5,x+395,y+75+54*6);
			        puthz(x+215, y+85+54*5, "心理门诊", 24, 24, DARKGRAY);
			}
			else 
		    {
		  			setfillstyle(1,LIGHTGRAY);
		  	        bar(x+205,y+75+54*5,x+395,y+75+54*6);
			        puthz(x+215, y+85+54*5, "心理门诊", 24, 24, WHITE);
			}//更新各个科室按钮点亮状态 
			for(i=0;i<6;i++) 
			{
				rectangle(x+205,y+75,x+395,y+75+54*i);
			}//重画边框 
	   } 
	   return num;
}
