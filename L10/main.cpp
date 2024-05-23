#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

class Card {
	std::string number;
	std::string suit;

public:
	Card(std::string number, std::string suit) : number(number), suit(suit) {}

	void printCard() {
		std::cout << Card::number << " of " << Card::suit << std::endl;
	}

};

class Deck {
	std::vector<Card> cards;
	
	Deck& generateDeck() {
		const std::vector<std::string> numbers = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
		const std::vector<std::string> suits = {"Hearts", "Diamonds", "Clubs", "Spades"};

		for (auto suit : suits) {
			for (auto number : numbers) {
				cards.push_back({number, suit});
			}
		}

		return *this;
	}

public:
	Deck() {
		generateDeck();
		shuffleDeck();
	}

	Deck& shuffleDeck() {
		std::random_shuffle(cards.begin(), cards.end());

		return *this;
	}

	Card takeCard() {
		if (cards.empty()) {
			throw std::range_error("The deck is empty!")
		}

		Card card = cards.back();

		cards.pop_back();

		return card;
	}

};

int main() {
	Deck deck;

	try {
		for (Card card = deck.takeCard();; card = deck.takeCard()) {
			card.printCard();
		}
	} catch(...) {}

	return 0;
}
