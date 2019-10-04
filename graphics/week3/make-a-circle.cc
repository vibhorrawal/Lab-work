// circle at (60,70) of radius 50
#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;
int main(int argc, char const *argv[]){
  int gd = DETECT, gm;
  cout<<"Building a Circle "<<endl;
  initgraph(&gd, &gm, NULL);
  int x,y,r;
  cin>>x>>y>>r;
  circle(60,70,50);
  //added width of a circle as 10
  circle(60,70,50+10);
  fill(60+50+5,70);
  getch();
  return 0;
}
void circle(int x, int y, int r){
  int pk = 1 - r;
  int count = r * 0.707106781;
  int xk,yk;
  xk = 0;
  yk = r;
  while(count--){
    if(pk >= 0){
      xk = xk + 1;
      yk = yk - 1;
      pk = pk + 2 * xk + 1 - 2 * yk;
    }
    else{
      xk = xk + 1;
      yk = yk;
      pk = pk + 2 * xk + 1;
    }
    putpixel(xk + x, yk + y, WHITE);
    putpixel(-xk + x, yk + y, WHITE);
    putpixel(xk + x, -yk + y, WHITE);
    putpixel(-xk + x, -yk + y, WHITE);

    putpixel(yk + x, xk + y, WHITE);
    putpixel(-yk + x, xk + y, WHITE);
    putpixel(yk + x, -xk + y, WHITE);
    putpixel(-yk + x, -xk + y, WHITE);


  }
  putpixel(x,y,WHITE);
}

//for filling the width of circle 
void fill(int x,int y)
{
  if(getpixel(x,y) == BLACK )
  {
    putpixel(x,y,RED);
    fill(x+1,y);
    fill(x-1,y);
    fill(x,y+1);
    fill(x,y-1);
  }
  delay(50);
}