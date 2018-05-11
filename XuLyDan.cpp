#include"XuLyDan.h"
#include"Menu.h"
#include"Umtil.h"

void xulydan(Dan&dan,Dan&dandich,MayBayTank&maybayban,int & itrangthaidan ,int &idemsoluongdan,int&isoluongdan,int & bodemso){
	//xu ly dan
	for(int i=0;i<30;i++){
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
	idemsoluongdan++;
	if(itrangthaidan==1){
		if(idemsoluongdan%4==0){
			if(isoluongdan<1){
				isoluongdan++;
			}
		}	
	}else{
		if(itrangthaidan==2){
			if(idemsoluongdan%6==0){
			    if(isoluongdan<1){
				   isoluongdan++;
			    }
		    }
		}else{
		    if(idemsoluongdan%9==0){
			   if(isoluongdan<1){
				  isoluongdan++;
			   }
		    }
		}
	}
	
	if(idemsoluongdan==100000){
		idemsoluongdan=0;
	}
	if(idemsoluongdan==100000){
		idemsoluongdan=0;
	}
	//xu ly dan dich
	if(bodemso%5==0){
	for(int i=0;i<30;i++){
		
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
}
