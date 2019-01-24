// first funtion with objects
#include <iostream>
using namespace std;

class Metazoa
{
	public :
	int eye;
	int leg;
	int arm;
	char brain;
	bool isMulticellular;
	bool living;
	char sex;
	int age;
	int biomass;


	void matabolise(){
		cout<<"Has Metabolism\n";
	}

	void status()
	{
		if( living == true)
			cout<<"Currently Living\n";
		else
			cout<<"Currently Extinct\n";
	}

	void homePlanet()
	{
		cout<<"Earth\n";
	}

	void structure()
	{
		if(isMulticellular == true)
			cout<<"Multicellular\n";
		else
			cout<<"Unicellular\n";
	}

	void presentAge()
	{
		cout<<"Present age is "<<age;
	}
    
    int limbs()
    {
    	return leg + arm;
    }


};


int main()
{
	Metazoa human,starfish,ameoba;

	human.eye = 2;
	human.leg = 2;
	human.arm = 2;
	human.brain = 'y';
	human.isMulticellular = true;
	human.living = true;
	human.age = 200000;

	human.limbs();
	human.structure();
	human.homePlanet();
	human.status();



}