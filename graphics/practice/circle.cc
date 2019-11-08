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
  // cin>>x>>y>>r;
  circle(60,70,50);
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
  putpixel(x,y,RED);

  putpixel(x,y+r,WHITE);
  putpixel(x,y-r,WHITE);
  putpixel(x+r,y,WHITE);
  putpixel(x-r,y,WHITE);
}

// void circle(int x_centre, int y_centre, int r, int color){
//   int x = r, y = 0;
//   putpixel(x+x_centre, y+y_centre, color);
//   putpixel(x+x_centre, -y+y_centre, color);
//   putpixel(y+x_centre, x+y_centre, color);
//   putpixel(-y+x_centre, x+y_centre, color);
//
//   int P = 1 - r;
//   while(x>y){
//     y++;
//     if (P < 0) P += 2*y + 1;
//     else x--, P =+ 2*y - 2*x + 1;
//
//     if(x<y) break;
//
//     putpixel(x+x_centre, y+y_centre, color);
//     putpixel(-x+x_centre, y+y_centre, color);
//     putpixel(x+x_centre, -y+y_centre, color);
//     putpixel(-x+x_centre, -y+y_centre, color);
//
//     if(x != y) // not on y=x line as already printed
//     {
//       putpixel(y+x_centre, x+y_centre, color);
//       putpixel(-y+x_centre, x+y_centre, color);
//       putpixel(y+x_centre, -x+y_centre, color);
//       putpixel(-y+x_centre, -x+y_centre, color);
//     }
//   }
//   putpixel(x_centre, y_centre, RED);
// }
