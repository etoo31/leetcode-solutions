class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
       
        vector<bool>visited = vector<bool>(numCourses , false);
        vector<bool>path = vector<bool>(numCourses , false);
        vector<int>answer;
        vector<vector<int>>adjList = vector<vector<int>>(numCourses , vector<int>());
        for (auto x : prerequisites)
        {
            adjList[x[0]].push_back(x[1]);
        }
        
        for (int i = 0 ; i < numCourses; i++)
        {
            if (!visited[i])
            {
                bool cycle = isCycle(i , answer , visited , adjList , path);
                if (cycle)
                    return vector<int>();
            }
        }
        return answer;
        
        
    }
    bool isCycle(int n , vector<int>&ans , vector<bool>&visited , vector<vector<int>>&adjList , vector<bool>&path)
    {
        if (visited[n])return true;
        visited[n] = true;
        path[n] = true;
        
        for (auto child : adjList[n]){
            
            if (!visited[child]){
                bool cycle = isCycle(child , ans , visited , adjList , path);
                if (cycle)return true;
                
            }
            else if (path[child])
            {
                return true;
            }
        }
        ans.push_back(n);
        path[n] = false;
        return false;
        
    }
    
    
};