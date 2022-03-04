#pragma once

#include "Card.h";

namespace Euchre {
	class Shuffler
	{
	public:
		void swapElement(Card arr[], int i, int j);
		int randomLocation(int min, int max);
		void shuffleElement(Card arr[], int size);
	};
}

