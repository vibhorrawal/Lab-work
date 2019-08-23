#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;
void drawLine(int x1, int y1, int x2, int y2);
int main(int argc, char const *argv[]){
  int gd = DETECT, gm;
  cout<<"Building a line, input x1,y1,x2,y2: "<<endl;
  initgraph(&gd, &gm, NULL);
  int x1,y1,x2,y2;
  cin>>x1>>y1>>x2>>y2;
  // x1 = 1,x2 = 0, y1 = 3, y2 = 4;
  putpixel(x1,y1,RED);
  putpixel(x2,y2,RED);
  drawLine(x1,y1,x2,y2);
  getch();
  return 0;
}
void drawLine(int x1, int y1, int x2, int y2){
  float m = (y2-y1)/(x2-x1);
  float x = x1,y = y1;
  long long int count;
  bool flag = 0;
  if(abs(x2 - x1) > abs(y2 - y1)){
    flag = 1;
    count = (x2 - x1);
  }
  else{
    count = (y2 - y1);
  }
  if(flag){
    if(count>0)
    while(count--){
      x = x + 1;
      y = y + m;
      putpixel(floor(x),floor(y), WHITE);
    }
    else
    while(count++){
      x = x - 1;
      y = y - m;
      putpixel(floor(x),floor(y), WHITE);
    }
  }
  else{
    if(count>0)
    while(count--){
      x = x + 1/m;
      y = y + 1;
      putpixel(floor(x),floor(y), WHITE);
    }
    else
    while(count++){
      x = x - 1/m;
      y = y - 1;
      putpixel(floor(x),floor(y), WHITE);
    }
  }
  // while(x != x2, y != y2){
  // if(m > 1){
  //   x = x + 1/m;
  //   y = y + 1;
  //   putpixel(floor(x),floor(y), WHITE);
  // }
  // else{
  //   x = x + 1;
  //   y = y + m;
  //   putpixel(floor(x),floor(y), WHITE);
  // }
  // }
}
