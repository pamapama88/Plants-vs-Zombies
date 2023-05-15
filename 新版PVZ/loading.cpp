#include"head.h"
const int num_cards = 8;
const int num_use_cards = 2;
const int MAX_plant_image = 17;

IMAGE map;            //�տ�ʼ��Ϊ��ʹ�÷��㣬�õ���һ�� IMAGE* ָ�룬���û��ʼ����������һ���磬�����г���һ��
IMAGE Bar;            //��ȷʵ�Ƴ綨������ʼ��һ�𣬵������ָ��������Ĳ�֪��Ҫ������ʼ��һ��ʲô���������Ծ͸����˱�����ʾ
IMAGE cards[num_cards]{};               //ֲ��Ŀ�ƬͼƬ
char save_name[60]{};                   //��ʱ�洢���ֵ�ַ���Ƶ��ַ���
IMAGE plant_cards[num_cards][25]{};     //ֲ������ж�̬ͼƬ
int num_of_plant_image[num_cards][2]{}; //ֲ��Ķ�̬ͼƬ�м��ţ����ڼ���ʱ˳��������ģ�
ExMessage point;     //ExMessage ��easyXͼ�ο��ﶨ���һ���ṹ�壬��������갴�¡��ƶ����ɿ������ָ�뵱ǰλ�õı���
int curX = point.x;
int curY = point.y;           
int curPlant = -1;           //��ǰ��ֲ������
const int p_w = -45;          //����΢��ֲ����õ�λ��
const int p_h = -55;          //����΢��ֲ����õ�λ��
struct place                 //��������
{
	int l = 175; int r = 995;
	int dist = 82;
	int u1 = 95, d1 = 205;
	int u2 = 205, d2 = 305;     //��ͼÿ�еĳ��������
	int u3 = 305, d3 = 405;
	int u4 = 405, d4 = 500;
	int u5 = 500, d5 = 595;
	int x{};             //���Է�ֲ��Ŀ�λ�Ķ�Ԫ���
	int y{};             //���Ͻ�Ϊԭ��
}pl;
int xunhuankonghzi = 0;

void Initmap()
{
	initgraph(1080, 675, 1);    //������Ϸ��ͼ�Σ�����

	std::cout << "���ڳ�ʼ����ͼ����...\n" << "���ڼ���ͼƬ...\n";
	loadimage(&map, "PCT/map.png", 1500, 675);           //���ر���ͼƬ
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
			{													//��(�ⲻ��һ������)��һ������������������кü���ֱ��ȫ��ֲ�ﶼ���й��ˣ�
				num_of_plant_image[i][0] += 1;
				loadimage(&plant_cards[i][j], save_name);     
			}
		}
	}
	plant_i.close();
}


void click_act()
{   
	//11111111111111111111111111111111111111111111111111111111111111111111111111111
	if (peekmessage(&point))                          //�����ȡ����һ��������Ϣ 
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
		//2222222222222222222222222222222222222222222222222222222222222222222222222222222
		if (point.message == WM_LBUTTONDOWN && curPlant != -1 && curPlant < num_use_cards)                     //���ѡ����һ��ֲ�ﲢ���ֵ����һ�����
		{
			if (curPlant != -1 && point.x >= pl.l && point.x <= pl.r && point.y >= pl.u1 && point.y <= pl.d1)          //�������µ�һ��
			{
				pl.y = 1;
				pl.x = (point.x - pl.l+pl.dist) / pl.dist;
				std::cout << pl.x << " and " << pl.y << "   pl.dis1 :" << pl.dist << "   �� ��" << pl.u1 << " �� ��" << pl.d1 << " ��  :" << pl.l << " �� ��" << pl.r << std::endl;
			}
			else if (curPlant != -1 && point.x >= pl.l && point.x <= pl.r && point.y >= pl.u2 && point.y <= pl.d2)      //�ڶ���
			{
				pl.y = 2;
				pl.x = (point.x - pl.l + pl.dist) / pl.dist;
				std::cout << pl.x << " and " << pl.y << std::endl;
			}
			else if (curPlant != -1 && point.x >= pl.l && point.x <= pl.r && point.y >= pl.u3 && point.y <= pl.d3)      //������
			{
				pl.y = 3;
				pl.x = (point.x - pl.l + pl.dist) / pl.dist;
				std::cout << pl.x << " and " << pl.y << std::endl;
			}
			else if (curPlant != -1 && point.x >= pl.l && point.x <= pl.r && point.y >= pl.u4 && point.y <= pl.d4)      //������
			{
				pl.y = 4;
				pl.x = (point.x - pl.l + pl.dist) / pl.dist;
				std::cout << pl.x << " and " << pl.y << std::endl;
			}
			else if (curPlant != -1 && point.x >= pl.l && point.x <= pl.r && point.y >= pl.u5 && point.y <= pl.d5)      //������
			{
				pl.y = 5;
				pl.x = (point.x - pl.l + pl.dist) / pl.dist;
				std::cout << pl.x << " and " << pl.y << std::endl;
			}

		}
	}
}



void Put_image()
{

	//��ʼ׼����ͼ
	BeginBatchDraw();		//������ͼ �ݲ����           //��ʼ���壬��������������Ȳ���ʾ����Ļ�ϣ������Ȼ������ڴ���
	putimage(-80, 0, &map);
	putimage(280, 0, &Bar);
	for (int i = 0; i < num_use_cards; i++)
	{
		//std::cout << "���ڼ��ؿ�Ƭ�ļ� :\n" << save_name << std::endl;
		putimage(358 + 50 * i, 8, &cards[i]);
	}


	if (curPlant != -1 && curPlant < num_use_cards)                                    //��ѡ�е�ֲ�￪ʼ���������
	{
		//putimage(500, 400, &plant_cards[curPlant][0]);
		newPNG(NULL, point.x - 40, point.y - 60, &plant_cards[curPlant][0], BLACK);
	}
	if (curPlant != -1 && curPlant < num_use_cards && pl.x != 0)                      //��ѡ�е�ֲ����ڶ�Ӧ�Ŀ�λ��
	{
		int p_mid_x = pl.l + pl.dist * (pl.x - 1) + pl.dist / 2 + p_w;		
		int p_mid_y = 0;

		switch(pl.y)                      
		{
		case 1:
			p_mid_y = pl.u1 - (pl.u1 - pl.d1) / 2 + p_h;
			//std::cout << pl.l1 << "��" << pl.r1 << "��" << pl.u1 << "��" << pl.d1 << "��" << "   " << p_mid_x << "," << p_mid_y << std::endl;
			break;
		case 2:
			p_mid_y = pl.u2 - (pl.u2 - pl.d2) / 2 + p_h;
			//std::cout << p_mid_x << "," << p_mid_y << std::endl;
			break;
		case 3:
			p_mid_y = pl.u3 - (pl.u3 - pl.d3) / 2 + p_h;
			//std::cout << p_mid_x << "," << p_mid_y << std::endl;
			break;
		case 4:
			p_mid_y = pl.u4 - (pl.u4 - pl.d4) / 2 + p_h;
			//std::cout << p_mid_x << "," << p_mid_y << std::endl;
			break;
		case 5:
			p_mid_y = pl.u5 - (pl.u5 - pl.d5) / 2 + p_h;
			//std::cout << p_mid_x << "," << p_mid_y << std::endl;
			break;
		default:
			break;
		}
//		std::cout << p_mid_x << "   " << p_mid_y << std::endl;
		newPNG(NULL, p_mid_x, p_mid_y, &plant_cards[curPlant][0], BLACK);              
		
		//������������е����ɣ�
		//while(num_of_plant_image[curPlant][0]--)                                      //���ŵ������λ�ǻ�仯�ģ���������ͼƬ�����ſ�λ�ı仯���仯
		//{                                                                             //�޷���ͼƬ���϶�״̬������
		//	int i = 0;
		//	newPNG(NULL, p_mid_x, p_mid_y, &plant_cards[curPlant][i],BLACK);
		//	i++;
		//}
	}



	EndBatchDraw();         //����������ͼģʽ�����м��ͼƬһ���Ի��Ƴ���                //����˫���壬���ڴ��е�����һ���Դ�ӡ����Ļ��ȥ
}



//
//void out_plant(int num)
//{
//	BeginBatchDraw();
//	_putimagePNG(point.x, point.y, &plant_cards[num][1]);
//	EndBatchDraw();
//}
                                        //����������������Ž���������ѭ����ȥ����ô���Ǿͻ��������λ�õ��ƶ������ϵ����ͼƬ���ͻᵼ��ͼƬ����
                                        //����һ��Ҫ�ûᶯ��ͼƬ�Ͳ��ᶯ��ͼƬһ��ˢ�£��������ܱ�֤��ˢ������ͼƬ����λ�����Ķ��ܹ�������ͼƬ����
//
//void update_windows()
//{
//	BeginBatchDraw();
//	EndBatchDraw();
//}