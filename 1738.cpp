#include <bits/stdc++.h>

#define inf 999999999 // define-se INF como infinito
using namespace std;
int d[201][201][26]; //[posiçao do vertice u][posiçao do vertice v][peso da aresta, neste caso, os provedores]
int n;

void floydwarshall()
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int l = 0; l < 26; l++)
                    d[i][j][l] = min(d[i][j][l], d[i][k][l] + d[k][j][l]);
            }
        }
    }
}

int main()
{
    int u, v, flag; // vertice de entrada, vertice de saida e flag que indica se ha caminho(1) ou nao(0)

    string provedores; // string q guardará o peso das arestas

    while (1)
    {
        cin >> n;   // entrada para o numero de vertices
        if (n == 0) // verifica, se o numero de vertices for 0, entao finaliza o programa
        {
            return 0;
        }

        for (int i = 0; i < n; i++) // inicia o grafo definindo tudo como inf
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < 26; k++)
                    d[i][j][k] = inf;
            }
        }

        while (1)
        {
            cin >> u >> v;        // entrada para vertice de entrada e saida
            if (u == 0 && v == 0) // se vertice de entrada e saida for igual a 0, entao paramos o while
            {
                break;
            }
            cin >> provedores; // se os vertices n forem nulos, entramos com o peso, que sao os provedores
            --u;               // subtraimos o valor de u e de v
            --v;
            for (int i = 0; i < provedores.size(); i++) // definimos os pesos das arestas
                d[u][v][provedores[i] - 'a'] = 1;
        }

        floydwarshall(); // chamada da funçao floydWarshall

        while (1)
        {
            cin >> u >> v; // entrada para vertice de entrada e saida, se ambos forem igual a 0 paramos o while
            if (u == 0 && v == 0)
            {
                break;
            }
            --u; // subtraimos o valor de u e de v
            --v;
            flag = 0;
            for (int i = 0; i < 26; i++) // verificamos se ha caminho
            {
                if (d[u][v][i] != inf) // se houver caminho, escrevemos a letra ou letras que correspondem ao caminho
                {
                    cout << (char)(i + 'a');
                    flag = 1;
                }
            }
            if (flag == 0) // se nao houver caminho, escrevemos apenas -
            {
                cout << '-';
            }
            cout << '\n';
        }
        cout << '\n';
    }
}
