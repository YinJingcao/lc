/**
 * @file 93_Restore_IP_Addresses.cpp
 * @author yinjingcao
 * @date 2018/04/04 17:28:52
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(const string& s) {
        vector<string> result;
        if (s.size() < 4) {
            return result;
        }
        for (int i1 = 0; i1 < s.size(); ++i1) {
            string ip1 = s.substr(0, i1 + 1);
            if (!valid(ip1)) {
                break;
            }
            for (int i2 = i1 + 1; i2 < s.size(); ++i2) {
                string ip2 = s.substr(i1 + 1, i2 - i1);
                if (!valid(ip2)) {
                    break;
                }
                for (int i3 = i2 + 1; i3 < s.size(); ++i3) {
                    string ip3 = s.substr(i2 + 1, i3 - i2);
                    string ip4 = s.substr(i3 + 1, s.size() - i3 - 1);
                    if (!valid(ip3) || !valid(ip4)) {
                        continue;
                    }
                    string ip = ip1 + "." + ip2 + "." + ip3 + "." + ip4;
                    result.push_back(ip);
                }
            }
        }
        return result;
    }

private:
    bool valid(const string& ip) {
        if (ip == "") {
            return false;
        } else if (ip.size() != 1 && ip[0] == '0') {
            return false;
        }
        int a = atoi(ip.c_str());
        if (a >= 0 && a < 256) {
            return true;
        }
        return false;
    }

};

int main() {
    Solution s;
    vector<string> result;
    result = s.restoreIpAddresses("010010");
    for (size_t idx = 0; idx < result.size(); ++idx) {
        printf("%s\n", result[idx].c_str());
    }
    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
