const int MAXN = 112345;

int st[4*MAXN], a[MAXN];

void build(int node, int i, int j){
    if(i == j){
        st[node] = a[i];
    }else{
        int mid = (i + j)/2;
        build(2*node, i, mid);
        build(2*node + 1, mid + 1, j);

        st[node] = st[2*node] * st[2*node + 1];
    }
}

void update(int node, int i, int j, int idx, int val){
    if(idx > j || idx < i) return;
    if(i == j){
        a[idx] = val;
        st[node] = val;
        return;
    }

    int mid = (i + j)/2;
    update(2*node, i, mid, idx, val);
    update(2*node + 1, mid + 1, j, idx, val);

    st[node] = st[2*node] * st[2*node + 1];
}

int query(int node, int i, int j, int l, int r){
    if(r < i || l > j) return 1;
    if(i >= l && j <= r) return st[node];

    int mid = (i + j)/2;
    int e = query(2*node, i, mid, l, r);
    int d = query(2*node + 1, mid + 1, j, l, r);
    return e * d;
}