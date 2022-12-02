#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <iterator>
#include "Poker.h"

int main(int argc, const char *argv[])
{
    Deck mydeck;
    PokerGame mypoker;

    mydeck.filDeck(); // Remplissage du Deck
    mydeck.shuffleDeck(); // On Mélange le Deck
    // mydeck.showDeck();
    mypoker.DrawCard(mydeck.deck); // On pioche les 5 cartes et on dit qui a gagné
    return 0;
}