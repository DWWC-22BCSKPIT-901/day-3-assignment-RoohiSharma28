#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

string makeLargestSpecial(string s) {
    int count = 0, start = 0;
    vector<string> specialSubstrings;

    for (int i = 0; i < s.size(); ++i) {
        count += (s[i] == '1') ? 1 : -1;
        if (count == 0) {
            string inner = makeLargestSpecial(s.substr(start + 1, i - start - 1));
            specialSubstrings.push_back("1" + inner + "0");
            start = i + 1;
        }
    }

    sort(specialSubstrings.rbegin(), specialSubstrings.rend());
    return accumulate(specialSubstrings.begin(), specialSubstrings.end(), string(""));
}

int main() {
    string s;
    cout << "Enter a special binary string: ";
    cin >> s;

    string result = makeLargestSpecial(s);
    cout << "Lexicographically largest special binary string: " << result << endl;

    return 0;
}
