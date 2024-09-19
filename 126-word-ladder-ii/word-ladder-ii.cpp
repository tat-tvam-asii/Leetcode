class Solution {
public:

    vector<vector<string>> dfs(int node,vector<int>& dis,vector<int> adj[],vector<string>& wordList){
        if(dis[node] == 0) return {{wordList[node]}};
        vector<vector<string>> ans;
        for(int i : adj[node]){
            if(dis[i] == dis[node] - 1){
                vector<vector<string>> temp1 = dfs(i,dis,adj,wordList);
                for(auto i : temp1){
                    vector<string> temp = i;
                    temp.insert(temp.begin(),wordList[node]);
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }

    bool check(string s1,string s2){
        int cnt = 0;
        for(int i = 0;i < s1.length();i++) if(s1[i] != s2[i]) cnt++;
        return cnt == 1;
    }

    vector<vector<string>> findLadders(string startWord, string targetWord, vector<string>& wordList) {
        bool flag = false;
        for(string s : wordList) if(s == startWord){
            flag = true;
            break;
        }
        if(!flag) wordList.push_back(startWord);
        int N = wordList.size();
        vector<int> adj[N];
        for(int i = 0;i < N;i++){
            for(int j = i+1;j < N;j++){
                if(check(wordList[i],wordList[j])){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int src = 0;
        for(int i = 0;i < N;i++) if(wordList[i] == startWord){
            src = i;
            break;
        }
        vector<int> dis(N,1e9);
        dis[src] = 0;
        queue<int> q;
        q.push(src);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int i : adj[node]){
                if(dis[node] + 1 < dis[i]){
                    dis[i] = 1 + dis[node];
                    q.push(i);
                }
            }
        }
        vector<vector<string>> ans;
        int dest = -1;
        for(int i = 0;i < N;i++){
            if(wordList[i] == targetWord){
                if(dis[i] == 1e9) return {};
                dest = i;
                break;
            }
        }
        if(dest == -1) return {};
        int seq = dis[dest] + 1;
        for(int i : adj[dest]){
            if(dis[i] == dis[dest] - 1) {
                vector<vector<string>> temp1 = dfs(i,dis,adj,wordList);
                for(auto i : temp1){
                    vector<string> temp = i;
                    reverse(temp.begin(),temp.end());
                    temp.push_back(wordList[dest]);
                    if(temp.size() == seq){
                        ans.push_back(temp);
                    }
                }
            }
        }
        return ans;
    }
};