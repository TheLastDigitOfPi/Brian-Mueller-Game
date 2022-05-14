//Daniel Davenport
//This Code is my own
#include <iostream>
#include "Slots.h"
#include <string>
#include <time.h>
#include <random>
#include <Windows.h>
#include <fstream>
#include <vector>
#include "Player.h"
using namespace std;

int Students = 80, Turn = 1, Money = 5000, Income = 300, NumGE = 30, NumCG = 4, NumRN = 3, NumBR = 8, TotalSlots = 300,
numASU = 9, NumGCU = 4, CostToInvest = 100, InvBooks = 0, InvBuild = 0, InvCFA = 0, ASUStudents = 100;
bool PlayingGame, choicemade = false, canBribe = true, adminMode = false, canOffer = true, bodyGaurd = false;
GenericEnemy *GE = new GenericEnemy[NumGE];
CowGuy *CG = new CowGuy[NumCG];
Rednecks *RN = new Rednecks[NumRN];
BritishRoyalty *BR = new BritishRoyalty[NumBR];
ASU AllASU[9];
GCU StartGCU[100];
EmptySlot *ES = new EmptySlot[TotalSlots];
vector <Slots*> AllSlots;
Player player;

//Display Map as a grid
void showMap() 
{
	string X[100];
	for (int i = 0; i < 100; i++)
	{ 
		if (AllSlots[i]->getType() == "GenericEnemy" && AllSlots[i]->getUnlocked() == true)
		{
			X[i] = " E";
		}
		else if (AllSlots[i]->getType() == "GCU" && AllSlots[i]->getUnlocked() == true)
		{
			X[i] = " G";
		}
		else if (AllSlots[i]->getType() == "ASU" && AllSlots[i]->getUnlocked() == true)
		{
			X[i] = " A";
		}
		else if (AllSlots[i]->getType() == "BritishRoyalty" && AllSlots[i]->getUnlocked() == true)
		{
			X[i] = " B";
		}
		else if (AllSlots[i]->getType() == "Rednecks" && AllSlots[i]->getUnlocked() == true)
		{
			X[i] = " R";
		}
		else if (AllSlots[i]->getType() == "EmptySlot" && AllSlots[i]->getUnlocked() == true)
		{
			X[i] = " V";
		}
		else if (AllSlots[i]->getType() == "CowGuy" && AllSlots[i]->getUnlocked() == true)
		{
			X[i] = " C";
		}
		else
		{
			X[i] = " X";
		}
	}

	cout << "  0 1 2 3 4 5 6 7 8 9";
	for (int i = 0; i < 100; i++)
	{
		if (i % 10 == 0)
		{
			cout << endl << i/ 10;
		}
		
		if (X[i] == " E")
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		}
		else if (X[i] == " G")
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		}
		else if (X[i] == " A")
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		}
		else if (X[i] == " B")
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		}
		else if (X[i] == " R")
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}
		else if (X[i] == " V")
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		}
		else if (X[i] == " C")
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		}
		cout << X[i];
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		
		if (i == 9){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11); 
			cout << "		    Key        ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		}
		else if (i == 19){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8); 
			cout << "         E = Generic Enemy  "; 
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		}
		else if (i == 29){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13); 
			cout << "         G = GCU Land       "; 
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		}
		else if (i == 39){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); 
			cout << "         A = ASU            "; 
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		}
		else if (i == 49){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); 
			cout << "         B = British Royalty"; 
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		}
		else if (i == 59){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			cout << "         R = Redneck        "; 
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		}
		else if (i == 69){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			cout << "         V = Vacant Land    "; 
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		}
		else if (i == 79){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
			cout << "         C = Cow Guy        "; 
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		}
		
		
	}
		/*cout << "  0 1 2 3 4 5 6 7 8 9" <<
		endl << "0" << X[0] << X[1] << X[2] << X[3] << X[4] << X[5] << X[6] << X[7] << X[8] << X[9] << "		    Key        " <<
		endl << "1" << X[10] << X[11] << X[12] << X[13] << X[14] << X[15] << X[16] << X[17] << X[18] << X[19] << "         E = Generic Enemy  " <<
		endl << "2" << X[20] << X[21] << X[22] << X[23] << X[24] << X[25] << X[26] << X[27] << X[28] << X[29] << "         G = GCU Land       " <<
		endl << "3" << X[30] << X[31] << X[32] << X[33] << X[34] << X[35] << X[36] << X[37] << X[38] << X[39] << "         A = ASU            " <<
		endl << "4" << X[40] << X[41] << X[42] << X[43] << X[44] << X[45] << X[46] << X[47] << X[48] << X[49] << "         B = British Royalty" <<
		endl << "5" << X[50] << X[51] << X[52] << X[53] << X[54] << X[55] << X[56] << X[57] << X[58] << X[59] << "         R = Redneck        " <<
		endl << "6" << X[60] << X[61] << X[62] << X[63] << X[64] << X[65] << X[66] << X[67] << X[68] << X[69] << "         V = Vacant Land    " <<
		endl << "7" << X[70] << X[71] << X[72] << X[73] << X[74] << X[75] << X[76] << X[77] << X[78] << X[79] << "         C = Cow Guy        " <<
		endl << "8" << X[80] << X[81] << X[82] << X[83] << X[84] << X[85] << X[86] << X[87] << X[88] << X[89] <<
		endl << "9" << X[90] << X[91] << X[92] << X[93] << X[94] << X[95] << X[96] << X[97] << X[98] << X[99];*/
}
//Get the distance between two slots
int GetDistance(int Slot1, int Slot2)
{
	int distance;
	distance = (abs((floor(Slot1 / 10)) - (floor(Slot2 / 10)))) + abs(((Slot1 % 10) - (Slot2 % 10)));
	return distance;
}
//Set the difficulty for generic enemies based off their distnace from GCU
void SetGenericEnemyDifficulty()
{
	for (int i = 0; i < NumGE;i++)
	{
		int x[4] = { GetDistance(GE[i].getLandSlot(), StartGCU[0].getLandSlot()),
		GetDistance(GE[i].getLandSlot(), StartGCU[1].getLandSlot()),
		GetDistance(GE[i].getLandSlot(), StartGCU[2].getLandSlot()),
		GetDistance(GE[i].getLandSlot(), StartGCU[3].getLandSlot()) };
		if (min(min(x[0], x[1]), min(x[2], x[3])) < 3)
		{
			GE[i].setDifficulty(1);
		}
		else if (min(min(x[0], x[1]), min(x[2], x[3])) > 2 && 5 > min(min(x[0], x[1]), min(x[2], x[3])))
		{
			GE[i].setDifficulty(2);
		}
		else if (min(min(x[0], x[1]), min(x[2], x[3])) > 4 && 7 > min(min(x[0], x[1]), min(x[2], x[3])))
		{
			GE[i].setDifficulty(3);
		}
		else if (min(min(x[0], x[1]), min(x[2], x[3])) > 6)
		{
			GE[i].setDifficulty(4);
		}
		else
		{
			GE[i].setDifficulty(69);
		}
	}

}
//Fill the map for a new game
void fillMap()
{
	int i = 0;
	#pragma region Set All Slots to Empty Slots
	while (i < 100)
	{
		ES[i].setLandSlot(i);
		//AllSlots[i] = ES[i];
		AllSlots.push_back(&ES[i]);
		i++;
	}
#pragma endregion
	
	#pragma region Set All GCU Slots
	i = 0;
	int FirstGCUSlot;
	int x = 0;
	int RandSlot;
	while (x < NumGCU)
	{
		RandSlot = rand() % 100;
		if (RandSlot < 90 && RandSlot %10 != 9 && AllSlots[RandSlot]->getType() == "EmptySlot")
		{
			StartGCU[RandSlot].setLandSlot(RandSlot);
			AllSlots[RandSlot] = &StartGCU[RandSlot];
			FirstGCUSlot = RandSlot;
			x++;
			StartGCU[RandSlot].setLandSlot(RandSlot +1);
			AllSlots[RandSlot +1] = &StartGCU[RandSlot + 1];
			x++;
			StartGCU[RandSlot].setLandSlot(RandSlot + 10);
			AllSlots[RandSlot + 10] = &StartGCU[RandSlot + 10];
			x++;
			StartGCU[RandSlot].setLandSlot(RandSlot + 11);
			AllSlots[RandSlot + 11] = &StartGCU[RandSlot + 11];
			x++;
		}
	}
#pragma endregion
	
	#pragma region Set All ASU Slots
x = 0;
	while (x < numASU)
	{
		RandSlot = rand() % 100;
		if (RandSlot > 10 && RandSlot %10 != 9 && RandSlot%10 !=0 && RandSlot < 90 && AllSlots[RandSlot]->getType() == "EmptySlot" && GetDistance(AllSlots[RandSlot]->getLandSlot(), AllSlots[FirstGCUSlot]->getLandSlot()) > 5)
		{
			AllASU[x].setLandSlot(RandSlot);
			AllASU[x].SetValues();
			AllSlots[RandSlot] = &AllASU[x];
			x++;
			AllASU[x].setLandSlot(RandSlot + 9);
			AllASU[x].SetValues();
			AllSlots[RandSlot + 9] = &AllASU[x];
			x++;
			AllASU[x].setLandSlot(RandSlot - 9);
			AllASU[x].SetValues();
			AllSlots[RandSlot - 9] = &AllASU[x];
			x++;
			AllASU[x].setLandSlot(RandSlot +11);
			AllASU[x].SetValues();
			AllSlots[RandSlot + 11] = &AllASU[x];
			x++;
			AllASU[x].setLandSlot(RandSlot - 11);
			AllASU[x].SetValues();
			AllSlots[RandSlot - 11] = &AllASU[x];
			x++;
			AllASU[x].setLandSlot(RandSlot - 10);
			AllASU[x].SetValues();
			AllSlots[RandSlot - 10] = &AllASU[x];
			x++;
			AllASU[x].setLandSlot(RandSlot - 1);
			AllASU[x].SetValues();
			AllSlots[RandSlot - 1] = &AllASU[x];
			x++;
			AllASU[x].setLandSlot(RandSlot + 10);
			AllASU[x].SetValues();
			AllSlots[RandSlot + 10] = &AllASU[x];
			x++;
			AllASU[x].setLandSlot(RandSlot +1);
			AllASU[x].SetValues();
			AllSlots[RandSlot +1] = &AllASU[x];
			x++;

		}

	}
#pragma endregion
	
	#pragma region Set All Generic Enemy Slots
x = 0;
	while (x < NumGE)
	{
		RandSlot = rand() % 100;
		if (AllSlots[RandSlot]->getType() == "EmptySlot")
		{
				GE[x].setLandSlot(RandSlot);
				AllSlots[RandSlot] = &GE[x];
				x++;
		}
	}
	SetGenericEnemyDifficulty();
	for (int i = 0; i < NumGE; i++)
	{
		GE[i].SetValues();
		
	}
	for (int i = 0; i < 100; i++)
	{
		for (int x = 0; x < NumGE; x++)
		{
			if (AllSlots[i]->getLandSlot() == GE[x].getLandSlot())
			{
				AllSlots[i] = &GE[x];
			}
		}
		
	}
#pragma endregion
	
	#pragma region Set All British Royalty Slots
	x = 0;
	while (x < NumBR)
	{
		RandSlot = rand() % 100;
		if (AllSlots[RandSlot]->getType() == "EmptySlot")
		{
				BR[x].setLandSlot(RandSlot);
				BR[x].SetValues();
				AllSlots[RandSlot] = &BR[x];
				x++;
		}
	}
#pragma endregion
	
	#pragma region Set All Redneck Slots
x = 0;
	while (x < NumRN)
	{
		RandSlot = rand() % 100;
		if (AllSlots[RandSlot]->getType() == "EmptySlot")
		{
			RN[x].setLandSlot(RandSlot);
			RN[x].SetValues();
			AllSlots[RandSlot] = &RN[x];
			x++;
		}
	}
#pragma endregion
	
	#pragma region Set All CowGuy Slots
x = 0;
	while (x < NumCG)
	{
		RandSlot = rand() % 100;
		if (AllSlots[RandSlot]->getType() == "EmptySlot")
		{
			CG[x].setLandSlot(RandSlot);
			CG[x].SetValues();
			AllSlots[RandSlot] = &CG[x];
			x++;
		}
	}
	x = 0;
#pragma endregion

	#pragma region Output Number of Each Enemy Type Created
int NumberOfGE = 0, NumberofBR = 0, NumberofRN = 0, NumberofASU = 0, NumberofCG = 0, NumberofGCU = 0;
	for (int i = 0; i < 100; i++)
	{
		if (AllSlots[i]->getType() == "GenericEnemy")
		{
			NumberOfGE++;
		}
		if (AllSlots[i]->getType() == "BritishRoyalty")
		{
			NumberofBR++;
		}
		if (AllSlots[i]->getType() == "Rednecks")
		{
			NumberofRN++;
		}
		if (AllSlots[i]->getType() == "ASU")
		{
			NumberofASU++;
		}
		if (AllSlots[i]->getType() == "CowGuy")
		{
			NumberofCG++;
		}
		if (AllSlots[i]->getType() == "GCU")
		{
			NumberofGCU++;
		}
	}
#pragma region Debug
	/*
cout << endl << "Succesfully created "<< NumberOfGE << " Generic Enemy spots";
	cout << endl << "Succesfully created " << NumberofBR << " Britsh Royalty spots";
	cout << endl << "Succesfully created " << NumberofRN << " Redneck spots";
	cout << endl << "Succesfully created " << NumberofASU << " ASU spots";
	cout << endl << "Succesfully created " << NumberofCG << " Cow Guy spots";
	cout << endl << "Succesfully created " << NumberofGCU << " GCU spots";
	*/
#pragma endregion

	#pragma endregion
}
//Admin mode for unlocking full map
void UnlockFullMap()
{
	for (int i = 0; i < 100; i++)
	{
		AllSlots[i]->setUnlocked(true);
	}
}
//Show Slot Statistics for a given slot - shows more information if admin mode is enabled
void ShowSlotInfo(int in)
{
	
	if (in >= 0 && in < 100)
	{
		if (AllSlots[in]->getUnlocked() == true || adminMode == true)
		{
			if (AllSlots[in]->getType() == "GCU")
			{
				cout << endl << "Lopes Up!" << endl;
			}
			else
			{
				cout << endl << "Stats for slot number " << AllSlots[in]->getLandSlot() << endl << " Slot Type: " << AllSlots[in]->getType() << endl << "Estimated Value: " << AllSlots[in]->getEstimatedValue() << endl << "Willingness: " << AllSlots[in]->getWillingness() << endl;
				if (adminMode == true)
				{
					cout << "Land Price:" << AllSlots[in]->getLandPrice() << endl << "Offer Delay:" << AllSlots[in]->getOfferDelay() << endl;
				}
			}
			
			
		}
		else
		{
			cout << endl << "You have not unlocked that slot yet. Attack or investigate it to learn more" << endl;
		}

	}
	else
	{
		cout << endl << "Not a valid slot number" << endl;
	}
	cin.get();
}
//Show Slot Statistics for all slots - Only available to admin
void ShowAllSlotInfo()
{
	for (int i = 0; i < 100; i++)
	{
		cout << "Slot: " << AllSlots[i]->getLandSlot() << "  Type: " << AllSlots[i]->getType() << endl << " Est Value: " 
		<< AllSlots[i]->getEstimatedValue() << endl << "Price: " << AllSlots[i]->getLandPrice()
		<< endl << "Willingness: " << AllSlots[i]->getWillingness() << endl << "Offer Delay:" << AllSlots[i]->getOfferDelay() << endl;
	}
}
//Quickly change variables when saving and loading a game
void QuickSaveandLoad()
{
	player.setIncome(Income);
	player.setBodyGaurd(bodyGaurd);
	player.setCanBribe(canBribe);
	player.setMoney(Money);
	player.setTurn(Turn);
	player.setStudents(Students);
	player.setASUStudents(ASUStudents);
	player.setInvBooks(InvBooks);
	player.setInvBuild(InvBuild);
	player.setInvCFA(InvCFA);
	player.setNumASU(numASU);
	player.setNumGCU(NumGCU);
}
//Save the game to a file
void SaveGame()
{
	cout << endl << "Saving your game will End the Turn and stop the game, would you like to continue? Yes/No" << endl;
	string Continue;
	cin >> Continue;
	if (Continue == "Yes")
	{
		string SaveName;
		cout << "Name your save file (Ex: MySave1)";
		cin.get();
		getline(cin, SaveName);	
		ofstream outfile(SaveName + ".txt");
		QuickSaveandLoad();
		outfile << player.getTurn() << " " << player.getMoney() << " " << player.getIncome() << " " << player.getStudents() << " " << player.getASUStudents() << " " << player.getBodyGaurd()
			<< " " << player.getCanBribe() << " " << player.getInvBooks() << " "<< player.getInvBuild() << " "<< player.getInvCFA() << " " << player.getNumASU() << " " << player.getNumGCU();
		for (int i = 0; i < 100; i++)
		{
			outfile << endl << i << " " << AllSlots[i]->getType() << " " << AllSlots[i]->getUnlocked() << " ";
			outfile << *AllSlots[i];

		}
		cout << endl << "Successfuly Saved Game!" << endl;
		Sleep(2000);
		outfile.close();
		cout << endl << "Closing Game!" << endl;
		Sleep(3000);
		PlayingGame = false;
	}
	else
	{
		cout << "Canceling Save Game" << endl;
		cin.get();
	}
}
//Load the game from a chosen file
void LoadGame()
{
	string LoadName;
	cout << endl << "Enter the Save name you want to load (Ex: MySave1)" << endl;
	getline(cin, LoadName);
	ifstream inFile(LoadName + ".txt");
	if (!inFile)
	{
		cout << "Invalid File or File Name";
		choicemade = false;
	}
	else
	{	
		
		AllSlots.clear();
		for(int i = 0; i < 100;i++)
		{
			ES[i].setLandSlot(i);
			AllSlots.push_back(&ES[i]);
		}
		string x;
		int slotnum = 0;
		bool unlocked;
		inFile >> Turn >> Money >> Income >> Students >> ASUStudents >> bodyGaurd >> canBribe >> InvBooks >> InvBuild >> InvCFA >> numASU >> NumGCU;
		QuickSaveandLoad();
		
		for (int i = 0; i < 100; i++)
		{
			int z;
			inFile >> z;
			AllSlots[i]->setLandSlot(z);
			inFile >> x;
			inFile >> unlocked;
			AllSlots[i]->setType(x);
			AllSlots[i]->setUnlocked(unlocked);
			inFile >> *AllSlots[i];

		}
		cout << "Successfuly Loaded Game " << endl;
		PlayingGame = true;
	}
	
}
//Shows Options for program on start up
void showOptions()
{
	cout << endl << "Choose An Option" << endl << "Save Game" << endl << "Load Game" << endl << "Exit Game" << endl << "Cancel";
}
//Investigates a slot to unlock it for the user and to gain information about the slot
void InvestigateSlot(int SlotNum)
{
	if (AllSlots[SlotNum]->getUnlocked() == true)
	{
		cout << "That slot has already been revealed" << endl;
	}
	else if (AllSlots[SlotNum]->getUnlocked() == false)
	{
		AllSlots[SlotNum]->setUnlocked(true);
		cout << "You investigated a(n) " << AllSlots[SlotNum]->getType() << "space. For more information about space types: Enter 'Slot Types'" << endl;
	}
	else
	{
		cout << "You entered an invalid slot number, to try again: Enter 'Investigate'" << endl;
	}
	
}
//Starting a new game from the start up menu
void StartNewGame()
{
	fillMap();
	cout << endl;
	//UnlockFullMap();
	showMap();
	PlayingGame = true;
}
//Displays Rules as text
void Rules()
{
	cout << "                      Welcome to Brian Mueller Takes Over the World!" << endl;
	cout << endl << "              To play the game, spend each turn doing any of the following: " << endl << endl << "               Bribe Land Owners to lower their land prices considerably!"
	<< endl << "                Make offers to land owners to try and get their land!" << endl << "             Visit the Shop to purchase upgrades and increase your income!";
	cout << endl << endl << "   The goal of the game is to conquer all the slots of land in the lowest turns possible" << endl  << endl << "                                      Good Luck!" << endl;
}
//Display the welcome message and run correct functions for player input
void StartUpConsole()
{
	cout << "Welcome to Brian Mueller Takes Over the World!" << endl << "Please select one of the following options" << endl << endl;
	cout << "New Game" << "       Load Game" << "        Rules" << endl << endl;
	while (!choicemade)
	{
		string UserInput;
		getline(cin, UserInput);
		if(UserInput == "New Game")
		{
			choicemade = true;
			StartNewGame();
		}
		else if (UserInput == "Load Game")
		{
			choicemade = true;
			LoadGame();
		}
		else if (UserInput == "Rules")
		{
			Rules();

			cout << endl << "Please select one of the following options" << endl;
			cout << "New Game" << endl << "Load Game" << endl << "Rules" << endl;
		}
		else
		{
			cout << "Invalid Input" << endl;
			cout << endl << "Please select one of the following options" << endl;
			cout << "New Game" << endl << "Load Game" << endl << "Rules" << endl;
		}
	}
}
//Bribe a slot. Each slot will give a different response when trying to be bribed
void Bribe(int Slot)
{
		if (AllSlots[Slot]->getType() == "GenericEnemy")
		{
			cout << endl << "Enter a bribe amount:" << endl;
			int Bribe;
			cin >> Bribe;
			if (Money >= Bribe)
			{
				
				int Chance = rand() % 100 + 1;

				if (Chance <= 90 && Bribe > AllSlots[Slot]->getLandPrice() * 0.15)
				{
					cout << "The owners thank you for your generosity" << endl << "Willingness Increased!" << endl;
					Money = Money - Bribe;
					double x1 = Bribe;
					double x2 = AllSlots[Slot]->getLandPrice();
					int increasedWill = floor(80 * (x1 / x2));
					AllSlots[Slot]->setWillingness(AllSlots[Slot]->getWillingness() + increasedWill);
					cout << endl << "Generic Enemy New Willingness: " << AllSlots[Slot]->getWillingness() << endl << "An Increase of: " << increasedWill << endl;
					AllSlots[Slot]->updateValues();
					canBribe = false;
					cin.get();
				}
				else if (Chance > 90)
				{
					cout << "They are disgusted that you think a bribe can change their minds" << endl << "Willingness Decreased" << endl;
					AllSlots[Slot]->setWillingness(AllSlots[Slot]->getWillingness() - 20);
					AllSlots[Slot]->updateValues();
					canBribe = false;
				}

			}
			else if (Money < Bribe)
			{
				cout << "You cannot afford that bribe!" << endl;
			}
		}
		else if (AllSlots[Slot]->getType() == "CowGuy")
		{
			cout << endl << "Enter a bribe amount:" << endl;
			int Bribe;
			cin >> Bribe;
			if (Money >= Bribe)
			{
				int Retaliate;
				Retaliate = rand() % 20 + 1;
				if (Retaliate < 8)
				{
				int Chance = rand() % 100 + 1;
				if (Chance <= 90 && Bribe > AllSlots[Slot]->getLandPrice() * 0.15)
					{
					cout << "The owners thank you for your generosity" << endl << "Willingness Increased!" << endl;
					Money = Money - Bribe;
					double x1 = Bribe;
					double x2 = AllSlots[Slot]->getLandPrice();
					int increasedWill = floor(80 * (x1 / x2));
					AllSlots[Slot]->setWillingness(AllSlots[Slot]->getWillingness() + increasedWill);
					cout << endl << "Cow Guy New Willingness: " << AllSlots[Slot]->getWillingness() << endl << "An Increase of: " << increasedWill << endl;
					AllSlots[Slot]->updateValues();
					canBribe = false;
					cin.get();
					}
				else if (Chance > 90)
					{
					cout << "They are disgusted that you think a bribe can change their minds" << endl << "Willingness Decreased" << endl;
					AllSlots[Slot]->setWillingness(AllSlots[Slot]->getWillingness() - 20);
					AllSlots[Slot]->updateValues();
					canBribe = false;
					}
				}
				else if (Retaliate > 7 && Retaliate < 13)
				{
					cout << "Cow Guy is not happy that you would try to get his land through bribes. " << endl <<
						"He attacks your students with cows, lowering your student count" << endl;
					cout << endl << "You lost " << ceil(Students * .2) << " Students" << endl;
					Students = ceil(Students * .8);
					canBribe = false;
					cin.get();
				}
				else if (Retaliate > 12)
				{
					cout << endl << "Cow Guy thinks bribing is disgusting. He takes this to the news, lowering your income!" << endl;
					cout << endl << "You lost " << ceil(Income *= .3) << " Income" << endl;
					Income = ceil(Income *= .7);
					canBribe = false;
					cin.get();
				}

			}
			else if (Money < Bribe)
			{
				cout << "You cannot afford that bribe!" << endl;
				cin.get();
			}
		}
		else if (AllSlots[Slot]->getType() == "BritishRoyalty")
		{
			cout << endl << "The British do not take bribes, how foolish of you" << endl;
			canBribe = false;
		}
		else if (AllSlots[Slot]->getType() == "Rednecks")
		{
			if (bodyGaurd == true)
			{
				cout << endl << "Enter a bribe amount:" << endl;
				int Bribe;
				cin >> Bribe;
				if (Money >= Bribe)
				{
					
					int Chance = rand() % 100 + 1;

					if (Chance <= 90 && Bribe > AllSlots[Slot]->getLandPrice() * 0.15)
					{
						cout << "The owners thank you for your generosity" << endl << "Willingness Increased!" << endl;
						Money = Money - Bribe;
						double x1 = Bribe;
						double x2 = AllSlots[Slot]->getLandPrice();
						int increasedWill = floor(80 * (x1 / x2));
						AllSlots[Slot]->setWillingness(AllSlots[Slot]->getWillingness() + increasedWill);
						cout << endl << "Redneck New Willingness: " << AllSlots[Slot]->getWillingness() << endl << "An Increase of: " << increasedWill << endl;
						AllSlots[Slot]->updateValues();
						canBribe = false;
						cin.get();
					}
					else if (Chance > 90)
					{
						cout << "They are disgusted that you think a bribe can change their minds" << endl << "Willingness Decreased" << endl;
						AllSlots[Slot]->setWillingness(AllSlots[Slot]->getWillingness() - 20);
						AllSlots[Slot]->updateValues();
						canBribe = false;
					}
				}
				else if (Money < Bribe)
				{
					cout << "You cannot afford that bribe!" << endl;
				}
			}
			else
			{
				cout << endl << "The Rednecks retailiate for you entering their land, face hospital fees! If only you had a body gaurd..." << endl;
				canBribe = false;
			}
		}
		else
		{
			cout << endl << "You cannot bribe this type of slot!" << endl;
			cin.get();
		}
	
	
}
//Make an offer on a slot. If the offer is accepted, the slot becomes a gcu slot
void Offer(int Slot)
{
	if (AllSlots[Slot]->getOfferDelay() == 0)
	{
		if (AllSlots[Slot]->getType() == "GenericEnemy")
		{
			cout << "How much would you like to offer?" << endl;
			int OfferAmount;
			cin >> OfferAmount;
			if (OfferAmount >= AllSlots[Slot]->getEstimatedValue())
			{
				cout << "The owners have accepted your deal!" << endl;
				Money = Money - OfferAmount;
				NumGCU++;
				AllSlots[Slot] = new GCU;
				player.setMyGCU(StartGCU[Slot], Slot);
			}
			else
			{
				cout << "The owners laugh at your offer, better luck next time" << endl;
				AllSlots[Slot]->setOfferDelay(AllSlots[Slot]->getOfferDelay() + 2);
			}
		}
		else if (AllSlots[Slot]->getType() == "CowGuy")
		{
			cout << "How much would you like to offer?" << endl;
			int OfferAmount;
			cin >> OfferAmount;
			int Retaliate;
			Retaliate = rand() % 20 + 1;
			if (Retaliate < 8)
			{
				if (OfferAmount >= AllSlots[Slot]->getEstimatedValue())
				{
					cout << "You offered " << OfferAmount << " and needed " << AllSlots[Slot]->getEstimatedValue() << endl;
					cout << "The owners have accepted your deal!" << endl;
					Money = Money - OfferAmount;
					NumGCU++;
					AllSlots[Slot] = new GCU;
					player.setMyGCU(StartGCU[Slot], Slot);
				}
				else
				{
					cout << "You offered " << OfferAmount << " and needed " << AllSlots[Slot]->getEstimatedValue() << endl;
					cout << "The owners laugh at your offer, try offering more next time!" << endl;
					AllSlots[Slot]->setOfferDelay(AllSlots[Slot]->getOfferDelay() + 2);
				}
			}
			else if (Retaliate > 7 && Retaliate < 13)
			{
				cout << endl << "Coy Guy does not like your offer. He retaliates, causing students to leave campus" << endl;
				cout << endl << "You lost " << ceil(Students * .2) << " Students!";
				Students = ceil(Students * .8);
				AllSlots[Slot]->setOfferDelay(AllSlots[Slot]->getOfferDelay() + 2);
			}
			else if (Retaliate > 12)
			{
				cout << endl << "The cows whisper into the Cow Guy's ears. They tell him not to trust you. He decides to keep his land and put signs all around saying how bad of a school you are" << endl;
				cout << endl << "You lost " << ceil(Income * .3) << " Income!" << endl;
				Income = ceil(Income * .7);
				AllSlots[Slot]->setOfferDelay(AllSlots[Slot]->getOfferDelay() + 2);
			}
			
		}
		else if (AllSlots[Slot]->getType() == "BritishRoyalty")
		{
			if (AllSlots[Slot]->getLandPrice() <= NumGCU)
			{
				cout << endl << "The British respect your power and give your their land" << endl;
			}
			else
			{
				cout << endl << "The British see your as inferior, they would never accept your money for their land" << endl;
				AllSlots[Slot]->setOfferDelay(2);
			}
		}
		else if (AllSlots[Slot]->getType() == "EmptySlot")
		{
			cout << "Empty Land Costs $1000 to purchase. Would you like to purchase this land? Yes/No" << endl;
			string UInput;
			cin >> UInput;
			if (UInput == "Yes")
			{
				if (Money >= 1000)
				{
					cout << endl << "Success! You have purchased this slot of land!" << endl;
					Money -= 1000;
					NumGCU++;
					AllSlots[Slot] = new GCU;
				}
				else if (Money < 1000)
				{
					cout << endl << "You do not have enough money to purchase this land!" << endl;
				}
				else
				{
					cout << endl << "Invalid Input" << endl;
				}
			}
		}
		else if (AllSlots[Slot]->getType() == "Rednecks")
		{
			if (bodyGaurd == true)
			{
				cout << "How much would you like to offer?" << endl;
				int OfferAmount;
				cin >> OfferAmount;
				if (OfferAmount >= AllSlots[Slot]->getEstimatedValue())
				{
					cout << "You offered " << OfferAmount << " and needed " << AllSlots[Slot]->getEstimatedValue() << endl;
					cout << "The owners have accepted your deal!" << endl;
					Money = Money - OfferAmount;
					NumGCU++;
					AllSlots[Slot] = new GCU;
					player.setMyGCU(StartGCU[Slot], Slot);
				}
				else
				{
					cout << "You offered " << OfferAmount << " and needed " << AllSlots[Slot]->getEstimatedValue() << endl;
					cout << "The owners laugh at your offer, better luck next time" << endl;
					AllSlots[Slot]->setOfferDelay(AllSlots[Slot]->getOfferDelay() + 2);
				}
			}
			else
			{
				cout << endl << "The Rednecks don't like intruders. You've been shot! You rush to the hospital and pay the hospital fee" << endl;
				cout << "You lost $2000!" << endl;
				Money -= 2000;
				AllSlots[Slot]->setOfferDelay(2);
			}
		}
		else if (AllSlots[Slot]->getType() == "ASU")
		{
			cout << endl << "Your students go to war, each side fighting valiantly..." << endl;
			cout << "." << endl;
			Sleep(1000);
			cout << "." << endl;
			Sleep(1000);
			cout << "." << endl;
			Sleep(1000);
			if (Students / NumGCU > ASUStudents / numASU)
			{
				cout << "Your students fought greatly, and won the war! The ASU Land is ours!" << endl;
				ASUStudents -= ASUStudents / numASU;
				Students -= ASUStudents / numASU;
				numASU--;
				NumGCU++;
				AllSlots[Slot] = new GCU;
				player.setMyGCU(StartGCU[Slot], Slot);
				cin.get();
			}
			else
			{
				cout << endl << "Your students were too few in number. ASU quickly took them over. The fight has been lost" << endl;
				Students -= ASUStudents / numASU;
				AllSlots[Slot]->setOfferDelay(2);
				cin.get();
			}
		}
		else
		{
			cout << endl << "You can't make offers for that land!" << endl;
			cin.get();
		}
	}
	else
	{
		cout << "You cannot make an offer on that slot for " << AllSlots[Slot]->getOfferDelay() << " turn(s)";
		cin.get();
	}
}
//Open the shop menu and respond to player commands
void Shop()
{
	cout << endl << "                                  Welcome to the Shop!" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	cout << "Upgrades:" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << "Body Gaurds";
	if (bodyGaurd)
	{
		cout << "     PURCHASED -"<< "A set of body gaurds to protect you on your quest of expansion" << endl;
	}
	else
	{
		cout << "     Cost: 10000 -" << "A set of body gaurds to protect you on your quest of expansion" << endl;
	}
	cout << endl << "Books";
	cout << "           Cost: 500 -" << "  Perfect for student education, incraese income by 100  YOU HAVE: " << InvBooks << endl;
	cout << endl << "Classrooms";
	cout << "      Cost: 1000 -" << " A nice learning environment that will surely make students happy. Increase income by 250  YOU HAVE: " << InvBuild << endl;
	cout << endl << "Chick Fil A";
	cout << "     Cost: 3000 -" << " It's Chick Fil A. What else do I have to say. Increase income by 1000 YOU HAVE: " << InvCFA << endl;
	cout << endl << "            Purchase - Purchase an Item     " << "Exit - Leave Shop" << endl;
	bool inShop = true;
	while (inShop == true)
	{
		cout << endl << "What would you like to do?" << endl;
		string Response;
		cin >> Response;
		if (Response == "Exit")
		{
			inShop = false;
		}
		else if (Response == "Purchase")
		{
			cout << endl << "What would you like to purchase?" << endl;
			cin.get();
			getline(cin, Response);
			if (Response == "Books")
			{
				if (Money >= 500)
				{
					cout << endl << "You purchased a set of books!" << endl;
					InvBooks++;
					Income += 100;
				}
				else
				{
					cout << endl << "You can't afford that!" << endl;
				}
			}
			else if (Response == "Classrooms")
			{
				if (Money >= 1000)
				{
					cout << endl << "You purchased a classroom!" << endl;
					InvBuild++;
					Income += 250;
				}
				else
				{
					cout << endl << "You can't afford that!" << endl;
				}
			}
			else if (Response == "Chick Fil A")
			{
				if (Money >= 3000)
				{
					cout << endl << "You purchased a Chick Fil A!" << endl;
					InvCFA++;
					Income += 1000;
				}
				else
				{
					cout << endl << "You can't afford that!" << endl;
				}
			}
			else
			{
				cout << "Invalid Response" << endl;
			}
			
		}
	}
}
//End the round, causing many variables to change such as money goes up based off income
void EndRound()
{
	Turn++;
	CostToInvest = 100;
	Students += NumGCU * 20;
	ASUStudents += numASU * 40;
	canBribe = true;
	Money += Income;

}
//Admin command to see all color options for the console
void ShowColorOptions()
{
	for (int i = 0; i < 256; i++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
		cout << "This color has the number" << i << endl;
	}
}
//Constantly gets user input and gives correct response while the player is playing the game
void PlayTheGame()
{
		string input = "";
		cout << endl << "Enter what you would like to do: Type help for a list of commands" << endl;
		getline(cin, input);
		if (input == "help")
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			cout << endl << "General commands:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			cout << endl << "help, " << "Rules, "<< "Show Map, " << "Stats, " << "Shop, " << "End Turn" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
			cout << endl << "Expansion Commands:" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			cout << "Investigate, Bribe, Offer, Slot Stats"<< endl;
		}
		else if (input == "Load Game")
		{
			LoadGame();
		}
		else if (input == "Save Game")
		{
			SaveGame();

		}
		else if (input == "Exit Game")
		{
			cout << "Are you sure you would like to exit? All unsaved progress will be lost! Reply with 'YES' or 'NO'" << endl;
			getline(cin, input);
			if (input == "YES")
			{
				PlayingGame = false;
			}
		}
		else if (input == "Show Map")
		{
			showMap();
		}
		else if (input == "Investigate")
		{
			if (Money > CostToInvest)
			{
				int slotnum;
				cout << "Which slot would you like to investigate?" << endl;
				cin >> slotnum;
				InvestigateSlot(slotnum);
				Money = Money - CostToInvest;
				CostToInvest *= 2;
				cin.get();

			}
			else
			{
				cout << "You don't have enough money to do that";
			}
		}
		else if (input == "Unlock Map")
		{
			UnlockFullMap();
		}
		else if (input == "New Game")
		{
			bool done = false;
			while(done == false)
			{
				string choice;
				cout << "Would you like to start a new game? WARNING: all unsaved data will be lost!" << endl << "Reply with 'YES' or 'NO'" << endl;
				getline(cin, choice);
				if (choice == "NO")
				{
					cout << "Canceling..." << endl;
					done = true;
				}
				else if (choice == "YES")
				{
					cout << "Starting New Game..." << endl;
					StartNewGame();
					done = true;
				}
				else
				{
					cout << "Invalid Input" << endl;
				}
			}
			
		}
		else if (input == "End Turn")
		{
			cout << endl << "End of turn " << Turn << endl;
			EndRound();
			cout << endl << "Turn " << Turn << endl;
		}
		else if (input == "Rules")
		{
			Rules();
		}
		else if (input == "Stats")
		{
			cout << endl << "Money: " << Money << endl << "Students: " << Students << endl << "Income: " << Income << endl;
		}
		else if (input == "Slot Stats")
		{
			int Slotnum;
			cout << "Enter the slot you want the stats for" << endl;
			cin >> Slotnum;
			ShowSlotInfo(Slotnum);
		}
		else if (input == "AdminMode")
		{
			cout << "Admin Mode set to true";
			adminMode = true;
		}
		else if (input == "Show Colors")
		{
			ShowColorOptions();
		}
		else if (input == "Slot Stats All")
		{
			ShowAllSlotInfo();
		}
		else if (input == "Bribe")
		{
			if (canBribe)
			{
				int Slot;
				cout << endl << "What slot would you like to bribe?" << endl;
				cin >> Slot;
				if (AllSlots[Slot]->getType() != "GCU" && AllSlots[Slot]->getUnlocked() == true)
				{
					Bribe(Slot);
				}
				else if (AllSlots[Slot]->getType() == "GCU")
				{
					cout << endl << "You cannot bribe your own land!" << endl;
				}
				else
				{
					cout << endl << "You have no unlocked that slot yet! Investigate it to unlock!" << endl;
				}
				
			}
			else
			{
				cout << "You can only bribe one slot each turn!" << endl;
			}
			
		}
		else if (input == "Offer")
		{
			int Slot;
			cout << endl << "What slot would you like to offer?" << endl;
			cin >> Slot;
			if (AllSlots[Slot]->getType() != "GCU" && AllSlots[Slot]->getUnlocked() == true)
			{
				Offer(Slot);
			}
			else if (AllSlots[Slot]->getType() == "GCU")
			{
				cout << endl << "You cannot make offers for your own land!" << endl;
			}
			else
			{
				cout << endl << "You have no unlocked that slot yet! Investigate it to unlock!" << endl;
			}	

		}
		else if (input == "Shop")
		{
			Shop();
		}
		else if (input == "Testing")
		{
			for (int i = 0; i < 100; i++)
			{
				cout << "Slot " << i << ": " << AllSlots[i]->getType() << endl;
			}
		}
		else 
		{
			cout << "Unknown Command '"<<  input << "', please try again" << endl;
		}
} 
//Main function that starts up the game and will close the game when finished
int main()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	srand(time(NULL));
	StartUpConsole();
	while (PlayingGame == true)
	{
		PlayTheGame();
	}
	
}
