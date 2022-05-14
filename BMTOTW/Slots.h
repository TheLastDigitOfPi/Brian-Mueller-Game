#pragma once
#include <iostream>
#include <time.h>
#include <fstream>
#include <random>
using namespace std;
class Slots
{
private:
	string type = "None";
	int LandSlot = -1, LandPrice = -1, Willingness = -1, EstimatedValue = -1, MoneyInvested = 0, OfferDelay = 0;
	bool Unlocked = false;
public:
	
	Slots()
	{}
	int getLandSlot()
	{
		return LandSlot;
	}
	void setLandSlot(int LS)
	{
		LandSlot = LS;
	}
	int getWillingness()
	{
		return Willingness;
	}
	void setWillingness(int W)
	{
		Willingness = W;
	}
	int getLandPrice()
	{
		return LandPrice;
	}
	void setLandPrice(int LP)
	{
		LandPrice = LP;
	}
	int getEstimatedValue()
	{
		return EstimatedValue;
	}
	void setEstimatedValue(int EV)
	{
		EstimatedValue = EV;
	}
	int getMoneyInvested()
	{
		return MoneyInvested;
	}
	void setMoneyInvested(int MI)
	{
		MoneyInvested = MI;
	}
	int getOfferDelay()
	{
		return OfferDelay;
	}
	void setOfferDelay(int OD)
	{
		OfferDelay = OD;
	}
	bool getUnlocked()
	{
		return Unlocked;
	}
	void setUnlocked(bool U)
	{
		Unlocked = U;
	}
	string getType()
	{
		return type;
	}
	void setType(string t)
	{
		type = t;
	}
	virtual void updateValues() {}
	friend ostream& operator << (ostream& os, Slots& obj)
	{
		os << obj.getLandPrice() << " ";
		os << obj.getWillingness() << " ";
		os << obj.getEstimatedValue() << " ";
		os << obj.getOfferDelay() << " ";
		return os;
	}
	friend istream& operator >> (istream& is, Slots& obj)
	{
		int x;
		is >> x;
		obj.setLandPrice(x);
		is >> x;
		obj.setWillingness(x);
		is >> x;
		obj.setEstimatedValue(x);
		is >> x;
		obj.setOfferDelay(x);
		return is;
	}
};

class GenericEnemy : public Slots
{
private:
	int difficulty;
public:
	GenericEnemy():Slots()
	{
		srand(time(NULL));
		setType("GenericEnemy");
		setLandPrice(0);
		setWillingness(rand() % 20 + 40);
		setDifficulty(0);
		setUnlocked(false);
		setOfferDelay(0);
	}
	friend ostream& operator << (ostream& os, GenericEnemy& obj)
	{
		os << obj.getLandPrice() << " ";
		os << obj.getWillingness() << " ";
		os << obj.getEstimatedValue()<< " ";
		os << obj.getOfferDelay() << " ";
		return os;
	}
	friend istream& operator >> (istream& is, GenericEnemy& obj)
	{
		int x;
		is >> x;
		obj.setLandPrice(x);
		is >> x;
		obj.setWillingness(x);
		is >> x;
		obj.setEstimatedValue(x);
		is >> x;
		obj.setOfferDelay(x);
		return is;
	}
	void SetValues()
	{
		double x = (rand() % 60 + 70)/100;
		//Willingness = 100 - 15 * difficulty;
		setLandPrice((pow(difficulty,2) * 500 + 1000));
		setEstimatedValue(ceil((-2.3 * getWillingness() + 315) / 100 * getLandPrice()));
		
	}
	void updateValues()
	{
		if (getWillingness() > 100)
		{
			setWillingness(100);
		}
		if (getWillingness() < 0)
		{
			setWillingness(0);
		}
		setEstimatedValue(ceil((-2.3 * getWillingness() + 315) / 100 * getLandPrice()));
	}
	int getDifficulty()
	{
		return difficulty;
	}
	void setDifficulty(int d)
	{
		difficulty = d;
	}
};

class CowGuy : public Slots
{
public:
	CowGuy() :Slots()
	{
		setType("CowGuy");
		setLandPrice(0);
		setWillingness(rand() % 20 + 40);
	}
	friend ostream& operator << (ostream& os, CowGuy& obj)
	{
		os << obj.getLandPrice() << " ";
		os << obj.getWillingness() << " ";
		os << obj.getEstimatedValue() << " ";
		os << obj.getOfferDelay() << " ";
		return os;
	}
	friend istream& operator >> (istream& is, CowGuy& obj)
	{
		int x;
		is >> x;
		obj.setLandPrice(x);
		is >> x;
		obj.setWillingness(x);
		is >> x;
		obj.setEstimatedValue(x);
		is >> x;
		obj.setOfferDelay(x);
		return is;
	}
	void SetValues()
	{
		double x = rand() % 60 + 70;
		x = x / 100;
		setLandPrice(rand() % 20000 + 15000);
		setEstimatedValue(floor(x * getLandPrice()));
	}
	void updateValues()
	{
		if (getWillingness() > 100)
		{
			setWillingness(100);
		}
		if (getWillingness() < 0)
		{
			setWillingness(0);
		}
		setEstimatedValue(ceil((-2.3 * getWillingness() + 315) / 100 * getLandPrice()));
	}
};

class BritishRoyalty : public Slots
{
private:
public:
	BritishRoyalty() : Slots()
	{
		setType("BritishRoyalty");
		setLandPrice(0);
		setWillingness(0);
	}
	friend ostream& operator << (ostream& os, BritishRoyalty& obj)
	{
		os << obj.getLandPrice() << " ";
		os << obj.getWillingness() << " ";
		os << obj.getEstimatedValue() << " ";
		os << obj.getOfferDelay() << " ";
		return os;
	}
	friend istream& operator >> (istream& is, BritishRoyalty& obj)
	{
		int x;
		is >> x;
		obj.setLandPrice(x);
		is >> x;
		obj.setWillingness(x);
		is >> x;
		obj.setEstimatedValue(x);
		is >> x;
		obj.setOfferDelay(x);
		return is;
	}
	void SetValues()
	{
		double x = rand() % 60 + 70;
		x = x / 100;
		setLandPrice(rand() % 15 + 10);
		setEstimatedValue(floor(x * getLandPrice()));
	}
};

class Rednecks : public Slots
{
private:
public:
	Rednecks() :Slots()
	{
		setType("Rednecks");
		setLandPrice(0);
		setWillingness(rand() % 20 + 40);
	}
	friend ostream& operator << (ostream& os, Rednecks& obj)
	{
		os << obj.getLandPrice() << " ";
		os << obj.getWillingness() << " ";
		os << obj.getEstimatedValue() << " ";
		os << obj.getOfferDelay() << " ";
		return os;
	}
	friend istream& operator >> (istream& is, Rednecks& obj)
	{
		int x;
		is >> x;
		obj.setLandPrice(x);
		is >> x;
		obj.setWillingness(x);
		is >> x;
		obj.setEstimatedValue(x);
		is >> x;
		obj.setOfferDelay(x);
		return is;
	}
	void SetValues()
	{
		double x = 70 + (rand() % 60);
		x = x / 100;
		setLandPrice(rand() % 3000 + 2000);
		setEstimatedValue(floor(x * getLandPrice()));
	}
	void updateValues()
	{
		if (getWillingness() > 100)
		{
			setWillingness(100);
		}
		if (getWillingness() < 0)
		{
			setWillingness(0);
		}
		setEstimatedValue(ceil((-2.3 * getWillingness() + 315) / 100 * getLandPrice()));
	}
};

class ASU : public Slots
{
private:
public:
	ASU() :Slots()
	{
		setType("ASU");
		setLandPrice(0);
		setWillingness(0);
	}
	friend ostream& operator << (ostream& os, ASU& obj)
	{
		os << obj.getLandPrice() << " ";
		os << obj.getWillingness() << " ";
		os << obj.getEstimatedValue() << " ";
		os << obj.getOfferDelay() << " ";
		return os;
	}
	friend istream& operator >> (istream& is, ASU& obj)
	{
		int x;
		is >> x;
		obj.setLandPrice(x);
		is >> x;
		obj.setWillingness(x);
		is >> x;
		obj.setEstimatedValue(x);
		is >> x;
		obj.setOfferDelay(x);
		return is;
	}
	void SetValues()
	{
		double x = (rand() % 60) + 70;
		x = x / 100;
		setLandPrice(rand() % 200 + 300);
		setEstimatedValue(floor(x * getLandPrice()));
		
	}
};

class EmptySlot : public Slots
{
private:
public:
	EmptySlot() :Slots()
	{
		setType("EmptySlot");
		setEstimatedValue(1000);
		setLandPrice(1000);
		setWillingness(0);
	}

	friend ostream& operator << (ostream& os, EmptySlot& obj)
	{
		os << obj.getLandPrice() << " ";
		os << obj.getWillingness() << " ";
		os << obj.getEstimatedValue() << " ";
		os << obj.getOfferDelay() << " ";
		return os;
	}
	friend istream& operator >> (istream& is, EmptySlot& obj)
	{
		int x;
		is >> x;
		obj.setLandPrice(x);
		is >> x;
		obj.setWillingness(x);
		is >> x;
		obj.setEstimatedValue(x);
		is >> x;
		obj.setOfferDelay(x);
		return is;
	}
	
	
};

class GCU : public Slots
{
private:
public:
	GCU() :Slots()
	{
		setUnlocked(true);
		setType("GCU");
		setLandPrice(0);
		setWillingness(0);
	}
	friend ostream& operator << (ostream& os, GCU& obj)
	{
		os << obj.getLandPrice() << " ";
		os << obj.getWillingness() << " ";
		os << obj.getEstimatedValue() << " ";
		os << obj.getOfferDelay() << " ";
		return os;
	}
	friend istream& operator >> (istream& is, GCU& obj)
	{
		int x;
		is >> x;
		obj.setLandPrice(x);
		is >> x;
		obj.setWillingness(x);
		is >> x;
		obj.setEstimatedValue(x);
		is >> x;
		obj.setOfferDelay(x);
		return is;
	}
	
};

