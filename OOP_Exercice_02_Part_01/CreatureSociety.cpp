#include <iostream>
#include <string>
using namespace std;
#define BADNAME "Bad Billy"
#define GOODNAME "Good Bod"

class creature
{
        string name;

    protected:
        int estimatedLifespan;

    public:
        creature(int);
        void clone(int);
        bool is_a_zombie();
        void hit();
        void heal();
};

creature::creature(int L = 0)
{
    estimatedLifespan = L;
    //is_bad = false;
    // Give a place to society and a name
}

void creature::clone(int pos)
{
    // Destroy someone and clone your self to there place
}

bool creature::is_a_zombie()
{
    if (estimatedLifespan > 0)
        return false;
    return true;
}

void creature::hit()
{
    // Take 1 from his life (if not a zombie)
}

void creature::heal()
{
    // Give one to his life (if not a zombie)
}


class good_creature : public creature
{
    public:
        void bless();
        bool is_a_good();

};

void good_creature::bless()
{
    if (estimatedLifespan > 0)
        clone(0);   // Change 0 with next position variable
}

bool good_creature::is_a_good()
{
    return true;
}


class bad_creature : public creature
{
    public:
        void bless();
        bool is_a_good();
};

void bad_creature::bless()
{
    if (estimatedLifespan > 0)
    {
        int pos;
        // int pos = next_pos;
        for (bool foundGood = false; foundGood != true; pos++)
        {
            // Check if next creature is good or bad
            if (true)
                foundGood = true;
            else
                //clone(pos);
                clone(0);
        }
    }
}

bool bad_creature::is_a_good()
{
    return false;
}


class creature_society
{
        int numOfCreatures = 0;
        creature* firstCreature;
        creature* ArrayOfCreatures;

    public:
        creature_society(int);
};

creature_society::creature_society(int N)
{
    // ArrayOfCreatures = new creature[N];
    // bool good_creature = false;
    // for (int curCreature = 0; curCreature < N; curCreature++)
    // {
    //     int randomNum = ((double) rand() / (RAND_MAX)) + 1;
    //     if (randomNum == 1)
    //         good_creature = true;
    // }
}