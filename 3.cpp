#include<iostream>
#include<stdlib.h>
#include<Windows.h>
#include<string.h>
#include "Util.h"
#include<ctime>
#include<stdio.h>

#define ConW 25
#define ConH 25
enum TrangThai {UP,DOWN,LEFT,RIGHT
};

int i,j=0,isoluongdan=26,idemsoluongdan=0,gameover=0,maybaylife=3,mangbaove=0, diem=0,bodemso=0,sobichia=4,isoluongquaivat=0,iitems;

using namespace std;

struct ToaDo{
	int y,x;
};

struct HinhDang{
	char a[10];
	char b[2];
	char c[3];
};

struct MayBay{
	ToaDo td;
	HinhDang hd;
};

struct MayBayDich{
	MayBay mb[30];	
};

struct Dan{
	MayBay mb[30];
};

struct Heart{
	HinhDang hd;
	ToaDo td;
};

struct Shield{
	HinhDang hd;
	ToaDo td;
};

struct Bullet{
	HinhDang hd;
	ToaDo td;
};

struct Items{
	Heart h;
	Shield s;
	Bullet b;
};

void KhoiTao(MayBay& maybay,MayBayDich & maybaydich,Dan&dan,Items&items){
	maybay.td.y=ConW;
	maybay.td.x=ConW/2;
	strcpy(maybay.hd.a,"~|O|~");
	diem=0;
	for(i=0;i<30;i++){
	    maybaydich.mb[i].td.x=50;
	    maybaydich.mb[i].td.y=2;
		strcpy(maybaydich.mb[i].hd.a,"~|-|~");
		dan.mb[i].td.x=40;
		dan.mb[i].td.y=3;
		strcpy(dan.mb[i].hd.a,"^");
		strcpy(dan.mb[i].hd.b,"i i");
		strcpy(dan.mb[i].hd.c,"_^_");
	}
	strcpy(items.h.hd.c,"Y");
	strcpy(items.s.hd.c,"Q");
	strcpy(items.b.hd.c,"!");
	items.h.td.x=50;
	items.h.td.y=5;
	items.s.td.x=50;
	items.s.td.y=5;
	items.b.td.x=50;
	items.b.td.y=5;
}

void HienThi(MayBay&maybay,MayBayDich & maybaydich,Dan& dan,Items & items){
	system("cls");
	for(i=0;i<=ConW;i++){
		printf("%c\n",179);
	}
	for(i=0;i<=ConH;i++){
		gotoxy(ConH+5,i);
		putchar(179);
	}
	if(mangbaove>0){
		for(i=0;i<5;i++){
			gotoxy(maybay.td.x+i,maybay.td.y-1);
			cout<<"_";
		}
	}
	gotoxy(maybay.td.x,maybay.td.y);
	cout<<maybay.hd.a;
	gotoxy(40,20);
	cout<<"Point : "<<diem*100;
	gotoxy(40,18);
	cout<<"So luong dan dang co : "<<isoluongdan;
	gotoxy(40,19);
	cout<<"Mang : "<<maybaylife;
	for(i=0;i<30;i++){
		if(maybaydich.mb[i].td.x>=0&&maybaydich.mb[i].td.x<=ConW&&maybaydich.mb[i].td.y>=0&&maybaydich.mb[i].td.y<=ConW){
			gotoxy(maybaydich.mb[i].td.x,maybaydich.mb[i].td.y);
			cout<<maybaydich.mb[i].hd.a;
		}
		if(dan.mb[i].td.x>=0&&dan.mb[i].td.x<=ConW+1&&dan.mb[i].td.y>=0&&dan.mb[i].td.y<=ConW){
			gotoxy(dan.mb[i].td.x,dan.mb[i].td.y);
			cout<<dan.mb[i].hd.a;
		}
	}
	if(items.h.td.x>=0&&items.h.td.x<=ConW+1&&items.h.td.y>=0&&items.h.td.y<=ConW){
		gotoxy(items.h.td.x,items.h.td.y);
		cout<<items.h.hd.c;
	}
	if(items.s.td.x>=0&&items.s.td.x<=ConW+1&&items.s.td.y>=0&&items.s.td.y<=ConW){
		gotoxy(items.s.td.x,items.s.td.y);
		cout<<items.s.hd.c;
	}
	if(items.b.td.x>=0&&items.b.td.x<=ConW+1&&items.b.td.y>=0&&items.b.td.y<=ConW){
		gotoxy(items.b.td.x,items.b.td.y);
		cout<<items.b.hd.c;
	}
}

void DieuKhien(MayBay&maybay){
	if (checkKey(KEY_LEFT)){
			maybay.td.x--;
			if(maybay.td.x<=0)maybay.td.x++;
		}
    	else if (checkKey(KEY_RIGHT)){
			maybay.td.x++;
			if(maybay.td.x>=ConW)maybay.td.x--;
		}
    	else if (checkKey(KEY_UP)){
			maybay.td.y--;
			if(maybay.td.y<0)maybay.td.y++;
		}
    	else if (checkKey(KEY_DOWN)){
			maybay.td.y++;
			if(maybay.td.y>ConH)maybay.td.y--;
		}
}

void vacham(MayBay& maybay,MayBayDich& maybaydich,Dan & dan){
	//va cham dan
	int l;
	for(i=0;i<30;i++){
		for(l=0;l<30;l++){
			int ddanx=maybaydich.mb[i].td.x-dan.mb[l].td.x;
		    int ddany=abs(maybaydich.mb[i].td.y-dan.mb[l].td.y);
		    if(ddany==0&&ddanx<=0&&ddanx>=-5){
		    	    if(dan.mb[l].td.x>=0&&dan.mb[l].td.x<=ConW+1&&dan.mb[l].td.y>=0&&dan.mb[l].td.y<=ConW&&maybaydich.mb[i].td.x>=0&&maybaydich.mb[i].td.x<=ConW&&maybaydich.mb[i].td.y>=0&&maybaydich.mb[i].td.y<=ConW){
		    			diem++;
		    		}
		    		maybaydich.mb[i].td.x=50;
		    		maybaydich.mb[i].td.y=2;
		    		dan.mb[l].td.x=40;
		    		dan.mb[l].td.y=3;
		    	}	
		}
	}
	//va cham may bay
	for(i=0;i<30;i++){
		   int dx=abs(maybay.td.x-maybaydich.mb[i].td.x);
		   int dy=abs(maybay.td.y-maybaydich.mb[i].td.y);
	       
	      if(mangbaove==0){
	      	if(dx<=4&&dy==0){
	       	  maybaylife--;
	       	  mangbaove=100;
		    if(maybaylife==0){
		    	gameover=1;
			}
	       }
	      }
   }
   if(mangbaove>0){
   	mangbaove--;
   }
}

void shoot(MayBay& maybay,Dan& dan){
	if (checkKey(KEY_S)){
			if(isoluongdan>0){
				for(i=0;i<30;i++){
					if(dan.mb[i].td.x>=0&&dan.mb[i].td.x<=ConW+1&&dan.mb[i].td.y>=0&&dan.mb[i].td.y<=ConW){
					}else{
						dan.mb[i].td.x=maybay.td.x+2;
			            dan.mb[i].td.y=maybay.td.y;
			            isoluongdan--;
			            goto Nhap1;
					}
				}
			}
		}
		Nhap1:;
}

void xuly(MayBay maybay,MayBayDich & maybaydich,Dan & dan,Items & items){
	if(bodemso%sobichia==0){
		int ingaunhien=rand()%20;
	    if(ingaunhien%4==0){
		   for(i=0;i<30;i++){
		      if(maybaydich.mb[i].td.x>=0&&maybaydich.mb[i].td.x<=ConW&&maybaydich.mb[i].td.y>=0&&maybaydich.mb[i].td.y<=ConW){
		      }else{
		   	       maybaydich.mb[i].td.x=rand()%ConW+1;
		           maybaydich.mb[i].td.y=0;
		           isoluongquaivat++;
		           goto Nhap;
		   }
		}
	}
	vacham(maybay,maybaydich,dan);
	Nhap:;
	
		for(i=0;i<30;i++){
		   if(maybaydich.mb[i].td.x>=0&&maybaydich.mb[i].td.x<=ConW&&maybaydich.mb[i].td.y>=0&&maybaydich.mb[i].td.y<=ConW){
			maybaydich.mb[i].td.y++;
		   }else{
			     maybaydich.mb[i].td.x=40;
	             maybaydich.mb[i].td.y=2;
		   }
	    }
	    vacham(maybay,maybaydich,dan);
	}
	shoot(maybay,dan);
	bodemso++;
	if(bodemso==10000){
		bodemso=0;
	}
	if(isoluongquaivat>15&&isoluongquaivat<=30){
		sobichia=3;
	}
	if(isoluongquaivat>30&&isoluongquaivat<=60){
		sobichia=2;
	}
	if(isoluongquaivat>60){
		sobichia=1;
	}
	//tao vat pham
	if((isoluongquaivat+1)%30==0){
		iitems=rand()%5+1;
		if(iitems==1){
			items.h.td.x=rand()%ConW+1;
			items.h.td.y=0;
		}
		if(iitems==2){
			items.s.td.x=rand()%ConW+1;
			items.s.td.y=0;
		}
		if(iitems==3){
			items.b.td.x=rand()%ConW+1;
			items.b.td.y=0;
		}
		isoluongquaivat++;
	}
	if(bodemso%6==0){
		if(items.h.td.x>=0&&items.h.td.x<=ConW+1&&items.h.td.y>=0&&items.h.td.y<=ConW){
		   items.h.td.y++;	
		}else{
			items.h.td.x=50;
	        items.h.td.y=5;
		}
		if(items.s.td.x>=0&&items.s.td.x<=ConW+1&&items.s.td.y>=0&&items.s.td.y<=ConW){
			items.s.td.y++;
		}else{
			items.s.td.x=50;
	        items.s.td.y=5;
		}
		if(items.b.td.x>=0&&items.b.td.x<=ConW+1&&items.b.td.y>=0&&items.b.td.y<=ConW){
			items.b.td.y++;
		}else{
			items.b.td.x=50;
	        items.b.td.y=5;
		}
	}
	
	vacham(maybay,maybaydich,dan);
	for(i=0;i<30;i++){
		if(dan.mb[i].td.x>=0&&dan.mb[i].td.x<=ConW+1&&dan.mb[i].td.y>=0&&dan.mb[i].td.y<=ConW){
			dan.mb[i].td.y--;
		}else{
			dan.mb[i].td.x=40;
			dan.mb[i].td.y=2;
		}
	}
	idemsoluongdan++;
	if(idemsoluongdan%6==0){
		if(isoluongdan<26){
			isoluongdan++;
		}
	}
	if(idemsoluongdan==100000){
		idemsoluongdan=0;
	}
	vacham(maybay,maybaydich,dan);
}

void endgame(){
	
}

int main(){
	ShowCur(0);
	srand(time(NULL));
	MayBay maybay;
	MayBayDich maybaydich;
	Dan dan;
	Items items;
	KhoiTao(maybay,maybaydich,dan,items);
	while(1){
		DieuKhien(maybay);
		HienThi(maybay,maybaydich,dan,items);
		xuly(maybay, maybaydich,dan,items);
		Sleep(25);
		if(gameover==1){
			goto lost;
		}
	}
	lost:;
	system("cls");
	HienThi(maybay,maybaydich,dan,items);
	gotoxy(10,13);
	cout<<"you lost ";
	while(1){
			if (checkKey(KEY_J)){
				goto Nhap2;
		}
	}
	Nhap2:;
	return 0;
}
