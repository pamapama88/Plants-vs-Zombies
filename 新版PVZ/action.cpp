#include"head.h"
//���ļ�����дֲ���ʬ�Ĺ�����������Ĳ�������С�Ƴ����ȹ���

IMAGE p_sunshine[29]{};
int rd_x{};               //����������x����
int rd_y{};               //����������y����
int count2{};              //������
void random_sun() 
{
	unsigned seed;
	seed = time(0);
	srand(seed);

	struct the_rand
	{
		int lx = 193, rx = 953;
		int ly = 154, dy = 564;         //��ʾ��������ķ�Χ
	}r; 
	if(count2==0)
	{
		rd_x = rand() % (953 - 193) + 193;
		rd_y = rand() % (564 - 154) + 154;
	}

	count2++;
	count2 = count2 >= 10000 ? 0 : count2;
	std::cout << count2 << std::endl;
}