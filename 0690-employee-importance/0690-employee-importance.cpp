/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> mp;

        for (auto e : employees)
            mp[e->id] = e;

        queue<int> q;
        q.push(id);

        int ans = 0;

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            Employee* emp = mp[cur];
            ans += emp->importance;

            for (int sub : emp->subordinates)
                q.push(sub);
        }

        return ans;
    }
};