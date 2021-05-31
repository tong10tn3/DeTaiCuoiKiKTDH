#include "hamCoSo.h"
#include "VeGiaoDien.h"
#include<graphics.h>
#include<iostream>
#include<math.h>
#include <time.h>
#include <sstream>
#include "ve3D1.h"

using namespace std;

int banKinhMatTroi=10;
int banKinhTraiDat=4;
int mauMatTroi=12;// mau cam
int mauTraiDat=2;//mau Xanh la
int mauMatTrang=14;//mau Vang
int banKinhMatTrang=3;
int mauCanhVeTinh=9;
int mauTamVeTinh=13;
int banKinhVeTinh=5;
int mauDuoiThienThach1=9;
int mauDuoiThienThach2=10;
int banKinhThienThach=3;
int mauThienThach=6;
int mauNgoaiThienThach=12;



void veMatTroi(int xTam, int yTam)
{
	circleBresenhamNguoiDung(xTam,yTam,banKinhMatTroi,mauMatTroi);
	setfillstyle(1,mauMatTroi);
	int xKQ,yKQ;
	doiNguoiDungsangMayTinh(xTam,yTam,790,360,xKQ,yKQ);
	floodfill(xKQ,yKQ,mauMatTroi);
}
void veTraiDat(int xTam, int yTam)
{
	setfillstyle(1,11);
	elipseNguoiDung(xTam,yTam,9,2,11);
	floodfillNguoiDung(xTam,yTam,11); 
	
	circleBresenhamNguoiDung(xTam,yTam,banKinhTraiDat,mauTraiDat);
	setfillstyle(1,mauTraiDat);
	floodfillNguoiDung(xTam,yTam,mauTraiDat); 
	
	
}
void veMatTrang(int xTam, int yTam)
{
	circleBresenhamNguoiDung(xTam,yTam,banKinhMatTrang,mauMatTrang);
	setfillstyle(1,mauMatTrang);
	floodfillNguoiDung(xTam,yTam,mauMatTrang); 
}

// A cap mxn * B cap nxp = C cap mxp
void nhan2MaTran(double A[][3], double B[][3], double C[][3], int m, int n, int p)
{
	for(int i=0;i<m;i++)
	{
		for(int k=0;k<p;k++)
		{
			C[i][k]=0;
			for(int j=0;j<n;j++)
			{
				C[i][k]=C[i][k]+A[i][j]*B[j][k];
			}
		}
	}
}

void maTranQo(double Qo[][3], double gocQuay)
{
	Qo[0][0]= cos(gocQuay);
	Qo[0][1]= sin(gocQuay);
	Qo[0][2]= 0;
	
	Qo[1][0]= -sin(gocQuay);
	Qo[1][1]= cos(gocQuay);
	Qo[1][2]= 0;
	
	Qo[2][0]=0;
	Qo[2][1]= 0;
	Qo[2][2]= 1;
	

}

void randomSao(int soLuong, int XSao[], int YSao[])
{
	srand((unsigned int) time(0));
	int i=0;
    while(i<soLuong){
    	
        int x =  rand() % (1274 - 306 + 1) + 306; 
        int y =  rand() % (714 - 6 + 1) + 6 ;
        //int c = rand()%16;
        //putpixel(x,y,0);
        XSao[i]=x;
        YSao[i]=y;
        i++;
    }
    
}

void veBauTroiSao(int soLuong, int XSao[], int YSao[] )
{
	for(int i=0;i<soLuong;i++)
	{
		putpixel(XSao[i],YSao[i],15);
		
	}
}
char* doiSangChar(string text)
{
	char *textC1 = new char[text.length()+1];
	strcpy(textC1,text.c_str());
	return textC1;
}
string doiBanKinh(int x)
{
	ostringstream convertX;
	convertX<<x;
	string xDoi=convertX.str();
	return xDoi;
}
string doiToaDo(float x)
{
	ostringstream convertX;
	convertX<<x;
	string xDoi=convertX.str();
	return xDoi;
}
void PhepXoay1Diem(int xDiem,int yDiem,int xGoc,int yGoc, int gocQuay,int &xMoi,int &yMoi)
{
	double gocQuayNew=gocQuay*3.14159/180.0;
	double Qo[3][3];
	maTranQo(Qo,gocQuayNew);
	double diemCu[1][3] ={{xDiem,yDiem,1}};
	
	double maTranTTVeO[3][3]=
	{
		{1,0,0	},
		{0,1,0	},
		{-xGoc, -yGoc, 1}
	};
	
	double maTranTTVeLai[3][3]
	{
		{1,0,0	},
		{0,1,0	},
		{xGoc, yGoc, 1}
	};
	double KQ1[1][3];
	double KQ2[1][3];
	double KQ3[1][3];
			
	nhan2MaTran(diemCu,maTranTTVeO,KQ1,1,3,3);
	nhan2MaTran(KQ1,Qo,KQ2,1,3,3);
	nhan2MaTran(KQ2,maTranTTVeLai,KQ3,1,3,3);
	xMoi=KQ3[0][0];
	yMoi=KQ3[0][1];	
}
void veThienThach(int x, int y, int gocQuay,int mauDuoi)
{
	int doDaiDuoi=15;
	int doRongVanh=3;
	circleBresenhamNguoiDung(x,y,banKinhThienThach+doRongVanh,7);
	setfillstyle(SOLID_FILL,mauNgoaiThienThach);
	floodfillNguoiDung(x,y,7);

	circleBresenhamNguoiDung(x,y,banKinhThienThach,7);
	setfillstyle(SOLID_FILL,mauThienThach);
	floodfillNguoiDung(x,y,7);
	
	int x1=x-banKinhThienThach-doDaiDuoi;
	int y1=y-banKinhThienThach-doRongVanh;
	
	int x2=x;
	int y2=y-banKinhThienThach;
	
	int x3=x-banKinhThienThach-doDaiDuoi;
	int y3=y+banKinhThienThach+doRongVanh;
	
	int x4=x;	
	int y4=y+banKinhThienThach;
	
	int x5=x-(3*(banKinhThienThach+doDaiDuoi)/4);
	int y5=y;
	
	int x6= x5+5;
	int y6=y5;
	

	
	int x1New;
	int y1New;
	int x3New;
	int y3New;
	int x5New;
	int y5New;
	int x6New;
	int y6New;

	PhepXoay1Diem(x1,y1,x,y,-gocQuay,x1New,y1New);
	PhepXoay1Diem(x3,y3,x,y,-gocQuay,x3New,y3New);
	PhepXoay1Diem(x5,y5,x,y,-gocQuay,x5New,y5New);
	PhepXoay1Diem(x6,y6,x,y,-gocQuay,x6New,y6New);
	
	
	if(gocQuay<240&&gocQuay>130)
	{
		setcolor(15);
		lineDDANguoiDung(x1New,y1New,x4,y4,7);
		lineDDANguoiDung(x3New,y3New,x2,y2,7);
		lineDDANguoiDung(x1New,y1New,x5New,y5New,7);
		lineDDANguoiDung(x3New,y3New,x5New,y5New,7);
	}
	else
	{
		setcolor(15);
		lineDDANguoiDung(x1New,y1New,x2+2,y2,7);
		lineDDANguoiDung(x3New,y3New,x4+2,y4,7);
		lineDDANguoiDung(x1New,y1New,x5New,y5New,7);
		lineDDANguoiDung(x3New,y3New,x5New,y5New,7);
	}
	setfillstyle(SOLID_FILL,mauDuoi);
	floodfillNguoiDung(x6New,y6New,7);
	//ghi thong tin
	setcolor(15);
	setbkcolor(mauxanhgiongaokhoaccrush);
	settextstyle(DEFAULT_FONT,0, 1);
	outtextxy(100,475,"THIEN THACH");
	float xKQ,yKQ;
	
	outtextxy(15,490,doiSangChar("X= "+doiToaDo(x)));
	outtextxy(15,505,doiSangChar("Y= "+doiToaDo(y)));
	
	outtextxy(130,490,doiSangChar("BK in= "+doiBanKinh(banKinhThienThach)));
	outtextxy(220,490,doiSangChar("BK out= "+doiBanKinh(banKinhThienThach+doRongVanh)));

	outtextxy(15,520,doiSangChar("X1= "+doiToaDo(x1)));
	outtextxy(15,535,doiSangChar("Y1= "+doiToaDo(y1)));

	outtextxy(130,520,doiSangChar("X2= "+doiToaDo(x5)));
	outtextxy(130,535,doiSangChar("Y2= "+doiToaDo(y5)));

	outtextxy(220,520,doiSangChar("X3= "+doiToaDo(x3)));
	outtextxy(220,535,doiSangChar("Y3= "+doiToaDo(y3)));
	
}
void veHeTruc()
{
	setcolor(5);
	lineDDA1DV(790,6,790,714,5);
	lineDDA1DV(306,360,1274,360,5);
	setcolor(15);
}

void ghiToaDo( int x, int y, int i)
{
	int xO=790;
	int yO=360;
	
	int gocTen=260;
	float toaDoX= roundf(((x-xO)/5.0) * 100) / 100;
	float toaDoY= roundf(((y-yO)/5.0)* 100) / -100;

	ostringstream convertX;
	convertX<<toaDoX;
	string toaDoXString=convertX.str();
	char* toaDoXChar = new char[toaDoXString.size()];
	copy(toaDoXString.begin(), toaDoXString.end(), toaDoXChar);
	toaDoXChar[toaDoXString.size()] = '\0';
	
	settextstyle(DEFAULT_FONT,0, 1);
	outtextxy(150,gocTen+15*i,toaDoXChar);
	settextstyle(DEFAULT_FONT,0,1);
		
		
		
	ostringstream convertY;
	convertY<<toaDoY;
	string toaDoYString=convertY.str();
		
	char* toaDoYChar = new char[toaDoYString.size()];
	copy(toaDoYString.begin(), toaDoYString.end(), toaDoYChar);
	toaDoYChar[toaDoYString.size()] = '\0';
	settextstyle(DEFAULT_FONT,0, 1);
	outtextxy(233,gocTen+15*i,toaDoYChar);
	settextstyle(DEFAULT_FONT,0,1);
}


void tinhTienThienThach1(int i)
{
	int xDau=-78; int yDau=52;
	int xCuoi=22; int yCuoi=-68;
	
	double tanA=(yCuoi-yDau)/(xCuoi-xDau);
	double gocQuay=360- atan(tanA)*(180/3.14159);
	
	double maTranThienThach[1][3]={{xDau,yDau,1}};
	
	double maTranTT[3][3]={
		{1,0,0	},
		{0,1,0	},
		{(xCuoi-xDau)*i/31, (yCuoi-yDau)*i/31, 1}
	};
	double KQ[1][3];
	nhan2MaTran(maTranThienThach,maTranTT,KQ,1,3,3);
	veThienThach(KQ[0][0],KQ[0][1],gocQuay,mauDuoiThienThach1);
	setbkcolor(mauxanhgiongaokhoaccrush);
	setcolor(15);

}
void tinhTienThienThach2(int i)
{
	int xDau=17; int yDau=-60;
	int xCuoi=34; int yCuoi=61;
	
	double tanA=(yCuoi-yDau)/(xCuoi-xDau);
	double gocQuay=360.0- atan(tanA)*(180/3.14159);
	
	double maTranThienThach[1][3]={{xDau,yDau,1}};
	
	double maTranTT[3][3]={
		{1,0,0	},
		{0,1,0	},
		{(xCuoi-xDau)*(i-41)/28, (yCuoi-yDau)*(i-41)/28, 1}
	};
	double KQ[1][3];
	nhan2MaTran(maTranThienThach,maTranTT,KQ,1,3,3);
	veThienThach(KQ[0][0],KQ[0][1],gocQuay,mauDuoiThienThach2);
	setbkcolor(mauxanhgiongaokhoaccrush);
	setcolor(15);

	
}

void veVeTinh(int x , int y)
{
	setcolor(mauCanhVeTinh);
	circle(x,y,banKinhVeTinh);
	
	setfillstyle(SOLID_FILL,mauCanhVeTinh);
	line(x,y-banKinhVeTinh,x+3*banKinhVeTinh,y-4*banKinhVeTinh);
	
	line(x+banKinhVeTinh,y,x+4*banKinhVeTinh,y-3*banKinhVeTinh);
	line(x+3*banKinhVeTinh,y-4*banKinhVeTinh,x+4*banKinhVeTinh+1,y-3*banKinhVeTinh+1);

	floodfill(x+2*banKinhVeTinh,y-2*banKinhVeTinh, mauCanhVeTinh);
	
	line(x,y-banKinhVeTinh,x-4*banKinhVeTinh,y+3*banKinhVeTinh);
	line(x+banKinhVeTinh,y,x-3*banKinhVeTinh,y+4*banKinhVeTinh);
	line(x-4*banKinhVeTinh,y+3*banKinhVeTinh,x-3*banKinhVeTinh+1,y+4*banKinhVeTinh+1);
	floodfill(x-2*banKinhVeTinh,y+2*banKinhVeTinh,mauCanhVeTinh);
	
	setcolor(mauTamVeTinh);
	setfillstyle(SOLID_FILL,mauTamVeTinh);
	pieslice(x,y,0,360,banKinhVeTinh);

	
	setbkcolor(mauxanhgiongaokhoaccrush);
	settextstyle(DEFAULT_FONT,0,1);
	setcolor(15);
	float xKQ,yKQ;
	doiMayTinhSangNguoiDung(x+3*banKinhVeTinh,y-4*banKinhVeTinh,790,360,xKQ,yKQ);
	outtextxy(220,400+15,doiSangChar("X1= "+doiToaDo(xKQ)));
	outtextxy(220,400+30,doiSangChar("Y1= "+doiToaDo(yKQ)));
	
	doiMayTinhSangNguoiDung(x+4*banKinhVeTinh,y-3*banKinhVeTinh,790,360,xKQ,yKQ);
	outtextxy(15,400+45,doiSangChar("X2= "+doiToaDo(xKQ)));
	outtextxy(15,400+60,doiSangChar("Y2= "+doiToaDo(yKQ)));
	
	doiMayTinhSangNguoiDung(x-4*banKinhVeTinh,y+3*banKinhVeTinh,790,360,xKQ,yKQ);
	outtextxy(130,400+45,doiSangChar("X3= "+doiToaDo(xKQ)));
	outtextxy(130,400+60,doiSangChar("Y3= "+doiToaDo(yKQ)));
	
	doiMayTinhSangNguoiDung(x-3*banKinhVeTinh,y+4*banKinhVeTinh,790,360,xKQ,yKQ);
	outtextxy(220,400+45,doiSangChar("X4= "+doiToaDo(xKQ)));
	outtextxy(220,400+60,doiSangChar("Y4= "+doiToaDo(yKQ)));
}

void veHanhTinhKhac()
{
	int x1=-78;
	int y1=-48;
	
	elipseNguoiDung(x1,y1,9,2,6);
	setfillstyle(SOLID_FILL,6);
	floodfillNguoiDung(x1,y1,6);
	circleBresenhamNguoiDung(x1,y1,4,14);
	setfillstyle(SOLID_FILL,14);
	floodfillNguoiDung(x1,y1,14);
	
	
	int x2=72;
	int y2=58;
	elipseNguoiDung(x2,y2,9,2,12);
	setfillstyle(SOLID_FILL,12);
	floodfillNguoiDung(x2,y2,12);
	circleBresenhamNguoiDung(x2,y2,4,1);
	setfillstyle(SOLID_FILL,1);
	floodfillNguoiDung(x2,y2,1);
	
	int x4=80;
	int y4=-4;
	elipseNguoiDung(x4,y4,9,2,10);
	setfillstyle(SOLID_FILL,10);
	floodfillNguoiDung(x4,y4,10);
	circleBresenhamNguoiDung(x4,y4,4,2);
	setfillstyle(SOLID_FILL,2);
	floodfillNguoiDung(x4,y4,2);
	
	int x5= 76;
	int y5= -46;
	elipseNguoiDung(x5,y5,9,2,9);
	setfillstyle(SOLID_FILL,9);
	floodfillNguoiDung(x5,y5,9);
	circleBresenhamNguoiDung(x5,y5,4,3);
	setfillstyle(SOLID_FILL,3);
	floodfillNguoiDung(x5,y5,3);
}


void ghiThongTin(int x,int y,int a, int b, int BK, int i, string tenVat)
{

	int cach=40;
	int gocTen=280;
	
	outtextxy(100,gocTen+i*cach,doiSangChar(tenVat));


	ostringstream convertX;
	convertX<<x;
	string toaDoXString="X= "+convertX.str();
	char* toaDoXChar = new char[toaDoXString.size()];
	copy(toaDoXString.begin(), toaDoXString.end(), toaDoXChar);
	toaDoXChar[toaDoXString.size()] = '\0';
	
	settextstyle(DEFAULT_FONT,0, 1);
	outtextxy(15,gocTen+i*cach+15,toaDoXChar);
	settextstyle(DEFAULT_FONT,0,1);
	
	ostringstream convertY;
	convertY<<y;
	string toaDoYString="Y= "+convertY.str();
		
	char* toaDoYChar = new char[toaDoYString.size()];
	copy(toaDoYString.begin(), toaDoYString.end(), toaDoYChar);
	toaDoYChar[toaDoYString.size()] = '\0';
	settextstyle(DEFAULT_FONT,0, 1);
	outtextxy(15,gocTen+i*cach+30,toaDoYChar);
	settextstyle(DEFAULT_FONT,0,1);

	outtextxy(130,gocTen+i*cach+15,doiSangChar("BK= "+doiBanKinh(BK)));
	
	if(a!=-1)
	{
		outtextxy(230,gocTen+i*cach+15,doiSangChar("a= "+doiBanKinh(a)));
		outtextxy(230,gocTen+i*cach+30,doiSangChar("b= "+doiBanKinh(b)));
	}

}

void xuLi2D1()
{
	int xTraiDat=0; int yTraiDat=46;
	int xMatTrang=0; int yMatTrang=70;
	
	int XSao[500];
	int YSao[500];
	int soLuong=500;
	randomSao(soLuong,XSao,YSao);
	int page=0;
	bool kt=false;
	while(true)
	{
		if(kt==true)
		{
			break;
		}
		double Qo[3][3];
		double Qo_MT[3][3];
		double Qo_VT[3][3];
		int k=0;
		//TRAI DAT XOAY
		for(double i=-0.0436*2;i>-6.29;i-=0.0436*2)
		{
			setactivepage(page);
			setvisualpage(1-page);
			
			
			//TRAIDAT
			double gocQuay=i;
			int xTraiDats;
			int yTraiDats;
			PhepXoay1Diem(xTraiDat,yTraiDat,0,0,gocQuay*180.0/3.14159,xTraiDats,yTraiDats);
	
			//MATTRANG
			double gocQuayMT=-i*5;
			int xMatTrangs;
			int yMatTrangs;
			PhepXoay1Diem(xMatTrang,yMatTrang,xTraiDat,yTraiDat,gocQuayMT*180.0/3.14159,xMatTrangs,yMatTrangs);
			
			int xMatTrangs1;
			int yMatTrangs1;
			PhepXoay1Diem(xMatTrangs,yMatTrangs,0,0,gocQuay*180.0/3.14159,xMatTrangs1,yMatTrangs1);

			//VE 
			setGiaoDienHoatDong(0);
			
				//QUYDAO
			setcolor(15);
			circleBresenham(790,360,230,15);

			veBauTroiSao(soLuong,XSao,YSao);
			veMatTroi(0,0);
			veTraiDat(xTraiDats,yTraiDats);
			veMatTrang(xMatTrangs1,yMatTrangs1);
			
			
			if(k<=31)
			{
				tinhTienThienThach1(k);	
			}
			else if( k>=41)
			{
				tinhTienThienThach2(k);
			}
			k++;
			
			veHanhTinhKhac();
			
			
			int gocTen=280;
			int gocX;
			int gocY;
			setcolor(15);
			settextstyle(DEFAULT_FONT,0, 1);
			
			setbkcolor(mauxanhgiongaokhoaccrush);

			//MAT TROI
			
			outtextxy(100,gocTen,doiSangChar("MAT TROI"));
			outtextxy(15,gocTen+15,"X= 0");
			outtextxy(15,gocTen+30,"Y= 0");
			outtextxy(150,gocTen+15,doiSangChar("BK:"+doiBanKinh(banKinhMatTroi)));
			
			//TRAI DAT
			ghiThongTin(xTraiDats,yTraiDats,9,2,banKinhTraiDat,1,"TRAI DAT");
			
			//MAT TRANG
			ghiThongTin(xMatTrangs1,yMatTrangs1,-1,-1,banKinhMatTrang,2,"MAT TRANG");

			//HE TRUC TOA DO
			setcolor(5);
			lineDDA1DV(790,6,790,714,5);
			lineDDA1DV(306,360,1274,360,5);
			setcolor(15);
			
		
			
			
			if(ismouseclick(WM_LBUTTONUP))
			{
				int xtam; int ytam;
				getmouseclick(WM_LBUTTONUP,xtam,ytam);
				clearmouseclick(WM_LBUTTONUP);
				if(xtam>=25&&xtam<=150&&ytam>=27&&ytam<=97)
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
					cout<<xtam<<"\t"<<ytam<<endl;
				}
			}
			page=1-page;
			delay(50);
		}
		
			
	}
}
























