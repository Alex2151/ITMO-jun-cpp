#ifndef ARMY_H
#define ARMY_H
#include <iostream>
#include <vector>

class Infantryman
{
public:
    virtual void info() = 0;
    virtual ~Infantryman() {}
};

class Archer
{
public:
    virtual void info() = 0;
    virtual ~Archer() {}
};

class Horseman
{
public:
    virtual void info() = 0;
    virtual ~Horseman() {}
};

class  ImperialInfantryman: public Infantryman
{
public:
   void info() {
     std::cout << " ImperialInfantryman" << std::endl;
   }

   virtual ~ImperialInfantryman()
   {
       std::cout << " ImperialInfantryman dead" << std::endl;
   }
};

class  ImperialHorseman: public Horseman
{
public:
   void info() {
     std::cout << " ImperialHorseman" << std::endl;
   }

   virtual ~ImperialHorseman()
   {
       std::cout << " ImperialHorseman dead" << std::endl;
   }
};


class  ImperialArcher: public Archer
{
public:
   void info() {
     std::cout << " ImperialArcher" << std::endl;
   }

   virtual ~ImperialArcher()
   {
       std::cout << " ImperialArcher dead" << std::endl;
   }
};



class StormcloaksInfantryman: public Infantryman
{
  public:
    void info() {
      std::cout << "StormcloaksInfantryman" << std::endl;
    }

    virtual ~StormcloaksInfantryman()
    {
        std::cout << " StormcloaksInfantryman dead" << std::endl;
    }
};

class StormcloaksArcher: public Archer
{
  public:
    void info() {
      std::cout << "StormcloaksArcher" << std::endl;
    }

    virtual ~StormcloaksArcher()
    {
        std::cout << " StormcloaksArcher dead" << std::endl;
    }
};

class StormcloaksHorseman: public Horseman
{
  public:
    void info() {
      std::cout << "StormcloaksHorseman" << std::endl;
    }

    virtual ~StormcloaksHorseman()
    {
        std::cout << " StormcloaksHorseman dead" << std::endl;
    }
};

// абстрактные фабрики воинов
class ArmyFactory
{
public:

    virtual Infantryman* createInfantryman() = 0;
    virtual Archer* createArcher() = 0;
    virtual Horseman* createHorseman() = 0;

    virtual ~ArmyFactory() {}
};


class ImperialArmyFactory: public ArmyFactory
{
public:
    virtual Infantryman* createInfantryman()
    {
        return new ImperialInfantryman;
    }

    virtual Archer* createArcher()
    {
        return new ImperialArcher;
    }

    virtual Horseman* createHorseman()
    {
        return new ImperialHorseman;
    }
};


class StormcloaksArmyFactory: public ArmyFactory
{
public:
    virtual Infantryman* createInfantryman()
    {
        return new StormcloaksInfantryman;
    }

    virtual Archer* createArcher()
    {
        return new StormcloaksArcher;
    }

    virtual Horseman* createHorseman()
    {
        return new StormcloaksHorseman;
    }
};


// Класс, содержащий всех воинов той или иной армии
class Army
{
  public:

   ~Army() {

      for(Infantryman* item : vi)
          delete item;
      for(Archer* item : va)
          delete item;
      for(Horseman* item : vh)
          delete item;
    }
    void info() {

        for(Infantryman* item : vi)
            item->info();
        for(Archer* item : va)
            item->info();
        for(Horseman* item : vh)
           item->info();
    }
    std::vector<Infantryman*> vi;
    std::vector<Archer*> va;
    std::vector<Horseman*> vh;
};


class Game
{
  public:
    Army* createArmy( ArmyFactory& factory ) {
        Army* p = new Army;
        p->vi.push_back( factory.createInfantryman());
        p->va.push_back( factory.createArcher());
        p->vh.push_back( factory.createHorseman());
        return p;
    }
};

#endif // ARMY_H
