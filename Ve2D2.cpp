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
double maTranquay[3][3]=
	{
		{1,0,0},
		{0,1,0},
		{1/2,1/2, 1}
	};
void VePhanCach(double x,double y,int color){
	setcolor(color);
	lineDDA(x,y,x+100,y,0);
	lineDDA(x+10,y+7,x+100+10,y+7,0);
	lineDDA(x,y,x+10,y+7,0);
	lineDDA(x+100,y,x+100+10,y+7,0);
}
void canhVat(){
	double mtnui1[1][3]={306,300,1};
	double mtnui2[1][3]={450,100,1};
	double mtnui3[1][3]={600,300,1};
	double mtnui11[1][3]={500,250,1};
	double mtnui22[1][3]={600,60,1};
	double mtnui33[1][3]={700,250,1};
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
				{+350,0,1}
			};
	setcolor(0);
	line(306,300,1700,300);	
	for(int i=0;i<3;i++){
		lineDDA(mtnui1[0][0],mtnui1[0][1],mtnui2[0][0],mtnui2[0][1],0);
		lineDDA(mtnui2[0][0],mtnui2[0][1],mtnui3[0][0],mtnui3[0][1],0);
		setfillstyle(1,2);
		floodfill(mtnui2[0][0],mtnui2[0][1]+10,0);
		nhan2MaTran(mtnui1,MTTTNui,mt1,1,3,3);
		nhan2MaTran(mtnui2,MTTTNui,mt2,1,3,3);
		nhan2MaTran(mtnui3,MTTTNui,mt3,1,3,3);
		mtnui1[0][0]=mt1[0][0];
		mtnui1[0][1]=mt1[0][1];
		mtnui2[0][0]=mt2[0][0];
		mtnui2[0][1]=mt2[0][1];
		mtnui3[0][0]=mt3[0][0];
		mtnui3[0][1]=mt3[0][1];
		lineDDA(306,50,380,195,0);
		setfillstyle(1,2);
		floodfill(380-10,195,0);
		lineDDA(520,200,615,120,0);
		lineDDA(615,120,715,220,0);
		setfillstyle(1,2);
		floodfill(615,130,0);
		lineDDA(850,160,970,60,0);
		lineDDA(970,60,1100,175,0);
		setfillstyle(1,2);
		floodfill(970,60+10,0);
		setfillstyle(1,11);
		floodfill(310,7,0);
		circleBresenham(715,150,30,0);
		setfillstyle(1,14);
		floodfill(715,150,0);
		setfillstyle(1,2);
		bar(306,301,1275,480);
		
	}
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
		setfillstyle(1,14);
		floodfill(mt51[0][0],mt51[0][1],0);
		setcolor(4);
		line(790,6,790,714);
		line(306,360,1274,360);
		setcolor(15);
		setactivepage(page);
		setvisualpage(1-page);
		
		setGiaoDienHoatDong(1);
		
		//setGiaoDien();
		//duong di
		
		setfillstyle(1,8);
		bar(306,480,1275,590);
		//le duong
		setfillstyle(1,2);
		bar(306,591,1275,800);
		canhVat();
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
