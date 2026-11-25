//
// Created by Sam on 18.11.2026.
//
#include <iostream>
#include "pile.hpp"
#include <array>
#include <iomanip>
#include <stdexcept>

using namespace std;


void push(Pile& pile, int n, int& count)
{
    if (pile_size <= count)
    {
        throw overflow_error("impossible d'empiler dans une pile pleine.");
    }
    pile.at(count) = n;
    count++;

}
void pop(int& count)
{
    if (empty(count))
    {
        throw underflow_error("impossible de dépiler une pile vide.");
    }
    // on baisse juste le compteur, la case ne fait plus partie de la pile
    count--;
}
int top(const Pile& pile, const int& count)
{
    if (empty(count))
    {
        throw underflow_error("impossible de consulter le sommet d'une pile vide.");
    }
    return pile[count - 1];
}
// retourne une référence vers le sommet, pour pouvoir lui affecter une nouvelle valeur
int& top(Pile& pile, const int& count)
{
    if (empty(count))
    {
        throw underflow_error("impossible de remplacer le sommet d'une pile vide.");
    }
    return pile[count - 1];
}
bool empty(const int& count)
{
    if (count == 0)
    {
        return true;
    }
    return false;
}
int size(const int& count)
{
    return count;
}
void clear(int& count)
{
    count = 0;
}
void show_pile(const Pile& pile, const int& count)
{
    if (empty(count))
    {
        cout << "La pile est vide." << endl;
    }
    else if (count == 1)
    {
        cout << "Sommet / Fond -> " << pile[0] << endl;
    }
    else
    {
        for (int i = count - 1; i >= 0; --i)
        {
            if (i == count - 1)
            {
                cout << "Sommet ->";
            }
            else if (i == 0)
            {
                cout << "Fond   ->";
            }
            else
            {
                cout << "         ";
            }
            cout << setw(3) << pile[i] << endl;
        }
    }
}