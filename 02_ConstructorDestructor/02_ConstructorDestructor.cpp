#include <iostream>
#include <windows.h>  
using namespace std;

struct PIB
{
	string first_name;
	string last_name;
	string surname;
};
struct  Date
{
	int day;
	int month;
	int year;
};

class Student//Incapsulation
{
private:
	PIB fullname;
	Date birthdate;
	string phone;
	string city;
	string country;
	string schoolname;
	string schoolname_city;
	string schoolname_country;
	string groupname;
	int* marks;//nullptr
	int markCount;//0
	float averageMark;
	void setAverageMark()
	{
		float summa = 0;
		for (int i = 0; i < markCount; i++)
		{
			summa += marks[i];
		}
		averageMark = (float)summa / markCount;
	}
public:
	//Constructor  ctor+TAB
	Student()
	{
		cout << "Default Constructor" << endl;
		fullname.first_name = "no name";
		fullname.last_name = "no last name";
		fullname.surname = "no surname";
		birthdate.day = 1;
		birthdate.month = 1;
		birthdate.year = 1;
		phone = "no phone";
		city = "no city";
		country = "no country";
		schoolname = "none";
		schoolname_city = "none";
		schoolname_country = "none";
		groupname = "none";
		marks = nullptr;
		markCount = 0;
		averageMark = 0;
	}
	Student(string name, string last, string surname)
	{
		fullname.first_name = name;
		fullname.last_name = last;
		fullname.surname = surname;
		birthdate.day = 1;
		birthdate.month = 1;
		birthdate.year = 1;
		phone = "no phone";
		city = "no city";
		country = "no country";
		schoolname = "none";
		schoolname_city = "none";
		schoolname_country = "none";
		groupname = "none";
		marks = nullptr;
		markCount = 0;
		averageMark = 0;
	}
	Student(string name, string last, string surname, int day, int month, int year)
	{
		fullname.first_name = name;
		fullname.last_name = last;
		fullname.surname = surname;
		birthdate.day = day;
		birthdate.month = month;
		birthdate.year = year;
		phone = "no phone";
		city = "no city";
		country = "no country";
		schoolname = "none";
		schoolname_city = "none";
		schoolname_country = "none";
		groupname = "none";
		marks = nullptr;
		markCount = 0;
		averageMark = 0;

	}
	//set  
	void setName(string name)
	{
		fullname.first_name = name;
	}
	void setLastName(string lastname)
	{
		fullname.last_name = lastname;
	}
	void setSurName(string surname)
	{
		fullname.surname = surname;
	}
	//get
	string getName()
	{
		return fullname.first_name;
	}
	int getDayBirthdate()
	{
		return birthdate.day;
	}
	void Initialization()
	{
		fullname.first_name = "no name";
		fullname.last_name = "no last name";
		fullname.surname = "no surname";
		birthdate.day = 1;
		birthdate.month = 1;
		birthdate.year = 1;
		phone = "no phone";
		city = "no city";
		country = "no country";
		schoolname = "none";
		schoolname_city = "none";
		schoolname_country = "none";
		groupname = "none";
		marks = nullptr;
		markCount = 0;
		averageMark = 0;
	}
	void InputFromKeyboard()
	{
		cout << "Enter first name : "; cin >> fullname.first_name;
		cout << "Enter last name : "; cin >> fullname.last_name;
		cout << "Enter surname : "; cin >> fullname.surname;

		cout << "Enter birthdate day : "; cin >> birthdate.day;
		cout << "Enter birthdate month : "; cin >> birthdate.month;
		cout << "Enter birthdate year : "; cin >> birthdate.year;

		cout << "Enter phone number : "; cin >> phone;
		cout << "Enter city : "; cin >> city;
		cout << "Enter country : "; cin >> country;
		cout << "Enter schoolname : "; cin >> schoolname;
		cout << "Enter schoolname city : "; cin >> schoolname_city;
		cout << "Enter schoolname country : "; cin >> schoolname_country;
		cout << "Enter group name : "; cin >> groupname;
		marks = nullptr;
		markCount = 0;
		averageMark = 0;
	}
	void Print()
	{
		cout << "Fullname : " << fullname.first_name << " " << fullname.last_name << " "
			<< fullname.surname << endl;
		cout << "Birthdate : " << birthdate.day << "/" << birthdate.month << "/" 
			<< birthdate.year << endl;
		cout << "Phone number : " << phone << endl;
		cout << "City : " << city << endl;
		cout << "Country : " << country << endl;
		cout << "School name : " << schoolname << endl;
		cout << "School name city : " << schoolname_city << endl;
		cout << "School name country : " << schoolname_country << endl;
		cout << "Group name  : " << groupname << endl;
		for (int i = 0; i < markCount; i++)
		{
			cout << marks[i] << " ";
		}
		cout << endl;
		cout << "Average mark : " << averageMark << endl;
	}
	void AddMark(int mark)
	{
		markCount++;
		int* temp = new int[markCount];//6
		for (int i = 0; i < markCount-1; i++)
		{
			temp[i] = marks[i];
		}
		temp[markCount - 1] = mark;
		if (marks != nullptr)
			delete[]marks;
		marks = temp;
		setAverageMark();
		//delete  marks
	}
	void Delete()
	{
		if (marks != nullptr)
			delete[]marks;
	}
	//~ + TAB Destructor
	~Student()
	{
		cout << "Destructor " << fullname.first_name << endl;
		if (marks != nullptr)
			delete[]marks;
	}
};
void gotoxy(int x, int y)
{
	COORD coordinate;
	coordinate.X = x;
	coordinate.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);
}
class User//Інкапсуляція
{
private:
	string login;
	string password;
public:
	//default constructor
	User()
	{
		login = "none";
		password = "none";
	}
	User(string login, string password)
	{
		//(*this).login = login;
		this->login = login;
		this->password = password;
	}
	//default destructor
	~User()
	{

	}
};
int main()
{
	
	User u;
	gotoxy(10, 5);cout << "Main program" << endl;
	gotoxy(12, 7);
	Student st;//Constructor default
	//st.Initialization();
	st.Print();
	//st.InputFromKeyboard();
	st.setName("Artyr");
	st.Print();
	

	
	
	Student student2("Mukola", "Vasulovich", "Oliunuk", 11, 12, 2001);
	student2.Print();
	student2.AddMark(12);
	student2.AddMark(7);
	student2.AddMark(4);
	student2.AddMark(8);
	student2.Print();

	//st.Delete();
	//student1.Delete();
	//student2.Delete();
	if (true)
	{
		Student student1("Oleg", "Mukolayovich", "Petruk");
		student1.Print();

	}


   
}

