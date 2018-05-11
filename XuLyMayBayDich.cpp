#include"XuLyMayBayDich.h"
#include"Menu.h"
#include"Umtil.h"

void xulymaybaydich(MayBayDich&maybaydich,MayBayTank&maybaytank,int& bodemso,int& sobichia,int& isoluongquaivat,int&checkboss){
	int ingaunhien=rand()%20;
	if(bodemso%sobichia==0){
	    if(ingaunhien%4==0){
	    	for(int e=0;e<30;e++){
						if(maybaytank.mb[e].td.x>=0&&maybaytank.mb[e].td.x<=ConW&&maybaytank.mb[e].td.y<=1){
							goto Nhap39;
					    }
					}
		   for(int i=0;i<30;i++){
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
	
		for(int i=0;i<30;i++){
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
void xulymaybaytank(MayBayTank&maybaytank,MayBayDich&maybaydich,int&bodemso,int&sobichia,int&isoluongquaivat,int&checkboss,int bmautank[30])
{
	int ingaunhien=rand()%20;
	if(bodemso%sobichia==0){
		if(ingaunhien%10==0){
			for(int i=0;i<30;i++){
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
		for(int i=0;i<30;i++){
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

void xulymaybayban(MayBayTank&maybayban,int&bodemso,int&sobichia,int&isoluongquaivat,int&checkboss){
	int ingaunhien=rand()%20;
	if(bodemso%(sobichia+3)==0){
	    if(ingaunhien%17==0){
		   for(int i=0;i<30;i++){
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
		for(int i=0;i<30;i++){
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
