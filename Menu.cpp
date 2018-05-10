#include"Menu.h"
void menu(){
	int itrangthaimenu=1;
	taoviengame();
	
	// tao chu trong game
	gotoxy(11,3);
	cout<<"P L A N E";
	gotoxy(13,5);
	cout<<"~|O|~";
	SetColor(13);
	gotoxy(10,10);
	cout<<"START GAME";
	gotoxy(13,13);
	cout<<"KEY ";
	gotoxy(13,16);
	cout<<"HELP";
	while(1){
		if (checkKey(KEY_UP)){
			if(itrangthaimenu>1){
				itrangthaimenu--;
			}else{
				itrangthaimenu=3;
			}
			goto Nhap;
		}
		if (checkKey(KEY_DOWN)){
			if(itrangthaimenu<3){
				itrangthaimenu++;
			}else{
				itrangthaimenu=1;
			}
			goto Nhap;
		}
		Nhap:;
		if(itrangthaimenu==1){
		   		taovienchu(10,12);
	            taovienchu(13,14);
	            taovienchu(16,14);
	            if (checkKey(KEY_S)){
	            	goto Nhap1;
	            }
		}
		if(itrangthaimenu==2){
		   		taovienchu(10,14);
	            taovienchu(13,12);
	            taovienchu(16,14);
		}
		if(itrangthaimenu==3){
		   		taovienchu(10,14);
	            taovienchu(13,14);
	            taovienchu(16,12);
		}
		Sleep(100);
	}
	Nhap1:;
	system("cls");
}
