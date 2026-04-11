//-- bfs ..topological sorting

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map <int, vector<int>> preMap;
        vector<int> indegree(numCourses, 0);

        for (int i=0; i<prerequisites.size(); i++){
            int prereq = prerequisites[i][0];
            int course = prerequisites[i][1];
            preMap[prereq].push_back(course);
            indegree[course]++;
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        unordered_map<int, unordered_set<int>> topoMap;

        while(!q.empty()){
            int prereq = q.front();
            q.pop();

            for(int i=0;i<preMap[prereq].size();i++){
                int node = preMap[prereq][i];

                topoMap[node].insert(prereq);
                topoMap[node].insert(topoMap[prereq].begin(), topoMap[prereq].end());
                
                indegree[node]--;
                if(indegree[node]==0){
                    q.push(node);
                }
            }
        }

        vector<bool> result(queries.size(), false);
        for(int i=0; i<queries.size(); i++){
            int prereq = queries[i][0];
            int course = queries[i][1];
            if (topoMap[course].count(prereq)){
                result[i]=true;
            }
        }

        return result;

    }
};