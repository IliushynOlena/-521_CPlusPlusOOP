#include <iostream>
using namespace std;
class Enemy
{
protected:
    string name;
    int health;
    float strength;
    static const int maxHealth = 100;
public:
    Enemy():name("no name"), health(maxHealth), strength(0){}
    Enemy(string n, float s):name(n), health(maxHealth), strength(s){}
    void Print()const
    {
        cout << "Name : " << name << endl;
        cout << "Health : " << health << "%" << endl;
        cout << "Strenght : " << strength << endl;
    }
    void DecreaseHealth(int value)
    {
        if (health - value < 0)
            health = 0;//10 - 15
        else
            health -=value;
    }
    bool IsAlive()const
    {
        return health > 0;
    }
};
//Inheritance 
//class Child : [spetificator] Parent
// [spetificator] - private public protected
class Dragon : public Enemy
{
    float armor;
public:
    Dragon() : armor(0), Enemy() {}
    Dragon(string n, float s, float a) : armor(a), Enemy(n,s) {}
    void Print()
    {
        cout << "-------------------- Dragon ----------------------" << endl;
        Enemy::Print();
        cout << "Armor : " << armor << endl;
    }
    void Defence(int damage)
    {
        cout << "Getting defence : " << damage << " damage ...." << endl;
        DecreaseHealth(damage-armor);
        cout << "Health after defence : " << health <<" % " << endl;
    }
    float Attack()
    {
        cout << "Attacking with strength : " << strength << " ! " << endl;
        return strength;
    }


};
class Zombie: public Enemy
{
    float runSpeed;
public:
    Zombie(): runSpeed(0),Enemy(){}
    Zombie(string n, float s, float r): runSpeed(r),Enemy(n,s){}
    void Run()
    {
        cout << "Run with speed : " << runSpeed << " km/h" << endl;
    }
    void Print()
    {
        cout << "-------------------- Zombie ----------------------" << endl;
        Enemy::Print();
        cout << "Run speed : " << runSpeed << endl;
    }    

};
int main()
{
    Zombie zombie("Eddy", 2, 150);
    zombie.Run();
    zombie.Print();
    Dragon dragon("Stive",60,40);
    dragon.Print();

    Dragon boss("Boss", 70, 20);
    boss.Print();

    int i = 1;
    do
    {
        cout << "------------- Round : " << i << "------------------\n";
        boss.Defence(dragon.Attack());
        dragon.Defence(boss.Attack());
        dragon.Print();
        boss.Print();
        i++;
        cout << endl;

    } while (boss.IsAlive() && dragon.IsAlive());    
}

