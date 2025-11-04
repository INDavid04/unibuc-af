///////////////////
// Laboratorul 1 //
///////////////////

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

//////////////////////////////
// Reprezentarea grafurilor //
// 1. Lista de muchii       //
//////////////////////////////

void listaDeMuchii() {
    int numarNoduri;
    int numarMuchii;
    cout << "Numarul de noduri: "; cin >> numarNoduri;
    cout << "Numarul de muchii: "; cin >> numarMuchii;

    vector<pair<int, int>> listaMuchii;
    for (int i = 0; i < numarMuchii; i++) {
        int nod1, nod2;
        cout << "Muchia: ";
        cin >> nod1 >> nod2;
        listaMuchii.push_back({nod1, nod2});
    }

    cout << "Graful este reprezentat de urmatoarea lista de muchii\n";
    for (auto i : listaMuchii) {
        cout << i.first << " " << i.second << "\n";
    }

    // cout << "Graful este reprezentat de urmatoarea lista de muchii";
    // for (int i = 1; i <= numarNoduri; i++) {
    //     cout << "\n" << i << ": ";
    //     for (auto j : listaMuchii) {
    //         if (j.first == i) {
    //             cout << j.second << " ";
    //         }
    //     }
    // }
    // cout << "\n";
}

//////////////////////////////////////////////////
// Reprezentarea grafurilor                     //
// 2. Matrice de adiacenta                      // 
// https://www.pbinfo.ro/probleme/412/adiacenta //
//////////////////////////////////////////////////

void matriceDeAdiacenta() {
    ifstream fin("adiacenta.in");
    ofstream fout("adiacenta.out");

    int n, m; /// n noduri si m muchii
    fin >> n >> m;

    int matriceAdiacenta[101][101] = {0};
    for (int cnt = 1; cnt <= m; cnt++) {
        int i, j;
        fin >> i >> j;
        matriceAdiacenta[i][j] = 1;
        matriceAdiacenta[j][i] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            fout << matriceAdiacenta[i][j] << " ";
        }
        fout << "\n";
    }
    fout.close();
    fin.close();
}

////////////////////////////////////////////////////
// Reprezentarea grafurilor                       //
// 3. Liste de adiacenta                          // 
// https://www.pbinfo.ro/probleme/414/listavecini //
////////////////////////////////////////////////////

void listeDeAdiacenta() {
    ifstream fin("listavecini.in");
    ofstream fout("listavecini.out");
    
    int n; /// numarul de varfuri ale grafului
    fin >> n;

    int matriceAdiacenta[101][101] = {0};
    int i, j;
    while (fin >> i >> j) {
        matriceAdiacenta[i][j] = 1;
        matriceAdiacenta[j][i] = 1;
    }

    for (i = 1; i <= n; i++) {
        int numarVecini = 0;
        for (int j = 1; j <= n; j++) {
            if (matriceAdiacenta[i][j] == 1) {
                numarVecini++;
            }
        }
        fout << numarVecini << " ";
        for (j = 1; j <= n; j++) {
            if (matriceAdiacenta[i][j] == 1) {
                fout << j << " ";
            }
        }
        fout << "\n";
    }
    
    fout.close();
    fin.close();
}

///////////////////
// Laboratorul 1 //
///////////////////

int main() {
    // listaDeMuchii();
    // matriceDeAdiacenta();
    listeDeAdiacenta();

    return 0;
}