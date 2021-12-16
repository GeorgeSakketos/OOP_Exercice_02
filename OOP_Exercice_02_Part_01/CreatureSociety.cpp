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
        virtual bool is_a_good();
        void clone(int);
        void beat();
        virtual void bless(int, int, int);
};

creature::creature(int L, string type)
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

void creature::bless(int N, int creature_pos, int thrsh)
{
    if (!is_a_zombie())
        estimatedLifespan++;
}

class good_creature : public creature
{
    public:
        good_creature();
        void bless(int, int, int);
        bool is_a_good();
};

void good_creature::bless(int N, int creature_pos, int good_thrsh)
{
    creature::bless(N, creature_pos, good_thrsh);
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
        bad_creature();
        void bless(int, int, int);
        bool is_a_good();
};

void bad_creature::bless(int N, int creature_pos, int bad_thrsh)
{
    creature::bless(N, creature_pos, bad_thrsh);
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

struct creatureInfo
{
    creature* Creature;
    int index;
};

class creature_society
{
        int creaturesOnSociety;
        creature* firstCreature;
        creatureInfo* ArrayOfCreatures;

    public:
        creature_society(int);
};

creature_society::creature_society(int N)
{
    creaturesOnSociety = 0;
    ArrayOfCreatures = new creatureInfo[N];

    for (int curCreature = 0; curCreature < N; curCreature++)
    {
        srand(time(NULL));
        int randNum = rand() % 2;

        if (randNum == 0)
        {
            bad_creature bad;
            ArrayOfCreatures[curCreature].Creature = &bad;
        }
        else
        {
            good_creature good;
            ArrayOfCreatures[curCreature].Creature = &good;
        }
    }
}
