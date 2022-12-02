/*
** EPITECH PROJECT, 2022
** Card.h
** File description:
** TODO
*/


#ifndef PROJET_THUNE_CARD_H
#define PROJET_THUNE_CARD_H

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

// Création de l'objet Carte pour le jeu complet
class Card
{
private:

    int value; // Valeur Carte
    std::string color; // Couleur Carte

public:
    // constructor default
    Card() = default;
    // constructor
    Card(int _val, std::string _color);
    // deconstructor
    ~Card();
    // Get color
    std::string getcolor();
    // Get value
    int getValue();
};

#endif //PROJET_THUNE_CARD_H
