#include <iostream>
#include <string>
using namespace std;

class creature
{
        string name;
    
    protected:
        int estimatedLifespan;

    public:
        creature(int L);
        bool is_a_zombie();
        void clone(int);
        void beat();
        void bless();
};

creature::creature(int L)
{
    estimatedLifespan = L;
}

bool creature::is_a_zombie()
{
    if (estimatedLifespan > 0)
        return false;
    return true;
}

void creature::clone(int creature)
{
    
}

void creature::beat()
{
    estimatedLifespan--;
}

void creature::bless()
{
    estimatedLifespan++;
}

class good_creature : public creature
{
    public:
        good_creature();
        void bless(int, int, int);
        bool is_a_good();
};

void good_creature::bless(int pos, int good_thrsh, int N)
{
    creature::bless();
    if (estimatedLifespan >= good_thrsh)
        clone(pos + 1);
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

void bad_creature::bless(int pos, int bad_thrsh, int N)
{
    creature::bless();
    bool notAZombie = false;
    int addToPos = 1;
    while (!notAZombie)
    {
        if (!is_a_zombie)
            notAZombie = true;
        
        clone(pos + addToPos);
        addToPos++;
    }
}

bool bad_creature::is_a_good()
{
    return false;
}

struct good_struct
{
    good_creature goodCreature;
    int position;
};

struct bad_struct
{
    bad_creature badCreature;
    int position;
};

class creature_society
{
        int creaturesOnSociety = 0, goodCreatures = 0, badCreatures = 0, N, good_thrsh, bad_thrsh;
        string firstCreaturePosition;

        good_struct* ArrayOfGoodCreatures;
        bad_struct* ArrayOfBadCreatures;

    public:
        creature_society(int, int, int);
        void beat(int);
        void bless(int);
};

creature_society::creature_society(int N, int good_thrsh, int bad_thrsh)
{
    this->N = N;
    this->good_thrsh = good_thrsh;
    this->bad_thrsh = bad_thrsh;
    good_struct* tempgood = new good_struct[N];
    bad_struct* tempbad = new bad_struct[N];
    
    for (int curCreature = 0; curCreature < N; curCreature++)
    {
        srand(time(NULL));
        int randNum = rand()%2;

        if (randNum == 1)
        {
            good_creature good;
            tempgood[curCreature].goodCreature = good;
            tempgood[curCreature].position = curCreature;
            goodCreatures++;

            if (curCreature == 0)
                firstCreaturePosition = "good";
        }
        else if (randNum == 2)
        {
            bad_creature bad;
            tempbad[curCreature].badCreature = bad;
            tempbad[curCreature].position = curCreature;
            badCreatures++;

            if (curCreature == 0)
                firstCreaturePosition = "bad";
        }
    }

    ArrayOfGoodCreatures = new good_struct[goodCreatures];
    ArrayOfBadCreatures = new bad_struct[badCreatures];

    for (int curCreature = 0; curCreature < N; curCreature++)
    {
        if (tempgood[curCreature].position == curCreature)
        {
            ArrayOfGoodCreatures[curCreature].goodCreature = tempgood[curCreature].goodCreature;
            ArrayOfGoodCreatures[curCreature].position = tempgood[curCreature].position;
        }
        else if (tempbad[curCreature].position == curCreature)
        {
            ArrayOfBadCreatures[curCreature].badCreature = tempbad[curCreature].badCreature;
            ArrayOfBadCreatures[curCreature].position = tempbad[curCreature].position;
        }
    }

    delete [] tempgood;
    delete [] tempbad;
}

void creature_society::beat(int i)
{
    for (int curCreature = 0; curCreature < N; curCreature++)
    {
        if (ArrayOfGoodCreatures[curCreature].position == i)
        {
            ArrayOfGoodCreatures[curCreature].goodCreature.beat();
            curCreature = N;
        }
        else if (ArrayOfBadCreatures[curCreature].position == i)
        {
            ArrayOfBadCreatures[curCreature].badCreature.beat();
            curCreature = N;
        }
    }
}

void creature_society::bless(int i)
{
    for (int curCreature = 0; curCreature < N; curCreature++)
    {
        if (ArrayOfGoodCreatures[curCreature].position == i)
        {
            ArrayOfGoodCreatures[curCreature].goodCreature.bless(curCreature, good_thrsh, N);
            curCreature = N;
        }
        else if (ArrayOfBadCreatures[curCreature].position == i)
        {
            ArrayOfBadCreatures[curCreature].badCreature.bless(curCreature, bad_thrsh, N);
            curCreature = N;
        }
    }
}   