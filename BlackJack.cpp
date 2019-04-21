#include <iostream>
#include <time.h>

int Actor(int card_total, int& ace)
{
	int card = rand() % 10 + 1; //1 to 10
	if (card == 1)
	{
		ace++;
		card_total = 11 + card_total;
		std::cout << "you got an ace! your total is now ";
	}
	else
	card_total = card + card_total;

	if (card_total > 21 && ace > 0)
	{		
		ace--;
		card_total = card_total - 10;
		std::cout << "...\nace value changed from 11 to 1, your total is now: " << card_total << "\n";
	}

	std::cout << card_total << "\n";
	return card_total;
}

void EndGameCalculation(int player_total, int dealer_total)
{
	if (dealer_total > 21 || player_total > dealer_total)
	{
		std::cout << "Player Wins!\n";
	}
	else if (dealer_total > player_total)
	{
		std::cout << "Dealer Wins!\n";
	}
	else if (player_total = dealer_total)
	{
		std::cout << "Tie!\n";
	}
}

int main()
{
	//start seeding for randomness
	srand((unsigned int)time(NULL));

    std::cout << "Welcome to Black Jack\n"; 
	int ace = 0;
	int dealer_total = 0;
	int player_total = 0;
	char player_continue;

	//Player rule: Must have less than 22 and more than the Dealer
	do {
		std::cout << "Player: ";
		player_total = Actor(player_total, ace);

		if (player_total < 22)
		{
			std::cout << "deal another card? Y or N? ";
			std::cin >> player_continue;
		}
		else
		{
			std::cout << "Bust!\n";
			return 0;
		}

	} while (player_continue == 'y' || player_continue == 'Y');

	ace = 0;

	//Dealer rule: Must have more than 16
	do {
		std::cout << "Dealer: ";
		dealer_total = Actor(dealer_total, ace);
	} while (dealer_total < 17);

	EndGameCalculation(player_total, dealer_total);

	return 0;
}