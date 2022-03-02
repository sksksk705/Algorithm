#include <bits/stdc++.h>

using namespace std;

int weight[31];
int n;
int dp[55001][31];

int checkCanWeight(int marble,int idx){
    int& ret = dp[marble][idx];
    if (ret != 0)
        return ret;
    if (marble < 0)
        return 1;
    if(marble == 0)
        return 2;
    for(int i = idx+1;i < n;++i){
        ret = max(ret, checkCanWeight(marble + weight[i], i));
        ret = max(ret, checkCanWeight(marble - weight[i], i));
    }
    return ret;
}

int main(){
    cin>>n;
    int sum = 0;
    for(int i = 0; i< n;++i){
        cin>>weight[i];
        sum += weight[i];
    }
    int m;
    cin>>m;
    for(int i = 0; i <m;++i){
        int ball;
        cin >> ball;
        if (ball > sum || checkCanWeight(ball, -1) != 2)
            cout << "N ";
        else
            cout<<"Y ";
    }
    return 0;
}