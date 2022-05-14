#include <iostream>
#include <time.h>
#include <fstream>
#include <random>
#include <vector>
#include "Slots.h"
using namespace std;

class Player
{
private:
	int Students = 50, Turn = 0, Money = 1000, Income = 50, numASU = 9, NumGCU = 4, InvBooks = 0, InvBuild = 0, InvCFA = 0, ASUStudents = 100;
	bool canBribe = true, bodyGaurd = false;
    GCU myGCU[100];
public:
	
public:
    int getStudents() const { return Students; }
    void setStudents(int Students) { this->Students = Students; }

    int getTurn() const { return Turn; }
    void setTurn(int Turn) { this->Turn = Turn; }

    int getMoney() const { return Money; }
    void setMoney(int Money) { this->Money = Money; }

    int getIncome() const { return Income; }
    void setIncome(int Income) { this->Income = Income; }

    bool getCanBribe() const { return canBribe; }
    void setCanBribe(bool canBribe) { this->canBribe = canBribe; }

    bool getBodyGaurd() const { return bodyGaurd; }
    void setBodyGaurd(bool bodyGaurd) { this->bodyGaurd = bodyGaurd; }

    GCU getMyGCU(int i) const { return myGCU[i]; }
    void setMyGCU(GCU myGCU, int i) { this->myGCU[i] = myGCU; }
    
    int getNumGCU() const { return NumGCU; }
    void setNumGCU(int NumGCU) { this->NumGCU = NumGCU; }

    int getInvBooks() const { return InvBooks; }
    void setInvBooks(int InvBooks) { this->InvBooks = InvBooks; }

    int getInvBuild() const { return InvBuild; }
    void setInvBuild(int InvBuild) { this->InvBuild = InvBuild; }

    int getInvCFA() const { return InvCFA; }
    void setInvCFA(int InvCFA) { this->InvCFA = InvCFA; }

    int getASUStudents() const { return ASUStudents; }
    void setASUStudents(int ASUStudents) { this->ASUStudents = ASUStudents; }

    int getNumASU() const { return numASU; }
    void setNumASU(int numASU) { this->numASU = numASU; }

    

};