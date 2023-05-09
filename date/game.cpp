#define _CRT_SECURE_NO_DEPRECATE 1
#include"tansfer.h"

extern IMAGE ImgBg;  //�����ⲿ���ţ������ǽ�ȫ�ֱ���ImgBg�������
extern IMAGE ImgBar; //������
extern enum { Bin, Sunflower, count };
extern IMAGE ImgCards[count];
extern char name[64];
extern int curX, curY;
extern IMAGE* ImgPlants[count][20];
extern int curPlant;




bool FileExist(const char* name)      //�������صķ�������ļ��Ƿ����
{ 
	FILE* fp = fopen(name, "r");      // fopen  :���ļ�      r ��ָ ��ֻ����ʽ��һ���ı��ļ��������뿴������α���
	if (fp == NULL)                   // NULL   ����
	{
		return false;
	}
	else
	{
		fclose(fp);                   // fcolse :�ر��ļ�      ��Ϊ�ļ���Ҳ�˷���Դ���������ֹر��Ǻ�ϰ��
		return true;                    
	}
	//  ����������   ����Ŀ�����а�c++��SDL���ص��ſ�������������,����ֻ�ܼ� _s


}





void Initgame() {


	//���ر���ͼƬ
	loadimage(&ImgBg, "PCT/ImgBg.png");   //���ִ�����������Ŀ����������ַ����ĳ��ˡ����ֽ��ַ�����
	
	//������Ϸͼ�δ���
	initgraph(950, 728,1);

	//������Ϸ����,���ر���
	//UpdateWindow();

	//����һ��������,�����ں���λ��
	loadimage(&ImgBar, "PCT/Bar.png"); 
	//UpdateWindow();
	

	//����ö�� �г�ֲ���ȷ��ֲ�����
	//enum {Bin,Sunflower,count};   //��ö���У���һ������=0��Ҳ����˵count�����ܱ�ʾֲ��ĸ�������������

	//����һ��ͼ�����飬���ڴ��ֲ�￨Ƭ
	//IMAGE ImgCards[count];

	//��ʼ��ֲ�￨Ƭ

	//��ָ�루���У����㡣������forѭ����������Ҫ��һ��������������Ϊһ��ֵ��ʱ������ã�
	memset(ImgPlants, 0, sizeof(ImgPlants));

	
	for (int i = 0; i < count; i++)
	{
		//����ֲ�￨Ƭ�ļ�����
		sprintf_s(name, sizeof(name), "PCT/card/card_%d.png", i);
		loadimage(&ImgCards[i], name);


		//��ʼ����ֲ���ͼƬ��



		for (int j = 0; j < 20; j++)
		{
			//����ֲ���ļ�����
			sprintf_s(name, sizeof(name), "PCT/plant/%d/%d.png", i, j+1);

			//��Ϊÿ��ֲ���ͼƬ��һ���࣬��������Ҫ�ж��ļ��Ƿ����
			if (FileExist(name))
			{
				ImgPlants[i][j] = new IMAGE;  //��Ϊ������鱻��ʼ��Ϊ0������ֱ�ӿ�ʼ����ͼƬ�Ļ����ᵼ�½����޷�����
				                              //new ��C�еĺ��������ڷ����ڴ棨��Ϊgraphics�ĵײ����Ծ���C���Բ���C++�еĺ��������ڴ棩
				loadimage(ImgPlants[i][j], name);
			}
			else
			{
				break;
			}
		}

	}
	//UpdateWindow();



}



void UserClick()
{
	ExMessage msg;
	static int status = 0;   //��Ϊ����ƶ�������Ҫ���ϵ����������������Ϊ�˳����ܿ������У������status��״̬���þ�̬������


	//peekmessage(&msg);  //�ж���û����Ϣ������������ƶ��ȵȣ�������Ϣ�����棬û����Ϣ���ؼ�
	//getmessage      ��֮���ƵĻ���getmessge,����getmessaeg�Ƕ�ȡ��Ϣ�����û����Ϣ������ȻῨס��Ӱ���û�����

	if (peekmessage(&msg))
	{
		if (msg.message == WM_LBUTTONDOWN)   //�����Ϣ����갴��
		{
			if (msg.x > 300 && msg.x < 350 + 52 * count && msg.y>6 && msg.y < 71)
			{
				int index = (msg.x - 300) / 52;      //ԭ�����....�ϼ򵥣��Լ�����(����������ֻ���ܳ�����52�����һ�����ƵĿ�ȣ�)
				status = 1;                     //��ʾ״̬�����������ִ���ˣ���ôstatus�͵���1                                                         //����
				curPlant = index + 1;
				printf("curPlant=%d", curPlant);
			
			}		
		}
		else if (msg.message == WM_MOUSEMOVE  && 1 == status)   //���������ƶ�,���ҵ����ȥ��
		{
			curX = msg.x;
			curY = msg.y;
		//	printf("X=%d,Y=%d", curX, curY);


		}
		else if (msg.message == WM_LBUTTONUP)      //����ɿ�
		{

		}

	}



}







void UpdateWindow()
{
	BeginBatchDraw();   //��ʼ���壬��������������Ȳ���ʾ����Ļ�ϣ������Ȼ������ڴ���

	//����
	putimage(0, 0, &ImgBg);  //0,0 ��ͼƬ�����꣬�������Ͻ���ԭ�㣬ͼƬ���Ͻ���ͼƬ�Ķ�λ��
	//������
	putimage(230, 0, &ImgBar);

	//ֲ�￨Ƭ
	for (int i = 0; i < count; i++)
	{
		int x = 305 + i * 52;
		int y = 7;
		putimage(x, y, &ImgCards[i]);
	}

	//��Ⱦ �϶������е�ֲ��
	if (curPlant > 0)
	{
		//printf("��ʵ����");
		putimage(curX - 25,curY - 30, ImgPlants[curPlant][0]);     //��Ϊ�����ֲ������Ͻǣ����԰�X��Y��ȥ���ͼƬ������ʹ���ָ��ֲ���м���
	}




	EndBatchDraw();   //����˫���壬���ڴ��е�����һ���Դ�ӡ����Ļ��ȥ
}
////;
