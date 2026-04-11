class UnionFind {
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(int n){
        parent.resize(n);
        rank.resize(n,1);
        for(int i=0; i<n;i++){
            parent[i] = i;
        }
    }

    int find(int x){
        if(x != parent[x]){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionByRank(int x1, int x2){
        int p1 = find(x1);
        int p2 = find(x2);

        if(p1==p2){
            return;
        }

        if(rank[p1] > rank[p2]){
            parent[p2] = p1;
            rank[p1] += rank[p2];
        }else{
            parent[p1] = p2;
            rank[p2] += rank[p1];
        }
        return;
    }

};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        UnionFind u(n);

        unordered_map<string, int> emailToIndex;
        for(int i=0; i<accounts.size(); i++){
            for(int j =1; j<accounts[i].size();  j++){
                string email = accounts[i][j];
                if(!emailToIndex.count(email)){
                    emailToIndex[email] = i;
                }else{
                    u.unionByRank(i, emailToIndex[email]);
                }
            }
        }

        unordered_map<int, vector<string>> indexToEmail;

        for(auto &it: emailToIndex){
            int index = it.second;
            int parent = u.find(index);
            indexToEmail[parent].push_back(it.first);
        }

        vector<vector<string>> result;
        for(auto &it: indexToEmail){
            vector<string> cred;
           string name = accounts[it.first][0];
            cred.push_back(name);
            vector<string> emails = it.second;
            sort(emails.begin(), emails.end());
            for(auto email : emails){
                cred.push_back(email);
            }
            result.push_back(cred);
        }

        return result;

    }
};