#include"TaoVienChu.h"

void taoviengame(){
	// tao vien` doc
	SetColor(10);
	for(int i=0;i<=ConW;i++){
		printf("%c\n",179);
	}
	for(int i=0;i<=ConH;i++){
		gotoxy(ConH+5,i);
		putchar(179);
	}
	// tao vien goc chu a
	gotoxy(0,ConW+1);
	putchar(192);
	gotoxy(ConH+5,ConW+1);
	putchar(217);
	// tao vien ngang
	for(int i=1;i<ConH+5;i++){
		gotoxy(i,ConH+1);
		putchar(196);
	}
	SetColor(15);
}

void taovienchu(int y, int ma_mau){
	SetColor(ma_mau);
	gotoxy(8,y);
	putchar(179);
	gotoxy(21,y);
	putchar(179);
	for(int i=1;i<=12;i++){
		gotoxy(8+i,y-1);
		putchar(196);
		gotoxy(8+i,y+1);
		putchar(196);
		gotoxy(8,y-1);
		putchar(218);
		gotoxy(21,y-1);
		putchar(191);
		gotoxy(8,y+1);
		putchar(192);
		gotoxy(21,y+1);
		putchar(217);
	}
}
