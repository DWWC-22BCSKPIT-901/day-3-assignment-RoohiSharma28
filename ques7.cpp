#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> charIndex;
    int maxLength = 0, start = 0;

    for (int i = 0; i < s.length(); ++i) {
        if (charIndex.find(s[i]) != charIndex.end() && charIndex[s[i]] >= start) {
            start = charIndex[s[i]] + 1;
        }
        charIndex[s[i]] = i;
        maxLength = max(maxLength, i - start + 1);
    }

    return maxLength;
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    int result = lengthOfLongestSubstring(input);
    cout << "The length of the longest substring without repeating characters is: " << result << endl;

    return 0;
}
