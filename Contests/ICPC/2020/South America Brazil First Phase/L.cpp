#include <bits/stdc++.h>

using namespace std;

int L, C, N;
vector<string> mat, words;
set<int> st[45][45];

void findHorizontal(string s, int idx) {
    int n = (int)s.size();

    for (int i = 0; i < L; i++) {
        for (int j = 0; j + n - 1 < C; j++) {
            string anagram;

            for (int k = 0; k < n; k++) {
                anagram.push_back(mat[i][j + k]);
            }

            sort(anagram.begin(), anagram.end());

            if (anagram == s) {
                for (int k = 0; k < n; k++) {
                    st[i][j + k].insert(idx);
                } 
            }
        }
    }
}

void findVertical(string s, int idx) {
    int n = (int)s.size();

    for (int i = 0; i < C; i++) {
        for (int j = 0; j + n - 1 < L; j++) {
            string anagram;

            for (int k = 0; k < n; k++) {
                anagram.push_back(mat[j + k][i]);
            }

            sort(anagram.begin(), anagram.end());

            if (s == anagram) {
                for (int k = 0; k < n; k++) {
                    st[j + k][i].insert(idx);
                }
            }
        }
    }
}

void findDiagonallyRight(string s, int idx) {
    int n = (int)s.size();

    for (int i = 0; i + n - 1 < L; i++) {
        for (int j = 0; j + n - 1 < C; j++) {
            string anagram;

            for (int k = 0; k < n; k++) {
                anagram.push_back(mat[i + k][j + k]);
            }

            sort(anagram.begin(), anagram.end());

            if (s == anagram) {
                for (int k = 0; k < n; k++) {
                    st[i + k][j + k].insert(idx);
                }
            }
        }
    }
}

void findDiagonallyLeft(string s, int idx) {
    int n = (int)s.size();

    for (int i = 0; i + n - 1 < L; i++) {
        for (int j = n - 1; j < C; j++) {
            string anagram;

            for (int k = 0; k < n; k++) {
                anagram.push_back(mat[i + k][j - k]);
            }

            sort(anagram.begin(), anagram.end());

            if (s == anagram) {
                for (int k = 0; k < n; k++) {
                    st[i + k][j - k].insert(idx);
                }
            }
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> L >> C;

    mat.resize(L);
    for (auto &x : mat) cin >> x;

    cin >> N;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        words.push_back(s);
    }

    for (int i = 0; i < N; i++) {
        findHorizontal(words[i], i);
        findVertical(words[i], i);
        findDiagonallyRight(words[i], i);
        findDiagonallyLeft(words[i], i);
    }

    int ans = 0;

    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            ans += (st[i][j].size() > 1);
        }
    }

    cout << ans << endl;

    return 0;
}