//
// Created by Sam on 18.11.2026.
//
#ifndef PILE_H
#define PILE_H
#include <array>

const int pile_size = 5;
using Pile = std::array<int, pile_size>;

void push(Pile& pile, int n, int& count);
void pop(int& count);
int top(const Pile& pile, const int& count);   // consulter le sommet
int& top(Pile& pile, const int& count);        // remplacer le sommet
bool empty(const int& count);
int size(const int& count);
void clear(int& count);
void show_pile(const Pile& pile, const int& count);

#endif //PILE_H
