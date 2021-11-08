#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;
const long long INFLL = 0x3f3f3f3f3f3f3f3fLL;
const long double EPS = 1e-9;
const long double PI = acos(-1.0);

enum StatusEscalator {
    STOPPED,
    MOVING_RIGHT,
    MOVING_LEFT,
};

StatusEscalator getStatusEscalator(int direction) {
    return direction == 0 ? MOVING_RIGHT : MOVING_LEFT;
}

const int ESCALATOR_TIME = 10;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    StatusEscalator statusEscalator = STOPPED;
    pair<int, StatusEscalator> personWaiting = { -1, STOPPED };
    bool isSomeoneWaiting = false;
    int time = 0;

    vector<pair<int, StatusEscalator>> people;

    for (int i = 0, t, d; i < n; i++) {
        cin >> t >> d;
        people.emplace_back(t, getStatusEscalator(d));
    }

    int ptr = 0;

    while (ptr < n) {
        pair<int, StatusEscalator> person = people[ptr];
        int personTime = person.first;
        StatusEscalator statusEscalatorFromPerson = person.second;

        if (time > personTime) {
            switch (statusEscalator) {
                case STOPPED:
                    time = personTime + ESCALATOR_TIME;
                    statusEscalator = statusEscalatorFromPerson;
                    break;
                case MOVING_LEFT:
                    if (statusEscalatorFromPerson == MOVING_LEFT) {
                        time = personTime + ESCALATOR_TIME;
                        break;
                    }

                    personWaiting = make_pair(personTime, statusEscalatorFromPerson);
                    isSomeoneWaiting = true;
                    break;
                case MOVING_RIGHT:
                    if (statusEscalatorFromPerson == MOVING_RIGHT) {
                        time = personTime + ESCALATOR_TIME;
                        break;
                    }

                    personWaiting = make_pair(personTime, statusEscalatorFromPerson);
                    isSomeoneWaiting = true;
                    break;
            }
            ptr++;
        } else {
            if (isSomeoneWaiting) {
                statusEscalator = personWaiting.second;
                personWaiting = { personWaiting.first, STOPPED };
                time += ESCALATOR_TIME;
                isSomeoneWaiting = false;
            } else {
                statusEscalator = statusEscalatorFromPerson;
                time = personTime + ESCALATOR_TIME;
            }
        }
    }

    cout << (isSomeoneWaiting ? time + ESCALATOR_TIME : time) << endl;

    return 0;
}