#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

const int INSIDE = 0; // 0000
const int LEFT = 1;   // 0001
const int RIGHT = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8;    // 1000

int x_max,y_max,x_min,y_min;
void clip(double x1, double y1, double x2, double y2);
int main(){
  int gd = DETECT, gm;
  cout<<"Creating cohen-sutherland-algorithm..."<<endl;
  x_max = 100;
  x_min = 40;
  y_max = 80;
  y_min = 40;
  initgraph(&gd, &gm, NULL);

  line(x_min,y_min,x_min,y_max);
  line(x_max,y_min,x_max,y_max);
  line(x_min,y_min,x_max,y_min);
  line(x_min,y_max,x_max,y_max);

  clip(50,50,70,70);
  clip(70,90,110,40);
  clip(10,50,40,10);
  getch();
  closegraph();
}
int computeCode(double x, double y){
  int code = INSIDE;

  if(x < x_min) code |= LEFT;
  else if(x > x_max) code |= RIGHT;

  if(y < y_min) code |= BOTTOM;
  else if(y > y_max) code |= TOP;

  return code;
}
void clip(double x1, double y1, double x2, double y2){

  int check1 = computeCode(x1, y1);
  int check2 = computeCode(x2, y2);

  bool accept = false;

  while (1) {
    if(check1 == INSIDE && check2 == INSIDE){
      accept = true;
      break;
    }
    else if(check1 & check2){
      break;
    }
    else{
      int check_out;
      double x,y;

      if(check2) check_out = check2;
      else check_out = check1;

      // Find intersection point;
      // using formulas y = y1 + slope * (x - x1),
      // x = x1 + (1 / slope) * (y - y1)
      if (check_out & TOP)
      {
          // point is above the clip rectangle
          x = x1 + (x2 - x1) * (y_max - y1) / (y2 - y1);
          y = y_max;
      }
      else if (check_out & BOTTOM)
      {
          // point is below the rectangle
          x = x1 + (x2 - x1) * (y_min - y1) / (y2 - y1);
          y = y_min;
      }
      else if (check_out & RIGHT)
      {
          // point is to the right of rectangle
          y = y1 + (y2 - y1) * (x_max - x1) / (x2 - x1);
          x = x_max;
      }
      else if (check_out & LEFT)
      {
          // point is to the left of rectangle
          y = y1 + (y2 - y1) * (x_min - x1) / (x2 - x1);
          x = x_min;
      }

      if(check_out == check1){
        x1 = x;
        y1 = y;
        check1 = computeCode(x1,y1);
      }
      else{
        x2 = x;
        y2 = y;
        check2 = computeCode(x2,y2);
      }

    }
  }
    if (accept)
{
    cout <<"Line accepted from " << x1 << ", "
         << y1 << " to "<< x2 << ", " << y2 << endl;
         line(x1,y1,x2,y2);
}
else
    cout << "Line rejected ("<<x1<<", "<<y1<<") to ("<<x2<<", "<<y2<<")" << endl;

}
