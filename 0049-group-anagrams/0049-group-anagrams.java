import java.util.*;

class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> mp = new HashMap<>();
        
        for (String str : strs) {
            // Convert the string to a character array
            char[] chars = str.toCharArray();
            // Sort the character array
            Arrays.sort(chars);
            // Convert the character array back to a string
            String sortedString = new String(chars);
            
            // Check if the sorted string is already a key in the map
            if (!mp.containsKey(sortedString)) {
                mp.put(sortedString, new ArrayList<>());
            }
            mp.get(sortedString).add(str);
        }
        
        // Collect the grouped anagrams into a list
        List<List<String>> ans = new ArrayList<>(mp.values());
        
        return ans;
    }
}
