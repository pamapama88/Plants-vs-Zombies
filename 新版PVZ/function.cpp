#define _CRT_SECURE_NO_DEPRECATE 1
#include"head.h"
const int num_cards = 8;
const int num_use_cards = 2;

IMAGE map;            //�տ�ʼ��Ϊ��ʹ�÷��㣬�õ���һ�� IMAGE* ָ�룬���û��ʼ����������һ���磬�����г���һ��
IMAGE Bar;            //��ȷʵ�Ƴ綨������ʼ��һ�𣬵������ָ��������Ĳ�֪��Ҫ������ʼ��һ��ʲô���������Ծ͸����˱�����ʾ
IMAGE cards[10]{};
char save_name[60]{};
//enum cards_name{bin,flower,count };
//IMAGE card_name[1];


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
	for (int i = 0; i <= num_cards; i++)
	{
		of_save_name << "PCT/card/card_" << i << ".png\n";         //�����ļ������� ��Ƭ���ڵ��ļ���ַ ��������
	}
	for(int i=0;i<num_use_cards;i++)
	{
		//if_save_name >> save_name[0];
		if_save_name.getline(save_name, 60);
		std::cout << "���ڼ��ؿ�Ƭ�ļ���ַ :\n" << save_name[i] << std::endl;

		loadimage(&cards[0], save_name);
	}




}
void Put_image()
{

	//��ʼ׼����ͼ
	BeginBatchDraw();		//������ͼ �ݲ����           //��ʼ���壬��������������Ȳ���ʾ����Ļ�ϣ������Ȼ������ڴ���
	putimage(0, 0, &map);
	putimage(280, 0, &Bar);
	for(int i=0;i<num_use_cards;i++)
	{
		std::cout << "���ڼ��ؿ�Ƭ�ļ� :\n" << save_name[i] << std::endl;
		putimage(310, 10, &cards[i]);
	}


	EndBatchDraw();         //����������ͼģʽ�����м��ͼƬһ���Ի��Ƴ���                //����˫���壬���ڴ��е�����һ���Դ�ӡ����Ļ��ȥ



}