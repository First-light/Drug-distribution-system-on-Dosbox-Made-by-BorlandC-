#include "common.h"
#define BLOCK_X 50
#define BLOCK_Y 40

void normal_block(int x, int y)
{
	setfillstyle(3, LIGHTGRAY);
	bar(x, y, x + BLOCK_X, y + BLOCK_Y);
}

void medicine_block(int x, int y, MED *m, int i, int j)
{
	MED *p = m;
	setfillstyle(1, DARKGRAY);
	bar(x, y, x + BLOCK_X, y + BLOCK_Y);
	setfillstyle(1, WHITE);
	bar(x + 1, y + 1, x + BLOCK_X - 1, y + BLOCK_Y - 1);
	setfillstyle(1, DARKGRAY);
	bar(x + 3, y + BLOCK_Y - 13, x + BLOCK_X - 3, y + BLOCK_Y - 13 + 2);
	setfillstyle(11, DARKGRAY);
	bar(x + 3, y + 3, x + BLOCK_X - 3, y + BLOCK_Y - 13);

	while (p != NULL)
	{
		if (p->x == i && p->y == j)
		{
			char output[5] = {0};
			CHAR_INT_Change(output, p->ID);
			settextstyle(2, 0, 4);
			setcolor(BLUE);
			outtextxy(x + 3, y + BLOCK_Y - 13 + 2, output);
			strcpy(output, "\0");
			CHAR_INT_Change(output, p->margin);
			outtextxy(x + BLOCK_X - 20, y + BLOCK_Y - 13 + 2, output);
			if (1)
			{
				if (p->ID % 5 == 0)
				{
					setfillstyle(1, CYAN);
				}
				else if (p->ID % 5 == 1)
				{
					setfillstyle(1, BLUE);
				}
				else if (p->ID % 5 == 2)
				{
					setfillstyle(1, LIGHTBLUE);
				}
				else if (p->ID % 5 == 3)
				{
					setfillstyle(1, GREEN);
				}
				else
				{
					setfillstyle(1, BROWN);
				}
				bar(x + 6, y + BLOCK_Y - 13 - 15, x + 6 + 10, y + BLOCK_Y - 13);
				bar(x + 16 + 3, y + BLOCK_Y - 13 - 11, x + 16 + 3 + 8, y + BLOCK_Y - 13);
				bar(x + 27 + 6, y + BLOCK_Y - 13 - 20, x + 30 + 15, y + BLOCK_Y - 13);
			}
			if (p->margin < 20)
			{
				if (p->margin == 0)
				{
					setfillstyle(1, YELLOW);
					bar(x + 3, y + 10, x + BLOCK_X - 3, y + BLOCK_Y - 13 - 2);
					puthz(x + 3 + 1 + 5, y + 3 + 5 + 1, "缺药", 16, 16, RED);
					puthz(x + 3 + 5, y + 3 + 5, "缺药", 16, 16, RED);
				}
				else
				{
					setfillstyle(1, YELLOW);
					bar(x + 3, y + 10, x + BLOCK_X - 3, y + BLOCK_Y - 13 - 2);
					puthz(x + 3 + 1 + 5, y + 3 + 5, "少药", 16, 16, BLUE);
					puthz(x + 3 + 5, y + 3 + 5, "少药", 16, 16, BLUE);
				}
			}
			break;
		}
		p = p->next;
	}
}

void Store_draw(int *data, MED *m)
{
	int x;
	int y;
	int i;
	int j;
	for (j = 0; j < 8; j++)
	{
		for (i = 0; i < 7; i++)
		{
			if (j == 3 || j == 4 || (i == 6) && i != 5)
			{
				x = data[0] + i * BLOCK_X;
				y = data[1] + j * BLOCK_Y;
				normal_block(x, y);
			}
			if ((j == 3 || j == 4) && i == 5)
			{
				setfillstyle(1, BLUE);
				bar(x, y, x + BLOCK_X, y + BLOCK_Y);
				setfillstyle(1, WHITE);
				bar(x + 2, y + 2, x + BLOCK_X - 2, y + BLOCK_Y - 2);
				puthz(x + 3, y + 12, "出药口", 16, 16, BLUE);
			}
		}
	}
	for (j = 0; j < 8; j++)
	{
		if (j == 3 || j == 4)
		{
			continue;
		}
		for (i = 0; i < 6; i++)
		{
			x = data[0] + i * BLOCK_X;
			y = data[1] + j * BLOCK_Y;
			medicine_block(x, y, m, i, j);
		}
	}
}

void Robotstate_Show(int x, int y, struct robot *ro, char *text, int *flash)
{
	int length_x = 220;
	int length_y = 120;
	int text2[6] = {0};
	int color = 0;
	char output[5] = {0};
	settextstyle(2,0,6);
	if(*flash == 1){
		setfillstyle(1,DARKGRAY);
		bar(x,y,x+length_x,y+length_y);
		setfillstyle(1,WHITE);
		bar(x+2,y+2,x+length_x-2,y+2+30);
		puthz(x+2+20,y+2+4,text,24,24,CYAN);
		*flash = 0;
	}
	setfillstyle(1, DARKGRAY);
	bar(x, y + 33, x + length_x, y + length_y);
	puthz(x + 2 + 15, y + 35, "状态：", 16, 16, WHITE);
	switch (ro->state)
	{
	case 0:
		strcpy(text2, "空闲中");
		color = LIGHTGREEN;
		break;
	case 1:
		strcpy(text2, "前往药架");
		color = YELLOW;
		break;
	case 2:
		strcpy(text2, "取药中");
		color = LIGHTCYAN;
		break;
	case 3:
		strcpy(text2, "前往出药口");
		color = YELLOW;
		break;
	default:
		strcpy(text2, "未知");
		color = LIGHTGRAY;
		break;
	}
	puthz(x + 2 + 55 + 15, y + 35, text2, 16, 16, color);
	setcolor(YELLOW);
	puthz(x + 2 + 15, y + 55, "配药单号：", 16, 16, WHITE);
	CHAR_INT_Change2(output, ro->pat, 4);
	outtextxy(x + 2 + 5 * 16 + 5 + 20, y + 55, output);
	puthz(x + 2 + 15, y + 75, "药品编号：", 16, 16, WHITE);
	CHAR_INT_Change2(output, ro->medi, 4);
	outtextxy(x + 2 + 5 * 16 + 5 + 20, y + 75, output);
	puthz(x + 2 + 15, y + 95, "取药数量：", 16, 16, WHITE);
	CHAR_INT_Change2(output, ro->count, 4);
	outtextxy(x + 2 + 5 * 16 + 5 + 20, y + 95, output);
}

void Robot_draw(int *data, struct robot *ro)
{
	int x;
	int y;
	char a[5] = {0};
	x = data[0] + (ro)->x * BLOCK_X;
	y = data[1];
	setfillstyle(1, DARKGRAY);
	if (ro->ystart == 3)
	{
		bar(x + BLOCK_X + BLOCK_X / 2 - 5 - 10, y + 5, x + BLOCK_X + BLOCK_X / 2 + 5 - 10, y + BLOCK_Y * 4 - 2);
	}
	else
	{
		bar(x + BLOCK_X + BLOCK_X / 2 - 5 - 10, y + BLOCK_Y * 4 + 2, x + BLOCK_X + BLOCK_X / 2 + 5 - 10, y + BLOCK_Y * 8 - 5);
	}
	x = data[0] + (ro)->x * BLOCK_X;
	y = data[1] + (ro)->y * BLOCK_Y;
	y -= 5;
	setfillstyle(1, LIGHTGRAY);
	bar(x + BLOCK_X + 6, y + 5, x + BLOCK_X * 2 - 10 + 3, y + BLOCK_Y - 5);
	bar(x + 5, y + 23, x + BLOCK_X * 2 - 10 + 3, y + BLOCK_Y - 5);
	setfillstyle(1, DARKGRAY);
	bar(x + 5, y + BLOCK_Y - 5 - 7, x + BLOCK_X * 2 - 10 + 3, y + BLOCK_Y - 5);
	setfillstyle(1, DARKGRAY);
	bar(x + BLOCK_X + 5 + 10, y + 8, x + BLOCK_X * 2 - 10, y + BLOCK_Y - 8);
	setfillstyle(1, LIGHTBLUE);
	bar(x + BLOCK_X + 5 + 2 + 10, y + 8 + 2, x + BLOCK_X * 2 - 10 - 2, y + BLOCK_Y - 8 - 2);
	settextstyle(2, 0, 3);
	setcolor(YELLOW);
	CHAR_INT_Change(a, (ro)->state);
	outtextxy(x + BLOCK_X + 5 + 5 + 10, y + 10, a); // 输入只能是字符串
	CHAR_INT_Change(a, (ro)->medi);
	outtextxy(x + BLOCK_X + 5 + 5 + 20, y + 10, a); // 输入只能是字符串
	CHAR_INT_Change(a, (ro)->count);
	outtextxy(x + BLOCK_X + 5 + 5 + 10, y + 18, a); // 输入只能是字符串
	CHAR_INT_Change(a, (ro)->pat);
	outtextxy(x + BLOCK_X + 5 + 5 + 20, y + 18, a); // 输入只能是字符串
	setfillstyle(1, DARKGRAY);
	bar(x + BLOCK_X + 6 - 8, y + 25 + 1 - 3, x + BLOCK_X + 6, y + 25 + 9 - 3);
	if (ro->state == 0)
	{
		setfillstyle(1, LIGHTGREEN);
	}
	else if (ro->state % 5 == 1)
	{
		setfillstyle(1, YELLOW);
	}
	else if (ro->state % 5 == 2)
	{
		setfillstyle(4, DARKGRAY);
		bar(x + 5, y + 14, x + BLOCK_X + 6, y + 23);
	}
	else if (ro->state % 5 == 3)
	{
	}
	setfillstyle(1, YELLOW);
	bar(x + BLOCK_X + 6 - 8 + 2, y + 25 + 1 + 2 - 3, x + BLOCK_X + 6 - 2, y + 25 + 9 - 2 - 3);
	x = data[0] + (ro)->x2 * BLOCK_X;
	y = data[1] + (ro)->y2 * BLOCK_Y;
	setlinestyle(0, 0, 3);
	setcolor(LIGHTGREEN);
	line(x + BLOCK_X / 2, y + 10, x + BLOCK_X / 2, y + BLOCK_Y - 10);
	line(x + 15, y + BLOCK_Y / 2, x + BLOCK_X - 15, y + BLOCK_Y / 2);
}

void Robot_Setup(struct robot *r, int n)
{
	char in0;
	int in = 0;
	FILE *pf = fopen("C:\\project\\DATABASE\\ROT_DAT.txt", "r");
	if (pf == NULL)
	{ // 如果找不到文件，输出错误报告
		printf("can not find the data file!!!\n");
	}
	else
	{
		while (in0 != -1)
		{
			in0 = fgetc(pf);
			if (in0 == '#')
			{
				fscanf(pf, " %d", &in);
				if (in == n)
				{
					fscanf(pf, " %d %d %d %d %d %d %d %d $",
						   &((r)->x),
						   &((r)->y),
						   &((r)->x2),
						   &((r)->y2),
						   &((r)->state),
						   &((r)->medi),
						   &((r)->count),
						   &((r)->pat));
					if (n == 0)
					{
						(r)->ystart = 3;
					}
					if (n == 1)
					{
						(r)->ystart = 4;
					}
					break;
				}
				else
				{
					continue;
				}
			}
		}
	}
	fclose(pf);
}

void Robot_Output(struct robot *r, int n)
{
	int num = n;
	FILE *PF = fopen("C:\\project\\DATABASE\\ROT_DAT.txt", "w+");
	int i = 0;
	while (i < num)
	{
		fprintf(PF, "# %d %d %d %d %d %d %d %d %d $ %d\n", i,
				(r[i].x),
				(r[i].y),
				(r[i].x2),
				(r[i].y2),
				(r[i].state),
				(r[i].medi),
				(r[i].count),
				(r[i].pat),
				(r[i].ystart));
		i++;
	}
	fprintf(PF, "\n\n\n\n\n");
	fclose(PF);
	//		printf("Input Finished\n");
}
MED *Robot_workdelieve(struct robot *ro, PatientData *p, int *n, MED *me)
{
	MED *back = NULL;
	int pass = 1;
	PatientData *m = p;

	while (m != NULL && pass)
	{
		if ((m)->nummed != 0 /*have num*/ && (m)->payreg < 4 /*对于药物全部分配*/ && (m)->payreg > 1)
		{
			int j = 0;
			for (; j < 6; j++)
			{
				MED *me2 = me;
				int kind = (m)->medicine_list[j][0];
				while (me2 != NULL)
				{
					if ((me2)->ID == kind)
					{
						break;
					}
					me2 = me2->next;
				}
				if (me2 == NULL)
				{
					continue; // 查无此药
				}
				else
				{
					if ((ro)->ystart == 3)
					{
						if ((me2)->y < 3)
						{
						}
						else
						{
							continue;
						}
					}
					if ((ro)->ystart == 4)
					{
						if ((me2)->y > 4)
						{
						}
						else
						{
							continue;
						}
					}
					if ((me2)->margin < (m)->medicine_list[j][1] || (m)->medicine_list[j][2] != 1)
					{
						continue;
					}
					else
					{
						(m)->payreg = 3;
						back = me2;
						*n = (m)->medicine_list[j][1];
						(m)->medicine_list[j][2] = 0;
						(ro)->pat = (m)->numreg;
						pass = 0;
						break;
					}
				}
			}
		}
		m = m->next;
	}
	return back;
}

int Robot_ifwork(PatientData *p)
{
	int back = 0;
	PatientData *m = p;
	int i = 0;
	while (m != NULL)
	{
		if ((m)->payreg < 4 && (m)->nummed != 0 && (m)->payreg > 1)
		{
			back = 1;
			break;
		}
		m = m->next;
		i++;
	}
	return back;
}

int Robot_move(struct robot *ro, int xn, int yn)
{
	int back = 0;
	(ro)->x2 = xn;
	(ro)->y2 = yn;
	if ((ro)->x != (ro)->x2)
	{
		if ((ro)->y == (ro)->ystart)
		{
			(ro)->x = (ro)->x + ((ro)->x2 - (ro)->x) / abs(((ro)->x2 - (ro)->x));
		}
		else
		{
			(ro)->y = (ro)->y + ((ro)->ystart - (ro)->y) / abs(((ro)->ystart - (ro)->y));
		}
	}
	else
	{
		if ((ro)->y == (ro)->y2)
		{
			back = 1;
		}
		else
		{
			(ro)->y = (ro)->y + ((ro)->y2 - (ro)->y) / abs(((ro)->y2 - (ro)->y));
		}
	}
	return back;
}

void Robot_analyse(MED *m, int *output, PatientData *p, struct robot *ro1, struct robot *ro2)
{
	if ((ro1)->state == 0)
	{
		if (Robot_ifwork(p))
		{
			Robot_Working(ro1, p, m);
		}
		else
		{
			Robot_move(ro1, 0, (ro1)->ystart);
			(ro1)->state = 0;
		}
	}
	else
	{
		Robot_Working(ro1, p, m);
	}

	if ((ro2)->state == 0)
	{
		if (Robot_ifwork(p))
		{
			Robot_Working(ro2, p, m);
		}
		else
		{
			Robot_move(ro2, 0, (ro2)->ystart);
			(ro2)->state = 0;
		}
	}
	else
	{
		Robot_Working(ro2, p, m);
	}
}

void Robot_Working(struct robot *ro1, PatientData *p, MED *m)
{
	if ((ro1)->state == 0)
	{
		MED *out;
		int n = 0;
		out = Robot_workdelieve(ro1, p, &n, m);
		if (out == NULL)
		{
			Robot_move(ro1, 0, (ro1)->ystart);
			(ro1)->state = 0;
		}
		else
		{
			(ro1)->x2 = (out)->x;
			(ro1)->y2 = (out)->y;
			(ro1)->count = n;
			(ro1)->medi = (out)->ID;
			(ro1)->state = 1;
		}
	}
	else if ((ro1)->state == 1)
	{
		int j = 0;
		j = Robot_move(ro1, (ro1)->x2, (ro1)->y2);
		if (j)
		{
			(ro1)->state = 2;
		}
	}
	else if ((ro1)->state == 2)
	{
		MED *in = m;
		while (in != NULL)
		{
			if ((in)->ID == (ro1)->medi)
			{
				(in)->margin -= 1;
				(ro1)->count -= 1;
				if ((ro1)->count == 0)
				{
					(ro1)->state = 3;
				}
				break;
			}
			in = (in)->next;
		}
	}
	else if (((ro1)->state) == 3)
	{
		int j = 0;
		j = Robot_move(ro1, 5, (ro1)->ystart);
		if (j)
		{
			PatientData *p2 = p;
			int c = 0;
			while (p2 != NULL)
			{
				if (p2->numreg == (ro1)->pat)
				{
					int num = 0;
					int num2 = 0;
					int num3 = 0;
					for (num = 0; num < 6; num++)
					{
						if ((p2)->medicine_list[num][0] == (ro1)->medi)
						{
							(p2)->medicine_list[num][2] = 2;
						}
						if ((p2)->medicine_list[num][0] != 0)
						{
							num2++;
						}
						if ((p2)->medicine_list[num][2] == 2)
						{
							num3++;
						}
					}
					if (num2 == num3)
					{
						p2->payreg = 4;
					}
					(ro1)->count = 0;
					(ro1)->medi = 0;
					(ro1)->state = 0;
					(ro1)->pat = 0;
					if (p2->payreg == 5)
					{
						//								p2->nummed = 0;
					}
					break;
				}
				p2 = p2->next;
			}
		}
	}
	else
	{
	}
}
