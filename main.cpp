#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <crt.cpp>

using namespace std;

class othello
{
public:
    int x[8],y[8],value[8][8];
    int xtemp,ytemp;
    othello();
    void bead ();
    void flipcheck (int a,int b);
    bool poscheck (int a,int b,int v);
    bool possible (int v);
    void input (int v);
    void score ();
    void win ();
};

othello::othello()
{
    for (int n=0;n<8;n++)
    {
        x[n] = 7+(n+1)+n+n;
        y[n] = 4+(n+1)+n;
    };
    for (int m=0;m<8;m++)
    {
        for (int n=0;n<8;n++)
        {
            value[m][n] = 0;
        };
    };
    Textattr(2,0);
    int i=1;
    for (int x=8;x<30;x+=3)
    {
        gotoxy(x,3); cout<<i;i++;
    }
    i=1;
    for (int y=5;y<20;y+=2)
    {
        gotoxy(6,y); cout<<i;i++;
    }
    for (int x=8;x<31;x++)
    {
        for (int y=5;y<20;y++)
        {
            gotoxy (x,y);
            Textattr(0,2);
            puts(" ");
        }
    }
    for (int x=8;x<31;x++)
    {
        for (int y=6;y<20;y+=2)
        {
            gotoxy (x,y);
            Textattr(8,2);
            puts("-");
        }
    }
     for (int x=10;x<31;x+=3)
    {
        for (int y=5;y<20;y++)
        {
            gotoxy (x,y);
            Textattr(8,2);
            puts("|");
        }
    }
    value[4-1][4-1]=3;
    value[4-1][5-1]=2;
    value[5-1][5-1]=3;
    value[5-1][4-1]=2;
    Textattr(7,0);
    gotoxy (32,18);cout<<"Othello 1.5";
    gotoxy (32,19);cout<<"by: Bima Panji Yudasmara (2914100033)";

}

void othello::bead ()
{
    for (int m=0;m<8;m++)
    {
        for (int n=0;n<8;n++)
        {
        switch (value[m][n])
        {
        case 1:
            gotoxy (x[m],y[n]);
            Textattr(0,2);
            puts(" ");
            break;
        case 2:
            gotoxy (x[m],y[n]);
            Textattr(0,2);
            puts("O");
            break;
        case 3:
            gotoxy (x[m],y[n]);
            Textattr(7,2);
            puts("O");
            break;
        }
        }
    }


};

bool othello::poscheck (int a,int b,int v)
{
    int n=0;

    if (value[a][b]!=0)return false;

    for (int i=2;i<8;i++)
    {
        if (a+i>7) break;
        if (value[a+i][b]==0)break;
        if (value[a+1][b]==0||value[a+1][b]==v)break;
        if (value[a+i][b]==v){n++;}
    }
    for (int i=2;i<8;i++)
    {;
        if (b+i>7) break;
        if (value[a][b+i]==0)break;
        if (value[a][b+1]==0||value[a][b+1]==v)break;
        if (value[a][b+i]==v){n++;}
    }
    for (int i=2;i<8;i++)
    {
        if (a-i<0) break;
        if (value[a-i][b]==0)break;
        if (value[a-1][b]==0||value[a-1][b]==v)break;
        if (value[a-i][b]==v){n++;}
    }
    for (int i=2;i<8;i++)
    {
        if (b-i<0) break;
        if (value[a][b-i]==0)break;
        if (value[a][b-1]==0||value[a][b-1]==v)break;
        if (value[a][b-i]==v){n++;}
    }
    for (int i=2;i<8;i++)
    {
        if (a+i>7||b+i>7) {break;}
        if (value[a+i][b+i]==0){break;}
        if (value[a+1][b+1]==0||value[a+1][b+1]==v){break;}
        if (value[a+i][b+i]==v){n++;}
    }
    for (int i=2;i<8;i++)
    {
        if (a-i<0||b-i<0) break;
        if (value[a-i][b-i]==0)break;
        if (value[a-1][b-1]==0||value[a-1][b-1]==v)break;
        if (value[a-i][b-i]==v){n++;}
    }
    for (int i=2;i<8;i++)
    {
        if (a+i>7||b-i<0) break;
        if (value[a+i][b-i]==0)break;
        if ((value[a+1][b-1]==0)||(value[a+1][b-1]==v))break;
        if (value[a+i][b-i]==v){n++;}
    }
    for (int i=2;i<8;i++)
    {
        if (b+i>7||a-i<0) break;
        if (value[a-i][b+i]==0)break;
        if (value[a-1][b+1]==0||value[a-1][b+1]==v)break;
        if (value[a-i][b+i]==v){n++;}
    }
    if(n==0) return false;
    else return true;
}

bool othello::possible (int v)
{
    int r=0;
    for (int a=0;a<8;a++)
    {
        for (int b=0;b<8;b++)
        {
            int n=0;

            for (int i=2;i<8;i++)
            {
                if (value[a][b]!=0)break;
                if (a+i>7) break;
                if (value[a+i][b]==0)break;
                if (value[a+1][b]==0||value[a+1][b]==v)break;
                if (value[a+i][b]==v){n++;}
            }
            for (int i=2;i<8;i++)
            {
                if (value[a][b]!=0)break;
                if (b+i>7) break;
                if (value[a][b+i]==0)break;
                if (value[a][b+1]==0||value[a][b+1]==v)break;
                if (value[a][b+i]==v){n++;}
            }
            for (int i=2;i<8;i++)
            {
                if (value[a][b]!=0)break;
                if (a-i<0) break;
                if (value[a-i][b]==0)break;
                if (value[a-1][b]==0||value[a-1][b]==v)break;
                if (value[a-i][b]==v){n++;}
            }
            for (int i=2;i<8;i++)
            {
                if (value[a][b]!=0)break;
                if (b-i<0) break;
                if (value[a][b-i]==0)break;
                if (value[a][b-1]==0||value[a][b-1]==v)break;
                if (value[a][b-i]==v){n++;}
            }
            for (int i=2;i<8;i++)
            {
                if (value[a][b]!=0)break;
                if (a+i>7||b+i>7) break;
                if (value[a+i][b+i]==0)break;
                if (value[a+1][b+1]==0||value[a+1][b+1]==v)break;
                if (value[a+i][b+i]==v){n++;}
            }
            for (int i=2;i<8;i++)
            {
                if (value[a][b]!=0)break;
                if (a-i<0||b-i<0) break;
                if (value[a-i][b-i]==0)break;
                if (value[a-1][b-1]==0||value[a-1][b-1]==v)break;
                if (value[a-i][b-i]==v){n++;}
            }
            for (int i=2;i<8;i++)
            {
                if (value[a][b]!=0)break;
                if (a+i>7||b-i<0) break;
                if (value[a+i][b-i]==0)break;
                if ((value[a+1][b-1]==0)||(value[a+1][b-1]==v))break;
                if (value[a+i][b-i]==v){n++;}
            }
            for (int i=2;i<8;i++)
            {
                if (value[a][b]!=0)break;
                if (b+i>7||a-i<0) break;
                if (value[a-i][b+i]==0)break;
                if (value[a-1][b+1]==0||value[a-1][b+1]==v)break;
                if (value[a-i][b+i]==v){n++;}
            }
            if(n>0) r++;
        }
    }
    if (r==0) {return false;}
    else return true;
}

void othello::flipcheck (int a,int b)
{
    for (int i=1;i<(8);i++)
    {
        if (value[a+i][b]==0)break;
        if (value[a+i][b]==value[a][b])
        {
            for (int j=a;j<a+i;j++)value[j][b]=value[a][b];
            break;
        }
    }
    for (int i=1;i<(8);i++)
    {
        if (value[a][b+i]==0)break;
        if (value[a][b+i]==value[a][b])
        {
            for (int j=b;j<b+i;j++) value[a][j]=value[a][b];
            break;
        }
    }
    for (int i=1;i<(8);i++)
    {
        if (value[a-i][b]==0)break;
        if (value[a-i][b]==value[a][b])
        {
            for (int j=a;j>=a-i;j--) value[j][b]=value[a][b];
            break;
        }
    }
    for (int i=1;i<(8);i++)
    {
        if (value[a][b-i]==0)break;
        if (value[a][b-i]==value[a][b])
        {
            for (int j=b-1;j>=i;j--) value[a][j]=value[a][b];
            break;
        }
    }
    for (int i=1;i<(8);i++)
    {
        if (value[a+i][b+i]==0)break;
        if (value[a+i][b+i]==value[a][b])
        {
            for (int j=1;j<i;j++)value[a+j][b+j]=value[a][b];
            break;
        }
    }
    for (int i=1;i<(8);i++)
    {
        if (value[a-i][b-i]==0)break;
        if (value[a-i][b-i]==value[a][b])
        {
            for (int j=1;j<i;j++) value[a-j][b-j]=value[a][b];
            break;
        }
    }
    for (int i=1;i<(8);i++)
    {
        if (value[a+i][b-i]==0)break;
        if (value[a+i][b-i]==value[a][b])
        {
            for (int j=1;j<i;j++)value[a+j][b-j]=value[a][b];
            break;
        }
    }
    for (int i=1;i<(8);i++)
    {
        if (value[a-i][b+i]==0)break;
        if (value[a-i][b+i]==value[a][b])
        {
            for (int j=1;j<i;j++)value[a-j][b+j]=value[a][b];
            break;
        }
    }

}

void othello::score()
{
    int xa,yb;
    int s;
    Textattr(7,0);
    gotoxy (32,9);cout<<"Skor:";
    for (int a=2;a<4;a++)
    {
        s=0;
        for (xa=0;xa<8;xa++)
        {
            for (yb=0;yb<8;yb++)
            {
                if (value[xa][yb]==a) s++;
            }
        }
        if (a==2) {gotoxy (32,10);cout<<"Hitam: "<<s<<"   ";}
        else if (a==3) {gotoxy (32,11);cout<<"Putih: "<<s<<"   ";}
    }
}
void othello::win()
{
    int xa,yb,s,sh,sp;
    for (int a=2;a<4;a++)
    {
        s=0;
        for (xa=0;xa<8;xa++)
        {
            for (yb=0;yb<8;yb++)
            {
                if (value[xa][yb]==a) s++;
            }
        }
        if (a==2) {sh=s;}
        else if (a==3) {sp=s;}
    }
    if (sh>sp) {gotoxy(32,15);cout<<"Hitam Menang";}
    else if (sp>sh) {gotoxy(32,15);cout<<"Putih Menang";}
    else {gotoxy(32,15);cout<<"Seri";};
}

void othello::input (int v)
{
    gotoxy (32,5);
    Textattr(7,0);
    switch (v)
    {
        case 2: {cout << "Hitam:";break;}
        case 3: {cout << "Putih:";break;}
    }
    gotoxy (32,6);
    cout << "                               ";
    gotoxy (32,7);
    cout << "                               ";
    gotoxy (32,6);
    cout << "Masukkan koordinat X: ";
    cin>>xtemp;
    gotoxy (32,7);
    cout << "Masukkan koordinat Y: ";
    cin>>ytemp;
}

int main()
{
    othello o;
    int n=1;
    while(n>=1)
    {
        o.bead();
        n=0;
        for (int a=2;a<4;a++)
        {
            o.score ();
            if (o.possible(a))
            {
                do{
                o.input(a);
                }while (!o.poscheck(o.xtemp-1,o.ytemp-1,a));
                o.value[o.xtemp-1][o.ytemp-1]=a;
                o.bead();
                o.flipcheck((o.xtemp-1),(o.ytemp-1));o.bead();
                n++;
            }
            o.score ();
        }
        o.score ();
    };
    gotoxy (32,13);cout<<"Selesai";
    o.win ();
    getch();
}
