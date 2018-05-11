
#include<stdlib.h>
#include"Menu.h"
#include<ctime>
#include"KhoiTaoHinhDangVaToaDo.h"
#include"Hienthi.h"
#include"DieuKhienMayBay.h"
#include"XuLyCacVaCham.h"
#include"XuLyMayBayDich.h"
#include"Shoot.h"
#include"XuLyItems.h"
#include"XuLyDan.h"
#include"Boss.h"

int i,j=0,isoluongdan,idemsoluongdan=0,gameover,maybaylife,mangbaove=0, diem,bodemso=0,sobichia,isoluongquaivat,itrangthaidan,bmautank[30],bmauboss,checkboss;
int ihuongdichuyenboss;


void KhoiTao(MayBay& maybay,MayBayDich & maybaydich,Dan&dan,Items&items,MayBayTank&maybaytank,MayBayTank&maybayban,Dan&dandich,MayBay&boss){
	diem=0;
	maybaylife=3;
	gameover=0;
	sobichia=4;
	isoluongquaivat=0;
	isoluongdan=1;
	itrangthaidan=1;
	bmauboss=100;
	checkboss=0;
	ihuongdichuyenboss=1;
	for(int i=0;i<30;i++){
		bmautank[i]=6;
	}
	KhoiTaoHinhDangVaToaDo(maybay,maybaydich,dan,items,maybaytank,maybayban,dandich,boss);
	taoviengame();
}

void xuly(MayBay maybay,MayBayDich & maybaydich,Dan & dan,Items & items,MayBayTank&maybaytank,MayBayTank&maybayban,Dan&dandich){
	xulymaybaydich(maybaydich,maybaytank,bodemso,sobichia,isoluongquaivat,checkboss);
	vacham(maybay,maybaydich,dan,items,maybaytank,maybayban,dandich,diem,bmautank,itrangthaidan,maybaylife,mangbaove,gameover);
	xulymaybaytank(maybaytank,maybaydich,bodemso,sobichia,isoluongquaivat,checkboss,bmautank);
	vacham(maybay,maybaydich,dan,items,maybaytank,maybayban,dandich,diem,bmautank,itrangthaidan,maybaylife,mangbaove,gameover);
	xulymaybayban(maybayban,bodemso,sobichia,isoluongquaivat,checkboss);
	vacham(maybay,maybaydich,dan,items,maybaytank,maybayban,dandich,diem,bmautank,itrangthaidan,maybaylife,mangbaove,gameover);
	
	shoot(maybay,dan,itrangthaidan,isoluongdan);
	bodemso++;
	//toc do  game;
	if(bodemso==10000){
		bodemso=1;
	}
	if(isoluongquaivat>=0&&isoluongquaivat<=100){
		sobichia=5;
	}
	if(isoluongquaivat>100&&isoluongquaivat<=300){
		sobichia=4;
	}
	if(isoluongquaivat>300){
		sobichia=3;
	}
	vacham(maybay,maybaydich,dan,items,maybaytank,maybayban,dandich,diem,bmautank,itrangthaidan,maybaylife,mangbaove,gameover);
	
	xulyitems(items,isoluongquaivat,bodemso);
	vacham(maybay,maybaydich,dan,items,maybaytank,maybayban,dandich,diem,bmautank,itrangthaidan,maybaylife,mangbaove,gameover);
	
	xulydan(dan,dandich,maybayban,itrangthaidan,idemsoluongdan,isoluongdan,bodemso);
	vacham(maybay,maybaydich,dan,items,maybaytank,maybayban,dandich,diem,bmautank,itrangthaidan,maybaylife,mangbaove,gameover);
	
	Nhap6:;
	if(isoluongquaivat%50==0&&isoluongquaivat!=0){
		checkboss=1;
	}
}

int main(){
	ShowCur(0);
	menu();
	//setFullScreen();
	srand(time(NULL));
	MayBay maybay;
	MayBayDich maybaydich;
	MayBayTank maybaytank;
	MayBayTank maybayban;
	MayBay boss;
	Dan dan;
	Dan dandich;
	Items items;
	KhoiTao(maybay,maybaydich,dan,items,maybaytank,maybayban,dandich,boss);
	//ban may bay thuong
	while(1){
		Nhap40:;
		HienThi(maybay,mangbaove,diem,bmauboss,maybaylife);
		DieuKhien(maybay,mangbaove);
		xuly(maybay, maybaydich,dan,items,maybaytank,maybayban,dandich);
		if(checkboss==1){
			goto Nhap30;
		}
		if(gameover==1){
			goto lost;
		}
		Sleep(40);
		
	}
	//ban boss
	while(1){
		Nhap30:;
		xuly(maybay, maybaydich,dan,items,maybaytank,maybayban,dandich);
		DieuKhien(maybay,mangbaove);
		xulyboss(maybay,boss,items,dan,dandich,maybaylife,itrangthaidan,mangbaove,bmauboss,ihuongdichuyenboss,gameover);
		HienThi(maybay,mangbaove,diem,bmauboss,maybaylife);
		if(bmauboss<=0){
			gotoxy(boss.td.x,boss.td.y);
		   	cout<<"          ";
		   	gotoxy(boss.td.x,boss.td.y-1);
		   	cout<<"          ";
		   	gotoxy(boss.td.x,boss.td.y-2);
		   	cout<<"          ";

			checkboss=0;
			bmauboss=1000;
			boss.td.x=30;
			boss.td.y=3;
			isoluongquaivat++;
			goto Nhap40;
		}
		if(gameover==1){
			goto lost;
		}
		Sleep(40);
	}
	//thua cuoc
	lost:;
	gotoxy(10,13);
	SetColor(11);
	cout<<"you lost ";
	SetColor(15);
	while(1){
		
	}
	return 0;
}
