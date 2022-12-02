#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include "Card.h"

//Creation de la classe Deck
class Deck
{
private:
    const std::string spades{u8"\u2660"}; // Logo pour pike
    const std::string treffle{u8"\u2663"}; // Logo pour treffles
    const std::string hearts{u8"\u2665"}; // Logo pour coeur
    const std::string diamonds{u8"\u2666"}; // Logo pour carreaux

public:
    // Constructor
    Deck();
    // Deconstruteur
    ~Deck();
    // Creation d'un tableau de Card appeller "deck"
    std::vector<Card> deck;
    // Function pour remplir le deck
    void filDeck();
    // Function pour voir le deck au complet (juste pour si la création marche bien)
    void showDeck();
    // Function pour mélanger le deck
    void shuffleDeck();
};