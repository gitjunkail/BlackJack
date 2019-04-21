#include <iostream>
#include <time.h>
#include <vector>

void EndGameCalculation(int player_number,  int player_total, int dealer_total)
{
	if (dealer_total > 21 || player_total > dealer_total)
	{
		std::cout << "Player " << player_number << " Won!\n";
	}
	else if (dealer_total > player_total)
	{
		std::cout << "Player " << player_number << " Lost!\n";
	}
	else if (player_total = dealer_total)
	{
		std::cout << "Player " << player_number << " is tie with the Dealer!\n";
	}
}

//? decks of cards
//4 types: diamonds, clubs, hearts, spades
//13 cards; ace, two, three, four, five, six, seven, eight, nine, ten, jack, queen, king
//3d array?

class Players
{
public:
	int total;

	void Play(int& ace)
	{
		int card = rand() % 10 + 1; //1 to 10
		if (card == 1)
		{
			ace++;
			total += 11;
			std::cout << "you got an ace! your total is now ";
		}
		else
			total += card;

		if (total > 21 && ace > 0)
		{
			ace--;
			total -= 10;
			std::cout << "...\nace value changed from 11 to 1, your total is now: " << total << "\n";
		}

		std::cout << total << "\n";
	}
};

int main()
{
	//start seeding for randomness
	srand((unsigned int)time(NULL));

    std::cout << "Welcome to Black Jack\n"; 
	int ace = 0;
	int amount_of_players = 0;

	std::cout << "How Many Players? ";
	std::cin >> amount_of_players;
	amount_of_players += 1; //add dealer into players, dealer is array 0
	std::vector<Players> player(amount_of_players);

	//Player rule: Must have less than 22 and more than the Dealer
	for (int player_number = 1; player_number < amount_of_players; player_number++)
	{
		char player_continue;
		do {

			std::cout << "\nPlayer " << player_number << ": ";
			player[player_number].Play(ace);
			if (player[player_number].total == 21)
			{
				player_continue = 'n';
			}
			else if (player[player_number].total < 22)
			{
				std::cout << "Player " << player_number << ": deal another card? Y or N? ";
				std::cin >> player_continue;
			}
			else
			{
				std::cout << "Player " << player_number << ": Bust! You lose!\n";
				break;
			}
		} while (player_continue == 'y' || player_continue == 'Y');
	}

	ace = 0;

	//Dealer rule: Must have more than 16
	do {
		std::cout << "Dealer: ";
		player[0].Play(ace);
	} while (player[0].total < 17);

	for (int player_number = 1; player_number < amount_of_players; player_number++)
	{
		EndGameCalculation(player_number, player[player_number].total, player[0].total);
	}

	return 0;
}