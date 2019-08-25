// Potion Seller.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
using namespace std;

#include <cmath>
#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <algorithm>

int ItemCounter(string search, const vector<string>(&mStock));

int PrintStock(string item[], const vector<string>(&stock));

bool EnoughStock(string item, int quantity, vector<string>& _Stock);

bool EnoughDosh(string item, string(itemList[]), int count, int prices[], int& _dosh, int& buySell);

void Transfer(string item, int count, vector<string>& takeFrom, vector<string>& giveTo);


int main()
{
	//character riches, measured in D0$Hs
	int pDosh = 2500;
	int mDosh = 5000;
	int buySell = 0;

	int quantity = 0;							//user input quantity of items to buy/sell
	int iDebug = 0;

	bool test = false;							//DEBUG do loop stopper
	string owner[] = { "merchant" , "player" }; //function input

	string search = "";

	//List of all game items and prices
	string item[8] = { "Healing", "Poison", "Antidote", "Phoenix", "Luck", "Water", "Divine_Blessing", "Rare_Coins" };
	int prices[8] = {20, 30, 40, 1750, 1500, 5, 900, 125};

	//player and merchant inventory initialization
	vector<string> pStock(7, item[7]);
	vector<string> mStock(20, item[0]);

	//player and merchant inventory population and sorting
	for (int i = 0; i < 5; i++)
	{
		mStock.push_back(item[1]);
		mStock.push_back(item[2]);
		mStock.push_back(item[5]);
		mStock.push_back(item[5]);

		if (i%2 ==0)
		{
			mStock.push_back(item[1]);
			mStock.push_back(item[1]);
			mStock.push_back(item[6]);
			mStock.push_back(item[7]);
			mStock.push_back(item[7]);
		}
		else if (i%3 == 0)
		{
			pStock.push_back(item[2]);
			pStock.push_back(item[2]);
			pStock.push_back(item[5]);
			pStock.push_back(item[7]);
			pStock.push_back(item[7]);
		}
	}
	mStock.push_back(item[3]);
	mStock.push_back(item[4]);

	//merchant purchase discrimination and sell price categories
	enum merchantFee { Low, Normal, High };

	cout << "Potion Seller!\n\n";

	//the main item selling and buying takes place here
	do
	{
		cout << "Potion Seller loop: " << iDebug + 1 << "\t" <<endl<<endl;
		
		cout << "Merchant's Stock:\n";
		PrintStock(item, mStock);

		cout << "\nPlayer's Stock:\n";
		PrintStock(item, pStock);

		cout << endl << endl << endl;

		Transfer(item[0], 20, mStock, pStock);

		cout << "Out of stock test\nNew Merchant's Stock:\n";
		PrintStock(item, mStock);

		iDebug++;
		if (iDebug == 1)	//DEBUG do loop count
		{
			test = false;
			cout << endl << endl;
		}
		else
		{
			test = true;
		}
	} while (test);
}

int ItemCounter(string search, const vector<string>(&mStock))									//Returns the count of an item in the merchants stock
{
	int temp = 0;

	for (unsigned int i = 0; i < mStock.size(); i++)
	{
		if (mStock[i] == search)
		{
			temp++;
		}
	}
	return temp;
}

int PrintStock(string item[], const vector<string>(&stock))
{
	for (int i = 0; i < 8; i++)
	{
		int tempCount = ItemCounter(item[i], stock);
		cout << item[i] << "  x" << tempCount << endl;
	}
	return 0;
}

bool EnoughStock(string item, int quantity, vector<string>& _Stock)	//Checks the owners stock for item quantity before Transfer() can be used
{
	bool ans = false;

	if (ItemCounter(item, _Stock) >= quantity)
	{
		ans = true;
	}
	else
	{
		ans = false;
	}
	return ans;
}

bool EnoughDosh(string item, string (itemList[]), int count, int prices[], int &_dosh, int &buySell)	//Checks the buyers Do$h based on price and item to buy
{
	bool ans = false;
	int i = 0;
	int tempPrice = 0;
	buySell = 0;		//erase garbage values.

	for (; i < 8; i++)
	{
		if (item == itemList[i])
		{
			tempPrice = prices[i];
			break;
		}
	}

	if (_dosh >= (count * tempPrice))
	{
		buySell = (count * tempPrice);
		ans = true;
	}
	else
	{
		ans = false;
	}

	return ans;
}

void Transfer(string item, int count, vector<string>& takeFrom, vector<string>& giveTo)		//Moves a number of items to owner from other character in trade
{
	int initialItemCount = ItemCounter(item, takeFrom);
	int i = 0;
	int tracker = count;

	do
	{
		if (takeFrom[i] == item)
		{
			giveTo.push_back(takeFrom[i]);
			takeFrom.erase(takeFrom.begin()+i);
			tracker--;
		}
		
		i++;

		if (i >= takeFrom.size())
		{
			i = 0;
		}

	} while (tracker > 0);
}























































// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
