//searching an array/vector with quick sort

#include<iostream>
#include<vector>


using namespace std;
void Rselect(vector<int> &vec, int id, int start, int last); // search function declaration

int main(){

int id;
vector<int> x  = {300, 600, 800, 900, 101, 20, 1009, 102, 270, 1800, 160,30,500,109}; // arbitrary vector to search from

cout<<"Given Array: ";
for(int i =0; i <x.size(); i++)
{
        cout<<x[i]<<" ";
}

cout<<"\nEnter the n smallest number to find: ";
cin>>id;

Rselect(x, id, 1, x.size()); // function call

}

void Rselect(vector<int> &vec, int id, int start, int last){ // function definition
    int pivot  = vec[start-1];
    int i = start;
    int j;
    //main loop to sort a sub vector to look for the element
    for (j= start; j<last; j++){
        if(vec[j]<=pivot){
            int temp = vec[i];
            vec[i]= vec[j];
            vec[j]= temp;
            i++;
        }
    }
        //swapping pivot with the start value
        int temp = vec[i-1];
        vec[i-1] = pivot;
        vec[start-1] = temp;
    // checking if the index of the pivot is less than the index of the value we are looking for
    if(i-1<id-1){
        Rselect(vec,id,i+1,last); // if so we recursively call the Rselect function with the starting index being 1 more than the index of pivot.
    }
    // checking if the index of the pivot is greater than the index of the value we are looking for
    else if(i-1>id-1){
        Rselect(vec,id,start,i-1);// if so we recursively call the Rselect function with the last index being 1 less than the index of pivot.
    }
    //element found
    else if(i-1==id-1){
        cout<<"\nThe element in question is:"<<vec[i-1]<<"\n";
    }
}


