///----------------------------------------------
/// Finding stongly connected cmponents in a graph using "Divide-and-Conquer Strong Components" algorithm
///
/// This implentations uses Hash-Maps to accomodate various forms of inputs
///----------------------------------------------


#include<bits/stdc++.h>

using namespace std ;


///stores the given graph
map<int,unordered_set<int>> inp;

///stores the reverse of goven graph i.e. for any edge the from vertex will be the to vertext and vice versa
map<int,unordered_set<int>> rev_inp;

///stores if the fiven vertex is visited while performing dfs on inp
map<int,bool> p_visit;

///stores if the fiven vertex is visited while performing dfs on rev_inp
map<int,bool> d_visit;

///stores if a given vertext has been considered to preform dfs on
set<int> main_visit;

/// store the current Strongly Connected Component
set<int> scc ;



/// Perform dfs on either graphs: inp and rev_inp
void dfs(int s, bool swit){

    ///perform dfs on inp if bool val is false
    if(!swit){
    d_visit[s] = true;
        for(auto i : inp[s]){
            if(!d_visit[i])dfs(i,swit);
        }
    }

    ///perform dfs on rev_inp if bool val is true
    if(swit){
    p_visit[s] = true;
        for(auto i : rev_inp[s]){
            if(!p_visit[i] && d_visit[i])dfs(i,swit);
            if(p_visit[i] && d_visit[i] ){
                if(scc.find(i)==scc.end()){
                    cout<<i<<" ";
                    scc.insert(i);
                    main_visit.insert(i);
                }
            }
        }
    }

    return ;
}

int main(){

    ///n: number of nodes m: nuber of edges
    int n,m;
    cin >> n >> m;


    ///Taking edge inputs and modifying the graph accordingly
    ///Format of input for a edge: v1 v2
    ///v1 is 'from' vertex and v2 is 'to' vertex
    for(int i=0;i<m;i++){
        int a ,b ;
        cin >> a >> b;
        inp[a].insert(b);
        rev_inp[b].insert(a);
        inp[a].insert(a);
        rev_inp[b].insert(b);
        inp[b].insert(b);
        rev_inp[a].insert(a);
    }


    cout<<"Strongly Connected Components are:\n\n";

    ///stores max num of nodes in a SCC
    int max_nodes =0 ;

    ///loop to consider each vertex to perform dfs
    for(auto i : inp){

        scc.clear();
        p_visit.clear();
        d_visit.clear();

        ///checking if given vertex is alreadty considered for dfs
        if(main_visit.find(i.first)==main_visit.end()){

            ///dfs on inp
            dfs(i.first,0);

            ///dfs on rev_inp
            dfs(i.first,1);

            ///updating max_nodes
            int count = scc.size();
            max_nodes = max(count,max_nodes);
            
            if(scc.size()>0)cout<<"\n\n";
    }}
    cout<<"\n\n\nNodes in largest SCC:"<<max_nodes<<"\n";
}