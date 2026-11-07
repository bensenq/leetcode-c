class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        vector<int> ans;
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > free_server;
        for(int i = 0; i < servers.size(); i++) {
            free_server.push({servers[i], i}); //compare weights first, then index
        }
        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>      //first: expire time, second: index
        > busy_server;
        int cur = 0;
        long long time = 0;    
        while(cur < tasks.size()) {
            while(!busy_server.empty()) {
                if(busy_server.top().first == time) {
                    int index = busy_server.top().second;
                    busy_server.pop();                          //server become free
                    free_server.push({servers[index], index});  //add to free server pool
                } else {
                    break;
                }
            }
            while(cur < time && cur < tasks.size()) {
                if(!free_server.empty()) {
                    int index = free_server.top().second;
                    free_server.pop();
                    busy_server.push({time+tasks[cur], index});
                    ans.push_back(index);
                    cur++;
                } else {
                    break;
                }
            }
            if(free_server.empty() && !busy_server.empty())
                time = busy_server.top().first;
            else
                time++;
        }
        return ans;
    }
};
