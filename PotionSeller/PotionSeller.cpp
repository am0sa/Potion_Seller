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

int PrintStock(string item[], int priceList[], const vector<string>(&stock));

bool EnoughStock(string item, int quantity, vector<string>& _Stock);

bool EnoughDosh(string item, string(itemList[]), int count, int prices[], int& _dosh, int& buySell);

void Transfer(string item, int count, vector<string>& takeFrom, vector<string>& giveTo);


int main()
{
	int pDosh = 2500;							//Player Dosh
	int mDosh = 5000;							//Merchant Dosh
	int buySell = 0;							//Holds the total cost for a purchase of x amount of items
	int quantity = 0;							//user input quantity of items to buy/sell
	int iDebug = 0;								//Debug loop index
	int choice1 = 0;								//Holds the players menu choices
	int choice2 = 0;								//Item Choice for purchase
	int choice3 = 0;								//Quantity to purchase/sell
	int choice4 = 0;								//Proceed with purchase/sale if equals 1
	int retry = 0;								//Int used for cin validation
	int tempCheck = 0;

	bool test = false;							//DEBUG do loop stopper
	string owner[] = { "merchant" , "player" }; //function input

	string search = "";

	//List of all game items and prices
	string item[8] = { "Healing", "Poison", "Antidote", "Phoenix", "Fortune", "Water", "Elixir", "Whiskey" };
	int prices[8] = {100, 80, 80, 1750, 1500, 100, 900, 120};

	//player and merchant inventory initialization
	vector<string> pStock(7, item[7]);
	vector<string> mStock(20, item[0]);

	//player and merchant inventory population
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
	int fees[] = { 10, 30, 100 };

	cout << "Welcome to Potion Seller's shop\nThe Potion Seller currently has:\n";

	PrintStock(item, prices, mStock);



	do
	{
		cout << "Player Dosh: $" << pDosh << endl;
		cout << "Merchant Dosh: $" << mDosh << endl << endl;

		cout << "What would you like to do?\nEnter '1' to see merchant inventory\nEnter '2' to Make a purchase\nEnter '3' to sell an item\nEnter '4' to exit\n";

		do
		{
			cout << "\nEnter a choice: ";
			cin >> choice1;

			retry = cin.fail();
			cin.clear();
			cin.ignore(std::numeric_limits<int>::max(), '\n');

			if (retry == 1)
			{
				cout << "Invalid Entry\n";
			}
			else if (choice1 > 4 || choice1 < 1)
			{
				cout << "Enter a number from 1 to 4\n";
			}

		} while (retry == 1 || choice1 > 4 || choice1 < 1);

		switch (choice1)
		{
			case 1: //See merchant stock again
				PrintStock(item, prices, mStock);

				cout << "Player Dosh: $" << pDosh << endl;

				break;

			case 2: //buy an item
				cout << "\nWhat would you like to buy?\nEnter a number from 1 to 8";

				do
				{
					cout << "\nEnter a choice: ";
					cin >> choice2;

					retry = cin.fail();
					cin.clear();
					cin.ignore(std::numeric_limits<int>::max(), '\n');

					if (retry == 1)
					{
						cout << "Invalid Entry\n";
					}
					else if (choice2 > 8 || choice2 < 1)
					{
						cout << "\nEnter a number from 1 to 8\n";
					}
					else
					{
						tempCheck = ItemCounter(item[(choice2 - 1)], mStock);
					}

					if (tempCheck <= 0)
					{
						cout << "\nSorry, that item is out of stock\nPlease choose again\n";
						retry = 1;
					}
				} while (retry == 1 || choice2 > 8 || choice2 < 1);


				do
				{
					cout << "\nThere are " << tempCheck << "x " << item[choice2-1] << " available\n";
					cout << "\nEnter a quantity to purchase: ";
					cin >> choice3;

					retry = cin.fail();
					cin.clear();
					cin.ignore(std::numeric_limits<int>::max(), '\n');

					if (retry == 1)
					{
						cout << "Invalid Entry\n";
					}
					else if (choice3 > tempCheck || choice3 < 1)
					{
						cout << "\nEnter a number from 1 to " << tempCheck <<"\n";
						retry = 1;
					}

					if (retry !=1 && (EnoughDosh(item[choice2-1], item, choice3, prices, pDosh, buySell)))
					{
						cout << "\nYou can afford this item. \nEnter '0' to cancel and '1' to continue\nContinue with Purchase?:";

						do
						{
							cout << "\nEnter a choice: ";
							cin >> choice4;

							retry = cin.fail();
							cin.clear();
							cin.ignore(std::numeric_limits<int>::max(), '\n');

							if (retry == 1)
							{
								cout << "Invalid Entry\n";
							}
							else if (choice4 > 1 || choice4 < 0)
							{
								retry = 1;
								cout << "Enter '1' or '0' \n";
							}
						} while (retry == 1);
						cout << endl;
						if (choice4 == 1)
						{
							Transfer(item[choice2-1], choice3, mStock, pStock);
							pDosh -= buySell;
							mDosh += buySell;
						}
						else
						{
							break;
						}

					}
					else
					{
						retry = 1;
					}

				} while (retry == 1);

				break;

			case 3: //sell an item

				cout << "\nYour inventory:\n";

				PrintStock(item, prices, pStock);

				cout << "\nThis merchant charges $" << fees[1] << "per Item you sell.\n\nWhat would you like to Sell?\nEnter a number from 1 to 8\n";

				do
				{
					cout << "Enter a choice: ";
					cin >> choice2;

					retry = cin.fail();
					cin.clear();
					cin.ignore(std::numeric_limits<int>::max(), '\n');

					if (retry == 1)
					{
						cout << "\nInvalid Entry\n";
					}
					else if (choice2 > 8 || choice2 < 1)
					{
						cout << "\nEnter a number from 1 to 8\n";
					}
					else
					{
						tempCheck = ItemCounter(item[(choice2 - 1)], pStock);
					}

					if (tempCheck <= 0)
					{
						cout << "\nSorry, you can't sell what you dont have.\nPlease choose again\n";
						retry = 1;
					}
					
				} while (retry == 1 || choice2 > 8 || choice2 < 1);


				do
				{
					cout << "\nThere are " << tempCheck << "x " << item[choice2 - 1] << " available\n";
					cout << "Enter a quantity to sell: ";
					cin >> choice3;

					retry = cin.fail();
					cin.clear();
					cin.ignore(std::numeric_limits<int>::max(), '\n');

					if (retry == 1)
					{
						cout << "Invalid Entry\n";
					}
					else if (choice3 > tempCheck || choice3 < 1)
					{
						cout << "Enter a number from 1 to " << tempCheck << "\n";
						retry = 1;
					}

					if (retry != 1 && (EnoughDosh(item[choice2 - 1], item, choice3, prices, mDosh, buySell)))
					{
						cout << "\nPotion Seller can afford this item. \nEnter '0' to cancel and '1' to continue\nContinue with Sale?:";

						buySell -= (choice3 * fees[1]);

						do
						{
							cout << "\nEnter a choice: ";
							cin >> choice4;
							cout << endl;
							retry = cin.fail();
							cin.clear();
							cin.ignore(std::numeric_limits<int>::max(), '\n');

							if (retry == 1)
							{
								cout << "Invalid Entry\n";
							}
							else if (choice4 > 1 || choice4 < 0)
							{
								retry = 1;
								cout << "Enter '1' or '0' \n";
							}
						} while (retry == 1);
						cout << endl;
						if (choice4 == 1)
						{
							Transfer(item[choice2 - 1], choice3, pStock, mStock);
							mDosh -= buySell;
							pDosh += buySell;
						}
						else
						{
							break;
						}

					}
					else
					{
						retry = 1;
					}
				} while (retry == 1);

				break;

			case 4: //exit program
				cout << "\nThanks for shoppping!\n";

				cout << "Player Dosh: $" << pDosh << endl;

				cout << "\nYour inventory now has:\n";

				PrintStock(item, prices, pStock);

				return 0;
				break;

			default:
				cout << "Your choice is invalid. Please choose '1', '2' or '3'\n";
				break;
		}



		iDebug++;
		if (choice1 == 4)
		{
			test = false;
			cout << endl << endl;
		}
		else
		{
			test = true;
		}
	} while (test);
	return 0;
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

int PrintStock(string item[], int priceList[], const vector<string>(&stock))
{
	cout << endl;
	for (int i = 0; i < 8; i++)
	{
		int tempCount = ItemCounter(item[i], stock);
		cout << i+1 << "- "<< item[i] << " x" << tempCount << ",\t$" << priceList[i] << " each\n";
	}

	cout << endl << endl;

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
