#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    // Helper to count required factors of 2, 3, 5, 7 for a number
    bool countFactors(long long t, vector<int>& factors) {
        while (t % 2 == 0) { factors[0]++; t /= 2; }
        while (t % 3 == 0) { factors[1]++; t /= 3; }
        while (t % 5 == 0) { factors[2]++; t /= 5; }
        while (t % 7 == 0) { factors[3]++; t /= 7; }
        return t == 1; // Returns false if t has prime factors other than 2, 3, 5, 7
    }

    // Helper to extract factors from a single digit
    void addDigitFactors(int d, vector<int>& factors, int sign) {
        if (d <= 1) return;
        if (d == 2) factors[0] += sign;
        else if (d == 3) factors[1] += sign;
        else if (d == 4) factors[0] += 2 * sign;
        else if (d == 5) factors[2] += sign;
        else if (d == 6) { factors[0] += sign; factors[1] += sign; }
        else if (d == 7) factors[3] += sign;
        else if (d == 8) factors[0] += 3 * sign;
        else if (d == 9) factors[1] += 2 * sign;
    }

    // Greedily generates the minimal string of digits needed to satisfy required factors
    string getMinDigitsNeeded(const vector<int>& required) {
        int n2 = max(0, required[0]);
        int n3 = max(0, required[1]);
        int n5 = max(0, required[2]);
        int n7 = max(0, required[3]);

        string suffix = "";
        // 7s and 5s can only be satisfied by themselves
        suffix.append(n7, '7');
        suffix.append(n5, '5');

        // Combine 3s into 9s
        suffix.append(n3 / 2, '9');
        n3 %= 2;

        // Combine 2s into 8s
        suffix.append(n2 / 3, '8');
        n2 %= 3;

        // Combine remaining 2 and 3 into a 6
        if (n3 == 1 && n2 >= 1) {
            suffix.push_back('6');
            n3 = 0;
            n2--;
        }
        
        // Handle left over factors
        if (n3 == 1) suffix.push_back('3');
        if (n2 == 2) suffix.push_back('4');
        else if (n2 == 1) suffix.push_back('2');

        sort(suffix.begin(), suffix.end());
        return suffix;
    }

public:
    string smallestNumber(string num, long long t) {
        vector<int> targetFactors(4, 0);
        if (!countFactors(t, targetFactors)) return "-1";

        int n = num.length();
        // Track prime factors contributed by each prefix position
        vector<vector<int>> prefixFactors(n + 1, vector<int>(4, 0));
        int firstZero = -1;

        for (int i = 0; i < n; ++i) {
            prefixFactors[i + 1] = prefixFactors[i];
            if (num[i] == '0' && firstZero == -1) {
                firstZero = i;
            }
            if (firstZero == -1) {
                addDigitFactors(num[i] - '0', prefixFactors[i + 1], 1);
            }
        }

        // Case 1: Check if the original number itself is zero-free and valid
        if (firstZero == -1) {
            bool valid = true;
            for (int j = 0; j < 4; ++j) {
                if (prefixFactors[n][j] < targetFactors[j]) valid = false;
            }
            if (valid) return num;
        }

        // Case 2: Backtrack from the rightmost modifiable position
        int startPos = (firstZero == -1) ? n - 1 : firstZero;
        for (int i = startPos; i >= 0; --i) {
            int currentDigit = num[i] - '0';
            for (int d = currentDigit + 1; d <= 9; ++d) {
                vector<int> req(4);
                for (int j = 0; j < 4; ++j) {
                    req[j] = targetFactors[j] - prefixFactors[i][j];
                }
                // Add factors of the newly placed digit `d`
                addDigitFactors(d, req, -1);

                string minSuffix = getMinDigitsNeeded(req);
                int remSpaces = n - 1 - i;

                if (minSuffix.length() <= remSpaces) {
                    string ans = num.substr(0, i);
                    ans.push_back('0' + d);
                    ans.append(remSpaces - minSuffix.length(), '1');
                    ans.append(minSuffix);
                    return ans;
                }
            }
        }

        // Case 3: If no number of the same length works, we increase the total length
        string minSuffix = getMinDigitsNeeded(targetFactors);
        int targetLen = max((int)num.length() + 1, (int)minSuffix.length());
        string ans = "";
        ans.append(targetLen - minSuffix.length(), '1');
        ans.append(minSuffix);
        return ans;
    }
};
