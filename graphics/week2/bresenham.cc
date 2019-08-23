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
  int x = x1, y = y1;
  int delX = abs(x2 - x1), delY = abs(y2 - y1);
  int p = 2 * delY - delX;
  int count = max(abs(x2 - x1), abs(y2 - y1));

  while(count--){
    if(p<0){
       putpixel(++x, y, WHITE);
       p = 2 * delY + p;
     }
    else {
      putpixel(++x, ++y, WHITE);
      p = 2 * delY - 2 * delX + p;
    }

  }
}
