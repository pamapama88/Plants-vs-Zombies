#include"head.h"
//���ļ�����дֲ���ʬ�Ĺ�����������Ĳ�������С�Ƴ����ȹ���

IMAGE p_sunshine[29]{};     
IMAGE sun[24]{};
int rdom_x{};               //����������x����
int rdom_y{};               //����������y����
int count2 = 10 * 10000 * 0.2; //������  ��ʼֵ����0��Ϊ�˵�һ���������ڿ�ʼ�󲻾þ��ܽ�������
float mov_y = -75;           //�������ʼλ���Լ��Ժ���˶��켣
float dfrn{};                //ÿ������ļ��


void random_sun()                                      //�����������
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

	if (count2 > 0.4 * cycle && note_sunshine == 0)
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






void my_load(IMAGE get_in[], string load_name)              //���� load_name �ļ��������е� .PNG ͼƬ��get_in������
{
	int num_0 = num_a_cards(load_name);                    
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



int num_a_cards(string load_name)                      //����ͼƬ���ļ���λ�����ƣ�����������ļ������м��� .PNG ͼƬ
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

//int num_a_cards(IMAGE tupianshuzu[])                //�����м���ͼƬ�ġ�����ͼƬ���������
//{
//	bool make_break = 1;
//
//	int the_num_a_card = 0;
//
//	IMAGE* IBegin = 
//		
//	return the_num_a_card;
//}



int wei_shu(int  a)           //����һ�������м�λ�ĺ���
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


string turn_int_into_char(int a)              //��һ������ת��Ϊstring�ַ����ĺ���     ��  �����Ҫchar* �� ����Ҫ�� .c_str() ��������ת��
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



//   �ƶ�        �ٶ�        ϸ�ּ���   ���X          ���Y          �յ�X        �յ�Y    Ҫ�ƶ���ͼƬ��      ���������±�   ���е����Ҫ�޸ĵı�־�Ͳ���
void move_it(int speece, int Npart, int pl_startX, int pl_startY, int pl_endX, int pl_endY, IMAGE img_object[], int img_num, int* note)
{

	static float dfrnX = (pl_startX - pl_endX) / Npart;
	static float dfrnY = (pl_startY - pl_endY) / Npart;

	static int m_count{};

	static int pl_mX = pl_startX;        
	static int pl_mY = pl_startY;

	if(m_count>=0)
	{
		if (m_count % speece == 0)
		{
			newPNG(NULL, pl_mX, pl_mY, &img_object[m_count % img_num + 1], BLACK);

			pl_mX += dfrnX;
			pl_mY += dfrnY;

		}
		m_count++;
		m_count > Npart* speece ? m_count : -1;              //ѭ�� Npart ��֮�� m_count
		if (m_count == -1)
		{
			*note = 0;
		}
	}

}


//�����ձ�־������
void move_it(int speece, int Npart, int pl_startX, int pl_startY, int pl_endX, int pl_endY, IMAGE img_object[], int img_num)
{

	static float dfrnX = (pl_startX - pl_endX) / Npart;
	static float dfrnY = (pl_startY - pl_endY) / Npart;

	static int m_count{};

	static int pl_mX = pl_startX;
	static int pl_mY = pl_startY;

	if (m_count >= 0)
	{
		if (m_count % speece == 0)
		{
			newPNG(NULL, pl_mX, pl_mY, &img_object[m_count % img_num + 1], BLACK);

			pl_mX += dfrnX;
			pl_mY += dfrnY;

		}
		m_count++;
		m_count > Npart* speece ? m_count : -1;              //ѭ�� Npart ��֮�� m_count

	}

}


//û��ϸ�ֲ��ĺ�������  de  ֻ����һ��ͼƬ��  ����
void move_it(int speece,  int pl_startX, int pl_startY, int pl_endX, int pl_endY, IMAGE img_object)
{

	static float dfrnX = (pl_startX - pl_endX) / 66;
	static float dfrnY = (pl_startY - pl_endY) / 66;

	static int m_count{};

	static int pl_mX = pl_startX;
	static int pl_mY = pl_startY;

	if (m_count >= 0)
	{
		if (m_count % speece == 0)
		{
			newPNG(NULL, pl_mX, pl_mY, &img_object, BLACK);

			pl_mX += dfrnX;
			pl_mY += dfrnY;

		}
		m_count++;
		m_count > 66* speece ? m_count : -1;              //ѭ�� Npart ��֮�� m_count
	}
}



