#define _CRT_SECURE_NO_DEPRECATE 1
#include"head.h"

int main()
{
	Initmap();          // ��ʼ��һ���ؿ���ͼ����
	load_cards();
	Put_image();

	std::cin.get();       //�����õ� getch �Ҳ����ã�����������ðɣ�����˵��������

	//closegraph();          // �رջ�ͼ����
	return 0;
}


