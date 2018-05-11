#include"Shoot.h"
#include"Menu.h"
#include"Umtil.h"

void shoot(MayBay& maybay,Dan& dan,int&itrangthaidan,int&isoluongdan){
	if (checkKey(KEY_S)){
			if(isoluongdan>0){
				for(int i=0;i<30;i++){
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

