#ifndef ENTITY_H
#define ENTITY_H

//Any living thing in the demo game.
class Entity
{
    public:
        Entity(int health=100);
    protected:
    private:
        int health;
};
//Hostile Entity.
class Enemy: public Entity{
    public:
        Enemy(int);
        virtual ~Enemy()=0; //Virtual, each derivative class of Enemy must have its own implementation for the destructor.
        virtual void attack()=0; //Virtual, each derivative class of Enemy must have its own attack type.
        Entity* getTarget();
        void setTarget();
    protected:
        Entity *target; //Pointer to the entity that this enemy will attack.
};
//Monster class - derivative of Enemy.
class Monster: public Enemy{
    public:
        Monster(int);
        ~Monster();
        void attack(); //Will be implemented in Enemy.cpp
        void bite();
        void claw();
        void stomp();
};
//Ninja class - derivative of Enemy.
class Ninja: public Enemy{
    public:
        Ninja(int);
        ~Ninja();
        void attack(); // Will be implemented in Enemy.cpp
        void slash();
        void shuriken();
        void chop();
};
#endif // ENTITY_H
