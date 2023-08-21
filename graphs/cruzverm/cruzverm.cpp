#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 5999
#define TEM 1
#define NTEM 2

int graus[MAX];
int v[MAX][3];
int adj[MAX][MAX];

void dfs(int no) {

    v[no][0] = 1;
    v[no][TEM] = 1;
    v[no][NTEM] = 0;

    for (int i = 0; i < graus[no]; i++)
    {
        int u = adj[no][i];

        if(!v[u][0]) {
            dfs(u);
            v[no][TEM] += v[u][NTEM];
            v[no][NTEM] += std::max(v[u][NTEM],v[u][TEM]);
        }
    }
    
}

int main() {

    int t;
    std::cin >> t;
    
    


    for (int i = 0; i < t; i++)
    {
        int n;
        std::cin >> n;

        for (int j = 0; j < n; j++) {
            graus[j] = 0;
            v[j][0] = 0;
        }

        for (int j = 0; j < n-1; j++)
        {
            int x, y;
            std::cin >> x >> y; x--; y--;
            adj[x][graus[x]++]= y;
            adj[y][graus[y]++]= x;


        }
        
        dfs(0);
        std::cout << std::max(v[0][TEM],v[0][NTEM]) <<std::endl;
        
        
    }

    
    
}