#include"XuLyCacVaCham.h"
#include"Menu.h"
#include"Umtil.h"

void anitems(MayBay& maybay,Items & items,int &maybaylife,int &itrangthaidan,int&mangbaove){
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
   		goto Nhap4;
   	}
   	Nhap4:;
   	items.b.td.x=50;
   	items.b.td.y=5;
   }
}


void vacham(MayBay& maybay,MayBayDich& maybaydich,Dan & dan,Items&items,MayBayTank&maybaytank,MayBayTank&maybayban,Dan&dandich,int &diem,int bmautank[30],int &itrangthaidan,int &maybaylife,int &mangbaove,int &gameover){
	//va cham items vs maybay
   anitems(maybay,items,maybaylife,itrangthaidan,mangbaove);
	//va cham dan voi cac loai may bay dich
	int l;
	for(int i=0;i<30;i++){
		for(int l=0;l<30;l++){
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
	 anitems(maybay,items,maybaylife,itrangthaidan,mangbaove);
	//va cham may bay
	for(int i=0;i<30;i++){
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
