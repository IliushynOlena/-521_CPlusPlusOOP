#include <iostream>

using namespace std;
struct Point
{
    int x;
    int y;
};
class Student//Incapsulation
{
private:
	string name;
	int age;
	int* marks;//nullptr
	int markCount;//0
public:

	Student()//default constrcutor
	{
		cout << "Default Constructor" << endl;
		name = "no name";
		age = 0;
		marks = nullptr;
		markCount = 0;
	}
	Student(string n, int a)//parametrized constrcutor
	{
		cout << "Parametrized Constructor" << endl;
		this->name = n;
		this->age = a;
		
		marks = nullptr;
		markCount = 0;
	}
	Student(const Student &original)
	{
		cout << "Copy constryctor" << endl;
		this->name = original.name;//Mark == Mark
		this->age = original.age;//16 == 16
		this->markCount = original.markCount;//6  == 6
		//this->marks = original.marks;//0x147   == 0x147
		this->marks = new int[original.markCount];
		for (int i = 0; i < markCount; i++)
		{
			this->marks[i] = original.marks[i];//12  == 12
		}
	/*	int num = 3;
		for (size_t i = 0; i < markCount; i++)
		{
			if (marks[i] != num)
				temp[i] = marks[i];
		}*/
	}
	void Print()
	{
		cout << "name : " << name << " " << endl;
		cout << "age : " << age << " " << endl;
		for (int i = 0; i < markCount; i++)
		{
			cout << marks[i] << " ";
		}
		cout << endl;
	}
	void AddMark(int mark)
	{
		markCount++;
		int* temp = new int[markCount];//6
		for (int i = 0; i < markCount - 1; i++)
		{
			temp[i] = marks[i];
		}
		temp[markCount - 1] = mark;
		if (marks != nullptr)
			delete[]marks;
		marks = temp;
	}
	//~ + TAB Destructor
	~Student()
	{
		if (marks != nullptr)
			delete[]marks;
	}
};
class MyClass
{
	//default constrcutor
	//copy constructor
	//destructor
};
int main()
{
	MyClass a;////default constrcutor
	MyClass copy1(a);//copy constructor
	Student st;//default constructor
	st.AddMark(10);
	st.AddMark(10);
	st.AddMark(10);
	st.Print();

	Student student("Mark", 16);//parametrized costructor
	student.AddMark(9);
	student.AddMark(10);
	student.AddMark(11);
	student.AddMark(12);
	student.AddMark(12);
	student.AddMark(12);
	student.Print();
	cout << "---------------- Copy ------------------" << endl;
	Student copy(student);
	copy.Print();
    //int a;
    //float b = 3.14;
    //string name;

    //int num = 3.9333333;
    //cout << "Num : " << num << endl;
    ////cout << "A : " << a << endl;
    //// 
    ////Уніфікована ініціалізація 

    //int numbers[2];
    //cout << numbers[0] << endl;
    //numbers[0] += 2;
    //cout << numbers[0] << endl;

    //int num1 = 4.3;//ініціалізація з копіювання
    //cout << num1 << endl;

    //int value(10.2);//пряма ініціалізація
    //cout << value << endl;

    //float pi{ 3.14 };//уніфікована ініціалізація
    //cout << pi << endl;

    //int answer{ 42 };//simple variable
    //const float goodTemp{ 36.6 };//const variable
    //int grades[4]{ 11,12,9,4 };
    //int matrix[2][2] { 2,2,2,2, };
    //int* ptr{ nullptr };//pointer
    //Point p;
    //p.x = 10;
    //p.y = 22;
    //Point newP { 1,2 };


}//destructor
