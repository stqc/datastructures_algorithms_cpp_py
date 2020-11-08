#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>

using namespace std;
class graph{

public:
    unordered_map<int, vector<int>> g;
    graph(int x){
    vector<int> j;
    g[x] =j;
    }
    void add_vertex(int x){
    vector <int> j;
    if(g.find(x)==g.end()){
    g[x] = j;
    }
    else{
        cout<<"vertex already exists\n";
        cout<<g.size()<<"\n";
    }
    }
    void add_edge(int v1, int v2){
        if(g.find(v1)!=g.end() && g.find(v2)!=g.end()){
        if(find(g[v1].begin(),g[v1].end(),v2)==g[v1].end()){
        g[v1].push_back(v2);
        }
        if(find(g[v2].begin(),g[v2].end(),v1)==g[v2].end()){

        g[v2].push_back(v1);}
    }
    else{
        cout<<"One or both vertex do not exist\n";
    }
    }
};

int main(){

graph gg(2);
gg.add_vertex(3);
gg.add_edge(2,3);
gg.add_vertex(4);
gg.add_edge(2,4);
gg.add_vertex(6);
gg.add_edge(4,6);



for(auto x: gg.g){
        cout<<x.first<<"->";
        for(int i = 0; i < x.second.size(); i++){
            cout<<" "<<x.second[i];
        }
        cout<<"\n";
}
}

