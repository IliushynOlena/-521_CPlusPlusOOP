#include<iostream>
using namespace std;

struct FullName
{
    string last_name;
    string first_name;
    string middle_name;
};

struct Additional_info
{
    int number_of_calls;
    string last_call;
    int num_of_phone_nums;
};

class Abonent
{
private:
    FullName f_n;
    int home_phone;
    int work_phone;
    int mobile_phone;
    Additional_info a_i;
    static int number_of_abonents;
public:
    Abonent() : f_n{ "no last name", "no first name", "no middle name" }, home_phone{ 0 }, work_phone{ 0 }, mobile_phone{ 0 }, a_i{ 0, "no last call", 0 } { number_of_abonents++; };
    Abonent(string last_name) : Abonent()
    {
        f_n.last_name = last_name;
    }
    Abonent(string last_name, string first_name) : Abonent(last_name)
    {
        f_n.first_name = first_name;
    }
    Abonent(string last_name, string first_name, string middle_name) : Abonent(last_name, first_name)
    {
        f_n.middle_name = middle_name;
    }
    Abonent(string last_name, string first_name, string middle_name, int home, int work, int mobile) : Abonent(last_name, first_name, middle_name)
    {
        home_phone = home;
        work_phone = work;
        mobile_phone = mobile;
    }

    Abonent(string last_name, string first_name, string middle_name, int home, int work, int mobile, int calls, string last_call, int phones) : Abonent(last_name, first_name, middle_name, home, work, mobile)
    {
        a_i.number_of_calls = calls;
        a_i.last_call = last_call;
        a_i.num_of_phone_nums = phones;

    }
    void setHomePhone(int phone)
    {
        home_phone = phone;
    }
    void setWorkPhone(int phone)
    {
        work_phone = phone;
    }
    void setMobilePhone(int phone)
    {
        mobile_phone = phone;
    }
    void setNumberOfCalls(int n)
    {
        a_i.number_of_calls = n;
    }
    void setLastCall(string day)
    {
        a_i.last_call = day;
    }
    void setNumOfPhones(int n)
    {
        a_i.num_of_phone_nums = n;
    }
    void Print()const
    {
        cout << "Last name : " << f_n.last_name << endl;
        cout << "First name : " << f_n.first_name << endl;
        cout << "Middle name : " << f_n.middle_name << endl;
        cout << "Home phone : " << home_phone << endl;
        cout << "Work phone : " << work_phone << endl;
        cout << "Mobile phone : " << mobile_phone << endl;
        cout << "Number of calls : " << a_i.number_of_calls << endl;
        cout << "Last call : " << a_i.last_call << endl;
        cout << "Number of phone numbers : " << a_i.num_of_phone_nums << endl;
    }
    string getName()const
    {
        return f_n.first_name;
    }
    int getPhone()const
    {
        return work_phone;
    }
    static int getAbonentsCount()
    {
        return number_of_abonents;
    }
};

int Abonent::number_of_abonents = 0;

class PhoneBook
{
private:
    Abonent* abonents;
    int countAbonent;
    int age;
public:
    PhoneBook()
    {
        abonents = nullptr;
        countAbonent = 0;
        age = 0;
    }
    ~PhoneBook()
    {
        delete[]abonents;
    }
    void Add(Abonent& a)
    {
        Abonent* temp = new Abonent[countAbonent + 1];
        for (int i = 0; i < countAbonent; i++)
        {
            temp[i] = abonents[i];
        }
        temp[countAbonent] = a;
        delete[]abonents;
        abonents = temp;
        countAbonent++;
    }
    void Delete(int phone)
    {
        int index = -1;
        for (int i = 0; i < countAbonent; i++)
        {
            if (abonents[i].getPhone() == phone)
            {
                index = i;
                break;
            }
        }
        if (index == -1) return;
        Abonent* temp = new Abonent[countAbonent - 1];
        for (int i = 0, j = 0; i < countAbonent; i++)
        {
            if (i != index)
            {
                temp[j++] = abonents[i];
            }
        }
        delete[]abonents;
        abonents = temp;
        countAbonent--;
    }
    void SearchByName(string name)const
    {
        for (int i = 0; i < countAbonent; i++)
        {
            if (abonents[i].getName() == name)
            {
                abonents[i].Print();
                cout << "----------------------------\n";
            }
        }
    }
    void SearchByPhone(int phone)const
    {
        for (int i = 0; i < countAbonent; i++)
        {
            if (abonents[i].getPhone() == phone)
            {
                abonents[i].Print();
                return;
            }
        }
    }
    void ShowAll()const
    {
        for (int i = 0; i < countAbonent; i++)
        {
            abonents[i].Print();
            cout << "----------------------------\n";
        }
    }
    Abonent getAbonent(int index)//20000
    {
        if (index > 0 && index < countAbonent)
            return abonents[index];
        else
            return Abonent();
    }
    Abonent operator[](int index)//20000
    {
        if (index > 0 && index < countAbonent)
            return abonents[index];
        else
            return Abonent();
    }
    void ChageAge(int value)
    {
        age = value;
    }
    void operator()(int value)
    {
        age = value;
    }
    void ShowAge()
    {
        cout << age << endl;
    }
};

int main()
{
    PhoneBook book;
    Abonent a("Shevchenko", "Ivan", "Dmytrovich", 2335627, 975263147, 682758927, 6, "Monday", 25);
    a.Print();
    cout << "----------------------------\n";
    Abonent a2("Pylypchuk", "Vasyl", "Sergiyovich", 2572568, 955468792, 662578951, 7, "Tuesday", 18);
    a2.Print();
    cout << "----------------------------\n";
    Abonent a3("Dmytrenko", "Orest", "Yosypovich", 43569874, 682256446, 672302546, 2, "Saturday", 33);
    a3.Print();
    cout << "----------------------------\n";
    cout << "Total abonents : " << Abonent::getAbonentsCount() << endl;
    cout << "------------------\n";

    book.Add(a);
    book.Add(a2);
    book.Add(a3);
    book.ShowAll();

    book.getAbonent(2).Print();
    book[1].Print();

    book.ChageAge(100);
    book.ShowAge();
    book(200);
    book.ShowAge();

   /* cout << "--------All Phones----------\n";
    book.ShowAll();

    cout << "--------Search Name---------\n";
    book.SearchByName("Ivan");

    cout << "-----------Delete-----------\n";
    book.Delete(955468792);

    cout << "--------After delete--------\n";
    book.ShowAll();*/
}