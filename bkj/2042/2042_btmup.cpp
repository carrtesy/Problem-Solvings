S


void makeTree(){
    for(int i = 0; i < N; i++){
        tree[S + i] = nums[i+1];
    }

    for(int i = S-1; i >0 i--){
        tree[i] = tree[i*2] + tree[i*2+1]
    }
}

void query(int left, right){
    long result = 0;
    left += S-1;
    right += S-1;
    
    while(left <= right){
        if(left%2 == 1){
            result += tree[left++];
        }

        if(right%2 == 1){
            result += tree[right--];
        }
        
        left /= 2;
        right /= 2;
    }
}

void update(int index, int value){
    index += S -1 ; 
    tree[index] = value;
    index /= 2;
    while(index >= 1){
        tree[index] = tree[index * 2] + tree[index * 2+ 1];
        index /= 2;
    }
}
