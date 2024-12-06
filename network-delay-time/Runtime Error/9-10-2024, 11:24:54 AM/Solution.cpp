// https://leetcode.com/problems/network-delay-time

class Solution {
public:
    const static int MX = 1e2+2;
    vector<pair<int, int>> adj_list[MX];
    int N;
    
    int dijkstras(int k) {
        vector<int> dist(N, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        dist[k] = 0;
        pq.push({0, k});
        
        while (!pq.empty()) {
            pair<int, int> x = pq.top();
            pq.pop();
            
            if (x.first != dist[x.second])
                continue;
            for (pair<int, int> i : adj_list[x.second]) {
                if (dist[x.second] + i.second < dist[i.first]) {
                    dist[i.first] = dist[x.second] + i.second;
                    pq.push({i.second, i.first});
                }
            }
        }
        return *max_element(dist.begin(), dist.end());
    }
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        N = n;
        for (auto i : times) {
            adj_list[i[0]].push_back({i[1], i[2]});
            adj_list[i[1]].push_back({i[0], i[2]});
        }
        int v = dijkstras(k); 
        return (v == INT_MAX ? -1 : v);
            
    }
};
