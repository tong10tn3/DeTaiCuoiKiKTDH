#include <graphics.h> 
#include<iostream>
#include "hamCoSo.h"
#include "ve2D1.h"
#include "ve2D2.h"
#include<fstream>
#include<math.h>
#include<conio.h>
#include "VeGiaoDien.h"
#include<iostream>
using namespace std;
#define PI 3.14159265359

int main()//int argc, char *argv[]
{
	initwindow(1280+8,720+12);
	setGiaoDien();
	xuLi();
	//tinhTien();
	//outtextxy(15,500,"VAT");
//	putpixel5DV(500,200,12);
	//lineDDA(500,200,700,300,12);
	
//	for(int i=20;i<=100;i+=5)
//	{
//		setDoThi();
//		//drawCircleMidpoint(500, 200, i,12);
//		//circleBresenham(500,200,i,12);
//		elipse(500,200,i,i/2,12);
//		setfillstyle(SOLID_FILL,15);
//		floodfill(500,200,12);
//		cout<<i<<endl;
//		delay(1000);
//	
//	}

	//veVeTinh(500,200);
//veThienThach(500,200,0,12);
	
	getch();
	return 0;
	
}



