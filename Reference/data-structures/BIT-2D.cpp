// Complexidade:- update -> O(logN)
//              - query  -> O(logN)

#define MAXN 1010

int bit[MAXN][MAXN], a[MAXN][MAXN], x, y;

void update(int idx, int idx2, int val){
    for(int i = idx; i <= x; i += i & -i){
        for(int j = idx2; j <= y; j += j & -j){
            bit[i][j] += val;
        }
    }
}

void query(int idx, int idx2){
    int sum = 0;
    for(int i = idx; i > 0; i -= i & -i){
        for(int j = idx2; j > 0; j -= j & -j){
            sum += bit[i][j];
        }
    }
    return sum;
}

void query(int xmin, int ymin, int xmax, int ymax){
    if(xmin > xmax) swap(xmin, xmax);
    if(ymin > ymax) swap(ymin, ymax);
    return query(xmax, ymax) - query(xmax, ymin - 1) - query(xmin - 1, ymax) + query(xmin - 1, ymin - 1);
}