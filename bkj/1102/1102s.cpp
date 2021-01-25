

int first_state = 0;
for(int i = 0; i < n; i++){
    if(onoff[i]){
        first_state = bit_set(first_state, i);
    }

}
dp[first_state] = 0;

// start
for(int state = 0; state < (1<<n); state++){
    for(int i = 0; i < n; i++){
        // state 상태에서 i를 켤 수 있을까?>
        // 켜게된다면 비용은?
        // 그때 state는 어떤 모양일까? > nxt_state
        // nxt_state에는 어떤 값이 있었을까?
        int nxt_state, nxt_cost;
        if(bit_check(state, i)){ // state: 발전소가 켜져 있는것, i가 켜져 있으면 skip
            continue;
        }

        nxt_state = bit_set(state, i);
        for(int j = 0; j < n; j++){ // j번째 발전소를 이용해 i를 켜자!
            if(bit_check(state, j){
                nxt_cost = dp[state] + cost[j][i];
                if(nxt_cost < dp[nxt_state]){
                    dp[nxt_state] = nxt_cost;
                }
            }
        }
    }
}

int answer = INF;
for(int i = 0; i < (1<<n); i++){
    if(bitcount(i) >= p){
        if(dp[i] < answer){
            answer = dp[i];
        }
    }
}

if(answer == INF) answer = -1;
printf("%d", answer);
