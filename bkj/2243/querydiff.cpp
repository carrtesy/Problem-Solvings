int query(int node, int left, int right, int target){
    if(left == right){
        return left
    } else {
        int mid = (left+right)/2;
        if(tree[node*2] >= target){
       //왼쪽 값이 쿼리를 포함
            return query(node*2, left, right, target);
        } else {
        //포함 X
            return query(node*2+1, mid+1, right, target - tree[node*2]);
        }
    }
}
