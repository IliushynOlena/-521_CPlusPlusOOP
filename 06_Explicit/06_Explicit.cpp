#include <iostream>
using namespace std;

void doSomething(long number) {}

float doSomething()
{
	return 10.0;//double
}
class Array
{
	int* arr;//-825669978
	int size;//-825669978
public:
	Array()
	{
		size = 0;
		arr = nullptr;
	}
	//explicit - забороняє неявне перетвореня від одного типу даних до іншого
	explicit Array(int size)//constructor parametrized
	{
		this->size = size;
		arr = new int[size];
	}
	void setValue(int value, int index)
	{
		arr[index] = value;
	}
	int getValue(int index)const
	{
		return arr[index];
	}
	int getSize()const
	{
		return size;
	}
	void display(int index)const
	{
		cout << arr[index] << " ";
	}
	~Array()
	{
		if (arr != nullptr)
			delete[]arr;
	}
};

void Display(const Array& arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		arr.display(i);
	}

}
class Student
{
	string name;
	int age;
public:
	explicit Student(int age)
	{
		name = "no name";
		this->age = age;

	}
	Student(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
	void Print()
	{
		cout << name << " " << age << endl;
	}

};
void Show(Student s)
{
	//code....
	s.Print();
}
int main()
{
	Array arr5;//100
	Student s(12);
	Show(s);
	Student s1("Ivan", 22);
	Show(s1);
	//Show(100);//implicit int ---> Studnet

	int size = 5;
	Array arr(size);//constrcutor
	for (int i = 0; i < arr.getSize(); i++)
	{
		arr.setValue(size - i, i);
	}
	Display(arr);
	cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
	//Display(3);// 3 === Array implicit error

	//Array arr2 = 10;
	//Display(arr2);



	//implicit  explicit

	//double a(10);//int ----> double  implicit  10.0000000000000000
	//doSomething(5);//int ----> long  implicit
	//float c = doSomething();//double ----> float implicit
	//double d = 5.0 / 4;
	//cout << d << endl;
	//int g = 9.8;//double ---> int implicit
	//cout << g << endl;

}

