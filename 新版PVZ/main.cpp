#include"head.h"

int main()
{
	Initmap();          // ��ʼ��һ���ؿ���ͼ����
	load_cards();
	load_plants();
	Put_image();

	while(1)
	{

		click_act();
		//update_windows();


	}
	std::cin.get();       //�����õ� getch �Ҳ����ã�����������ðɣ�����˵��������

	//closegraph();          // �رջ�ͼ����
	return 0;
}


