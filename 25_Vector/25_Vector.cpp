#include <iostream>
#include <vector>
using namespace std;
void Print(vector<int> v2)
{
    for (int i = 0; i < v2.size(); i++)
    {
        cout << v2[i] << " ";
    }
    cout << endl;
}
int main()
{
    vector<int> v;//size = 0
    vector<int> v2({ 1,2,3,4,5,6,7,8,9,10 });//size = 10
    vector<int> v3 = { 10,20,30,40 };//size = 10

    

    cout << "Size vector 2 " << v2.size() << endl;
    cout << "Capacity vector 2 " << v2.capacity() << endl << endl;
    for (int i = 0; i < v2.size(); i++)
    {
        cout << v2[i] << " ";
    }
    cout << endl;
    v3[0] = 100;
    for (int i = 0; i < v3.size(); i++)
    {
        cout << v3[i] << " ";
    }
    cout << endl;
    // iterator ---> pointer
    //v2.begin() - pointer first element
    //v2.end() - pointer first empty element
    //delete elements
    Print(v2);
    v2.erase(v2.begin());
    Print(v2);
    cout << "Size vector 2 " << v2.size() << endl;
    cout << "Capacity vector 2 " << v2.capacity() << endl << endl;
    v2.erase(v2.begin(), v2.begin()+2);
    Print(v2);
    cout << "Size vector 2 " << v2.size() << endl;
    cout << "Capacity vector 2 " << v2.capacity() << endl << endl;
    v2.erase(v2.end()-1);
    Print(v2);
    cout << "Size vector 2 " << v2.size() << endl;
    cout << "Capacity vector 2 " << v2.capacity() << endl << endl;

    //insert
    v2.insert(v2.begin(), 77);
    Print(v2);
    cout << "Size vector 2 " << v2.size() << endl;
    cout << "Capacity vector 2 " << v2.capacity() << endl << endl;
    v2.insert(v2.begin(),5,4);
    Print(v2);
    cout << "Size vector 2 " << v2.size() << endl;
    cout << "Capacity vector 2 " << v2.capacity() << endl << endl;
    v2.insert(v2.end(), {33,22,11});
    Print(v2);
    cout << "Size vector 2 " << v2.size() << endl;
    cout << "Capacity vector 2 " << v2.capacity() << endl << endl;
    v2.insert(v2.end(), v3.begin(), v3.end());
    Print(v2);
    cout << "Size vector 2 " << v2.size() << endl;
    cout << "Capacity vector 2 " << v2.capacity() << endl << endl;

    //add element to the end
    v2.push_back(444);
    v2.push_back(444);
    v2.push_back(444);
    v2.push_back(444);
    Print(v2);
    v2.pop_back();
    v2.pop_back();
    Print(v2);

   /* Print(v2);
    Print(v3);
    v2.swap(v3);
    Print(v2);
    Print(v3);*/
    cout << "Show first element : " << v2.front() << endl;
    cout << "Last first element : " << v2.back() << endl;

    v2.resize(50);
    Print(v2);
    v2.push_back(444);
    v2.push_back(444);
    Print(v2);
    v2.resize(5);
    v2.shrink_to_fit();
    cout << "Size vector  " << v2.size() << endl;
    cout << "Capacity vector " << v2.capacity() << endl << endl;
    v2.push_back(444);
    v2.push_back(444);
    Print(v2);
    cout << "Size vector  " << v2.size() << endl;
    cout << "Capacity vector " << v2.capacity() << endl << endl;

    v2.push_back(444);
    v2.push_back(444);
    v2.push_back(444);
    v2.push_back(444);
    v2.push_back(444);
    Print(v2);
    cout << "Size vector  " << v2.size() << endl;
    cout << "Capacity vector " << v2.capacity() << endl << endl;


}

