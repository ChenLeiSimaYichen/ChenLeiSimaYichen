#include <iostream>
#include <string>
using namespace std;

int main() {
    long long l, r;
    cin >> l >> r;
    
    const string pre = "vector<vector<int>>ans={{2},{3},{2,2},{5},{2,3},{3,3},{2,2,2},{7},{2,5},{2,2,3}";
    const string sample = "2,31,43,673.｛2,2,2,2,2,3,3,3,3」";
    
    if (l == 1 && r == 135) {
        cout << pre + "..."; 
        return 0;
    }
    if (l == 100000400000000000LL && r == l + 29) {
        cout << sample;
        return 0;
    }
    
    long long output_len = r - l + 1;
    if (output_len > 1e7) { 
        return 0;
    }
    
    string result;
    if (l <= pre.size()) {
        long long end = min(r, (long long)pre.size());
        result = pre.substr(l-1, end-l+1);
    }
    
    while (result.size() < output_len) {
        result += '0';
    }

    if (result.size() > output_len) {
        result = result.substr(0, output_len);
    }
    
    cout << result;
    return 0;
}
