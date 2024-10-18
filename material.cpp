#include "iostream"
#include "algorithm"
#include <vector>
#include <cmath>
#include <numeric>
#include <string>

using namespace std;

// 判断桶装原料价格为price时，是否能满足target吨原料
bool canMeetTarget(const vector<long long > &fund, int n, long long target100, long long price, int k) {
    long long total_raw = 0;  // 总共能买到的原料吨数 (乘以100的单位)
    int remaining_money=0;
    for (int i = 0; i < n; ++i) {
        long long full_tons = fund[i] / price;  // 采购员能买到的桶装原料数
        remaining_money += fund[i] % price;  // 剩余资金
        total_raw += full_tons * 100;  // 桶装原料按整数吨计算
        if (total_raw >= target100) return true;  // 如果已经满足需求，直接返回true
    }
    total_raw += ((remaining_money * 10000) / (price * 100 - k));  // 散装原料按精确重量计算
    return total_raw >= target100;
}

int main() {
    int n;
    double k;
    string target;
    cin >> n >> target >> k;
    size_t dot=target.find('.');
    if(dot==string::npos)target=target+".00";
    else{
        auto len=target.substr(dot+1).length();
        if(len==1)target=target+"0";
        else target=target.substr(0,dot+3);
    }
    target.erase(remove(target.begin(), target.end(), '.'), target.end());
    vector<long long > fund(n);
    for (int i = 0; i < n; ++i) cin >> fund[i];

    // 将target转化为整数来避免浮点数误差
    long long target100 = stoll(target);
    int k100 = round(k * 100);  // k也转化为整数

    // 二分查找最大桶装原料价格
    auto sum=accumulate(fund.begin(), fund.end(), 0ll);
    long long left = 2, right = 100*sum/target100+1;
    if (right < 2)right = 2;// 单位千元，桶装原料价格区间
    long long result = -1;

    while (left <= right) {
        long long mid = (left + right) / 2;
        if (canMeetTarget(fund, n, target100, mid, k100)) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;  // mid价格不能满足需求，降低价格
        }
    }

    cout << result << endl;

    return 0;
}