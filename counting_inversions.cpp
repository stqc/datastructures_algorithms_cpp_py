/* Counting inversions in an array*/

#include<iostream>
#include<vector>

using namespace std;
int count_inversions(vector<int> &x);

int main(){
vector<int> arr ={1,3,5,2,4,6};
cout<<"unsorted array: ";
for (int i = 0; i< arr.size(); i++){
    cout<<"["<<arr[i]<<"]";
}
cout<<"\n";
int inversions = count_inversions(arr);
cout<<"\ninversions in the array: "<<inversions<<"\n\n";

cout<<"sorted array: ";
for (int i = 0; i< arr.size(); i++){
    cout<<"["<<arr[i]<<"]";
}
cout<<"\n";
}

int count_inversions(vector<int> &x){
int mid = x.size()/2;
vector<int> left,right;

/* dividing the vector in left and right parts as long as,
 the length of the main array is greater than 1*/
if (x.size()>1){
    for( int i = 0; i < mid; i++){
        left.push_back(x[i]);
    }
    for (int j = mid; j<x.size(); j++){
        right.push_back(x[j]);
    }
    count_inversions(left); // recursive call
    count_inversions(right); // recursive call

}
int i=0, j=0, k=0;
int inversion =0;
//merging loop
while(i <left.size() && j < right.size()){
    if(left[i]<=right[j]){
        x[k]=left[i];
        i++;

    }
    /*inversions are incremented as mid_index_of_original_array - i
        since, if the element on right side is smaller then all the remaining
        elements on the left side are also greater than the element on the right*/
    else
    if(left[i]>right[j]){
        x[k]=right[j];
        j++;
        inversion+=left.size()-i;
    }
    k++;
}
// one of these loops will execute
while (i <left.size()){
    x[k]=left[i];
    i++;
    k++;
}
while(j<right.size()){
    x[k]=right[j];
    j++;
    k++;
}
return inversion;
}
