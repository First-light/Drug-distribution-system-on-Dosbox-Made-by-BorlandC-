#include <common.h>

/******************************************************************
	【药库管理界面绘画函数】 
编写人：樊范 
传入：MED*medicine（工具结构指针） 
传出：void
函数功能：绘制药库管理界面 
*******************************************************************/
 
void DrugStorManagePg(MED* medicine)
{
	int i;//常规操作的参数 
	int j = 0;
	char nowchar[3]={0};
	cleardevice();
	setbkcolor(WHITE);
	setfillstyle(11,DARKGRAY);
	bar(0, 0, 600,40 );
    frameline();
    setfillstyle(1,LIGHTGRAY);
    for(i=0;i<6;i++)
    {
    	bar(80,80+i*40,560,120+i*40);
	}
	setlinestyle(0,0,5);
    setcolor(DARKGRAY);
    for(i=0;i<7;i++)
    {
    	line(80,80+i*40,560,80+i*40);
	}
	line(80,80,80,320);
	line(120,80,120,320);
	line(160,80,160,320);
	line(440,80,440,320);
	line(480,80,480,320);
	line(520,80,520,320);
	line(560,80,560,320);
	puthz(85, 90, "状态", 16, 16, DARKGRAY);
    puthz(125, 90, "序号", 16, 16, DARKGRAY);
    puthz(165, 90, "药品名称", 16, 16, DARKGRAY);
    puthz(445, 90, "单价", 16, 16, DARKGRAY);
    puthz(485, 90, "药格", 16, 16, DARKGRAY);
    puthz(525, 90, "库存", 16, 16, DARKGRAY);
    bar(80,360,140,400);
    rectangle(80,360,140,400);
    puthz(90, 370, "增添", 24, 24, DARKGRAY);
    bar(80,410,140,450);
    rectangle(80,410,140,450);
    puthz(90, 420, "入库", 24, 24, DARKGRAY);
    bar(160,360,220,400);
    rectangle(160,360,220,400);
    puthz(170, 370, "删除", 24, 24, DARKGRAY);
    bar(160,410,220,450);
    rectangle(160,410,220,450);
    puthz(170, 420, "出库", 24, 24, DARKGRAY);
    bar(250,360,290,400);
    rectangle(250,360,290,400);
    bar(310,360,350,400);
    rectangle(310,360,350,400);
    bar(370,360,590,400);
    rectangle(370,360,590,400);
    puthz(375, 365, "药品数量告急：", 24, 24, RED);
    puthz(565, 365, "项", 24, 24, RED);
    setfillstyle(1,DARKGRAY);
    line(255,380,285,395);
    line(255,380,285,365);
    line(345,380,315,365);
    line(345,380,315,395);
    puthz(15, 15, "药库管理界面", 24, 24, DARKGRAY);
    j = check_em(medicine);
    int_trans_char(j,nowchar);
    setcolor(RED);
    settextstyle(1,0,2) ;
    outtextxy(540,365,nowchar);
    strcpy(nowchar,"\0");
    setcolor(DARKGRAY);
 } 


/******************************************************************
	【药库管理界面主函数】 
编写人：樊范 
传入：void 
传出：int page（页面跳转整型） 
函数功能：实现药库界面出入库，增添删减翻页等功能，返回页面跳转整型 
*******************************************************************/


 int drstma(void)
{
	int page = 0;//页面跳转记�
	int mark=1;//指示每一页药库显示的标记 
	int i=0;//循环工具数
	int MAX_check = 0; //检测上限的数量标志 
	int check = 1;
	MED*medicine = (MED*)malloc(sizeof(MED));//创建一个工具结构 
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
			else if (MouseX > 80 && MouseY > 360 && MouseX < 140 && MouseY < 400)
			{
				MouseS = 1;
				break;
			}//增 
			else if (MouseX > 160 && MouseY > 360 && MouseX < 220 && MouseY < 400)
			{
				MouseS = 1;
				break;
			}//删 
			else if (MouseX > 80 && MouseY > 410 && MouseX < 140 && MouseY < 450)
			{
				MouseS = 1;
				break;
			}//加 
			else if (MouseX > 160 && MouseY > 410 && MouseX < 220 && MouseY < 450)
			{
				MouseS = 1;
				break;
			}//减 
			else if (MouseX > 250 && MouseY > 360 && MouseX < 290 && MouseY < 400)
			{
				MouseS = 1;
				break;
			}//左 
			else if (MouseX > 310 && MouseY > 360 && MouseX < 350 && MouseY < 400)
			{
				MouseS = 1;
				break;
			}//右 
			else if (MouseX > 370 && MouseY > 360 && MouseX < 590 && MouseY < 400)
			{
				MouseS = 1;
				break;
			}//提示 
			else
			{
				MouseS = 0;
				break;
			}
		}
		
		if(check)
		{
			char nowchar[6]={0};//数据类型转换空数组 
			int cell_num = 5;
			int k = 0;
			FILE*fp; 
			fp=fopen("C:\\project\\DATABASE\\drugdata.txt","r");
			clrmous(MouseX,MouseY);
			settextstyle(1,0,2);
			DrugStorManagePg(medicine);
			for(i= 1;i < cell_num + (mark-1)*cell_num +1 ;i++)
			{	
				fscanf(fp,"%d\t%d\t%s\t%d\t%d\t%d\n",&medicine->ID,&medicine->Store_No,medicine->name,&medicine->price,&medicine->margin,&medicine->inventory);
				if( i < (mark-1)*cell_num +1 )
				{		
				}
				else
				{
					if(medicine->ID<1000&&medicine->ID>0)
					{
						int_trans_char(i/*5*(mark-1)+k+1*/,nowchar);
						outtextxy(120,120+40*k,nowchar);
						strcpy(nowchar,"\0");
						outtextxy(160,120+40*k,medicine->name);
						strcpy(nowchar,"\0");
						int_trans_char(medicine->price,nowchar);
						outtextxy(440,120+40*k,nowchar);
						strcpy(nowchar,"\0");
						int_trans_char(medicine->Store_No,nowchar) ;
						outtextxy(480,120+40*k,nowchar);
						strcpy(nowchar,"\0");
						int_trans_char(medicine->margin,nowchar);
						outtextxy(520,120+40*k,nowchar);
						strcpy(nowchar,"\0");						
					}//打印当前药品信息 
					k++ ;//药品标志数增加 
				}
				if(feof(fp))break;
			}
			fclose(fp);		
			check = 0;
		}//页面更新和状态检测模块 
		
		if(mouse_press(600, 0, 600+40 , 0 + 40) == 1)
		{
		  page = 14;
		  delay(200);
		  break; 
		}//退出药库 
		else if(mouse_press(80,360,140,400) == 1)
		{
		  FILE*fp; 
		  fp=fopen("C:\\project\\DATABASE\\drugdata.txt","r");
		  while(1)
		  {
		  	if(feof(fp))
			{
			  	break;
			}
		  	fscanf(fp,"%d\t%d\t%s\t%d\t%d\t%d\n",&medicine->ID,&medicine->Store_No,medicine->name,&medicine->price,&medicine->margin,&medicine->inventory);
	        MAX_check++;
		  } 
			if(MAX_check >= 34)
			{
		 		puthz(240, 420, "药库容量已达上限", 24, 24, RED);
		 		delay(2000);
				setfillstyle(1,WHITE);
	            bar(240, 420, 600,445 );
			 }//检测当前的药库容量，看能否允许添加药品 
			 else
			 {
			 	strcpy(medicine->name,"\0");
		        medicine->margin=0;
		        medicine->price=0;
		        medicine->inventory=0;
		        page = 30;
		        delay(200);
			 }
            fclose(fp);
            break;
		}//药品增加界面 
		else if(mouse_press(160,360,220,400) == 1)
		{
		  DrugDelet(medicine ,& mark);
		  delay(200); 
		  page = 26  ;
		  break;
		}//药品删除界面 
		else if(mouse_press(250,360,290,400) == 1)
		{
			mark--;
			mark = max(mark,1);
		  strcpy(medicine->name,"\0");
		  medicine->margin=0;
		  medicine->price=0;
		  medicine->inventory=0;
		  check = 1;
		  delay(200);
		  continue; 
		}//左翻药单 
		else if(mouse_press(310,360,350,400) == 1)
		{
			mark++;
		  strcpy(medicine->name,"\0");
		  medicine->margin=0;
		  medicine->price=0;
		  medicine->inventory=0;
		  delay(200);
		  check = 1;
		  continue; 
		}//右翻药单 
		else if(mouse_press(80,410,140,450) == 1)
		{
		  plus(medicine);//增加函数 
		  strcpy(medicine->name,"\0");
		  medicine->margin=0;
		  medicine->price=0;
		  medicine->inventory=0;
		  delay(200);
		  check = 1;
		  continue; 
		}//入库
		else if(mouse_press(160,410,220,450) == 1)
		{
		  minus(medicine);//减少函数 
		  strcpy(medicine->name,"\0");
		  medicine->margin=0;
		  medicine->price=0;
		  medicine->inventory=0;
		  delay(200);
		  check = 1;
		  continue; 
		}//出库  
		else if(mouse_press(370,360,590,400) == 1)
		{
		  clrmous(MouseX,MouseY);
		  Notice();//药品缺少提示界面函数 
		  delay(200);
		  check = 1;
		  continue;
		}//药品提示
   }
  	free(medicine);
	return page;
}   
