#include"function.h"

int step = 0;
int scene = 2;//Ϊ2�Ͳ���ӡ��ֹ�û�������������ʱ��Ҳ��ӡ��ͼ
int is_scene = 0;//��is_scene=1���ӡinterface,����render�ж�
int level = 1;
int x, y;

Maps* temp = &map;

void init()
{
	//�öδ��빦�������ع�꣬������win32��̽ӿڣ�����Ҫ����
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//��ȡ���ھ��
	CONSOLE_CURSOR_INFO cci;//ʵ�л�һ������̨�����Ϣ��
	GetConsoleCursorInfo(hOut, &cci);//��ȡ�����Ϣ
	cci.bVisible = FALSE;//���ع��
	SetConsoleCursorInfo(hOut, &cci);//���ù����Ϣ
	SetConsoleTitle("�����Ե������������");
	//system("������");//�趨��������
	system("mode con cols=120 lines=30");//�趨���ڴ�С
}

void initmap()
{
	//level = 1;
	temp = gameMap(level);
	temp->level = level;
	x = temp->n;//nΪ��
	y = temp->m;
	step = 0;
}

Maps* gameMap(int level)
{
	Maps* temp = &map;
	char gmap[256];
	FILE *fp;
	sprintf(gmap, "..\\dhd\\Map\\%d.txt", level);
	fp = openfile(gmap, "r");

	temp->aim_sum = 0;
	for (int i = 0;; i++)
	{
		fgets(temp->maps[i], 256, fp);
		temp->maps[i][strlen(temp->maps[i]) - 1] = '\0';
		for (int j = 0; temp->maps[i][j] != '\0'; j++)
		{
			switch (temp->maps[i][j])
			{
			case 'X':
			case 'Q':						   //mΪ�� nΪ��
				temp->aim_m[temp->aim_sum] = i;
				temp->aim_n[temp->aim_sum] = j;
				temp->aim_sum++;
				break;
			case '@':
				temp->m = i;
				temp->n = j;
				break;
			}
		}
		if (temp->maps[i][1] == '|')
		{
			temp->maps[i][1] = '=';
			break;
		}
	}
	fclose(fp);
	return temp;
}
FILE* openfile(char *route, char *mode)
{
	FILE *temp = fopen(route, mode);
	if (temp == NULL)
	{
		printf("wrong");
		getchar();
		exit(1);
	}

	return temp;
}
Interfs *interf(int scene)
{
	// scene=1 �����ӽ���
	//scene=2 ��ʼ����
	//scene=3 ѡ�ؽ���
	//scene=4 ���ؽ���
	//scene=5 ͨ�ؽ���
	//scene=6 �ڹؿ������˳�
	Interfs *temp = &Interf;
	char game_f[256];
	sprintf(game_f, "..\\dhd\\Interface\\%d.txt", scene);
	FILE *fi;
	fi = openfile(game_f, "r");
	int line;
	fscanf(fi, "%2d", &line);
	for (int i = 0; i < line; i++)
	{
		fgets(temp->game_interf[i], 50, fi);
		temp->game_interf[i][strlen(temp->game_interf[i]) - 1] = '\0';
	}
	fclose(fi);
	if (scene == 1)
	{
		char jump[8] = "\n\n\n\n\n\n\n";
		puts(jump);
		char tab[7] = "\t\t\t\t\t\t";


		for (int i = 0; i < 15; i++)
		{
			printf("%s", tab);
			puts(temp->game_interf[i]);
		}
		Sleep(1500);
		getchar();
		system("cls");
		temp = NULL;
		return temp;
	}
	else if (scene == 2)
	{
		char jump[8] = "\n\n\n\n\n\n\n";
		puts(jump);
		char tab[7] = "\t\t\t\t\t\t";
		for (int i = 0; i < 15; i++)
		{
			printf("%s", tab);
			puts(temp->game_interf[i]);
		}
		temp = NULL;
		return temp;
	}
	return temp;
}

char event()
{

	char option = getch();
	getch();
	option = tolower(option);
	switch (option)
	{
	case 'w':
		return 'w';
	case 's':
		return 's';
	case 'a':
		return 'a';
	case 'd':
		return 'd';
	case 'c':
		return 'c';
	case 'p':
		return 'p';
	case 'r':
		return 'r';
	case 'n':
		return 'n';
	case 'b':
		return 'b';
	case 'm':
		return 'm';
	case 'u':
		return 'u';
	case 13:
		return 'q';
	case 27:
		return 'e';
	}
}
void update()
{
	char option = event();
	system("cls");
	switch (option)
	{
	case 'w':record(map, step);
		switch (temp->maps[y - 1][x])
		{
		case ' ':
		case 'X':
			temp->maps[y][x] = ' ';
			temp->maps[y - 1][x] = '@';
			y--;
			step++;
			break;
		case 'O':
		case 'Q':
			switch (temp->maps[y - 2][x])
			{
			case ' ':
				temp->maps[y][x] = ' ';
				temp->maps[y - 1][x] = '@';
				temp->maps[y - 2][x] = 'O';
				y--;
				step++;
				break;
			case 'X':
				temp->maps[y][x] = ' ';
				temp->maps[y - 1][x] = '@';
				temp->maps[y - 2][x] = 'Q';
				y--;
				step++;
				break;
			default:
				break;
			}
		}break;
	case 's':record(map, step);
		switch (temp->maps[y + 1][x])
		{
		case ' ':
		case 'X':
			temp->maps[y][x] = ' ';
			temp->maps[y + 1][x] = '@';
			y++;
			step++;
			break;
		case 'O':
		case 'Q':
			switch (temp->maps[y + 2][x])
			{
			case ' ':
				temp->maps[y][x] = ' ';
				temp->maps[y + 1][x] = '@';
				temp->maps[y + 2][x] = 'O';
				y++;
				step++;
				break;
			case 'X':
				temp->maps[y][x] = ' ';
				temp->maps[y + 1][x] = '@';
				temp->maps[y + 2][x] = 'Q';
				y++;
				step++;
				break;
			default:
				break;
			}
		}break;
	case 'a':record(map, step);
		switch (temp->maps[y][x - 1])
		{
		case ' ':
			temp->maps[y][x] = ' ';
			temp->maps[y][x - 1] = '@';
			x--;
			step++;
			break;
		case 'X':
			temp->maps[y][x] = ' ';
			temp->maps[y][x - 1] = '@';
			x--;
			step++;
			break;
		case 'O':
		case 'Q':
			switch (temp->maps[y][x - 2])
			{
			case ' ':
				temp->maps[y][x] = ' ';
				temp->maps[y][x - 1] = '@';
				temp->maps[y][x - 2] = 'O';
				x--;
				step++;
				break;
			case 'X':
				temp->maps[y][x] = ' ';
				temp->maps[y][x - 1] = '@';
				temp->maps[y][x - 2] = 'Q';
				x--;
				step++;
				break;
			default:
				break;
			}
		}break;
	case 'd':record(map, step);
		switch (temp->maps[y][x + 1])
		{
		case ' ':
			temp->maps[y][x] = ' ';
			temp->maps[y][x + 1] = '@';
			x++;
			step++;
			break;
		case 'X':
			temp->maps[y][x] = ' ';
			temp->maps[y][x + 1] = '@';
			x++;
			step++;
			break;
		case 'O':
		case 'Q':
			switch (temp->maps[y][x + 2])
			{
			case ' ':
				temp->maps[y][x] = ' ';
				temp->maps[y][x + 1] = '@';
				temp->maps[y][x + 2] = 'O';
				x++;
				step++;
				break;
			case 'X':
				temp->maps[y][x] = ' ';
				temp->maps[y][x + 1] = '@';
				temp->maps[y][x + 2] = 'Q';
				x++;
				step++;
				break;
			default:
				break;
			}
		}break;
	case 'c':
		scene = 3;
		is_scene = 1;
		break;
	case 'p':
	case 'r':
		level = 1;
		initmap();
		scene = 8;  
		
		break;
	case 'n':
		if (scene == 4 || scene == 6)
		{
			++level;
			initmap();
			is_scene = 0;
		}
		else;
		break;
	case 'b':
		initmap();
		is_scene = 0;
		break;
	case 'm':
		if (scene == 5)
		{
			scene = 2;
			is_scene = 1;
		}
		break;
	case 'e':
		if (is_scene == -1 || scene == 6)//˵����ʱ�Ѿ���ӡ��scene=6�˻����ڳ�ʼ�����˳�
		{
			exit(1);
		}
		else
		{
			scene = 6;
			is_scene = 1;
		}
		break;
	case 'q':break;
	case 'u':
		if (step > 0)
		{
			step--;
			Undo(step);
		}
		break;
		break;
	default:
		scene = 2;
		is_scene = 1;
		break;
	}

	//�жϹ���
	if (is_scene != 1)
	{
		int fcount = 0;
		for (int i = 0; i < 15; i++)
		{
			for (int j = 0; j < strlen(temp->maps[i]); j++)
			{
				if (temp->maps[i][j] == 'Q')
				{
					fcount++;
				}
			}
		}

		if (fcount == temp->aim_sum)
		{
			if (level != 35)
			{

				scene = 4;
				is_scene = 1;
			}
			else
			{
				scene = 5;
				is_scene = 1;
			}
		}
	}

	//��ԭX
	int x_m, x_n;
	for (int i = 0; i < temp->aim_sum; i++)
	{
		x_m = temp->aim_m[i];
		x_n = temp->aim_n[i];
		if (temp->maps[x_m][x_n] != '@' && temp->maps[x_m][x_n] != 'Q')
			temp->maps[x_m][x_n] = 'X';
	}
}
void render()
{


	Interfs *it = &Interf;
	Maps *mp = &map;

	if (level != temp->level)
	{
		initmap();
	}

	if (is_scene)
	{
		if (scene == 3)
		{
			char jump[8] = "\n\n\n\n\n\n\n";
			puts(jump);
			char tab[7] = "\t\t\t\t\t\t";
			interf(scene);
			for (int i = 0; i < 15; i++)
			{
				printf("%s", tab);
				puts(it->game_interf[i]);
			}
			printf("\t\t\t\t\t\t�밴���λس���ȷ��ѡ��\n");
			printf("\t\t\t\t\t\t    ѡ��: ");
			scanf("%d", &level);
			fflush(stdin);
			while (level < 0 || level>35)
			{
				printf("\t\t\t\t\t\t����ؿ�����\n");
				printf("\t\t\t\t\t\t�밴���λس���ȷ��ѡ��\n");
				printf("\t\t\t\t\t\t����������:");
				scanf("%d", &level);
				fflush(stdin);
				if (level > 0 && level < 36)
					break;
			}
			initmap();
		}
		else if (scene == 2)
		{
			interf(scene);
		}
		else if (scene == 6)
		{

			char jump[8] = "\n\n\n\n\n\n\n";
			puts(jump);
			char tab[7] = "\t\t\t\t\t\t";
			interf(scene);
			for (int i = 0; i < 15; i++)
			{
				printf("%s", tab);
				puts(it->game_interf[i]);
			}
		}
		else
		{
			char jump[8] = "\n\n\n\n\n\n\n";
			puts(jump);
			char tab[7] = "\t\t\t\t\t\t";
			interf(scene);
			for (int i = 0; i < 15; i++)
			{
				printf("%s", tab);
				puts(it->game_interf[i]);
			}
		}
		is_scene = 0;
		if (scene == 6)
		{
			is_scene = -1;
			
		}
		else if (scene == 3)
			scene = 0;		
	}

	else
	{
		char jump[8] = "\n\n\n\n\n\n\n";
		puts(jump);
		char tab[7] = "\t\t\t\t\t\t";
		if (level == 35)
		{
			for (int i = 0; i < 11; i++)
			{
				printf("%s", tab);
				puts(mp->maps[i]);
			}
		}	
		else
		{
			for (int i = 0; i < 15; i++)
			{
				printf("%s", tab);
				puts(mp->maps[i]);
			}
		}	
		printf("\t\t\t\t\t\t   ��%d��\n", level);
		printf("\t\t\t\t\t  W:�� S:�� A:�� D:�� ����:U\n");
		printf("\t\t\t\t\t\t��������%d��\n", step);
	}

}

void record(Maps map, int step)
{
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < strlen(temp->maps[i]); j++)
		{
			withdraw[step].r_map[i][j] = temp->maps[i][j];
		}
	}
}
void Undo(int step)
{
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			temp->maps[i][j] = withdraw[step].r_map[i][j];
		}
	}
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			if (temp->maps[i][j] == '@')
			{
				x = j;
				y = i;
			}
		}
	}

}
