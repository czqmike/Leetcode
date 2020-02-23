#include <iostream> 
#include <fstream>
#include <vector>
#include <set>
#include <map>
using namespace std;

int main() {
    vector<int> nums = {9, 1, 7, 9, 7, 9, 7};

    map<int, int> m;
    for (auto num : nums) {
        auto it = m.find(num);
        if ( it == m.end()) {
            m.insert(pair<int, int> (num, 1));
        } else {
            it->second += 1; 
        }
    }

    int ret = 0;
    for (auto p : m) {
        // cout << p.first << " " << p.second << endl;
        if (p.second == 1) {
            ret = p.first;
            break;
        }
    }
    // cout << "ret = " << ret << endl;

    return 0;
}