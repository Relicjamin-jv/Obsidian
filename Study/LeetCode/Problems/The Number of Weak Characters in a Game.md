```c++
class Solution {
public:
    static bool compare(std::vector<int>& a, std::vector<int>& b){
        if(a[0] == b[0]){
            return a[1] > b[1];
        }
        return a[0] < b[0];
    }
    
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int result = 0;
        
        std::sort(properties.begin(), properties.end(), compare);
        
        int max = properties[properties.size() - 1][1]; //setting the first max
        
        for(int i = properties.size() - 2; i >= 0; i--){
            if(properties[i][1] >= max){
                max = properties[i][1]; //dont update result beacuse it came from someone who is same or better, on attack. But this one has a better defense.
            }
            else{
                result++;
            }
        }
        
        return result;
    }
};
```
Problem Type: Greedy Solution

# Problem Description
You are playing a game that contains multiple characters, and each of the characters has **two** main properties: **attack** and **defense**. You are given a 2D integer array `properties` where `properties[i] = [attacki, defensei]` represents the properties of the `ith` character in the game.

A character is said to be **weak** if any other character has **both** attack and defense levels **strictly greater** than this character's attack and defense levels. More formally, a character `i` is said to be **weak** if there exists another character `j` where `attackj > attacki` and `defensej > defensei`.

Return _the number of **weak** characters_.

**Example 1:**

**Input:** properties = ([[5,5],[6,3],[3,6]])
**Output:** 0
**Explanation:** No character has strictly greater attack and defense than the other.

**Example 2:**

**Input:** properties = ([2,2],[3,3])
**Output:** 1
**Explanation:** The first character is weak because the second character has a strictly greater attack and defense.

**Example 3:**

**Input:** properties = ([[1,5],[10,4],[4,3]])
**Output:** 1
**Explanation:** The third character is weak because the second character has a strictly greater attack and defense.

**Constraints:**

-   `2 <= properties.length <= 105`
-   `properties[i].length == 2`
-   `1 <= attacki, defensei <= 105`


# Solved
This is solved by a greedy solution. The greedy part of this solution is that we sort from least to greatest by strength (*properties i, 1*). This takes care of the stregth variable. We no longer need to worry about it. This is due to the fact that if we iterate from the end to the array back we'll only run into the same or less strength. This allows us to just keep a max value for defense and if there is the same defense or higher defense we update the max value. Although there is a case we need to take care of to get the correct output. If we sort the array just by strength lets look at the output for the properties array -> ((1, 1), (2, 1), (2, 2), (1, 2)). If we sort this just by strength we get -> ((1, 1), (1, 2), (2, 1), (2, 2)). This causes an issue. The last two indexes should cause the result to change, however, they do. Max = 2 for the last index, when going to the third index we dont update the max beacause 2 > 1, thus the result changes. We can fix for this case by just making sure that if they have the same strength we have the max defense value towards the end of the array. If we account for that the sorted array would look like this 
-> ((1, 1), (1, 2), (2, 2), (2, 1)).

# Runtime
Run Time -> O(nlgn), nlgn comes from the std::sort. the for loop adds an n to the runtime but is negliable to nlgn of the sort.

Space Time -> O(1), no new space is allocated for this algorithm. 