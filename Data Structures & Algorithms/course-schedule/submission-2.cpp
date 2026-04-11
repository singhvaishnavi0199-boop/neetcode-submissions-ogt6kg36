class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // adj list
        // indegree
        // queue
        // push of nodes with indegree 0 to the queue
        // loop to all neighbours of the front
        // indegree -- , if indegree = 0 -> push into the queue

        // if all ele with indegree = 0 => true else false;

        vector<vector<int>> adj (numCourses);
        vector<int> indegree (numCourses, 0);
        queue<int> q;

        for(int i = 0; i<prerequisites.size(); i++){
            int dest = prerequisites[i][0];
            int source = prerequisites[i][1];
            adj[source].push_back(dest);
            indegree[dest]++;
        }

        for(int i=0; i<numCourses; i++){
            if (indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int course = q.front();
            q.pop();

            for(auto neigh: adj[course]){
                indegree[neigh]--;
                if (indegree[neigh] == 0){
                    q.push(neigh);
                }
            }
        }

        for(int i=0; i<numCourses; i++){
            if (indegree[i] != 0){
                return false;
            }
        }
        return true;
    }
};
