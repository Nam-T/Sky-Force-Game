#include"HienThi.h"
#include"Menu.h"
void HienThi(MayBay&maybay,int mangbaove,int diem,int bmauboss,int maybaylife){
	
	if(mangbaove==300){
		for(int i=0;i<5;i++){
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
	gotoxy(40,16);
	cout<<"Score : "<<diem*100;
	gotoxy(40,13);
	cout<<"HP BOSS ";
	SetColor(12);
	cout<<bmauboss;
	SetColor(15);
	gotoxy(40,15);
	cout<<"HP : ";
	for(int i=0;i<maybaylife;i++){
		SetColor(12);
		printf("%c",177);
		printf("%c",177);
		cout<<" ";
		SetColor(15);
	}
	cout<<"         ";	
	
}
