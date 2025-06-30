#include <bits/stdc++.h>
using namespace std;

vector<int> getTotalVotes(const vector<vector<int>>& votes, int n, int m)
{
    vector<int> total(m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            total[j] += votes[i][j];
    return total;
}

bool isOppositionSafe(const vector<int>& total, int m)
{
    for (int i = 0; i < m - 1; i++)
        if (total[m - 1] > total[i])
            return false;
    return true;
}

vector<int> findStationsToCancel(const vector<vector<int>>& votes, int n, int m, const vector<int>& total)
{

    vector<pair<int, int>> stations(n);
    for (int i = 0; i < n; i++)
        stations[i] = {votes[i][m - 1], i};

    sort(stations.begin(), stations.end(), greater<int>());

    vector<int> current = total;
    vector<int> cancel;

    for (auto [opp_votes, idx] : stations)
    {
        for (int j = 0; j < m; j++)
            current[j] -= votes[idx][j];
        cancel.push_back(idx + 1);

        if (isOppositionSafe(current, m))
            break;
    }
    return cancel;
}

int main()
{
    int m, n;
    cout << "Enter total candidates and stations: ";
    cin >> m >> n;

    vector<vector<int>> votes(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

         cin >> votes[i][j];
    }
}

vector<int> total = getTotalVotes(votes, n, m);

if (isOppositionSafe(total, m))
{
    cout << "0"<<endl;
    return 0;
}

vector<int> cancel = findStationsToCancel(votes, n, m, total);

cout << cancel.size() << endl;
for (int idx : cancel)
    cout << idx << " ";
cout << endl;

return 0;
}
