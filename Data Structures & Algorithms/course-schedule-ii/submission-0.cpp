class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        // result;
        vector<int> result;
        vector<int> empty(0);

        //preMap
        vector<vector<int>> preMap(numCourses);

        // indegree
        vector<int> indegree(numCourses, 0);
        for (int i=0; i<prerequisites.size(); i++){
            int course = prerequisites[i][0];
            int prereq = prerequisites[i][1];
            indegree[course]++;
            preMap[prereq].push_back(course);
        }

        //queue and push 0 indegree courses first
        queue<int> q;
        for (int i=0; i<numCourses ; i++){
            if (indegree[i]==0){
                q.push(i);
            }
        }

        //processed courses
        int finish =0;

        //
        while(!q.empty()){
            int c = q.front();
            result.push_back(c);
            q.pop();
            finish++;

            for(int i =0; i<preMap[c].size(); i++){
                indegree[preMap[c][i]]--;
                if (indegree[preMap[c][i]] ==0){
                    q.push(preMap[c][i]);
                }
            }
        }

        if(finish != numCourses){
            return empty;
        }else{
            return result;
        }
        
    }
};
