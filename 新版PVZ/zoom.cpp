//��һ��Դ�ļ�д�˺öණ��
//�����е��ң����Խ���ʬд������ļ�������
//�����Ҿ���ҪΪ�Ժ���������㣬�ѹ��ܾ������ɿ��Դ��εĺ���
//�����Ժ�ֱ�ӵ��þͿ�����

#include"head.h"







void my_load(string load_name)
{
	int num_0 = num_a_cards(load_name);                      //����һ��ֲ��Ķ�̬��Ƭ���м���
	std::cout << num_0 << std::endl;
	//std::ofstream plant_o;                                      //��ʼ��һ��ֲ�￨Ƭ���ļ���ַд��һ��txt�ļ�
	//plant_o.open("plant_name.txt");
	//for (int i = 0; i < num_use_cards; i++)
	//{
	//	for (int j = 0; j < MAX_plant_image; j++)
	//	{
	//		plant_o << "PCT/plant/" << i << "/" << j << ".png\n";
	//	}
	//}
	//plant_o.close();                                      //�ر�д��

	//std::ifstream plant_i("plant_name.txt");             //��ʼ��ȡ�ո�д���ֲ��ͼƬ�ļ���ַ����

	//for (int i = 0; i < num_use_cards; i++)
	//{
	//	for (int j = 0; j <= MAX_plant_image; j++)
	//	{
	//		plant_i.getline(save_name, 62);

	//		std::ifstream test_open(save_name);                     //�ж��ļ��Ƿ����(��������дһ���ж��м���ͼƬ�ĺ����ģ���û�뵽ֱ����ôд
	//		if (test_open.good())                                    //����д��������(һ�����м���ͼƬ�ġ�һ��������ǰҪ���ص�ֲ�����Ÿ��������
	//		{													//��(�ⲻ��һ������)��һ������������������кü���ֱ��ȫ��ֲ�ﶼ���й��ˣ�
	//			num_of_plant_image[i] += 1;
	//			loadimage(&plant_cards[i][j], save_name);
	//		}
	//	}
	//}
	//plant_i.close();




}



int num_a_cards(string load_name)
{
	string all_of_this = "23";
	string type_name = ".png";
	string char_num{};
	bool make_break = 1;

	std::cout << make_break << std::endl;

	int the_num_a_card{};
	while (make_break)
	{
		std::ofstream this_test;
		char_num = '0' + the_num_a_card;
		all_of_this = load_name + char_num + type_name;
		std::cout << all_of_this << std::endl;
		this_test.open(all_of_this);
		
		make_break = this_test.good();
		this_test.close();
		the_num_a_card++;
	}
	the_num_a_card--;
	return the_num_a_card;
}







