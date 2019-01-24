//code by Vibhor Rawal dated: 20 August 2018
#include<iostream>
#include<string.h>

using namespace std;
class BankAccount
{
public:
	string name, type;
	int accountNo, withdrawal, balance,temp;

	void opbal()
	{
		cout<<"Enter Name :- ";
		cin.ignore(20,'\n');
		getline(cin,name);
		cout<<"Enter A/c no. :- ";
		cin>>accountNo;
		cout<<"Enter A/c Type :- ";
		cin>>type;
		cout<<"Enter Opening Balance :- ";
		cin>>balance;

	}
	
	void deposit()
	{
		cout<<"Enter Deposit amount :- ";
		cin>>temp;
		balance = balance + temp;
		cout<<"Deposit Balance :- "<<balance<<endl;

	}

	void withdraw()
	{
		cout<<"Balance amount:- "<<balance<<endl;
		cout<<"Enter Withdraw Amount :- ";
		cin>>withdrawal;
		balance = balance - withdrawal;
		cout<<"After Withdraw Balance is "<<balance<<endl;

	}

	void display()
	{
		cout<<"Name "<<name<<endl;
		cout<<"A/c. No "<<accountNo<<endl;
		cout<<"A/c Type "<<type<<endl;
		cout<<"Balance "<<balance<<endl;

	}
};

int main()
{
	
	int n,choice = 0;
	cout<<"enter how many records ";
	cin>>n;
	BankAccount bankAccount[n];

 	cout<<"\tcall to opbal member "<< n <<" times\n";

	for (int i = 0; i < n; ++i)
	{
		bankAccount[i].opbal();
		cout<<endl;
	}

	cout<<"call to display member function "<< n <<" times\n";
	cout<<"\t\"DETAILS\"\n";

	for (int i = 0; i < n; ++i)
	{
		bankAccount[i].display();
		cout<<endl;
	}

	return 0;
}