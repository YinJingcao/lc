 /**
 * @file 13_Roman_to_Integer.cpp
 * @author yinjingcao
 * @date 2018/03/15 14:04:11
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    Solution() {
        map_["M"] = 1000;
        map_["C"] = 100;
        map_["CC"] = 200;
        map_["CCC"] = 300;
        map_["CD"] = 400;
        map_["D"] = 500;
        map_["DC"] = 600;
        map_["DCC"] = 700;
        map_["DCCC"] = 800;
        map_["CM"] = 900;
        map_["X"] = 10;
        map_["XX"] = 20;
        map_["XXX"] = 30;
        map_["XL"] = 40;
        map_["L"] = 50;
        map_["LX"] = 60;
        map_["LXX"] = 70;
        map_["LXXX"] = 80;
        map_["XC"] = 90;
        map_["I"] = 1;
        map_["II"] = 2;
        map_["III"] = 3;
        map_["IV"] = 4;
        map_["V"] = 5;
        map_["VI"] = 6;
        map_["VII"] = 7;
        map_["VIII"] = 8;
        map_["IX"] = 9;
    }
    int romanToInt(const string& s) {
        int idx = 0;
        int result = 0;
        while (idx < s.size()) {
            if (map_.find(s.substr(idx, 4)) != map_.end()) {
                result += map_[s.substr(idx, 4)];
                idx += 4;
            } else if (map_.find(s.substr(idx, 3)) != map_.end()) {
                result += map_[s.substr(idx, 3)];
                idx += 3;
            } else if (map_.find(s.substr(idx, 2)) != map_.end()) {
                result += map_[s.substr(idx, 2)];
                idx += 2;
            } else if (map_.find(s.substr(idx, 1)) != map_.end()) {
                result += map_[s.substr(idx, 1)];
                ++idx;
            } else {
                return 0;
            }
        }
        return result;
    }
private:
    unordered_map<string, int> map_;
};

int main() {
    Solution s;
    printf("%d\n", s.romanToInt("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMCDLVI"));
    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
