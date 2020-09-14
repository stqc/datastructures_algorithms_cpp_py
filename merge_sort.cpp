//Merge Sort

#include<iostream>
#include<vector>

using namespace std;

void merge_sort(vector<int> &arr);

int main(){
    vector<int> x={3,6,1,0,9,7,99,78,1,-1,-11,123,128,-9,123,128,-9,27,97,112,69,8,99};
    cout<<"Unsorted array: ";
    for (int i=0 ; i <x.size();i++)
        cout<<x[i]<<" ";
    merge_sort(x);
    cout<<"\n\nSorted array: ";
    for (int i=0 ; i <x.size();i++)
        cout<<x[i]<<" ";
cout<<"\n";
}

void merge_sort(vector<int> &arr){
    int len = arr.size();
    vector<int> left;
    vector<int> rl;
/* dividing the vector in left and right parts as long as,
 the length of the main array is greater than 1*/
    if(len>1){

        for(int i= 0; i < len/2; i++){
            left.push_back(arr[i]);
        }

        for(int j= len/2; j<len ; j++){
            rl.push_back(arr[j]);
        }

    merge_sort(left); // recursive call
    merge_sort(rl); // recursive call
    }

    int i=0,j=0,k=0;

    //merging loop
    while(i<left.size() && j<rl.size()){
        if(left[i]<=rl[j]){
            arr[k]=left[i];
            i++;
        }
        else
            if(rl[j]<=left[i]){
                arr[k]=rl[j];
                j++;
            }
            k++;
    }
    while(j<rl.size()){
        arr[k]=rl[j];
        k++;
        j++;
    }
    while(i<left.size()){
        arr[k]=left[i];
        k++;
        i++;
    }

}
