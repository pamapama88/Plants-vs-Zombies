#include"head.h"
const int num_cards = 8;
const int num_use_cards = 2;

IMAGE map;            //�տ�ʼ��Ϊ��ʹ�÷��㣬�õ���һ�� IMAGE* ָ�룬���û��ʼ����������һ���磬�����г���һ��
IMAGE Bar;            //��ȷʵ�Ƴ綨������ʼ��һ�𣬵������ָ��������Ĳ�֪��Ҫ������ʼ��һ��ʲô���������Ծ͸����˱�����ʾ
IMAGE cards[num_cards]{};
char save_name[60]{};
//enum cards_name{bin,flower,count };
//IMAGE card_name[1];
IMAGE plant_cards[num_cards][25]{};
ExMessage point;     //ExMessage ��easyXͼ�ο��ﶨ���һ���ṹ�壬��������갴�¡��ƶ����ɿ������ָ�뵱ǰλ�õı���
int curX = point.x;
int curY = point.y;

void Initmap()
{
	initgraph(1080, 828, 1);    //������Ϸ��ͼ�Σ�����

	std::cout << "���ڳ�ʼ����ͼ����...\n" << "���ڼ���ͼƬ...\n";
	loadimage(&map, "PCT/map.png", 1080, 828);           //���ر���ͼƬ
	std::cout << "��ͼ�������سɹ�������\n";
	loadimage(&Bar, "PCT/bar.png",500,80);        
}

void load_cards()
{
	std::ofstream of_save_name;
	std::ifstream if_save_name;
	of_save_name.open("save_name.txt");
	if_save_name.open("save_name.txt");
	for (int i = 0; i < num_use_cards; i++)
	{
		of_save_name << "PCT/card/card_" << i << ".png\n";         //�����ļ������� ��Ƭ���ڵ��ļ���ַ ��������
	}
	of_save_name.close();                                          //����out���ļ��ر��ˣ�in���ļ���û������ʹ��
	for(int i=0;i<num_use_cards;i++)
	{
		//if_save_name >> save_name[0];
		if_save_name.getline(save_name, 60);                        //��������Ϊ����������临�ӣ��Ż��Ŀռ仹�кܴ�
		std::cout << "���ڼ��ؿ�Ƭ�ļ���ַ :\n" << save_name << std::endl;

		loadimage(&cards[i], save_name);
	}
	if_save_name.close();
}


void load_plants()
{
	int num_0 = num_a_cards(0);
	std::ofstream of_save_name;
	of_save_name.open("save_name.txt");
	for (int i = 0; i < num_use_cards; i++)
	{
		for (int j = 0; j < num_0; j++)
		{
			std::ofstream card;
			card.open("plant_name.txt");



		}
		of_save_name << "PCT/plant/" << i<<"/"<<j << ".png\n";
	}
	of_save_name.close();     

	std::ifstream if_save_name;
	if_save_name.open("save_name.txt");
	for (int i = 0; i < num_use_cards; i++)
	{
		if_save_name.getline(save_name, 60);                       
		std::cout << "���ڼ���ֲ��ͼƬ�ļ���ַ :\n" << save_name << std::endl;      //��ͬ�ķ�������������ճ������ڵ���ʱû��װ�Ը�����

		//loadimage(&plant_cards[i], save_name);
	}
	if_save_name.close();


}

int num_a_cards(int num)
{



	return 0;
}

void Put_image()
{

	//��ʼ׼����ͼ
	BeginBatchDraw();		//������ͼ �ݲ����           //��ʼ���壬��������������Ȳ���ʾ����Ļ�ϣ������Ȼ������ڴ���
	putimage(0, 0, &map);
	putimage(280, 0, &Bar);
	for(int i=0;i<num_use_cards;i++)
	{
		std::cout << "���ڼ��ؿ�Ƭ�ļ� :\n" << save_name << std::endl;
		putimage(358 + 50 * i, 8, &cards[i]);
	}


	EndBatchDraw();         //����������ͼģʽ�����м��ͼƬһ���Ի��Ƴ���                //����˫���壬���ڴ��е�����һ���Դ�ӡ����Ļ��ȥ
}



void click_act()
{
	//std::cout << "�ȴ�������Ϣ\n";
	if (peekmessage(&point))                           //�����ȡ����һ��������Ϣ
	{
//		std::cout << "get��Ϣ\n";
		if (point.message == WM_LBUTTONDOWN)     //��������һ�����������µ���Ϣ
		{
			//std::cout << "���" << std::endl;
			if (point.x >= 358 && point.x <= 770 && point.y >= 8 && point.y <= 70)
			{
				int tmp = (point.x - 356) / 47;
				//std::cout << tmp;
				out_plant(tmp);
			}
		}


	}



}



void out_plant(int num)
{




}



void update_windows()
{



}