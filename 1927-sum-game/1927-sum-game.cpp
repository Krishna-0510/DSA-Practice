class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();
        int left_sum = 0, right_sum = 0;
        int left_q = 0, right_q = 0;

        // Process the left half
        for (int i = 0; i < n / 2; ++i) {
            if (num[i] == '?') {
                left_q++;
            } else {
                left_sum += num[i] - '0';
            }
        }

        // Process the right half
        for (int i = n / 2; i < n; ++i) {
            if (num[i] == '?') {
                right_q++;
            } else {
                right_sum += num[i] - '0';
            }
        }

        // Bob wins if the sums match after pairing question marks optimally
        return (left_sum - right_sum) != (right_q - left_q) * 9.0 / 2.0;
    }
};
