#include<iostream>
#include<vector>
using namespace std;

int min_initial_oil(int C, vector<int> A){
    int curr_oil = 0;
    int min_oil_required = 0;

    for(int order:A){
        if(order == -1){ // Buy
            curr_oil -= 1;
            if(curr_oil < 0){
                min_oil_required += 1;
                curr_oil = 0;
            }
        }else{
            curr_oil += 1;
            if(curr_oil > C){
                curr_oil = C;  
            }
        }
    }

    return min_oil_required;
}

int main(){
    int N = 3;
    int C = 2;
    vector<int> A = {-1, -1, 1};

    cout<<min_initial_oil(C, A);
    return 0;
}