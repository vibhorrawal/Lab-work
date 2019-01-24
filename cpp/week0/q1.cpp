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
		cout<<"\"DETAILS\""<<endl;
		cout<<"Name "<<name<<endl;
		cout<<"A/c. No "<<accountNo<<endl;
		cout<<"A/c Type "<<type<<endl;
		cout<<"Balance "<<balance<<endl;

	}
};

int main()
{
	BankAccount bankAccount;
	int choice = 0;
 	cout<<"Choice List\n1) To assign Initial Value\n2) To Deposit\n3) To Withdraw\n4) To Display All Details\n5) EXIT\n";

	while(choice != 5)
	{
		cout<<"\n\tEnter your choice :- ";
		cin>>choice;

		switch(choice)
		{
			case 1:
			bankAccount.opbal();
			break;

			case 2:
			bankAccount.deposit();
			break;

			case 3:
			bankAccount.withdraw();
			break;

			case 4:
			bankAccount.display();
			break;


		}
	}
	cout<<"Exit from programme control";

	return 0;
}