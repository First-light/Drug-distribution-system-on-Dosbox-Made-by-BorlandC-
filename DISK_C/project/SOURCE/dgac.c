#include <common.h>


/******************************************************************
	【创建药品链表头节点函数】 
编写人：樊范
传入：void 
传出：MED*headNode（头节点指针) 
函数功能：创建药品的头节点 
*******************************************************************/
MED*creatlist(void)
{
	MED*headNode = (MED*)malloc(sizeof(MED));//将headNode变为结构体变量
	headNode->next = NULL;
	headNode->ID = 0;
	return headNode; 	 
}

/******************************************************************
	【创建药品链表普通节点函数】 
编写人：樊范
传入：MED*medicine（空的工具指针） 
传出：MED*newNode（新普通节点指针) 
函数功能：创建药品新的普通节点 
*******************************************************************/

MED*creatNode(MED*medicine)
{
	MED*newNode = (MED*)malloc(sizeof(MED));
	newNode->ID=medicine->ID;
	newNode->Store_No=medicine->Store_No;
	strcpy(newNode->name,medicine->name);
	newNode->margin=medicine->margin;
	newNode->inventory=medicine->inventory;
	newNode->price=medicine->price;
	newNode->next = NULL;
	return newNode;
}

/******************************************************************
	【药品信息写入函数】 
编写人：樊范
传入：MED*headNode（头结点指针） 
传出：void 
函数功能：将整条链表所有品信息重建新同名文本后写入药品数据文本 
*******************************************************************/

void printlist_FILE(MED *headNode)
{
	MED*pMove = headNode->next;//创建用来遍历的结构指针 
	FILE*fp;
	fp=fopen("C:\\project\\DATABASE\\drugdata.txt","w+");
	while(pMove)
	{
		fprintf(fp,"%d\t%d\t%s\t%d\t%d\t%d\n",pMove->ID,pMove->Store_No,pMove->name,pMove->price,pMove->margin,pMove->inventory);
		pMove = pMove->next;
		printf("\n");
	}//边遍历边写入 
	printf("\n");
	fclose(fp);
}


/******************************************************************
	【int转char函数】 
编写人：樊范
传入：int number（所要转换的整形）,char*nowchar（转换后的存放位置） 
传出：void 
函数功能：将最高位数为百位的整形转化为字符串 
*******************************************************************/

void int_trans_char(int number,char*nowchar)
{
	int a = number / 100;
	int c = number % 10;
	int b = (number - 100 * a - c) / 10;
	if (a != 0)
	{
		nowchar[0] = a+'0';
		nowchar[1] = b+'0';
		nowchar[2] = c+'0';
	}
	else if (a == 0 && b != 0)
	{
		nowchar[0] = b+'0';
		nowchar[1] = c+'0';
		nowchar[2] = '\0';
	}
	else if (a == 0 && b == 0)
	{
		nowchar[0] = c+'0';
		nowchar[1] = '\0';
		nowchar[2] = '\0';
	}//逐位转换 

}

/******************************************************************
	【char转int函数】 
编写人：樊范
传入：char*num（所要转换的字符串） 
传出：int NUM（转换后的整型） 
函数功能：将最高位数为十万位的字符串转化为整型 
*******************************************************************/

int char_trans_int(char*num)
{
	int i=0;
	int k=0;
	int NUM=0;
	for(i=0;i<6;i++)
	{
	if(num[i]!='\0')
	k++;
	else 
	break;
    }
	switch(k)
	{
		case 0:
			NUM=0;
			break;
		case 1:
			NUM=num[0]-'0';
			break;
		case 2:
			NUM=(num[0]-'0')*10+(num[1]-'0');
			break;
		case 3:
			NUM=(num[0]-'0')*100+(num[1]-'0')*10+(num[2]-'0');
			break;
		case 4:
			NUM=(num[0]-'0')*1000+(num[1]-'0')*100+(num[2]-'0')*10+(num[3]-'0');
			break;
		case 5:
			NUM=(num[0]-'0')*10000+(num[1]-'0')*1000+(num[2]-'0')*100+(num[3]-'0')*10+(num[4]-'0');
			break;
		case 6:
			NUM=(num[0]-'0')*100000+(num[1]-'0')*10000+(num[2]-'0')*1000+(num[3]-'0')*100+(num[4]-'0')*10+(num[5]-'0');
			break;				
	}//位数判断后逐位转换 
    return NUM;
}

/******************************************************************
	【结点删除函数函数】 
编写人：樊范  徐哲轩 
传入：MED*headNode（头节点）,int*Delet_Item（多选记录着被选择的药品的ID的数组） 
传出：void 
函数功能：将多选所选择的药品数据一并删除，并且重新写入文件 
*******************************************************************/

void deletNode(MED*headNode,int*Delet_Item)
 {
	int i=0;

    for(i=0;i<34;i++)
	{
		if(Delet_Item[i]==0)
		{
			continue; 
		}///若状态为0跳过 
		else
		{
			MED*posNode = headNode->next;
			MED*posNodeFront = headNode;
			while(posNode->ID != Delet_Item[i] && posNode != NULL)
			{
				posNodeFront = posNode;
				posNode = posNode->next;
			}
			if(posNode != NULL)
			{
				posNodeFront->next = posNode->next;
				free(posNode);
				posNode = posNodeFront->next;
			}
			Delet_Item[i]=0;
		}//若状态不为0删除 
	}	
	printlist_FILE(headNode);//打印到文件中 
 }
  
/******************************************************************
	【从头插入节点函数】 
编写人：樊范 
传入：MED*headNode（头节点）,MED*medicine（工具空结构） 
传出：void 
函数功能：将新创建的节点从链表头部插入链表 
*******************************************************************/

void insertNodeByHead(MED*medicine,MED*headNode)
{
	MED*newNode = creatNode(medicine);
	newNode->next = headNode->next;
	headNode->next = newNode;
}
 
 /******************************************************************
	【从尾插入节点函数】 
编写人：樊范 
传入：MED*headNode（头节点）,MED*medicine（工具空结构） 
传出：void 
函数功能：将新创建的节点从链表末尾插入链表 
*******************************************************************/

void insertNodeByTail(MED*medicine,MED*headNode)
{   
    MED*posNode = headNode;//创建遍历指针 
	MED*newNode = creatNode(medicine);
	while(posNode->next!=NULL)
	{
	 posNode=posNode->next;
	}//找到链表末尾 
	
	posNode->next=newNode;
	newNode->next=NULL;
} 

/******************************************************************
	【初始化文件中所有药品信息链表函数】 
编写人：樊范 
传入：MED*medicine（工具空结构） 
传出：MED*list（将已创建好了的信息完备的链表头节点传出） 
函数功能：从文件中边读边创建链表，并将所创建链表的头节点传出 
*******************************************************************/

MED*reopen(MED*medicine) 
{
	int i=0;//这个int是想用来遍历数据个数方便创初始链表的 
	int j=0;//遍历链表的 
	FILE*fp; 
	MED*list =creatlist();//创建一个头指针
	fp=fopen("C:\\project\\DATABASE\\drugdata.txt","rt");
    while(!feof(fp))
	{
	 fscanf(fp,"%d\t%d\t%s\t%d\t%d\t%d\n",&medicine->ID,&medicine->Store_No,medicine->name,&medicine->price,&medicine->margin,&medicine->inventory);
	 if(medicine->ID<1000&&medicine->ID>0)
	 {
	 	i++;
	 }
	}//将文件遍历一遍看要创建几个节点 
	rewind(fp);
	medicine->ID=0;
	medicine->Store_No=0;
	strcpy(medicine->name,"\0");
	medicine->margin=0;
	medicine->inventory=0;
	medicine->price=0;
	medicine->next=NULL;//重置工具结构指针 
	for(j=0;j<i;j++)
	{
	 fscanf(fp,"%d\t%d\t%s\t%d\t%d\t%d\n",&medicine->ID,&medicine->Store_No,medicine->name,&medicine->price,&medicine->margin,&medicine->inventory);
	insertNodeByTail(medicine,list);
	 medicine->ID=0;
	 medicine->Store_No=0;
	 strcpy(medicine->name,"\0");
	 medicine->margin=0;
	 medicine->inventory=0;
	 medicine->price=0;
	 medicine->next=NULL;
	}//边读取边从尾插入链表 
	fclose(fp);
	return list;//返回头节点指针 
}
 
/******************************************************************
	【添加新药品的逻辑判断函数】 
编写人：樊范 
传入：MED*medicine（工具空结构）MED*headNode（头节点） 
传出：int k（觉得是否在操作函数中显示添加成功） 
函数功能：加新药品的逻辑判断，并对外传出显示判断信号 
*******************************************************************/

int add(MED*medicine,MED*headNode)
{
     int i=1;
     int j = 0;
     int k = 0;
     int l = 0; 
     int m = 0; 
     int n = 0;
     int p = 0;
   //	 int q = 0;
     FILE*fp;
     MED*posNode = headNode;
     MED*posNode2 = headNode->next;
	 fp=fopen("C:\\project\\DATABASE\\drugdata.txt","rt+");
	 while(1)
	 {
	 	if(medicine->Store_No == posNode2->Store_No)
	 	{
	 		cleardevice();
	        setbkcolor(WHITE);
	        setfillstyle(11,YELLOW);
	        bar(0,0,640,480);
            frameline();
            puthz(150, 180, "所添加到的药格已被占用", 32, 32, DARKGRAY);
            puthz(200, 230, "请更换一个药格", 32, 32, DARKGRAY);
	        delay(2000); 
	        j = 1;
	 		break;
		}//判断药格是否占用 
		else if(medicine->Store_No >34)
	 	{
	 		cleardevice();
	        setbkcolor(WHITE);
	        setfillstyle(11,YELLOW);
	        bar(0,0,640,480);
            frameline();
            puthz(150, 180, "所添加到的药格已达上限", 32, 32, DARKGRAY);
            puthz(200, 230, "请更换一个药格", 32, 32, DARKGRAY);
	        delay(2000); 
	        m = 1;
	 		break;
		}//判断药格是否超越上限 
		else if(medicine->Store_No ==0)
	 	{
	 		cleardevice();
	        setbkcolor(WHITE);
	        setfillstyle(11,YELLOW);
	        bar(0,0,640,480);
            frameline();
            puthz(150, 180, "所添加到的药格已不存在", 32, 32, DARKGRAY);
            puthz(200, 230, "请更换一个药格", 32, 32, DARKGRAY);
	        delay(2000); 
	        p = 1;
	 		break;
		}//判断药格是否超越上限 
		else if(!strcmp(medicine->name,posNode2->name))
		{
			cleardevice();
	        setbkcolor(WHITE);
	        setfillstyle(11,YELLOW);
	        bar(0,0,640,480);
            frameline();
            puthz(150, 180, "所添加的药品名已被占用", 32, 32, DARKGRAY);
            puthz(200, 230, "请更换一个名字", 32, 32, DARKGRAY);
	        delay(2000); 
	        l = 1;
	 		break;
		}//判断药品是否重名 
		else if(!(strcmp(medicine->name,'\0')&&medicine->Store_No>0&&medicine->price>0&&medicine->inventory>0))
		{
			cleardevice();
	        setbkcolor(WHITE);
	        setfillstyle(11,YELLOW);
	        bar(0,0,640,480);
            frameline();
            puthz(200, 180, "请填写完整信息", 32, 32, DARKGRAY);
	        delay(2000); 
	        n = 1;
	 		break;
		}//判断药品是否信息完整 
		else if(posNode2->next == NULL)
		{
			break;
		}
//		else
//		{
//			cleardevice();
//	        setbkcolor(WHITE);
//	        setfillstyle(11,YELLOW);
//	        bar(0,0,640,480);
//            frameline();
//            puthz(200, 180, "信息错误", 32, 32, DARKGRAY);
//	        delay(2000); 
//	        q = 1;
//	 		break;
//		}//判断药品是否信息合法 
		posNode2 = posNode2->next;
      }//判断是否能创建新药品 
		if(j == 0&&l == 0&&m == 0&&n == 0&&p ==0)
		{
			k = 1;
			while(posNode!=NULL)
	   {
		if(posNode->ID == i )
		{
			i++;
			posNode = headNode;
		}
		if(posNode->next == NULL)
		{
			break;
		}
	    posNode=posNode->next;
	   }
	 medicine->margin = medicine->inventory;
	 medicine->inventory = 200;
	 medicine->ID = i;
	 insertNodeByTail(medicine,headNode);

     printlist_FILE(headNode);
	}  //可以插入后插入并重新写入文件 
	fclose(fp);
	return k;//返回状态值 
}
