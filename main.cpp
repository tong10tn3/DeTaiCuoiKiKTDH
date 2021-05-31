#include <graphics.h> 
#include "VeGiaoDien.h"
#include "ve3D3.h"
#include "ve2D1.h"
#include "Ve2D2.h"
using namespace std;

int main()//int argc, char *argv[]
{
	initwindow(1280+8,720+12);
	setGiaoDien();
	//ghiDSTV();
	xuLi();
	//canhVat();
//	veXe(22,-14,32,-28,16,-20,22,-28,32,-8,92,-28,24,-28,48,-28,76,-28);
//	doiXungXeQuaO(22,-14,32,-28,16,-20,22,-28,32,-8,92,-28,24,-28,48,-28,76,-28);
//	tinhTienXe(3);
	getch();
	return 0;
	
}



