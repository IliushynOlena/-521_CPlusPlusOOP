#include <iostream>

using namespace std;

inline void hello()
{
	cout << "Hello world" << endl;
}
//Delegation  
class Human
{
	//private - інкапсуляція
	string name;
	int age;
	int weight;
	static int count;//змінна одна для всіх
public:
	static int getCount()
	{
		//this - don*t have this
		return count;
	}

	//Human()//default constructor
	//{
	//	name = "no name";
	//	age = 0;
	//	weight = 0;
	//}
	//Human() : name("no name"), age(0), weight(0) {}
	Human() : name{ "no name" }, age{ 0 }, weight{ 0 } { count++; }//список ініціалізаторів	
	Human(string name) : Human()//parametrized constructor with 1 parameter
	{
		this->name = name;
		//age = 0;
		//weight = 0;
	}
	Human(string name, int age): Human(name)//parametrized constructor with 2 parameter
	{
		//this->name = name;
		this->age = age;
		//weight = 0;
	}
	Human(string name, int age, int weight):Human(name,age)//parametrized constructor with 3 parameter
	{
		//this->name = name;
		//this->age = age;
		this->weight = weight;
	}
	//Human(int age)//parametrized constructor with 1 parameter
	//{
	//	name = "no name";
	//	this->age = age;
	//	weight = 0;
	//}
	//Human(int weight)//parametrized constructor with 1 parameter
	//{
	//	name = "no name";
	//	age = 0;
	//	this->weight = weight;
	//}
	////Human(string name, int weight)//parametrized constructor with 2 parameter
	////{
	////	this->name = name;
	////	this->age = 0;
	////	this->weight = weight;
	////}
	//Human( int age, int weight)//parametrized constructor with 2 parameter
	//{
	//	this->name = "no name";
	//	this->age = age;
	//	this->weight = weight;
	//}
	void Print()const
	{

		cout << "Name : " << name << endl;
		cout << "Age : " << age << endl;
		cout << "Weight : " << weight << endl;
	}
	~Human()
	{
		count--;
	}
};

int Human::count = 0;
int main()
{
	//cout << hello << endl;
	//cout << "Hello world" << endl;//hello();

	cout << "Count : " << Human::getCount() << endl;


	Human h;//default constructor
	h.Print();

	cout << "Count : " << Human::getCount() << endl;
	cout << "Count : " << h.getCount() << endl;

	Human h2("Oleg");
	h2.Print();

	Human h3("Ira", 15);
	h3.Print();
	cout << "Count : " << Human::getCount() << endl;
	cout << "Count : " << h.getCount() << endl;
	cout << "Count : " << h2.getCount() << endl;

	if (true)
	{
		Human h4("Vova", 25, 97);
		h4.Print();

	}
	//Human::count = 0;
	
	cout << "Count : " << h.getCount() << endl;
	cout << "Count : " << h2.getCount() << endl;
	cout << "Count : " << h3.getCount() << endl;



}

