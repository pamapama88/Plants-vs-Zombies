#include"head.h"
//���ļ�����дֲ���ʬ�Ĺ�����������Ĳ�������С�Ƴ����ȹ���

IMAGE p_sunshine[29]{};
IMAGE sun[24]{};
int rdom_x{};               //����������x����
int rdom_y{};               //����������y����
int count2 = 10 * 10000 * 0.2; //������  ��ʼֵ����0��Ϊ�˵�һ���������ڿ�ʼ�󲻾þ��ܽ�������
float mov_y = -75;           //�������ʼλ���Լ��Ժ���˶��켣
float dfrn{};                //ÿ������ļ��


void random_sun() 
{
	const int cycle = 10 * 10000;                //������ѭ������

	srand((unsigned int)time(NULL));

	struct the_rand
	{
		int lx = 193, rx = 953;
		int uy = 154, dy = 564;         //��ʾ�����������ķ�Χ
	}r; 
	if (count2 == (0.4 * cycle) - 2)
	{
		rdom_x = rand() % (r.rx - r.lx) + r.lx;       //���ȷ��һ������������յ�λ��
		rdom_y = rand() % (r.dy - r.uy) + r.uy;

		mov_y = -75;                          //���ó�ʼλ�ú������ٶ�
		dfrn = (rdom_y - mov_y) / 110;        // 110 ��ʾ�����ٶȣ�ԽС����Խ��
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
		//std::cout << mov_y << std::endl;
		newPNG(NULL, rdom_x, mov_y, &sun[(count2 / 500) % 22], BLACK);   //ÿ11000�θı�һ��ͼƬ
	}

}





IMAGE easy_zoom_go3[19]{};
IMAGE easy_zoom_wait2[25]{};






void my_load(IMAGE get_in[], string load_name)
{
	int num_0 = num_a_cards(load_name);                      //����һ��ֲ��Ķ�̬��Ƭ���м���
	std::cout << num_0 << std::endl;
	string all_of_this = "23";
	string type_name = ".png";
	string char_num = "      ";
	int num_count = 0;
	while (num_0)
	{
		char_num = turn_int_into_char(num_count);
		all_of_this = load_name + char_num + type_name;
		loadimage(&get_in[num_count], all_of_this.c_str());          // c_str() �� ctring �ṩ��һ�ַ������ܹ���string����ת���� char* ���ͷ��ء�
		num_count++;
		num_0--;
	}
}



int num_a_cards(string load_name)
{
	string all_of_this = "23";
	string type_name = ".png";
	string char_num = "      ";
	bool make_break = 1;

	int the_num_a_card = 0;
	while (make_break)
	{
		std::ifstream this_test;
		char_num = turn_int_into_char(the_num_a_card);                  //������취������ת��0~9֮�ڵ�������λ���Ͳ����ˣ�     
		all_of_this = load_name + char_num + type_name;   //�������ǻ���Ҫһ������ת���ַ����ĺ���������Ӧ�û�����һ������λ���ĺ�������� �����±���⣩                      
		std::cout << all_of_this << std::endl;
		this_test.open(all_of_this);

		make_break = this_test.good();
		this_test.close();
		the_num_a_card++;
	}
	the_num_a_card--;
	return the_num_a_card;
}



int wei_shu(int  a)
{
	if (a == 0)
	{
		return 1;
	}
	int ws = 0;
	int b = a;
	while (b)
	{
		b /= 10;
		ws++;
	}
	return ws;

}


string turn_int_into_char(int a)
{
	int ws = wei_shu(a);
	int* one_num = new int[ws];
	string the_char{};
	string a_num{};
	for (int i = 0; i < ws; i++)
	{
		one_num[ws - i - 1] = a % 10;
		a /= 10;
	}
	for (int i = 0; i < ws; i++)
	{
		the_char += ('0' + one_num[i]);
	}
	delete[ws] one_num;
	//std::cout << the_char << std::endl;
	return the_char;
}


