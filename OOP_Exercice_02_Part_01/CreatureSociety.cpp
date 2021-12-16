#include <iostream>
#include <string>
using namespace std;

#define GOODNAME "Good Bob"
#define BADNAME "Bad Billy"

class creature
{
        string name;

    protected:
        int estimatedLifespan;

    public:
        creature(int, string);
        bool is_a_zombie();
        void clone(int);
        void beat();
        virtual void bless();
};

creature::creature(int L = 0, string type = "NONE")
{
    estimatedLifespan = L;
    if (type == "good")
        name = GOODNAME;
    else if (type == "bad")
        name = BADNAME;
}

bool creature::is_a_zombie()
{
    if (estimatedLifespan > 0)
        return false;
    return true;
}

void creature::clone(int creature_pos)
{
    // delete [] ArrayOfCreatures[creature_pos];
    // strcpy(name, ArrayOfCreatures[creature_pos].name);
    // ArrayOfCreatures[creature_pos].estimatedLifespan = estimatedLifespan;
    int i;
}

void creature::beat()
{
    if (!is_a_zombie())
        estimatedLifespan--;
}

void creature::bless()
{
    if (!is_a_zombie())
        estimatedLifespan++;
}

class good_creature : public creature
{
    public:
        void bless(int, int, int);
        bool is_a_good();
};

void good_creature::bless(int N, int creature_pos, int good_thrsh)
{
    creature::bless();
    if (estimatedLifespan >= good_thrsh)
    {
        if (creature_pos + 1 >= N)
            clone(0);
        else
            clone(creature_pos + 1);
    }
}

bool good_creature::is_a_good()
{
    return true;
}

class bad_creature : public creature
{
    public:
        void bless(int, int, int);
        bool is_a_good();
};

void bad_creature::bless(int N, int creature_pos, int bad_thrsh)
{
    creature::bless();
    if (estimatedLifespan >= bad_thrsh)
    {
        if (++creature_pos < N)
        {
            bool notAZombie = false;
            while (!notAZombie && creature_pos < N)
            {
                // if (!ArrayOfCreatures[creature_pos + 1].is_a_zombie())
                //{
                //      notAZombie = true;
                //}
                // else
                //{
                //      clone(creature_pos);
                //}
                int i;
            }
        }
    }
}

bool bad_creature::is_a_good()
{
    return false;
}

class creature_society
{
        int creaturesOnSociety;
        creature* firstCreature;

    public:
        creature* ArrayOfCreatures;
        creature_society(int);
};

creature_society::creature_society(int N)
{
    creaturesOnSociety = 0;
    this->ArrayOfCreatures = new creature[N];
    
    for (int curCreature = 0; curCreature < N; curCreature++)
    {
        srand(time(NULL));
        int randNum = rand() % 2;

        if (randNum == 0)
        {
            bad_creature bad;
            this->ArrayOfCreatures[curCreature] = bad;
        }
        else if (randNum == 1)
        {
            good_creature good;
            this->ArrayOfCreatures[curCreature] = good;
        }
    }
}