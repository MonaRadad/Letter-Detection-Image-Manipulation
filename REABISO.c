#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <bmpio.h>
#include <math.h>
unsigned char photo[2000][2000][3];
unsigned char photo2[2000][2000][3];
void crop();
void resize_photo();
void magre();
void cropphoto();
void resize_photo2();
void tashkhis();
void tashkhis();
int keyy();
int keyy2(int i,int j , int k);
void show();
int tedadx=4,tedady=4;
int xaddress[10],yaddress[10];
char string[100];
char str[100];
char lock[80][80];
char key[80];
int ramz1[80];
int ramz2[80];

int main()
{
	int i;
	printf("are you ready?");
	crop();
	magre();
	cropphoto();
	resize_photo2();
	tashkhis();
	printf("harf ra vared konid\n");
	scanf("\n");
	gets(key);
	keyy();
	show();
}

void crop()
{	

	int width,heigth,i,j,k,x1=0,x2=0,y1=0,y2=0,m=0,n=0,count=0;
	
	for(k=1 ; k<=172 ; k++)
	{
	sprintf(string,"./project.f/%d.bmp",k);
	readBMP(string,&width,&heigth,photo);
	i=0;
	while(i<heigth)
	{
		j=0;
		while(j<width)
		{
			if(photo[i][j][0]!=255 || photo[i][j][1]!=255 || photo[i][j][2]!=255){//==
					if(count==0){
						count=1;
						x1=i;
						//breakkkkkkkkkkkkkkkkkkkkkkkkkkkkk;
					}
				}
				j++;
		}
		i++;
	}
	j=0;
	count=0;
	while(j<width)
	{
		i=0;
		while(i<heigth)
		{
			if(photo[i][j][0]!=255 || photo[i][j][1]!=255 || photo[i][j][2]!=255)
			{
				if(count==0){
					count=1;
					y1=j;
					//breakkkkkkkkkkkkkkkkkkkkkkkkkkkkk;
				}
			}
			i++;
		}
		j++;
	}
	count=0;
	i=0;
	while(i<heigth)
	{
		j=0;
		while(j<width)
		{
			if(photo[i][j][0]!=255 || photo[i][j][1]!=255 || photo[i][j][2]!=255)
			{
					x2=i;
			}
			j++;
		}
		i++;
	}
	j=0;
	while(j<width)
	{
		i=0;
		while(i<heigth)
		{
			if(photo[i][j][0]!=255 || photo[i][j][1]!=255 || photo[i][j][2]!=255)
			{
					y2=j;
			}
			i++;
		}
		j++;
	}
	for(i=x1; i<=x2 ; i++){
		for(j=y1 ; j<=y2 ; j++){
			photo2[m][n][0]=photo[i][j][0];
			photo2[m][n][1]=photo[i][j][1];
			photo2[m][n][2]=photo[i][j][2];
			n++;	
		}
		m++;
		n=0;
	}
	m=0;
	saveBMP(photo2, y2-y1,x2-x1,string);
	resize_photo();
	}
	
}


void resize_photo()
{
	int width,width2,heigth,heigth2;
	int i,j,X,Y,k,num,s;
	readBMP(string,&width,&heigth,photo);
	width2=460;heigth2=460;
	
	double ww=(double)width2/width;
	double ratiow=ww;
	double hh=(double)heigth2/heigth;
	double ratioH=hh;
	
	j=0,Y=0;
	while(j<width)
	{
		i=0,X=0;
		while(i<heigth)
		{
			
			while(hh>=1){
				photo2[X][Y][0]=photo[i][j][0];
				photo2[X][Y][1]=photo[i][j][1];
				photo2[X][Y][2]=photo[i][j][2];
				hh--;
				X++;
			}	
			if(i!=heigth-1)
			{
				for(k=0 ; k<3 ; k++)
				{
					photo2[X][Y][0]=0;
					photo2[X][Y][1]=0;
					photo2[X][Y][2]=0;
				}
				photo2[X][Y][0]+=photo[i][j][0]*hh;
				photo2[X][Y][1]+=photo[i][j][1]*hh;
				photo2[X][Y][2]+=photo[i][j][2]*hh;
				photo2[X][Y][0]+=photo[i+1][j][0]*(1-hh);
				photo2[X][Y][1]+=photo[i+1][j][1]*(1-hh);
				photo2[X][Y][2]+=photo[i+1][j][2]*(1-hh);
				X++;
			}
			hh=ratioH-(1-hh);
			if(X==heigth2-1)
			{
				photo2[X][Y][0]=photo[i][j][0];
				photo2[X][Y][1]=photo[i][j][1];
				photo2[X][Y][2]=photo[i][j][2];
				X++;
			}
			i++;
			
		}
		Y++,j++;
	}
	
	saveBMP(photo2, Y, X,"X.bmp");
	readBMP("X.bmp",&width,&heigth,photo);
	
	i=0,X=0;
	while(i<heigth)
	{
		j=0,Y=0;
		while(j<width)
		{
			while(ww>=1)
			{
				photo2[X][Y][0]=photo[i][j][0];
				photo2[X][Y][1]=photo[i][j][1];
				photo2[X][Y][2]=photo[i][j][2];
				ww--;
				Y++;
			}
			if(j!=width-1)
			{
				for(k=0 ; k<3 ; k++){
					photo2[X][Y][0]=0;
					photo2[X][Y][1]=0;
					photo2[X][Y][2]=0;
				}
				photo2[X][Y][0]+=photo[i][j][0]*ww;
				photo2[X][Y][1]+=photo[i][j][1]*ww;
				photo2[X][Y][2]+=photo[i][j][2]*ww;
				
				photo2[X][Y][0]+=photo[i][j+1][0]*(1-ww);
				photo2[X][Y][1]+=photo[i][j+1][1]*(1-ww);
				photo2[X][Y][2]+=photo[i][j+1][2]*(1-ww);
				Y++;
			}
			ww=ratiow-(1-ww);
			if(Y==width2-1)
			{//599*
				photo2[X][Y][0]=photo[i][j][0];
				photo2[X][Y][1]=photo[i][j][1];
				photo2[X][Y][2]=photo[i][j][2];
				Y++;
			}
			j++;
		}
		X++,i++;
	}
	saveBMP(photo2,Y,X,string);
}

void resize_photo2()
{
	int width,width2,heigth,heigth2;
	
	int i,j,X,Y,k,s;
	for(s=1 ; s<=tedadx*tedady ; s++){
	X=0,Y=0;
	sprintf(string,"./tashkhis/%d.bmp",s);
	readBMP(string,&width,&heigth,photo);
	width2=460;heigth2=460;
	
	double ww=(double)width2/width;
	double ratiow=ww;
	double hh=(double)heigth2/heigth;
	double ratioH=hh;
	
	j=0,Y=0;
	while(j<width)
	{
		i=0,X=0;
		while(i<heigth)
		{
			
				while(hh>=1){
						photo2[X][Y][0]=photo[i][j][0];
						photo2[X][Y][1]=photo[i][j][1];
					photo2[X][Y][2]=photo[i][j][2];
					hh--;
					X++;
				}	
			if(i!=heigth-1)
			{
				for(k=0 ; k<3 ; k++)
				{
					photo2[X][Y][0]=0;
					photo2[X][Y][1]=0;
					photo2[X][Y][2]=0;
				}
				photo2[X][Y][0]+=photo[i][j][0]*hh;
				photo2[X][Y][1]+=photo[i][j][1]*hh;
				photo2[X][Y][2]+=photo[i][j][2]*hh;
				photo2[X][Y][0]+=photo[i+1][j][0]*(1-hh);
				photo2[X][Y][1]+=photo[i+1][j][1]*(1-hh);
				photo2[X][Y][2]+=photo[i+1][j][2]*(1-hh);
				X++;
			}
			hh=ratioH-(1-hh);
			if(X==heigth2-1)
			{
				photo2[X][Y][0]=photo[i][j][0];
				photo2[X][Y][1]=photo[i][j][1];
				photo2[X][Y][2]=photo[i][j][2];
				X++;
			}
			i++;
			
		}
		Y++,j++;
	}
	
	saveBMP(photo2, Y, X,"X.bmp");
	readBMP("X.bmp",&width,&heigth,photo);
	
	i=0,X=0;
	while(i<heigth)
	{
		
		j=0,Y=0;
		while(j<width)
		{
			
			while(ww>=1)
			{
				
				photo2[X][Y][0]=photo[i][j][0];
				photo2[X][Y][1]=photo[i][j][1];
				photo2[X][Y][2]=photo[i][j][2];
				ww--;
				Y++;
				
			}
			if(j!=width-1)
			{
				for(k=0 ; k<3 ; k++){
					photo2[X][Y][0]=0;
					photo2[X][Y][1]=0;
					photo2[X][Y][2]=0;
				}
				
				photo2[X][Y][0]+=photo[i][j][0]*ww;
				photo2[X][Y][1]+=photo[i][j][1]*ww;
				photo2[X][Y][2]+=photo[i][j][2]*ww;
				
				photo2[X][Y][0]+=photo[i][j+1][0]*(1-ww);
				photo2[X][Y][1]+=photo[i][j+1][1]*(1-ww);
				photo2[X][Y][2]+=photo[i][j+1][2]*(1-ww);
				Y++;
				
			}
			ww=ratiow-(1-ww);
			if(Y==width2-1)
			{//599*
				photo2[X][Y][0]=photo[i][j][0];
				photo2[X][Y][1]=photo[i][j][1];
				photo2[X][Y][2]=photo[i][j][2];
				Y++;
			}
			j++;
		}
		X++,i++;
	}
	saveBMP(photo2,Y,X,string);
}
}

void magre(){
	int i,j,num,r,k,width,heigth;
	num=32;
	sprintf(string,"./project.f/1.bmp");
	readBMP(string,&width,&heigth,photo);
	i=0;
	while(i<heigth)
	{
		j=0;
		while(j<width)
		{
			photo[i][j][0]/=num;
			photo[i][j][1]/=num;
			photo[i][j][2]/=num;
			j++;
		}
		i++;
	}
	for(k=2 ; k<=32 ; k++)
	{
	sprintf(string,"./project.f/%d.bmp",k);
	readBMP(string,&width,&heigth,photo2);
	i=0;
	while(i<width)
		{
			j=0;
			while(j<heigth)
			{
				photo[i][j][0]+=(photo2[i][j][0]/num);
				photo[i][j][1]+=(photo2[i][j][1]/num);
				photo[i][j][2]+=(photo2[i][j][2]/num);
				j++;
			}
			i++;
		}
		saveBMP(photo,width,heigth,"./tashkhis/a.bmp");
	}
	for(i=0 ; i<heigth ; i++){
		for(j=0 ; j<width ; j++){
			photo[i][j][0]=0;
			photo[i][j][1]=0;
			photo[i][j][2]=0;
		}
	}

	num=41;
	sprintf(string,"./project.f/33.bmp");
	readBMP(string,&width,&heigth,photo);
	i=0;
	while(i<heigth)
	{
		j=0;
		while(j<width)
		{
			photo[i][j][0]/=num;
			photo[i][j][1]/=num;
			photo[i][j][2]/=num;
			j++;
		}
		i++;
	}
	for(k=34 ; k<=73 ; k++)
	{
	sprintf(string,"./project.f/%d.bmp",k);
	readBMP(string,&width,&heigth,photo2);
	i=0;
	while(i<width)
		{
			j=0;
			while(j<heigth)
			{
				photo[i][j][0]+=(photo2[i][j][0]/num);
				photo[i][j][1]+=(photo2[i][j][1]/num);
				photo[i][j][2]+=(photo2[i][j][2]/num);
				j++;
			}
			i++;
		}
		saveBMP(photo,width,heigth,"./tashkhis/b.bmp");
	}
	for(i=0 ; i<heigth ; i++){
		for(j=0 ; j<width ; j++){
			photo[i][j][0]=0;
			photo[i][j][1]=0;
			photo[i][j][2]=0;
		}
	}	
	num=32;
	sprintf(string,"./project.f/74.bmp");
	readBMP(string,&width,&heigth,photo);
	i=0;
	while(i<heigth)
	{
		j=0;
		while(j<width)
		{
			photo[i][j][0]/=num;
			photo[i][j][1]/=num;
			photo[i][j][2]/=num;
			j++;
		}
		i++;
	}
	for(k=75 ; k<=105 ; k++)
	{
	sprintf(string,"./project.f/%d.bmp",k);
	readBMP(string,&width,&heigth,photo2);		
	i=0;
	while(i<width)
		{
			j=0;
			while(j<heigth)
			{
				photo[i][j][0]+=(photo2[i][j][0]/num);
				photo[i][j][1]+=(photo2[i][j][1]/num);
				photo[i][j][2]+=(photo2[i][j][2]/num);
				j++;
			}
			i++;
		}
		saveBMP(photo,width,heigth,"./tashkhis/e.bmp");
	}
	for(i=0 ; i<heigth ; i++){
		for(j=0 ; j<width ; j++){
			photo[i][j][0]=0;
			photo[i][j][1]=0;
			photo[i][j][2]=0;
		}
	}	
	num=15;
	sprintf(string,"./project.f/106.bmp");
	readBMP(string,&width,&heigth,photo);
	i=0;
	while(i<heigth)
	{
		j=0;
		while(j<width)
		{
			photo[i][j][0]/=num;
			photo[i][j][1]/=num;
			photo[i][j][2]/=num;
			j++;
		}
		i++;
	}
	for(k=107 ; k<=120 ; k++)
	{
	sprintf(string,"./project.f/%d.bmp",k);
	readBMP(string,&width,&heigth,photo2);		
	i=0;
	while(i<width)
		{
			j=0;
			while(j<heigth)
			{
				photo[i][j][0]+=(photo2[i][j][0]/num);
				photo[i][j][1]+=(photo2[i][j][1]/num);
				photo[i][j][2]+=(photo2[i][j][2]/num);
				j++;
			}
			i++;
		}
		saveBMP(photo,width,heigth,"./tashkhis/i.bmp");
	}
	for(i=0 ; i<heigth ; i++){
		for(j=0 ; j<width ; j++){
			photo[i][j][0]=0;
			photo[i][j][1]=0;
			photo[i][j][2]=0;
		}
	}	
	num=15;
	sprintf(string,"./project.f/121.bmp");
	readBMP(string,&width,&heigth,photo);
	i=0;
	while(i<heigth)
	{
		j=0;
		while(j<width)
		{
			photo[i][j][0]/=num;
			photo[i][j][1]/=num;
			photo[i][j][2]/=num;
			j++;
		}
		i++;
	}
	for(k=122 ; k<=135 ; k++)
	{
	sprintf(string,"./project.f/%d.bmp",k);
	readBMP(string,&width,&heigth,photo2);		
	i=0;
	while(i<width)
		{
			j=0;
			while(j<heigth)
			{
				photo[i][j][0]+=(photo2[i][j][0]/num);
				photo[i][j][1]+=(photo2[i][j][1]/num);
				photo[i][j][2]+=(photo2[i][j][2]/num);
				j++;
			}
			i++;
		}
		saveBMP(photo,width,heigth,"./tashkhis/o.bmp");
	}
	for(i=0 ; i<heigth ; i++){
		for(j=0 ; j<width ; j++){
			photo[i][j][0]=0;
			photo[i][j][1]=0;
			photo[i][j][2]=0;
		}
	}	
	num=17;
	sprintf(string,"./project.f/136bmp");
	readBMP(string,&width,&heigth,photo);
	i=0;
	while(i<heigth)
	{
		j=0;
		while(j<width)
		{
			photo[i][j][0]/=num;
			photo[i][j][1]/=num;
			photo[i][j][2]/=num;
			j++;
		}
		i++;
	}
	for(k=137 ; k<=152 ; k++)
	{
	sprintf(string,"./project.f/%d.bmp",k);
	readBMP(string,&width,&heigth,photo2);		
	i=0;
	while(i<width)
		{
			j=0;
			while(j<heigth)
			{
				photo[i][j][0]+=(photo2[i][j][0]/num);
				photo[i][j][1]+=(photo2[i][j][1]/num);
				photo[i][j][2]+=(photo2[i][j][2]/num);
				j++;
			}
			i++;
		}
		saveBMP(photo,width,heigth,"./tashkhis/r.bmp");
	}
	for(i=0 ; i<heigth ; i++){
		for(j=0 ; j<width ; j++){
			photo[i][j][0]=0;
			photo[i][j][1]=0;
			photo[i][j][2]=0;
		}
	}	
	num=20;
	sprintf(string,"./project.f/153bmp");
	readBMP(string,&width,&heigth,photo);
	i=0;
	while(i<heigth)
	{
		j=0;
		while(j<width)
		{
			photo[i][j][0]/=num;
			photo[i][j][1]/=num;
			photo[i][j][2]/=num;
			j++;
		}
		i++;
	}
	for(k=154 ; k<=173 ; k++)
	{
	sprintf(string,"./project.f/%d.bmp",k);
	readBMP(string,&width,&heigth,photo2);		
	i=0;
	while(i<width)
		{
			j=0;
			while(j<heigth)
			{
				photo[i][j][0]+=(photo2[i][j][0]/num);
				photo[i][j][1]+=(photo2[i][j][1]/num);
				photo[i][j][2]+=(photo2[i][j][2]/num);
				j++;
			}
			i++;
		}
		saveBMP(photo,width,heigth,"./tashkhis/s.bmp");
	}
	
	
}

void cropphoto()
{
	int i,j,k;
	int xx=0,yy=0;
	int width,heigth,count=0,x1=0,x2=0,y1=0,y2=0,m=0,n=0,q=1;
	printf("ax vared konid");
	gets(str);
	readBMP(str,&width,&heigth,photo);
	printf("tedad ax re vared konid");
	scanf("%d %d",&tedadx,&tedady);
	xaddress[0]=0;
	xaddress[tedadx]=width;
	yaddress[0]=0;
	yaddress[tedady]=heigth;
	i=1;
	while(i<tedadx)
	{
		xaddress[i]=(width/tedadx)+xaddress[i-1];
		i++;
	}i=1;
	while(i<tedady)
	{
		yaddress[i]=(heigth/tedady)+yaddress[i-1];
		i++;
	}
	while(xx!=tedadx)
	{
	i=xaddress[xx];
	while(i<xaddress[xx+1])
	{
		j=yaddress[yy];
		while(j<yaddress[yy+1])
		{
			if(photo[i][j][0]!=255 || photo[i][j][1]!=255 || photo[i][j][2]!=255){//==
			if(count==0){
				count=1;
				x1=i;
				//breakkkkkkkkkkkkkkkkkkkkkkkkkkkkk;
			}
		}
		j++;
	}
	i++;
	}
	
	count=0;
	j=yaddress[yy];
	while(j<yaddress[yy+1])
	{
			i=xaddress[xx];
			while( i<xaddress[xx+1])
			{
				if(photo[i][j][0]!=255 || photo[i][j][1]!=255 || photo[i][j][2]!=255){//==
				if(count==0){
					count=1;
					y1=j;
					//breakkkkkkkkkkkkkkkkkkkkkkkkkkkkk;
				}
			}
			i++;
		}
		j++;
	}	
	count=0;
	j=yaddress[yy];
	while(j<yaddress[yy+1])
	{
			i=xaddress[xx];
			while( i<xaddress[xx+1])
			{
				if(photo[i][j][0]!=255 || photo[i][j][1]!=255 || photo[i][j][2]!=255){//==
					y2=j;
					//breakkkkkkkkkkkkkkkkkkkkkkkkkkkkk;
				}
			i++;
		}
		j++;
	}
	i=xaddress[xx];
	while(i<xaddress[xx+1])
	{
		j=yaddress[yy];
		while(j<yaddress[yy+1])
		{
			if(photo[i][j][0]!=255 || photo[i][j][1]!=255 || photo[i][j][2]!=255){//==
				x2=i;
				//breakkkkkkkkkkkkkkkkkkkkkkkkkkkkk;
			}
			j++;
		}
		i++;
	}
	
	for(i=x1; i<x2 ; i++){
		for(j=y1 ; j<y2 ; j++){
			photo2[m][n][0]=photo[i][j][0];
			photo2[m][n][1]=photo[i][j][1];
			photo2[m][n][2]=photo[i][j][2];
			n++;	
		}
		m++;
		n=0;
	}
	m=0;
	sprintf(string,"./tashkhis/%d.bmp",q);
	saveBMP(photo2, y2-y1,x2-x1,string);
	//resize_photo();
	q++;
	yy++;
	if(yy==tedady){
		yy=0;
		xx++;
		}	
	}
	
}

int keyy(){
	int i,j,k=0,x,y,q=0,s;
	for(i=0 ;i<tedadx ; i++){
		for (j=0 ; j<tedady ; j++){
			if(lock[i][j]==key[k]){
				ramz1[k]=i;
				ramz2[k]=j;
				if(keyy2(i,j,k)==1){
					for(s=0 ; s<strlen(key) ; s++)
						printf("%d %d\n",ramz1[s],ramz2[s]);
					q=1;
				}
			}
			if(q==1)break;
		}
		if(q==1)break;
	}
}

int keyy2(int i,int j , int k){
	int x,y,s,flag=0;
	if((k+1)==strlen(key))
		return(1);
	else{
		k++;
		for(x=i-1 ;x<i+2 ; x++){
			for (y=j-1 ; y<j+2 ; y++){
				if(x==i && y==j)continue;
				if(y>=0 && x>=0){
					if(lock[x][y]==key[k]){
						for(s=0 ; s<k ; s++){
							if(x==ramz1[s] && y==ramz2[s])
							flag=1;
						}
						if(flag==0){
							ramz1[k]=x;
							ramz2[k]=y;
							if(keyy2(x,y,k)==1)return(1);
						}else flag=0;
					
					}
				}
				
			}
		}
		
	}
	return (0);
}

void tashkhis(){
	int i,j,k;
	int width,heigth,q=1,some,MIN,m,n,X=0,Y=0;
	int num=tedadx*tedady;
	char word;
	char s[100];
	for(q=1 ; q<=num ; q++){
	sprintf(string,"./tashkhis/a.bmp");
	readBMP(string,&width,&heigth,photo);
//	gets(s);
	sprintf(s,"./tashkhis/%d.bmp",q);
	readBMP(s,&width,&heigth,photo2);
	some=0;
	for(i=0 ; i<500 ; i++){
		for(j=0 ; j<500 ;j++){
			if(photo2[i][j][0]<250){
			some+=(fabs(photo[i][j][0]-photo2[i][j][0]));
			}
		}
	}
	MIN=some;
	word='a';
	some=0;
	sprintf(string,"./tashkhis/b.bmp");
	readBMP(string,&width,&heigth,photo);
	for(i=0 ; i<500 ; i++){
		for(j=0 ; j<500 ;j++){
			if(photo2[i][j][0]<250)
			some+=(fabs(photo[i][j][0]-photo2[i][j][0]));
		}
	}
	if(some<MIN){
		MIN=some;
		word='b';
	}
	some=0;
	sprintf(string,"./tashkhis/e.bmp");
	readBMP(string,&width,&heigth,photo);
	for(i=0 ; i<500 ; i++){
		for(j=0 ; j<500 ;j++){
			if(photo2[i][j][0]<250)
			some+=(fabs((double)photo[i][j][0]-photo2[i][j][0]));
		}
	}
	if(some<MIN){
		MIN=some;
		word='e';
	}
	some=0;
	sprintf(string,"./tashkhis/i.bmp");
	readBMP(string,&width,&heigth,photo);
	for(i=0 ; i<500 ; i++){
		for(j=0 ; j<500 ;j++){
			if(photo2[i][j][0]<250)
			some+=(fabs((double)photo[i][j][0]-photo2[i][j][0]));
		}
	}
	if(some<MIN){
		MIN=some;
		word='i';
	}	
	some=0;
	sprintf(string,"./tashkhis/o.bmp");
	readBMP(string,&width,&heigth,photo);
	for(i=0 ; i<500 ; i++){
		for(j=0 ; j<500 ;j++){
			if(photo2[i][j][0]<250)
			some+=(fabs((double)photo[i][j][0]-photo2[i][j][0]));
		}
	}
	if(some<MIN){
		MIN=some;
		word='o';
	}	
	some=0;
	sprintf(string,"./tashkhis/r.bmp");
	readBMP(string,&width,&heigth,photo);
	for(i=0 ; i<500 ; i++){
		for(j=0 ; j<500 ;j++){
			if(photo2[i][j][0]<250)
			some+=(fabs((double)photo[i][j][0]-photo2[i][j][0]));
		}
	}	
	if(some<MIN){
		MIN=some;
		word='r';
	}
	some=0;
	sprintf(string,"./tashkhis/s.bmp");
	readBMP(string,&width,&heigth,photo);
	for(i=0 ; i<500 ; i++){
		for(j=0 ; j<500 ;j++){
			if(photo2[i][j][0]<250)
			some+=(fabs((double)photo[i][j][0]-photo2[i][j][0]));
		}
	}	
	if(some<MIN){
		MIN=some;
		word='s';
	}
	lock[X][Y]=word;
	Y++;
	if(Y==tedady){
		Y=0;
		X++;
	}
	}
	for(i=0 ; i<tedadx ; i++){
	for(j=0 ; j<tedady ; j++){
		printf("%c ",lock[i][j]);
	}
	printf("\n");
}
}

void show()
{
	int i,j,k,width,heigth;
	readBMP(str,&width,&heigth,photo);
	for(k=0 ; k<strlen(key) ; k++){
		i=xaddress[ramz1[k]];
		while(i<xaddress[ramz1[k]+1])
		{
			j=yaddress[ramz2[k]];
			while(j<yaddress[ramz2[k]+1])
			{
				if(photo[i][j][0]!=255 || photo[i][j][1]!=255 || photo[i][j][2]!=255){//==
					photo[i][j][0]=20;
					photo[i][j][1]=250;
					photo[i][j][2]=20;
				}
				j++;
			}
		i++;
		}
	}
	saveBMP(photo,width,heigth,"main2.bmp");
	
}

















