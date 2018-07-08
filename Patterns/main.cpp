#include <iostream>
#include <vector>

#include "warriors.h"
#include "army.h"

#include "observer.h"

#include "delegate.h"

using namespace std;


int main()
{
//    vector<Warrior*> v;
//    v.push_back( Warrior::createWarrior( warrior_ID::Infantryman_ID));
//    v.push_back( Warrior::createWarrior( warrior_ID::Archer_ID));
//    v.push_back( Warrior::createWarrior( warrior_ID::Horseman_ID));

//    for(Warrior *w : v)
//        w->info();


//    InfantryFactory* infantry_factory = new InfantryFactory;
//    ArcherFacroty* archers_factory  = new ArcherFacroty ;
//    HorsemanFactory* cavalry_factory  = new HorsemanFactory ;

//    vector<Warrior*> v;
//    v.push_back(infantry_factory->createWarrior());
//    v.push_back(archers_factory->createWarrior());
//    v.push_back(cavalry_factory->createWarrior());

//    for(Warrior *w : v)
//        w->info();


//    Game game;
//    ImperialArmyFactory ra_factory;
//    StormcloaksArmyFactory ca_factory;

//    Army * imp_army = game.createArmy( ra_factory);
//    Army * storm_army = game.createArmy( ca_factory);

//    cout << "Imperial army:" << endl;
//    imp_army->info();
//    cout << endl;
//    cout << "Stormcloaks army:" << endl;
//    storm_army->info();
//    cout << endl;

//    delete imp_army;
//    delete storm_army;



//    Achievements<PhisicsEntity> *achiev = new Achievements<PhisicsEntity>;
//    Phisics *ph = new Phisics;
//    ph->addObserver(achiev);
//    ph->updateState();



    test();

    return 0;
}
