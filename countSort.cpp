#include<iostream>
#include<vector>

using namespace std;

int main(){

vector<int> arr,c,b;
int maxNum=0;

arr={0,4,3,4,3,9,3,2,4};
for(int i=0; i<arr.size();i++){ //finding the maximum element in the vector
    b.push_back(0);
    if(arr[i]>maxNum){
        maxNum=arr[i];
    }
}

cout<<maxNum<<"\n";

for(int i=0; i<=maxNum;i++){ // storing all values in the c vector as 0
    c.push_back(0);
}

for(int i =1; i<arr.size();i++){// incrementing all the values in c vector as they are encountered in our arr vector
    c[arr[i]]++;
}
for(int i=2; i<c.size();i++){// cumulative count of all the elements in c vector
    c[i]=c[i]+c[i-1];
}
cout<<"\n";
for(int i=1; i<c.size();i++){
    cout<<c[i]<<" ";
}

for(int i=arr.size()-1;i>=1;i--){// sorting the array based on the counts in c vector
    b[c[arr[i]]]=arr[i];
    c[arr[i]]--;
}
cout<<"\n";
for(int i=1; i<b.size(); i++){
    cout<<b[i]<<" ";
}

}
