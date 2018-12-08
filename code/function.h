#pragma once
#pragma warning (disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<string.h>


typedef struct Map
{
	char maps[50][50];
	int level;
	int m;//人物的起始竖坐标
	int n;//人物的起始横坐标
	int aim_m[25];
	int aim_n[25];
	int aim_sum;

}Maps;
Maps map;
Maps* gameMap(int level);

typedef struct
{
	char judgeintf;
	char game_interf[50][50];
}Interfs;
Interfs Interf;
Interfs *interf(int scene);

typedef struct _undo
{
	char r_map[50][50];
}undo;
undo withdraw[1000];
void record(Maps map, int step);
void Undo(int step);

void init();
char event();
void update();
void render();

FILE *openfile(char *, char *);

void initmap();
