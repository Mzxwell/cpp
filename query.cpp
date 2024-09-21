//
// Created by Jinx on 24-9-21.
//
#include "iostream"

using namespace std;

int max(int arr[]) {
    int r = 0;
    for (int i = 97; i < 123; ++i) if (arr[i] > r)r = arr[i];
    return r;
}

int main() {
    int q, r[123] = {0}, m;
    string word, com;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        cin >> com;
        if (com == "add") {
            cin >> word;
            for (auto a: word)
                r[a]++;
        } else if(com=="query"){
            m = max(r);
            if(m)for (int j = 97; j < 123; j++)if (r[j] == m)cout << ((char) j);
            cout<<endl;
        }
    }
}