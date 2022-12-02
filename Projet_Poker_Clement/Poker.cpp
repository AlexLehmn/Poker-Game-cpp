#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include "Poker.h"
#include "Card.h"

PokerGame::PokerGame()
{
}

PokerGame::~PokerGame()
{
}

void PokerGame::DrawCard(std::vector<Card> deck)
{
    // Remplissage de la main hand1 avec le deck
    for (int i = 0; i < 5; i++)
    {
        this->hand1.push_back(deck[i]);
    }

    /*  FORCER LA MAIN DU JOUEUR 1 TEST    */

    // this->hand1.push_back(Card(4, spades));
    // this->hand1.push_back(Card(7, spades));
    // this->hand1.push_back(Card(9, spades));
    // this->hand1.push_back(Card(13, spades));
    // this->hand1.push_back(Card(14, hearts));

    std::cout << "Card: Player 1" << std::endl;
    for (Card i : hand1)
    {
        std::cout << "\tValue: " << i.getValue() << " ";
        std::cout << "\tColor: " << i.getcolor() << std::endl;
    }
    std::cout << "\n" << std::endl;

    // Remplissage de la main hand 2 avec le deck
    for (int i = 5; i < 10; i++)
    {
        this->hand2.push_back(deck[i]);
    }

    /*  FORCER LA MAIN DU JOUEUR 2 TEST    */

    // this->hand2.push_back(Card(5, spades));
    // this->hand2.push_back(Card(6, spades));
    // this->hand2.push_back(Card(7, spades));
    // this->hand2.push_back(Card(8, spades));
    // this->hand2.push_back(Card(9, spades));

    std::cout << "Card: Player 2" << std::endl;
    for (Card i : hand2)
    {
        std::cout << "\tValue: " << i.getValue() << " ";
        std::cout << "\tColor: " << i.getcolor() << std::endl;
    }
    // Appelle de la fonction pour annoucer les winners car les joueurs on piocher
    AnnouceWinner(hand1, hand2);
}

int PokerGame::DetermineWinner(std::vector<Card> hand1, std::vector<Card> hand2)
{
    // Si le joueur 1 a une meilleur main ou non on check ça en appellant la fonction HandComp
    // qui nous dira ce que le joueur a
    if (HandComp(hand1) > HandComp(hand2))
        return 1;
    else if (HandComp(hand2) > HandComp(hand1))
        return 2;
    // Si le joueur 1 et joueur 2 ont une pair chacun il faut savoir laquelle est la plus fort
    else if (HandComp(hand1) == HandComp(hand2) && HandComp(hand1) == Pair && HandComp(hand2) == Pair)
        return HightPair(hand1, hand2); // Return la fonction Highpaire pour savoir qui a gagné
    // Suite seulement s'il n'y a pas de combinaisons alors on regarde la plus forte carte
    else {
        if ((getHighest(hand1) > getHighest(hand2)))
            return 1;
        else if ((getHighest(hand2) > getHighest(hand1)))
            return 2;
        else
            return 5;
    }
}

// Fonction pour bien afficher le gagnant
void PokerGame::AnnouceWinner(std::vector<Card> hand1, std::vector<Card> hand2)
{
    // Quand le joueur 1 a eu une combinaisons
    cout << endl;
    cout << "Joueur 1"
         << " has a: " << endl;
    if (HandComp(hand1) == 9)
        cout << "FlushRoyal." << endl;
    else if (HandComp(hand1) == 8)
        cout << "FullSuite." << endl;
    else if (HandComp(hand1) == 7)
        cout << "Carre." << endl;
    else if (HandComp(hand1) == 6)
        cout << "Full." << endl;
    else if (HandComp(hand1) == 5)
        cout << "Couleur." << endl;
    else if (HandComp(hand1) == 4)
        cout << "Suite." << endl;
    else if (HandComp(hand1) == 3)
        cout << "Brelan." << endl;
    else if (HandComp(hand1) == 2)
        cout << "Two Pair." << endl;
    else if (HandComp(hand1) == 1)
        cout << "Pair." << endl;
    else // Quand le joueur n'a que une carte haute
    {
        if (getHighest(hand1) < 11)
            cout << "High Card of " << getHighest(hand1) << "." << endl;
        else if (getHighest(hand1) == 11)
            cout << "High Card of J." << endl;
        else if (getHighest(hand1) == 12)
            cout << "High Card of Q." << endl;
        else if (getHighest(hand1) == 13)
            cout << "High Card of K." << endl;
        else if (getHighest(hand1) == 14)
            cout << "High Card of A." << endl;
    }

    cout << endl;
    // Quand le joueur 2 a eu une combinaisons
    cout << "Joueur 2"
         << " has a: " << endl;
    if (HandComp(hand2) == 9)
        cout << "FlushRoyal." << endl;
    else if (HandComp(hand2) == 8)
        cout << "FullSuite." << endl;
    else if (HandComp(hand2) == 7)
        cout << "Carre." << endl;
    else if (HandComp(hand2) == 6)
        cout << "Full." << endl;
    else if (HandComp(hand2) == 5)
        cout << "Couleur." << endl;
    else if (HandComp(hand2) == 4)
        cout << "Suite." << endl;
    else if (HandComp(hand2) == 3)
        cout << "Brelan." << endl;
    else if (HandComp(hand2) == 2)
        cout << "Two Pair." << endl;
    else if (HandComp(hand2) == 1)
        cout << "Pair." << endl;
    else // Quand le joueur n'a que une carte haute
    {
        if (getHighest(hand2) < 11)
            cout << "High Card of " << getHighest(hand2) << "." << endl;
        else if (getHighest(hand2) == 11)
            cout << "High Card of J." << endl;
        else if (getHighest(hand2) == 12)
            cout << "High Card of Q." << endl;
        else if (getHighest(hand2) == 13)
            cout << "High Card of K." << endl;
        else if (getHighest(hand2) == 14)
            cout << "High Card of A." << endl;
    }

    cout << endl;
    // Afficher qui a gagner la partie
    if (DetermineWinner(hand1, hand2) == 1)
        cout << "Joueur 1"
             << " wins! " << endl;
    else if (DetermineWinner(hand1, hand2) == 2)
        cout << "Joueur 2"
             << " wins! " << endl;
    else if (DetermineWinner(hand1, hand2) == 3)
        cout << "Joueur 2"
             << " wins! with Highest Pair " << endl;
    else if (DetermineWinner(hand1, hand2) == 4)
        cout << "Joueur 1"
             << " wins! with Highest Pair " << endl;
    else
        cout << "It is a tie. " << endl;
}

Combination PokerGame::HandComp(std::vector<Card> hand)
{
    // Regarde si la main donner en argument à une combinaison ou pas
    if (IsFlushRoyal(hand) == true)
        return FlushRoyal;
    else if (IsSuiteCouleur(hand) == true)
        return FullSuite;
    else if (IsCarre(hand) == true)
        return Carre;
    else if (IsFull(hand) == true)
        return Full;
    else if (IsSuite(hand) == true)
        return Suite;
    else if (IsColor(hand) == true)
        return ColorFlush;
    else if (IsBrelan(hand) == true)
        return Brelan;
    else if (IsDoublePair(hand) == true)
        return twoPairs;
    else if (IsPair(hand) == true)
        return Pair;
    else
        return HighCard;
}

//  Fonction pour la QuinteFlush Royal
bool PokerGame::IsFlushRoyal(std::vector<Card> _hand)
{
    bool _suite = false;
    bool flush = false;

    // On regarde si les cartes se suivent
    for (int i = 0; i < 4; i++) {
        if ((_hand[i].getValue() - 1) == _hand[i + 1].getValue())
            _suite = true;
        else
        {
            _suite = false;
            break;
        }
    }
    // regarde si les cartes on la meme couleurs
    for (int i = 0; i < 4; i++)
    {
        if (_hand[i].getcolor() == _hand[i + 1].getcolor())
            flush = true;
        else
        {
            flush = false;
            break;
        }
    }
    // On regarde s'il la plus grande carte est un as et si tout est bon au dessus alors QuinteFlushRoyal
    if (_suite == true && flush == true && getHighest(_hand) == 14)
        return true;
    return false;
}

// Fonction pour trouver une couleur
bool PokerGame::IsColor(std::vector<Card> _hand)
{
    int color = 1;
    bool isColor = false;
    std::string colorCard = _hand[0].getcolor(); // On prend la premiere cartes de la main comme couleur de comparaison

    // On regarde si tout les cartes ont les memes couleurs que la premieres
    for (int i = 1; i < 5; i++) {
        if (colorCard == _hand[i].getcolor()){
            color++;
        }
        else{
            color = 0;
            break;
        }
    }
    // Si tout de la meme couleur alors Couleur
    if (color == 5){
        isColor = true;
    }
    return isColor;
}

// Fonction pour trouver une suite
bool PokerGame::IsSuite(std::vector<Card> _hand)
{
    int suite = 1;
    int BestCard = getHighest(_hand);
    bool Suite = false;
    vector<int> value_card; // Creation d'un tableau pour juste recuperer les valeurs des cartes

    // On rempli le tableau des valeurs de la main
    for (int i = 0; i < 5; i++){
        value_card.push_back(_hand[i].getValue());
    }
    // On se deplace jusqu'a la fin de la meilleur moins la taille de la main (exemple: 14->9, 14 - 5)
    for (int i = BestCard - 1; i > BestCard - 5; i--) {
        // on utilise count pour chercher si la valeur que l'on cherche existe dans le tableau que on lui donne en lui donnant le debut du tableau et la fin
        if (count(value_card.begin(), value_card.end(), i)) {
            suite++;
        }
        else {
            suite = 0;
            break;
        }
    }
    // Pour checker la suite si on prend du plus fort au moins fort As -> 2 -> 3 ....
    if (BestCard == 14 && suite == 0) {
        suite = 1;
    // On se deplace mains a l'envers ducoup
        for (int i = 2; i < 6; i++){
        // on utilise count pour chercher si la valeur que l'on cherche existe dans le tableau que on lui donne en lui donnant le debut du tableau et la fin
            if (count(value_card.begin(), value_card.end(), i)) {
                suite++;
            }
            if (suite == 5) {
                BestCard = i;
            }
            else {
                suite = 0;
                break;
            }
        }
    }
    // Si tout est bon alors on a une suite
    if (suite == 5) {
        Suite = true;
    }
    return Suite;
}

// Fonction pour trouver un full brelan + paire
bool PokerGame::IsFull(std::vector<Card> _hand)
{
    // Initialisation de beaucoup de valeur pour pas reutiliser les memes
    bool Full = false;
    int brelan = 0;
    int full = 0;
    int x = 0;
    int nbPaire = 0;
    int x2 = 0;
    int valuebrelan = 0;

    // On cherche le brelan puis la paire
    // On se deplace Chiffre par chiffre
    for (int i = 0; i < 3; i++) {
        x = 0;
        for (int j = 1; j < 5; j++) {
            if (_hand[i].getValue() == _hand[j].getValue() && i != j) {
                x++;
            }
            if (x == 2) {
                valuebrelan = _hand[i].getValue();
                brelan = 1;
                break;
            }
        }
    }
    // Si on a trouvé un brelan alors on regarde s'il y a une paire, en ne prenant pas en compte les valeurs du brelan !!
    if (brelan == 1) {
        // On se deplace Chiffre par chiffre
        for (int i = 0; i < 4; i++) {
            x2 = 0;
            for (int j = 1; j < 5; j++) {
                if (_hand[i].getValue() == _hand[j].getValue() && i != j && (_hand[i].getValue() != valuebrelan || _hand[j].getValue() != valuebrelan)) {
                    x2++;
                }
                if (x2 == 1) {
                    nbPaire = 1;
                    break;
                }
            }
        }
        if (nbPaire > 0) {
            Full = true;
        }
    }
    return Full;
}

// Fonction pour regarder s'il y a une paire
bool PokerGame::IsPair(std::vector<Card> _hand)
{
    bool checkPair = false;
    int nbPaire = 0;
    int CardFirst = 0;
    int CardSecond = 0;

    // Meme comparaison pour full
    // On se deplace Chiffre par chiffre
    for (int i = 0; i < 5; i++) {
        int valueCard = _hand[i].getValue();
        for (int j = 0; j < 5; j++) {
            if (i != j) {
                int valueCardSecond = _hand[j].getValue();
                if (valueCard == valueCardSecond) {
                    nbPaire++;
                    if (CardFirst == 0) {           // On regarde s'il les chiffres sont les memes
                        CardFirst = valueCard;
                    }
                    else if (CardSecond == 0 && CardFirst != valueCard) {
                        CardSecond = valueCard;
                    }
                }
            }
        }
    }
    // Si on trouvé seulement 2 chiffre a eu deux qui font une pair alors on a trouvé une pair
    if (nbPaire >= 2)
        checkPair = true;
    return checkPair;
}

bool PokerGame::IsDoublePair(std::vector<Card> _hand)
{
    bool checkPair = false;
    int nbPaire = 0;
    int CardFirst = 0;
    int CardSecond = 0;

    // Exactement Pareil que la simple Pair
    for (int i = 0; i < 5; i++) {
        int valueCard = _hand[i].getValue();
        for (int j = 0; j < 5; j++) {
            if (i != j) {
                int valueCardSecond = _hand[j].getValue();
                if (valueCard == valueCardSecond) {
                    nbPaire++;
                    if (CardFirst == 0) {
                        CardFirst = valueCard;
                    }
                    else if (CardSecond == 0 && CardFirst != valueCard) {
                        CardSecond = valueCard;
                    }
                }
            }
        }
    }
    // Si on trouvé seulement 4 chiffre a eu quatre qui font 2 paire alors on a trouvé 2 paire
    if (nbPaire >= 4)
        return true;
    return checkPair;
}

// Fonction pour trouver les brelans
bool PokerGame::IsBrelan(std::vector<Card> _hand)
{

    bool Brelan = false;
    int var = 0;

    // ON prend un chiffre référence et s'il se repete 2 fois alors il y a un brelan
    for (int i = 0; i < 3; i++) {   // on se balade chiffre par chiffre
        var = 0;
        for (int j = 1; j < 5; j++) {
            if (_hand[i].getValue() == _hand[j].getValue() && i != j) {
                var++;
            }
            if (var == 2) {
                Brelan = true;
                break;
            }
        }
    }
    return Brelan;
}

// Fonction pour trouver un carre
bool PokerGame::IsCarre(std::vector<Card> _hand)
{

    bool carre = false;
    int x = 0;

    // ON prend un chiffre référence et s'il se repete 3 fois alors il y a un carre
    for (int i = 0; i < 2; i++){    // On se balade chiffre par chiffre
        x = 0;
        for (int j = 1; j < 5; j++) {
            if (_hand[i].getValue() == _hand[j].getValue() && i != j) {
                x++;
            }
            if (x == 3) {
                carre = true;
                break;
            }
        }
    }
    return carre;
}

// Fonction pour trouver une QuinteFlush pareil que quinteflushroyal sans l'AS
bool PokerGame::IsSuiteCouleur(std::vector<Card> _hand) {
	bool quinteFlush = false;
	int suite = 1; // Pour compter la suite s'il n'y a pas de probleme
	int valueBestCard = getHighest(_hand); // On prend la meilleur de la main pour savoir dans quelle sens prendre la suite
	vector<int> value_card; // Creation d'un tableau pour juste recuperer les valeurs des cartes

    // On remplie le tableau value_card des valeurs de la main
	for (int i = 0; i < 5; i++) {
		value_card.push_back(_hand[i].getValue());
	}

    // Comparaison des cartes avec la meilleur - 1 à chaque fois
	for (int i = valueBestCard - 1; i > valueBestCard - 5; i--) {
    // on utilise count pour chercher si la valeur que l'on cherche existe dans le tableau que on lui donne en lui donnant le debut du tableau et la fin
		if (count(value_card.begin(), value_card.end(), i)) {
			suite++;
		}
		else {
			suite = 0;
			break;
		}

	}
    // Si suite trouver alors on checke la couleur
	if (suite == 5) {
		int color = 1; // Pour compter le nombre de couleur jusqu'a 5 si tout marche bien
        // On prend une couleur de base pour la comparé au autre
		std::string colorFirstCard = _hand[0].getcolor();
        // Checke de la main en fonction de la couleur prise au debut
		for (int i = 1; i < 5; i++) {
			if (colorFirstCard == _hand[i].getcolor()) {
				color++;
			}
			else {
				color = 0;
				break;
			}
		}
        // Si tout est bon alors on a trouvé une quinteflush
		if (color == 5) {
			quinteFlush = true;
		}
	}
	return quinteFlush;
}

// Fonction pour trouver la pair la plus puissant entre les 2 mains
int PokerGame::HightPair(std::vector<Card> _hand1, std::vector<Card> _hand2)
{
    int highhand1 = 0; // Variable pour prendre la valeur de la paire du joueur 1
    int highhand2 = 0; // Variable pour prendre la valeur de la paire du joueur 2

    // On refait la meme chose que pour chercher les simples paires pour le joueur 1
    for (int i = 0; i < 5; i++) {
        int valueCard = _hand1[i].getValue();
        for (int j = 0; j < 5; j++) {
            if (i != j) {
                int valueCardSecond = _hand1[j].getValue();
                if (valueCard == valueCardSecond) {
                    highhand1 = valueCard; // on remplie "highhand1" de la valeur de la pair
                }
            }
        }
    }
    // On refait la meme chose que pour chercher les simples paires pour le joueur 2
    for (int i = 0; i < 5; i++) {
        int valueCard = _hand2[i].getValue();
        for (int j = 0; j < 5; j++) {
            if (i != j) {
                int valueCardSecond = _hand2[j].getValue();
                if (valueCard == valueCardSecond) {
                    highhand2 = valueCard; // on remplie "highhand2" de la valeur de la pair
                }
            }
        }
    }
    // En fonction de la valeur des paires on en detuit le gagnant
    if (highhand1 < highhand2)
        return 3;
    else if (highhand1 > highhand2)
        return 4;
    else
        return 5;
}

// Mini fonction pour savoir si une valeur est plus grande que l'autre
bool comp(int a, int b)
{
    return (a < b);
}

// Fonction pour trouver la meilleur carte d'une main
int PokerGame::getHighest(std::vector<Card> hand)
{
    int high = 0;
    // On utilsie la fonction std::max qui permet de donner la plus grande valeur d'un tableau
    high = std::max({hand[0].getValue(), hand[1].getValue(),
                     hand[2].getValue(), hand[3].getValue(), hand[4].getValue()},
                    comp);
    return high; // on renvoie la valeur de la meilleur carte
}
