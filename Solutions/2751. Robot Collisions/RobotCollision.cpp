class Solution {
public:
    struct Robot {
        int position;
        int health;
        char direction;
        int index;
    };

    static bool comparePosition(const Robot& a, const Robot& b) {
        return a.position < b.position;
    }

    static bool compareIndex(const Robot& a, const Robot& b) {
        return a.index < b.index;
    }

    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<Robot> robots;

        for (int i = 0; i < n; i++) {
            robots.push_back({positions[i], healths[i], directions[i], i});
        }

        sort(robots.begin(), robots.end(), comparePosition);

        stack<int> st; // stores indices of right-moving robots in sorted robots vector

        for (int i = 0; i < n; i++) {
            if (robots[i].direction == 'R') {
                st.push(i);
            } else {
                while (!st.empty() && robots[i].health > 0) {
                    int j = st.top();

                    if (robots[j].health == robots[i].health) {
                        robots[j].health = 0;
                        robots[i].health = 0;
                        st.pop();
                        break;
                    } 
                    else if (robots[j].health > robots[i].health) {
                        robots[j].health--;
                        robots[i].health = 0;
                        break;
                    } 
                    else {
                        robots[i].health--;
                        robots[j].health = 0;
                        st.pop();
                    }
                }
            }
        }

        vector<Robot> survivors;
        for (int i = 0; i < n; i++) {
            if (robots[i].health > 0) {
                survivors.push_back(robots[i]);
            }
        }

        sort(survivors.begin(), survivors.end(), compareIndex);

        vector<int> result;
        for (Robot& r : survivors) {
            result.push_back(r.health);
        }

        return result;
    }
};
