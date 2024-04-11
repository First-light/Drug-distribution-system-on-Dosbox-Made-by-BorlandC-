#include <common.h>

/******************************************************************
	【入库界面绘制函数】 
编写人：樊范 
传入： int x,int y（界面左上角坐标） 
传出： void 
函数功能：绘制入库界面 
*******************************************************************/

void plus_Page(int x,int y)
{
	setlinestyle(0,0,5);
    setcolor(DARKGRAY);
    setfillstyle(11,YELLOW);
    bar(x,y,x+360,y+240);
    setfillstyle(1,BROWN);
    bar(x,y,x+360,y+30);
    setfillstyle(1,RED);
    bar(x+330,y,x+360,y+30);
    line(x,y,x,y+240);
    line(x,y,x+360,y);
    line(x+360,y,x+360,y+240);
    line(x,y+240,x+360,y+240);
    setlinestyle(0,0,5);
    setcolor(WHITE);
    line(x+335,y+5,x+355,y+25);
    line(x+335,y+25,x+355,y+5);
    puthz(x+5, y+5, "药品添加界面", 24, 24, WHITE);
    puthz(x+5, y+50, "药品名称：", 24, 24, DARKGRAY);
    puthz(x+5, y+100, "添加数量：", 24, 24, DARKGRAY);
    setfillstyle(1,LIGHTGRAY);
    bar(x+130,y+150,x+230,y+180);
    puthz(x+135, y+155, "确认入库", 24, 24, DARKGRAY);
} 

/******************************************************************
	【药品入库操作执行函数】 
编写人：樊范 
传入： MED*list（头节点）,MED*medicine（工具结构指针）,char*data（输入进来的数字） 
传出： void 
函数功能：进行入库执行操作 
*******************************************************************/

void plus_Change(MED*list,MED*medicine,char*data)
{
	int x=120;//小界面的左上角x坐标 
	int y=80;
	int i = 0;
  MED*posNode=list->next;
  while(1)
  {
  	if(strcmp(medicine->name,posNode->name)==0)
  	{
  	  break;	
	}
	else if(posNode->next == NULL)
	{
		i = 1;
		break;
	}
  	posNode = posNode->next;		
  }//寻找到到目标药品 
  if(i == 0)
  {
  	if(posNode->margin+char_trans_int(data)<=999)
  {
  	posNode->margin = posNode->margin+char_trans_int(data);
  } //未达上限并执行 
  else
  {
  	posNode->margin = 999;
  	setlinestyle(0,0,5);
    setcolor(DARKGRAY);
    setfillstyle(11,YELLOW);
    bar(x,y,x+360,y+240);
    setfillstyle(1,BROWN);
    bar(x,y,x+360,y+30);
    setfillstyle(1,RED);
    bar(x+330,y,x+360,y+30);
    line(x,y,x,y+240);
    line(x,y,x+360,y);
    line(x+360,y,x+360,y+240);
    line(x,y+240,x+360,y+240);
    setlinestyle(0,0,5);
    setcolor(WHITE);
    line(x+335,y+5,x+355,y+25);
    line(x+335,y+25,x+355,y+5);
    puthz(x+85, y+120, "已达最大上限", 32, 32, DARKGRAY);
    puthz(x+84, y+119, "已达最大上限", 32, 32, DARKGRAY);
  }//药品已达最大上限 显示提示 
  }//添加结果判断并执行 
  else if(i == 1)
  {
  	setlinestyle(0,0,5);
    setcolor(DARKGRAY);
    setfillstyle(11,YELLOW);
    bar(x,y,x+360,y+240);
    setfillstyle(1,BROWN);
    bar(x,y,x+360,y+30);
    setfillstyle(1,RED);
    bar(x+330,y,x+360,y+30);
    line(x,y,x,y+240);
    line(x,y,x+360,y);
    line(x+360,y,x+360,y+240);
    line(x,y+240,x+360,y+240);
    setlinestyle(0,0,5);
    setcolor(WHITE);
    line(x+335,y+5,x+355,y+25);
    line(x+335,y+25,x+355,y+5);
    puthz(x+85, y+120, "未找到该药品", 32, 32, DARKGRAY);
    puthz(x+84, y+119, "未找到该药品", 32, 32, DARKGRAY);
  } //未检索到药品并提示 
} 

/******************************************************************
	【药品入库操作函数】 
编写人：樊范 
传入：MED*medicine（工具结构指针）
传出： void 
函数功能：进行入库操作 
*******************************************************************/
void plus(MED*medicine)
{
	int page = 0;//页面跳转记录
	int i;//常规操作的参数
	int x=120;//小界面的左上角x坐标 
	int y=80; //小界面的左上角y坐标
	int data_name[9]={250,130,220,40,22,8,20,1,2};
	int data_num[9]={250,180,220,40,22,8,3,1,2};
	int m = 1;
	int n = 1;
	char data[4]={'\0'};
	MED*list =reopen(medicine);
	MED* mt = medicine;
	plus_Page(x,y);
	while(page == 0)
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
			else if (MouseX > x+130 && MouseY > y+150 && MouseX < x+230 && MouseY < 180)
			{
				MouseS = 1;
				break;
			}
			else
			{
				MouseS = 0;
				break;
			}
		}
		
		if(mouse_press(600, 0, 600+40 , 0 + 40) == 1)
		{
		  page = 20;
		  delay(200);
		  break; 
		}//退出药库 

        else if(mouse_press(x+330,y,x+360,y+30) == 1)
		{
		  delay(200);
		  break; 
		}//退出小界面 
         else if(mouse_press(x+130,y+150,x+230,y+180) == 1)
		{
		 plus_Change(list,medicine,data);
		 delay(2000); 
		 break; 
		}//确认添加
		CreateButton_INPUT_3  (data_name,&m,medicine->name,"\0",1);
		CreateButton_INPUT_3  (data_num,&n,data,"\0",1);//输入框模块
	}
	printlist_FILE(list);
	mt = list->next;
	while(mt != NULL)
	{
		free(list);
		list = mt;
		mt = mt->next;
	}
	free(list);
} 
