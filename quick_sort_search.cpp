//searching an array/vector with quick sort

#include<iostream>
#include<vector>


using namespace std;
void Rselect(vector<int> &vec, int id, int start, int last); // search function declaration

int main(){

int id;
vector<int> x  = {3, 6, 8, 9, 11, 2, 19, 12, 27, 18, 16};
cout<<"Given Array: ";
for(int i =0; i <x.size(); i++)
{
        cout<<x[i]<<" ";
}

cout<<"\nEnter the n smallest number to find: ";
cin>>id;

Rselect(x, x.size(), id, 1, x.size());

}

void Rselect(vector<int> &vec, int len, int id, int start, int last){
    int pivot  = vec[start-1];
    int i = start;
    int j;
    for (j= start; j<last; j++){
        if(vec[j]<pivot){
            int temp = vec[i];
            vec[i]= vec[j];
            vec[j]= temp;
            i++;
        }
    }
        int temp = vec[i-1];
        vec[i-1] = pivot;
        vec[start-1] = temp;
    if(i-1<id-1){
        Rselect(vec,vec.size(),id,i+1,last);
    }
    else if(i-1>id-1){
        Rselect(vec,len,id,start,i-1);
    }
    else if(i-1==id-1){
        cout<<"\nThe element in question is:"<<vec[i-1];
    }
}


