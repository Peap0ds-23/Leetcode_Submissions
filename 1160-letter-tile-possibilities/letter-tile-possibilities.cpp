class Solution {
public:

    int backtrack(unordered_map<char, int>& counter) {
        int total = 0;
        for (auto& [tile, count] : counter) {
            if (count > 0) {
                total++;  // Count this sequence
                counter[tile]--;  // Use this tile
                total += backtrack(counter);  // Recur for next tile selection
                counter[tile]++;  // Restore tile count
            }
        }
        return total;
    }
    int numTilePossibilities(string tiles) {
        unordered_map<char, int> counter;
        for (char tile : tiles) {
            counter[tile]++;
        }
        return backtrack(counter);
    }
};