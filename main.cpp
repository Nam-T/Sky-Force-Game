
#include<stdlib.h>
#include"Menu.h"
#include<ctime>
#include"KhoiTaoHinhDangVaToaDo.h"

int i,j=0,isoluongdan,idemsoluongdan=0,gameover,maybaylife,mangbaove=0, diem,bodemso=0,sobichia,isoluongquaivat,iitems,itrangthaidan,bmautank[30],bmauboss,checkboss;
int ihuongdichuyenboss;


void KhoiTao(MayBay& maybay,MayBayDich & maybaydich,Dan&dan,Items&items,MayBayTank&maybaytank,MayBayTank&maybayban,Dan&dandich,MayBay&boss){
	diem=0;
	maybaylife=3;
	gameover=0;
	sobichia=4;
	isoluongquaivat=0;
	isoluongdan=1;
	itrangthaidan=1;
	bmauboss=100;
	checkboss=0;
	ihuongdichuyenboss=1;
	for(int i=0;i<30;i++){
		bmautank[i]=6;
	}
	KhoiTaoHinhDangVaToaDo(maybay,maybaydich,dan,items,maybaytank,maybayban,dandich,boss);
	taoviengame();
}

void HienThi(MayBay&maybay,MayBayDich & maybaydich,Dan& dan,Items & items,MayBayTank&maybaytank,MayBayTank&maybayban,Dan&dandich,MayBay&boss){
	
	if(mangbaove==300){
		for(i=0;i<5;i++){
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
	gotoxy(40,14);
	cout<<bmauboss;
	gotoxy(40,15);
	cout<<"HP : ";
	for(i=0;i<maybaylife;i++){
		SetColor(12);
		printf("%c",177);
		printf("%c",177);
		cout<<" ";
		SetColor(15);
	}
	cout<<"         ";	
	
}

void DieuKhien(MayBay&maybay){
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
	        	for(i=0;i<5;i++){
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
	        	for(i=0;i<5;i++){
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
	        	for(i=0;i<5;i++){
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
	        	for(i=0;i<5;i++){
			      gotoxy(maybay.td.x+i,maybay.td.y-1);
			      SetColor(14);
			      cout<<"_";
			      SetColor(15);
		        }
	        }
		}
}

void anitems(MayBay& maybay,Items & items){
	int sx=maybay.td.x-items.s.td.x;
   int sy=maybay.td.y-items.s.td.y;
   if(sy==0&&sx<=0&&sx>=-4){
   	mangbaove=300;
   	items.s.td.x=50;
   	items.s.td.y=5;
   }
   int hx=maybay.td.x-items.h.td.x;
   int hy=maybay.td.y-items.h.td.y;
   if(hy==0&&hx<=0&&hx>=-4){
   	if(maybaylife<5){
   		maybaylife++;
   	}
   	items.h.td.x=50;
   	items.h.td.y=5;
   }
   int bx=maybay.td.x-items.b.td.x;
   int by=maybay.td.y-items.b.td.y;
   if(by==0&&bx<=0&&bx>=-4){
   	if(itrangthaidan<3){
   		itrangthaidan++;
   		isoluongdan=1;
   		goto Nhap4;
   	}
   	Nhap4:;
   	items.b.td.x=50;
   	items.b.td.y=5;
   }
}

void vacham(MayBay& maybay,MayBayDich& maybaydich,Dan & dan,Items&items,MayBayTank&maybaytank,MayBayTank&maybayban,Dan&dandich){
	//va cham items vs maybay
   anitems(maybay,items);
	//va cham dan
	int l;
	for(i=0;i<30;i++){
		for(l=0;l<30;l++){
			int ddanx=maybaydich.mb[i].td.x-dan.mb[l].td.x;
		    int ddany=abs(maybaydich.mb[i].td.y-dan.mb[l].td.y);
		    int ddantankx=maybaytank.mb[i].td.x-dan.mb[l].td.x;
		    int ddantanky=maybaytank.mb[i].td.y-dan.mb[l].td.y;
		    int ddanbanx=maybayban.mb[i].td.x-dan.mb[l].td.x;
		    int ddanbany=maybayban.mb[i].td.y-dan.mb[l].td.y;
		    if(itrangthaidan==1){
		       if(ddany==0&&ddanx<=0&&ddanx>=-4){
		    	    if(dan.mb[l].td.x>=0&&dan.mb[l].td.x<=ConW+1&&dan.mb[l].td.y>=0&&dan.mb[l].td.y<=ConW&&maybaydich.mb[i].td.x>=0&&maybaydich.mb[i].td.x<=ConW&&maybaydich.mb[i].td.y>=0&&maybaydich.mb[i].td.y<=ConW){
		    			diem++;
		    		}
		    		gotoxy(maybaydich.mb[i].td.x,maybaydich.mb[i].td.y);
		    		cout<<"     ";
		    		gotoxy(dan.mb[l].td.x,dan.mb[l].td.y);
		    		cout<<" ";
		    		maybaydich.mb[i].td.x=50;
		    		maybaydich.mb[i].td.y=2;
		    		dan.mb[l].td.x=40;
		    		dan.mb[l].td.y=2;
		       }
		       if(ddantanky==0&&ddantankx<=0&&ddantankx>=-6){
		       	  if(dan.mb[l].td.x>=0&&dan.mb[l].td.x<=ConW+1&&dan.mb[l].td.y>=0&&dan.mb[l].td.y<=ConW&&maybaytank.mb[i].td.x>=0&&maybaytank.mb[i].td.x<ConW-2&&maybaytank.mb[i].td.y>=0&&maybaytank.mb[i].td.y<ConW){
		       	  	 bmautank[i]--;
		       	  	 if(bmautank[i]==0){
		       	  	 	  gotoxy(maybaytank.mb[i].td.x,maybaytank.mb[i].td.y);
		       	  	 	  cout<<"       ";
		       	  	 	  diem++;
		       	  	 	  bmautank[i]=6;
		       	  	 	  maybaytank.mb[i].td.x=60;
		       	  	 	  maybaytank.mb[i].td.y=4;
		       	  	      }
					      gotoxy(dan.mb[l].td.x,dan.mb[l].td.y);
		    		      cout<<" ";  
		       	  	      dan.mb[l].td.x=40;
		       	  	 	  dan.mb[l].td.y=2;
					 goto Nhap11; 
		       	     }
		       }
		       if(ddanbany==0&&ddanbanx<=0&&ddanbanx>=-4){
		       	if(dan.mb[l].td.x>=0&&dan.mb[l].td.x<=ConW+1&&dan.mb[l].td.y>=0&&dan.mb[l].td.y<=ConW&&maybayban.mb[i].td.x>=0&&maybayban.mb[i].td.x<=ConW&&maybayban.mb[i].td.y>=0&&maybayban.mb[i].td.y<=ConW){
		       		diem++;
		       		gotoxy(dan.mb[i].td.x,dan.mb[i].td.y);
		    		cout<<" ";
		    		gotoxy(maybayban.mb[i].td.x,maybayban.mb[i].td.y);
		    		cout<<"     ";
		       		maybayban.mb[i].td.x=50;
		       	     maybayban.mb[i].td.y=6;
		       	     dan.mb[i].td.x=40;
		       	     dan.mb[i].td.y=2;
		       	   }
		       }
			   
		    }
		    if(itrangthaidan==2){
		    	if(ddany==0&&ddanx<=2&&ddanx>=-4){
		    	    if(dan.mb[l].td.x>=0&&dan.mb[l].td.x<=ConW+1&&dan.mb[l].td.y>=0&&dan.mb[l].td.y<=ConW&&maybaydich.mb[i].td.x>=0&&maybaydich.mb[i].td.x<=ConW&&maybaydich.mb[i].td.y>=0&&maybaydich.mb[i].td.y<=ConW){
		    			diem++;
		    		}
		    		gotoxy(maybaydich.mb[i].td.x,maybaydich.mb[i].td.y);
		    		cout<<"     ";
		    		gotoxy(dan.mb[l].td.x,dan.mb[l].td.y);
		    		cout<<"   ";
      	    		maybaydich.mb[i].td.x=50;
		    		maybaydich.mb[i].td.y=2;
		    		dan.mb[l].td.x=40;
		    		dan.mb[l].td.y=2;
		       }
		       if(ddantanky==0&&ddantankx<=2&&ddantankx>=-6){
		       	  if(dan.mb[l].td.x>=0&&dan.mb[l].td.x<=ConW+1&&dan.mb[l].td.y>=0&&dan.mb[l].td.y<=ConW&&maybaytank.mb[i].td.x>=0&&maybaytank.mb[i].td.x<ConW&&maybaytank.mb[i].td.y>=0&&maybaytank.mb[i].td.y<ConW){
		       	  	 bmautank[i]=bmautank[i]-3;
		       	  	 if(bmautank[i]==0){
		       	  	 	  gotoxy(maybaytank.mb[i].td.x,maybaytank.mb[i].td.y);
		       	  	 	  cout<<"       ";
		       	  	 	  diem++;
		       	  	 	  bmautank[i]=6;
		       	  	 	  maybaytank.mb[i].td.x=60;
		       	  	 	  maybaytank.mb[i].td.y=4;
		       	  	      }  
		       	  	      gotoxy(dan.mb[l].td.x,dan.mb[l].td.y);
		    		      cout<<"   ";  
		       	  	      dan.mb[l].td.x=40;
		       	  	 	  dan.mb[l].td.y=2;
					 goto Nhap11; 
		       	     }
		       }
		       if(ddanbany==0&&ddanbanx<=0&&ddanbanx>=-4){
		       	if(dan.mb[l].td.x>=0&&dan.mb[l].td.x<=ConW+1&&dan.mb[l].td.y>=0&&dan.mb[l].td.y<=ConW&&maybayban.mb[i].td.x>=0&&maybayban.mb[i].td.x<=ConW&&maybayban.mb[i].td.y>=0&&maybayban.mb[i].td.y<=ConW){
		       		    diem++;
		       		    gotoxy(dan.mb[i].td.x,dan.mb[i].td.y);
		    		    cout<<"   ";
		    		    gotoxy(maybayban.mb[i].td.x,maybayban.mb[i].td.y);
		    		    cout<<"     ";
		       			maybayban.mb[i].td.x=50;
		       			maybayban.mb[i].td.y=6;
		       			dan.mb[i].td.x=40;
		       	        dan.mb[i].td.y=2;
		       	}
		       }
		    }	
		    if(itrangthaidan==3){
		    	if(ddany==0&&ddanx<=4&&ddanx>=-4){
		    	    if(dan.mb[l].td.x>=0&&dan.mb[l].td.x<=ConW+1&&dan.mb[l].td.y>=0&&dan.mb[l].td.y<=ConW&&maybaydich.mb[i].td.x>=0&&maybaydich.mb[i].td.x<=ConW&&maybaydich.mb[i].td.y>=0&&maybaydich.mb[i].td.y<=ConW){
		    			diem++;
		    		}
		    		gotoxy(maybaydich.mb[i].td.x,maybaydich.mb[i].td.y);
		    		cout<<"     ";
		    		gotoxy(dan.mb[l].td.x,dan.mb[l].td.y);
		    		cout<<"     ";
		    		maybaydich.mb[i].td.x=50;
		    		maybaydich.mb[i].td.y=2;
		    		dan.mb[l].td.x=40;
		    		dan.mb[l].td.y=2;
		       }
		       if(ddantanky==0&&ddantankx<=4&&ddantankx>=-6){
		       	  if(dan.mb[l].td.x>=0&&dan.mb[l].td.x<=ConW+1&&dan.mb[l].td.y>=0&&dan.mb[l].td.y<=ConW&&maybaytank.mb[i].td.x>=0&&maybaytank.mb[i].td.x<ConW&&maybaytank.mb[i].td.y>=0&&maybaytank.mb[i].td.y<ConW){
		       	  	 bmautank[i]=0;
		       	  	 if(bmautank[i]==0){
		       	  	 	  gotoxy(maybaytank.mb[i].td.x,maybaytank.mb[i].td.y);
		       	  	 	  cout<<"       ";
		       	  	 	  diem++;
		       	  	 	  bmautank[i]=6;
		       	  	 	  maybaytank.mb[i].td.x=60;
		       	  	 	  maybaytank.mb[i].td.y=4;
		       	  	      } 
						  gotoxy(dan.mb[l].td.x,dan.mb[l].td.y);
		    		      cout<<"     ";  	    
		       	  	      dan.mb[l].td.x=40;
		       	  	 	  dan.mb[l].td.y=3;
					 goto Nhap11; 
		       	     }
		       }
		       if(ddanbany==0&&ddanbanx<=4&&ddanbanx>=-4){
		       	if(dan.mb[l].td.x>=0&&dan.mb[l].td.x<=ConW+1&&dan.mb[l].td.y>=0&&dan.mb[l].td.y<=ConW&&maybayban.mb[i].td.x>=0&&maybayban.mb[i].td.x<=ConW&&maybayban.mb[i].td.y>=0&&maybayban.mb[i].td.y<=ConW){
		       		diem++;
		       		gotoxy(dan.mb[i].td.x,dan.mb[i].td.y);
		    		cout<<"     ";
		    		gotoxy(maybayban.mb[i].td.x,maybayban.mb[i].td.y);
		    		cout<<"     ";
		       		maybayban.mb[i].td.x=50;
		       		maybayban.mb[i].td.y=6;
		       		dan.mb[i].td.x=40;
		       	    dan.mb[i].td.y=3;
		       	}
		       }
		    }	
		}
	}
	 anitems(maybay,items);
	//va cham may bay
	for(i=0;i<30;i++){
		   int dx=abs(maybay.td.x-maybaydich.mb[i].td.x);
		   int dy=abs(maybay.td.y-maybaydich.mb[i].td.y);
	       int dtankx=-maybay.td.x+maybaytank.mb[i].td.x;
	       int dtanky=abs(maybay.td.y-maybaytank.mb[i].td.y);
	       int ddandichx=maybay.td.x-dandich.mb[i].td.x;
	       int ddandichy=maybay.td.y-dandich.mb[i].td.y;
	       int dmaybaybanx=abs(maybay.td.x-maybayban.mb[i].td.x);
	       int dmaybaybany=maybay.td.y-maybayban.mb[i].td.y;
	      if(mangbaove==0){
	      	    if(dx<=4&&dy==0){
	       	      maybaylife--;
	       	         if(itrangthaidan>1){
	       	      	    itrangthaidan--;
	       	            }
	       	         if(itrangthaidan==2){
	       	      	    isoluongdan=1;
	       	            }
	       	            mangbaove=300;
		             if(maybaylife==0){
		    	       gameover=1;
			         }
				    
	              }
	            if(ddandichx<=0&&ddandichx>=-4&&ddandichy==0){
	            	gotoxy(dandich.mb[i].td.x,dandich.mb[i].td.y);
	            	cout<<" ";
	            	maybaylife--;
	            	if(itrangthaidan>1){
	       	      	    itrangthaidan--;
	       	            }
	       	         if(itrangthaidan==2){
	       	      	    isoluongdan=1;
	       	            }
	       	            mangbaove=300;
		             if(maybaylife==0){
		    	       gameover=1;
			         }
			         dandich.mb[i].td.x=50;
		             dandich.mb[i].td.y=8;
	            }
				if(dmaybaybanx<=4&&dmaybaybany==0){
					maybaylife--;
	            	if(itrangthaidan>1){
	       	      	    itrangthaidan--;
	       	            }
	       	         if(itrangthaidan==2){
	       	      	    isoluongdan=1;
	       	            }
	       	            mangbaove=300;
		             if(maybaylife==0){
		    	       gameover=1;
			         }
				}  
	            if(dtankx>=-6&&dtankx<=4&&dtanky==0){
	       	      maybaylife--;
	       	         if(itrangthaidan>1){
	       	      	    itrangthaidan--;
	       	            }
	       	         if(itrangthaidan==2){
	       	      	    isoluongdan=1;
	       	            }
	       	            mangbaove=300;
		             if(maybaylife==0){
		    	       gameover=1;
			         }
				    
	              }
	      }
   }
   Nhap11:;
   if(mangbaove>0){
   	mangbaove--;
   	if(mangbaove==0){
   		gotoxy(maybay.td.x,maybay.td.y-1);
   		cout<<"     ";
   	}
   }
   
}

void shoot(MayBay& maybay,Dan& dan){
	if (checkKey(KEY_S)){
			if(isoluongdan>0){
				for(i=0;i<30;i++){
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

void xuly(MayBay maybay,MayBayDich & maybaydich,Dan & dan,Items & items,MayBayTank&maybaytank,MayBayTank&maybayban,Dan&dandich){
	//xu ly may bay dich
	int ingaunhien=rand()%20;
	if(bodemso%sobichia==0){
	    if(ingaunhien%4==0){
	    	for(int e=0;e<30;e++){
						if(maybaytank.mb[e].td.x>=0&&maybaytank.mb[e].td.x<=ConW&&maybaytank.mb[e].td.y<=1){
							goto Nhap39;
					    }
					}
		   for(i=0;i<30;i++){
		      if(maybaydich.mb[i].td.x>=0&&maybaydich.mb[i].td.x<=ConW&&maybaydich.mb[i].td.y>=0&&maybaydich.mb[i].td.y<=ConW){
		      }else{
		      	   if(checkboss!=1){
		   	           maybaydich.mb[i].td.x=rand()%ConW+1;
		               maybaydich.mb[i].td.y=0;
		               gotoxy(maybaydich.mb[i].td.x,maybaydich.mb[i].td.y);
			           cout<<maybaydich.mb[i].hd.a;
		               isoluongquaivat++;
		               goto Nhap;}
		   }
		}
		Nhap39:;
	    }
	
	vacham(maybay,maybaydich,dan,items,maybaytank,maybayban,dandich);
	Nhap:;
	
		for(i=0;i<30;i++){
		   if(maybaydich.mb[i].td.x>=0&&maybaydich.mb[i].td.x<=ConW&&maybaydich.mb[i].td.y>=0&&maybaydich.mb[i].td.y<=ConW){
		   	gotoxy(maybaydich.mb[i].td.x,maybaydich.mb[i].td.y);
		   	cout<<"     ";
			maybaydich.mb[i].td.y++;
			gotoxy(maybaydich.mb[i].td.x,maybaydich.mb[i].td.y);
			cout<<maybaydich.mb[i].hd.a;
		   }else{
		   	     if(maybaydich.mb[i].td.y==ConW+1){
				     gotoxy(maybaydich.mb[i].td.x,maybaydich.mb[i].td.y);
				     for(i=0;i<5;i++){
				 	 	SetColor(10);
				 	 	 putchar(196);
				  	     SetColor(15);
				 	 }
		   	        }
			     maybaydich.mb[i].td.x=50;
	             maybaydich.mb[i].td.y=2;
		   }
	    }
	    vacham(maybay,maybaydich,dan,items,maybaytank,maybayban,dandich);
	}
	//xu ly may bay tank
	if(bodemso%sobichia==0){
		if(ingaunhien%10==0){
			for(i=0;i<30;i++){
				if(maybaytank.mb[i].td.x>=0&&maybaytank.mb[i].td.x<ConW-2&&maybaytank.mb[i].td.y>=0&&maybaytank.mb[i].td.y<=ConW){
				}else{
					int ixuathien=rand()%22+1;
					for(int e=0;e<30;e++){
						if(maybaydich.mb[e].td.x>=0&&maybaydich.mb[e].td.x<=ConW&&maybaydich.mb[e].td.y<=1){
							goto Nhap10;
					    }
					}
					if(checkboss!=1){
					maybaytank.mb[i].td.x=ixuathien;
					maybaytank.mb[i].td.y=0;
					gotoxy(maybaytank.mb[i].td.x,maybaytank.mb[i].td.y);
			        SetColor(13);
			        cout<<maybaytank.mb[i].hd.a;
			        SetColor(15);
					isoluongquaivat++;
					goto Nhap10;}
				}
			}
		}
		Nhap10:;
		vacham(maybay,maybaydich,dan,items,maybaytank,maybayban,dandich);
		for(i=0;i<30;i++){
			if(maybaytank.mb[i].td.x>=0&&maybaytank.mb[i].td.x<ConW-2&&maybaytank.mb[i].td.y>=0&&maybaytank.mb[i].td.y<=ConW){
				gotoxy(maybaytank.mb[i].td.x,maybaytank.mb[i].td.y);
				cout<<"       ";
				maybaytank.mb[i].td.y++;
				gotoxy(maybaytank.mb[i].td.x,maybaytank.mb[i].td.y);
			    SetColor(13);
			    cout<<maybaytank.mb[i].hd.a;
			    SetColor(15);
			}else{
				if(maybaytank.mb[i].td.y==ConW+1){
				  gotoxy(maybaytank.mb[i].td.x,maybaytank.mb[i].td.y);
				  for(i=0;i<7;i++){
				 	 	SetColor(10);
				 	 	 putchar(196);
				  	     SetColor(15);
				 	 }
				}
				maybaytank.mb[i].td.x=60;
				maybaytank.mb[i].td.y=4;
				bmautank[i]=6;
			}
		}
		vacham(maybay,maybaydich,dan,items,maybaytank,maybayban,dandich);
	}
	//xu ly may bay ban
	if(bodemso%(sobichia+3)==0){
	    if(ingaunhien%17==0){
		   for(i=0;i<30;i++){
		      if(maybayban.mb[i].td.x>=0&&maybayban.mb[i].td.x<=ConW&&maybayban.mb[i].td.y>=0&&maybayban.mb[i].td.y<=ConW){
		      }else{
		      	   if(checkboss!=1){
		   	         maybayban.mb[i].td.x=rand()%ConW+1;
		             maybayban.mb[i].td.y=0;
		             gotoxy(maybayban.mb[i].td.x,maybayban.mb[i].td.y);
			         SetColor(11);
			         cout<<maybayban.mb[i].hd.a;
			         SetColor(15);
		             isoluongquaivat++;
		             goto Nhap20;}
		   }
		}
	}
	
	Nhap20:;
		vacham(maybay,maybaydich,dan,items,maybaytank,maybayban,dandich);
		for(i=0;i<30;i++){
		   if(maybayban.mb[i].td.x>=0&&maybayban.mb[i].td.x<=ConW&&maybayban.mb[i].td.y>=0&&maybayban.mb[i].td.y<=ConW){
		   	gotoxy(maybayban.mb[i].td.x,maybayban.mb[i].td.y);
		   	cout<<"     ";
			maybayban.mb[i].td.y++;
			gotoxy(maybayban.mb[i].td.x,maybayban.mb[i].td.y);
			SetColor(11);
			cout<<maybayban.mb[i].hd.a;
			SetColor(15);
			if(maybayban.mb[i].td.y==ConW+1){
				 	 gotoxy(maybayban.mb[i].td.x,maybayban.mb[i].td.y);
				 	 for(i=0;i<5;i++){
				 	 	SetColor(10);
				 	 	 putchar(196);
				  	     SetColor(15);
				 	 }
		   	     }
		   }else{
		   	     maybayban.mb[i].td.x=50;
	             maybayban.mb[i].td.y=6;
		   }
	    }
	    vacham(maybay,maybaydich,dan,items,maybaytank,maybayban,dandich);
	}
	
	
	shoot(maybay,dan);
	bodemso++;
	//toc do  game;
	if(bodemso==10000){
		bodemso=1;
	}
	if(isoluongquaivat>=0&&isoluongquaivat<=160){
		sobichia=4;
	}
	if(isoluongquaivat>160&&isoluongquaivat<=1120){
		sobichia=3;
	}
	if(isoluongquaivat>1120){
		sobichia=2;
	}
	vacham(maybay,maybaydich,dan,items,maybaytank,maybayban,dandich);
	//tao vat pham
	if((isoluongquaivat+1)%30==0){
		iitems=rand()%3+1;
		if(iitems==1){
			items.h.td.x=rand()%ConW+1;
			items.h.td.y=0;
			gotoxy(items.h.td.x,items.h.td.y);
		    SetColor(10);
		    cout<<items.h.hd.c;
		    SetColor(15);
		}
		if(iitems==2){
			items.s.td.x=rand()%ConW+1;
			items.s.td.y=0;
			gotoxy(items.s.td.x,items.s.td.y);
		    SetColor(11);
		    cout<<items.s.hd.c;
		    SetColor(15);
		}
		if(iitems==3){
			items.b.td.x=rand()%ConW+1;
			items.b.td.y=0;
			gotoxy(items.b.td.x,items.b.td.y);
		    SetColor(13);
		    cout<<items.b.hd.c;
		    SetColor(15);
		}
		isoluongquaivat++;
	}
	vacham(maybay,maybaydich,dan,items,maybaytank,maybayban,dandich);
	if(bodemso%4==0){
		if(items.h.td.x>=0&&items.h.td.x<=ConW+1&&items.h.td.y>=0&&items.h.td.y<=ConW){
		   gotoxy(items.h.td.x,items.h.td.y);
		   cout<<" ";
		   items.h.td.y++;
		   gotoxy(items.h.td.x,items.h.td.y);
		   SetColor(10);
		   cout<<items.h.hd.c;
		   SetColor(15);	
		}else{
			if(items.h.td.y==ConW+1){
			  SetColor(10);
			  gotoxy(items.h.td.x,items.h.td.y);
			  putchar(196);
			  SetColor(15);	
			}
			items.h.td.x=50;
	        items.h.td.y=5;
		}
		if(items.s.td.x>=0&&items.s.td.x<=ConW+1&&items.s.td.y>=0&&items.s.td.y<=ConW){
			gotoxy(items.s.td.x,items.s.td.y);
			cout<<" ";
			items.s.td.y++;
			gotoxy(items.s.td.x,items.s.td.y);
		    SetColor(11);
		    cout<<items.s.hd.c;
		    SetColor(15);
		}else{
			if(items.s.td.y==ConW+1){
			  SetColor(10);
			  gotoxy(items.s.td.x,items.s.td.y);
			  putchar(196);
			  SetColor(15);	
			}
			items.s.td.x=50;
	        items.s.td.y=5;
		}
		if(items.b.td.x>=0&&items.b.td.x<=ConW+1&&items.b.td.y>=0&&items.b.td.y<=ConW){
			gotoxy(items.b.td.x,items.b.td.y);
			cout<<" ";
			items.b.td.y++;
			gotoxy(items.b.td.x,items.b.td.y);
		    SetColor(13);
		    cout<<items.b.hd.c;
		    SetColor(15);
		}else{
			if(items.b.td.y==ConW+1){
			  SetColor(10);
			  gotoxy(items.b.td.x,items.b.td.y);
			  putchar(196);
			  SetColor(15);	
			}
			items.b.td.x=50;
	        items.b.td.y=5;
		}
	}
	
	vacham(maybay,maybaydich,dan,items,maybaytank,maybayban,dandich);
	
	// dan di chuyen
	
	for(i=0;i<30;i++){
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
	vacham(maybay,maybaydich,dan,items,maybaytank,maybayban,dandich);
	idemsoluongdan++;
	if(itrangthaidan==1){
		if(idemsoluongdan%3==0){
			if(isoluongdan<1){
				isoluongdan++;
			}
		}	
	}else{
		if(itrangthaidan==2){
			if(idemsoluongdan%5==0){
			    if(isoluongdan<1){
				   isoluongdan++;
			    }
		    }
		}else{
		    if(idemsoluongdan%7==0){
			   if(isoluongdan<1){
				  isoluongdan++;
			   }
		    }
		}
	}
	
	if(idemsoluongdan==100000){
		idemsoluongdan=0;
	}
	//dan dich ban
	if(bodemso%5==0){
	for(i=0;i<30;i++){
		
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
				
			    if(maybayban.mb[i].td.x>=0&&maybayban.mb[i].td.x<=ConW&&maybayban.mb[i].td.y>=0&&maybayban.mb[i].td.y<=ConW){		
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
	Nhap6:;
	vacham(maybay,maybaydich,dan,items,maybaytank,maybayban,dandich);
	if(isoluongquaivat%50==0&&isoluongquaivat!=0){
		checkboss=1;
	}
}

void vachamboss(MayBay&boss,MayBay&maybay,Dan&dan){
	int dbossx=boss.td.x-maybay.td.x;
	int dbossy=boss.td.y-maybay.td.y;
	if(boss.td.x>=0&&boss.td.x<=ConW&&boss.td.y>=0&&boss.td.y<=ConW){
		if(mangbaove==0){
			if(dbossy>=0&&dbossy<=2&&dbossx>=-9&&dbossx<=4){
			maybaylife--;
			mangbaove=100;
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
	}
	// va cham dan vs boss
	for(i=0;i<30;i++){
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

void bossdichuyen(MayBay&boss,MayBay&maybay,Dan&dan){
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
			vachamboss(boss,maybay,dan);
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

void xulyboss(MayBay&maybay,MayBay&boss,Items&items,Dan&dan,Dan&dandich){
	bossdichuyen(boss,maybay,dandich);
	vachamboss(boss,maybay,dan);
	anitems(maybay,items);
	if(boss.td.x>=0&&boss.td.x<=ConW&&boss.td.y>=0&&boss.td.y<=ConW){
	}else{
		boss.td.x=6;
		boss.td.y=2;
	}
	vachamboss(boss,maybay,dan);
	
}

int main(){
	ShowCur(0);
	menu();
	//setFullScreen();
	srand(time(NULL));
	MayBay maybay;
	MayBayDich maybaydich;
	MayBayTank maybaytank;
	MayBayTank maybayban;
	MayBay boss;
	Dan dan;
	Dan dandich;
	Items items;
	KhoiTao(maybay,maybaydich,dan,items,maybaytank,maybayban,dandich,boss);
	//ban may bay thuong
	while(1){
		Nhap40:;
		HienThi(maybay,maybaydich,dan,items,maybaytank,maybayban,dandich,boss);
		DieuKhien(maybay);
		xuly(maybay, maybaydich,dan,items,maybaytank,maybayban,dandich);
		if(checkboss==1){
			goto Nhap30;
		}
		if(gameover==1){
			goto lost;
		}
		Sleep(40);
		
	}
	//ban boss
	while(1){
		Nhap30:;
		xuly(maybay, maybaydich,dan,items,maybaytank,maybayban,dandich);
		DieuKhien(maybay);
		xulyboss(maybay,boss,items,dan,dandich);
		HienThi(maybay,maybaydich,dan,items,maybaytank,maybayban,dandich,boss);
		if(bmauboss<=0){
			gotoxy(boss.td.x,boss.td.y);
		   	cout<<"          ";
		   	gotoxy(boss.td.x,boss.td.y-1);
		   	cout<<"          ";
		   	gotoxy(boss.td.x,boss.td.y-2);
		   	cout<<"          ";

			checkboss=0;
			bmauboss=1000;
			boss.td.x=30;
			boss.td.y=3;
			isoluongquaivat++;
			goto Nhap40;
		}
		if(gameover==1){
			goto lost;
		}
		Sleep(40);
	}
	//thua cuoc
	lost:;
	gotoxy(10,13);
	SetColor(11);
	cout<<"you lost ";
	SetColor(15);
	while(1){
		
	}
	return 0;
}
