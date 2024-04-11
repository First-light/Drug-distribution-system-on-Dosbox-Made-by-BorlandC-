#include <stdio.h>
#include "LVup.h"
#include <time.h>
#include <string.h>

/******************************************************************
		【时间检索函数】
编写人：徐哲轩
传入：char* input,char* check
传出：int（比较结果）
函数功能：将时间对比，对比符合要求则返回0
*******************************************************************/
int TimeCheck(char* input,char* check)
{
	int back = 0;
	int i = 0;
	while(input[i] != 0 &&check[i] != 0)
	{
		if(input[i]-check[i] == 0)
		{
		}
		else if(input[i]-check[i] > 0)
		{
			back = 1;
			break;
		}
		else
		{
			back = -1;
			break;
		}
		i++;
	}
	return back;
}


/******************************************************************
		【时间输出函数】
编写人：徐哲轩
传入：char *time0
传出：void
函数功能：将当前的系统时间按格式赋值给time0
*******************************************************************/
void TimeOut (char *time0)
{
	char minute[3] = {0};
	char hour[3] = {0};
	char day[3] = {0};
	char month[3] = {0};
	char year[5] = {0};
	struct tm* local;
	time_t timer;
	timer = time(NULL);
	local = localtime(&timer);
	strcpy(time0,"\0");
	CHAR_INT_Change2(minute,local->tm_min,2);
	CHAR_INT_Change2(hour,local->tm_hour,2);
	CHAR_INT_Change2(day,local->tm_mday,2);
	CHAR_INT_Change2(month,local->tm_mon +1,2);
	CHAR_INT_Change2(year,local->tm_year + 1900,4);
	strcpy(time0,year);
	strcat(time0,month);
	strcat(time0,day);
	strcat(time0,hour);
	strcat(time0,minute);
}
