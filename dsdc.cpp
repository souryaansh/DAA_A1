#include<bits/stdc++.h>

using namespace std ;

map<int,unordered_set<int>> inp;
map<int,unordered_set<int>> rev_inp;
map<int,bool> p_visit;
map<int,bool> d_visit;
map<int,bool> main_visit;
set<int> scc ;
void dfs(int s, bool swit){
    if(!swit){
    d_visit[s] = true;
        for(auto i : inp[s]){
            if(!d_visit[i])dfs(i,swit);
        }
    }
    if(swit){
    p_visit[s] = true;
        for(auto i : rev_inp[s]){
            if(!p_visit[i] && d_visit[i])dfs(i,swit);
            if(p_visit[i] && d_visit[i] ){if(scc.find(i)==scc.end())
            cout<<i<<" ";
            scc.insert(i);
            main_visit[i]=1;}
        }
    }
    return ;
}

int main(){
    int n,m;
    cin >> n >> m;
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
        // cout<<"hello";
    // main_visit.assign(n,false);
    cout<<"Strongly Connected Components are:\n\n";
    int max_nodes =0 ;
    for(auto i : inp){
        scc.clear();
        p_visit.clear();
        d_visit.clear();
        if(!main_visit[i.first]){
            dfs(i.first,0);
            dfs(i.first,1);
            int count = scc.size();
            max_nodes = max(count,max_nodes);
            if(scc.size()>0)cout<<"\n\n";
    }}
    cout<<"\n\n\nNodes in largest SCC:"<<max_nodes<<"\n";
}