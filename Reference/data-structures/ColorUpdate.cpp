// Update -> Change all colors in range [left, right] to some color.
// Query -> How many indexes has some color. 
struct ColorUpdate {
    struct Node {
        long long l, r;
        int color;

        Node(long long l, long long r, int color) : l(l), r(r), color(color) {}
    };

    struct Comparator {
        bool operator()(Node a, Node b) {
            if (a.r == b.r) {
                return a.l < b.l;
            }
            return a.r < b.r;
        }
    };

    set<Node, Comparator> st;
    vector<long long> ans;

    ColorUpdate(long long left, long long right, int max_color) {
        ans.resize(max_color + 1);
        ans[0] = right - left + 1LL;
        st.insert(Node(left, right, 0));
    }

    void update(long long left, long long right, int new_color){
        auto p = st.lower_bound(Node(0, left, -1));

        assert(p != st.end());

        long long l = p->l;
        long long r = p->r;
        int old_color = p->color;

        ans[old_color] -= (r - l + 1LL);
        p = st.erase(p);

        if (l < left) {
            ans[old_color] += (left - l);
            st.insert(Node(l, left - 1LL, old_color));
        }

        if (right < r){
            ans[old_color] += (r - right);
            st.insert(Node(right + 1LL, r, old_color));
        }

        while ((p != st.end()) && (p->l <= right)) {
            l = p->l;
            r = p->r;
            old_color = p->color;
            ans[old_color] -= (r - l + 1LL);

            if (right < r) {
                ans[old_color] += (r - right);
                st.insert(Node(right + 1LL, r, old_color));
                st.erase(p);
                break;
            } else {
                p = st.erase(p);
            }
        }

        ans[new_color] += (right - left + 1LL);
        st.insert(Node(left, right, new_color));
    }

    int getColor(long long pos) {
        auto p = st.lower_bound(Node(0, pos, -1));
        return p->color;
    }

    long long countColor(int color){
        return ans[color];
    }
};