class Solution {
    public boolean isAnagram(String s, String t) {
        // If lengths are not the same, they cannot be anagrams
        if (s.length() != t.length()) return false;

        // Create a map to count the frequency of each character in string s
        Map<Character, Integer> mp = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            mp.put(c, mp.getOrDefault(c, 0) + 1);
        }

        // Decrease the count for each character found in string t
        for (int i = 0; i < t.length(); i++) {
            char c = t.charAt(i);
            if (!mp.containsKey(c) || mp.get(c) == 0) {
                return false;
            }
            mp.put(c, mp.get(c) - 1);
        }

        return true;
    }
}
