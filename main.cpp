#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <limits>
#include "pile.hpp"
using namespace std;


int main() {
    int reponse = 0;
    Pile pile;
    int count = 0;
    // référence constante pour faire la difference entre le top qui consulte et pas celui qui remplace
    const Pile& pile_lecture = pile;

    cout << "Ce programme permet de manipuler une pile d'entiers." << endl << endl;

    do {
        cout << "1 - Empiler\n"
             << "2 - Dépiler\n"
             << "3 - Consulter le sommet\n"
             << "4 - Modifier l'élément au sommet\n"
             << "5 - Vérifier si la pile est vide\n"
             << "6 - Afficher le nombre de valeurs\n"
             << "7 - Vider la pile\n"
             << "8 - Afficher toute la pile\n"
             << "0 - Quitter" << endl;

        do {
            cout << "Votre choix : ";
            cin >> reponse;


            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Erreur : Saisie invalide" << endl;
                reponse = -1;
            }
        } while (reponse < 0 || reponse > 8);

        try {
            switch (reponse) {
                case 1: {
                    int valeur;
                    cout << "Valeur : ";
                    cin >> valeur;
                    push(pile, valeur, count);
                    cout << "Valeur empilée." << endl;
                    break;
                }
                case 2:
                    pop(count);
                    cout << "Valeur retirée : " << pile[count] << endl;
                    break;
                case 3: {
                    int sommet = top(pile_lecture, count);
                    cout << "Sommet : " << sommet << endl;
                    break;
                }
                case 4: {
                    int valeur;
                    cout << "Valeur de remplacement : ";
                    cin >> valeur;
                    top(pile, count) = valeur;   // on écrit valeur dans la case du sommet
                    cout << "Valeur remplacée." << endl;
                    break;
                }
                case 5:
                    if (empty(count))
                    {
                        cout << "La pile est vide." << endl;
                    }
                    else
                    {
                        cout << "La pile n'est pas vide." << endl;
                    }
                    break;
                case 6:
                    cout << "Nombre de valeurs : " << size(count) << endl;
                    break;
                case 7:
                    clear(count);
                    cout << "Pile vidée." << endl;
                    break;
                case 8:
                    show_pile(pile, count);
                    break;
                case 0:
                    cout << "Fin de programme." << endl;
                    break;
            }
        } catch (const exception& erreur) {
            cout << "Erreur : " << erreur.what() << endl;
        }
        cout << endl;
    } while (reponse != 0);








    return EXIT_SUCCESS;
}