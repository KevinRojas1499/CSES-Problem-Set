#include <bits/stdc++.h>
#define ll long long


using namespace std;


bool in(ll x, ll y){
    return 0<=x && x<8 && 0<=y && y<8;
}


int main(){
    ll a,b;
    cin>>a>>b;
    a--,b--;
    swap(a,b);
    ll curStep = 2;
    ll order[8][8], board[8][8];

    bool chosen[8][8];
    memset(chosen,false, sizeof chosen);
    memset(order,0, sizeof order);
    memset(board, 0, sizeof board);
    ll dirX[] = {-1,1,-1,  1, -2,  2, -2 ,2};
    ll dirY[] = {-2,2, 2, -2,  1, -1, -1, 1};

    for(int i = 0; i<8; i++){
        for(int j = 0; j<8; j++){
            for(int k = 0; k<8; k++){
                ll nX = i+dirX[k];
                ll nY = j+dirY[k];
                if(in(nX,nY)){
                    board[i][j]++;
                }
            }
        }
    }

    stack<pair<ll,ll>> st;
    st.push({a,b});
    chosen[a][b] = 1;
    order[a][b] = 1;
    while(st.size()){
        auto [x,y] = st.top();
        st.pop();
        pair<ll,ll> next = {-1,-1};
        ll cur = 1e9;
        for(int i = 0; i<8; i++){
            ll nX = x+dirX[i];
            ll nY = y+dirY[i];
            if(in(nX,nY) && !chosen[nX][nY]){
                if(board[nX][nY]< cur ){
                    next = {nX,nY};
                    cur = board[nX][nY];
                }
            }
        }
        if(next.first != -1){
            st.push(next);
            chosen[next.first][next.second] = 1;
            order[next.first][next.second] = curStep;
            curStep++;
            for(int i = 0; i<8; i++){
                ll nX = x+dirX[i];
                ll nY = y+dirY[i];
                if(in(nX,nY) && !chosen[nX][nY]){
                    board[nX][nY]--;
                }
            }
        }
    }
    for(int i = 0; i<8; i++){
        for(int j = 0; j<8; j++){
            cout<<order[i][j]<<" ";
        }
        cout<<endl;
    }
}