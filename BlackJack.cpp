#include <iostream>
#include <time.h>

//dealer rule: always have a minimum of 17
int main()
{
	//start seeding for randomness
	srand((unsigned int)time(NULL)); //static_cast<unsigned int>(time(NULL))

    std::cout << "Black Jack Game\n"; 
	int dealer = 0, dealer_total = 0;
	int player = 0, player_total = 0;
	char player_continue = ' ';


	dealer = rand() % 11 + 1;
	dealer_total = dealer + dealer_total;
	std::cout << "dealer " << dealer_total << "\n";

	player = rand() % 11 + 1;
	player_total = player + player_total;
	std::cout << "player " << player_total << "\n";


	std::cout << "continue? ";
	std::cin >> player_continue;
	while (player_continue == 'y')
	{
		player = rand() % 11 + 1;
		player_total = player + player_total;
		std::cout << "player " << player_total << "\n";

		std::cout << "continue? ";
		std::cin >> player_continue;
	}

	while (dealer_total < 17)
	{
		dealer = rand() % 11 + 1;
		dealer_total = dealer + dealer_total;
		std::cout << "dealer " << dealer_total << "\n";
	}

	if (player_total > 21)
	{
		std::cout << "bust!\n";
	}
	else if (player_total > dealer_total)
	{
		std::cout << "player win!\n";
	}
	else if (dealer_total > player_total)
	{
		std::cout << "dealer win!\n";
	}

	return 0;
}