#include<bits/stdc++.h>
using namespace std;

class Point
{
public:
	int x,y;
};

inline float min(float a, float b){ return (a > b)? a : b; }
inline float dist(Point p1, Point p2){ return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y)); }
int compareX(const void* a, const void* b)
{
	Point *p1 = (Point*)a, *p2 = (Point*)b;
	return p1->x - p2->x;
}
int compareY(const void* a, const void* b)
{
	Point *p1 = (Point*)a, *p2 = (Point*)b;
	return p1->y - p2->y;
}
float bruteForce(Point p[], int n)
{
	float min = FLT_MAX;
	for (int i = 0; i < n; ++i)
		for(int j = i+1; j < n; ++j){
			if(dist(p[i],p[j]) < min)
				min = dist(p[i],p[j]);
		}
}
float stripClosest(Point strip[], int size, float d)
{
	qsort(strip,size,sizeof(Point), compareY);

	for (int i = 0; i < size; ++i)
		for(int j =  i+1; j < size && (strip[j].y - strip[i].y < d); j++)
			if(dist(strip[i],strip[j]) < d)
				d = dist(strip[i],strip[j]);

	return d;		
}
float closest(Point p[], int n)
{
	if(n < 4) return bruteForce(p,n);

	qsort(p,n,sizeof(Point),compareX);
	int mid = n/2;

	float dl = closest(p,mid);
	float dr = closest(p + mid,n - mid);
	float d = min(dl,dr);

	Point strip[n];
	int j = 0;
	for (int i = 0; i < n; ++i)
		if(abs(p[i].x - p[mid].x) < d)
			strip[j++] = p[i];

	return min(d, stripClosest(p,j,d));	
}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	Point p[n];
	for (int i = 0; i < n; ++i)
		cin>>p[i].x>>p[i].y;

	cout<<"Closst Distance is "<<closest(p,n)<<endl;
	return 0;
}
