// calculate no of triangles with given points using area non zero
#include<iostream>
using namespace std;
struct Point{
  int x, y;
};
float area(Point arr[], int i, int j, int k);
int calculateNonZeroArea(Point arr[], int n);
int main(int argc, char const *argv[]){
  int n;
  cin>>n;
  Point points[n];
  for (int i = 0; i < n; i++) {
    cin>>points[i].x>>points[i].y;
  }
  cout<<calculateNonZeroArea(points, n);
  return 0;
}

int calculateNonZeroArea(Point arr[], int n){
  int count = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      for (int k = j+1; k < n; k++) {
        if(area(arr, i, j, k) != 0)
        count++;
      }
    }
  }

  return count;
}

float area(Point arr[], int i, int j, int k){
  if (i == j || i == k || j == k) return 0;

  float ar = arr[i].x * (arr[j].y - arr[k].y) - arr[j].x * (arr[i].y - arr[k].y)
              + arr[k].x * (arr[i].y - arr[j].y);

  return ar;
}
