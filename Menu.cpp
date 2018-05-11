#include"Menu.h"

void loadgame(){
	SetColor(11);
cout<< "          #### "<<endl;  
Sleep(200);
cout<< "          #   #"<<endl;  
Sleep(200);
cout<< "          #### "<<endl;  
Sleep(200);
cout<< "          #    "<<endl;
Sleep(200);
cout<< "          #    "<<endl<<endl;  
SetColor(12);  
    Sleep(200);
cout<<"          #    "<<endl;
Sleep(200);
cout<<"          #    "<<endl;
Sleep(200);
cout<<"          #    "<<endl;
Sleep(200);
cout<<"          #    "<<endl;
Sleep(200);
cout<<"          #####"<<endl<<endl;  
SetColor(13);  
    Sleep(200);
cout<<"           ### "<<endl;
Sleep(200);
cout<<"          #   #"<<endl;
Sleep(200);
cout<<"          #####"<<endl;
Sleep(200);
cout<<"          #   #"<<endl;
Sleep(200);
cout<<"          #   #"<<endl<<endl;  
SetColor(14); 
   Sleep(200);
cout<<"          #   #"<<endl;
Sleep(200);
cout<<"          ##  #"<<endl;
Sleep(200);
cout<<"          # # #"<<endl;
Sleep(200);
cout<<"          #  ##"<<endl;
Sleep(200);
cout<<"          #   #"<<endl<<endl;  
SetColor(8);           
   Sleep(300);
cout<<"          #####"<<endl;
Sleep(200);
cout<<"          #    "<<endl;
Sleep(200);
cout<<"          #####"<<endl;
Sleep(200);
cout<<"          #    "<<endl;
Sleep(200);
cout<<"          #####";  
Sleep(500);                        
system("cls");
}

void menu(){
	loadgame();
	int itrangthaimenu=1;
	Nhap1000:;
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
	gotoxy(40,10);
	cout<<"Press S to continue";
	gotoxy(40,11);
	cout<<"Press UP to up";
	gotoxy(40,12);
	cout<<"Press Down to down";
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
	            if (checkKey(KEY_S)){
	            	system("cls");
	            	taoviengame();
	            	SetColor(14);
	            	gotoxy(10,3);
	                cout<<"P L A N E";
	                SetColor(13);
	            	while(1){
	            		SetColor(13);
	            		gotoxy(13,8);
	            		cout<<"UP";
	            		gotoxy(13,9);
	            		cout<<"^";
	            	    gotoxy(1,10);
	            	    cout<<" Press LEFT< O >RIGHT to move";
	            	    gotoxy(13,11);
	            	    cout<<"v";
	            	    gotoxy(12,12);
	            	    cout<<"DOWN";
	            	    
	            	    gotoxy(1,14);
	            	    cout<<" Press  S  to fire !!!";
	            	    SetColor(14);
	            	    gotoxy(40,10);
	            	    cout<<"Press RIGHT to back";
	            	    if (checkKey(KEY_LEFT)){
	            		system("cls");
	            		goto Nhap1000;
	            	}	
	            	}
	            }
		}
		if(itrangthaimenu==3){
		   		taovienchu(10,14);
	            taovienchu(13,14);
	            taovienchu(16,12);
	            if (checkKey(KEY_S)){
	            	system("cls");
	            	taoviengame();
	            	SetColor(14);
	            	gotoxy(10,3);
	                cout<<"P L A N E";
	                while(1){
	                	SetColor(9);
	                	gotoxy(5,7);
	                	cout<<"Danger : ";
	                	gotoxy(8,9);
	                	cout<<"Plane Normal : ";
	                	SetColor(15);
	                	cout<<"~|-|~";
	                	gotoxy(8,11);
	                	SetColor(9);
	                	cout<<"Plane Tank : ";
	                	SetColor(13);
	                	cout<<"~|_-_|~";
	                	SetColor(9);
	                	gotoxy(8,13);
	                	cout<<"Plane Fire : ";
	                	SetColor(11);
	                	cout<<"~|-|~  ";
	                	gotoxy(8,15);
	                	SetColor(9);
	                	cout<<"Bullet : ";
	                	SetColor(14);
	                	cout<<".";
	                	gotoxy(40,10);
	            	    cout<<"Press RIGHT to back";
	                	if (checkKey(KEY_LEFT)){
	            		system("cls");
	            		goto Nhap1000;
	            	    }
	                }
	            }
		}
		Sleep(100);
	}
	Nhap1:;
	system("cls");
}
