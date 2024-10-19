#include "iostream"

using namespace std;

int main() {
    int n, m, t = 0, *idt;
    cin >> n >> m;
    int *max = new int[n + 1](), *id = new int[m], *price = new int[m], *buy = new int[m];
    for (int i = 0; i < m; i++) {
        string action;
        cin >> action >> id[i] >> price[i];
        buy[i] = (action == "buy");
    }
    for (int i = m-1; i >= 0; i--){
        idt = max + id[i];
        if (*idt == 0 || price[i] > *idt)*idt = price[i];
        else if (buy[i])t += *idt - price[i];
    }
    cout << t;
    delete[]max;
    delete[]id;
    delete[]price;
    delete[]buy;
}