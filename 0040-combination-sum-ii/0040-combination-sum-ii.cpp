class Solution {
public:
     vector<vector<int>> calculateSum(vector<int>& candidates, int target,int ind, vector<vector<int>>& combinations,int n,vector<int>& vec) {
         if(target == 0) {
             combinations.push_back(vec);
             return combinations;
         }
        if(ind>n) return combinations;
        for(int i=ind;i<=n;i++) {
            if(i == ind ) {
                vec.push_back(candidates[i]);
                calculateSum(candidates,target-candidates[i],i+1,combinations,n,vec);
                vec.pop_back();
            }
            if(i> ind && candidates[i] != candidates[i-1] && target >= candidates[i]) {
                vec.push_back(candidates[i]);
                calculateSum(candidates,target-candidates[i],i+1,combinations,n,vec);
                vec.pop_back();
            }
            // if(i> ind && candidates[i] == candidates[i-1]) continue;
            // if(target<candidates[i]) break;
            // vec.push_back(candidates[i]);
            // calculateSum(candidates,target-candidates[i],i+1,combinations,n,vec);
            // vec.pop_back();
        }
        return combinations;

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> combinations;
        vector<int> vec;
        int n=candidates.size()-1;
        sort(candidates.begin(), candidates.end());
        return calculateSum(candidates,target,0,combinations,n,vec);
    }
};