#include <iostream>
#include <sstream>
#include <string>
using namespace std;

void dfs(vector<vector<int>> &ops_list, vector<int> ops, int ops_len) {
  if (ops.size() == ops_len) {
    ops_list.push_back(ops);
  } else {
    vector<int> plus = ops;
    vector<int> times = ops;
    plus.push_back(1);
    times.push_back(2);
    dfs(ops_list, plus, ops_len);
    dfs(ops_list, times, ops_len);
  }
}

int main() {
  freopen("./day7.txt", "r", stdin);
  string input = "";
  string hold = "";
  long long result = 0;
  vector<vector<int>> data;
  vector<long long> totals;

  while (getline(cin, input)) {
    vector<int> list;
    istringstream iss(input);
    iss >> hold;
    totals.push_back(stoll(hold));
    while (iss >> hold) {
      list.push_back(stoi(hold));
    }

    data.push_back(list);
  }

  int pos_ll = 0;
  for (auto line : data) {

    bool found = false;
    long long total = totals[pos_ll];
    int op_len = line.size() - 1;
    vector<vector<int>> ops_list;
    vector<int> ops;
    long long hold = 0;
    hold += line[0];
    int pos = 1;
    dfs(ops_list, ops, op_len);
    for (auto potential_operator : ops_list) {
      if (found) {
        break;
      }
      hold = line[0];
      pos = 1;
      for (auto cur_op : potential_operator) {

        if (cur_op == 1) {
          hold += line[pos];
        } else if (cur_op == 2) {
          hold *= line[pos];
        }

        pos++;
      }

      if (hold == total) {
        if (!found) {
          result += total;
        }
        found = true;
      }
    }
    pos_ll++;
  }

  cout << result << "\n";
  return 0;
}
