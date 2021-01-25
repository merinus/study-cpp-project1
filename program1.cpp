/*
9.5
Napisz program kt�ry najpierw pobierze liczb� z przedzia�u 4-24 reprezentuj�c� sum�cyfr. Nast�pnie wype�ni
 macierz 3x3 (tablica dwuwymiarowa dziewi�cioelementowa)
liczbami trzycyfrowymi
suma cyfr ka�dej z liczb musi by� jednakowa i r�wna pierwszej zmiennej podanej przez u�ytkownika
dwie takie same liczby nie mog� wyst�powa� obok siebie ani nie mog� by� wczytane dwie takie same warto�ci
 pod rz�d :

x1 x2 x1
x2 x1 x2
x1 x2 x1
*/
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

main() {

    int sum, number, three, first, second, third, rest;
    bool ok, sum_ok;
    int tab[3][3];
    string number_s;

    do {
        cout << "Podaj liczbe z przedzialu 4-24: ";
        cin >> sum;
        if (sum > 3 && sum < 25) {
            ok = false;
        } else {
            ok = true;
        }
    } while (ok);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            do {
                cout << "Wprowadz liczbe: wiersz " << i+1 << " | kolumna " << j+1 << ": ";
                cin >> number;
                number_s = to_string(number);
                three = number_s.size();

                first = number / 100;
                rest = number - (first * 100);
                second = rest / 10;
                third = rest - (second * 10);

                tab[i][j] = number;
            } while ((three != 3) || ((first + second + third) != sum ) || (tab[i][j-1])==tab[i][j] || (tab[i][j]==tab[i-1][j]));
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
                cout << tab[i][j] << "\t";
        }
        cout << "\n";
    }

    return 0;
}
