#include <iostream>
#include <cstdlib>
#include "Entity.h"
#include <windows.h>
using namespace std;
int main(){
    Player p;
    Enemy *e;
    string enemy;
    cout << "Choose your enemy (monster/ninja):" << endl;
    while(enemy != "monster" && enemy != "ninja"){
        cin >> enemy;
    }
    if(enemy == "monster"){
        Monster m;
        e = &m;
        p.setTarget(e);
        m.setTarget(&p);
    }else{
        Ninja n;
        e = &n;
        p.setTarget(e);
        n.setTarget(&p);
    }
    bool valid = false;
    string cmd;
    cout << "Choose from the 3 available attacks below:\n\n";
    cout << "attack | damage" << endl;
    cout << "---------------" << endl;
    cout << "punch  | 15" << endl;
    cout << "kick   | 20" << endl;
    cout << "slash  | 30\n\n" << endl;
    while(cmd != "end"){
            cin >> cmd;
            if(cmd == "punch"){
                valid = true;
                p.punch();
                Sleep(1000);
            }else if(cmd == "kick"){
                valid = true;
                p.kick();
                Sleep(1000);
            }else if(cmd == "slash"){
                valid = true;
                p.slash();
                Sleep(1000);
            }else{
                valid = false;
            }
            if(valid){
                if(p.getTarget()->isDead()){
                    system("cls");
                    cout << "You Win!";
                    Sleep(2000);
                    return 0;
                }
                e->attack();
                Sleep(1000);
                cout << "Choose next attack: " << endl;
                if(e->getTarget()->isDead()){
                    system("cls");
                    cout << "Boo. You lose. :(";
                    Sleep(2000);
                    return 0;
                }
            }
    }
    return 0;
}
