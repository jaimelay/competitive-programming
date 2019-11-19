struct Edge {
    int u, v, w;

    Edge(int u, int v, int w){
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

vector<Edge> G[MAXN], MST;
bool vis[MAXN];

bool comp(Edge &a, Edge &b){ return a.w > b.w; }

int prim(int v){
    priority_queue<Edge, vector<Edge>, decltype(&comp)> pq(&comp);
    int min_cost = 0;

    pq.push(Edge(v, v, 0));

    while(!pq.empty()){
        Edge top = pq.top();
        pq.pop();

        if(vis[top.v]) continue;

        vis[top.v] = 1;
        min_cost += top.w;

        MST.push_back(top);
        
        for(auto u : G[top.v]){
            if(!vis[u.v]) pq.push(u);
        }
    }

    return min_cost;
}