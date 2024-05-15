#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

class Card {
	std::string number;
	std::string suit;

public:
	void printCard() {
		std::cout << Card::number << " of " << Card::suit << std::endl;
	}

};

class Deck {
	std::vector<Card> deck;

public:
	Deck& generateDeck() {
		std::vector<std::string> numbers = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
		std::vector<std::string> suits = {"Hearts", "Diamonds", "Clubs", "Spades"};

		for (auto suit : suits) {
			for (auto number : numbers) {
				deck.deck.push_back({number, suit});
			}
		}

		return *this;
	}

	Deck& shuffleDeck() {
		std::random_shuffle(deck.deck.begin(), deck.deck.end());

		return *this;
	}

	std::shared_ptr<Card> takeCard() {
		if (deck.deck.empty()) {
			return nullptr;
		}

		std::shared_ptr<Card> card = std::make_shared<Card>(deck.deck.back());

		deck.deck.pop_back();

		return card;
	}

};

int main() {
	Deck deck;

	deck.generateDeck().shuffleDeck();

	for (std::shared_ptr<Card> card = deck.takeCard(); card != nullptr; card = deck.takeCard()) {
		card->printCard();
	}

	return 0;
}
