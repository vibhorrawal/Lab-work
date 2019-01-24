#include <iostream>
using namespace std;

class test
{
	int num;
public:
	void getNum();
	void showNum(){
		cout<<"The value of obj1 is "<<num<<endl;
	}
	friend void show(test);
};

void test:: getNum()
{
	cin>>num;
}

void show(test obj2)
{
	obj2.num = 20;
	cout<<"The value of obj2 is "<<obj2.num<<endl;

}

int main()
{
	test obj1;
	obj1.getNum();
	obj1.showNum();

	show(obj1);
	//obj1.showNum();

	return 0;
}