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
  int result = 0;
  vector<vector<int>> data;

  while (getline(cin, input)) {
    vector<int> list;
    istringstream iss(input);
    while (iss >> hold) {
      list.push_back(stoi(hold));
    }

    data.push_back(list);
  }

  for (auto i : data) {

    int total = i[0];
    int op_len = i.size() - 2;
    vector<vector<int>> ops_list;
    vector<int> ops;
    dfs(ops_list, ops, op_len);
    for (auto k : ops_list) {
      for (auto m : k) {
        cout << m << " ";
      }
      cout << "\n";
    }
    for (int j = 1; j < i.size(); j++) {
      cout << i[j] << " ";
    }
    cout << "\n";
  }
  return 0;
}
