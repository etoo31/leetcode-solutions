class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int startRows = 0 , endRows = matrix.size()-1;
        while (startRows <= endRows)
        {
            int midRows = (startRows + endRows)/2;
            if (matrix[midRows][0] <= target && matrix[midRows][matrix[midRows].size()-1] >= target)
            {
                //cout << "In" << endl;
                int s = 0 , e = matrix[midRows].size()-1;
                while (s <= e)
                {
                    int mid = (s + e) / 2;
                    //cout << mid << endl;
                    if (matrix[midRows][mid] == target)
                    {
                        return true;
                    }
                    else if (matrix[midRows][mid] > target)
                    {
                        e = mid - 1;
                    }
                    else s = mid + 1;
                }
                break;
            }
            else if (matrix[midRows][0] > target)
            {
                endRows = midRows - 1;
            }
            else startRows = midRows + 1;
        }
        return false;
    }
};