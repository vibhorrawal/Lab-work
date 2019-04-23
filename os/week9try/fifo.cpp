#include<bits/stdc++.h>
using namespace std;
class Frame
{
	int count = -1;
	int n;
	int *frame;
	int index(int m);
public:
	Frame(int n);
	int push(int m);
	void display();	
};

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	Frame f(n);
	int x;
	int hit = 0, miss = 0;
	while(1){
		cin>>x;
		if(x == -1) break;

		if(f.push(x) == -1)
			miss++;
		else
			hit++;
		f.display();
	}
	cout<<"Hits = "<<hit<<endl;
	cout<<"Miss = "<<miss<<endl;
	return 0;
}

int Frame::push(int m)
{
	if(index(m) != -1)
		return index(m);
	count = (count + 1) % n;
	frame[count] = m;
	return -1;
}
int Frame:: index(int m)
{
	for (int i = 0; i < n; ++i)
	{
		if(frame[i] == m)
			return i;
	}
	return -1;
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