#ifndef Opject_H_
#define Opject_H_

#define ConW 25
#define ConH 25

struct ToaDo{
	int y,x;
};

struct HinhDang{
	char a[10];
	char b[10];
	char c[10];
};

struct MayBay{
	ToaDo td;
	HinhDang hd;
};

struct MayBayDich{
	MayBay mb[30];	
};

struct MayBayTank{
	MayBay mb[30];
};

struct Dan{
	MayBay mb[30];
};

struct Items{
	MayBay h;//heart
	MayBay s;//shield
	MayBay b;//bullet
};


#endif
