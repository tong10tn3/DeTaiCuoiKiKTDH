#include "hamCoSo.h"
#include "VeGiaoDien.h"
#include "ve2D1.h"
#include<graphics.h>
#include<iostream>
#include<math.h>
#include <sstream>
using namespace std;

void VePhanCach(double x,double y,int color){
	setcolor(color);
	lineDDANguoiDung(x,y,x+20,y,0);
	lineDDANguoiDung(x+2,y+3,x+21,y+3,0);
	lineDDANguoiDung(x,y,x+2,y+3,0);
	lineDDANguoiDung(x+20,y,x+21,y+3,0);
}

void veTenLua(int x, int y,int x1, int y1,int x2,int y2, int x3, int y3, int x4, int y4, int x5, int y5, int x6, int y6, int x7, int y7)
{
	lineDDANguoiDung(x1,y1,x2,y2,0);
	lineDDANguoiDung(x1,y1,x3,y3,0);
	
	lineDDANguoiDung(x2,y2,x3,y3,0);
	lineDDANguoiDung(x2,y2,x4,y4,0);
	
	lineDDANguoiDung(x3,y3,x5,y5,0);
	lineDDANguoiDung(x4,y4,x5,y5,0);
	
	lineDDANguoiDung(x4,y4,x6,y6,0);
	lineDDANguoiDung(x5,y5,x7,y7,0);
	lineDDANguoiDung(x6,y6,x7,y7,0);
	
	setfillstyle(SOLID_FILL,4);
	floodfillNguoiDung((x1+(x2+x3)/2)/2,(y1+(y2+y3)/2)/2,0);
	
	setfillstyle(SOLID_FILL,1);
	floodfillNguoiDung(x,y,0);
	
	setfillstyle(SOLID_FILL,14);
	floodfillNguoiDung((x4+x7)/2,(y4+y7)/2,0);
	
	// Toa Do ten lua
		setbkcolor(mauxanhgiongaokhoaccrush);
		settextstyle(DEFAULT_FONT,0, 1);
		setcolor(15);
		outtextxy(15,290+15*14,"Toa do cac diem cua TEN LUA");
		outtextxy(15,290+15*15,"1.Mui Ten lua:");
		hienThiToaDo(x1,y1,15);//ten lua x1
		
		outtextxy(15,290+15*16,"2.Than Ten Lua 1:");
		hienThiToaDo(x2,y2,16);//ten lua x1
		
		outtextxy(15,290+15*17,"3.Than Ten Lua 2:");
		hienThiToaDo(x3,y3,17);//ten lua x1
		
		outtextxy(15,290+15*18,"4.Than Ten Lua 3:");
		hienThiToaDo(x4,y4,18);//ten lua x1
		
		outtextxy(15,290+15*19,"5.Than Ten Lua 4:");
		hienThiToaDo(x5,y5,19);//ten lua x1
		
		outtextxy(15,290+15*20,"6.Duoi Ten Lua 1:");
		hienThiToaDo(x6,y6,20);//ten lua x1
		
		outtextxy(15,290+15*21,"7.Duoi Ten Lua 2:");
		hienThiToaDo(x7,y7,21);//ten lua x1
	
	
}
void PTTN1Diem(double Sx,double Sy, int x, int y, int &xKQ, int &yKQ)
{
	double maTranTyLe[3][3]={
		{Sx,0,0},{0,Sy,0},{0,0,1}
	};
	double maTranDiem[1][3]={{x,y,1}};
	double maTranKQ[1][3];
	
	nhan2MaTran(maTranDiem,maTranTyLe,maTranKQ,1,3,3);
	xKQ=maTranKQ[0][0];
	yKQ=maTranKQ[0][1];
}

void tinhTienTenLua(int i)
{
	int k=i;
	i=k-(20*(k/20));
	int xDau=100;  int xCuoi=-98;
	int yDau=60;   int yCuoi=60;

	double maTranTenLua[1][3]={{xDau,yDau,1}};
	
	double maTranTT[3][3]={
		{1,0,0	},
		{0,1,0	},
		{(xCuoi-xDau)*i/15, (yCuoi-yDau)*i/15, 1}
	};
	
	double KQ[1][3];
	nhan2MaTran(maTranTenLua,maTranTT,KQ,1,3,3);
	
	int x=KQ[0][0];
	int y=KQ[0][1];
	int a=20;
	int b=10;
	int aKQ,bKQ;
	double m=1+0.15*i;
	PTTN1Diem(1/m,1/m,a,b,aKQ,bKQ);
	a=aKQ;
	b=bKQ;
	int x1=x-a;
	int y1=y;
	
	int x2=x-a/2;
	int y2=y-b/2;
	
	int x3=x-a/2;
	int y3=y+b/2;
	
	int x4=x+a/2;
	int y4=y-b/2;
	
	int x5=x+a/2;
	int y5=y+b/2;
	
	int x6=x+a;
	int y6=y-b;
	
	int x7=x+a;
	int y7=y+b;
	veTenLua( x , y, x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,x6,y6,x7,y7);
}
void canhVat(){
	double mtnui1[1][3]={-86,12,1};
	double mtnui2[1][3]={-68,52,1};
	double mtnui3[1][3]={-38,12,1};
	
	
	double mt1[1][3];
	double mt2[1][3];
	double mt3[1][3];
	double mt11[1][3];
	double mt22[1][3];
	double mt33[1][3];
	double MTTTNui[3][3]=
			{
				{1,0,0},
				{0,1,0},
				{70,0,1}
			};
	setcolor(0);
	//Duong ke chan nui
	lineDDANguoiDung(-97,12,98,12,0);	
	for(int i=0;i<3;i++){
		lineDDANguoiDung(mtnui1[0][0],mtnui1[0][1],mtnui2[0][0],mtnui2[0][1],0);
		lineDDANguoiDung(mtnui2[0][0],mtnui2[0][1],mtnui3[0][0],mtnui3[0][1],0);
		
		setfillstyle(1,2);
		floodfillNguoiDung(mtnui2[0][0],mtnui2[0][1]-2,0);
		nhan2MaTran(mtnui1,MTTTNui,mt1,1,3,3);
		nhan2MaTran(mtnui2,MTTTNui,mt2,1,3,3);
		nhan2MaTran(mtnui3,MTTTNui,mt3,1,3,3);
		
		mtnui1[0][0]=mt1[0][0];
		mtnui1[0][1]=mt1[0][1];
		
		mtnui2[0][0]=mt2[0][0];
		mtnui2[0][1]=mt2[0][1];
		
		mtnui3[0][0]=mt3[0][0];
		mtnui3[0][1]=mt3[0][1];
	}
		lineDDANguoiDung(-97,50,-78,33,0);
		setfillstyle(1,2);
		floodfillNguoiDung(-95,45,0);
		lineDDANguoiDung(-54,32,-35,46,0);
		lineDDANguoiDung(-37,46,-7,30,0);
		setfillstyle(1,2);
		floodfillNguoiDung(-37,44,0);
		lineDDANguoiDung(12,40,36,50,0);
		lineDDANguoiDung(36,50,65,37,0);
		setfillstyle(1,2);
		floodfillNguoiDung(36,47,0);
		circleBresenhamNguoiDung(-15,42,3,0);
		setfillstyle(1,14);
		floodfillNguoiDung(-15,42,0);	
		
		lineDDANguoiDung(-97,-24,97,-24,0);
		setfillstyle(1,2);
		floodfillNguoiDung(90,-10,0);
		//giai phan cach
		lineDDANguoiDung(-97,-40,97,-40,0);
		setfillstyle(1,7);
		floodfillNguoiDung(0,-39,0);
		VePhanCach(-94,-34,0);
		VePhanCach(-54,-34,0);
		VePhanCach(-14,-34,0);
		VePhanCach(26,-34,0);
		VePhanCach(66,-34,0);
		setfillstyle(1,2);
		floodfillNguoiDung(0,-45,0);
		setfillstyle(1,11);
		floodfillNguoiDung(0,70,0);
	}

void veXe(int xdauXe1,int ydauXe1, int xdauXe2,int ydauXe2, int xdauXe11,int ydauXe11, int xdauXe22,int ydauXe22, int xthungXe1,int ythungXe1, int xthungXe2,int ythungXe2, int xbanhXe1,int ybanhXe1, int xbanhXe2,int ybanhXe2, int xbanhXe3,int ybanhXe3)
{
	Ve_HCN(xdauXe1,ydauXe1,xdauXe2,ydauXe2,8);
	setfillstyle(1,1);
	floodfillNguoiDung((xdauXe1+xdauXe2)/2,(ydauXe1+ydauXe2)/2,8);
	Ve_HCN(xdauXe11,ydauXe11,xdauXe22,ydauXe22,8);
	setfillstyle(1,1);
	floodfillNguoiDung((xdauXe11+xdauXe22)/2,(ydauXe11+ydauXe22)/2,8);
	Ve_HCN(xthungXe1,ythungXe1,xthungXe2,ythungXe2,8);
	setfillstyle(1,14);
	floodfillNguoiDung((xthungXe1+xthungXe2)/2,(ythungXe1+ythungXe2)/2,8);	
	circleBresenhamNguoiDung(xbanhXe1,ybanhXe1,3,3);
	circleBresenhamNguoiDung(xbanhXe2,ybanhXe2,3,3);
	circleBresenhamNguoiDung(xbanhXe3,ybanhXe3,3,3);
	setfillstyle(1,0);
	floodfillNguoiDung(xbanhXe1,ybanhXe1,3);
	floodfillNguoiDung(xbanhXe2,ybanhXe2,3);
	floodfillNguoiDung(xbanhXe3,ybanhXe3,3);
	circleBresenhamNguoiDung(xbanhXe1,ybanhXe1,3,8);
	circleBresenhamNguoiDung(xbanhXe2,ybanhXe2,3,8);
	circleBresenhamNguoiDung(xbanhXe3,ybanhXe3,3,8);
	circleBresenhamNguoiDung(xbanhXe1,ybanhXe1,1,15);
	circleBresenhamNguoiDung(xbanhXe2,ybanhXe2,1,15);
	circleBresenhamNguoiDung(xbanhXe3,ybanhXe3,1,15);
	lineDDANguoiDung(xdauXe1,ydauXe1,xdauXe11,ydauXe11,8);
	setfillstyle(1,15);
	floodfillNguoiDung((xdauXe1+xdauXe11+xdauXe22)/3,(ydauXe1+ydauXe11+ydauXe11)/3,8);
	
	
	settextstyle(DEFAULT_FONT,0,1);
	setcolor(15);
	setbkcolor(mauxanhgiongaokhoaccrush);
	//toa do banh xe truoc
		outtextxy(15,290+15*0,"Banh xe truoc");
		hienThiToaDo(xbanhXe1,ybanhXe1,0);
		// toa do banh xe giua
		outtextxy(15,290+15*1,"Banh xe giua");
		hienThiToaDo(xbanhXe2,ybanhXe2,1);
		
		//toa do banh xe sau
		outtextxy(15,290+15*2,"Banh xe sau");
		hienThiToaDo(xbanhXe3,ybanhXe3,2);
		//toa do cac diem dau xe
		outtextxy(15,290+15*3,"Toa do cac diem dau xe");
		outtextxy(15,290+15*4,"dau xe 1");
		hienThiToaDo(xdauXe11,ydauXe11,4);
		outtextxy(15,290+15*5,"dau xe 2");
		hienThiToaDo(xdauXe22,ydauXe22,5);
		outtextxy(15,290+15*6,"dau xe 3");
		hienThiToaDo(xdauXe1,ydauXe1,6);
		outtextxy(15,290+15*7,"dau xe 4");
		hienThiToaDo(xdauXe2,ydauXe2,7);
		
		//toa do cac diem thung xe
		outtextxy(15,290+15*8,"Toa do cac diem thung xe");
		outtextxy(15,290+15*9,"thung xe 1");
		hienThiToaDo(xthungXe1,ythungXe2,9);
		outtextxy(15,290+15*10,"thung xe 2");
		hienThiToaDo(xthungXe2,ythungXe1,10);
		outtextxy(15,290+15*11,"thung xe 3");
		hienThiToaDo(xthungXe1,ythungXe2,11);
		outtextxy(15,290+15*12,"thung xe 4");
		hienThiToaDo(xthungXe2,ythungXe2,12);
		
		int banKinhin= 1;
		int banKinhout=3;
		outtextxy(15,290+15*22,doiSangChar("Ban Kinh Trong Banh Xe: "+doiBanKinh(banKinhin)));
		outtextxy(15,290+15*23,doiSangChar("Ban Kinh Ngoai Banh Xe: "+doiBanKinh(banKinhout)));
}
void doiXungTamO(int x , int y, int &xKQ, int &yKQ)
{
	double mtDoiXung[3][3] ={
	{-1,0,0},{0,-1,0},{0,0,1}};
	double maTranDiem[1][3]={{x,y,1}};
	double maTranKQ[1][3];
	nhan2MaTran(maTranDiem,mtDoiXung,maTranKQ,1,3,3);
	xKQ=maTranKQ[0][0];
	yKQ=maTranKQ[0][1];
	
}
void doiXungOy(int x , int y, int &xKQ, int &yKQ)
{
	double mtDoiXung[3][3] ={
	{-1,0,0},{0,1,0},{0,0,1}};
	double maTranDiem[1][3]={{x,y,1}};
	double maTranKQ[1][3];
	nhan2MaTran(maTranDiem,mtDoiXung,maTranKQ,1,3,3);
	xKQ=maTranKQ[0][0];
	yKQ=maTranKQ[0][1];
}
void doiXungOx(int x , int y, int &xKQ, int &yKQ)
{
	double mtDoiXung[3][3] ={
	{1,0,0},{0,-1,0},{0,0,1}};
	double maTranDiem[1][3]={{x,y,1}};
	double maTranKQ[1][3];
	nhan2MaTran(maTranDiem,mtDoiXung,maTranKQ,1,3,3);
	xKQ=maTranKQ[0][0];
	yKQ=maTranKQ[0][1];
}
void doiXungXeQuaO(int xdauXe1,int ydauXe1, int xdauXe2,int ydauXe2, int xdauXe11,int ydauXe11, int xdauXe22,int ydauXe22, int xthungXe1,int ythungXe1, int xthungXe2,int ythungXe2, int xbanhXe1,int ybanhXe1, int xbanhXe2,int ybanhXe2, int xbanhXe3,int ybanhXe3)
{
	int xKQ1,yKQ1,xKQ2,yKQ2,xKQ11,yKQ11,xKQ22,yKQ22,xKQtx1,yKQtx1,xKQtx2,yKQtx2,xKQbx1,yKQbx1,xKQbx2,yKQbx2,xKQbx3,yKQbx3;
	doiXungTamO(xdauXe1,ydauXe1,xKQ1,yKQ1);
	doiXungTamO(xdauXe2,ydauXe2,xKQ2,yKQ2);
	doiXungTamO(xdauXe11,ydauXe11,xKQ11,yKQ11);
	doiXungTamO(xdauXe22,ydauXe22,xKQ22,yKQ22);
	doiXungTamO(xthungXe1,ythungXe1,xKQtx1,yKQtx1);
	doiXungTamO(xthungXe2,ythungXe2,xKQtx2,yKQtx2);
	doiXungTamO(xbanhXe1,ybanhXe1,xKQbx1,yKQbx1);
	doiXungTamO(xbanhXe2,ybanhXe2,xKQbx2,yKQbx2);
	doiXungTamO(xbanhXe3,ybanhXe3,xKQbx3,yKQbx3);

	veXe(xKQ1,yKQ1,xKQ2,yKQ2,xKQ11,yKQ11,xKQ22,yKQ22,xKQtx1,yKQtx1,xKQtx2,yKQtx2,xKQbx1,yKQbx1,xKQbx2,yKQbx2,xKQbx3,yKQbx3);
	
}
void doiXungXeOx(int xdauXe1,int ydauXe1, int xdauXe2,int ydauXe2, int xdauXe11,int ydauXe11, int xdauXe22,int ydauXe22, int xthungXe1,int ythungXe1, int xthungXe2,int ythungXe2, int xbanhXe1,int ybanhXe1, int xbanhXe2,int ybanhXe2, int xbanhXe3,int ybanhXe3)
{
	int xKQ1,yKQ1,xKQ2,yKQ2,xKQ11,yKQ11,xKQ22,yKQ22,xKQtx1,yKQtx1,xKQtx2,yKQtx2,xKQbx1,yKQbx1,xKQbx2,yKQbx2,xKQbx3,yKQbx3;
	doiXungOx(xdauXe1,ydauXe1,xKQ1,yKQ1);
	doiXungOx(xdauXe2,ydauXe2,xKQ2,yKQ2);
	doiXungOx(xdauXe11,ydauXe11,xKQ11,yKQ11);
	doiXungOx(xdauXe22,ydauXe22,xKQ22,yKQ22);
	doiXungOx(xthungXe1,ythungXe1,xKQtx1,yKQtx1);
	doiXungOx(xthungXe2,ythungXe2,xKQtx2,yKQtx2);
	doiXungOx(xbanhXe1,ybanhXe1,xKQbx1,yKQbx1);
	doiXungOx(xbanhXe2,ybanhXe2,xKQbx2,yKQbx2);
	doiXungOx(xbanhXe3,ybanhXe3,xKQbx3,yKQbx3);

	veXe(xKQ1,yKQ1,xKQ2,yKQ2,xKQ11,yKQ11,xKQ22,yKQ22,xKQtx1,yKQtx1,xKQtx2,yKQtx2,xKQbx1,yKQbx1,xKQbx2,yKQbx2,xKQbx3,yKQbx3);
	
}
void tinhTien1Diem(int x, int y, double trx, double trys, int &xKQ, int &yKQ)
{
	double maTranTinhTien[3][3]={
	{1,0,0},{0,1,0},{trx,trys,1}};
	double maTranDiem[1][3]={{x,y,1}};
	double maTranKQ[1][3];
	nhan2MaTran(maTranDiem,maTranTinhTien,maTranKQ,1,3,3);
	xKQ=maTranKQ[0][0];
	yKQ=maTranKQ[0][1];
}
void tinhTienXe(int i)
{
	double trx=-1;
	double trys=1;
	int xdauXe1=22; int ydauXe1=-14;
	int xdauXe2=32; int ydauXe2=-28;
	int xdauXe11=16; int ydauXe11=-20;
	int xdauXe22=22; int ydauXe22=-28;
	int xthungXe1=32; int ythungXe1=-8;
	int xthungXe2=92; int ythungXe2=-28;
	int xbanhXe1=24; int ybanhXe1=-28;
	int xbanhXe2=48; int ybanhXe2=-28;
	int xbanhXe3=76; int ybanhXe3=-28;
	int xKQ1,yKQ1,xKQ2,yKQ2,xKQ11,yKQ11,xKQ22,yKQ22,xKQtx1,yKQtx1,xKQtx2,yKQtx2,xKQbx1,yKQbx1,xKQbx2,yKQbx2,xKQbx3,yKQbx3;
	if(i>=0&&i<=13)
	{
		
		tinhTien1Diem(xdauXe1,ydauXe1,trx*i,trys,xKQ1,yKQ1);
		tinhTien1Diem(xdauXe2,ydauXe2,trx*i,trys,xKQ2,yKQ2);
		tinhTien1Diem(xdauXe11,ydauXe11,trx*i,trys,xKQ11,yKQ11);
		tinhTien1Diem(xdauXe22,ydauXe22,trx*i,trys,xKQ22,yKQ22);
		tinhTien1Diem(xthungXe1,ythungXe1,trx*i,trys,xKQtx1,yKQtx1);
		tinhTien1Diem(xthungXe2,ythungXe2,trx*i,trys,xKQtx2,yKQtx2);
		tinhTien1Diem(xbanhXe1,ybanhXe1,trx*i,trys,xKQbx1,yKQbx1);
		tinhTien1Diem(xbanhXe2,ybanhXe2,trx*i,trys,xKQbx2,yKQbx2);
		tinhTien1Diem(xbanhXe3,ybanhXe3,trx*i,trys,xKQbx3,yKQbx3);
		veXe(xKQ1,yKQ1,xKQ2,yKQ2,xKQ11,yKQ11,xKQ22,yKQ22,xKQtx1,yKQtx1,xKQtx2,yKQtx2,xKQbx1,yKQbx1,xKQbx2,yKQbx2,xKQbx3,yKQbx3);
	}
	else if(i<=26&&i>13)
	{
		i=i-13;
		i =13-i;
		
		tinhTien1Diem(xdauXe1,ydauXe1,trx*i,trys,xKQ1,yKQ1);
		tinhTien1Diem(xdauXe2,ydauXe2,trx*i,trys,xKQ2,yKQ2);
		tinhTien1Diem(xdauXe11,ydauXe11,trx*i,trys,xKQ11,yKQ11);
		tinhTien1Diem(xdauXe22,ydauXe22,trx*i,trys,xKQ22,yKQ22);
		tinhTien1Diem(xthungXe1,ythungXe1,trx*i,trys,xKQtx1,yKQtx1);
		tinhTien1Diem(xthungXe2,ythungXe2,trx*i,trys,xKQtx2,yKQtx2);
		tinhTien1Diem(xbanhXe1,ybanhXe1,trx*i,trys,xKQbx1,yKQbx1);
		tinhTien1Diem(xbanhXe2,ybanhXe2,trx*i,trys,xKQbx2,yKQbx2);
		tinhTien1Diem(xbanhXe3,ybanhXe3,trx*i,trys,xKQbx3,yKQbx3);
		doiXungXeQuaO(xKQ1,yKQ1,xKQ2,yKQ2,xKQ11,yKQ11,xKQ22,yKQ22,xKQtx1,yKQtx1,xKQtx2,yKQtx2,xKQbx1,yKQbx1,xKQbx2,yKQbx2,xKQbx3,yKQbx3);
	}
	else 
	{
		i =i-26;
		
		tinhTien1Diem(xdauXe1,ydauXe1,trx*i,trys,xKQ1,yKQ1);
		tinhTien1Diem(xdauXe2,ydauXe2,trx*i,trys,xKQ2,yKQ2);
		tinhTien1Diem(xdauXe11,ydauXe11,trx*i,trys,xKQ11,yKQ11);
		tinhTien1Diem(xdauXe22,ydauXe22,trx*i,trys,xKQ22,yKQ22);
		tinhTien1Diem(xthungXe1,ythungXe1,trx*i,trys,xKQtx1,yKQtx1);
		tinhTien1Diem(xthungXe2,ythungXe2,trx*i,trys,xKQtx2,yKQtx2);
		tinhTien1Diem(xbanhXe1,ybanhXe1,trx*i,trys,xKQbx1,yKQbx1);
		tinhTien1Diem(xbanhXe2,ybanhXe2,trx*i,trys,xKQbx2,yKQbx2);
		tinhTien1Diem(xbanhXe3,ybanhXe3,trx*i,trys,xKQbx3,yKQbx3);
		doiXungTamO(xKQ1,yKQ1,xKQ1,yKQ1);
		doiXungTamO(xKQ2,yKQ2,xKQ2,yKQ2);
		doiXungTamO(xKQ11,yKQ11,xKQ11,yKQ11);
		doiXungTamO(xKQ22,yKQ22,xKQ22,yKQ22);
		doiXungTamO(xKQtx1,yKQtx1,xKQtx1,yKQtx1);
		doiXungTamO(xKQtx2,yKQtx2,xKQtx2,yKQtx2);
		doiXungTamO(xKQbx1,yKQbx1,xKQbx1,yKQbx1);
		doiXungTamO(xKQbx2,yKQbx2,xKQbx2,yKQbx2);
		doiXungTamO(xKQbx3,yKQbx3,xKQbx3,yKQbx3);

		doiXungXeOx(xKQ1,yKQ1,xKQ2,yKQ2,xKQ11,yKQ11,xKQ22,yKQ22,xKQtx1,yKQtx1,xKQtx2,yKQtx2,xKQbx1,yKQbx1,xKQbx2,yKQbx2,xKQbx3,yKQbx3);
	}
		
	
}

void xuLi2D2(){
	boolean kt=false;
	while(true){
		for(int i=0;i<=40;i++)
		{
		int page=0;
		setactivepage(page);
		setvisualpage(1-page);
		setGiaoDienHoatDong(1);
		canhVat();
		tinhTienXe(i);
		tinhTienTenLua(i);
		
		setMenu();
		button a[11];
		taoMangButton(a);
		drawMenuButton(a);
		doiMauButton(a[1],mauxanhlachuoi);
		setcolor(15);
		veHeTruc();
		setcolor(15);
		settextstyle(DEFAULT_FONT,0, 1);	
		setbkcolor(mauxanhgiongaokhoaccrush);
		outtextxy(15,275,"VAT");
		outtextxy(150,275,"X");
		outtextxy(233,275,"Y");
		
		if(ismouseclick(WM_LBUTTONUP))
			{
				int xtam; int ytam;
				getmouseclick(WM_LBUTTONUP,xtam,ytam);
				clearmouseclick(WM_LBUTTONUP);
				if(xtam>=155&&xtam<=280&&ytam>=27&&ytam<=97)
				{
					kt=true;
					
					setactivepage(NULL);
					setvisualpage(NULL);
					setDoThi();
					setThongTin();
					break;
				}
				else
				{
					cout<<xtam<<"\t t"<<ytam<<endl;
				}
			}
		
		page=1-page;
		delay(50);
		}
		if(kt==true)
		{
			break;
		}
		}
}
