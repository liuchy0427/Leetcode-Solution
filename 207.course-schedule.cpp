/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

// @lc code=start
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> degree(numCourses,0);
        queue<int> bfs;

        for(auto p:prerequisites)
            graph[p[1]].push_back(p[0]), degree[p[0]]++;
        
        for(int i=0;i<numCourses;i++)
            if(!degree[i])
                bfs.push(i);

        int count = bfs.size();
        while(!bfs.empty() and count <= numCourses){
            int b = bfs.front();
            bfs.pop();
            for(auto g:graph[b]){
                if(--degree[g]==0)  
                    bfs.push(g),count++;
            }
        }

        return bfs.empty() and count == numCourses;

    }


    bool canFinish2(int numCourses, vector<vector<int>>& prerequisites) {
        graph g = buildGraph(numCourses, prerequisites);
        vector<int> degree = computeIndegrees(g);
        
        for(int i=0;i<numCourses;i++){
            int j=0;
            for(;j<numCourses;j++)
                if(!degree[j])
                    break;
            
            if(j==numCourses)
                return false;
            
            degree[j]--;
            for(int v:g[j])
                degree[v]--;
        }
        return true;
    }

private:
    typedef vector<vector<int>> graph;

    graph buildGraph(int numCourses, graph& prerequisites){
        graph g(numCourses);
        for(auto p:prerequisites)
            g[p[1]].push_back(p[0]);
        
        // for(int i=0;i<g.size();i++){
        //     cout<<i<<" -> ";
        //     for(int j=0;j<g[i].size();j++){
        //         cout<<g[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return g;
    }

    vector<int> computeIndegrees(graph& g){
        vector<int> degree(g.size(), 0);
        for(auto adj:g)
            for(auto v:adj)
                degree[v]++;
        
        // for(auto d:degree)
        //     cout<<d<<" ";
        // cout<<endl;
        return degree;

    }
};
// @lc code=end

