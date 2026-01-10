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

        return day;
    }
    void setDate( int newDate)
    {
        this->day = newDate;
    }
};

int main()
{
    const int size = 5;
    const string str{ "first day" };
    const char* filename{ "text.txt" };
    const int days[]{ 31,31,28 };

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

