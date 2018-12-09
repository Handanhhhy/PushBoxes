# PushBoxes
>>``粗制滥造的没有灵性的推箱子``
>>>需要一个有灵性的人来玩
>>>>现在开始<br>
>>>>首先检验你是否有灵性
![](https://github.com/MiracleVin/PushBoxes/blob/master/pictures/1.png)
>>>>当然你肯定是有灵性的
>>>>于是你按下了回车
![](https://github.com/MiracleVin/PushBoxes/blob/master/pictures/9.png)
>>>>有灵性的人不安套路出牌，于是咱们选关
![](https://github.com/MiracleVin/PushBoxes/blob/master/pictures/2.png)
>>>>>继续不按套路出牌
![](https://github.com/MiracleVin/PushBoxes/blob/master/pictures/3.png)
>>>>>这次是真的手滑
![](https://github.com/MiracleVin/PushBoxes/blob/master/pictures/4.png)
>>>>>终于对了,来个倒数第二关试一下
![](https://github.com/MiracleVin/PushBoxes/blob/master/pictures/5.png)
>>>>手滑走错了，不用担心，咱们想撤回就撤回
>>>>>于是有灵性的人过关啦
![](https://github.com/MiracleVin/PushBoxes/blob/master/pictures/10.png)
>>>>>continue the next level
![](https://github.com/MiracleVin/PushBoxes/blob/master/pictures/7.png)
>>>>>太优秀，通关了
![](https://github.com/MiracleVin/PushBoxes/blob/master/pictures/8.jpg)
>>>>>咱们重玩游戏
![](https://github.com/MiracleVin/PushBoxes/blob/master/pictures/9.png)
>>That is all.<br>
```c
撤销的功能实现
typedef struct _undo
{
	char r_map[50][50];
}undo;
undo withdraw[1000];
void record(Maps map, int step);
void Undo(int step);
```
```c
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

```
>>界面的打印<br>
>>实现从文件读取数字来限制行数
```c
typedef struct
{
	char judgeintf;
	char game_interf[50][50];
}Interfs;
Interfs Interf;
Interfs *interf(int scene);
```
```c
Interfs *interf(int scene)
{
	// scene=1 推箱子界面
	//scene=2 开始界面
	//scene=3 选关界面
	//scene=4 过关界面
	//scene=5 通关界面
	//scene=6 在关卡界面退出
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
```
