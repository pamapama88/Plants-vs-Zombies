#define _CRT_SECURE_NO_DEPRECATE 1

#include"tansfer.h"

	//����һ��ͼ�α���
	IMAGE ImgBg;
	//����һ��������
	IMAGE ImgBar;
	//����ö�� �г�ֲ���ȷ��ֲ�����
	enum { Bin, Sunflower, count };
	//����ֲ�￨Ƭ
	IMAGE ImgCards[count];
	//����ֲ�￨Ƭ���ƴ���λ��
	char name[64];
	//��ǰѡ�е�ֲ�����ƶ������е�����
	int curX, curY;
	//����ֲ���ͼ��
	IMAGE* ImgPlants[count][20];    //��Ϊÿ��ֲ���ͼƬ��������һ����������ָ���ʾ
	//��ǰѡ�е�ֲ��
	int curPlant = 0;         //0��ʾû��ѡ�У�1��ʾѡ���˵�һ��ֲ��,2��ʾѡ���˵ڶ���ֲ��.....




int main()
{


	//��ʼ����Ϸ����
	Initgame();

	while (1)
	{


		UserClick();
		UpdateWindow();
	}
	//������Ϸ��Ӧ�ö���һ����ѭ��ֱ���˳�
	//��Ϊѭ������updatewindowһֱ�ڹ���������Ϊ����һ��һ���Ĵ�ӡͼƬ�����Իᵼ�´�����˸����ʱ���Ҫ��updatewindow�������һ��˫����



	system("pause");

	return 0;
}