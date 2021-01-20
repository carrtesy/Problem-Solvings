#include <iostream>

using namespace std;
// find ax + by = c -> as + bt = r
// until r = gcd(a, b) 
void eGCD(int a, int b){
    int s0 = 1, t0 = 0, r0 = a;
    int s1 = 0, t1 = 1, r1 = b;

    int tmp;
    while(r1 != 0){
        int q = r0 / r1;
        tmp = r0 - q * r1; // new r
        r0 = r1;
        r1 = tmp;
        
        tmp = s0 - q* s1;
        s0 = s1;
        s1 = tmp;
        
        tmp = t0 - q* t1;
        t0 = t1;
        t1 = tmp;
        
    }
    cout << s0 << t0 << r0 << endl;
}


// X
// Y
// A * x + 1 = B * Y
// -AX + BY = 1
// A(-X) + BY = 1
// D = gcd(A, B)
// D * k = C > C%D ==0 -> sol yes

//s, t, r
// x0 = s * C / D
// y0 = t * C / D

// general
// x = x0 + B/D * k
// y = y0 - A/D * k

// x < 0

// cond
// 0 < x  => 0 > x
// 0 < y <= 10^9


int main(void){
    eGCD(71, 240);

 
    int A, B;
    // s,t, r = D
    // x0 = s * C / D
    // y0 = t * C / D
    result = egcd(a,b) // s.t.r
    if(result[2] != 1){
        cout << "IMPOSSIBLE" << endl;
    } else{
        int x0 = result[0]; // C = 1 D = 1
        int y0 = result[1];
    }


    // general solution
    // x = x0 + B / D * k
    // y = y0 - A / D * k

    // x < 0
    // x0 + B / D * k < 0
    // k < -x0 + B / D

    // 0 < y <= 1e9
    // 0 < y0 - A/D * k <= 1e9
    //-y0 < - A/D*k <= 1e9 - y0
    // (y0 - 1e9) / A * D <= k < y0 / A * D

    // y0-1e9 / A * D <= k < y0 / A *D
                   //    k < -x0 / B * D
    ll kFromY = (long)math.ceil((double)y0/(double)A) // (* D) .. D =1
    ll kFromX = (long)math.ceil((double) -x0/(double)B) // (* D) .. D =1
    //k의 max를 구한 후 k를 이용해 y 구하기 k가 커지면 y가 작아지므로
    ll k = min(kFromX, kFromY);
    ll y = y0-A*k;

    //그렇게 구한 y는 가장 작은 y값
    if(y <= 1e9){
        cout << y << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
}
