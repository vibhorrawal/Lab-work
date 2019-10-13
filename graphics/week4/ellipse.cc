// circle at (60,70) of radius 50
#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;
void midpoint_ellipse_algorithm(int x, int y, int rx, int ry);
void floodfill(int x, int y){
  int color = getpixel(x,y);

  putpixel(x,y,RED);
  if(color)
    return;
  floodfill(x+1,y);
  floodfill(x,y+1);
  floodfill(x-1,y);
  floodfill(x,y-1);
}
int main(int argc, char const *argv[]){
  int gd = DETECT, gm;
  cout<<"Building an ellipse "<<endl;
  initgraph(&gd, &gm, NULL);
  // int x,y,r;
  // cin>>x>>y>>r;
  midpoint_ellipse_algorithm(260,200,40,70);
  midpoint_ellipse_algorithm(260,200,70,100);
  floodfill(260+0,200+71);
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
    int p1 = ry * ry - rx * rx * ry + rx * rx / 4.0;
    int px = 0, py = 2 * rx * rx * ry;
    while(px < py){
      // cout<<"X,Y = "<<_x<<", "<<_y<<endl;
      plot_ellipse_pixel(_x, _y, x, y);
      _x++;
      px += 2 * ry * ry;
      if(p1 < 0){
        // _x++;
        // _y = _y;
        p1 += ry * ry + px;
      }
      else{
        // _x++;
        _y--;
        py -= 2 * rx * rx;
        p1 += ry * ry + px - py;
      }
      // plot_ellipse_pixel(_x, _y, x, y);

    }
    plot_ellipse_pixel(_x, _y, x, y);


    int p2 = ry * ry * (_x + 0.5) * (_x + 0.5) + rx * rx * (_y - 1) * (_y - 1)
              - rx * rx * ry * ry;
    while(_y > 0){
      // cout<<"X,Y = "<<_x<<", "<<_y<<endl;
      _y--;
      py -= 2 * rx * rx;
      if(p2 > 0){
        p2 += rx *rx - py;
        // _x = _x;
        // _y = _y - 1;
      }
      else{
        _x++;
        px += 2 * ry * ry;
        p2 += rx * rx + px -py;
        // _x = _x + 1;
        // _y = _y - 1;
      }
    plot_ellipse_pixel(_x, _y, x, y);
    }
}
