#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int main(){
vector<int>x ={2,3,1,4,5,6,8,5,0,9,2,1,3,5}; // array/vector to be checked
unordered_map<int,int> maps; // We create an empty hash map here

// iterating through the vector/array
for (int i =0; i<x.size(); i++){
    if (maps.find(x[i])!= maps.end()){ // check if the key exists in the map if it does return and break
        cout<<"First recurring number is "<<x[i];
        break;
    }
    else{ // else insert the key/value pair in the map
        maps[x[i]]=x[i];
    }

}

}
