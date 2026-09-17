import java.util.*;

class Solution {
    public List<String> letterCombinations(String digits) {

        List<String> result = new ArrayList<>();

        if (digits == null || digits.length() == 0)
            return result;

        String[] map = {
            "",     // 0
            "",     // 1
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };

        backtrack(result, digits, map, 0, "");

        return result;
    }

    private void backtrack(List<String> result, String digits, String[] map, int index, String current) {

        // If combination length equals digits length
        if (index == digits.length()) {
            result.add(current);
            return;
        }

        // Get letters for current digit
        String letters = map[digits.charAt(index) - '0'];

        // Try each letter
        for (char c : letters.toCharArray()) {
            backtrack(result, digits, map, index + 1, current + c);
        }
    }
}
