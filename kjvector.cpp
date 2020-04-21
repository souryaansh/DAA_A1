#include<bits/stdc++.h>

using namespace std;
vector<bool> visited;
stack<int> strong;
int current =0;
void dfs(int vertex,vector<int> graph[]){
    visited[vertex] = true;
    for(auto i : graph[vertex]){
        if(!visited[i])dfs(i,graph);
    }
    strong.push(vertex);
}
void revdfs(int vertex,vector<int> graph[]){
    visited[vertex] = true;
    cout<<vertex<<" ";
    ++current;
    for(auto i : graph[vertex]){
        if(!visited[i])revdfs(i,graph);
    }
    strong.push(vertex);
}

int main(){
    int v,e;
    cin>>v>>e;
    vector<int> graph[v];
    vector<int> rev_graph[v];
    for(int i=0;i<e;i++){
        int inpv1,inpv2;
        cin>>inpv1>>inpv2;
        graph[inpv1].push_back(inpv2);
    }
    for(int i=0;i<v;i++)visited.push_back(false);
    for(int i=0;i<v;i++){
        if(!visited[i])dfs(i,graph);
    }
    for(int i=0;i<v;i++){
        for(auto j:graph[i]){
            rev_graph[j].push_back(i);
        }
    }
    int maxtore=0;
    current=0;
    cout<<"Strongly Connected Components are:\n";
    for(int i=0;i<v;i++){visited[i] = false;}
    while(!strong.empty()){
        current =0;
        int curr = strong.top();
        if(!visited[curr]){revdfs(curr,rev_graph);cout<<"\n\n";}
        strong.pop();
        maxtore = max(current,maxtore);
    }
    cout<<"\n\n\nNodes in largest SCC:"<<maxtore<<"\n";
}