#include <iostream>
#include <string.h>
using namespace std;
class hero
{
public:
    char *name;
    int health;
    char level;

    // public:
    hero()
    {
        cout << "simple constructor called" << endl;
        name = new char[100];
    }

    // parameterized constructor:
    hero(const char name[], int health, char level)
    {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        // this->name = name;
        this->health = health;
        this->level = level;
    }

    hero(int health, char level)
    {
        this->health = health;
        this->level = level;
    }

    // hero(hero &temp)
    // {
    //     cout << endl;
    //     cout << "Copy constructor called" << endl;
    //     char *ch = new char[strlen(temp.name) + 1];
    //     strcpy(ch, temp.name);
    //     this->name = ch;

    //     this->health = temp.health;
    //     this->level = temp.level;
    // }
    // Both above and below can be used
    hero(hero &temp)
    {
        cout << endl;
        cout << "Copy constructor called edited version" << endl;
        this->name = new char[strlen(temp.name) + 1];
        strcpy(this->name, temp.name);
        // this->name = ch;

        this->health = temp.health;
        this->level = temp.level;
    }

    void setname(const char name[])
    {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }
    int sethealth(int health)
    {
        this->health = health;
    }
    char setlevel(char level)
    {
        this->level = level;
    }
    char *getname()
    {
        return this->name;
    }
    int gethealth()
    {
        return health;
    }
    char getlevel()
    {
        return level;
    }
    void print()
    {
        // cout << endl;
        cout << "Name: " << this->name << endl;
        cout << "Health: " << this->health << endl;
        cout << "Level: " << this->level << endl;
    }
    ~hero()
    {
        delete[] name;
        cout << "Destructor is called\n";
    };
};

int main()
{
    hero paul;
    // hero paul("paul", 10, 'A');
    // paul.print();

    // hero *h = new hero("hari", 1, 'C');
    // h->print();

    // hero sawn("sawn", 22, 'B');
    // sawn.print();
    paul.sethealth(12);
    paul.setlevel('D');
    char name[7] = "paul";

    paul.setname("fame");
    cout << endl;

    paul.print();

    // use default copy constructor

    hero eddy(paul);
    cout << endl;
    cout << "eddy's data: " << endl;
    eddy.print();
    //    Hero hero2 = hero1;

    paul.name[0] = 's';
    cout << endl;
    cout << "paul data: " << endl;
    paul.print();
    cout << endl;
    cout << "eddy data: " << endl;
    eddy.print();

    // hero1 = hero2;

    // hero1.print();

    // hero2.print();

    // eddy.print();

    // paul.name[0] = 'e';

    // default constructor using ptr
    /*
     hero *h = new hero;

       h->setname("paul");
       h->sethealth(20);
       h->setlevel('C');
       cout << endl;
       //.print();
       cout << "Name: " << (*h).getname() << endl;
       cout << "Name: " << (h)->getname() << endl;
       cout << "Health: " << (h)->gethealth() << endl;
       cout << "Health: " << (*h).gethealth() << endl;
       cout << "Level: " << (h)->getlevel() << endl;
       cout << "Level: " << (*h).getlevel() << endl;*/

    // default constructor use
    /*
    #include <iostream>
#include <string.h>
using namespace std;
class hero
{
    char *name;
    int health;
    char level;

public:
    void setname(const char name[])
    {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        // this->name = name;
    }
    int sethealth(int health)
    {
        this->health = health;
    }
    char setlevel(char level)
    {
        this->level = level;
    }
    char *getname()
    {
        return this->name;
    }
    int gethealth()
    {
        return health;
    }
    char getlevel()
    {
        return level;
    }
};
    int main()
    {
        hero p;
     p.setname("paul");
     p.sethealth(10);
     p.setlevel('A');
     cout << "Name: " << p.getname() << endl;
     cout << "Health: " << p.gethealth() << endl;
     cout << "Level: " << p.getlevel() << endl;
     }
     */
}