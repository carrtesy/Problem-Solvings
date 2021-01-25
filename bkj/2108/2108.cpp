#include <iostream>
#include <cstring>
#include <stack>
#include <cmath>

using namespace std;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    int *arr = new int[N];
    int radix[8001];
    memset(radix, 0, sizeof(radix));
    
    int minimum = 4001;
    int maximum = -4001;
    int s = 0;
    for(int i = 0; i < N; i++){
        int n;
        cin >> n;
        radix[n+4000]++;
        if(n < minimum) minimum = n;
        if(n > maximum) maximum = n;
        s += n;
    }


    int idx = 0;
    for(int i = 0; i < N; i++){
        while(!radix[idx]) idx++;
        int freq = radix[idx];
        while(freq--){
            arr[i++] = idx - 4000;
        }
        i--;
        idx++;
    }

    int maxfreq_num;
    int maxfreq = 0;
    for(int i = 8000; i >= 0; i--){
        maxfreq = max(radix[i], maxfreq);
    }

    stack <int> st;   
    for(int i = 8000; i >= 0; i--){
        if(radix[i] == maxfreq){
            st.push(i - 4000);
        }
    }

    if(st.size() > 1){
        st.pop();
    }
    maxfreq_num = st.top();
    
    cout << round((double)s/N) << endl;
    cout << arr[N/2] << endl;
    cout << maxfreq_num << endl;
    cout << maximum - minimum << endl;

}
