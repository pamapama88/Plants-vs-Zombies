#include"head.h"
const int num_cards = 8;
const int num_use_cards = 2;
const int MAX_plant_image = 17;

IMAGE map;            //�տ�ʼ��Ϊ��ʹ�÷��㣬�õ���һ�� IMAGE* ָ�룬���û��ʼ����������һ���磬�����г���һ��
IMAGE Bar;            //��ȷʵ�Ƴ綨������ʼ��һ�𣬵������ָ��������Ĳ�֪��Ҫ������ʼ��һ��ʲô���������Ծ͸����˱�����ʾ
IMAGE cards[num_cards]{};
char save_name[60]{};
IMAGE plant_cards[num_cards][25]{};
ExMessage point;     //ExMessage ��easyXͼ�ο��ﶨ���һ���ṹ�壬��������갴�¡��ƶ����ɿ������ָ�뵱ǰλ�õı���
int curX = point.x;
int curY = point.y;
int curPlant = -1;

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

	for (int i = 0; i < num_use_cards; i++)
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
	//int num_0 = num_a_cards(n);                      //����һ��ֲ��Ķ�̬��Ƭ���м���

	std::ofstream plant_o;                                      //��ʼ��һ��ֲ�￨Ƭ���ļ���ַд��һ��txt�ļ�
	plant_o.open("plant_name.txt");                          
	for (int i = 0; i < num_use_cards; i++)
	{
		for (int j = 0; j < MAX_plant_image; j++)
		{	
			plant_o << "PCT/plant/" << i << "/" << j << ".png\n";
		}
	} 
	plant_o.close();                                      //�ر�д��

	std::ifstream plant_i("plant_name.txt");             //��ʼ��ȡ�ո�д���ֲ��ͼƬ�ļ���ַ����

	for (int i = 0; i < num_use_cards; i++)
	{
		for (int j = 0; j <= MAX_plant_image; j++)
		{
			plant_i.getline(save_name, 62);

			std::ifstream test_open(save_name);                     //�ж��ļ��Ƿ����(��������дһ���ж��м���ͼƬ�ĺ����ģ���û�뵽ֱ����ôд
			if(test_open.good())                                    //����д��������(һ�����м���ͼƬ�ġ�һ��������ǰҪ���ص�ֲ�����Ÿ��������
			{														//��(�ⲻ��һ������)��һ������������������кü���ֱ��ȫ��ֲ�ﶼ���й��ˣ�
				loadimage(&plant_cards[i][j], save_name);     
			}
		}
	}
	plant_i.close();
}
void Put_image()
{

	//��ʼ׼����ͼ
	BeginBatchDraw();		//������ͼ �ݲ����           //��ʼ���壬��������������Ȳ���ʾ����Ļ�ϣ������Ȼ������ڴ���
	putimage(0, 0, &map);
	putimage(280, 0, &Bar);
	for(int i=0;i<num_use_cards;i++)
	{
		//std::cout << "���ڼ��ؿ�Ƭ�ļ� :\n" << save_name << std::endl;
		putimage(358 + 50 * i, 8, &cards[i]);
	}


	if (curPlant != -1 && curPlant < num_use_cards)
	{
//		putimage(point.x - 20, point.y - 30, &plant_cards[curPlant][1],SRCPAINT);
		newPNG(NULL, point.x - 20, point.y - 30, &plant_cards[curPlant][0], BLACK);
	}




	EndBatchDraw();         //����������ͼģʽ�����м��ͼƬһ���Ի��Ƴ���                //����˫���壬���ڴ��е�����һ���Դ�ӡ����Ļ��ȥ
}



void click_act()
{
	if (peekmessage(&point))                           //�����ȡ����һ��������Ϣ
	{
//		std::cout << "get��Ϣ\n";
		if (point.message == WM_LBUTTONDOWN)     //��������һ�����������µ���Ϣ
		{
			//std::cout << "���" << std::endl;
			if (point.x >= 358 && point.x <= 770 && point.y >= 8 && point.y <= 70)
			{
				curPlant = (point.x - 356) / 47;
				std::cout << curPlant << std::endl;
			}
		}


	}



}


//
//void out_plant(int num)
//{
//	BeginBatchDraw();
//	_putimagePNG(point.x, point.y, &plant_cards[num][1]);
//	EndBatchDraw();
//}


//
//void update_windows()
//{
//	BeginBatchDraw();
//	EndBatchDraw();
//}