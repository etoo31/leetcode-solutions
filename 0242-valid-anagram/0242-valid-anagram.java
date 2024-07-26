class Solution {
    public boolean isAnagram(String s, String t) {
        if(s.length() != t.length())return false;
        Map<Character, Integer> mp = new HashMap<>();
        for (char c : s.toCharArray())
        {
            if (mp.containsKey(c))
            {
                mp.put(c , mp.get(c)+1);
            }
            else 
                mp.put(c , 1);
        }
        for (char c : t.toCharArray())
        {
             if (mp.containsKey(c) && mp.get(c) > 0)
            {
                mp.put(c , mp.get(c)-1);
            }
            else return false;
        }
        return true;
    }
}