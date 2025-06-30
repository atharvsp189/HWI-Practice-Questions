#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int max_good_subarray_sum(vector<int> A, int k){
    int N = A.size();
    if(N==0) return 0;

    int left = 0;
    int curr_sum = 0;
    int max_sum = 0;
    unordered_map<int, int> freq;

    for(int right = 0; right<N;right++){
        freq[A[right]] += 1;
        curr_sum += A[right];

        while(freq.size() > k){
            freq[A[left]] -= 1;
            curr_sum -= A[left];

            if(freq[A[left]] == 0){
                freq.erase(A[left]);
            }
            left += 1;
        }
        max_sum = max(max_sum, curr_sum);
    }

    return max_sum;
}

int main(){
    vector<int> A = {1, 2, 2, 3, 2, 3, 5, 1, 2, 1, 1};
    int k = 2;
    cout<<max_good_subarray_sum(A, k); // output: 12

    return 0;
}