#define _CRT_SECURE_NO_DEPRECATE 1
/*
������־
1���������������Ϸ����
2��ʵ����Ϸ����Ĺ�����
3��������Ϸ�е�ֲ�￨Ƭ
4��ʵ���϶���Ƭ����ֲ��




*/
#include<stdio.h>
#include<graphics.h>    //easy_Xͼ�ο�



#define WIN_WIDTH  900   //���ڿ��
#define WIN_HEIGHT 600   //���ڸ߶�



void Initgame();
void UpdateWindow();
void UserClick();
bool FileExist(const char* name);
