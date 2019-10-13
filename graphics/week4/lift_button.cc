// circle at (60,70) of radius 50
#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;
void midpoint_ellipse_algorithm(int x, int y, int rx, int ry);
int main(int argc, char const *argv[]){
  int gd = DETECT, gm;
  cout<<"Building a Circle "<<endl;
  initgraph(&gd, &gm, NULL);
  // int x,y,r;
  // cin>>x>>y>>r;
  midpoint_ellipse_algorithm(160,170,50,40);
  getch();
  return 0;
}
void plot_ellipse_pixel(int x, int y, int xc, int yc){
  putpixel(xc - x, yc - y, WHITE);
  putpixel(xc - x, yc + y, WHITE);
  putpixel(xc + x, yc - y, WHITE);
  putpixel(xc + x, yc + y, WHITE);

}

void midpoint_ellipse_algorithm(int x, int y, int rx, int ry){
    int _x = 0, _y = ry;
    int p1 = ry * ry - rx * rx * ry + rx * rx / 4;

    while(2 * ry * ry * _x < 2 * rx * rx * _y){
      cout<<"X,Y = "<<_x<<", "<<_y<<endl;
      plot_ellipse_pixel(_x, _y, x, y);

      if(p1 < 0){
        _x = _x + 1;
        _y = _y;
        p1 = p1 + 2 * ry * ry * _x + ry * ry;
      }
      else{
        _x = _x + 1;
        _y = _y - 1;
        p1 = p1 + 2 * ry * ry * _x - 2 * rx * rx + ry * ry;
      }
    }

    //
    // int p2 = ry * ry * (_x + 0.5) * (_x + 0.5) + rx * rx * (_y - 1) * (_y - 1)
    //           - rx * rx * ry * ry;
    // while(2 * ry * ry * _x >= 2 * rx * rx * _y){
    //   cout<<"X,Y = "<<_x<<", "<<_y<<endl;
    //   if(p2 > 0){
    //     p2 = p2 - 2 * rx * rx * _y + rx * rx;
    //     _x = _x;
    //     _y = _y - 1;
    //   }
    //   else{
    //     p2 = p2 + 2 * ry * ry * _x - 2 * rx *rx  + rx * rx;
    //     _x = _x + 1;
    //     _y = _y - 1;
    //   }
    // plot_ellipse_pixel(_x, _y, x, y);
    // }
}
