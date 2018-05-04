#include<iostream>
#include<stdlib.h>
#include<Windows.h>
#include<string.h>
#include "Util.h"
#include<ctime>
#include<stdio.h>
#define ConW 25
#define ConH 25

int i,j=0,isoluongdan,idemsoluongdan=0,gameover,maybaylife,mangbaove=0, diem,bodemso=0,sobichia,isoluongquaivat,iitems,itrangthaidan,bmautank[30],bmauboss,checkboss;
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

struct MayBayTank{
	MayBay mb[30];
};

struct Dan{
	MayBay mb[30];
};

struct Items{
	MayBay h;//heart
	MayBay s;//shield
	MayBay b;//bullet
};

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
	maybay.td.y=ConW;
	maybay.td.x=ConW/2;
	strcpy(maybay.hd.a,"~|O|~");
	diem=0;
	for(i=0;i<30;i++){
	    maybaydich.mb[i].td.x=50;
	    maybaydich.mb[i].td.y=2;
		strcpy(maybaydich.mb[i].hd.a,"~|-|~");
		dan.mb[i].td.x=40;
		dan.mb[i].td.y=2;
		strcpy(dan.mb[i].hd.a,"^");
		strcpy(dan.mb[i].hd.b,"| |");
		strcpy(dan.mb[i].hd.c,"|||||");
		maybaytank.mb[i].td.x=60;
		maybaytank.mb[i].td.y=4;
		strcpy(maybaytank.mb[i].hd.a,"~|_-_|~");
		bmautank[i]=6;
		maybayban.mb[i].td.x=50;
		maybayban.mb[i].td.y=6;
		strcpy(maybayban.mb[i].hd.a,"~|!|~");
		dandich.mb[i].td.x=50;
		dandich.mb[i].td.y=8;
		strcpy(dandich.mb[i].hd.a,".");
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
	boss.td.x=30;
	boss.td.y=3;
	strcpy(boss.hd.a,"| |    | |");
}

void HienThi(MayBay&maybay,MayBayDich & maybaydich,Dan& dan,Items & items,MayBayTank&maybaytank,MayBayTank&maybayban,Dan&dandich,MayBay&boss){
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
	cout<<"So luong dan dang co : "<<isoluongdan<<" "<<bmauboss;
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
		if(maybaytank.mb[i].td.x>=0&&maybaytank.mb[i].td.x<=ConW-2&&maybaytank.mb[i].td.y>=0&&maybaytank.mb[i].td.y<=ConW){
			gotoxy(maybaytank.mb[i].td.x,maybaytank.mb[i].td.y);
			SetColor(13);
			cout<<maybaytank.mb[i].hd.a;
			SetColor(15);
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
		if(maybayban.mb[i].td.x>=0&&maybayban.mb[i].td.x<=ConW&&maybayban.mb[i].td.y>=0&&maybayban.mb[i].td.y<=ConW){
			gotoxy(maybayban.mb[i].td.x,maybayban.mb[i].td.y);
			SetColor(8);
			cout<<maybayban.mb[i].hd.a;
			SetColor(15);
		}
		if(dandich.mb[i].td.x>=0&&dandich.mb[i].td.x<=ConW+1&&dandich.mb[i].td.y>=0&&dandich.mb[i].td.y<=ConW){
			gotoxy(dandich.mb[i].td.x,dandich.mb[i].td.y);
			SetColor(14);
			cout<<dandich.mb[i].hd.a;
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
	if(boss.td.x>=0&&boss.td.x<=ConW&&boss.td.y>=0&&boss.td.y<=ConW){
			gotoxy(boss.td.x,boss.td.y);
			cout<<boss.hd.a;
			
	}
	if(boss.td.x>=0&&boss.td.x<=ConW&&boss.td.y-1>=0&&boss.td.y<=ConW){
			gotoxy(boss.td.x,boss.td.y-1);
			cout<<"|___00___|";
			
	}
	if(boss.td.x>=0&&boss.td.x<=ConW&&boss.td.y-2>=0&&boss.td.y<=ConW){
			gotoxy(boss.td.x,boss.td.y-2);
			cout<<"0000000000";
			
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

void vacham(MayBay& maybay,MayBayDich& maybaydich,Dan & dan,Items&items,MayBayTank&maybaytank,MayBayTank&maybayban,Dan&dandich){
	//va cham items vs maybay
   anitems(maybay,items);
	//va cham dan
	int l;
	for(i=0;i<30;i++){
		for(l=0;l<30;l++){
			int ddanx=maybaydich.mb[i].td.x-dan.mb[l].td.x;
		    int ddany=abs(maybaydich.mb[i].td.y-dan.mb[l].td.y);
		    int ddantankx=maybaytank.mb[i].td.x-dan.mb[l].td.x;
		    int ddantanky=maybaytank.mb[i].td.y-dan.mb[l].td.y;
		    int ddanbanx=maybayban.mb[i].td.x-dan.mb[l].td.x;
		    int ddanbany=maybayban.mb[i].td.y-dan.mb[l].td.y;
		    if(itrangthaidan==1){
		       if(ddany==0&&ddanx<=0&&ddanx>=-4){
		    	    if(dan.mb[l].td.x>=0&&dan.mb[l].td.x<=ConW+1&&dan.mb[l].td.y>=0&&dan.mb[l].td.y<=ConW&&maybaydich.mb[i].td.x>=0&&maybaydich.mb[i].td.x<=ConW&&maybaydich.mb[i].td.y>=0&&maybaydich.mb[i].td.y<=ConW){
		    			diem++;
		    		}
		    		maybaydich.mb[i].td.x=50;
		    		maybaydich.mb[i].td.y=2;
		    		dan.mb[l].td.x=40;
		    		dan.mb[l].td.y=2;
		       }
		       if(ddantanky==0&&ddantankx<=0&&ddantankx>=-6){
		       	  if(dan.mb[l].td.x>=0&&dan.mb[l].td.x<=ConW+1&&dan.mb[l].td.y>=0&&dan.mb[l].td.y<=ConW&&maybaytank.mb[i].td.x>=0&&maybaytank.mb[i].td.x<ConW-2&&maybaytank.mb[i].td.y>=0&&maybaytank.mb[i].td.y<ConW){
		       	  	 bmautank[i]--;
		       	  	 if(bmautank[i]==0){
		       	  	 	  diem++;
		       	  	 	  bmautank[i]=6;
		       	  	 	  maybaytank.mb[i].td.x=60;
		       	  	 	  maybaytank.mb[i].td.y=4;
		       	  	      }  
		       	  	      dan.mb[l].td.x=40;
		       	  	 	  dan.mb[l].td.y=2;
					 goto Nhap11; 
		       	     }
		       }
		       if(ddanbany==0&&ddanbanx<=0&&ddanbanx>=-4){
		       	if(dan.mb[l].td.x>=0&&dan.mb[l].td.x<=ConW+1&&dan.mb[l].td.y>=0&&dan.mb[l].td.y<=ConW&&maybayban.mb[i].td.x>=0&&maybayban.mb[i].td.x<=ConW&&maybayban.mb[i].td.y>=0&&maybayban.mb[i].td.y<=ConW){
		       		diem++;
		       		maybayban.mb[i].td.x=50;
		       	     maybayban.mb[i].td.y=6;
		       	     dan.mb[i].td.x=40;
		       	    dan.mb[i].td.y=2;
		       	}
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
		    		dan.mb[l].td.y=2;
		       }
		       if(ddantanky==0&&ddantankx<=2&&ddantankx>=-6){
		       	  if(dan.mb[l].td.x>=0&&dan.mb[l].td.x<=ConW+1&&dan.mb[l].td.y>=0&&dan.mb[l].td.y<=ConW&&maybaytank.mb[i].td.x>=0&&maybaytank.mb[i].td.x<ConW&&maybaytank.mb[i].td.y>=0&&maybaytank.mb[i].td.y<ConW){
		       	  	 bmautank[i]=bmautank[i]-3;
		       	  	 if(bmautank[i]==0){
		       	  	 	  diem++;
		       	  	 	  bmautank[i]=6;
		       	  	 	  maybaytank.mb[i].td.x=60;
		       	  	 	  maybaytank.mb[i].td.y=4;
		       	  	      }  
		       	  	      dan.mb[l].td.x=40;
		       	  	 	  dan.mb[l].td.y=2;
					 goto Nhap11; 
		       	     }
		       }
		       if(ddanbany==0&&ddanbanx<=0&&ddanbanx>=-4){
		       	if(dan.mb[l].td.x>=0&&dan.mb[l].td.x<=ConW+1&&dan.mb[l].td.y>=0&&dan.mb[l].td.y<=ConW&&maybayban.mb[i].td.x>=0&&maybayban.mb[i].td.x<=ConW&&maybayban.mb[i].td.y>=0&&maybayban.mb[i].td.y<=ConW){
		       		diem++;
		       			maybayban.mb[i].td.x=50;
		       			maybayban.mb[i].td.y=6;
		       			dan.mb[i].td.x=40;
		       	        dan.mb[i].td.y=2;
		       	}
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
		    		dan.mb[l].td.y=2;
		       }
		       if(ddantanky==0&&ddantankx<=4&&ddantankx>=-6){
		       	  if(dan.mb[l].td.x>=0&&dan.mb[l].td.x<=ConW+1&&dan.mb[l].td.y>=0&&dan.mb[l].td.y<=ConW&&maybaytank.mb[i].td.x>=0&&maybaytank.mb[i].td.x<ConW&&maybaytank.mb[i].td.y>=0&&maybaytank.mb[i].td.y<ConW){
		       	  	 bmautank[i]=0;
		       	  	 if(bmautank[i]==0){
		       	  	 	  diem++;
		       	  	 	  bmautank[i]=6;
		       	  	 	  maybaytank.mb[i].td.x=60;
		       	  	 	  maybaytank.mb[i].td.y=4;
		       	  	      }  
		       	  	      dan.mb[l].td.x=40;
		       	  	 	  dan.mb[l].td.y=3;
					 goto Nhap11; 
		       	     }
		       }
		       if(ddanbany==0&&ddanbanx<=4&&ddanbanx>=-4){
		       	if(dan.mb[l].td.x>=0&&dan.mb[l].td.x<=ConW+1&&dan.mb[l].td.y>=0&&dan.mb[l].td.y<=ConW&&maybayban.mb[i].td.x>=0&&maybayban.mb[i].td.x<=ConW&&maybayban.mb[i].td.y>=0&&maybayban.mb[i].td.y<=ConW){
		       		diem++;
		       		maybayban.mb[i].td.x=50;
		       		maybayban.mb[i].td.y=6;
		       		dan.mb[i].td.x=40;
		       	    dan.mb[i].td.y=3;
		       	}
		       }
		    }	
		}
	}
	 anitems(maybay,items);
	//va cham may bay
	for(i=0;i<30;i++){
		   int dx=abs(maybay.td.x-maybaydich.mb[i].td.x);
		   int dy=abs(maybay.td.y-maybaydich.mb[i].td.y);
	       int dtankx=-maybay.td.x+maybaytank.mb[i].td.x;
	       int dtanky=abs(maybay.td.y-maybaytank.mb[i].td.y);
	       int ddandichx=maybay.td.x-dandich.mb[i].td.x;
	       int ddandichy=maybay.td.y-dandich.mb[i].td.y;
	       int dmaybaybanx=abs(maybay.td.x-maybayban.mb[i].td.x);
	       int dmaybaybany=maybay.td.y-maybayban.mb[i].td.y;
	      if(mangbaove==0){
	      	    if(dx<=4&&dy==0){
	       	      maybaylife--;
	       	         if(itrangthaidan>1){
	       	      	    itrangthaidan--;
	       	            }
	       	         if(itrangthaidan==2){
	       	      	    isoluongdan=1;
	       	            }
	       	            mangbaove=100;
		             if(maybaylife==0){
		    	       gameover=1;
			         }
				    
	              }
	            if(ddandichx<=0&&ddandichx>=-4&&ddandichy==0){
	            	maybaylife--;
	            	if(itrangthaidan>1){
	       	      	    itrangthaidan--;
	       	            }
	       	         if(itrangthaidan==2){
	       	      	    isoluongdan=1;
	       	            }
	       	            mangbaove=100;
		             if(maybaylife==0){
		    	       gameover=1;
			         }
	            }
				if(dmaybaybanx<=4&&dmaybaybany==0){
					maybaylife--;
	            	if(itrangthaidan>1){
	       	      	    itrangthaidan--;
	       	            }
	       	         if(itrangthaidan==2){
	       	      	    isoluongdan=1;
	       	            }
	       	            mangbaove=100;
		             if(maybaylife==0){
		    	       gameover=1;
			         }
				}  
	            if(dtankx>=-6&&dtankx<=4&&dtanky==0){
	       	      maybaylife--;
	       	         if(itrangthaidan>1){
	       	      	    itrangthaidan--;
	       	            }
	       	         if(itrangthaidan==2){
	       	      	    isoluongdan=1;
	       	            }
	       	            mangbaove=100;
		             if(maybaylife==0){
		    	       gameover=1;
			         }
				    
	              }
	      }
   }
   Nhap11:;
   if(mangbaove>0){
   	mangbaove--;
   }
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

void xuly(MayBay maybay,MayBayDich & maybaydich,Dan & dan,Items & items,MayBayTank&maybaytank,MayBayTank&maybayban,Dan&dandich){
	//xu ly may bay dich
	int ingaunhien=rand()%20;
	if(bodemso%sobichia==0){
	    if(ingaunhien%4==0){
		   for(i=0;i<30;i++){
		      if(maybaydich.mb[i].td.x>=0&&maybaydich.mb[i].td.x<=ConW&&maybaydich.mb[i].td.y>=0&&maybaydich.mb[i].td.y<=ConW){
		      }else{
		      	   if(checkboss!=1){
		   	       maybaydich.mb[i].td.x=rand()%ConW+1;
		           maybaydich.mb[i].td.y=0;
		           isoluongquaivat++;
		           goto Nhap;}
		   }
		}
	}
	
	vacham(maybay,maybaydich,dan,items,maybaytank,maybayban,dandich);
	Nhap:;
	
		for(i=0;i<30;i++){
		   if(maybaydich.mb[i].td.x>=0&&maybaydich.mb[i].td.x<=ConW&&maybaydich.mb[i].td.y>=0&&maybaydich.mb[i].td.y<=ConW){
			maybaydich.mb[i].td.y++;
		   }else{
			     maybaydich.mb[i].td.x=50;
	             maybaydich.mb[i].td.y=2;
		   }
	    }
	    vacham(maybay,maybaydich,dan,items,maybaytank,maybayban,dandich);
	}
	//xu ly may bay tank
	if(bodemso%sobichia==0){
		if(ingaunhien%10==0){
			for(i=0;i<30;i++){
				if(maybaytank.mb[i].td.x>=0&&maybaytank.mb[i].td.x<ConW-2&&maybaytank.mb[i].td.y>=0&&maybaytank.mb[i].td.y<ConW){
				}else{
					int ixuathien=rand()%24+1;
					for(int e=0;e<30;e++){
						if(maybaydich.mb[i].td.x>=0&&maybaydich.mb[i].td.x<=ConW&&maybaydich.mb[i].td.y<=3){
							goto Nhap10;
					    }
					}
					if(checkboss!=1){
					maybaytank.mb[i].td.x=ixuathien;
					maybaytank.mb[i].td.y=0;
					isoluongquaivat++;
					goto Nhap10;}
				}
			}
		}
		Nhap10:;
		vacham(maybay,maybaydich,dan,items,maybaytank,maybayban,dandich);
		for(i=0;i<30;i++){
			if(maybaytank.mb[i].td.x>=0&&maybaytank.mb[i].td.x<ConW-2&&maybaytank.mb[i].td.y>=0&&maybaytank.mb[i].td.y<ConW){
				maybaytank.mb[i].td.y++;
			}else{
				maybaytank.mb[i].td.x=60;
				maybaytank.mb[i].td.y=4;
				bmautank[i]=6;
			}
		}
		vacham(maybay,maybaydich,dan,items,maybaytank,maybayban,dandich);
	}
	//xu ly may bay ban
	if(bodemso%(sobichia+3)==0){
	    if(ingaunhien%17==0){
		   for(i=0;i<30;i++){
		      if(maybayban.mb[i].td.x>=0&&maybayban.mb[i].td.x<=ConW&&maybayban.mb[i].td.y>=0&&maybayban.mb[i].td.y<=ConW){
		      }else{
		      	   if(checkboss!=1){
		   	       maybayban.mb[i].td.x=rand()%ConW+1;
		           maybayban.mb[i].td.y=0;
		           isoluongquaivat++;
		           goto Nhap20;}
		   }
		}
	}
	
	Nhap20:;
		vacham(maybay,maybaydich,dan,items,maybaytank,maybayban,dandich);
		for(i=0;i<30;i++){
		   if(maybayban.mb[i].td.x>=0&&maybayban.mb[i].td.x<=ConW&&maybayban.mb[i].td.y>=0&&maybayban.mb[i].td.y<=ConW){
			maybayban.mb[i].td.y++;
		   }else{
			     maybayban.mb[i].td.x=50;
	             maybayban.mb[i].td.y=6;
		   }
	    }
	    vacham(maybay,maybaydich,dan,items,maybaytank,maybayban,dandich);
	}
	
	
	shoot(maybay,dan);
	bodemso++;
	//toc do  game;
	if(bodemso==10000){
		bodemso=1;
	}
	if(isoluongquaivat>=0&&isoluongquaivat<=160){
		sobichia=4;
	}
	if(isoluongquaivat>160&&isoluongquaivat<=1120){
		sobichia=3;
	}
	if(isoluongquaivat>1120){
		sobichia=2;
	}
	vacham(maybay,maybaydich,dan,items,maybaytank,maybayban,dandich);
	//tao vat pham
	if((isoluongquaivat+1)%30==0){
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
	vacham(maybay,maybaydich,dan,items,maybaytank,maybayban,dandich);
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
	
	vacham(maybay,maybaydich,dan,items,maybaytank,maybayban,dandich);
	
	// dan di chuyen
	
	for(i=0;i<30;i++){
		if(dan.mb[i].td.x>=0&&dan.mb[i].td.x<=ConW+1&&dan.mb[i].td.y>=0&&dan.mb[i].td.y<=ConW){
			dan.mb[i].td.y--;
		}else{
			dan.mb[i].td.x=40;
			dan.mb[i].td.y=2;
		}
	}
	vacham(maybay,maybaydich,dan,items,maybaytank,maybayban,dandich);
	idemsoluongdan++;
	if(itrangthaidan==1){
		if(idemsoluongdan%3==0){
			if(isoluongdan<1){
				isoluongdan++;
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
		    if(idemsoluongdan%7==0){
			   if(isoluongdan<1){
				  isoluongdan++;
			   }
		    }
		}
	}
	
	if(idemsoluongdan==100000){
		idemsoluongdan=0;
	}
	//dan dich ban
	if(bodemso%5==0){
	for(i=0;i<30;i++){
		
			if(dandich.mb[i].td.x<=ConW+1&&dandich.mb[i].td.x>=0&&dandich.mb[i].td.y>=0&&dandich.mb[i].td.y<=ConW){
				dandich.mb[i].td.y++;
			}else{
				dandich.mb[i].td.x=50;
				dandich.mb[i].td.y=8;
				
			    if(maybayban.mb[i].td.x>=0&&maybayban.mb[i].td.x<=ConW&&maybayban.mb[i].td.y>=0&&maybayban.mb[i].td.y<=ConW){		
					   dandich.mb[i].td.x=maybayban.mb[i].td.x+2;
					   dandich.mb[i].td.y=maybayban.mb[i].td.y+1;
				    
				}
			}
		}
	}
	Nhap6:;
	vacham(maybay,maybaydich,dan,items,maybaytank,maybayban,dandich);
	if(isoluongquaivat%50==0&&isoluongquaivat!=0){
		checkboss=1;
	}
}

void bossdichuyen(MayBay&boss,MayBay&maybay){
	int ihuongdichuyen=rand()%3+1;
	if(ihuongdichuyen==1){
		if(boss.td.x>0&&boss.td.x<=ConW-6&&boss.td.y>=0&&boss.td.y<=ConW){
		   if(boss.td.x+2>maybay.td.x){
		   	boss.td.x--;
		   }else{
		   	boss.td.x++;
		   }
		}
	}
	if(ihuongdichuyen==2){
		if(boss.td.x>0&&boss.td.x<=ConW-4&&boss.td.y>=0&&boss.td.y<=ConW){
			boss.td.x--;
		}
	}
	if(ihuongdichuyen==2){
		if(boss.td.x>0&&boss.td.x<=ConW-6&&boss.td.y>=0&&boss.td.y<=ConW){
			boss.td.x++;
		}
	}
}

void vachamboss(MayBay&boss,MayBay&maybay,Dan&dan){
	int dbossx=boss.td.x-maybay.td.x;
	int dbossy=boss.td.y-maybay.td.y;
	if(boss.td.x>=0&&boss.td.x<=ConW&&boss.td.y>=0&&boss.td.y<=ConW){
		if(mangbaove==0){
			if(dbossy>=0&&dbossy<=2&&dbossx>=-9&&dbossx<=4){
			maybaylife--;
			mangbaove=100;
			if(maybaylife==0){
		    	gameover=1;
			   }
			if(itrangthaidan>1){
	       	    itrangthaidan--;
	       	  }
		    }
		}
	}
	if(mangbaove>0){
		mangbaove--;
	}
	// va cham dan vs boss
	for(i=0;i<30;i++){
		int ddbossx=boss.td.x-dan.mb[i].td.x;
		int ddbossy=boss.td.y-dan.mb[i].td.y;
		if(boss.td.x>=0&&boss.td.x<=ConW&&boss.td.y>=0&&boss.td.y<=ConW&&dan.mb[i].td.x>=0&&dan.mb[i].td.x<=ConW+1&&dan.mb[i].td.y>=0&&dan.mb[i].td.y<=ConW){
			if(itrangthaidan==1){
				if(ddbossy==0&&ddbossx<=0&&ddbossy>=-9){
					dan.mb[i].td.x=40;
					dan.mb[i].td.y=2;
					bmauboss--;
				}
			}
			if(itrangthaidan==2){
				if(ddbossy==0&&ddbossx<=2&&ddbossy>=-9){
					dan.mb[i].td.x=40;
					dan.mb[i].td.y=2;
					bmauboss=bmauboss-10;
				}
			}
		}
	}
}

void xulyboss(MayBay&maybay,MayBay&boss,Items&items,Dan&dan){
	if(boss.td.x>=0&&boss.td.x<=ConW&&boss.td.y>=0&&boss.td.y<=ConW){
	}else{
		boss.td.x=3;
		boss.td.y=3;
	}
	bossdichuyen(boss,maybay);
	vachamboss(boss,maybay,dan);
	anitems(maybay,items);
	for(i=0;i<30;i++){
		if(dan.mb[i].td.x>=0&&dan.mb[i].td.x<=ConW+1&&dan.mb[i].td.y>=0&&dan.mb[i].td.y<=ConW){
			dan.mb[i].td.y--;
		}else{
			dan.mb[i].td.x=40;
			dan.mb[i].td.y=2;
		}
	}
	if((isoluongquaivat+1)%30==0){
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
	idemsoluongdan++;
	if(itrangthaidan==1){
		if(idemsoluongdan%3==0){
			if(isoluongdan<1){
				isoluongdan++;
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
		    if(idemsoluongdan%7==0){
			   if(isoluongdan<1){
				  isoluongdan++;
			   }
		    }
		}
	}
	
	if(idemsoluongdan==100000){
		idemsoluongdan=0;
	}
	vachamboss(boss,maybay,dan);
}

int main(){
	Nhap3:;
	ShowCur(0);
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
		DieuKhien(maybay);
		HienThi(maybay,maybaydich,dan,items,maybaytank,maybayban,dandich,boss);
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
		DieuKhien(maybay);
		xulyboss(maybay,boss,items,dan);
		HienThi(maybay,maybaydich,dan,items,maybaytank,maybayban,dandich,boss);
		if(bmauboss<=0){
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
	system("cls");
	HienThi(maybay,maybaydich,dan,items,maybaytank,maybayban,dandich,boss);
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
