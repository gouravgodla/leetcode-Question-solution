class Solution {
public:
    int minBitFlips(unsigned start, unsigned goal) {
        // If the value of a bit in start and goal differ, then we need to flip that bit.
        // XOR operation to determine which bits need a bit flip.
        return popcount(start^goal); 
    }
};
