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
    i.erase(i.begin());
    int op_len = i.size() - 1;
    vector<vector<int>> ops_list;
    vector<int> i_copy;
    vector<int> k_copy;
    vector<int> ops;
    int plus_hold = 0;
    bool times_flag = false;
    int ops_pos = 0;
    dfs(ops_list, ops, op_len);
    for (auto k : ops_list) {
      i_copy = i;
      k_copy = k;
      cout << total << "\n";
      for (auto z : k_copy) {
        cout << z << " ";
      }
      cout << "\n";
      plus_hold = 0;
      while (i_copy.size() > 1) {
        if (k_copy[k_copy.size() - 1] == 1) {
          plus_hold += i_copy[i_copy.size() - 1];
          i_copy.pop_back();
          k_copy.pop_back();
        } else if (k_copy[k_copy.size() - 1] == 2) {
          i_copy[i_copy.size() - 2] *= i_copy[i_copy.size() - 1];
          i_copy.pop_back();
          k_copy.pop_back();
        }
      }

      if ((i_copy[0] + plus_hold) == total) {
        cout << "true\n";
        cout << total << "\n";
        result += (i_copy[0] + plus_hold);
        break;
      }
    }
  }

  cout << result << "\n";
  return 0;
}
