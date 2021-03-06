#include <math.h>
#include <conio.h>
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <string.h>
#include <graphics.h>
#include <sstream>
#include <time.h>
#include "ve3D1.h"
#define ROUND(a) (int)(a+0.5)
using namespace std;


void floodfillNguoiDung(int xTam, int yTam, int mauBorder)
{
	int xKQ,yKQ;
	doiNguoiDungsangMayTinh(xTam,yTam,790,360,xKQ,yKQ);
	floodfill(xKQ,yKQ,mauBorder);
}
void putpixel5DV(int x, int y, int color)
{
	setbkcolor(0);
	setcolor(color);
	for(int i=x-2;i<=x+2;i++)
	{
		for(int j=y-2;j<=y+2;j++)
		{
			putpixel(i,j,color);
		}
	}
}

void putpixel5DVNguoiDung(int x, int y, int color)
{
	int xKQ,yKQ;
	doiNguoiDungsangMayTinh(x,y,790,360,xKQ,yKQ);
	
	setbkcolor(0);
	setcolor(color);
	for(int i=xKQ-2;i<=xKQ+2;i++)
	{
		for(int j=yKQ-2;j<=yKQ+2;j++)
		{
			putpixel(i,j,color);
		}
	}
}

void doiMayTinhSangNguoiDung(int xDoi, int yDoi, int x0, int y0, float &xKQ, float &yKQ)
{
	xKQ=(xDoi-x0)/5.0;
	yKQ=-(yDoi-y0)/5.0;
}

void lineDDANguoiDung(int x1,int y1, int x2,int y2,int c){
	int i,j,step;
	int dx=x2-x1;
	int dy=y2-y1;
	abs(dx)>=abs(dy) ? step=abs(dx) : step=abs(dy);
	float inc_x = (float) dx/step;
	float inc_y = (float) dy/step;
	if(abs(dx)>=abs(dy) || abs(dx)<=abs(dy)){
		float x=x1;
		float y=y1;
		for(i=0;i<=abs(step);i+=1){
			putpixel5DVNguoiDung(round(x),round(y),c);
			x+=inc_x;
			y+=inc_y;
		}
	}
}


void lineDDA(int x1,int y1, int x2,int y2,int c){
	int i,j,step;
	int dx=x2-x1;
	int dy=y2-y1;
	abs(dx)>=abs(dy) ? step=abs(dx) : step=abs(dy);
	float inc_x = (float) dx/step;
	float inc_y = (float) dy/step;
	if(abs(dx)>=abs(dy) || abs(dx)<=abs(dy)){
		float x=x1;
		float y=y1;
		for(i=0;i<=abs(step);i+=1){
			putpixel5DV(round(x),round(y),c);
			x+=inc_x;
			y+=inc_y;
		}
	}
}
void lineDDA1DV(int x1,int y1, int x2,int y2,int c){
	int i,j,step;
	int dx=x2-x1;
	int dy=y2-y1;
	abs(dx)>=abs(dy) ? step=abs(dx) : step=abs(dy);
	float inc_x = (float) dx/step;
	float inc_y = (float) dy/step;
	if(abs(dx)>=abs(dy) || abs(dx)<=abs(dy)){
		float x=x1;
		float y=y1;
		for(i=0;i<=abs(step);i+=1){
			putpixel(round(x),round(y),c);
			x+=inc_x;
			y+=inc_y;
		}
	}
}






void ve8diem(int x0,int y0,int x, int y, int color)
{

  putpixel5DV( x0 + x , y0 + y ,color);

  putpixel5DV( x0 - x , y0 + y ,color);

  putpixel5DV( x0 + x , y0 - y ,color);

  putpixel5DV( x0 - x , y0 - y ,color);

  putpixel5DV( x0 + y , y0 + x ,color);

  putpixel5DV( x0 - y , y0 + x ,color);

  putpixel5DV( x0 + y , y0 - x ,color);

  putpixel5DV( x0 - y , y0 - x ,color);

}
void ve8diemNguoiDung(int x0,int y0,int x, int y, int color)
{

  putpixel5DVNguoiDung( x0 + x , y0 + y ,color);

  putpixel5DVNguoiDung( x0 - x , y0 + y ,color);

  putpixel5DVNguoiDung( x0 + x , y0 - y ,color);

  putpixel5DVNguoiDung( x0 - x , y0 - y ,color);

  putpixel5DVNguoiDung( x0 + y , y0 + x ,color);

  putpixel5DVNguoiDung( x0 - y , y0 + x ,color);

  putpixel5DVNguoiDung( x0 + y , y0 - x ,color);

  putpixel5DVNguoiDung( x0 - y , y0 - x ,color);

}

void circleBresenhamNguoiDung(int x0,int y0,int r, int color)
{
  int x=0;int y=r;

  int p=(3-2*r) ;

  while (x<=y)

  {

   ve8diemNguoiDung(x0,y0,x,y,color);

   if(p<0) p=p+(4*x+6);

   else

       {

            p=p+4*(x-y)+10;

            y=y-1;

       }

   x=x+1;

  }

}
void circleBresenham(int x0,int y0,int r, int color)
{
  int x=0;int y=r;

  int p=(3-2*r) ;

  while (x<=y)

  {

   ve8diem(x0,y0,x,y,color);

   if(p<0) p=p+(4*x+6);

   else

       {

            p=p+4*(x-y)+10;

            y=y-2;

       }

   x=x+2;

  }

}
void elipseNguoiDung(int xcenter,int ycenter,int xradius,int yradius, int color)
{
    int x,y; float c,p;
    x=0; y=yradius;
    c=(float)yradius/xradius;
    c=c*c; p=2*c-2*yradius+1;
    while (c*x<=y)
        {
            putpixel5DVNguoiDung(xcenter+x,ycenter+y,color);
            putpixel5DVNguoiDung(xcenter-x,ycenter+y,color);
            putpixel5DVNguoiDung(xcenter+x,ycenter-y,color);
            putpixel5DVNguoiDung(xcenter-x,ycenter-y,color);
            if (p<0) p += 2*c*(2*x+3);
            else
                {
                    p +=4*(1-y)+2*c*(2*x+3);
                    y-=1;
                }
            x+=1;
        }
   
    y=0;x=xradius;
    c= (float)xradius/yradius;
    c=c*c; p=2*c-2*xradius+1;
    while (c*y<=x)
        {
            putpixel5DVNguoiDung(xcenter+x,ycenter+y,color);
            putpixel5DVNguoiDung(xcenter-x,ycenter+y,color);
            putpixel5DVNguoiDung(xcenter+x,ycenter-y,color);
            putpixel5DVNguoiDung(xcenter-x,ycenter-y,color);
            if (p<0) p +=2*c*(2*y+3);
            else
                {
                    p +=4*(1-x)+2*c*(2*y+3);
                    x-=1;
                }
            y+=1;
        }
}

//Elipse
void elipse(int xcenter,int ycenter,int xradius,int yradius, int color)
{
    int x,y; float c,p;
    x=0; y=yradius;
    c=(float)yradius/xradius;
    c=c*c; p=2*c-2*yradius+1;
    while (c*x<=y)
        {
            putpixel5DV(xcenter+x,ycenter+y,color);
            putpixel5DV(xcenter-x,ycenter+y,color);
            putpixel5DV(xcenter+x,ycenter-y,color);
            putpixel5DV(xcenter-x,ycenter-y,color);
            if (p<0) p += 2*c*(2*x+3);
            else
                {
                    p +=4*(1-y)+2*c*(2*x+3);
                    y-=2;
                }
            x+=2;
        }
   
    y=0;x=xradius;
    c= (float)xradius/yradius;
    c=c*c; p=2*c-2*xradius+1;
    while (c*y<=x)
        {
            putpixel5DV(xcenter+x,ycenter+y,color);
            putpixel5DV(xcenter-x,ycenter+y,color);
            putpixel5DV(xcenter+x,ycenter-y,color);
            putpixel5DV(xcenter-x,ycenter-y,color);
            if (p<0) p +=2*c*(2*y+3);
            else
                {
                    p +=4*(1-x)+2*c*(2*y+3);
                    x-=2;
                }
            y+=2;
        }
}

void Ve_HCN(int x1, int y1, int x2, int y2, int color)
{
    setcolor(color);
    lineDDANguoiDung(x1,y1,x1,y2,color);
    lineDDANguoiDung(x1,y1,x2,y1,color);
    lineDDANguoiDung(x2,y2,x2,y1,color);
    lineDDANguoiDung(x2,y2,x1,y2,color);
}


void put8pixel(int xc, int yc, int x, int y, int color)
{
    putpixel5DV(x + xc, y + yc, color);
    putpixel5DV(-x + xc, y + yc, color);
    putpixel5DV(x + xc, -y + yc, color);
    putpixel5DV(-x + xc, -y + yc, color);
    putpixel5DV( y + xc, x + yc, color);
    putpixel5DV(-y + xc, x + yc, color);
    putpixel5DV(y + xc, -x + yc, color);
    putpixel5DV(-y + xc, -x + yc, color);
}


void drawCircleMidpoint(int xc, int yc, int r, int color)
{
    int x = 0, y = r;
    int f = 1 - r;

    put8pixel(xc, yc, x, y, color);

    while (x < y)
    {
        if (f < 0) f += (x << 1) + 3;
        else
        {
            y-=5;
            f += ((x - y) << 1) + 5;
        }
        x+=5;
        put8pixel(xc, yc, x, y, color);
    }
}
void hienThiToaDo(double x, double y, int i)
{
	double xO=790;
	double yO=360;
	
	double gocTen=290;
	

	ostringstream convertX;
	convertX<<x;
	string toaDoXString=convertX.str();
	char* toaDoXChar = new char[toaDoXString.size()];
	copy(toaDoXString.begin(), toaDoXString.end(), toaDoXChar);
	toaDoXChar[toaDoXString.size()] = '\0';
	
	settextstyle(DEFAULT_FONT,0, 1);
	outtextxy(150,gocTen+15*i,toaDoXChar);
	settextstyle(DEFAULT_FONT,0,1);
		
		
		
	ostringstream convertY;
	convertY<<y;
	string toaDoYString=convertY.str();
		
	char* toaDoYChar = new char[toaDoYString.size()];
	copy(toaDoYString.begin(), toaDoYString.end(), toaDoYChar);
	toaDoYChar[toaDoYString.size()] = '\0';
	settextstyle(DEFAULT_FONT,0, 1);
	outtextxy(233,gocTen+15*i,toaDoYChar);
	settextstyle(DEFAULT_FONT,0,1);
}


















