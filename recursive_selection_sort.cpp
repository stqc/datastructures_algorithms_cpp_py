//Recursive selection sort

#include<iostream>
#include<vector>

using namespace std;
//selection sort function declaration
void select_sort(vector<int> &vec, int start, int last);

int main(){
vector<int> x ={5,6,9,0,34,23,11,3,1,2,-1,8,20,11,65,25,12,22,11}; // vector to be sorted
cout<<"Before Sorting: ";
for(int i =0; i <x.size(); i++){
    cout<<x[i]<<" ";
}

select_sort(x,0,x.size()); //function calls
cout<<"\n\nAfter Sorting: ";
for(int i =0; i <x.size(); i++){
    cout<<x[i]<<" ";
}
cout<<"\n";
}

void select_sort(vector<int> &vec,int start,int last){// function definition

int min_index = start; // setting the index for minimum value as start

for(int i =start+1; i <last; i++){ // main loop
    if (vec[i]<vec[min_index]) // if the i'th value of vector is less than the min_index'th
    {
        int temp = vec[min_index]; //we swap them
        vec[min_index]=vec[i];
        vec[i] = temp;
    }

}
// if start is less than last-1 we make a recursive call
if(start<last-1){
    select_sort(vec,start+1,last); // recursive call
}
}
