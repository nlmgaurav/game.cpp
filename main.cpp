#include <iostream>
#include<conio.h>
#include<windows.h>
using namespace std;
bool gameover;
const int width=20;
const int height=20;
int x,y,fruitx,fruity,score;
int tailX[100],tailY[100];
int nTail;
enum eDirection {STOP=0,LEFT,RIGHT,UP,DOWN};
eDirection dir;
void Setup()
{
   gameover=false;
   dir=STOP;
   x=width/2;
   y=height/2;
   fruitx=rand()%width;
   fruity=rand()%height;
   score=0;
}
void Draw()
{
  system("cls");
  for(int i=0;i<width+2;i++)
    cout<< "#";
  cout<< endl;
  for(int i=0;i<height;i++)
  {
      for(int j=0;j<width;j++)
      {
          if(j==0)
            cout<< "#";
            if(i==y && j==x)
                cout<<"O";
            else if(i==fruity && j==fruitx)
                cout<<"F";
          else
          {
               bool print=false;
              for(int k=0;k<nTail;k++)
              {
                  if(tailX[k]==j && tailY[k]==i)
                  {
                      cout<<"O";
                      print =true;
                  }
              }
               if(!print)
                    cout<<" ";
          }

          if(j==width-1)
            cout<< "#";
      }
      cout<<endl;
  }
  for(int i=0;i<width+2;i++)
    cout<< "#";
    cout<< endl;
    cout<<"score:"<<score<<endl;
}

void Input()
{
if(_kbhit())
{
  switch(_getch())
  {
   case'a':
       dir=LEFT;
       break;
       case's':
       dir=RIGHT;
       break;
       case'd':
       dir=UP;
       break;
       case'f':
       dir=DOWN;
       break;
       case'g':
        gameover=true;
        break;
  }
}
}
void Logic()
{ int prevX=tailX[0];
int prevY=tailY[0];
int prev2X,prev2Y;
tailX[0]=x;
tailY[0]=y;
for(int i=1;i<nTail;i++)
{
    prev2X=tailX[i];
    prev2Y=tailY[i];
    tailX[i]=prevX;
    tailY[i]=prevY;
    prevX=prev2X;
    prevY=prev2Y;
}

switch(dir)
{
  case LEFT:
      x--;
      break;
  case RIGHT:
    x++;
  case UP:
    y--;
    break;
  case DOWN:
    y++;
    break;
  default:
    break;
}
//if(x>width || x<0 || y>height ||y<0)
   // gameover=true;
    if(x>=width) x=0;else if (x<0) x=width-1;
     if(y>=height) y=0;else if (y<0) y=height-1;

    for(int i=0;i<nTail;i++)
        if(tailX[i]==x && tailY[i]==y)
        gameover=true;
if(x==fruitx && y==fruity)
{
    score+=10;
    fruitx=rand()%width;
   fruity=rand()%height;
   nTail++;
}
}

int main()
{
Setup();
while(!gameover)
{
    Draw();
    Input();
    Logic();
    Sleep(60);

}
    return 0;
}
