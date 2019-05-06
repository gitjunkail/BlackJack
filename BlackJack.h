#pragma once
#include <vector>		//std::vector

class BlackJack
{
public:
	void EndGameCalculation(const int& player_number, const int& player_total, const int& dealer_total);
	std::vector<int> DecksGenerator(const int& how_many_decks, const unsigned int& seed);
};

class Players
{
public:
	int total;

	void Play(const int& card, int& ace);
};
