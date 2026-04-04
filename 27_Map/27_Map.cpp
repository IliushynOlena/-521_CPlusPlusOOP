#include <iostream>
#include <map>
#include <list>
#include <string>
using namespace std;


map<string, int>::iterator findByValue(map<string, int>& m, int value)
{
    for (map<string,int>::iterator i = m.begin(); i != m.end(); i++)
    {
        if (i->second == value)
            return i;
    }
    return m.end();
}

class Dictionary {
    map<string, list<string>> dic;

    int a = 5;
    map<string, list<string>>::iterator it;
    int* ptr = &a;
    void Print(){}
    void AddWordWithTranslation(){}
    void AddTranslation(){}
    void RemoveWord(){}
};
int main()
{
    map<string, list<string>> dic;

    string word = "run";
    list<string> meanings = { "bigtu", "pochatu","zapochatkevatu" };

    dic.insert(make_pair(word, meanings));
    dic.insert(make_pair("word", list<string>({ "slovo" })));
    dic.insert(make_pair("mind", list<string>({ "dumka","dusha","spogad" })));
    dic.insert(make_pair("bad", list<string>({ "poganuy","borg" })));

    for(auto item : dic)
    {
        cout << "Key : " << item.first << " - ";
        for (string word : item.second)
        {
            cout << word << " ";
        }
        cout << endl;
    }

    for (string item : dic["bad"])
    {
        cout << item << " ";
    }
    cout << endl;

    //////////////////// add translate
    string input = "";
    cout << "Enter word to add translatins: "; getline(cin, input);

    if (dic.find(input) == dic.end())
        cout << "Word not found!\n";
    else
    {
        string translate = "";
        do
        {
            cout << "Enter translate: ";
            getline(cin, translate);
            dic[input].push_back(translate);

        } while (!translate.empty());
    }

    for (string item : dic[input])
    {
        cout << item << " ";
    }

    ////////////////////// check translate
    cout << "Enter word to translate: "; getline(cin, input);

    if (dic.find(input) == dic.end())
        cout << "Translate not found!\n";
    else
    {
        cout << "\tMeans:\n";
        for (string elem : dic[input])
            cout << elem << " ";
    }


    /*
    map<string, int> m;

    pair<string, int> p("Inna", 5);

    m.insert(p);
    m.insert(pair<string, int>("Valia", 4));
    m.insert(make_pair("Olga", 1));  

    
    for (auto el : m)
    {
        cout << "Key : " << el.first << " . Value : " << el.second << endl;
    }

     //pair<map<string,int>::iterator,bool> result =   m.insert(make_pair("Olga", 9));
     auto result =   m.insert(make_pair("Olga", 9));
     if (result.second)
     {
         cout << "Item was added" << endl;
     }
     else
     {
         cout << "Item was not added" << endl;
     }
    for (auto el : m)
    {
        cout << "Key : " << el.first << " . Value : " << el.second << endl;
    }

    cout << "Value of Olga : " << m["Olga"] << endl;
    cout << "Value of Inna : " << m["Inna"] << endl;

    map<string, int>::iterator it = m.find("Olga");
    if (it == m.end())
    {
        cout << "Not found" << endl;
    }
    else
    {
        cout << "Key : " << it->first << " . Value : " << it->second << endl;
        //it->first = "Mukola";//error
        it->second = 9;
        cout << "Key : " << it->first << " . Value : " << it->second << endl;
    }

    it = findByValue(m, 9);
    if (it == m.end())
    {
        cout << "Not found" << endl;
    }
    else
    {
        cout << "Super prize" << endl;
        cout << "Key : " << it->first << " . Value : " << it->second << endl;
    }

    if (it != m.end())
        m.erase(it);

    cout << "------------------------------------------------" << endl;
    m["Kolya"] = 100500;
    m["Inna"] = 333;
    for (auto el : m)
    {
        cout << "Key : " << el.first << " . Value : " << el.second << endl;
    }
    */


}

