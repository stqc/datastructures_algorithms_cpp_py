// Quick sort in C++ using vectors

#include<iostream>
#include<vector>

using namespace std;

void quick_sort(vector<int> &arr , int low, int high); //function declaration

int main(){

    vector<int> arr = {2,3,-7,4,0,9,2,1,7,1,-9,11,10,15,12};
    int x = arr.size();

    cout<<"Before sorting: ";
    for(int i =0; i < x; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n\n";

    quick_sort(arr,1,x);// function call

    cout<<"After sorting: ";
    for(int i =0; i < x; i++)
    {
        cout<<arr[i]<<" ";
    }

}
void quick_sort(vector<int> &arr,int low, int high) // function definition starts here
{
    // pivot value is set as the first element in the vector/array

    int i = low; // setting a variable i to be equal to the value of low
    int temp; // temporary variable for swapping

    // main loop
    for(int j=i; j<high; j++){

        if (arr[j]<=arr[low-1]){ // if the jth value of of the vector/array is lower than or equal to than that of the pivot value
            temp = arr[i];      // we swap the ith element with the jth element of the vector/array and increment i
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }
    }

temp = arr[i-1]; // then we swap the pivot value with the i-1th value in the vector/array
arr[i-1] = arr[low-1];
arr[low-1] = temp;

if(low< high){ // and finally we check if the low value if less than the high value passed as arguments
    quick_sort(arr,low,i-1); // recursive call for the left side of the vector/array
    quick_sort(arr,i+1,high); // recursive call for the right side of the vector/array
        }
}

