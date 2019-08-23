// Potion Seller.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
using namespace std;

#include <cmath>
#include <iostream>
#include <vector>
#include <array>
#include <string>

int ItemCounter(string search, const vector<string>(&mStock));									//Returns the count of an item in the owners stock
int FullCost(string search, string item, int prices);
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
	string item[] = { "Healing", "Poison", "Antidote", "Phoenix", "Luck", "Water", "Divine_Blessing", "Rare_Coins" };
	int prices[8] = {20, 30, 40, 1750, 1500, 5, 900, 125};

	//player + merchant stock lists ***NEED TO BE GENERATED***
	vector<string> pStock(3, item[3]);
	vector<string> mStock(5, item[0]);

	//merchant purchase discrimination and sell price categories
	enum merchantFee { Low, Normal, High };

																								//Returns the price of an item

		/* NEEDS UPDATES
		
		bool OwnerCheck(bool buySell, const string & item, const int& quantity, vector<string> & mStock, vector<string> & pStock);	//Checks the owners stock for item quantity

		bool OwnerCheck(bool buySell, const int& item_price, const int& quantity, int& pDosh, int& mDosh);							//Overload - checks the owners Dosh amounts

		void Transfer(bool buySell, const string & item, const int& quantity, vector<string> & mStock, vector<string> & pStock);		//Moves a number of items to owner from other character in trade

		void Transfer(bool buySell, const int& item_price, const int& quantity, int& mDosh, int& pDosh);							//Overload to move Dosh from owner to other character in trade

		void StockList(const vector<string> & mStock);																				//prints the current merchant stock;
		*/
	cout << "Potion Seller!\n";

	mStock.push_back(item[3]);
	//the main item selling and buying takes place here
	do
	{
		cout << "Potion Seller loop: " << iDebug + 1 << "\t" <<endl;

		for (int i = 0; i < 8; i++) {
			int temp = FullCost(item[3], item[i], prices[i]);

			if (temp != 0) {
				//do something
				cout << "TEST";
			}
		}
		
		iDebug++;
		if (iDebug == 3)																												//DEBUG do loop count
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

//Overloaded to return the count of an item in the players stock

//** to end

int FullCost(string search, string item, int prices)																							//Returns the price of an item
{
		if (search == item)
		{
			cout << prices;
			return prices;
		}

		return 0;
}

bool OwnerCheck(const bool& buySell, const string& item, const int& quantity, vector<string>& mStock, vector<string>& pStock)	//Checks the owners stock for item quantity
{
	int count = 0;

	for (unsigned int i = 0; i < mStock.size(); i++)
	{
		if (mStock[i] == item)
		{
			count++;
		}

	}

	
	return false;
}


bool OwnerCheck(const bool& buySell, const int& item_price, const int& quantity, int& pDosh, int& mDosh)							//Overload - checks the owners Dosh amounts
{
	return false;
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


void Transfer(const bool& buySell, const int& item_price, const int& quantity, int& mDosh, int& pDosh)							//Overload to move Dosh from owner to other character in trade
{
	int tempDosh = item_price;

	for (int i = 0; i < quantity; i++)
	{
		if (buySell)
		{
			//move from pDosh to mDosh
		}
		else
		{
			//move from mDosh to pDOsh
		}
	}

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
