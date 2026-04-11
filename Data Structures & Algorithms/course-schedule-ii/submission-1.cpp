class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> result;
        vector<vector<int>> adj(numCourses);
        vector<int> indegree (numCourses, 0);
        queue<int> q;
        for(auto preq: prerequisites){
            int source = preq[1];
            int dest = preq[0];
            adj[source].push_back(dest);
            indegree[dest]++;
        }

        for(int i=0; i<numCourses; i++){
            if (indegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int course = q.front();
            q.pop();
            result.push_back(course);

            for(auto neigh : adj[course]){
                indegree[neigh]--;
                if (indegree[neigh] == 0){
                    q.push(neigh);
                }
            }
        }

        for(int i=0; i<numCourses; i++){
            if (indegree[i]!=0){
                return {};
            }
        }
        return result;
    }
};
