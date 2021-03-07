#include<iostream>
#include<fstream>
#include<cstdlib>
#include<windows.h>
#include<stdlib.h>
#include<ctime>
using namespace std;
void setupboard(int a[][10],int &score);
void playgame(int a[][10],int &score);
void printxy(int  ,int  ,int color);
int main (){
    int a[10][10]={0},score=0,ar[10]={0},temp=0;
   setupboard( a,score);
   playgame( a,score);
   cout<<"time's up !"<<"your final score :  "<<score<<endl;
     ifstream fin("highscores.txt");
    if(!fin)
        cout<<"error";
    else{
        for(int i=0;i<10;i++){
       fin>>ar[i];
       if(ar[i]<score){
           temp=ar[i];
           ar[i]=score;
           score=temp;
       }
    }
    }
fin.close();


 ofstream fout("highscores.txt");
    if(!fout)
        cout<<"error";
    else{
            cout<<"high scores : ";
    for(int i=0;i<10;i++){
       fout<<ar[i]<<endl;
       cout<<endl<<ar[i]<<endl;
    }
    }
fout.close();
 return 0;
}
void printxy(int x ,int y ,int color){
COORD c;
//c.X=x;
//c.Y=y;
HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO info;
GetConsoleScreenBufferInfo(h, &info);
short ret=info.wAttributes;
//SetConsoleCursorPosition(h,c);
SetConsoleTextAttribute(h,color);

     cout<<"  ";

cout.flush();
SetConsoleTextAttribute(h, ret);
}

void setupboard(int a[][10],int &score){
   int n=0,g=0,c=0;
    srand(time(0));
   for(int i=0;i<10 ;i++){
    for(int j=0;j<10;j++){
        n= 1 + rand() % 5 ;
        if(a[i][j+1]!=n || a[i][j+2]!=n)
            g++;
        if( a[i+1][j]!=n || a[i+2][j]!=n )
            g++;
        if( a[i][j-1]!=n || a[i][j-2]!=n )
            g++;
        if( a[i-1][j]!=n || a[i-2][j]!=n)
            g++;
        if(g==4)
        a[i][j]=n;
        if(a[i][j]==0)
            j--;
        g=0;
    }
   }
cout<<"To load game enter 1 else enter any number ";
c=0;
cin>>c;
if(c==1){
   ifstream fin("savedgame.txt");
    if(!fin)
        cout<<"error";
    else{
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                fin>>a[i][j];
            }
        }
        fin>>score;

    }
fin.close();
}


 for(int i=0;i<10 ;i++){
    for(int j=0;j<10;j++){
    if(a[i][j]==1){
         printxy(0,0,a[i][j]+30);
    }
 else  if(a[i][j]==2){
         printxy(0,0,a[i][j]+40);
    }
  else   if(a[i][j]==3){
         printxy(0,0,a[i][j]+50);
    }
    else if(a[i][j]==4){
         printxy(0,0,a[i][j]+71);
    }
   else  if(a[i][j]==5){
         printxy(0,0,a[i][j]+1000);
    }
    cout<<" ";
    }cout<<endl<<endl;
}
cout<<"your score :  "<<score<<endl;
}
void playgame(int a[][10] , int &score){
     int x=0,y=0,xx=0,yy=0,temp=0,z=0,c=0, d=0,r=60,q=0,w=0,l=0,s=0,b=0;
     double timer=clock();
cout<<"enter x for object one";
     cin>>y;
cout<<"enter y for object one";
     cin>>x;
cout<<"enter x for object two";
     cin>>yy;
cout<<"enter y for object two";
     cin>>xx;
     system("cls");
           while( ( r-( q/1000 ) +56) >=0 && b!=1 )  {
     temp=a[x][y];
     a[x][y]=a[xx][yy];
     a[xx][yy]=temp;
     c=0;
     if(a[x][y]==a[x+1][y] && a[x][y]==a[x+2][y]){  //downwards
        z=0;
        c++;
        score=score+5;
        while(x>z){
            a[x+2-z][y]=a[x+2-z-3][y];
        z++;
        }
        a[0][y]=1+rand()%5;
        a[1][y]=1+rand()%5;
        a[2][y]=1+rand()%5;
     }
       if(a[x][y]==a[x+1][y] && a[x][y]==a[x-1][y]){  //down and up
        z=0;
        c++;
        score=score+5;
        while(x>z){
            a[x+1-z][y]=a[x+1-z-3][y];
        z++;
        }
        a[0][y]=1+rand()%5;
        a[1][y]=1+rand()%5;
        a[2][y]=1+rand()%5;
     }

     if(a[x][y]==a[x-1][y] && a[x][y]==a[x-2][y]){  //upwards
          z=0;
          c++;
          score=score+5;
        while(x>z){
            a[x-z][y]=a[x-z-3][y];
                   z++;
        }
        a[0][y]=1+rand()%5;
        a[1][y]=1+rand()%5;
        a[2][y]=1+rand()%5;
     }
     if(a[x][y]==a[x][y+1] && a[x][y]==a[x][y+2]){    //right side
             z=0;
             c++;
             score=score+5;
        while(x>z){
            a[x-z][y]=a[x-z-1][y];
            a[x-z][y+1]=a[x-z-1][y+1];
            a[x-z][y+2]=a[x-z-1][y+2];
                  z++;
        }
        a[0][y]=1+rand()%5;
        a[0][y+1]=1+rand()%5;
        a[0][y+2]=1+rand()%5;
     }
      if(a[x][y]==a[x][y+1] && a[x][y]==a[x][y-1]){    //right and left
             z=0;
             c++;
             score=score+5;
        while(x>z){
            a[x-z][y]=a[x-z-1][y];
            a[x-z][y+1]=a[x-z-1][y+1];
            a[x-z][y-1]=a[x-z-1][y-1];
                  z++;
        }
        a[0][y]=1+rand()%5;
        a[0][y+1]=1+rand()%5;
        a[0][y-1]=1+rand()%5;
     }

     if(a[x][y]==a[x][y-1] && a[x][y]==a[x][y-2]){        //left side
            z=0;
            c++;
            score=score+5;
        while(x>z){
            a[x-z][y]=a[x-z-1][y];
            a[x-z][y-1]=a[x-z-1][y-1];
            a[x-z][y-2]=a[x-z-1][y-2];
        z++;
        }
        a[0][y]=1+rand()%5;
        a[0][y-1]=1+rand()%5;
        a[0][y-2]=1+rand()%5;
     }

     if(a[xx][yy]==a[xx+1][yy] && a[xx][yy]==a[xx+2][yy]){      //downwards
           z=0;
           c++;
           score=score+5;
        while(xx>z){
            a[xx+2-z][yy]=a[xx+2-z-3][yy];
        z++;
        }
        a[0][yy]=1+rand()%5;
        a[1][yy]=1+rand()%5;
        a[2][yy]=1+rand()%5;
     }
       if(a[xx][yy]==a[xx+1][yy] && a[xx][yy]==a[xx-1][yy]){              //down and up
        z=0;
        c++;
        score=score+5;
        while(xx>z){
            a[xx+1-z][yy]=a[xx+1-z-3][yy];
        z++;
        }
        a[0][yy]=1+rand()%5;
        a[1][yy]=1+rand()%5;
        a[2][yy]=1+rand()%5;
     }

     if(a[xx][yy]==a[xx-1][yy] && a[xx][yy]==a[xx-2][yy]){       //upwards
          z=0;
          c++;
          score=score+5;
        while(xx>z){
            a[xx-z][yy]=a[xx-z-3][yy];
        z++;
        }
        a[0][yy]=1+rand()%5;
        a[1][yy]=1+rand()%5;
        a[2][yy]=1+rand()%5;
     }
     if(a[xx][yy]==a[xx][yy+1] && a[xx][yy]==a[xx][yy+2]){       //right side
             z=0;
             c++;
             score=score+5;
        while(xx>z){
            a[xx-z][yy]=a[xx-z-1][yy];
            a[xx-z][yy+1]=a[xx-z-1][yy+1];
            a[xx-z][yy+2]=a[xx-z-1][yy+2];
                  z++;
        }
        a[0][yy]=1+rand()%5;
        a[0][yy+1]=1+rand()%5;
        a[0][yy+2]=1+rand()%5;
     }
     if(a[xx][yy]==a[xx][yy+1] && a[xx][yy]==a[xx][yy-1]){    //right and left
             z=0;
             c++;
             score=score+5;
        while(xx>z){
            a[xx-z][yy]=a[xx-z-1][yy];
            a[xx-z][yy+1]=a[xx-z-1][yy+1];
            a[xx-z][yy-1]=a[xx-z-1][yy-1];
                  z++;
        }
        a[0][yy]=1+rand()%5;
        a[0][yy+1]=1+rand()%5;
        a[0][yy-1]=1+rand()%5;
     }

     if(a[xx][yy]==a[xx][yy-1] && a[xx][yy]==a[xx][yy-2]){           //left side
                z=0;
                c++;
                score=score+5;
        while(xx>z){
            a[xx-z][yy]=a[xx-z-1][yy];
            a[xx-z][yy-1]=a[xx-z-1][yy-1];
            a[xx-z][yy-2]=a[xx-z-1][yy-2];
        z++;
        }
        a[0][yy]=1+rand()%5;
        a[0][yy-1]=1+rand()%5;
        a[0][yy-2]=1+rand()%5;
     }
    else if(c==0){
            temp=a[x][y];
     a[x][y]=a[xx][yy];
     a[xx][yy]=temp;
     c=0;
    }
      for(int i=0;i<10 ;i++){
    for(int j=0;j<10;j++){

  if((a[i][j]==a[i+1][j] && a[i][j]==a[i+2][j]) && (i<8)){  //downwards
        z=0;
        score=score+5;

        while(i>z){
            a[i+2-z][j]=a[i+2-z-3][j];
        z++;
        }
        a[0][j]=1+rand()%5;
        a[1][j]=1+rand()%5;
        a[2][j]=1+rand()%5;
        }
       if((a[i][j]==a[i+1][j] && a[i][j]==a[i-1][j]) && (i!=9) && (i!=0)){  //down and up
        z=0;
        score=score+5;
        while(i>z){
            a[i+1-z][j]=a[i+1-z-3][j];
        z++;
        }
        a[0][j]=1+rand()%5;
        a[1][j]=1+rand()%5;
        a[2][j]=1+rand()%5;

     }

     if( (a[i][j]==a[i-1][j] && a[i][j]==a[i-2][j]) && (i>1)){  //upwards
          z=0;
        score=score+5;
        while(i>z){
            a[i-z][j]=a[i-z-3][j];
                   z++;
        }
        a[0][j]=1+rand()%5;
        a[1][j]=1+rand()%5;
        a[2][j]=1+rand()%5;

     }
     if( (a[i][j]==a[i][j+1] && a[i][j]==a[i][j+2]) && (j<8)){    //right side
             z=0;

        score=score+5;
        while(i>z){
            a[i-z][j]=a[i-z-1][j];
            a[i-z][j+1]=a[i-z-1][j+1];
            a[i-z][j+2]=a[i-z-1][j+2];
                  z++;
        }
        a[0][j]=1+rand()%5;
        a[0][j+1]=1+rand()%5;
        a[0][j+2]=1+rand()%5;

     }
      if((a[i][j]==a[i][j+1] && a[i][j]==a[i][j-1]) && (j!=9) && (j!=0)) {    //right and left
             z=0;
        score=score+5;
        while(i>z){
            a[i-z][j]=a[i-z-1][j];
            a[i-z][j+1]=a[i-z-1][j+1];
            a[i-z][j-1]=a[i-z-1][j-1];
                  z++;
        }
        a[0][j]=1+rand()%5;
        a[0][j+1]=1+rand()%5;
        a[0][j-1]=1+rand()%5;

                 }
    }
   }

   for(int i=0;i<10 ;i++){
    for(int j=0;j<10;j++){
    if(a[i][j]==1){
         printxy(0,0,a[i][j]+30);
    }
 else  if(a[i][j]==2){
         printxy(0,0,a[i][j]+40);
    }
  else   if(a[i][j]==3){
         printxy(0,0,a[i][j]+50);
    }
    else if(a[i][j]==4){
         printxy(0,0,a[i][j]+71);
    }
   else  if(a[i][j]==5){
         printxy(0,0,a[i][j]+1000);
    }
    cout<<" ";
    }cout<<endl<<endl;
}
   cout<<"your score : "<<score<<endl;
   d=0;
   cout<<"To save your game enter 1 else enter any number ";
   cin>>d;
   if(d==1){
    ofstream fout("savedgame.txt");
    if(!fout)
        cout<<"error";
    else{
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                fout<<a[i][j]<<" ";
            } fout<<endl;
        }
        fout<<endl<<score;
    }
fout.close();
   }
    if(clock() > (timer+1000)){
        timer=clock();
        cout<<"to pause enter : 1   ";
        cin>>l;
        if(l==1){
            temp=clock();
        cout<<"to resume enter any number :   ";
            cin>>s;
           w=w +(clock()-temp);
        }
r=60;
q=clock()-w;
        r=r-(q/1000);
      cout<<"Remaining time : "<<r<<"seconds"<<endl;
    }
    cout<<"To exit the game enter : 1 else enter any number other than 1 :   ";
    cin>>b;
    if(b!=1){
      cout<<"enter x for object one";
     cin>>y;
cout<<"enter y for object one";
     cin>>x;
cout<<"enter x for object two";
     cin>>yy;
cout<<"enter y for object two";
     cin>>xx;
    }
     system("cls");
           }

}
