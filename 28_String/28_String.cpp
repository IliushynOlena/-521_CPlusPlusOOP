

#include <iostream>
#include <string>
using namespace std;

int main()
{
    //string name = "Ivan";
    //cout << "Enter name : ";
    //getline(cin ,name);//cin >> name;
    //cout << name;

    string one("Lottery Winner");
    cout << one << endl;;
    string two = string("Hello");
    cout << two << endl;;
    string three(one);//copy constructor
    cout << three << endl;;
    one += "Opps!";
    cout << one << endl;;
    two = "Sorry! that was";
    cout << two<< endl;
    one[0] = 'P';
    cout << one << endl;
    string four = one + two;
    cout << four << endl;

    char alls[] = "All's well that ends well";
    string five(alls);
    cout << five << endl;
    string six(alls, 20);
    cout << six << endl;
    string seven(alls+6, alls + 10);
    cout << seven << endl;
    string eight(&alls[6], &alls[10]);
    cout << eight << endl;
    string nine(four, 7, 16);
    cout << nine << endl;

    for (string::iterator i = nine.begin(); i != nine.end(); i++)
    {
        cout << *i;
    }
    cout << endl;
    for (char s : nine)
    {
        cout << s;
    }

    //Methods
    const char c_str[] = "Hello";
    string str = "hello world!";
    string str2 = "World";

    cout << "Capacity : " << str.capacity() << endl;
    cout << "Size/Length : " << str.size() << " = "<< str.length() << endl;

    //str.clear();
    if (str.empty())
        cout << "String is empty" << endl;
    cout << "Capacity : " << str.capacity() << endl;
    cout << "Size/Length : " << str.size() << " = " << str.length() << endl;

    cout << "Str : " << str << endl;
    str[0] = 'H';//set
    cout << str[0] << endl;//get
    cout << "Str : " << str << endl;

    //add element at the end
    str.append(c_str);
    cout << "Str : " << str << endl;
    str.append(7, 'a');
    cout << "Str : " << str << endl;
    str.append(c_str, 2);
    cout << "Str : " << str << endl;
    str.append(str, 3, 5);
    cout << "Str : " << str << endl;
    str.append({ 'a','b','c' });
    cout << "Str : " << str << endl;
    str.append(str.begin()+3, str.end()-2);
    str.append("some text");
    cout << "Str : " << str << endl;

    //add by position
    str.insert(str.begin(), 5, 'b');
    cout << "Str : " << str << endl;
    str.insert(str.begin() + 5, 'B');
    cout << "Str : " << str << endl;
    str.insert(3, 7, 'c');
    cout << "Str : " << str << endl;
    str.insert(3, c_str);
    cout << "Str : " << str << endl;
    str.insert(str.begin(), { '.',',','!' });
    cout << "Str : " << str << endl;


    //erase
    str.erase(str.end()-1);
    cout << "Str : " << str << endl;
    str.erase(0, 10);
    cout << "Str : " << str << endl;
    str.erase(20);
    cout << "Str : " << str << endl;
    //str.erase();
    //cout << "Str : " << str << endl;

    str.replace(0, 5, "YES");
    cout << "Str : " << str << endl;

    const char* arr = str.c_str();
    cout << arr << endl;

    cout << "Index of first letter o " << str.find('o') << endl;

    if (str.find('O') == string::npos)
    {
        cout << "Element not found" << endl;
    }

    cout << "Index of last letter o " << str.rfind('o') << endl;
    cout << "find_first_of " << str.find_first_of("abcd") << endl;
    cout << "find_first_not_of " << str.find_first_not_of("abcd") << endl;

    cout << "Substring : " << str.substr(7, 5) << endl;

}

