#include<bits/stdc++.h>
using namespace std;
class Frame
{
	int n;
	int *frame;
	int recent_index(int value, int current);
	void push(int val, int x);
	bool find(int m);
public:
	Frame(int n);
	void display();
	int *reference;
	int size;	
	void load(int *reference, int size);
	int miss = 0;
	int hit = 0;
};
int main(int argc, char const *argv[])
{
	int reference[] = {7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
	int size = 20;
	Frame f(4);
	f.load(reference, size);
	cout<<"hits"<<f.hit;
	cout<<endl<<"miss"<<f.miss<<endl;
	return 0;
}
Frame::Frame(int n)
{
	frame = new int[n];
	this->n = n;
	for (int i = 0; i < n; ++i)
	{
		frame[i] = INT_MAX;
	}
}
void Frame::display(){
	cout<<"Frame:";
	for (int i = 0; i < n; ++i)
	{
		if(frame[i] == INT_MAX)
			cout<<" X";
		else
			cout<<" "<<frame[i];
	}
	cout<<endl;
}
void Frame::load(int *reference, int size){
	this->reference = reference;
	this->size = size;
	for (int i = 0; i < size; ++i)
	{
		if(!find(reference[i])){
			push(reference[i],i);
			miss++;
		}
		else
			hit++;
		display();
	}
}
bool Frame::find(int m){
	for (int i = 0; i < n; ++i)
	{
		if(m == frame[i])
			return true;
	}
	return false;
}
void Frame::push(int val, int x){
	int block[n];
	
	for (int i = 0; i < n; ++i)
		if(frame[i] == INT_MAX){
			frame[i] = val;
			return;
		}

	int index = 0, min = INT_MAX;
	for (int i = 0; i < n; ++i)
		block[i] = recent_index(frame[i],x);
	
	
	for (int i = 0; i < n; ++i)
		if(block[i] < min)
			min = block[i], index = i;
	
	frame[index] = val;
}
int Frame::recent_index(int value, int current){
	for (int i = current-1; i >= 0; i--)
	{
		if(value == reference[i])
			return i;
	}
}