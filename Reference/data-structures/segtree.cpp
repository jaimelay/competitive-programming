const int MAXN = 112345;

int st[4*MAXN], a[MAXN];

void build(int node, int left, int right){
    if(left == right){
        st[node] = a[left];
    }else{
        int mid = (left + right)/2;
        build(2*node, left, mid);
        build(2*node + 1, mid + 1, right);

        st[node] = st[2*node] * st[2*node + 1];
    }
}

void update(int node, int left, int right, int idx, int val){
    if(idx > right || idx < left){
        return;
    }else if(left == right){
        a[idx] = val;
        st[node] = val;
    }else{
        int mid = (left + right)/2;
        update(2*node, left, mid, idx, val);
        update(2*node + 1, mid + 1, right, idx, val);

        st[node] = st[2*node] * st[2*node + 1];
    }
}

int query(int node, int left, int right, int a, int b){
    if(b < left || a > right){
        return 1;
    }else if(left >= a && right <= b){
        return st[node];
    }else{
        int mid = (left + right)/2;
        int e = query(2*node, left, mid, a, b);
        int d = query(2*node + 1, mid + 1, right, a, b);
        return e * d;
    }
}