#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> temps;
    __int64_t sum = 0;
    for (int i = 0; i < N; i++){
        int a;
        cin >> a;
        sum += a;
        temps.push_back(a);
    }
    sum /= N;
    vector<int> t2;
    for (int i = 0; i < N; i++) {
        if (temps[i] > sum)
            t2.push_back(i);
    }
    cout << t2.size() << endl;
    for (int i = 0; i < t2.size(); i++) {
        cout << t2[i];
        if (i + 1 < t2.size())
            cout << " ";
    }
    /**/
    //cout << numeric_limits<__int64_t>::max();
    return 0;
}