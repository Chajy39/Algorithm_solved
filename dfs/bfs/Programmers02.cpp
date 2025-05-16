#include <string>
#include <vector>

using namespace std;

vector<bool> visited;

void dfs (int node, int n, vector<vector<int>>& computers) {
    visited[node] = true;
    
    for(int i =0; i< n; i++) {
        if(computers[node][i] == 1 && !visited[i]) {
            dfs(i, n, computers);
        }
    }       
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    visited.resize(n, 0);
    
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            dfs(i, n, computers);
            answer++;
        }
    }
    
    return answer;
}