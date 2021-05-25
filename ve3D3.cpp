#include <graphics.h> 
#include<iostream>
#include "hamCoSo.h"
#include "ve3D3.h"
#include "ve3D1.h"
#include<fstream>
#include<math.h>
#include<conio.h>
#include "VeGiaoDien.h"
#define ROUND(a) (int)(a+0.5)
#include <sstream>
using namespace std;


void veHinhHopChuNhat(int x,int y,int z,int d,int r,int c){
	d=d*5;
	r=r*5;
	c=c*5;
	int xO=700;
	int yO=320;	
	int X,Y,Xdoi,Ydoi;
	float sqrt2per2 = sqrt(2) / 2;
	doisang2D(x,y,z,X,Y);
	doiNguoiDungsangMayTinh(X,Y,xO,yO,Xdoi,Ydoi);
	setcolor(0);
	lineDDA(700,5,700,320,0);
	lineDDA(700,320,305,715,0);
	lineDDA(700,320,1275,320,0);
	setbkcolor(15);
	outtextxy(680,20,"Y");
	outtextxy(1250,300,"X");
	outtextxy(320,665,"Z");
	lineDDA(X, Y - c, X + d, Y - c,0);
	lineDDA(X + d, Y - c, X + d, Y,0);
	veNetDut(X + d, Y, X, Y);
	veNetDut(X, Y, X, Y-c);
	lineDDA(Xdoi - sqrt2per2*r, Ydoi - (c - sqrt2per2*r), Xdoi + d - sqrt2per2 * r, Ydoi - (c - sqrt2per2 * r),0);//EF
	lineDDA(Xdoi + d - sqrt2per2 * r, Ydoi - (c - sqrt2per2 * r), Xdoi + d - sqrt2per2 * r, Ydoi + sqrt2per2 * r,0);//FG
	lineDDA(Xdoi + d - sqrt2per2 * r, Ydoi + sqrt2per2 * r, Xdoi - sqrt2per2 * r, Ydoi + sqrt2per2 * r,0);//HG
	lineDDA(Xdoi - sqrt2per2 * r, Ydoi + sqrt2per2 * r, Xdoi - sqrt2per2 * r, Ydoi - (c - sqrt2per2 * r),0);//EH
	
	lineDDA(Xdoi - sqrt2per2 * r, Ydoi - (c - sqrt2per2 * r), Xdoi, Ydoi - c,0);//BF
	lineDDA(Xdoi + d - sqrt2per2 * r, Ydoi - (c - sqrt2per2 * r), Xdoi + d, Ydoi - c,0);//BB'
	lineDDA(Xdoi + d - sqrt2per2 * r, Ydoi + sqrt2per2 * r, Xdoi + d, Ydoi,0);//CG
	veNetDut(Xdoi - sqrt2per2 * r, Ydoi + sqrt2per2 * r, Xdoi, Ydoi);//DH
}
void hamVeHinhHopChuNhat(){
	clearmouseclick(WM_LBUTTONUP);
	setGiaoDienHoatDong(4);
	setbkcolor(mauxanhgiongaokhoaccrush);
	settextstyle(DEFAULT_FONT,0, 1);
	outtextxy(70,280,"HINH HCN ");
	int x=	nhapDuLieu("Nhap Toa Do X Day: ",3,1);

	int y=	nhapDuLieu("Nhap Toa Do Y Day: ",3,2);

	int z=	nhapDuLieu("Nhap Toa Do Z Day: ",3,3);
	
	int d=	nhapDuLieu("Nhap Chieu Dai : ",3,4);
	
	int r=	nhapDuLieu("Nhap Chieu Rong: ",3,5);
	
	int c = nhapDuLieu("Nhap Chieu Cao: ",3,6);
	veHinhHopChuNhat(x,y,z,d,r,c);
	setcolor(15);
	
	ostringstream convertX;
	ostringstream convertY;
	ostringstream convertZ;
	ostringstream convertD;
	ostringstream convertR;
	ostringstream convertC;
	
	convertX<<x;
	convertY<<y;
	convertZ<<z;
	convertD<<d;
	convertR<<r;
	convertC<<c;
	
	string toaDoXString=convertX.str();
	string toaDoYString= convertY.str();
	string toaDoZString= convertZ.str();
	string DString= convertD.str();
	string RString= convertR.str();
	string CString= convertC.str();
	
	setThongTin();
	outtextxy(70,280,"HINH HCN ");
	string text= "Tam Day 0 ("+toaDoXString+","+toaDoYString+","+toaDoZString+")";
	string text2= "Chieu Dai: "+DString;
	string text3="Chieu Rong: "+RString;
	string text4="Chieu Cao: "+CString;
	
		
	char *textC = new char[text.length()+1];
	strcpy(textC,text.c_str());
	outtextxy(15,280+30,textC);
	
	char *textC2= new char[text2.length()+1];
	strcpy(textC2,text2.c_str());
	outtextxy(15,280+60,textC2);
	
	char *textC3= new char[text3.length()+1];
	strcpy(textC3,text3.c_str());
	outtextxy(15,280+90,textC3);
	
	char *textC4 = new char[text.length()+1];
	strcpy(textC4,text.c_str());
	outtextxy(15,280+120,textC4);
	
	char *textC5= new char[text2.length()+1];
	strcpy(textC5,text2.c_str());
	outtextxy(15,280+150,textC5);
	
	char *textC6= new char[text3.length()+1];
	strcpy(textC6,text3.c_str());
	outtextxy(15,280+180,textC6);
	while(true){
		delay(1);

		if(ismouseclick(WM_LBUTTONUP))
			{
				int xtam; int ytam;
				getmouseclick(WM_LBUTTONUP,xtam,ytam);
				clearmouseclick(WM_LBUTTONUP);
				if(xtam>=25&&xtam<=108&&ytam>=119&&ytam<=189)
				{
					setThongTin();
					setDoThi();
					break;
				}
			}
	}
}
