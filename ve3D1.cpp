#include "hamCoSo.h"
#include "VeGiaoDien.h"
#include<graphics.h>
#include<iostream>
#include<math.h>
#include <sstream>
#define Round(a) (int)(a+0.5) 
using namespace std;
char TD[24] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S',
'T' };
struct toado2D
{
	int x, y;
};

struct toado3D
{
	int x, y, z;
};
toado2D tam = { 747, 297 };
toado2D ratoadouser(toado2D P) {
	toado2D ketqua;
	ketqua.x = P.x - tam.x;
	ketqua.y = tam.y - P.y;
	return ketqua;
}


void VeHinhChuNhatVien(int x, int y, int z, int b, int color)
{
	setfillstyle(SOLID_FILL, color);
	setcolor(BLACK);
	rectangle(x, y, z, b);
	setbkcolor(color);
	bar(x + 1, y + 1, z, b);
}
/*void LineDDA(int x1, int y1, int x2, int y2) { 
	float x = x1;
	float y = y1;
	float m = abs(float(x2 - x1) / (y2 - y1));
	putpixel(x, round(y), BLACK);
	if (x1 < x2)
	{
		if (m < 1)
		{
			if (y2 > y1)
			{
				m = float(x2 - x1) / (y2 - y1);
				for (int i = y1; i<y2; i++)
				{
					y++;
					x += m;
					putpixel(round(x), y, BLACK);
				}
			}
			else
			{
				m = float(x2 - x1) / (y1 - y2);
				for (int i = y2; i<y1; i++)
				{
					y--;
					x += m;
					putpixel(round(x), y, BLACK);
				}
			}
		}
		else
		{
			m = float(y2 - y1) / (x2 - x1);
			for (int i = x1; i<x2; i++)
			{
				x++;
				y += m;
				putpixel(x, round(y), BLACK);
			}
		}

	}
	else if (x1 > x2) {
		if (m < 1)
		{
			if (y2 > y1)
			{
				for (int i = y1; i<y2; i++)
				{
					y++;
					x -= m;
					cout << x << endl;
					putpixel(round(x), y, BLACK);
				}
			}
			else
			{
				m = float(x1 - x2) / (y1 - y2);
				for (int i = y2; i<y1; i++)
				{
					y--;
					x -= m;
					putpixel(round(x), y, BLACK);
				}

			}
		}
		else
		{
			m = float(y1 - y2) / (x1 - x2);
			for (int i = x2; i<x1; i++)
			{
				x--;
				y -= m;
				putpixel(x, round(y), BLACK);
			}
		}
	}
	else if (x1 == x2)
	{
		if (y2 > y1)
		{
			m = float(x2 - x1) / (y2 - y1);
			//putpixel(y, round(x), BLACK);
			for (int i = y1; i < y2; i++)
			{
				y++;
				x += m;
				putpixel(round(x), y, BLACK);
			}
		}
		else if (y2<y1)
		{
			m = float(x1 - x2) / (y1 - y2);
			//putpixel(y, round(x), BLACK);
			for (int i = y2; i < y1; i++)
			{
				y--;
				x += m;
				putpixel(round(x), y, BLACK);
			}
		}
	}

}*/
void LineDDA(int x1, int y1, int x2, int y2){       // thuat toan DDA
    int  Dx = x2 - x1, Dy = y2 - y1;  
    float x_inc , y_inc;
    float step=max(abs(Dx),abs(Dy));
    x_inc=Dx/step;
    y_inc=Dy/step;
    float x=x1, y=y1;
    putpixel(x, y, 0);
      
    int k=1;
    while(k <=step){
        k++;
         
        x += x_inc;
        y += y_inc;
        
        putpixel(Round(x),Round(y),9);
         
    }
}
void HeTrucXYZ()
{
	//LineDDAan(195, 297, 747, 297);//195,0,1298,594,8 747
	line(747, 297, 1270, 297);//Oy
	line(747, 0, 747, 297);//Ox
	line(747, 297, 450, 594);//Oz
	putpixel(747, 297, RED);//diem giua
	int toadoduong = 0;
	int toadoam = 0;
	char td[100];
	setcolor(RED);
	setfillstyle(SOLID_FILL, 8);
	setcolor(7);
	setbkcolor(8);
	settextstyle(10, 0, 1);
	_itoa(toadoduong, td, 10);
	int luiam = 697;
	//strcpy(td,);
	outtextxy(749, 302, td);
	for (int i = 797; i <= 1248; i = i + 50)//truc x
	{
		toadoduong += 50;
		line(i, 295, i, 300);
		_itoa(toadoduong, td, 10);
		outtextxy(i - 2, 302, td);
		
	}
	strcpy(td, "y");
	outtextxy(1238, 270, td);
	//297
	luiam = 247;
	toadoam = toadoduong = 0;
	
	for (int i = 347; i <= 594; i = i + 50)//truc y
	{

		toadoam += 50;
		LineDDA(745, luiam, 755, luiam);
		_itoa(toadoam, td, 10);
		outtextxy(755, luiam - 5, td);
		luiam = luiam - 50;

	}
	strcpy(td, "x");
	outtextxy(tam.x-20, 15, td);
	toadoduong = 0;
	luiam = 712;
	for (int i = 332; i <= 594; i += 35)// truc z line(747, 297, 450, 594);
	{
		toadoduong += 50;
		line(luiam-2,i-2, luiam+2,i+2);
		_itoa(toadoduong, td, 10);
		outtextxy (luiam + 4, i + 4, td);
		luiam -= 35;
	}
	strcpy(td, "z");
	outtextxy(712-35*7-15, 332+35*7-15, td);
	settextstyle(3, 0, 1);
	
}
void textWrite(int &x, int &y, char s[], int color) {//viet tiep
													 //settextstyle(0,0,1);
	setcolor(BLACK);
	setbkcolor(color);
	outtextxy(x, y, s);
	x += textwidth(s);

}
void textWriteRemove(int &x, int &y, char s[]) {//lui lai khi xoa
												//settextstyle(0,0,1);
	setcolor(7);
	setbkcolor(7);
	x -= textwidth(s);
	outtextxy(x, y, s);
}
void textReadnumber(int &x, int &y, char s[]) {//dua du lieu kieu so vao
	char ch[2];
	char temp;
	ch[1] = 0;
	int i = 0;
	while (1) {
		fflush(stdin);
		temp = getch();
		if (temp >= '0' && temp <= '9') {
			ch[0] = temp;
			textWrite(x, y, ch, 7);
			s[i++] = ch[0];
		}
		else if (temp == 8) {
			textWriteRemove(x, y, ch);
			i--;
			setcolor(WHITE);
		}
		else if (temp == 13) break;
	}
	s[i] = 0;
}
void textWriteln(int &x, int &y, char s[]) {//xuong hang
	outtextxy(x, y, s);
	x = 50;
	y += 25;
}
/*void LineDDAan(int x1, int y1, int x2, int y2) { //ve duong thang an ----------
	float x = x1;
	float y = y1;
	float m = abs(float(x2 - x1) / (y2 - y1));
	int dem = 0;
	putpixel(x, round(y), BLACK);
	if (x1 < x2)
	{
		if (m < 1)
		{
			if (y2 > y1)
			{
				m = float(x2 - x1) / (y2 - y1);
				for (int i = y1; i<y2; i++)
				{
					y++;
					x += m;
					dem++;
					if (dem == 3)
					{
						putpixel(round(x), y, 8);
						dem = 0;
					}
					else
					{
						putpixel(round(x), y, BLACK);
					}
				}
			}
			else
			{
				m = float(x2 - x1) / (y1 - y2);
				for (int i = y2; i<y1; i++)
				{
					y--;
					x += m;
					dem++;
					if (dem == 3)
					{
						putpixel(round(x), y, 8);
						dem = 0;
					}
					else
					{
						putpixel(round(x), y, BLACK);
					}
				}
			}
		}
		else
		{
			m = float(y2 - y1) / (x2 - x1);
			for (int i = x1; i<x2; i++)
			{
				x++;
				y += m;	
				dem++;
				if (dem == 3)
				{
					putpixel(round(x), y, 8);
					dem = 0;
				}
				else
				{
					putpixel(round(x), y, BLACK);
				}
			}
		}

	}
	else if (x1 > x2) {
		if (m < 1)
		{
			if (y2 > y1)
			{
				for (int i = y1; i<y2; i++)
				{
					y++;
					x -= m;
					//cout << x << endl;
					dem++;
					if (dem == 3)
					{
						putpixel(round(x), y, 8);
						dem = 0;
					}
					else
					{
						putpixel(round(x), y, BLACK);
					}
				}
			}
			else
			{
				m = float(x1 - x2) / (y1 - y2);
				for (int i = y2; i<y1; i++)
				{
					y--;
					x -= m;
					dem++;
					if (dem == 3)
					{
						putpixel(round(x), y, 8);
						dem = 0;
					}
					else
					{
						putpixel(round(x), y, BLACK);
					}
				}

			}
		}
		else
		{
			m = float(y1 - y2) / (x1 - x2);
			for (int i = x2; i<x1; i++)
			{
				x--;
				y -= m;
				dem++;
				if (dem == 3)
				{
					putpixel(round(x), y, 8);
					dem = 0;
				}
				else
				{
					putpixel(round(x), y, BLACK);
				}
			}
		}
	}
	else if (x1 == x2)
	{
		if (y2 > y1)
		{
			m = float(x2 - x1) / (y2 - y1);
			putpixel(y, round(x), BLACK);
			for (int i = y1; i < y2; i++)
			{
				y++;
				x += m;
				dem++;
				if (dem == 3)
				{
					putpixel(round(x), y, 8);
					dem = 0;
				}
				else
				{
					putpixel(round(x), y, BLACK);
				}
			}
		}
		else if (y2<y1)
		{
			m = float(x1 - x2) / (y1 - y2);
			putpixel(y, round(x), BLACK);
			for (int i = y2; i < y1; i++)
			{
				y--;
				x += m;
				dem++;
				if (dem == 3)
				{
					putpixel(round(x), y, 8);
					dem = 0;
				}
				else
				{
					putpixel(round(x), y, BLACK);
				}
			}
		}
	}
}*/
void LineDDAan(int x1, int y1, int x2, int y2)
{
	int  Dx = x2 - x1, Dy = y2 - y1;  
    float x_inc , y_inc;
    float step=max(abs(Dx),abs(Dy));
    x_inc=Dx/step;
    y_inc=Dy/step;
    float x=x1, y=y1;
    putpixel(x, y, 0);
      
    int k=1;
    int soNetPutPixel=0;
    int soNetKhongPutPixel=0;
    int soNetVe=10;
    int soNetAn=5;
    while(k <=step)
	{
        k++;
         
        x += x_inc;
        y += y_inc;
        
        if(soNetPutPixel<soNetVe&&soNetKhongPutPixel==0)
        {
        	putpixel(Round(x),Round(y),9);
        	soNetPutPixel++;
		}
		else if(soNetPutPixel==soNetVe&&soNetKhongPutPixel<soNetAn)
		{
			soNetKhongPutPixel++;
			soNetPutPixel=0;
		}
		else if(soNetPutPixel==0&&soNetKhongPutPixel<soNetAn)
		{
			soNetKhongPutPixel++;
		}
		else if(soNetKhongPutPixel==soNetAn&&soNetPutPixel==0)
		{
			soNetPutPixel++;
			soNetKhongPutPixel=0;
			putpixel(Round(x),Round(y),9);
		}
		
 
    }
}
void hientoado(int sd, toado3D A[],int couser)
{
	toado3D B[50];
	//B[30] = A[30];
	
	/*	for (int i = 1; i <= sd; i++)
		{
			
			//cout << B[i].x << ";" << B[i].y << endl;
			if (couser == 1)
			{
				
				B[i] = A[i];
			}
			else
			{
				B[i] = ratoadouser(A[i]);
			}
		}
	*/
	settextstyle(8, 0, 2);
	setcolor(9);
	setbkcolor(7);
	char dr[100];
	char ar[100];
	char a[2];
	a[1] = 0;
	int x = 100;
	
	/*if (sd <= 8)
	{
		for (int i = 0; i < sd; i++)//195, 595
		{
			a[0] = TD[i];
			x = x + 120;
			outtextxy(x, 615, a);
			//settextstyle(0, 0, 1);
			strcpy(dr, "      ");
			outtextxy(x - 23, 640, dr);
			strcpy(dr, "|");
			strcat(dr, _itoa(B[i + 1].x, ar, 10));
			outtextxy(x - 23, 640, dr);
			strcpy(dr, "      ");
			outtextxy(x - 20, 660, dr);
			strcpy(dr, _itoa(B[i + 1].y, ar, 10));
			strcat(dr, "|");
			outtextxy(x - 20, 660, dr);
			//settextstyle(8, 0, 2);
		}
	}
	else
	{
		for (int i = 0; i < sd; i++)//195, 595
		{
			a[0] = TD[i];
			x = x + 55;
			outtextxy(x, 615, a);
			settextstyle(0, 0, 1);
			strcpy(dr, "      ");
			outtextxy(x - 23, 640, dr);
			strcpy(dr, "|");
			strcat(dr, _itoa(B[i + 1].x, ar, 10));
			outtextxy(x - 23, 640, dr);
			strcpy(dr, "      ");
			outtextxy(x - 20, 660, dr);
			strcpy(dr, _itoa(B[i + 1].y, ar, 10));
			strcat(dr, "|");
			outtextxy(x - 20, 660, dr);
			settextstyle(8, 0, 2);
		}
	}*/
	
}
void HinhHopCN(){
	char a[100];
	int x = 50;
	int y = 298;
	char d1[30];
	int n1;
	float sqrt2per2 = sqrt(2) / 2;
	strcpy(a, "chieu dai(oy): ");
	textWrite(x, y, a, 7);
	textReadnumber(x, y, d1);
	n1 = atoi(d1);
	float d = n1;
	strcpy(a, "");
	textWriteln(x, y, a);
	strcpy(a, "chieu rong(oz): ");
	textWrite(x, y, a, 7);
	textReadnumber(x, y, d1);
	n1 = atoi(d1);
	float r = n1;
	strcpy(a, "");
	textWriteln(x, y, a);
	strcpy(a, "chieu cao(ox): ");
	textWrite(x, y, a, 7);
	textReadnumber(x, y, d1);
	n1 = atoi(d1);
	float c = n1;
	strcpy(a, "");
	textWriteln(x, y, a);

	strcpy(a, "x(0): ");
	textWrite(x, y, a, 7);
	textReadnumber(x, y, d1);
	n1=atoi(d1);
	float plusX = n1 ;
	strcpy(a, "");
	textWriteln(x, y, a);
	strcpy(a, "y(0): ");
	textWrite(x, y, a, 7);
	textReadnumber(x, y, d1);
	n1=atoi(d1);
	float plusY = n1 ;
	strcpy(a, "");
	textWriteln(x, y, a);
	toado2D A, B, C, D, E, F, G, H;

	LineDDA(plusX, plusY - c, plusX + d, plusY - c);//AB
	LineDDA(plusX + d, plusY - c, plusX + d, plusY);//BC
	LineDDAan(plusX + d, plusY, plusX, plusY);//CD
	LineDDAan(plusX, plusY, plusX, plusY-c);//AD
	LineDDA(plusX - sqrt2per2*r, plusY - (c - sqrt2per2*r), plusX + d - sqrt2per2 * r, plusY - (c - sqrt2per2 * r));//EF
	LineDDA(plusX + d - sqrt2per2 * r, plusY - (c - sqrt2per2 * r), plusX + d - sqrt2per2 * r, plusY + sqrt2per2 * r);//FG
	LineDDA(plusX + d - sqrt2per2 * r, plusY + sqrt2per2 * r, plusX - sqrt2per2 * r, plusY + sqrt2per2 * r);//HG
	LineDDA(plusX - sqrt2per2 * r, plusY + sqrt2per2 * r, plusX - sqrt2per2 * r, plusY - (c - sqrt2per2 * r));//EH
	
	LineDDA(plusX - sqrt2per2 * r, plusY - (c - sqrt2per2 * r), plusX, plusY - c);//BF
	LineDDA(plusX + d - sqrt2per2 * r, plusY - (c - sqrt2per2 * r), plusX + d, plusY - c);//BB'
	LineDDA(plusX + d - sqrt2per2 * r, plusY + sqrt2per2 * r, plusX + d, plusY);//CG
	LineDDAan(plusX - sqrt2per2 * r, plusY + sqrt2per2 * r, plusX, plusY);//DH
	toado3D K[20];
	K[1].x = plusX;//A'
	K[1].y = plusY - c;
	K[2].x = plusX + d;//B'
	K[2].y = plusY - c;
	K[3].x = plusX + d;//C'
	K[3].y = plusY;
	K[4].x = plusX;//D'
	K[4].y = plusY;
	K[5].x = plusX - sqrt2per2 * r;//A
	K[5].y = plusY - (c - sqrt2per2 * r);
	K[6].x = plusX + d - sqrt2per2 * r;//B
	K[6].y = plusY - (c - sqrt2per2 * r);
	K[7].x = plusX + d - sqrt2per2 * r;//C
	K[7].y = plusY + sqrt2per2 * r;
	K[8].x = plusX - sqrt2per2 * r;//D
	K[8].y = plusY + sqrt2per2 * r;
	hientoado(8, K, 9);
	char M[10];
	M[1] = 0;
	settextstyle(8, 0, 1);
	for (int i = 0; i < 8; i++)
	{
		M[0] = TD[i];
		//cout << A[i+1].x<< A[i + 1].y << endl;
		setcolor(9);
		setbkcolor(8);
		outtextxy(K[i + 1].x - 8, K[i + 1].y - 8, M);
	}
}
void xuLi3D1(){
	setGiaoDienHoatDong(2);
	//VeHinhChuNhatVien(306,360,1274,360,15);
	HeTrucXYZ();
	HinhHopCN();
	//menucachinh3D();
}
void HinhCN(){
	
}
