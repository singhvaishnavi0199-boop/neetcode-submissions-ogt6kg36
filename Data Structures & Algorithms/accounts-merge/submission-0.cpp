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

    void unionSet(int x1, int x2){
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
        UnionFind uf(n);

        unordered_map<string, int> emailIndex; // email - index
        for(int i=0; i<accounts.size(); i++){
            for(int j = 1; j<accounts[i].size(); j++){
                string email = accounts[i][j];
                if (emailIndex.count(email)){
                    uf.unionSet(i, emailIndex[email]);
                }else{
                    emailIndex[email] = i;
                }
            }
        }

        vector<vector<string>> indexToEmails (n, vector<string> {});
        for(auto &it: emailIndex){
            int leader = uf.find(it.second);
            indexToEmails[leader].push_back(it.first);
        }

        vector<vector<string>> result;

        for(int i =0; i<indexToEmails.size(); i++){
            if (indexToEmails[i].size() >0){
                vector<string> curr;
                curr.push_back(accounts[i][0]);
                for(int j =0; j<indexToEmails[i].size(); j++){
                    curr.push_back(indexToEmails[i][j]);
                }
                sort(curr.begin()+1, curr.end());
                result.push_back(curr);
            }
        }

        return result;

        //for (auto &p : mp) {
            //cout << p.first << " -> " << p.second << endl;
        //}
    }
};