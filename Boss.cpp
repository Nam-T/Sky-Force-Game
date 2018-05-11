#include"Boss.h"
#include"XuLyCacVaCham.h"
#include"Menu.h"
#include"Umtil.h"

void vachamboss(MayBay&boss,MayBay&maybay,Dan&dan,int &maybaylife,int &mangbaove,int&itrangthaidan,int&bmauboss,int&gameover){
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
	for(int i=0;i<30;i++){
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

void bossdichuyen(MayBay&boss,MayBay&maybay,Dan&dan,int&maybaylife,int&mangbaove,int&itrangthaidan,int&bmauboss,int&ihuongdichuyenboss,int&gameover){
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
			vachamboss(boss,maybay,dan,maybaylife,mangbaove,itrangthaidan,bmauboss,gameover);
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

void xulyboss(MayBay&maybay,MayBay&boss,Items&items,Dan&dan,Dan&dandich,int &maybaylife,int &itrangthaidan,int&mangbaove,int&bmauboss,int&ihuongdichuyenboss,int&gameover){
	bossdichuyen(boss,maybay,dandich,maybaylife,mangbaove,itrangthaidan,bmauboss,ihuongdichuyenboss,gameover);
	vachamboss(boss,maybay,dan,maybaylife,mangbaove,itrangthaidan,bmauboss,gameover);
	anitems(maybay,items,maybaylife,itrangthaidan,mangbaove);
	if(boss.td.x>=0&&boss.td.x<=ConW&&boss.td.y>=0&&boss.td.y<=ConW){
	}else{
		boss.td.x=6;
		boss.td.y=2;
	}
	vachamboss(boss,maybay,dan,maybaylife,mangbaove,itrangthaidan,bmauboss,gameover);
	
}
