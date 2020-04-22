// ----------------------------------------------
/// Finding stongly connected cmponents in a graph using Kosaraju's algorithm
///
/// This implentations uses Hash-Maps to accomodate various forms of inputs
// ----------------------------------------------


#include<bits/stdc++.h>

using namespace std;


set<int> visited;
stack<int> strong;
int current =0;

/// Performs Depth first search on the input graph and
/// pushes each reachable vertex on the stack: Strong
void dfs(int vertex,map<int,vector<int>> graph){
    visited.insert(vertex);

    for(auto i : graph[vertex]){

        if(visited.find(i)==visited.end())dfs(i,graph);

    }

    strong.push(vertex);

}

// Performs Depth first search on the reverse of the input graph and
/// pushes each reachable vertex on the stack: Strong
void revdfs(int vertex,map<int,vector<int>> graph){

    visited.insert(vertex);
    cout<<vertex<<" ";
    ++current;
    
    for(auto i : graph[vertex]){

        if(visited.find(i)==visited.end())revdfs(i,graph);
    
    }

    strong.push(vertex);
}

int main(){
    ///v:number of vetices and e:number of edges
    int v,e;
    cin>>v>>e;

    ///input graph
    map<int,vector<int>> graph;

    ///reverse of input graph
    map<int,vector<int>> rev_graph;

    ///Taking edge inputs and modifying the graph accordingly
    ///Format of input for a edge: v1 v2
    ///v1 is 'from' vertex and v2 is 'to' vertex
    for(int i=0;i<e;i++){

        int inpv1,inpv2;
        cin>>inpv1>>inpv2;
        graph[inpv1].push_back(inpv2);

    }

    ///Performing dfs on each unvisited node
    for(auto i =graph.begin();i!=graph.end();i++){

        int j = (*i).first;
        if(visited.find(j)==visited.end())dfs(j,graph);

    }

    ///Reversing the input graph to apply KosaRaju
    for(auto i =graph.begin();i!=graph.end();i++){

        for(auto j : (*i).second){
            rev_graph[j].push_back((*i).first);
        }
    
    }

    int maxtore=0;
    current=0;
    visited.clear();
    cout<<"Strongly Connected Components are:\n";

    ///Performing DFS on the nodes on the stack and pooping it out
    ///Hence identifying the Strongly Connected Components
    while(!strong.empty()){

        current =0;
        int curr = strong.top();
        if(visited.find(curr)==visited.end()){revdfs(curr,rev_graph);cout<<"\n\n";}
        strong.pop();
        maxtore = max(current,maxtore);
    }

    ///Printing number of nodes in largest SCC
    cout<<"\n\n\nNodes in largest SCC:"<<maxtore<<"\n";

}