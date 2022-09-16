#include<iostream>
#include<conio.h>
using namespace std;

bool gameOver;
const int width=20;
const int height=20;
int x,y,fruitX,fruitY,score;
enum eDirection{STOP=0,LEFT,RIGHT,UP,DOWN};
eDirection dir;

void setup()
{
	gameOver=false;
	dir=STOP;
	x=width/2;
	y=height/2;
	fruitX=rand()%width;
	fruitY=rand()%height;
	score=0;
}

void draw()
{	int i;
	system("cls");
	  for(i=0;i<width+2;i++)
		cout<<"#";
	  cout<<endl;

	  for(i=0;i<height;i++)
	  {
	    for(int j=0;j<width+2;j++)
	    {
		if(j==0)
		   cout<<"#";
		if(i==y && j==x)
		   cout<<"O";
		else if(i==fruitY && j==fruitX)
		       cout<<"F";
		else
			cout<<" ";
		if(j==width-1)
		  cout<<"#";
	    }
	  cout<<endl;
	  }
	for(i=0;i<width+2;i++)
	  cout<<"#";
	cout<<endl;
	cout<<"Score : "<<score<<endl;
	cout<<"To play use W A S D ";
}

void input()
{
	if(_kbhit())
	{
		switch(_getch())
		{
		   case 'a':
		   case 'A':
			dir = LEFT;
			break;
		   case 'd':
		   case 'D':
			dir = RIGHT;
			break;
		   case 'w':
		   case 'W':
			dir = UP;
			break;
		   case 's':
		   case 'S':
			dir = DOWN;
			break;
		   case 'x':
			gameOver=true;
			break;
		}
	}
}

void logic()
{	
	switch(dir)
	{
	 case LEFT:
		x--;
		break;
	 case RIGHT:
		x++;
		break;
	 case UP:
		y--;
		break;
	 case DOWN:
		y++;
		break;
	 default:
		break;
	 }
	 if(x>width||x<0||y>height||y<0)
		gameOver=true;
	 if(x==fruitX && y==fruitY)
	 {
		score+=10;
		fruitX=rand()%width;
		fruitY=rand()%height;
	 }
}

int main()
{
	setup();
	while(!gameOver)
	{
	  draw();
	  input();
	  logic();
	}
	cout<<"Game over";
	getch();

 return 0;
}
