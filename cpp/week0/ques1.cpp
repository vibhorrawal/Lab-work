//author:Vibhor Rawal
#include<iostream>
using namespace std;
class Students
{
    public:
    char name[20];
    int age,rollNo;
};
int main()
{
    int n;
    cout<<"Enter number of students: ";
    cin>>n;
    Students student[n];

    for(int i = 0; i<n; i++)
    {
        cin.ignore();
        cout<<"\n For student "<<i+1<<" :"<<endl;
        cout<<"Enter name: ";
        cin.getline(student[i].name, 20);
        cout<<"Enter age: ";
        cin>>student[i].age;
        cout<<"Enter roll number: ";
        cin>>student[i].rollNo;
    }

    cout<<"\nData Stored:\n\n";

    for(int i = 0; i<n; i++)
    {
        cout<<"Name: "<<student[i].name<<endl;
        cout<<"Age: "<<student[i].age<<endl;
        cout<<"Roll number: "<<student[i].rollNo<<endl<<endl;        
    }

    return 0;
}