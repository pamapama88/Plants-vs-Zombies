#include"head.h"



int main()
{
	Initmap();          // ��ʼ��һ���ؿ���ͼ����
	load_cards();
	load_plants();

	my_load(easy_zoom_go3,"PCT/zoom/go_3/");    //��һ����ͨ��ʬ�ĵ�������·���Ƽ��ص��ڴ���
	my_load(easy_zoom_wait2,"PCT/zoom/wait_2/");





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


