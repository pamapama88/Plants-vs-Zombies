#include"head.h"
//���ļ�����дֲ���ʬ�Ĺ�����������Ĳ�������С�Ƴ����ȹ���

IMAGE p_sunshine[29]{};
IMAGE sun[24]{};
int rdom_x{};               //����������x����
int rdom_y{};               //����������y����
int count2{};              //������

void random_sun() 
{
	static int cycle = 10 * 10000;                //������ѭ������

	srand((unsigned int)time(NULL));

	static float mov_y = -10;
	static float dfrn{};

	struct the_rand
	{
		int lx = 193, rx = 953;
		int uy = 154, dy = 564;         //��ʾ��������ķ�Χ
	}r; 
	if(count2==88)
	{
		rdom_x = rand() % (r.rx - r.lx) + r.lx;
		rdom_y = rand() % (r.dy - r.uy) + r.uy;

		mov_y = -10;
		dfrn = (rdom_y - mov_y) / 150;
	}

	count2++;
	count2 = count2 >= cycle ? 0 : count2;
	//std::cout << count2 << std::endl;

	if (count2 > 0.4* cycle)
	{
		if (count2 % 250 == 0 && mov_y <= rdom_y)      //ÿ350��ִ��һ��
		{
			mov_y += dfrn;
		}
		//std::cout << (count2 / 1000) % 22 << std::endl;
		std::cout << mov_y << std::endl;
		newPNG(NULL, rdom_x, mov_y, &sun[(count2 / 500) % 22], BLACK);   //ÿ11000�θı�һ��ͼƬ
	}

}