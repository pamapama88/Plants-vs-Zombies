#include"head.h"

int main()
{
	Initmap();          // ��ʼ��һ���ؿ���ͼ����
	load_cards();
	load_plants();

	my_load("PCT/zoom/go_3/");






	while(1)
	{

		click_act();
//		update_windows();
	    Put_image();


	}
	std::cin.get();       //�����õ� getch �Ҳ����ã�����������ðɣ�����˵��������

	//closegraph();          // �رջ�ͼ����
	return 0;
}


