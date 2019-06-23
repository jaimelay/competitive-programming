int invCountMS(vector<int> &v){
    int inv = 0;

    if(v.size() == 1) return 0;

    vector<int> m1, m2;
    for(int i = 0; i < v.size()/2; i++) m1.push_back(v[i]);
    for(int i = v.size()/2; i < v.size(); i++) m2.push_back(v[i]);

    inv += countInvMS(m1);
    inv += countInvMS(m2);

    m1.push_back(INT_MAX);
    m2.push_back(INT_MAX);

    int idx = 0, idx2 = 0;
    for(int i = 0; i < v.size(); i++){
        if(m1[idx] <= m2[idx2]){
            v[i] = m1[idx++];
        }else{
            v[i] = m2[idx2++];
            inv += m1.size() - idx - 1;
        }
    }
    return inv;
}