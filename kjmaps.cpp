#include<bits/stdc++.h>
using namespace std;
set<int> visited;
stack<int> strong;
int current =0;
void dfs(int vertex,map<int,vector<int>> graph){
    visited.insert(vertex);
    // cout<<vertex<<" ";
    for(auto i : graph[vertex]){
        if(visited.find(i)==visited.end())dfs(i,graph);
    }
    strong.push(vertex);
}
void revdfs(int vertex,map<int,vector<int>> graph){
    visited.insert(vertex);
    // cout<<vertex<<" ";
    ++current;
    // cout<<current;
    for(auto i : graph[vertex]){
        if(visited.find(i)==visited.end())revdfs(i,graph);
    }
    strong.push(vertex);
}

int main(){
    int v,e;
    cin>>v>>e;
    map<int,vector<int>> graph;
    map<int,vector<int>> rev_graph;
    for(int i=0;i<e;i++){
        int inpv1,inpv2;
        cin>>inpv1>>inpv2;
        // if(graph.find(inpv1)==graph.end())graph[inpv1]={};
        graph[inpv1].push_back(inpv2);
    }
    for(auto i =graph.begin();i!=graph.end();i++){
        int j = (*i).first;
        if(visited.find(j)==visited.end())dfs(j,graph);
    }
    for(auto i =graph.begin();i!=graph.end();i++){
        for(auto j : (*i).second){
            // if(rev_graph.find(j)==graph.end())graph[j]={};
            rev_graph[j].push_back((*i).first);
        }
    }
    int maxtore=0;
    current=0;
    visited.clear();
    while(!strong.empty()){
        // cout<<"hello";
        current =0;
        int curr = strong.top();
        if(visited.find(curr)==visited.end()){revdfs(curr,rev_graph);}
        // cout<<"\n";
        strong.pop();
        maxtore = max(current,maxtore);
    }
    cout<<maxtore<<"\n";

}