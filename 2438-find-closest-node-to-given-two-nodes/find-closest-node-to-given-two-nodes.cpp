class Solution {
public:
    void getDistances(int src, vector<int>&dist, vector<int>&edges){
        int d = 0;
        while(src != -1 && dist[src] == -1){
            dist[src] = d++;
            src = edges[src];
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();

        vector<int>dist1(n, -1), dist2(n, -1);
        getDistances(node1, dist1, edges);
        getDistances(node2, dist2, edges);

        int node=-1, mn_dist=INT_MAX;
        for(int i=0; i<n; i++){
            if(dist1[i] == -1 || dist2[i]==-1)continue;

            int curr = max(dist1[i], dist2[i]);
            if(curr < mn_dist){
                mn_dist = curr;
                node = i;
            }
        }
    
        return node;
    }
};