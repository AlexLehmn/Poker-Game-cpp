#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include "Deck.h"

Deck::Deck()
{
    filDeck();
}

Deck::~Deck()
{
}

// Remplissage du deck
void Deck::filDeck()
{
    // Creation des cartes pike
    for (int j = 1; j < 15; j++)
    {
        deck.push_back(Card(j, spades));
    }
    // Creation des cartes treffles
    for (int j = 1; j < 15; j++)
    {
        deck.push_back(Card(j, treffle));
    }
    // Creation des carte coeurs
    for (int j = 1; j < 15; j++)
    {
        deck.push_back(Card(j, hearts));
    }
    // Creation des cartes carreaux
    for (int j = 1; j < 15; j++)
    {
        deck.push_back(Card(j, diamonds));
    }
}

// Fonction pour mélanger le deck avec la fonction suffle
void Deck::shuffleDeck()
{
    // Initialisation obligatoire pour utiliser suffle
    // Initialisation du ramdom
    std::random_device rd;
    std::mt19937 g(rd());

    // Shuffle fonction en cpp qui permet de mélanger
    std::shuffle(this->deck.begin(), this->deck.end(), g);
}

//          FONCTION TEST          //

// void Deck::showDeck()
// {
//     int count = 0;

//     for (int i{}; i < 52; i++)
//     {
//         Card temp(deck[i]);
//         std::cout << temp.getValue() << temp.getcolor() << " ";
//         if (i == 12 || i == 25 || i == 38)
//         {
//             std::cout << std::endl;
//         }
//     }
//     std::cout << std::endl;
// }