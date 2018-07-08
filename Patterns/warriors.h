//#ifndef WARRIORS_H
//#define WARRIORS_H

//#include <iostream>
//#include <assert.h>

//enum class warrior_ID
//{
//    Infantryman_ID,
//    Archer_ID,
//    Horseman_ID
//};

//class Warrior
//{
//public:
//    virtual void info() = 0;
//    virtual ~Warrior(){}
//};


//class Infantryman: public Warrior
//{
//public:
//    void info() { std::cout << "Infantryman" << std::endl; }
//};

//class Archer: public Warrior
//{
//public:
//    void info() { std::cout << "Archer" << std::endl; }

//};

//class Horseman: public Warrior
//{
//public:
//    void info() { std::cout << "Horseman" << std::endl; }
//};


////  фабрики объектов
//class Factory
//{
//public:
//    virtual Warrior* createWarrior() = 0;
//    virtual ~Factory(){}
//};

//class InfantryFactory : public Factory
//{
//public:
//    virtual Warrior* createWarrior()
//    {
//        return new Infantryman;
//    }
//};


//class ArcherFacroty : public Factory
//{
//public:
//    virtual Warrior* createWarrior()
//    {
//        return new Archer;
//    }
//};

//class HorsemanFactory: public Factory
//{
//public:
//    virtual Warrior* createWarrior()
//    {
//        return new Horseman;
//    }
//};


//#endif // WARRIORS_H


