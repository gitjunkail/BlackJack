#include <iostream>		//cout & cin
#include <ctime>		//std::time
#include <vector>		//std::vector
#include <algorithm>	//std::random_shuffle

void EndGameCalculation(int player_number,  int player_total, int dealer_total)
{
	if (player_total < 22 && (dealer_total > 21 || player_total > dealer_total))
	{
		std::cout << "\nPlayer " << player_number << " Won!";
	}
	else if (dealer_total > player_total || player_total > 22)
	{
		std::cout << "\nPlayer " << player_number << " Lost!";
	}
	else if (player_total = dealer_total)
	{
		std::cout << "\nPlayer " << player_number << " is tie with the Dealer!";
	}
}

class DecksGenerator
{
public:
	std::vector<int> m_vi32_decks_of_cards;

	DecksGenerator(int how_many_decks)
	{
		for (int counter_decks = 0; counter_decks < how_many_decks; counter_decks++)
		{
			for (int counter_suit = 1; counter_suit <= 4; counter_suit++)
			{
				for (int counter_face = 1; counter_face <= 13; counter_face++)
				{
					if (counter_face == 1)
					{
						m_vi32_decks_of_cards.emplace_back(11);
					}
					else if (counter_face == 11 /*jack*/ || counter_face == 12 /*queen*/ || counter_face == 13 /*king*/)
					{
						m_vi32_decks_of_cards.emplace_back(10);
					}
					else
					{
						m_vi32_decks_of_cards.emplace_back(counter_face);
					}
				}
			}
		}

		std::cout << "\nshuffling deck(s)\n";
		std::random_shuffle(m_vi32_decks_of_cards.begin(), m_vi32_decks_of_cards.end());
		std::cout << "done shuffling deck(s)\n";
	}
};

class Players
{
public:
	int total;

	void Play(int& ace)
	{
		int card = rand() % 13 + 1; //1 to 13
		if (card == 1)
		{
			ace++;
			total += 11;
			std::cout << "you got an ace! your total is now ";
		}
		else if (card == 11 /*jack*/ || card == 12 /*queen*/ || card == 13 /*king*/ )
		{
			total += 10;
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
	srand((unsigned int)std::time(0));

	std::cout << "Welcome to Black Jack\n"; 
	int ace = 0;
	int amount_of_players = 0;
	int amount_of_decks = 0;


	std::cout << "How many players? ";
	std::cin >> amount_of_players;
	amount_of_players += 1; //Adds dealer into players, dealer is array 0
	std::vector<Players> player(amount_of_players);


	std::cout << "How many decks? ";
	std::cin >> amount_of_decks;
	DecksGenerator Decks(amount_of_decks);


	//Players rule: Must have less than 22 and more than the Dealer to win
	for (int player_number = 1; player_number < amount_of_players; player_number++)
	{
		char player_continue;
		do {

			std::cout << "\nPlayer " << player_number << ": ";
			player[player_number].Play(ace);
			if (player[player_number].total == 21) //Go to the next player if current player gets Black Jack
			{
				std::cout << "Player " << player_number << ": Black Jack! \n";
				break;
			}
			else if (player[player_number].total < 22) //Ask if the current player wants another card
			{
				std::cout << "Player " << player_number << ": deal another card? Y or N? ";
				std::cin >> player_continue;
			}
			else //Go to the next player if current player have more than 22 pts
			{
				std::cout << "Player " << player_number << ": Bust! You lose!\n";
				break;
			}
		} while (player_continue == 'y' || player_continue == 'Y'); //go to the next player if player do not want to continue

		ace = 0; //reset ace counter
	}


	//Dealer rule: Stop getting cards after having more than 16
	std::cout << "\n";
	do {
		std::cout << "Dealer: ";
		player[0].Play(ace);
	} while (player[0].total < 17);


	//End Game Calculation
	for (int player_number = 1; player_number < amount_of_players; player_number++)
	{
		EndGameCalculation(player_number, player[player_number].total, player[0].total);
	}

	return 0;
}