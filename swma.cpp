//
// Created by Jinx on 24-11-28.
//
#include "iostream"
#include "string"
using namespace std;

int main() {
    string type[6] = {"Chicken", "Lettuce", "Tomato", "Cheese", "Onion", "Sauce"};
    int n, t_num[6] = {0};
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string command;
        cin >> command;
        if (command == "Stock") {
            string t0;
            int j, num;
            cin >> t0 >> num;
            for (j = 0; j < 6; ++j) {
                if (type[j] == t0) {
                    break;
                }
            }
            if (j != 6) {
                t_num[j] += num;
                cout << "Stocked " << t0 << " with " << num << " units" << endl;
            }
        }
        if (command == "Order") {
            string id, re = "";
            cin >> id;
            bool b = true;
            int num, c_num[6] = {0},fre=0,fret[6],fren[6];
            while (cin.peek() != '\n') {
                string t0;
                int j;
                cin >> t0 >> num;
                for (j = 0; j < 6; ++j) {
                    if (type[j] == t0) {
                        break;
                    }
                }
                if (j != 6) {
                    c_num[j] = num;
                    if (num > t_num[j]) {
                        b = false;
                        fret[fre]=j;
                        fren[fre]=num-t_num[j];
                        fre++;
                    }
                }
            }
            if (b) {
                for (int j = 0; j < 6; ++j) {
                    t_num[j] -= c_num[j];
                }
                cout << "Order " + id + " completed" << endl;
            } else {
                cout << "Order " << id << " failed: " << "missing ";
                for (int j = 0; j < fre; ++j) {
                    cout<<type[fret[j]]<<" "<<fren[j];
                    if(j!=fre-1)cout<<", ";else cout<<endl;
                }
            }
        }
        if (command == "Inventory") {
            cout<<"=== Inventory ==="<<endl;
            for (int j = 0; j < 6; ++j) {
                cout << type[j] << ": " << t_num[j] << endl;
            }
            cout<<"================="<<endl;
        }
    }
}