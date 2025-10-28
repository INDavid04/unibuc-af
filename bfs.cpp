#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ifstream fin("bfs.in");
    ofstream fout("bfs.out");

    int noduri, muchii, nod_start, x, y, current;
    vector<vector<int>> lista_vecini;

    fin >> noduri >> muchii >> nod_start;

    lista_vecini.resize(noduri + 1);

    for (int i = 0; i < muchii; i++) {
        fin >> x >> y;
        lista_vecini[x].push_back(y);
    }

    vector<int> dist(noduri + 1, -1), viz(noduri + 1, 0);
    queue<int> coada;

    /// Inseram varful de start
    coada.push(nod_start);
    dist[nod_start] = 0;
    viz[nod_start] = 1;

    while (coada.size() > 0) {
        current = coada.front();
        coada.pop();
        /// Parcurgem vecinii lui current, daca nu e vizitat, il inseram in coada (scot 1 pun vecinii)
        for (auto i : lista_vecini[current]) {
            if (viz[i] == 0) {
                coada.push(i);
                viz[i] = 1;
                dist[i] = 1 + dist[current]; /// am mai facut din current inca un pas
            }
        }
    }

    for (int i = 1; i <= noduri; i++) {
        fout << dist[i] << " ";
    }
    fout << "\n";

    return 0;
}