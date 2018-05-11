#include"DieuKhienMayBay.h"
#include"Umtil.h"
#include"Menu.h"

void DieuKhien(MayBay&maybay,int mangbaove){
        if (checkKey(KEY_LEFT)){
	    	gotoxy(maybay.td.x+4,maybay.td.y);
	    	cout<<" ";
	    	if(mangbaove>0){
	    		gotoxy(maybay.td.x,maybay.td.y-1);
	    		cout<<"     ";
	    	}
			maybay.td.x--;
			if(maybay.td.x<=0)maybay.td.x++;
			
			gotoxy(maybay.td.x,maybay.td.y);
	        SetColor(14);
	        cout<<maybay.hd.a;
	        SetColor(15);
	        
	        if(mangbaove>0){
	        	for(int i=0;i<5;i++){
			      gotoxy(maybay.td.x+i,maybay.td.y-1);
			      SetColor(14);
			      cout<<"_";
			      SetColor(15);
		        }
	        }
		}
    	else if (checkKey(KEY_RIGHT)){
    		gotoxy(maybay.td.x,maybay.td.y);
	    	cout<<" ";
	    	if(mangbaove>0){
	    		gotoxy(maybay.td.x,maybay.td.y-1);
	    		cout<<"     ";
	    	}
			maybay.td.x++;
			if(maybay.td.x>=ConW)maybay.td.x--;
			
			gotoxy(maybay.td.x,maybay.td.y);
	        SetColor(14);
	        cout<<maybay.hd.a;
	        SetColor(15);
	        if(mangbaove>0){
	        	for(int i=0;i<5;i++){
			      gotoxy(maybay.td.x+i,maybay.td.y-1);
			      SetColor(14);
			      cout<<"_";
			      SetColor(15);
		        }
	        }
		}
    	else if (checkKey(KEY_UP)){
    		if(mangbaove>0){
	    		gotoxy(maybay.td.x,maybay.td.y-1);
	    		cout<<"     ";
	    	}
    		gotoxy(maybay.td.x,maybay.td.y);
	    	cout<<"     ";
			maybay.td.y--;
			if(maybay.td.y<0)maybay.td.y++;
			
			gotoxy(maybay.td.x,maybay.td.y);
	        SetColor(14);
	        cout<<maybay.hd.a;
	        SetColor(15);
	        if(mangbaove>0){
	        	for(int i=0;i<5;i++){
			      gotoxy(maybay.td.x+i,maybay.td.y-1);
			      SetColor(14);
			      cout<<"_";
			      SetColor(15);
		        }
	        }
		}
    	else if (checkKey(KEY_DOWN)){
    		if(mangbaove>0){
	    		gotoxy(maybay.td.x,maybay.td.y-1);
	    		cout<<"     ";
	    	}
    		gotoxy(maybay.td.x,maybay.td.y);
	    	cout<<"     ";
			maybay.td.y++;
			if(maybay.td.y>ConH)maybay.td.y--;
			
			gotoxy(maybay.td.x,maybay.td.y);
	        SetColor(14);
	        cout<<maybay.hd.a;
	        SetColor(15);
	        if(mangbaove>0){
	        	for(int i=0;i<5;i++){
			      gotoxy(maybay.td.x+i,maybay.td.y-1);
			      SetColor(14);
			      cout<<"_";
			      SetColor(15);
		        }
	        }
		}
}
