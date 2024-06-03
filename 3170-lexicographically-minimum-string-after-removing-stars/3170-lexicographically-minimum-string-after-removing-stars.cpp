class Solution {
public:

    struct comp{
       bool operator() (const pair<char,int> &p1, const pair<char,int> &p2){
           if(p1.first == p2.first){
               return p1.second < p2.second;
           }
           return p1.first > p2.first;
       } 
    };

    string clearStars(string s) {
        priority_queue<pair<char,int>, vector<pair<char,int>>, comp > pq;
        for(int i=0;i<s.size();i++) {
            if(!pq.empty() && s[i] == '*') {
                int ind = pq.top().second;
                s[ind] = '*';
                pq.pop();
            }
            else pq.push({s[i],i}); 
        }
        string str = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i] != '*'){
                str += s[i];
            }
        }
        return str;
    }
};