
#include <iostream>
#include <list>
#include <iomanip>
using namespace std;

void ShowList(list<int>& l1, list<int>& l2)
{
    list<int>::iterator iter;
    cout << "List 1: ";
    for (iter = l1.begin(); iter != l1.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << endl;

    cout << "List 2: ";
    for (iter = l2.begin(); iter != l2.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << endl;
    cout << endl;
}
struct Book {
    string name;
    string author;
    int pages;
};
bool CompareBookByName(const Book &b1, const Book &b2) {
    return b1.name < b2.name;
}
bool CompareBookByAuthor(const Book& b1, const Book& b2) {
    return b1.author < b2.author;
}
bool CompareBookByPages(const Book& b1, const Book& b2) {
    return b1.pages < b2.pages;
}
int main()
{
    list<Book> library;
    library.assign({
        Book{"Night","Gogol",786},
        Book{"Maria","Kotlarevskiy",350},
        Book{"Kaydasheva family","Nechy-Levitskiy",325},
        Book{"Kobzar","Shevchenko",1000},
        Book{"Murder on the Orient Express","Agata Khristi",786},
        Book{"Shadows of Forgotten Ancestors","Kotlarevskiy",786}
        });
    cout << "================== Original List ===========================" << endl;
    for (Book b : library)
    {
        cout << left<<  setw(30)<< b.name << " | " << setw(30) << b.author << " | " << b.pages << endl;
    }
    library.sort(CompareBookByName);
    cout << "================== Sorted List By Name ===========================" << endl;
    for (Book b : library)
    {
        cout << left << setw(30) << b.name << " | " << setw(30) << b.author << " | " << b.pages << endl;
    }

    library.sort(CompareBookByAuthor);
    cout << "================== Sorted List By Author ===========================" << endl;
    for (Book b : library)
    {
        cout << left << setw(30) << b.name << " | " << setw(30) << b.author << " | " << b.pages << endl;
    }

    library.sort(CompareBookByPages);
    cout << "================== Sorted List By Pages ===========================" << endl;
    for (Book b : library)
    {
        cout << left << setw(30) << b.name << " | " << setw(30) << b.author << " | " << b.pages << endl;
    }
    /*
    list<int> l1, l2;

    cout << " Size = " << l1.size() << endl;
    cout << " Size = " << l2.size() << endl;

   
    for (int i = 0; i < 8; i++)
    {
        l1.push_back(i);
        l2.push_front(i);
    }
    ShowList(l1, l2);
    //change elements
    l1.assign({ 1,5,3,7,8,9,14,5,7 });
    ShowList(l1, l2);

    //show first element
    cout << "First element : " << l1.front() << endl;
    list<int>::iterator it;
    it = l1.begin();
    it++;
    cout << "Second element : " << *it << endl;

    //remove elements by position
    l1.erase(l1.begin());
    ShowList(l1, l2);

    // //remove elements by end
    l1.pop_back();
    ShowList(l1, l2);

    //remove elements by start
    l1.pop_front();
    ShowList(l1, l2);

    //remove elements by value
    l1.remove(7);
    ShowList(l1, l2);

    //insert by pisition
    l1.insert(l1.end(), 100);
    ShowList(l1, l2);
    l1.insert(l1.begin(), 5, 88);
    ShowList(l1, l2);
    l1.insert(l1.begin(), { 11,22,33 });
    ShowList(l1, l2);
    l1.insert(l1.end(), l2.begin(), l2.end());
    ShowList(l1, l2);

    l1.resize(5);
    ShowList(l1, l2);

    l1.resize(30, 5);
    ShowList(l1, l2);

    l1.splice(l1.end(), l2, l2.begin());
    ShowList(l1, l2);

    l1.reverse();
    ShowList(l1, l2);

    l1.sort();
    l2.sort();
    ShowList(l1, l2);

    l1.merge(l2);
    ShowList(l1, l2);

    l1.unique();
    ShowList(l1, l2);

    l1.swap(l2);
    ShowList(l1, l2);
    */





}

