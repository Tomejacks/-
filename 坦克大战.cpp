#include<iostream>
#include<Windows.h>
#include<graphics.h>

using namespace std;

void logo(void){
	initgraph(640,640);//��ʼ��ͼ�ν���
	IMAGE logo_img;
	loadimage(&logo_img,_T("logo.bmp"),433,147);
	putimage(110,20,&logo_img);//��ʾͼƬ
	setlinecolor(WHITE);//����������ɫ
	setfillcolor(BLACK);
	rectangle(210,390,270,420);
	settextstyle(25,0,_T("΢���ź�"));
	outtextxy(220,395,_T("����"));
	rectangle(330,390,390,420);
	outtextxy(340,395,_T("��ʼ"));

	MOUSEMSG mouse;//��mouse��
	IMAGE illustrate_img;
	loadimage(&illustrate_img,_T("illustrate.jpg"),300,300);
    int finshed=0;
	while(!finshed){
		mouse=GetMouseMsg();//mouse=����ƶ�������
		switch(mouse.uMsg){
		case WM_MOUSEMOVE:
			if(mouse.x>210&&mouse.x<270&&mouse.y>390&&mouse.x<420){
				putimage(180,420,&illustrate_img);
			}else{
				solidrectangle(180,420,480,720);
			}
			break;
		case WM_LBUTTONDOWN:
			if(mouse.x>330 && mouse.x<390 && mouse.y>390 && mouse.y<420){
			cleardevice();
			finshed=1;
			break;
			}
	}
	}
}
int main(void){

	logo();//��ʾ���ǳ�ʼ����,�Լ���ʼ

	int map[6][6]={
		{0,1,1,1,1,1},
		{1,1,1,1,1,1},
		{1,2,1,1,1,1},
		{1,1,1,1,1,1},
		{1,1,3,3,1,1},
		{1,1,3,3,1,1}
	};
	//�����ҷ���ӥ,ǽ,����������ǽ
	IMAGE image_home;
	IMAGE image_wall1;
	IMAGE image_wall2;
	loadimage(& image_home ,_T("home.jpg"),50,50);//������ӥ��3��ʾ
	loadimage(& image_wall1,_T("wall1.jpg"),25,25);//��������ǽ��1
	loadimage(&image_wall2,_T("wall2.jpg"),25,25);//��������ǽ��2

	int i,j;//�����ά�����ʼֵ
	for(i=0;i<6;i++){
		for(j=0;j<6;j++){
			if(map[i][j]==1){
				putimage(25*j,25*i,&image_wall1);
			}else if(map[i][j]==2){
				putimage(25*j,25*i,&image_wall2);
			}else if(map[i][j]==3){
				putimage(25*j,25*i,&image_home);
				map[i][j]    =4;
				map[i+1][j]  =4;
				map[i][j+1]  =4;
				map[i+1][j+1]=4;
				

			}
		}
	}

	system("pause");
	return 0;
}