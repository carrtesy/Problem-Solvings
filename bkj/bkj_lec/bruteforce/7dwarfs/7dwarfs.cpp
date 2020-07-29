#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int get_bitmap(int * heights, int sum, int depth, int bitmap){
  if(depth > 9 || sum > 100){
    return -1;
  }
  if(sum == 100){
    return bitmap;
  } else {
    int take, ntake;
    // take
    take = get_bitmap(heights, sum + heights[depth], depth+1, bitmap | 1<<depth);
    if(take != -1){
      return take;
    }
    // not take
    ntake = get_bitmap(heights, sum, depth+1, bitmap);
    if(ntake != -1){
      return ntake;
    }
    return -1;
  }

}

int main(void){
  int N = 9;
  int *heights = new int[N];
  vector <int> v;

  for(int i = 0; i < N; i++){
    cin>>heights[i];
  }

  int bitmap = get_bitmap(heights, 0, 0, 0);
  for(int i = 0; i < N; i++){
    if(bitmap & (1<<i)){
      v.push_back(heights[i]);
    }
  }

  sort(v.begin(), v.end());

  vector<int>::iterator iter;
  for(iter = v.begin(); iter != v.end(); ++iter){
    cout << *iter << endl;
  }
  
}
