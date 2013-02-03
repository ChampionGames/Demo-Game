#include "Entity.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

Entity::Entity(int hp)
{
    this->health=hp;
    this->dead=false;
}
int Entity::getHealth(){
    return this->health;
}
void Entity::setHealth(int hp){
    this->health=hp;
}
bool Entity::isDead(){
    return this->dead;
}
void Entity::setDead(bool b){
    this->dead = b;
}

Enemy::Enemy(int i):Entity(i){
    this->health=i;
}

Entity* Enemy::getTarget(){
    return this->target;
}

void Enemy::setTarget(Entity *e){
    this->target=e;
}


Monster::Monster(int i):Enemy(i){
    this->health=i;
}
void Monster::attack(){
    srand(time(0));

    switch(rand()%3){
    case 0:
        bite();
        break;
    case 1:
        claw();
        break;
    case 2:
        stomp();
    }
}
void Monster::bite(){
    system("cls");
    this->getTarget()->setHealth(this->getTarget()->getHealth() - 15);
    cout << "Monster used bite! Target's health is now " << this->getTarget()->getHealth() << endl;
    if(this->getTarget()->getHealth() <= 0){
        this->getTarget()->setDead(true);
    }
}
void Monster::claw(){
    system("cls");
    this->getTarget()->setHealth(this->getTarget()->getHealth() - 20);
     cout << "Monster used claw! Target's health is now " << this->getTarget()->getHealth() << endl;
     if(this->getTarget()->getHealth() <= 0){
        this->getTarget()->setDead(true);
    }
}
void Monster::stomp(){
    system("cls");
    this->getTarget()->setHealth(this->getTarget()->getHealth() - 30);
     cout << "Monster used stomp! Target's health is now " << this->getTarget()->getHealth() << endl;
     if(this->getTarget()->getHealth() <= 0){
        this->getTarget()->setDead(true);
    }
}


Ninja::Ninja(int i):Enemy(i){
        this->health=i;
}
void Ninja::attack(){
    srand(time(0));
    switch(rand()%3){
    case 0:
        slash();
        break;
    case 1:
        shuriken();
        break;
    case 2:
        chop();
    }
}
void Ninja::slash(){
    system("cls");
    this->getTarget()->setHealth(this->getTarget()->getHealth() - 30);
     cout << "Ninja used slash! Target's health is now " << this->getTarget()->getHealth() << endl;
     if(this->getTarget()->getHealth() <= 0){
        this->getTarget()->setDead(true);
    }
}
void Ninja::shuriken(){
    system("cls");
    this->getTarget()->setHealth(this->getTarget()->getHealth() - 20);
     cout << "Ninja used shuriken! Target's health is now " << this->getTarget()->getHealth() << endl;
     if(this->getTarget()->getHealth() <= 0){
        this->getTarget()->setDead(true);
    }
}
void Ninja::chop(){
    system("cls");
    this->getTarget()->setHealth(this->getTarget()->getHealth() - 15);
     cout << "Ninja used chop! Target's health is now " << this->getTarget()->getHealth() << endl;
     if(this->getTarget()->getHealth() <= 0){
        this->getTarget()->setDead(true);
    }
}


Player::Player(int i): Entity(i){
    this->health=i;
}
Entity* Player::getTarget(){
    return this->target;
}
void Player::setTarget(Entity *e){
    this->target=e;
}
void Player::punch(){
    system("cls");
    this->getTarget()->setHealth(this->getTarget()->getHealth() - 15);
    cout << "You used punch. Your enemy's health is now " << this->getTarget()->getHealth() << endl;
    if(this->getTarget()->getHealth() <= 0){
        this->getTarget()->setDead(true);
    }
}
void Player::kick(){
    system("cls");
    this->getTarget()->setHealth(this->getTarget()->getHealth() - 20);
    cout << "You used kick. Your enemy's health is now " << this->getTarget()->getHealth() << endl;
    if(this->getTarget()->getHealth() <= 0){
        this->getTarget()->setDead(true);
    }
}
void Player::slash(){
    system("cls");
    this->getTarget()->setHealth(this->getTarget()->getHealth() - 30);
    cout << "You used slash. Your enemy's health is now " << this->getTarget()->getHealth() << endl;
   if(this->getTarget()->getHealth() <= 0){
        this->getTarget()->setDead(true);
    }
}
