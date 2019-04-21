#include <iostream>
#include <ctype.h>
#include <time.h>

int Dealer(int dealer_total)
{
	int dealer = rand() % 11 + 1;
	dealer_total = dealer + dealer_total;
	std::cout << "dealer " << dealer_total << "\n";

	return dealer_total;
}

int Player(int player_total)
{
	int player = rand() % 11 + 1;
	player_total = player + player_total;
	std::cout << "player " << player_total << "\n";

	return player_total;
}

void EndGameCalculation(int player_total, int dealer_total)
{

	if (player_total > 21) //dealer doesnt bust
	{
		std::cout << "Bust!\n";
	}
	else if (player_total > dealer_total)
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

//dealer rule: always have a minimum of 17
int main()
{
	//start seeding for randomness
	srand((unsigned int)time(NULL)); //static_cast<unsigned int>(time(NULL))

    std::cout << "Black Jack Game\n"; 
	int dealer_total = 0;
	int player_total = 0;
	char player_continue = 'y';


	while (player_continue == 'y')
	{
		player_total = Player(player_total);

		std::cout << "deal another card? Y or N? ";
		std::cin >> player_continue;
		player_continue = tolower(player_continue);
	}

	while (dealer_total < 17)
	{
		dealer_total = Dealer(dealer_total);
	}

	EndGameCalculation(player_total, dealer_total);

	return 0;
}