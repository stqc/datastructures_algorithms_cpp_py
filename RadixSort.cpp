#include<iostream>
#include<vector>

using namespace std;

void countSort(vector<int> &arr, int mxnum){
    vector<int> ar1 = arr;

    while(mxnum>0){
            cout<<"\n";
        vector<int> ar2 ;
        vector<int> b;
        for(int i=0; i<ar1.size(); i++){
                b.push_back(0);
                ar2.push_back(ar1[i]%10);
                ar1[i]/=10;

        }

        int maxNum =0;

        for(int i=0; i<ar2.size();i++){
            if(maxNum<ar2[i]){
                maxNum=ar2[i];
            }
        }

        vector<int> c;
        for(int i=0; i<=maxNum; i++){
            c.push_back(0);
        }

        for(int i=1; i<ar2.size();i++){
            c[ar2[i]]++;
        }
        for(int i=2; i<c.size();i++){
            c[i]=c[i]+c[i-1];
        }


        for(int i=ar2.size()-1;i>0;i--){
            b[c[ar2[i]]]=arr[i];
            c[ar2[i]]-=1;
        }


        mxnum/=10;
        cout<<"\n";
        if(mxnum==0){
            arr=b;
        }
    }

}

void radixSort(vector<int> &arr){
    arr.insert(arr.begin(),0);
    int maxNum =0;

    for(int i=0; i<arr.size(); i++){
        if(maxNum<arr[i]){
            maxNum=arr[i];
        }
    }

    countSort(arr,maxNum);



}

int main(){

vector<int> arr = {110,980,387,258,196};
radixSort(arr);
for(int i=1; i<arr.size();i++){
    cout<<arr[i]<<" ";
}

}
