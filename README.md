#include<iostream>
#include<stdlib.h>
#include<Windows.h>
#include<string.h>
#include "Util.h"
#include<ctime>

#define ConW 25
#define ConH 25

enum TrangThai {UP,DOWN,LEFT,RIGHT
};

int i,j;

using namespace std;

struct Pos2D{
	char s[10];
	int y,x;
};

int main(){
	int b[2000],c[2000];
	i=0;
	int k=0;
	Pos2D Plane;
	strcpy(Plane.s,"|-|");
	Plane.y=ConH;
	Plane.x=ConW/2;
	Pos2D Bullet[2000];
	Pos2D Boss[2000];
	
	srand(time(NULL));
    
    for(j=0;j<2000;j++){
		b[j]=0;
		c[j]=0;
		Boss[j].x=rand() % ConW ;
	    Boss[j].y=0;
	}
    
	for(j=0;j<2000;j++){
		strcpy(Bullet[j].s,"^");
		strcpy(Boss[j].s,"~o~");
	}
	
	while(1){
		system("cls");
		
		if (checkKey(KEY_LEFT)){
			Plane.x--;
			if(Plane.x<=0)Plane.x++;
		}
    	else if (checkKey(KEY_RIGHT)){
			Plane.x++;
			if(Plane.x>=ConW)Plane.x--;
		}
    	else if (checkKey(KEY_UP)){
			Plane.y--;
			if(Plane.y<0)Plane.y++;
		}
    	else if (checkKey(KEY_DOWN)){
			Plane.y++;
			if(Plane.y>=ConH)Plane.y--;
		}
		
    	if(checkKey(KEY_S)){
			Bullet[i].x=Plane.x+1;
			Bullet[i].y=Plane.y-1;
			gotoxy(Bullet[i].x,Bullet[i].y);
			b[i]=1;
			i++;
			if(i==1999){
				i=0;
				for(j=0;j<2000;j++){
					b[j]=0;
				}
			}
		}
		
		gotoxy(Plane.x,Plane.y);
		cout<<Plane.s;
		
        gotoxy(Boss[k].x,Boss[k].y);
			c[i]=1;
			k++;
			if(k==1999){
				k=0;
				for(j=0;j<2000;j++){
					c[j]=0;
				}
			}
		
		for(j=0;j<2000;j++){
			if(Boss[j].y==ConH){
			}else{
				if(c[j]==1){
					Boss[j].y++;
					gotoxy(Boss[j].x,Boss[j].y);
					cout<<Boss[j].s;
				}
			}
		}
		
		for(j=0;j<2000;j++){
			if(Bullet[j].y==0){
			}else{
				if(b[j]==1){
					Bullet[j].y--;
				    gotoxy(Bullet[j].x,Bullet[j].y);
				    cout<<Bullet[j].s;
				}
			}
		}	
	}
	Sleep(1);

}
