//
// Created by Jinx on 24-11-27.
//
#include <vector>
#include "iostream"

using namespace std;
struct plant {
    int HP, ATK;
    string type0;
    bool pf = false;
};
struct zombie {
    int HP, ATK, SPEED, Y;
};

void pat(vector<zombie> z, int atk, int y) {
    for (int k = 0; k < z.size(); ++k)
        if (z[k].Y >= y - 1 && z[k].Y <= y + 1) {
            z[k].HP -= atk;
            if (z[k].HP <= 0)z.erase(z.begin() + k);
        }
}

int main() {
    int num_p, num_z;
    cin >> num_p >> num_z;
    plant *map0[5][9] = {nullptr};
    vector<zombie> zombies[5];
    for (int i = 0; i < num_p; ++i) {
        int X, Y;
        plant *p = new plant();
        cin >> p->type0 >> p->HP >> p->ATK >> X >> Y;
        map0[X][Y] = p;
    }
    for (int i = 0; i < num_z; ++i) {
        int HP, ATK, SPEED, X;
        cin >> HP >> ATK >> SPEED >> X;
        zombies[i].push_back({HP, ATK, SPEED, 9});
    }
    bool z_win = false;
    for (int l = 1;; ++l) {
        for (int i = 0; i < 5; ++i)
            for (int j = 0; j < 9; ++j)
                if (map0[i][j]) {
                    plant *tmp = map0[i][j];
                    if (tmp->type0 == "pea") {
                        int y = j;
                        for (auto p: zombies[i]) if (p.Y >= j && p.Y <= y)y = p.Y;
                        for (int k = 0; k < zombies[i].size(); ++k)
                            if (zombies[i][k].Y == y) {
                                zombies[i][k].HP -= tmp->ATK;
                                if (zombies[i][k].HP <= 0)zombies[i].erase(zombies[i].begin() + k);
                            }
                    } else if (tmp->type0 == "potato" && tmp->pf) {
                        if (i > 0)pat(zombies[i - 1], tmp->ATK, j);
                        pat(zombies[i], tmp->ATK, j);
                        if (i < 4)pat(zombies[i + 1], tmp->ATK, j);
                    }
                }
        for (int i = 0; i < 5; ++i)
            for (auto &p: zombies[i])
                for (int j = 0; j < p.SPEED; ++j) {
                    if (p.Y < 9 && map0[i][p.Y]) {
                        if (map0[i][p.Y]->type0 == "potato")map0[i][p.Y]->pf = true; else break;
                    }
                    if (--(p.Y) < 0) {
                        z_win = true;
                        break;
                    }
                }
        if (!z_win)
            for (int i = 0; i < 5; ++i)
                for (auto &p: zombies[i])
                    if (p.Y < 9 && map0[i][p.Y] && map0[i][p.Y]->type0 != "potato") {
                        map0[i][p.Y]->HP -= p.ATK;
                        if (map0[i][p.Y]->HP <= 0)map0[i][p.Y] = nullptr;
                    }
        int rem_p = 0, rem_z = 0;
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 9; ++j)if (map0[i][j])rem_p++;
            rem_z += zombies[i].size();
        }
        cout << l << ' ' << rem_p << ' ' << rem_z << endl;
        if (z_win) {
            cout << "zombies win";
            break;
        }
        if(rem_z==0){
            cout << "plants win";
            break;
        }
    }
}