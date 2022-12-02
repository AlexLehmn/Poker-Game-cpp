/*
** EPITECH PROJECT, 2022
** Card.cpp
** File description:
** TODO
*/

#include <string>
#include <vector>
#include <istream>
#include <ostream>
#include <stdexcept>
#include "Card.h"

// Constructeur pour créer la carte
Card::Card(int _val, std::string _color)
{
    this->value = _val;
    this->color = _color;
}

// Deconstructeur obligatoire
Card::~Card()
{
}

// Function pour avoir la couleur de la carte
std::string Card::getcolor()
{
    return this->color;
}

// Function pour avoir la valeur de la carte
int Card::getValue()
{
    return this->value;
}