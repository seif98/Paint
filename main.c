#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include "mouse_dec.cpp"


/********************************************************************/
void drawframe();
void free_paint();
void line(int x1,int y1,int x2,int y2,int color);
void square(int x1,int y1,int l,int color);
void Rect(int x1,int y1,int l,int w,int color);
void triangle(int x1,int y1,int x2,int y2,int x3,int y3,int color);
void draw_line_frame();
void draw_square_frame();
void draw_rect_frame();
void draw_tri_frame();
/********************************************************************/
// t is text color and f is background color of that text.
void color(int t,int f)
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,f*16+t);
}
/********************************************************************/
void gotoxy(int x, int y)
{
    HANDLE hConsoleOutput;
    COORD dwCursorPosition;
    //cout.flush();
    dwCursorPosition.X = x;
    dwCursorPosition.Y = y;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput,dwCursorPosition);
}
/********************************************************************/


int main()
{
    drawframe();
    gotoxy(0,0);



//    line(10,10,10,20);
//    line(10,20,20,10);
//    line(10,10,20,10);
    // square(10,10,4);
    // Rect(10,10,10,10);
    //triangle(10,10,20,10,20,20);
//    gotoxy(16,20);

        free_paint();











    return 0;
}



/********************************************************************/

void drawframe()
{

    int i=0;
    int j=0;


    gotoxy(15,1);
    color(0,2);
    printf(" FREE_PAINT ");

//    gotoxy(26,1);
//    color(0,2);
//    printf(" DRAW_FIGURE ");

    gotoxy(35,1);
    color(0,2);
    printf(" CLEAR ");

    gotoxy(49,1);
    color(0,2);
    printf(" ERASE ");

    gotoxy(62,1);
    color(0,2);
    printf(" EXIT ");


    for(i=1 ; i<=15 ; i++)
    {
        gotoxy(5+j,5);
        color(0,i);
        printf("   ");
        color(7,0);
        j +=6;
    }


    color(1,0);
    for(i=1 ; i<95 ; i++)
    {
        gotoxy(i,7);
        printf("%c", 176);

    }

    for(i=1 ; i<=42 ; i++)
    {
        gotoxy(1,i);
        printf("%c", 186);

    }

    for(i=1 ; i<=42 ; i++)
    {
        gotoxy(95,i);
        printf("%c", 186);

    }

    for(i=1 ; i<95 ; i++)
    {
        gotoxy(i,42);
        printf("%c", 205);

    }
    gotoxy(1,42);
    printf("%c", 206);
    gotoxy(95,42);
    printf("%c", 206);

    gotoxy(98,1);
    color(0,2);
    printf(" Geometric Figures ");

    draw_line_frame();
    draw_square_frame();
    draw_rect_frame();
    draw_tri_frame();

    for(i=97 ; i<120 ; i++)
    {
        gotoxy(i,37);
        color(15,0);
        printf("-");

    }



    gotoxy(100,39);
    color(0,14);
    printf(" x > 1 ");
    gotoxy(110,39);
    printf(" x < 95 ");

    gotoxy(100,41);
    printf(" y > 7 ");
    gotoxy(110,41);
    printf(" y < 42 ");
    color(2,0);


}

/********************************************************************/

void free_paint()
{
    int temp = 7;
    static DMOUSE m;            // the mouse handler
    static int scolor = 10;     // the selected color
    static char schar = '*';    // the caracter to be printed

    static int y,x;


    int x1,x2,y1,y2,x3,y3,l,w;






    while(1)
    {
        mouse(&m);                  // exits when left button mouse clicked
        x = m.coordinates.X;        // the position of mouse click
        y = m.coordinates.Y;

        if( (x<95 && x>1 ) && (y>7 && y<42 ) )
        {
            gotoxy(x,y);
            color(scolor,0);
            printf("%c",schar);
            color(7,0);
        }


        else
        {
            if( (x<7 && x>4 ) && y==5 )
                scolor=1;

            if( (x<13 && x>10 ) && y==5 )
                scolor=2;

            if( (x<19 && x>16 ) && y==5 )
                scolor=3;

            if( (x<25 && x>22 ) && y==5 )
                scolor=4;

            if( (x<31 && x>28 ) && y==5 )
                scolor=5;

            if( (x<37 && x>34 ) && y==5 )
                scolor=6;

            if( (x<43 && x>40 ) && y==5 )
                scolor=7;

            if( (x<49 && x>46 ) && y==5 )
                scolor=8;

            if( (x<55 && x>52 ) && y==5 )
                scolor=9;

            if( (x<61 && x>58 ) && y==5 )
                scolor=10;

            if( (x<67 && x>64 ) && y==5 )
                scolor=11;

            if( (x<73 && x>70 ) && y==5 )
                scolor=12;

            if( (x<79 && x>76 ) && y==5 )
                scolor=13;

            if( (x<85 && x>82 ) && y==5 )
                scolor=14;

            if( (x<91 && x>88 ) && y==5 )
                scolor=15;

            if( (x<27 && x>14 ) && y==1 )
            {
                schar = '*';
                scolor = temp;
            }

            if( (x<42 && x>34 ) && y==1 )
            {
                system("CLS");
                drawframe();

                gotoxy(0,0);
            }

            if( (x<56 && x>48 ) && y==1 )
            {
                schar = ' ';

                if(scolor != 0)
                    temp = scolor;

                scolor = 0;
            }

            if( (x<68 && x>61 ) && y==1 )
            {
                color(7,0);
                gotoxy(1,44);
                exit(0);
            }


            if( (x<110 && x>104 ) && y==4 )
            {
                gotoxy(103,7);
                scanf("%d",&x1);

                gotoxy(113,7);
                scanf("%d",&y1);

                gotoxy(103,9);
                scanf("%d",&x2);

                gotoxy(113,9);
                scanf("%d",&y2);


                if((x1<95 && x1>1 ) && (y1>7 && y1<42 ) && (x2<95 && x2>1 ) && (y2>7 && y2<42 ))
                    line(x1,y1,x2,y2,scolor);

                draw_line_frame();

            }


            if( (x<112 && x>103 ) && y==12 )
            {
                gotoxy(103,15);
                scanf("%d",&x1);

                gotoxy(113,15);
                scanf("%d",&y1);

                gotoxy(108,17);
                scanf("%d",&l);

                if((x1<95 && x1>1 ) && (y1>7 && y1<42 ) )
                    square(x1,y1,l,scolor);

                draw_square_frame();

            }


            if( (x<113 && x>102 ) && y==20 )
            {
                gotoxy(103,23);
                scanf("%d",&x1);

                gotoxy(113,23);
                scanf("%d",&y1);

                gotoxy(103,25);
                scanf("%d",&l);

                gotoxy(113,25);
                scanf("%d",&w);

                if((x1<95 && x1>1 ) && (y1>7 && y1<42 ) && ( (x1+l)<=95 ) && ( (y1+w)<=42 ))
                    Rect(x1,y1,l,w,scolor);

                draw_rect_frame();

            }


            if( (x<114 && x>103 ) && y==28 )
            {
                gotoxy(103,31);
                scanf("%d",&x1);

                gotoxy(113,31);
                scanf("%d",&y1);

                gotoxy(103,33);
                scanf("%d",&x2);

                gotoxy(113,33);
                scanf("%d",&y2);

                gotoxy(103,35);
                scanf("%d",&x3);

                gotoxy(113,35);
                scanf("%d",&y3);


                if((x1<95 && x1>1 ) && (y1>7 && y1<42 ) && (x2<95 && x2>1 ) && (y2>7 && y2<42 ) && (x3<95 && x3>1 ) && (y3>7 && y3<42 ))
                    triangle(x1,y1,x2,y2,x3,y3,scolor);

                draw_tri_frame();

            }




        }


    }

}

/********************************************************************/

void line(int x1,int y1,int x2,int y2 ,int col)
{
    int i=0;
    int x=0;
    int y=0;
    int temp=0;
    int c;
    int m;

    if(x1>x2)
    {
        temp=x1;
        x1=x2;
        x2=temp;

        temp=y1;
        y1=y2;
        y2=temp;
    }



    if( !(x1 == x2) )
    {
        m = ((y2-y1) / (x2-x1) );

        if ( ( (y2-y1) % (x2-x1) ) !=  0)
            m++;
    }



    x=x1+i;
    for(i=1 ;x<=x2 && y<=y2 ;i++)
    {
        x=x1+i;
        if(x1==x2)
        {
            x=x1;
            m=1;
        }

        y=m*i + y1;
        if(y1==y2)
        {
            y=y1;
            m=0;
        }

        gotoxy(x,y);
        printf("*");
    }


    /*int dx,dy,step;

    if(x1>x2)
    {
        temp=x1;
        x1=x2;
        x2=temp;

        temp=y1;
        y1=y2;
        y2=temp;
    }

    c=y1-(dy/dx)4*x1;
    dx=(x2-x1);
    dy=(y2-y1);
    for (i=y1;i<y2;i++){
        for(int j=x1;j<x2;j++){
            if( ((dy/dx)*j+c) == (i) ) {
                    gotoxy(j,i);
                    color(col,0);
                    printf("*");
                    break;
            }
        }
    }
    /*if(dx>=dy)
        step=dx;
    else
        step=dy;

    dx=dx/step;
    dy=dy/step;

    x=x1;
    y=y1;

    i=1;
    while(i<=step)
    {
        gotoxy(x,y);
        color(col,0);
        printf("*");
        x=x+dx;
        y=y+dy;
        i=i+1;
    }*/
}

/*********************************************************************/

void square(int x1,int y1,int l,int col)
{
    int i=0;
    int j=0;

    for(i=0 ; i<l ; i++)
    {
        for(j=0 ; j<l/2 ; j++)
        {
            gotoxy(x1+i,y1+j);
            if( i == 0 || i == l-1 || j == 0 || j == l/2-1 )
            {
                color(col,0);
                printf("*");
            }

        }
    }
}


/*********************************************************************/
void Rect(int x1,int y1,int l,int w,int col)
{
    int i=0;
    int j=0;

    for(i=0 ; i<l ; i++)
    {
        for(j=0 ; j<w ; j++)
        {
            gotoxy(x1+i,y1+j);
            if( i == 0 || i == l-1 || j == 0 || j == w-1 )
            {
                color(col,0);
                printf("*");
            }
        }
    }
}

/*********************************************************************/
void triangle(int x1,int y1,int x2,int y2,int x3,int y3,int col)
{
    line(x1,y1,x2,y2,col);
    line(x2,y2,x3,y3,col);
    line(x3,y3,x1,y1,col);
}

/*******************************************************************/
void draw_line_frame()
{
    gotoxy(105,4);
    color(0,1);
    printf(" Line ");

    gotoxy(101,6);
    color(4,0);
    printf(" X_1 ");
    color(0,8);
    gotoxy(100,7);
    printf("   0   ");

    gotoxy(111,6);
    color(4,0);
    printf(" Y_1 ");
    color(0,8);
    gotoxy(110,7);
    printf("   0   ");

    gotoxy(101,8);
    color(4,0);
    printf(" X_2 ");
    color(0,8);
    gotoxy(100,9);
    printf("   0   ");

    gotoxy(111,8);
    color(4,0);
    printf(" Y_2 ");
    color(0,8);
    gotoxy(110,9);
    printf("   0   ");

    color(2,0);

}

/********************************************************/
void draw_square_frame()
{
    color(0,1);
    gotoxy(104,12);
    printf(" Square ");

    gotoxy(101,14);
    color(4,0);
    printf(" X_1 ");
    color(0,8);
    gotoxy(100,15);
    printf("   0   ");

    gotoxy(111,14);
    color(4,0);
    printf(" Y_1 ");
    color(0,8);
    gotoxy(110,15);
    printf("   0   ");

    gotoxy(106,16);
    color(4,0);
    printf("  L ");
    color(0,8);
    gotoxy(105,17);
    printf("   0   ");

    color(2,0);
}

/*************************************************/
void draw_rect_frame()
{
    color(0,1);
    gotoxy(103,20);
    printf(" Rectangle ");

    gotoxy(101,22);
    color(4,0);
    printf(" X_1 ");
    color(0,8);
    gotoxy(100,23);
    printf("   0   ");

    gotoxy(111,22);
    color(4,0);
    printf(" Y_1 ");
    color(0,8);
    gotoxy(110,23);
    printf("   0   ");

    gotoxy(101,24);
    color(4,0);
    printf("  L ");
    color(0,8);
    gotoxy(100,25);
    printf("   0   ");

    gotoxy(111,24);
    color(4,0);
    printf("  W ");
    color(0,8);
    gotoxy(110,25);
    printf("   0   ");

    color(2,0);
}

/****************************************************/
void draw_tri_frame()
{
    color(0,1);
    gotoxy(104,28);
    printf(" Triangle ");

    gotoxy(101,30);
    color(4,0);
    printf(" X_1 ");
    color(0,8);
    gotoxy(100,31);
    printf("   0   ");

    gotoxy(111,30);
    color(4,0);
    printf(" Y_1 ");
    color(0,8);
    gotoxy(110,31);
    printf("   0   ");

    gotoxy(101,32);
    color(4,0);
    printf(" X_2 ");
    color(0,8);
    gotoxy(100,33);
    printf("   0   ");

    gotoxy(111,32);
    color(4,0);
    printf(" Y_2 ");
    color(0,8);
    gotoxy(110,33);
    printf("   0   ");

    gotoxy(101,34);
    color(4,0);
    printf(" X_3 ");
    color(0,8);
    gotoxy(100,35);
    printf("   0   ");

    gotoxy(111,34);
    color(4,0);
    printf(" Y_3 ");
    color(0,8);
    gotoxy(110,35);
    printf("   0   ");

    color(2,0);
}
