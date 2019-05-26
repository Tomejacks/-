#include<iostream>
#include<Windows.h>
#include<graphics.h>

using namespace std;
int main(void){
	initgraph(640,640);
	IMAGE logo_img;
	loadimage(&logo_img,_T("logo.bmp"),433,147);
	putimage(110,20,&logo_img);
	setlinecolor(WHITE);
	setfillcolor(BLACK);
	rectangle(210,390,270,420);
	settextstyle(25,0,_T("Î¢ÈíÑÅºÚ"));
	outtextxy(220,395,_T("°ïÖú"));
	rectangle(330,390,390,420);
	outtextxy(340,395,_T("¿ªÊ¼"));
	MOUSEMSG mouse;
	IMAGE illustrate_img;
	loadimage(&illustrate_img,_T("illustrate.jpg"),300,300);
    int finshed=0;
	while(!finshed){
		mouse=GetMouseMsg();
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
	system("pause");
}