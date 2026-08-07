class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long long layer = 1;

        while (true) {
            long long apples = 2LL * layer * (layer + 1) * (2 * layer + 1);

            if (apples >= neededApples)
                return 8LL * layer;

            layer++;
        }
    }
};