#include<iostream>
#include<Windows.h>
#include<graphics.h>

using namespace std;
int main(void){

	initgraph(640,640);
	IMAGE logo_img;
	loadimage(&logo_img,_T("logo.bmp"),433,147);
	putimage(110,20,&logo_img);
	system("pause");
}