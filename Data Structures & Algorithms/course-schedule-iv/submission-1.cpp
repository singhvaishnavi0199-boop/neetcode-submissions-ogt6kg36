class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        for(auto preq : prerequisites){
            int source = preq[0];
            int dest = preq[1];
            adj[source].push_back(dest);
            indegree[dest]++;
        }

        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if (indegree[i]==0){
                q.push(i);
            }
        }

        vector<unordered_set<int>> prereq(numCourses);

        while(!q.empty()){
            int course = q.front();
            q.pop();

            for(auto neigh: adj[course]){

                for(auto p : prereq[course]){
                    prereq[neigh].insert(p);
                }

                prereq[neigh].insert(course);

                indegree[neigh]--;
                if(indegree[neigh]==0){
                    q.push(neigh);
                }
            }
        }

        vector<bool> result;
        for(auto query: queries){
            int src = query[0];
            int dest = query[1];
            if (prereq[dest].count(src)){
                result.push_back(true);
            }else{
                result.push_back(false);
            }
        }

        return result;
    }
};