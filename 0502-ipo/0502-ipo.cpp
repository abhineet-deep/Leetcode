class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        multimap<int,int> projects;
        for (int i = 0; i < profits.size(); i++) projects.insert(make_pair(capital[i], profits[i])); 

        // for (auto it : projects) cout<<it.first<<" "<<it.second<<endl;
        auto it = projects.begin();
        priority_queue<int> maximizeCapital;
        while (k--) {
            while (it != projects.end() && it->first <= w) {
                maximizeCapital.push(it->second);
                it++;
            }
            if (maximizeCapital.empty()) break;
            w += maximizeCapital.top();
            maximizeCapital.pop();
        }
        return w;
    }
};