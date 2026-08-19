#include <vector>
#include <unordered_map>

class Solution {
public:
    int maxNumberOfFamilies(int n, std::vector<std::vector<int>>& reservedSeats) {
        // Map row number -> bitmask representing reserved seats
        std::unordered_map<int, int> rowMasks;
        
        for (const auto& seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];
            // Only columns 2 through 9 affect the four-person family allocations
            if (col >= 2 && col <= 9) {
                rowMasks[row] |= (1 << (col - 2));
            }
        }
        
        // Start by assuming all rows can fit 2 families
        int maxFamilies = 2 * n;
        
        // Define masks for the three invalidating scenarios
        // seats 2,3,4,5 correspond to the first 4 bits (indices 0,1,2,3) -> binary 1111 = 15
        int leftMask = 15;       
        // seats 6,7,8,9 correspond to the last 4 bits (indices 4,5,6,7) -> binary 11110000 = 240
        int rightMask = 240;     
        // seats 4,5,6,7 correspond to middle 4 bits (indices 2,3,4,5) -> binary 00111100 = 60
        int middleMask = 60;     
        
        // Adjust counts for rows that contain reservations
        for (auto const& [row, mask] : rowMasks) {
            bool leftOccupied = (mask & leftMask) != 0;
            bool rightOccupied = (mask & rightMask) != 0;
            bool middleOccupied = (mask & middleMask) != 0;
            
            if (leftOccupied && rightOccupied && middleOccupied) {
                // Cannot place any family in this row
                maxFamilies -= 2; 
            } else if (leftOccupied && rightOccupied) {
                // Left and right are blocked, but middle is open -> holds 1 family instead of 2
                maxFamilies -= 1; 
            } else if (leftOccupied || rightOccupied) {
                // One side is blocked, meaning it holds 1 family instead of 2
                maxFamilies -= 1; 
            }
            // If none are true, both sides are fully clear, so 2 families still fit (no penalty)
        }
        
        return maxFamilies;
    }
};
