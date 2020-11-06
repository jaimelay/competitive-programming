// Returns all palindromes substrings, longest palindrome substring, if some range is palindrome.
// Complexity: O(n)
struct Manacher {
    int n;
    string s;
    vector<int> odd, even, p;
    vector<pair<pair<int, int>, string>> palindromes;

    Manacher(const string &s) {
        this->s = s;
        this->n = (int)s.size();
        this->odd.resize(n);
        this->even.resize(n);
        this->p.resize(2 * n - 1);
        preprocess();
    }

    void preprocess() {
        for (int i = 0, l = 0, r = -1; i < n; i++) {
            int k = (i > r) ? 1 : min(odd[l + r - i], r - i + 1);
            while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
                k++;
            }
            odd[i] = k--;
            if (i + k > r) {
                l = i - k;
                r = i + k;
            }
        }

        for (int i = 0, l = 0, r = -1; i < n; i++) {
            int k = (i > r) ? 0 : min(even[l + r - i + 1], r - i + 1);
            while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
                k++;
            }
            even[i] = k--;
            if (i + k > r) {
                l = i - k - 1;
                r = i + k ;
            }
        }

        for (int i = 0; i < n; i++) {
            if (odd[i]) {
                int l = i - odd[i] + 1, r = i + odd[i] - 1;
                palindromes.push_back({{ l, r }, s.substr(l, (l == r ? 1 : (r - l + 1))) });
            }

            if (even[i]) {
                int l = i - even[i], r = i + even[i] - 1;
                palindromes.push_back({{ l, r }, s.substr(l, (l == r ? 1 : (r - l + 1))) });
            }
        }

        for (int i = 0; i < n; i++) {
            p[2 * i] = 2 * odd[i] - 1;
        }

        for (int i = 0; i < n - 1; i++) {
            p[2 * i + 1] = 2 * even[i + 1];
        }
    }

    bool isPalindrome(int l, int r) {
        return p[l + r] >= r - l + 1;
    }

    int longestPalindromeSize() {
        return *max_element(p.begin(), p.end());
    }

    vector<pair<pair<int, int>, string>> getAllPalindromes() {
        return palindromes;
    }
};