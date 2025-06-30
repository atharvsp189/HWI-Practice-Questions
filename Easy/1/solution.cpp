#include<iostream>
#include<vector>
using namespace std;

int calculate_query2_sum(vector<int> A, vector<vector<int>> queries){
    if(A.size() == 0){
        return 0;
    }
    int sum = 0;
    for(vector<int> q:queries){
        if(q[0] == 1){
            int l = q[1], r = q[2];
            for(int i=l;i<=r;i++){
                A[i] = (i-l+1)*A[l];
            }
        }
        if(q[0] == 2){
            int l = q[1], r = q[2];
            for(int i=l;i<=r;i++){
                sum += A[i];
            }
        }
    }
    return sum;
}

int main(){
    vector<int> A = {1, 4, 5, 1, 6, 7, 8};
    vector<vector<int>> queries = {{1, 1, 6}, {1, 1, 5}, {2, 5, 5}, {2, 3, 4}, {2, 3, 3}};
    cout<<calculate_query2_sum(A, queries);

    return 0;
}