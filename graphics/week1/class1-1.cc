// calculate no of traingles with given point trying through NCR -- incomplete
#include<iostream>
using namespace std;
struct Point{
  int x, y;
};
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
  int ans = ncr(n,3);
  int r = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      for (int k = j+1; k < n; k++) {
        if(slope(arr, i, j, k))
        r++;
      }
      ans =- ncr(r,3);
    }
  }
  return ans;
}
