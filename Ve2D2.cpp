#include "hamCoSo.h"
#include "VeGiaoDien.h"
#include "ve2D1.h"
#include<graphics.h>
#include<iostream>
#include<math.h>
#include <sstream>
using namespace std;
double maTranTinhTien[3][3]=
			{
				{1,0,0},
				{0,1,0},
				{-5,0,1}
};
double maTranDonVi[3][3]=
			{
				{1,0,0},
				{0,1,0},
				{0,0,1}
			};


//void veOtoTai(){
//	//thùng xe sau
//	Ve_HCN(950, 400, 1250, 500, 0);
//	setfillstyle(1,14);
//	floodfill(955, 405,0);
//	//bánh xe truoc cua thung
//	circle(1030,500,20);
//	circle(1030,500,12);
//	setcolor(15);
//	line(1018,500,1042,500);
//	setcolor(0);
//	setfillstyle(1,7);
//	floodfill(1030, 500,0);
//	
//	//mau lop
//	setfillstyle(1,0);
//	floodfill(1043, 501,0);
//	floodfill(1043, 499,0);
//	
//	//bánh xe sau cua thung
//	circle(1170,500,20);
//	circle(1170,500,12);
//	setcolor(15);
//	line(1158,500,1182,500);
//	setfillstyle(1,7);
//	floodfill(1170, 500,0);
//	//mau lop
//	setfillstyle(1,0);
//	floodfill(1183, 501,0);
//	floodfill(1183, 499,0);
//	
//	//dau xe
//	Ve_HCN(900, 430, 950, 500, 0);
//	setfillstyle(1,1);
//	floodfill(901, 431,0);
//	Ve_HCN(870, 460, 900, 500, 0);
//	setfillstyle(1,1);
//	floodfill(871, 461,0);
//	line(900, 430,870, 460);
//	
//	//banh xe dau
//	circle(910,500,20);
//	circle(910,500,12);
//	setcolor(15);
//	line(898,500,922,500);
//	setfillstyle(1,7);
//	floodfill(910, 500,0);
//	//mau lop
//	setfillstyle(1,0);
//	floodfill(923, 501,0);
//	floodfill(894, 498,0);
//	floodfill(923, 499,0);
//	
//	//mau cua kinh
//	setfillstyle(1,7);
//	floodfill(895, 449,0);
//}
void VePhanCach(double x,double y,int color){
	setcolor(color);
	lineDDA(x,y,x+100,y,0);
	lineDDA(x+10,y+7,x+100+10,y+7,0);
	lineDDA(x,y,x+10,y+7,0);
	lineDDA(x+100,y,x+100+10,y+7,0);
}

void tinhTien(){
	boolean kt=false;
	while(true){
		
	//ma tran 2 diem ve thung xe sau
	double maTranThung1[1][3]={{950,400,1}};
	double maTranThung2[1][3]={{1250,500,1}};
	//ma tran 2 diem ve dau xe 1
	double maTranDauXe1[1][3]={{900, 430,1}};
	double maTranDauXe2[1][3]={{950, 500,1}};
	//ma tran 2 diem ve dau xe 2
	double maTranDauXe11[1][3]={{870, 460,1}};
	double maTranDauXe22[1][3]={{900, 500,1}};
	//ma tran banh xe truoc
	double maTranBanhXe1[1][3]={{910,500,1}};
	//ma tran banh xe thu 2 
	double maTranBanhXe2[1][3]={{1030,500,1}};
	//ma tran banh xe thu 3
	double maTranBanhXe3[1][3]={{1170,500,1}};
	//ma tran duong thang ve kinh oto
	double maTranKinh1[1][3]={{900, 430,1}};
	double maTranKinh2[1][3]={{870, 460,1}};
	double mt11[1][3];
	double mt12[1][3];
	
	double mt21[1][3];
	double mt22[1][3];
	
	double mt31[1][3];
	double mt32[1][3];
	
	double mt41[1][3];
	double mt42[1][3];
	
	double mt51[1][3];
	double mt52[1][3];
	double mt53[1][3];
	int page=0;
	for(int i=0;i<111;i++){
		setcolor(4);
		line(790,6,790,714);
		line(306,360,1274,360);
		setcolor(15);
		setactivepage(page);
		setvisualpage(1-page);
		setGiaoDienHoatDong(1);
		//duong di
		setfillstyle(1,8);
		bar(306,480,1275,590);
		//le duong
		setfillstyle(1,2);
		bar(306,591,1275,800);
		//bau troi
		setfillstyle(1,9);
		bar(306,479,1275,5);
		//giai phan cach
		VePhanCach(320,530,0);
		VePhanCach(520,530,0);
		VePhanCach(720,530,0);
		VePhanCach(920,530,0);
		VePhanCach(1120,530,0);
		//Ve banh xe thu 1
		circleBresenham(mt51[0][0],mt51[0][1],20,0);
		setfillstyle(1,0);
		floodfill(mt51[0][0],mt51[0][1],0);
		circleBresenham(mt51[0][0],mt51[0][1],12,15);
		nhan2MaTran(maTranBanhXe1,maTranTinhTien,mt51,1,3,3);
		nhan2MaTran(mt51,maTranDonVi,maTranBanhXe1,1,3,3);
		//Ve banh xe thu 2
		circleBresenham(mt52[0][0],mt52[0][1],20,0);
		setfillstyle(1,0);
		floodfill(mt52[0][0],mt52[0][1],0);
		circleBresenham(mt52[0][0],mt52[0][1],12,15);
		nhan2MaTran(maTranBanhXe2,maTranTinhTien,mt52,1,3,3);
		nhan2MaTran(mt52,maTranDonVi,maTranBanhXe2,1,3,3);
		//Ve banh xe thu 3
		circleBresenham(mt53[0][0],mt53[0][1],20,0);
		setfillstyle(1,0);
		floodfill(mt53[0][0],mt53[0][1],0);
		circleBresenham(mt53[0][0],mt53[0][1],12,15);
		nhan2MaTran(maTranBanhXe3,maTranTinhTien,mt53,1,3,3);
		nhan2MaTran(mt53,maTranDonVi,maTranBanhXe3,1,3,3);
		//Ve thung xe sau
		Ve_HCN(mt11[0][0],mt11[0][1],mt12[0][0],mt12[0][1],0);
		setfillstyle(1,14);
		floodfill(mt11[0][0]+6,mt11[0][1]+6,0);
		
		nhan2MaTran(maTranThung1,maTranTinhTien,mt11,1,3,3);
		nhan2MaTran(mt11,maTranDonVi,maTranThung1,1,3,3);
		
		nhan2MaTran(maTranThung2,maTranTinhTien,mt12,1,3,3);
		nhan2MaTran(mt12,maTranDonVi,maTranThung2,1,3,3);
		//Ve dau xe thu 2
		Ve_HCN(mt21[0][0],mt21[0][1],mt22[0][0],mt22[0][1],0);
		setfillstyle(1,1);
		floodfill(mt21[0][0]+6,mt21[0][1]+6,0);
		
		nhan2MaTran(maTranDauXe1,maTranTinhTien,mt21,1,3,3);
		nhan2MaTran(mt21,maTranDonVi,maTranDauXe1,1,3,3);
		
		nhan2MaTran(maTranDauXe2,maTranTinhTien,mt22,1,3,3);
		nhan2MaTran(mt22,maTranDonVi,maTranDauXe2,1,3,3);
		//Ve dau xe thu 1
		Ve_HCN(mt31[0][0],mt31[0][1],mt32[0][0],mt32[0][1],0);
		setfillstyle(1,1);
		floodfill(mt31[0][0]+6,mt31[0][1]+6,0);
		
		nhan2MaTran(maTranDauXe11,maTranTinhTien,mt31,1,3,3);
		nhan2MaTran(mt31,maTranDonVi,maTranDauXe11,1,3,3);
		
		nhan2MaTran(maTranDauXe22,maTranTinhTien,mt32,1,3,3);
		nhan2MaTran(mt32,maTranDonVi,maTranDauXe22,1,3,3);
		
		lineDDA(mt21[0][0]+5,mt21[0][1],mt31[0][0]+5,mt31[0][1],0);
		setfillstyle(1,15);
		floodfill(mt21[0][0]-5,mt21[0][1]+15,0);
		line(305,590,1275,590);
		line(305,480,mt31[0][0],480);
		line(1275,480,mt12[0][0],480);
		
		setcolor(15);
		settextstyle(DEFAULT_FONT,0, 1);	
		setbkcolor(mauxanhgiongaokhoaccrush);
		outtextxy(15,280,"VAT");
		outtextxy(150,280,"X");
		outtextxy(233,280,"Y");
		//toa do banh xe truoc
		outtextxy(15,260+30*1,"Banh xe truoc");
		hienThiToaDo(mt51[0][0]+5,mt51[0][1],1);
		//toa do banh xe giua
		outtextxy(15,260+30*2,"Banh xe giua");
		hienThiToaDo(mt52[0][0]+5,mt52[0][1],2);
		//toa do banh xe sau
		outtextxy(15,260+30*3,"Banh xe sau");
		hienThiToaDo(mt53[0][0]+5,mt53[0][1],3);
		//toa do cac diem dau xe
		outtextxy(15,260+30*4,"Toa do cac diem dau xe");
		outtextxy(15,260+30*5,"dau xe 1");
		hienThiToaDo(mt31[0][0]+5,mt31[0][1],5);
		outtextxy(15,260+30*6,"dau xe 2");
		hienThiToaDo(mt31[0][0]+5,mt32[0][1],6);
		outtextxy(15,260+30*7,"dau xe 3");
		hienThiToaDo(mt21[0][0]+5,mt21[0][1],7);
		outtextxy(15,260+30*8,"dau xe 4");
		hienThiToaDo(mt22[0][0]+5,mt21[0][1],8);
		outtextxy(15,260+30*9,"dau xe 5");
		hienThiToaDo(mt22[0][0]+5,mt22[0][1],9);
		//toa do cac diem thung xe
		outtextxy(15,260+30*10,"Toa do cac diem thung xe");
		outtextxy(15,260+30*11,"thung xe 1");
		hienThiToaDo(mt11[0][0]+5,mt11[0][1],11);
		outtextxy(15,260+30*12,"thung xe 2");
		hienThiToaDo(mt11[0][0]+5,mt12[0][1],12);
		outtextxy(15,260+30*13,"thung xe 3");
		hienThiToaDo(mt12[0][0]+5,mt11[0][1],13);
		outtextxy(15,260+30*14,"thung xe 4");
		hienThiToaDo(mt12[0][0]+5,mt12[0][1],14);
		
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
					cout<<xtam<<"\t"<<ytam<<endl;
				}
			}
		
		page=1-page;
		delay(0.1);
		}
		if(kt==true)
		{
			break;
		}
		}
}
