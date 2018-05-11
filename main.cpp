
#include<stdlib.h>
#include"Menu.h"
#include<ctime>
#include"KhoiTaoHinhDangVaToaDo.h"
#include"Hienthi.h"
#include"DieuKhienMayBay.h"
#include"XuLyCacVaCham.h"

int i,j=0,isoluongdan,idemsoluongdan=0,gameover,maybaylife,mangbaove=0, diem,bodemso=0,sobichia,isoluongquaivat,iitems,itrangthaidan,bmautank[30],bmauboss,checkboss;
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

void xulymaybaydich(MayBayDich&maybaydich,MayBayTank&maybaytank){
	int ingaunhien=rand()%20;
	if(bodemso%sobichia==0){
	    if(ingaunhien%4==0){
	    	for(int e=0;e<30;e++){
						if(maybaytank.mb[e].td.x>=0&&maybaytank.mb[e].td.x<=ConW&&maybaytank.mb[e].td.y<=1){
							goto Nhap39;
					    }
					}
		   for(i=0;i<30;i++){
		      if(maybaydich.mb[i].td.x>=0&&maybaydich.mb[i].td.x<=ConW&&maybaydich.mb[i].td.y>=0&&maybaydich.mb[i].td.y<=ConW){
		      }else{
		      	   if(checkboss!=1){
		   	           maybaydich.mb[i].td.x=rand()%ConW+1;
		               maybaydich.mb[i].td.y=0;
		               gotoxy(maybaydich.mb[i].td.x,maybaydich.mb[i].td.y);
			           cout<<maybaydich.mb[i].hd.a;
		               isoluongquaivat++;
		               goto Nhap;}
		   }
		}
		Nhap39:;
	    }
	Nhap:;
	
		for(i=0;i<30;i++){
		   if(maybaydich.mb[i].td.x>=0&&maybaydich.mb[i].td.x<=ConW&&maybaydich.mb[i].td.y>=0&&maybaydich.mb[i].td.y<=ConW){
		   	gotoxy(maybaydich.mb[i].td.x,maybaydich.mb[i].td.y);
		   	cout<<"     ";
			maybaydich.mb[i].td.y++;
			gotoxy(maybaydich.mb[i].td.x,maybaydich.mb[i].td.y);
			cout<<maybaydich.mb[i].hd.a;
		   }else{
		   	     if(maybaydich.mb[i].td.y==ConW+1){
				     gotoxy(maybaydich.mb[i].td.x,maybaydich.mb[i].td.y);
				     for(i=0;i<5;i++){
				 	 	SetColor(10);
				 	 	 putchar(196);
				  	     SetColor(15);
				 	 }
		   	        }
			     maybaydich.mb[i].td.x=50;
	             maybaydich.mb[i].td.y=2;
		   }
	    }
	}
}

void xulymaybaytank(MayBayTank&maybaytank,MayBayDich&maybaydich){
	int ingaunhien=rand()%20;
	if(bodemso%sobichia==0){
		if(ingaunhien%10==0){
			for(i=0;i<30;i++){
				if(maybaytank.mb[i].td.x>=0&&maybaytank.mb[i].td.x<ConW-2&&maybaytank.mb[i].td.y>=0&&maybaytank.mb[i].td.y<=ConW){
				}else{
					int ixuathien=rand()%22+1;
					for(int e=0;e<30;e++){
						if(maybaydich.mb[e].td.x>=0&&maybaydich.mb[e].td.x<=ConW&&maybaydich.mb[e].td.y<=1){
							goto Nhap10;
					    }
					}
					if(checkboss!=1){
					maybaytank.mb[i].td.x=ixuathien;
					maybaytank.mb[i].td.y=0;
					gotoxy(maybaytank.mb[i].td.x,maybaytank.mb[i].td.y);
			        SetColor(13);
			        cout<<maybaytank.mb[i].hd.a;
			        SetColor(15);
					isoluongquaivat++;
					goto Nhap10;}
				}
			}
		}
		Nhap10:;
		for(i=0;i<30;i++){
			if(maybaytank.mb[i].td.x>=0&&maybaytank.mb[i].td.x<ConW-2&&maybaytank.mb[i].td.y>=0&&maybaytank.mb[i].td.y<=ConW){
				gotoxy(maybaytank.mb[i].td.x,maybaytank.mb[i].td.y);
				cout<<"       ";
				maybaytank.mb[i].td.y++;
				gotoxy(maybaytank.mb[i].td.x,maybaytank.mb[i].td.y);
			    SetColor(13);
			    cout<<maybaytank.mb[i].hd.a;
			    SetColor(15);
			}else{
				if(maybaytank.mb[i].td.y==ConW+1){
				  gotoxy(maybaytank.mb[i].td.x,maybaytank.mb[i].td.y);
				  for(i=0;i<7;i++){
				 	 	SetColor(10);
				 	 	 putchar(196);
				  	     SetColor(15);
				 	 }
				}
				maybaytank.mb[i].td.x=60;
				maybaytank.mb[i].td.y=4;
				bmautank[i]=6;
			}
		}
	}
}

void xulymaybayban(MayBayTank&maybayban){
	int ingaunhien=rand()%20;
	if(bodemso%(sobichia+3)==0){
	    if(ingaunhien%17==0){
		   for(i=0;i<30;i++){
		      if(maybayban.mb[i].td.x>=0&&maybayban.mb[i].td.x<=ConW&&maybayban.mb[i].td.y>=0&&maybayban.mb[i].td.y<=ConW){
		      }else{
		      	   if(checkboss!=1){
		   	         maybayban.mb[i].td.x=rand()%ConW+1;
		             maybayban.mb[i].td.y=0;
		             gotoxy(maybayban.mb[i].td.x,maybayban.mb[i].td.y);
			         SetColor(11);
			         cout<<maybayban.mb[i].hd.a;
			         SetColor(15);
		             isoluongquaivat++;
		             goto Nhap20;}
		   }
		}
	}
	
	Nhap20:;
		for(i=0;i<30;i++){
		   if(maybayban.mb[i].td.x>=0&&maybayban.mb[i].td.x<=ConW&&maybayban.mb[i].td.y>=0&&maybayban.mb[i].td.y<=ConW){
		   	gotoxy(maybayban.mb[i].td.x,maybayban.mb[i].td.y);
		   	cout<<"     ";
			maybayban.mb[i].td.y++;
			gotoxy(maybayban.mb[i].td.x,maybayban.mb[i].td.y);
			SetColor(11);
			cout<<maybayban.mb[i].hd.a;
			SetColor(15);
		   }else{
		   	if(maybayban.mb[i].td.y==ConW+1){
				 	 gotoxy(maybayban.mb[i].td.x,maybayban.mb[i].td.y);
				 	 for(i=0;i<5;i++){
				 	 	SetColor(10);
				 	 	 putchar(196);
				  	     SetColor(15);
				 	 }
		   	     }
		   	     maybayban.mb[i].td.x=50;
	             maybayban.mb[i].td.y=6;
		   }
	    }
	}
}

void xulyitems(Items&items){
	if((isoluongquaivat+1)%30==0){
		iitems=rand()%3+1;
		if(iitems==1){
			items.h.td.x=rand()%ConW+1;
			items.h.td.y=0;
			gotoxy(items.h.td.x,items.h.td.y);
		    SetColor(10);
		    cout<<items.h.hd.c;
		    SetColor(15);
		}
		if(iitems==2){
			items.s.td.x=rand()%ConW+1;
			items.s.td.y=0;
			gotoxy(items.s.td.x,items.s.td.y);
		    SetColor(11);
		    cout<<items.s.hd.c;
		    SetColor(15);
		}
		if(iitems==3){
			items.b.td.x=rand()%ConW+1;
			items.b.td.y=0;
			gotoxy(items.b.td.x,items.b.td.y);
		    SetColor(13);
		    cout<<items.b.hd.c;
		    SetColor(15);
		}
		isoluongquaivat++;
	}
	if(bodemso%4==0){
		if(items.h.td.x>=0&&items.h.td.x<=ConW+1&&items.h.td.y>=0&&items.h.td.y<=ConW){
		   gotoxy(items.h.td.x,items.h.td.y);
		   cout<<" ";
		   items.h.td.y++;
		   gotoxy(items.h.td.x,items.h.td.y);
		   SetColor(10);
		   cout<<items.h.hd.c;
		   SetColor(15);	
		}else{
			if(items.h.td.y==ConW+1){
			  SetColor(10);
			  gotoxy(items.h.td.x,items.h.td.y);
			  putchar(196);
			  SetColor(15);	
			}
			items.h.td.x=50;
	        items.h.td.y=5;
		}
		if(items.s.td.x>=0&&items.s.td.x<=ConW+1&&items.s.td.y>=0&&items.s.td.y<=ConW){
			gotoxy(items.s.td.x,items.s.td.y);
			cout<<" ";
			items.s.td.y++;
			gotoxy(items.s.td.x,items.s.td.y);
		    SetColor(11);
		    cout<<items.s.hd.c;
		    SetColor(15);
		}else{
			if(items.s.td.y==ConW+1){
			  SetColor(10);
			  gotoxy(items.s.td.x,items.s.td.y);
			  putchar(196);
			  SetColor(15);	
			}
			items.s.td.x=50;
	        items.s.td.y=5;
		}
		if(items.b.td.x>=0&&items.b.td.x<=ConW+1&&items.b.td.y>=0&&items.b.td.y<=ConW){
			gotoxy(items.b.td.x,items.b.td.y);
			cout<<" ";
			items.b.td.y++;
			gotoxy(items.b.td.x,items.b.td.y);
		    SetColor(13);
		    cout<<items.b.hd.c;
		    SetColor(15);
		}else{
			if(items.b.td.y==ConW+1){
			  SetColor(10);
			  gotoxy(items.b.td.x,items.b.td.y);
			  putchar(196);
			  SetColor(15);	
			}
			items.b.td.x=50;
	        items.b.td.y=5;
		}
	}
}

void xuly(MayBay maybay,MayBayDich & maybaydich,Dan & dan,Items & items,MayBayTank&maybaytank,MayBayTank&maybayban,Dan&dandich){
	xulymaybaydich(maybaydich,maybaytank);
	vacham(maybay,maybaydich,dan,items,maybaytank,maybayban,dandich,diem,bmautank,itrangthaidan,maybaylife,mangbaove,gameover);
	xulymaybaytank(maybaytank,maybaydich);
	vacham(maybay,maybaydich,dan,items,maybaytank,maybayban,dandich,diem,bmautank,itrangthaidan,maybaylife,mangbaove,gameover);
	xulymaybayban(maybayban);
	vacham(maybay,maybaydich,dan,items,maybaytank,maybayban,dandich,diem,bmautank,itrangthaidan,maybaylife,mangbaove,gameover);
	
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
	vacham(maybay,maybaydich,dan,items,maybaytank,maybayban,dandich,diem,bmautank,itrangthaidan,maybaylife,mangbaove,gameover);
	
	xulyitems(items);
	
	vacham(maybay,maybaydich,dan,items,maybaytank,maybayban,dandich,diem,bmautank,itrangthaidan,maybaylife,mangbaove,gameover);
	
	// dan di chuyen
	
	for(i=0;i<30;i++){
		if(dan.mb[i].td.x>=0&&dan.mb[i].td.x<=ConW+1&&dan.mb[i].td.y>0&&dan.mb[i].td.y<=ConW){
			gotoxy(dan.mb[i].td.x,dan.mb[i].td.y);
			if(itrangthaidan==1){
				cout<<" ";
			}
			if(itrangthaidan==2){
				cout<<"   ";
			}
			if(itrangthaidan==3){
				cout<<"     ";
			}
			dan.mb[i].td.y--;
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
		}else{
			gotoxy(dan.mb[i].td.x,dan.mb[i].td.y);
			if(itrangthaidan==1){
				cout<<" ";
			}
			if(itrangthaidan==2){
				cout<<"   ";
			}
			if(itrangthaidan==3){
				cout<<"     ";
			}
			dan.mb[i].td.x=40;
			dan.mb[i].td.y=2;
		}
	}
	vacham(maybay,maybaydich,dan,items,maybaytank,maybayban,dandich,diem,bmautank,itrangthaidan,maybaylife,mangbaove,gameover);
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
				gotoxy(dandich.mb[i].td.x,dandich.mb[i].td.y);
				cout<<" ";
				dandich.mb[i].td.y++;
				gotoxy(dandich.mb[i].td.x,dandich.mb[i].td.y);
			    SetColor(14);
			    cout<<dandich.mb[i].hd.a;
			    SetColor(15);
			}else{
				if(dandich.mb[i].td.y==ConW+1){
				  SetColor(10);
				  gotoxy(dandich.mb[i].td.x,dandich.mb[i].td.y);
				  putchar(196);
				  SetColor(15);
				  dandich.mb[i].td.x=50;
				  dandich.mb[i].td.y=8;	
				}
				
			    if(maybayban.mb[i].td.x>=0&&maybayban.mb[i].td.x<=ConW-1&&maybayban.mb[i].td.y>=0&&maybayban.mb[i].td.y<=ConW){		
					   dandich.mb[i].td.x=maybayban.mb[i].td.x+2;
					   dandich.mb[i].td.y=maybayban.mb[i].td.y+1;
				       gotoxy(dandich.mb[i].td.x,dandich.mb[i].td.y);
			           SetColor(14);
			           cout<<dandich.mb[i].hd.a;
			           SetColor(15);
				}
			}
		}
	}
	Nhap6:;
	vacham(maybay,maybaydich,dan,items,maybaytank,maybayban,dandich,diem,bmautank,itrangthaidan,maybaylife,mangbaove,gameover);
	if(isoluongquaivat%50==0&&isoluongquaivat!=0){
		checkboss=1;
	}
}

void vachamboss(MayBay&boss,MayBay&maybay,Dan&dan){
	int dbossx=boss.td.x-maybay.td.x;
	int dbossy=boss.td.y-maybay.td.y;
	if(boss.td.x>=0&&boss.td.x<=ConW&&boss.td.y>=0&&boss.td.y<=ConW){
		if(mangbaove==0){
			if(dbossy>=0&&dbossy<=2&&dbossx>=-9&&dbossx<=4){
			maybaylife--;
			mangbaove=300;
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
		if(mangbaove==0){
   		gotoxy(maybay.td.x,maybay.td.y-1);
   		cout<<"     ";
   	    }
	}
	// va cham dan vs boss
	for(i=0;i<30;i++){
		int ddbossx=boss.td.x-dan.mb[i].td.x;
		int ddbossy=boss.td.y-dan.mb[i].td.y;
		if(boss.td.x>=0&&boss.td.x<=ConW&&boss.td.y>=0&&boss.td.y<=ConW&&dan.mb[i].td.x>=0&&dan.mb[i].td.x<=ConW+1&&dan.mb[i].td.y>=0&&dan.mb[i].td.y<=ConW){
			if(itrangthaidan==1){
				if(ddbossy==0&&ddbossx<=0&&ddbossy>=-9){
					gotoxy(dan.mb[i].td.x,dan.mb[i].td.y);
		    		cout<<" ";
					dan.mb[i].td.x=40;
					dan.mb[i].td.y=2;
					gotoxy(boss.td.x,boss.td.y);
			        cout<<boss.hd.a;
					bmauboss--;
				}
			}
			if(itrangthaidan==2){
				if(ddbossy==0&&ddbossx<=2&&ddbossy>=-9){
					gotoxy(dan.mb[i].td.x,dan.mb[i].td.y);
		    		cout<<"   ";
					dan.mb[i].td.x=40;
					dan.mb[i].td.y=2;
					gotoxy(boss.td.x,boss.td.y);
			        cout<<boss.hd.a;
					bmauboss=bmauboss-10;
				}
			}
			if(itrangthaidan==3){
				if(ddbossy==0&&ddbossx<=2&&ddbossy>=-9){
					gotoxy(dan.mb[i].td.x,dan.mb[i].td.y);
		    		cout<<"     ";
					dan.mb[i].td.x=40;
					dan.mb[i].td.y=2;
					gotoxy(boss.td.x,boss.td.y);
			        cout<<boss.hd.a;
					bmauboss=bmauboss-100;
				}
			}
		}
	}
}

void bossdichuyen(MayBay&boss,MayBay&maybay,Dan&dan){
    if(ihuongdichuyenboss!=3){
    	int randboss = rand()%40;
    	if(randboss == 4 ){
    		ihuongdichuyenboss=3;
    	}
    }
	if(ihuongdichuyenboss==1){
		if(boss.td.x>1&&boss.td.x<=ConW-6&&boss.td.y>=0&&boss.td.y<=ConW){
		   	gotoxy(boss.td.x,boss.td.y);
		   	cout<<"          ";
		   	gotoxy(boss.td.x,boss.td.y-1);
		   	cout<<"          ";
		   	gotoxy(boss.td.x,boss.td.y-2);
		   	cout<<"          ";
		   	boss.td.x--;
		   	gotoxy(boss.td.x,boss.td.y);
			cout<<boss.hd.a;
			gotoxy(boss.td.x,boss.td.y-1);
			cout<<"|___00___|";
			gotoxy(boss.td.x,boss.td.y-2);
			cout<<"0000000000";
			if(boss.td.x==1){
				ihuongdichuyenboss=2;
			}
	    }
	}
	if(ihuongdichuyenboss==2){
		if(boss.td.x>=0&&boss.td.x<=ConW-7&&boss.td.y>=0&&boss.td.y<=ConW){
			gotoxy(boss.td.x,boss.td.y);
		   	cout<<"          ";
		   	gotoxy(boss.td.x,boss.td.y-1);
		   	cout<<"          ";
		   	gotoxy(boss.td.x,boss.td.y-2);
		   	cout<<"          ";
		   	boss.td.x++;
		   	gotoxy(boss.td.x,boss.td.y);
			cout<<boss.hd.a;
			gotoxy(boss.td.x,boss.td.y-1);
			cout<<"|___00___|";
			gotoxy(boss.td.x,boss.td.y-2);
			cout<<"0000000000";
			if(boss.td.x==ConW-6){
				ihuongdichuyenboss=1;
			}
		}
	}
	if(ihuongdichuyenboss==3){
		if(boss.td.x>=0&&boss.td.x<=ConW-6&&boss.td.y>=0&&boss.td.y<ConW){
			gotoxy(boss.td.x,boss.td.y);
		   	cout<<"          ";
		   	gotoxy(boss.td.x,boss.td.y-1);
		   	cout<<"          ";
		   	gotoxy(boss.td.x,boss.td.y-2);
		   	cout<<"          ";
		   	boss.td.y++;
		   	gotoxy(boss.td.x,boss.td.y);
			cout<<boss.hd.a;
			gotoxy(boss.td.x,boss.td.y-1);
			cout<<"|___00___|";
			gotoxy(boss.td.x,boss.td.y-2);
			cout<<"0000000000";
		}
		if(boss.td.y==ConW){
			vachamboss(boss,maybay,dan);
			gotoxy(boss.td.x,boss.td.y);
		   	cout<<"          ";
		   	gotoxy(boss.td.x,boss.td.y-1);
		   	cout<<"          ";
		   	gotoxy(boss.td.x,boss.td.y-2);
		   	cout<<"          ";
		   	boss.td.y=30;
		   	ihuongdichuyenboss=1;
		}
	}
   
}

void xulyboss(MayBay&maybay,MayBay&boss,Items&items,Dan&dan,Dan&dandich,int &maybaylife,int &itrangthaidan,int&mangbaove){
	bossdichuyen(boss,maybay,dandich);
	vachamboss(boss,maybay,dan);
	anitems(maybay,items,maybaylife,itrangthaidan,mangbaove);
	if(boss.td.x>=0&&boss.td.x<=ConW&&boss.td.y>=0&&boss.td.y<=ConW){
	}else{
		boss.td.x=6;
		boss.td.y=2;
	}
	vachamboss(boss,maybay,dan);
	
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
		xulyboss(maybay,boss,items,dan,dandich,maybaylife,itrangthaidan,mangbaove);
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
