/**
 * @file 71_Simplify_Path.cpp
 * @author yinjingcao
 * @date 2018/03/27 20:12:09
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        if (path.empty()) return path;
        stack<string> t;
        for (int idx = 0; idx < path.size(); ) {
            string str = get_real_path(path, idx);
            if (str == "..") {
                if (!t.empty()) {
                    t.pop();
                }
            } else if (str != "." && str != "") {
                t.push(str);
            }
        }
        string result;
        while (!t.empty()) {
            result = "/" + t.top() + result;
            //printf("r=%s, t=%s\n", result.c_str(), t.top().c_str());
            t.pop();
        }
        if (result.empty()) return "/";
        return result;
    }
private:
    string get_real_path(string& path, int& start_pos) {
        int idx = start_pos;
        string result;
        while (idx < path.size()) {
            if (path[idx] == '/' && !result.empty()) {
                ++idx;
                break;
            } else if (path[idx] != '/') {
                result += path[idx++];
            } else {
                ++idx;
            }
        }
        start_pos = idx;
        return result;
    }
};

int main() {
    Solution s;
    printf("%s\n", s.simplifyPath("/a/bc/defg/acd/./../../").c_str());
    printf("%s\n", s.simplifyPath("/home/").c_str());
    printf("%s\n", s.simplifyPath("/a/./b/../../c/").c_str());
    printf("%s\n", s.simplifyPath("/a/./b///../c/../././../d/..//../e/./f/./g/././//.//h///././/..///").c_str());
    printf("%s\n", s.simplifyPath("/..").c_str());
    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
