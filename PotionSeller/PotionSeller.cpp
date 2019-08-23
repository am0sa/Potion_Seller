// Potion Seller.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
using namespace std;

#include <cmath>
#include <iostream>
#include <vector>

int main()
{

	//character riches, measured in D0$H
	int pDosh = 2500;
	int mDosh = 5000;

	int quantity = 0;							//user input quantity of items to buy/sell
	int i = 0;

	bool test = false;							//DEBUG do loop stopper
	bool buySell = false;						//buySell = true when player is making purchase, false when player is selling
	string owner[] = { "merchant" , "player" }; //function input


	//List of all game items and prices
	string item[] = { "Healing", "Poison", "Antidote", "Phoenix", "Luck", "Water", "Divine_Blessing", "Rare_Coins" };

	//player + merchant stock lists
	vector<string> pStock;
	vector<string> mStock;

	//merchant purchase discrimination and sell price categories
	enum merchantFee { Low, Normal, High };

	//function prototypes
	{
		int ItemCounter(const string & owner, const string & item, const vector<string> & p_m_stock);									//Returns the count of an item in the owners stock

		int BuyPrice(const string & item);																							//Returns the price of an item

		bool OwnerCheck(bool buySell, const string & item, const int& quantity, vector<string> & mStock, vector<string> & pStock);	//Checks the owners stock for item quantity

		bool OwnerCheck(bool buySell, const int& item_price, const int& quantity, int& pDosh, int& mDosh);							//Overload - checks the owners Dosh amounts

		void Transfer(bool buySell, const string & item, const int& quantity, vector<string> & mStock, vector<string> & pStock);		//Moves a number of items to owner from other character in trade

		void Transfer(bool buySell, const int& item_price, const int& quantity, int& mDosh, int& pDosh);							//Overload to move Dosh from owner to other character in trade

		void StockList(const vector<string> & mStock);																				//prints the current merchant stock;
	}
	cout << "Potion Seller!\n";

	//the main item selling and buying takes place here
	do
	{
		cout << "Potion Seller loop: " << i + 1 << endl;








		i++;
		if (i == 3)																												//DEBUG do loop count
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



int ItemCounter(const string& owner, const string& item, const vector<string>& p_m_stock)									//Returns the count of an item in the owners stock
{
	return 0;
}


int BuyPrice(const string& item)																							//Returns the price of an item
{
	return 0;
}

bool OwnerCheck(const bool& buySell, const string& item, const int& quantity, vector<string>& mStock, vector<string>& pStock)	//Checks the owners stock for item quantity
{
	int count = 0;

	for (int i = 0; int i < mStock.size(); i++)
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

	int tempCount = ItemCounter();

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

	int tempCount = ItemCounter();

	for (int i = 0; i < tempCount; i++)
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

	for ( int i = 0; int i < mStock.size(); i++)
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
