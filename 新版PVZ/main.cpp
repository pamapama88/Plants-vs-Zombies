#include"head.h"

                    


int main()
{
	//���ú����������
	srand((unsigned int)time(NULL));


	Initmap();          // ��ʼ��һ���ؿ���ͼ����
	load_cards();
	load_plants();

	my_load(easy_zoom_go3,"PCT/zoom/go_3/");    //��һ����ͨ��ʬ�ĵ�������·���Ƽ��ص��ڴ���
	my_load(easy_zoom_wait2,"PCT/zoom/wait_2/");   //��һ����ͨ��ʬ�ĵڶ��ֵȴ����Ƽ��ؽ���
	my_load(p_sunshine, "PCT/sunshine/");         //��������ͼƬ
	my_load(sun, "PCT/sun/");         //���ش����������ͼƬ




	while(1)
	{
		random_sun();

		click_act();
//		update_windows();
	    Put_image();


	}
	std::cin.get();       //�����õ� getch �Ҳ����ã�����������ðɣ�����˵��������

	//closegraph();          // �رջ�ͼ����
	return 0;
}


