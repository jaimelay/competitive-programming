// O(1) para quase todas operações, menos .clear();
// Caso dê MLE, use a MinQueue com duas stacks.
struct MinQueue {
    int sz = 0;
    int add_val = 0;
    deque<pair<int, int>> dq, aux;

    bool empty() { return dq.empty(); }

    int size() { return sz; }

    void clear() {
        add_val = 0;
        sz = 0;
        dq.clear();
    }

    void push(int x) {
        x -= add_val;
        int amt = 1;

        while (!dq.empty() && dq.back().first >= x) {
            amt += dq.back().second;
            dq.pop_back();
        }

        dq.push_back({ x, amt });
        sz++;
    }

    void pop() {
        dq.front().second--;
        sz--;

        if (!dq.front().second) {
            dq.pop_front();
        }
    }

    void addToEveryNumber(int val) { add_val += val; }

    int getMin() { return dq.front().first + add_val; }
};