#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

// using std::cin;
// using std::cout;
// using std::endl;
// using std::greater;
// using std::map;
// using std::string;
// using std::vector;

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *constructBinaryTree(const vector<string> &vecstr, int i) {
  if (vecstr.empty()) return nullptr;  // 特殊情况处理
  if (i >= vecstr.size()) return nullptr;
  TreeNode *root = nullptr;
  if (vecstr[i] != "null") {
    root = new TreeNode(stoi(vecstr[i]));
    root->left = constructBinaryTree(vecstr, 2 * i + 1);
    root->right = constructBinaryTree(vecstr, 2 * i + 2);
  }
  return root;
}

class Solution {
 public:
  vector<int> depth;
  int cnt = 1;
  void getDepth(TreeNode *root) {
    if (root == nullptr) return;
    depth.push_back(cnt);
    cnt++;
    getDepth(root->left);
    getDepth(root->right);
    cnt--;
  }

  int maxDepth(TreeNode *root) {
    if (!root) return 0;  // 特殊情况处理
    getDepth(root);
    sort(depth.begin(), depth.end(), less<int>());
    return depth.back();
  }
};

int main() {
  Solution sol;
  // stringstream sstr("3 9 20 null null 15 7");
  // vector<string> vec;
  // string s;
  // while (sstr >> s) {
  //   vec.push_back(s);
  // }
  stringstream sstr("3,9,20,null,null,15,7");
  vector<string> vec;
  string s;
  while (getline(sstr, s, ',')) {
    vec.push_back(s);
  }
  for_each(vec.begin(), vec.end(), [](const string str) { cout << str << endl; });
  cout << "vec size: " << vec.size() << endl;
  int treeDepth = log2(vec.size() + 1);
  cout << "treeDepth: " << treeDepth << endl;

  TreeNode *root = constructBinaryTree(vec, 0);  // 递归构建完全二叉树

  cout << sol.maxDepth(root) << "====" << endl;
  return 0;
}
