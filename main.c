/*
    Title : Simple Snakes Games
    project name: Snakes bikin ndiri
    Created by: Raindy Wicaksana H
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

#define ATAS 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

typedef struct
{
    int x;
    int y;
    int direction;
}coordinate;

char key;
coordinate food,head;

void gotoxy(int x,int y);
void board();
void summonfood();
void move();
void sleep(unsigned int mseconds);
void right();
void up();
void down();
void left();

int main()
{
    head.x =25;
    head.y = 10;
    head.direction=RIGHT;
    //gotoxy(head.x,head.y);printf(">");
    summonfood();
    board();
    move();

    puts("\n\n");
    //return 0;
}
void board()
{
    system("cls");
    int i;
    gotoxy(food.x,food.y);
    printf("F");
    for(i=5;i<=73;i++)
    {
        gotoxy(i,3);
        printf("!");
        gotoxy(i,19);
        printf("!");
    }
    for(i=3;i<=18;i++)
    {
        gotoxy(5,i);
        printf("!");
        gotoxy(73,i);
        printf("!");
    }
}

void summonfood()
{
    if(head.x == food.x && head.y == food.y)
    {
//        time_t a;
//        a=time(0);
//        srand(a);
        food.x = rand()%60;
        if(food.x<=5)
        {
            food.x+=11;
        }
        food.y = rand()%20;
        if(food.y<=5)
        {
            food.y+=11;
        }
    }
    else if(food.x==0) /// Kalo baru mulai
    {
        food.x = rand()%60;
        if(food.x<=5)
        {
            food.x+=11;
        }
        food.y = rand()%20;
        if(food.y<=5)
        {
            food.y+=11;
        }
    }

}
void move()
{
    do
    {
        summonfood();
        long double i;
        for(i=0;i<=(10900000);i++);
        board();
        if(head.direction == RIGHT)
        {
            right();
            //sleep(80);
            //system("cls");
        }
        else if(head.direction == LEFT)
        {
            left();
            //sleep(80);
            //system("cls");
        }
        else if(head.direction == ATAS)
        {
            up();
            //sleep(80);
            //system("cls");
        }
        else if(head.direction == DOWN)
        {
            down();
            //sleep(80);
            //system("cls");
        }
    }while(!kbhit());

    key=getch();
    head.direction= key;
    if(key == ATAS)
    {
        head.y--;
        move();
    }
    else if(key == DOWN)
    {
        head.y++;
        move();
    }
    else if(key == RIGHT)
    {
        head.x++;
        move();
    }
    else if(key == LEFT)
    {
        head.x--;
        move();
    }
    else if( key == 27)
    {
        exit(0);
    }
    else
    {
        move();
    }
}
void up()
{
    gotoxy(head.x,head.y);
    printf("O");
    if(!kbhit())
    {
        head.y--;
    }
}
void down()
{
    gotoxy(head.x,head.y);
    printf("O");
    if(!kbhit())
    {
        head.y++;
    }
}
void right()
{
    gotoxy(head.x,head.y);
    printf("O");
    if(!kbhit())
    {
        head.x++;
    }
}
void left()
{
    gotoxy(head.x,head.y);
    printf("O");
    if(!kbhit())
    {
        head.x--;
    }
}
void gotoxy(int x,int y)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(out,coord);
}
 void sleep(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

