#include <iostream>
#include <vector>

using namespace std;

int main(){
    int average_metr = 0, N, count = 0;
    cin >> N;
    vector<int> temp(N), news;
    for (int i = 0; i < N; i++){
        cin >> temp[i];
        average_metr += temp[i];
    } 
    average_metr /= N;
    for (int i = 0; i < N; i++)
        if (temp[i] > average_metr){
            count++;
            news.push_back(i);
        }
    cout << count << endl;
    for (auto &a : news)
        cout << a << " ";
    cout << endl;
    return 0;
}