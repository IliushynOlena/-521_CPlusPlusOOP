#include <iostream>
using namespace std;

//struct
//struct Player
//{
//    string position;
//    string club;
//    string name;
//    int age;
//    int games;
//    int goals;
//};
//
//void PrintPlayer(Player pl)
//{
//    cout << "Position : " << pl.position << endl;
//    cout << "Club : " << pl.club << endl;
//    cout << "Name : " << pl.name << endl;
//    cout << "Age : " << pl.age << endl;
//    cout << "Games : " << pl.games << endl;
//    cout << "Goals : " << pl.goals << endl;
//}
//void InitPlayer(Player &pl)//& - ссилка     * вказівник
//{
//    pl.position = "Defender";
//    pl.club = "Real Madrid";
//    cout << "Enter name : "; cin >> pl.name;
//    cout << "Enter age : "; cin >> pl.age;
//    pl.games = 0;
//    pl.goals = 0;
//}
//void AddGameToPlayer(Player& pl, int goals)
//{
//    pl.games++;
//    pl.goals += goals;
//}

//OOP 
class Player
{
private:

    string position;
    string club;
    string name;
    int age;
    int games;
    int goals;
public:
    void PrintPlayer()
    {
        cout << "Position : " << position << endl;
        cout << "Club : " << club << endl;
        cout << "Name : " << name << endl;
        cout << "Age : " << age << endl;
        cout << "Games : " << games << endl;
        cout << "Goals : " << goals << endl;
    }
    void InitPlayer()
    {
        position = "Defender";
        club = "Real Madrid";
        cout << "Enter name : "; cin >> name;
        cout << "Enter age : "; cin >> age;
        games = 0;
        goals = 0;
    }
    void AddGameToPlayer( int goals)
    {
        games++;
        this->goals += goals;
        //goals += goals;
    }
};

class Student//інкапсуляція private
{
private:
    //змінні-члени класу  data members.
    string name;
    int marks[3];
public:
    //методи-члени класу (методи) member function.
    double getAverage()
    {
        double summa = 0;
        for (int i = 0; i < 3; i++)
        {
            summa += marks[i];
        }
        return summa / 3;
    }
    
    //set
    void setName(string name)
    {
        this->name = name;
    }
    void setMark(int mark, int index)
    {
        if (mark > 0 && mark <= 12)
            marks[index] = mark;
        else
            cout << "Incorrect mark" << endl;
    }
    //get 
    string getName()
    {
        return name;
    }
    int getMark(int index)
    {
        return marks[index];
    }
};


int main()
{
    int a;//variable
    string name;
    Student st;//object
    st.setName("Ivan");
    st.setMark(12,0) ;
    st.setMark(8,1) ;
    st.setMark(12,2) ;
   

    cout << "Name : " << st.getName() << " Mark : " << st.getMark(0) << endl;
    cout << "Average marks : " << st.getAverage() << endl;
    /*Student st1;
    Student st2;
    Student st3;*/

   /* Player player;
    player.InitPlayer();
    player.PrintPlayer();
    player.AddGameToPlayer(5);
    player.PrintPlayer();*/
   /* Player player;
    InitPlayer(player);
    PrintPlayer(player);
    AddGameToPlayer(player, 0);
    PrintPlayer(player);
    AddGameToPlayer(player, 1);
    PrintPlayer(player);
    AddGameToPlayer(player, 5);
    PrintPlayer(player);*/



}

