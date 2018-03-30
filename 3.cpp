#include<iostream>
#include<stdlib.h>
#include<Windows.h>
#include<string.h>
#include "Util.h"
#include<ctime>
#include<stdio.h>

#define ConW 25
#define ConH 25

int i,j=0,isoluongdan,idemsoluongdan=0,gameover,maybaylife,mangbaove=0, diem,bodemso=0,sobichia,isoluongquaivat,iitems,itrangthaidan;
using namespace std;

struct ToaDo{
	int y,x;
};

struct HinhDang{
	char a[10];
	char b[10];
	char c[10];
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
	diem=0;
	maybaylife=3;
	gameover=0;
	sobichia=4;
	isoluongquaivat=0;
	isoluongdan=26;
	itrangthaidan=1;
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
		strcpy(dan.mb[i].hd.b,"| |");
		strcpy(dan.mb[i].hd.c,"|||||");
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
	SetColor(10);
	for(i=0;i<=ConW;i++){
		printf("%c\n",179);
	}
	for(i=0;i<=ConH;i++){
		gotoxy(ConH+5,i);
		putchar(179);
	}
	SetColor(15);
	if(mangbaove>0){
		for(i=0;i<5;i++){
			gotoxy(maybay.td.x+i,maybay.td.y-1);
			SetColor(14);
			cout<<"_";
			SetColor(15);
		}
	}
	gotoxy(maybay.td.x,maybay.td.y);
	SetColor(14);
	cout<<maybay.hd.a;
	SetColor(15);
	gotoxy(40,20);
	cout<<"Score : "<<diem*100;
	gotoxy(40,18);
	cout<<"So luong dan dang co : "<<isoluongdan;
	gotoxy(40,19);
	cout<<"Life : ";
	for(i=0;i<maybaylife;i++){
		SetColor(12);
		printf("%c",177);
		printf("%c",177);
		cout<<" ";
		SetColor(15);
	}
	for(i=0;i<30;i++){
		if(maybaydich.mb[i].td.x>=0&&maybaydich.mb[i].td.x<=ConW&&maybaydich.mb[i].td.y>=0&&maybaydich.mb[i].td.y<=ConW){
			gotoxy(maybaydich.mb[i].td.x,maybaydich.mb[i].td.y);
			cout<<maybaydich.mb[i].hd.a;
		}
		if(dan.mb[i].td.x>=0&&dan.mb[i].td.x<=ConW+1&&dan.mb[i].td.y>=0&&dan.mb[i].td.y<=ConW){
			gotoxy(dan.mb[i].td.x,dan.mb[i].td.y);
			SetColor(11);
			if(itrangthaidan==1){
				cout<<dan.mb[i].hd.a;
			}
			if(itrangthaidan==2){
				cout<<dan.mb[i].hd.b;
			}
			if(itrangthaidan==3){
				cout<<dan.mb[i].hd.c;
			}
			SetColor(15);
		}
	}
	if(items.h.td.x>=0&&items.h.td.x<=ConW+1&&items.h.td.y>=0&&items.h.td.y<=ConW){
		gotoxy(items.h.td.x,items.h.td.y);
		SetColor(10);
		cout<<items.h.hd.c;
		SetColor(15);
	}
	if(items.s.td.x>=0&&items.s.td.x<=ConW+1&&items.s.td.y>=0&&items.s.td.y<=ConW){
		gotoxy(items.s.td.x,items.s.td.y);
		SetColor(11);
		cout<<items.s.hd.c;
		SetColor(15);
	}
	if(items.b.td.x>=0&&items.b.td.x<=ConW+1&&items.b.td.y>=0&&items.b.td.y<=ConW){
		gotoxy(items.b.td.x,items.b.td.y);
		SetColor(13);
		cout<<items.b.hd.c;
		SetColor(15);
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

void anitems(MayBay& maybay,Items & items){
	int sx=maybay.td.x-items.s.td.x;
   int sy=maybay.td.y-items.s.td.y;
   if(sy==0&&sx<=0&&sx>=-4){
   	mangbaove=300;
   	items.s.td.x=50;
   	items.s.td.y=5;
   }
   int hx=maybay.td.x-items.h.td.x;
   int hy=maybay.td.y-items.h.td.y;
   if(hy==0&&hx<=0&&hx>=-4){
   	if(maybaylife<5){
   		maybaylife++;
   	}
   	items.h.td.x=50;
   	items.h.td.y=5;
   }
   int bx=maybay.td.x-items.b.td.x;
   int by=maybay.td.y-items.b.td.y;
   if(by==0&&bx<=0&&bx>=-4){
   	if(itrangthaidan<3){
   		itrangthaidan++;
   		isoluongdan=1;
   		goto Nhap4;
   	}
   	Nhap4:;
   	items.b.td.x=50;
   	items.b.td.y=5;
   }
}

void vacham(MayBay& maybay,MayBayDich& maybaydich,Dan & dan,Items&items){
	//va cham dan
	int l;
	for(i=0;i<30;i++){
		for(l=0;l<30;l++){
			int ddanx=maybaydich.mb[i].td.x-dan.mb[l].td.x;
		    int ddany=abs(maybaydich.mb[i].td.y-dan.mb[l].td.y);
		    if(itrangthaidan==1){
		       if(ddany==0&&ddanx<=0&&ddanx>=-4){
		    	    if(dan.mb[l].td.x>=0&&dan.mb[l].td.x<=ConW+1&&dan.mb[l].td.y>=0&&dan.mb[l].td.y<=ConW&&maybaydich.mb[i].td.x>=0&&maybaydich.mb[i].td.x<=ConW&&maybaydich.mb[i].td.y>=0&&maybaydich.mb[i].td.y<=ConW){
		    			diem++;
		    		}
		    		maybaydich.mb[i].td.x=50;
		    		maybaydich.mb[i].td.y=2;
		    		dan.mb[l].td.x=40;
		    		dan.mb[l].td.y=3;
		       }		
		    }
		    if(itrangthaidan==2){
		    	if(ddany==0&&ddanx<=2&&ddanx>=-4){
		    	    if(dan.mb[l].td.x>=0&&dan.mb[l].td.x<=ConW+1&&dan.mb[l].td.y>=0&&dan.mb[l].td.y<=ConW&&maybaydich.mb[i].td.x>=0&&maybaydich.mb[i].td.x<=ConW&&maybaydich.mb[i].td.y>=0&&maybaydich.mb[i].td.y<=ConW){
		    			diem++;
		    		}
		    		maybaydich.mb[i].td.x=50;
		    		maybaydich.mb[i].td.y=2;
		    		dan.mb[l].td.x=40;
		    		dan.mb[l].td.y=3;
		       }
		    }	
		    if(itrangthaidan==3){
		    	if(ddany==0&&ddanx<=4&&ddanx>=-4){
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
	}
	 anitems(maybay,items);
	//va cham may bay
	for(i=0;i<30;i++){
		   int dx=abs(maybay.td.x-maybaydich.mb[i].td.x);
		   int dy=abs(maybay.td.y-maybaydich.mb[i].td.y);
	       
	      if(mangbaove==0){
	      	    if(dx<=4&&dy==0){
	       	      maybaylife--;
	       	      if(itrangthaidan>1){
	       	      	itrangthaidan--;
	       	      }
	       	      if(itrangthaidan==2){
	       	      	isoluongdan=26;
	       	      }
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
   //va cham items vs maybay
   anitems(maybay,items);
}

void shoot(MayBay& maybay,Dan& dan){
	if (checkKey(KEY_S)){
			if(isoluongdan>0){
				for(i=0;i<30;i++){
					if(itrangthaidan==1){
						if(dan.mb[i].td.x>=0&&dan.mb[i].td.x<=ConW+1&&dan.mb[i].td.y>=0&&dan.mb[i].td.y<=ConW){
						}else{
							dan.mb[i].td.x=maybay.td.x+2;
			            	dan.mb[i].td.y=maybay.td.y;
			            	isoluongdan--;
			            	goto Nhap1;
						}
					}
					if(itrangthaidan==2){
						if(dan.mb[i].td.x>=0&&dan.mb[i].td.x<=ConW+1&&dan.mb[i].td.y>=0&&dan.mb[i].td.y<=ConW){
						}else{
							dan.mb[i].td.x=maybay.td.x+1;
			            	dan.mb[i].td.y=maybay.td.y;
			            	isoluongdan--;
			            	goto Nhap1;
						}
					}
					if(itrangthaidan==3){
						if(dan.mb[i].td.x>=0&&dan.mb[i].td.x<=ConW+1&&dan.mb[i].td.y>=0&&dan.mb[i].td.y<=ConW){
						}else{
							dan.mb[i].td.x=maybay.td.x;
			            	dan.mb[i].td.y=maybay.td.y;
			            	isoluongdan--;
			            	goto Nhap1;
						}
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
	vacham(maybay,maybaydich,dan,items);
	Nhap:;
	
		for(i=0;i<30;i++){
		   if(maybaydich.mb[i].td.x>=0&&maybaydich.mb[i].td.x<=ConW&&maybaydich.mb[i].td.y>=0&&maybaydich.mb[i].td.y<=ConW){
			maybaydich.mb[i].td.y++;
		   }else{
			     maybaydich.mb[i].td.x=40;
	             maybaydich.mb[i].td.y=2;
		   }
	    }
	    vacham(maybay,maybaydich,dan,items);
	}
	shoot(maybay,dan);
	bodemso++;
	if(bodemso==10000){
		bodemso=0;
	}
	if(isoluongquaivat>30&&isoluongquaivat<=60){
		sobichia=3;
	}
	if(isoluongquaivat>60&&isoluongquaivat<=120){
		sobichia=2;
	}
	if(isoluongquaivat>120){
		sobichia=1;
	}
	//tao vat pham
	if((isoluongquaivat+1)%50==0){
		iitems=rand()%3+1;
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
	if(bodemso%4==0){
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
	
	vacham(maybay,maybaydich,dan,items);
	
	// dan di chuyen
	
	for(i=0;i<30;i++){
		if(dan.mb[i].td.x>=0&&dan.mb[i].td.x<=ConW+1&&dan.mb[i].td.y>=0&&dan.mb[i].td.y<=ConW){
			dan.mb[i].td.y--;
		}else{
			dan.mb[i].td.x=40;
			dan.mb[i].td.y=2;
		}
	}
	idemsoluongdan++;
	if(itrangthaidan==1){
		if(isoluongdan==0){
			if(bodemso%80==0){
				isoluongdan=26;
			}
		}
	}else{
		if(itrangthaidan==2){
			if(idemsoluongdan%5==0){
			if(isoluongdan<1){
				isoluongdan++;
			}
		}
		}else{
			if(idemsoluongdan%8==0){
			if(isoluongdan<1){
				isoluongdan++;
			}
		}
		}
	}
	
	if(idemsoluongdan==100000){
		idemsoluongdan=0;
	}
	Nhap6:;
	vacham(maybay,maybaydich,dan,items);
}

int main(){
	Nhap3:;
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
	SetColor(11);
	cout<<"you lost ";
	SetColor(15);
	while(1){
		SetColor(14);
		gotoxy(10,15);
		cout<<"Do you want play again ?";
		gotoxy(10,16);
		cout<<"Yes press J and No press L";
			if (checkKey(KEY_L)){
				goto Nhap2;
		}
		if (checkKey(KEY_J)){
				goto Nhap3;
		}
		SetColor(15);
	}
	Nhap2:;
	return 0;
}
