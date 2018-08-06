/*
 * [71] Simplify Path
 *
 * https://leetcode.com/problems/simplify-path/description/
 *
 * algorithms
 * Medium (26.78%)
 * Total Accepted:    120.4K
 * Total Submissions: 449.4K
 * Testcase Example:  '"/home/"'
 *
 * Given an absolute path for a file (Unix-style), simplify it.
 * 
 * For example,
 * path = "/home/", => "/home"
 * path = "/a/./b/../../c/", => "/c"
 * 
 * Corner Cases:
 * 
 * 
 * Did you consider the case where path = "/../"?
 * In this case, you should return "/".
 * Another corner case is the path might contain multiple slashes '/' together,
 * such as "/home//foo/".
 * In this case, you should ignore redundant slashes and return "/home/foo".
 * 
 * 
 */
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> names;
        string name;
        for (int i = 1; i <= path.length(); i++) {
            if (path[i] == '/' || i == path.length()) {
                if (!name.empty()) {
                    if (name == "..") {
                        if(!names.empty())
                            names.pop_back();
                    }
                    else if (name != ".")
                        names.emplace_back(name);
                    name = "";
                }
            }
            else
                name.push_back(path[i]);
        }
        string res = "";
        for (string & name : names)
            res += "/" + name;
        if (res.empty()) // really important
            res = "/";
        return res;
    }
};
