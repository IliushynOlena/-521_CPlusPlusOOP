#include <iostream>
using namespace std;

class Date
{
    //this
public:
    int day;
    int month;
    int year;

  /*  int getDay()
    {
        return day;
    }*/
    int getDay()const
    {
        int a = 5;
        a++;
        return day;
    }
    void setDate( int newDate)
    {
        this->day = newDate;
    }
};
class Abonent 
{
    string name;
public:
    void Print()const {}
    string getName()const
    {
        return name;
    }
};
class PhoneBook
{
    Abonent* abonents;
    int countAbonent;
    void Add(Abonent a) {}
    void Delete(string phone) {}
    void SearchByName(string name) 
    {
        for (int i = 0; i < countAbonent; i++)
        {
            if (abonents[i].getName() == name)
            {
                abonents[i].Print();
            }
        }
    }
    void SearchByPhone(string phone){}
        void ShowAll() {}
};
int main()
{
    const int size = 5;
    const string str{ "first day" };
    const char* filename{ "text.txt" };
    const int days[]{ 31,31,28 };

    while (true)
    {

    }
            
    Date eventDay{ 12,5,2026 };//Easter Day
    eventDay.getDay();
    cout << "Day before : " << eventDay.getDay() << endl;
    eventDay.day = 25;
    eventDay.setDate(31);
    cout << "Day after : " << eventDay.getDay() << endl;
    const Date independenceDay{ 24,8,1991 };
    cout << "Day before : " << independenceDay.getDay() << endl;
    //independenceDay.day = 25; //error
   
}

