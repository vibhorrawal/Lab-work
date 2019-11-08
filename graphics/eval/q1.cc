#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;
void earth_moon(int x, int y, int r);
void sphere(int x_centre, int y_centre, int r, int color);
void midpoint_ellipse_algorithm(int x, int y, int rx, int ry);
void move_earth(int x, int y, int rx, int ry,int cc);
int M=7;
int main(int argc, char const *argv[]){
  int gd = DETECT, gm;
  initgraph(&gd, &gm, NULL);

  sphere(250,250,50,YELLOW); // SUN
  midpoint_ellipse_algorithm(250,250,200,150); // for plotting path of earth
  // move_earth(200,200,200,150);
  // for (int i = 0; i < 100; i+=10) {
  //   earth_moon(100+i,100+i,10);
  //
  // }
  // earth_moon(450,250,20);
  for (int i = 0; i < M; i++) {
    move_earth(250,250,200,150,20*i); // to put few frames in animation
  }
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
void plot_points(int x, int y, int x_centre, int y_centre, int color)
{
    putpixel(x + x_centre ,-y + y_centre,color);
    putpixel(y + x_centre ,x + y_centre,color);
    putpixel(-y + x_centre ,x + y_centre,color);

    putpixel(x + x_centre,y + y_centre,color);
    putpixel(-x + x_centre,y + y_centre,color);
    putpixel(x + x_centre,-y + y_centre,color);
    putpixel(-x + x_centre,-y + y_centre,color);

    putpixel(y + x_centre, x + y_centre,color);
    putpixel(-y + x_centre, x + y_centre,color);
    putpixel(y + x_centre, -x + y_centre,color);
    putpixel(-y + x_centre, -x + y_centre,color);
}

void sphere(int x_centre, int y_centre, int r, int color)
{
    //First Point
    int x = 0, y = r;
    putpixel(x + x_centre, y + y_centre,color);
    putpixel(y + y_centre, x + x_centre,color);
    putpixel(x + x_centre, -y + y_centre,color);
    putpixel(-y + y_centre, x + x_centre,color);
    int p = 1 - r;
    while(x++ <= y)
    {
        if(p < 0)
        {
            plot_points(x, y, x_centre, y_centre, color);
            p += 2*x + 1;
        }
        else
        {
            y--;
            plot_points(x, y, x_centre, y_centre, color);
            p += 2*x + 1 - 2*y;
        }
    }

    for(float phi = -1.57; phi<=0; phi += 0.1)
    {
        for(float theta = -3.14; theta<=3.14; theta += 0.2)
        {
            x = r * cos(phi) * cos(theta);
            y = r * cos(phi) * sin(theta);
            plot_points(0, y, x_centre, y_centre, color);
            p = 1 - r;
            while(x++ <= y)
            {
                if (p < 0)
                {
                    p += 2*x + 1;
                    plot_points(x, y, x_centre, y_centre, color);
                }
                else
                {
                    y--;
                    p += 2*x + 1 - 2*y;
                    plot_points(x, y, x_centre, y_centre, color);
                }
            }
        }
    }
}

int COUNT=0;
//this function is called to revolve moon around earth
void circlemoon(int x, int y, int r, int cc){
  int CM = -1;
  cout << "circle moon called" << endl;
  // COUNT += 10;
  int pk = 1 - r;
  int count = r * 0.707106781;
  int xk,yk;
  xk = 0;
  yk = r;
  while(count--){
    CM++;
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
    // putpixel(xk + x, yk + y, WHITE);
    // putpixel(-xk + x, yk + y, WHITE);
    // putpixel(xk + x, -yk + y, WHITE);
    // putpixel(-xk + x, -yk + y, WHITE);
    //
    // putpixel(yk + x, xk + y, WHITE);
    // putpixel(-yk + x, xk + y, WHITE);
    // putpixel(yk + x, -xk + y, WHITE);
    // putpixel(-yk + x, -xk + y, WHITE);
    // if(CM==cc*5) {sphere(xk+x,yk+y,4,WHITE); return;}

  }
  xk=yk=0;
  // printing 1 moon per fn call
    if(COUNT%4==0) sphere(xk+x+r,yk+y,4,WHITE);
    if(COUNT%4==1) sphere(xk+x,yk+y+r,4,WHITE);
    if(COUNT%4==2) sphere(xk+x-r,yk+y,4,WHITE);
    if(COUNT%4==2) sphere(xk+x,yk+y-r,4,WHITE);

  // }
  // putpixel(x,y,WHITE);
  //
  // putpixel(x,y+r,WHITE);
  // putpixel(x,y-r,WHITE);
  // putpixel(x+r,y,WHITE);
  // putpixel(x-r,y,WHITE);
  COUNT++;
}
// this function places earth with moon with centre x,y and rad r
int COUNTP=0;
void earth_moon(int x, int y, int r){
  sphere(x,y,r, BLUE);
  circle(x,y,r+30);
  circlemoon(x,y,r+30,COUNTP++);
}
// this function animates the earth
int MOVE=0;
int C = -1;
void move_earth(int x, int y, int rx, int ry,int cc){
  C = -1;
  cout << "move_earth called" << endl;
  // C++;

  //earth rad = 10
  // int c = -1;
  int _x = 0, _y = ry;
  int p1 = ry * ry - rx * rx * ry + rx * rx / 4.0;
  int px = 0, py = 2 * rx * rx * ry;
  while(px < py){
    C++;
    // cout<<"X,Y = "<<_x<<", "<<_y<<endl;
    // plot_ellipse_pixel(_x, _y, x, y);
    if(cc == C){ earth_moon(_x+x, _y+y, 20); return;} //print 1 earth per function call
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
    if(cc == C){ earth_moon(_x, _y, 10); return;}

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
