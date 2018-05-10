#include"KhoiTaoHinhDangVaToaDo.h"


void KhoiTaoHinhDangVaToaDo(MayBay& maybay,MayBayDich & maybaydich,Dan&dan,Items&items,MayBayTank&maybaytank,MayBayTank&maybayban,Dan&dandich,MayBay&boss){
	maybay.td.y=ConW;
	maybay.td.x=ConW/2;
	strcpy(maybay.hd.a,"~|O|~");
	for(int i=0;i<30;i++){
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
