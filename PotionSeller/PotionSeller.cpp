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


int main()
{
	//character riches, measured in D0$Hs
	int pDosh = 2500;
	int mDosh = 5000;

	int quantity = 0;							//user input quantity of items to buy/sell
	int iDebug = 0;

	bool test = false;							//DEBUG do loop stopper
	bool buySell = false;						//buySell = true when player is making purchase, false when player is selling
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
		
		PrintStock(item, mStock);

		cout << endl << endl << endl;

		cout << "EnoughStock() Testing:\n\n";

		cout << EnoughStock(item[0], 10, mStock);

		iDebug++;
		if (iDebug == 1)																												//DEBUG do loop count
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
	string tempItem = "";

	cout << "Current Merchant Stock:\n";
	for (int i = 0; i < 8; i++)
	{
		tempItem = item[i];

		int tempCount = ItemCounter(tempItem, stock);
		/* Same as ItemCounter()
		for (int j = 0; j < stock.size(); j++)
		{
			if (stock[j] == tempItem)
			{
				tempCount++;
			}
		}
		*/
		
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


void Transfer(const bool& buySell, const string& item, const int& quantity, vector<string>& mStock, vector<string>& pStock)		//Moves a number of items to owner from other character in trade
{
	string tempItem = item;
	int tempCount = 0;

	if (buySell)
	{

	}
	else
	{

	}

	for (int i = 0; i < tempCount; i++)
	{
		if (buySell)
		{
			//move from mStock to pStock
		}
		else
		{
			//move from pStock to mStock
		}
	}


}




bool OwnerCheck(const bool& buySell, const int& item_price, const int& quantity, int& pDosh, int& mDosh)							//Overload - checks the owners Dosh amounts
{
	return false;
}


void StockList(const vector<string>& mStock)																				//prints the current merchant stock;
{
	cout << "The merchant's current stock is:\n\n";

	for (unsigned int i = 0; i < mStock.size(); i++)
	{
		

	}
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
