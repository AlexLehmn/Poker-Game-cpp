#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include "Deck.h"

// Initialisation de tout les combinaisons possibles
enum Combination
{
    HighCard,
    Pair,
    twoPairs,
    Brelan,
    Suite,                  // Comme des chiffres mais on les écrits en lettres
    ColorFlush,
    Full,
    Carre,
    FullSuite,
    FlushRoyal
};

// Création Classe PokerGame héritant de la classe Deck pour reception les élements
class PokerGame : public Deck
{
public:
    // Construteur
    PokerGame();
    // Deconstruteur
    ~PokerGame();
    // Fonction pour piocher les cartes du deck
    void DrawCard(std::vector<Card> deck);
    // Fonction pour avoir ce que la main a (brelan, pair, etc...)
    Combination HandComp(std::vector<Card> hand);

private:
    const std::string spades{u8"\u2660"};   // Logo pour pike
    const std::string treffle{u8"\u2663"};    // Logo pour treffles
    const std::string hearts{u8"\u2665"};   // Logo pour coeur
    const std::string diamonds{u8"\u2666"}; // Logo pour carreaux

    std::vector<Card> hand1;    // Main Joueur 1
    std::vector<Card> hand2;    // Main Joueur 2
    bool IsFlushRoyal(std::vector<Card> hand);  // Fonction QuinteFlushRoyal Poker
    bool IsSuiteCouleur(std::vector<Card> hand);   // Fonction QuinteFlush Poker
    bool IsCarre(std::vector<Card> _hand);  // Fonction Carre Poker
    bool IsColor(std::vector<Card> _hand);  // Fonction Couleur Poker
    bool IsSuite(std::vector<Card> _hand);  // Fonction Suite Poker
    bool IsFull(std::vector<Card> _hand);   // Fonction Full Poker
    bool IsBrelan(std::vector<Card> _hand); // Fonction Brelan Poker
    bool IsDoublePair(std::vector<Card> _hand); // Fonction Double Pair
    bool IsPair(std::vector<Card> _hand); // Fonction Pair

    // Fonction pour determiner le gagnant de la partie
    int DetermineWinner(std::vector<Card> hand1, std::vector<Card> hand2);
    // Fonction pour annoncer le gagnant en fonction de la determination du gagnant
    void AnnouceWinner(std::vector<Card> hand1, std::vector<Card> hand2);
    // Fonction pour trouver la pair la plus puissant dans les 2 mains
    int HightPair(std::vector<Card> _hand1, std::vector<Card> _hand2);
    // Fonction pour trouver la carte la plus forte du jeu en fonction de la main du joueur
    int getHighest(std::vector<Card> hand);

};