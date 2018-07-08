#ifndef OBSERVER_H
#define OBSERVER_H

#include <iostream>
#include <vector>

enum class Event
{
    kill_all,
    die_young
};

template <typename Entity>
class Observer
{
public:
    virtual ~Observer(){}

    virtual void onNotify(const Entity& entity, Event event) = 0;
};


template <typename Entity>
class Achievements: public Observer<Entity>
{
public:
    virtual void onNotify(const Entity &entity, Event event)
    {
        switch (event) {
        case Event::kill_all:
            //проверка что не было разблокирвано раньше
            std::cout << "Achievement kill all unlocked" << std:: endl;
            break;
        case Event::die_young:
            std::cout << "Achievement die young unlocked" << std:: endl;
            break;
        default:
            break;
        }
    }
};

template <typename Entity>
class Subject
{
public:
    void addObserver(Observer<Entity> *obs)
    {
        observers.push_back(obs);
//        return;
    }

    void removeObservers(Observer<Entity> *obs)
    {
        return;
    }

protected:
    void notify(const Entity& entery, Event event)
    {
        for(Observer<Entity>* obs : observers)
        {
            obs->onNotify(entery, event);
        }

    }

private:
    std::vector<Observer<Entity>*> observers;
};


class PhisicsEntity
{

};

class Phisics : public Subject<PhisicsEntity>
{
public:
    void updateState()
    {
        if (all_killed)
            notify(entity, Event::kill_all);
    }

private:
    bool all_killed = true;
    PhisicsEntity entity;
};


#endif // OBSERVER_H
