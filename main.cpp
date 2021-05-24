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
#include "ve3d.h"
using namespace std;
#define PI 3.14159265359

int main()//int argc, char *argv[]
{
	initwindow(1280+8,720+12);
	setGiaoDien();  
	xuLi();

	
	getch();
	return 0;
	
}



