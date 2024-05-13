#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Card {
	std::string number;
	std::string suit;
};

struct Deck {
	std::vector<Card> deck;
};

Deck generateDeck() {
	Deck deck;
	
	std::vector<std::string> numbers = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
	std::vector<std::string> suits = {"Hearts", "Diamonds", "Clubs", "Spades"};

	for (auto suit : suits) {
		for (auto number : numbers) {
			deck.push_back({number, suit});
		}
	}

	return deck;
}

void shuffleDeck(Deck& deck) {
	std::random_shuffle(deck.begin(), deck.end());
}

std::shared_ptr<Card> takeCard(Deck& deck) {
	if (deck.empty()) {
		return nullptr;
	}

	std::shared_ptr<Card> card = std::make_shared<Card>(deck.back());

	deck.pop_back();

	return card;
}

void printCard(const Card& card) {
	std::cout << card.number << " of " << card.suit << std::endl;
}

int main() {
	Deck deck = generateDeck();

	shuffleDeck(deck);

	for (std::shared_ptr<Card> card = takeCard(deck); card != nullptr; card = takeCard(deck)) {
		printCard(*card);
	}

	return 0;
}