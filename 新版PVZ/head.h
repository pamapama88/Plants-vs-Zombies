/*
����֮ǰ��һ��C����˼·����ȫ�Լ��о���
ÿһ����ĸ����Ѫ��
*/
#include<iostream>
#include<fstream>
#include<graphics.h>
#include<cstring>



void Initmap();           //���ر���ͼ
void load_cards();        //���ؿ�ƬͼƬ
void load_plants();         
//void load_all_plants();//��ֲ��ͼƬ���ص��ڴ��б������Ա��Ժ�ʹ��
//int num_a_cards(int);                   //����ĳ��ֲ���ɼ���ͼƬ����
void Put_image();          //�������ͼƬ
void click_act();           //���������Ϣ��������ط�Ӧ
void out_plant(int num);       //����ֲ����Ų��������ֲ��ͼƬ
void update_windows();





//����һЩ����
void newPNG(IMAGE* dstimg, int x, int y, IMAGE* srcimg, UINT transparentcolor);     //͸����PNG��ͼ



