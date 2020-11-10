// Returns a vector that each z[i] is the length of the longest common prefix between s and the suffix of s starting at i.
// e.g: "aaabaab" - [0,2,1,0,2,1,0]
// Complexity: O(n)
vector<int> ZFunction(string s) {
    int n = (int)s.size();
    vector<int> z(n);

    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i <= r) z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }

    return z;
}