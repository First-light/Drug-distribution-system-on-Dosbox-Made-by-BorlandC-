#include <common.h>
/******************************************************************
	¡¾³ö¿â½çÃæ»æÖÆº¯Êý¡¿ 
±àÐ´ÈË£º·®·¶ 
´«Èë£º int x,int y£¨½çÃæ×óÉÏ½Ç×ø±ê£© 
´«³ö£º void 
º¯Êý¹¦ÄÜ£º»æÖÆ³ö¿â½çÃæ 
*******************************************************************/
void minus_Page(int x,int y)
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
    puthz(x+5, y+5, "Ò©Æ·É¾¼õ½çÃæ", 24, 24, WHITE);
    puthz(x+5, y+50, "Ò©Æ·Ãû³Æ£º", 24, 24, DARKGRAY);
    puthz(x+5, y+100, "É¾¼õÊýÁ¿£º", 24, 24, DARKGRAY);
    setfillstyle(1,LIGHTGRAY);
    bar(x+130,y+150,x+230,y+180);
    puthz(x+135, y+155, "È·ÈÏ³ö¿â", 24, 24, DARKGRAY);
} 

/******************************************************************
	¡¾Ò©Æ·³ö¿â²Ù×÷Ö´ÐÐº¯Êý¡¿ 
±àÐ´ÈË£º·®·¶ 
´«Èë£º MED*list£¨Í·½Úµã£©,MED*medicine£¨¹¤¾ß½á¹¹Ö¸Õë£©,char*data£¨ÊäÈë½øÀ´µÄÊý×Ö£© 
´«³ö£º void 
º¯Êý¹¦ÄÜ£º½øÐÐ³ö¿âÖ´ÐÐ²Ù×÷ 
*******************************************************************/

void minus_Change(MED*list,MED*medicine,char*data)
{
	int x=120;//Ð¡½çÃæµÄ×óÉÏ½Çx×ø±ê 
	int y=80; //Ð¡½çÃæµÄ×óÉÏ½Çy×ø±ê
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
  }//¼ìË÷¸ÃÒ©Æ· 
  if(i == 0)
  {
  	if ((posNode->margin-char_trans_int(data))>0)
	  {
	  	posNode->margin = posNode->margin-char_trans_int(data);
	  }//Ò©Æ·Îª¹éÁã 
	  else
	  {
	  	posNode->margin = 0; 
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
        puthz(x+85, y+120, "ÒÑÇå¿Õ¸ÃÒ©Æ·", 32, 32, DARKGRAY);
        puthz(x+84, y+119, "ÒÑÇå¿Õ¸ÃÒ©Æ·", 32, 32, DARKGRAY);
	  }//Ò©Æ·ÊýÁ¿ÒÑ¹éÁã 
  }//Ò©Æ·³É¹¦Ìí¼ÓºóµÄÏìÓ¦ 
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
    puthz(x+85, y+120, "Î´ÕÒµ½¸ÃÒ©Æ·", 32, 32, DARKGRAY);
    puthz(x+84, y+119, "Î´ÕÒµ½¸ÃÒ©Æ·", 32, 32, DARKGRAY);
  } //Î´ÕÒµ½Ò©Æ·   

} 

/******************************************************************
	¡¾Ò©Æ·³ö¿â²Ù×÷º¯Êý¡¿ 
±àÐ´ÈË£º·®·¶ 
´«Èë£ºMED*medicine£¨¹¤¾ß½á¹¹Ö¸Õë£©
´«³ö£º void 
º¯Êý¹¦ÄÜ£º½øÐÐ³ö¿â²Ù×÷ 
*******************************************************************/

void minus(MED*medicine)
{
	int page = 0;//Ò³ÃæÌø×ª¼ÇÂ
	int i;//³£¹æ²Ù×÷µÄ²ÎÊý
	int x=120;//Ð¡½çÃæµÄ×óÉÏ½Çx×ø±ê 
	int y=80; //Ð¡½çÃæµÄ×óÉÏ½Çy×ø±ê
	int data_name[9]={250,130,220,40,22,8,20,1,2};
	int data_num[9]={250,180,220,40,22,8,3,1,2};
	int m = 1;
	int n = 1;
	char data[4]={'\0'};
	MED*list =reopen(medicine);
	MED* mt = medicine;
	minus_Page(x,y);
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
		}//ÍË³öÒ©¿â 

        else if(mouse_press(x+330,y,x+360,y+30) == 1)
		{
		  delay(200);
		  break; 
		}//ÍË³öÐ¡½çÃæ 
         else if(mouse_press(x+130,y+150,x+230,y+180) == 1)
		{
		 minus_Change(list,medicine,data);
		 delay(2000); 
		 break; 
		}//È·ÈÏÉ¾¼õ 
		CreateButton_INPUT_3  (data_name,&m,medicine->name,"\0",1);
		CreateButton_INPUT_3  (data_num,&n,data,"\0",1);//ÊäÈë¿òÄ£¿é 
	}
	printlist_FILE(list);//ÖØÐ´Ò©Æ·Êý¾ÝÎÄ±¾ 
	mt = list->next;
	while(mt != NULL)
	{
		free(list);
		list = mt;
		mt = mt->next;
	}
	free(list);
} 
