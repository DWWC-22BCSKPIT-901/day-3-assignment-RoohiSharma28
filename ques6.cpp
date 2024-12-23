#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int findGCD(vector<int>& nums) {
    int smallest = *min_element(nums.begin(), nums.end());
    int largest = *max_element(nums.begin(), nums.end());
    return gcd(smallest, largest);
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int result = findGCD(nums);
    cout << "The greatest common divisor of the smallest and largest number is: " << result << endl;

    return 0;
}
