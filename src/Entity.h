#ifndef ENTITY_H
#define ENTITY_H

class Entity
{
    public:
        Entity(int hp=100);
        int getHealth();
        void setHealth(int);
        void setDead(bool);
        bool isDead();
    protected:
        int health;
        bool dead;
};
class Enemy: public Entity{
    public:
        Enemy(int hp=100);
        virtual void attack()=0;
        Entity* getTarget();
        void setTarget(Entity*);
    protected:
        Entity *target;
};
class Monster: public Enemy{
    public:
        Monster(int hp = 100);
        void attack();
        void bite();
        void claw();
        void stomp();
};
class Ninja: public Enemy{
    public:
        Ninja(int hp = 100);
        void attack();
        void slash();
        void shuriken();
        void chop();
};
class Player: public Entity{
    public:
        Player(int hp=100);
        Entity* getTarget();
        void setTarget(Entity*);
        void kick();
        void punch();
        void slash();
    protected:
        Entity *target;
};
#endif // ENTITY_H
