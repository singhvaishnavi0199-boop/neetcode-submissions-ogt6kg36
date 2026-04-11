class Solution {
    unordered_map<int, vector<int>> preMap;
    unordered_set<int> visited;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // indegree map

        for (int i =0; i<numCourses ; i++){
            preMap[i] = {};
        }
        for (const auto &prereq:prerequisites ){
            preMap[prereq[0]].push_back(prereq[1]);
        }

        for (int i =0; i<numCourses ; i++){
            if (!dfs(i)){
                return false;
            }
        }
        return true;

    }

    bool dfs(int course){
        if (visited.count(course)){
            return false;
        }

        if (preMap[course].empty()){
            return true;
        }

        visited.insert(course);

        for(int i =0; i< preMap[course].size(); i++ ){
            if (!dfs(preMap[course][i])){
                return false;
            }
        }
        visited.erase(course);
        return true;
    }
};
