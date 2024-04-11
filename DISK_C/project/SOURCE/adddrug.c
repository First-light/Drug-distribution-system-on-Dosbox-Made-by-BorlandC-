#include <common.h>
/******************************************************************
	【药品增添绘画函数】 
编写人：樊范
传入：void
传出：void
函数功能：绘制基本药品添加页面 
*******************************************************************/

void adddrug_screen(void)
{
	cleardevice();
	setbkcolor(WHITE);
    frameline();
    setfillstyle(1,LIGHTGRAY);
    bar(40, 150, 440, 190);
    bar(40,230,440,270) ;
    bar(40,310,440,350);
    bar(40,390,440,430);
    bar(460,230,560,260); 
    puthz(40,40, "添加药品窗口", 48, 48, DARKGRAY);
    puthz(40, 120, "新药品名称：", 24, 24, DARKGRAY);
    puthz(40, 200, "新药品库存：", 24, 24, DARKGRAY);
    puthz(40, 280, "新药品单价：", 24, 24, DARKGRAY);
    puthz(40, 360, "新药品存放药格（上限三十四）：", 24, 24, DARKGRAY);
    puthz(460, 230, "确认添加", 24, 24, DARKGRAY);
    setcolor(DARKGRAY);
	setlinestyle(0, 0, 3);
}

/******************************************************************
	【药品增添页面操作函数】 
编写人：樊范
传入：void
传出：int page(页面page跳转) 
函数功能：页面跳转，药品添加页面鼠标操作，输入框的读入药品数据 
*******************************************************************/
int adddrug(void)
{
	MED*medicine = (MED*)malloc(sizeof(MED));//创建一个工具结构 
	MED*list =reopen(medicine);//初始化药品链表 
	MED*mt = NULL;
	int page = 0;
	int data1[9]={40,150,400,40,22,8,18,1,2};
	int data2[9]={40,230,400,40,22,8,3,1,2};
	int data3[9]={40,310,400,40,22,8,3,1,2};
	int data4[9]={40,390,400,40,22,8,2,1,2};
	int x=1;
	int y=1;
	int z=1;
	int q=1; 
	int k=0;
	char data_inventory[4]={'\0'};
	char data_price[7]={'\0'};
	char data_drugno[3]={'\0'};//四个集成读取数据的传入参数 
	clrmous(MouseX,MouseY);
	adddrug_screen();//显示基本页面 
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
			else if(MouseX > 460 && MouseY > 230 && MouseX < 560 && MouseY < 260)
			{
				MouseS = 1;
				break;
			}
			else if(MouseX > 40 && MouseY > 150 && MouseX < 440 && MouseY < 190)
			{
				MouseS = 2;
				break;
			}
			else if(MouseX > 40 && MouseY > 230 && MouseX < 440 && MouseY < 270)
			{
				MouseS = 2;
				break;
			}
			else if(MouseX > 40 && MouseY > 310 && MouseX < 440 && MouseY < 350)
			{
				MouseS = 2;
				break;
			}
			else if(MouseX > 40 && MouseY > 390 && MouseX < 440 && MouseY < 430)
			{
				MouseS = 2;
				break;
			}
			else
			{
				MouseS = 0;
				break;
			}
		}//while根据鼠标位置显示鼠标状态 

		if(mouse_press(600, 0, 600+40 , 0 + 40) == 1)
		{
		  page = 26;
		  delay(200);
		  break; 
		}//退出界面 
		else if(mouse_press(460,230,560,260) == 1)
		{	
		  medicine->inventory = INT_CHAR_Change(data_inventory);
		  medicine->price = INT_CHAR_Change(data_price);
		  medicine->Store_No = INT_CHAR_Change(data_drugno);//将读取到的数据先临时存入新结构体 
		  k = add(medicine,list);//进入逻辑判断提示和数据重新写入文件流程 
          if(k == 1)
          {
          	puthz(460,310, "药品添加成功", 16, 16, RED);
		  }
		  delay(500);
		  page=26; 
		  break; 
		}//执行添加操作判断，并且成功则传入数据，并显示成功 
		    CreateButton_INPUT_3  (data1,&x,medicine->name,"\0",1);
			CreateButton_INPUT_3  (data2,&y,data_inventory,"\0",1);
			CreateButton_INPUT_3  (data3,&z,data_price,"\0",1); 
			CreateButton_INPUT_3  (data4,&q,data_drugno,"\0",1); //按钮集成读取 
	}
		mt = list->next;
		while(mt != NULL)
		{
			free(list);
			list = mt;
			mt = mt->next;
		}
		free(list);
		free(medicine);//将空结构体free掉 
	return page;//返回page跳转界面 
}    
