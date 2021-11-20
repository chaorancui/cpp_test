#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

<<<<<<< HEAD
// 递归由数组构建完全/满二叉树
=======
// 由数组构建完全/满二叉树
>>>>>>> 00483d32a1f382d95fbc7b5532cad8f36527b7d7
TreeNode *constructBinaryTree(const vector<string> &vecstr, int i) {
  if (vecstr.empty())
    return nullptr;  // 特殊情况处理
  if (i >= vecstr.size())
    return nullptr;
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
  map<int, int> mapDepth;
  vector<int> depth;
  int cnt = 1;
  // void getDepth(TreeNode *root) {
  //   if (root == nullptr) return;
  //   depth.push_back(cnt);
  //   cnt++;
  //   getDepth(root->left);
  //   getDepth(root->right);
  //   cnt--;
  // }

<<<<<<< HEAD
  void getDepth(const TreeNode *root, int cntDepth) {
=======
  void getDepth(TreeNode *root, int cntDepth) {
>>>>>>> 00483d32a1f382d95fbc7b5532cad8f36527b7d7
    if (root == nullptr) {
      return;
    }
    // mapDepth[root->val] = max(mapDepth[root->val], cntDepth); // 键值不存在，[]访问插入默认值；此处可用，不建议
    pair<map<int, int>::iterator, bool> ret = mapDepth.insert(pair<int, int>(root->val, cntDepth));
    // 已存在key，取最大val
    if (!ret.second) {
      (ret.first)->second = max((ret.first)->second, cntDepth);
    }
    getDepth(root->left, cntDepth + 1);
    getDepth(root->right, cntDepth + 1);
<<<<<<< HEAD
  }

  vector<int> ValueDepth(const vector<int> &target, const TreeNode *root) {
    if (!root) {
      return {};
    }

    // 获取深度值
    getDepth(root, 1);

    // 一次反向遍历，获取key大于当前key的节点的最大深度值
    auto it1 = mapDepth.rbegin();
    auto it2 = it1;
    for (it1++; it1 != mapDepth.rend(); ++it1, ++it2) {
      it1->second = max(it1->second, (it2)->second);
    }

    // for (auto it1 = mapDepth.rbegin(); it1 != mapDepth.rend(); ++it1) {
    //   it1->second = max(it1->second, 10);
    // }

    vector<int> retVec;
    for (const int &x : target) {
      auto iter = mapDepth.lower_bound(x);
      if (iter != mapDepth.end()) {
        retVec.push_back(iter->second);
      } else {
        retVec.push_back(-1);
      }
    }
    return retVec;
=======
  }

  vector<int> ValueDepth(const vector<int> &target, const TreeNode *root) {
    if (!root) {
      return {};
    }
    // 一次反向遍历，获取key大于当前key的节点的最大深度值
    // for (auto it = mapDepth.rbegin() + 1; it != mapDepth.rend(); ++it) {
    //     it->second = max(it->second, (it + 1)->second);
    // }
    // 一次反向遍历，获取key大于当前key的节点的最大深度值
    auto it1 = mapDepth.rbegin();
    auto it2 = it1;
    for (it1++; it1 != mapDepth.rend(); ++it1, ++it2) {
      it1->second = max(it1->second, (it2)->second);
    }

    vector<int> retVec;
    for (const int &x : target) {
      retVec.push_back(mapDepth.lower_bound(x)->second);
    }
    return retVec;
  }

  int maxDepth(TreeNode *root) {
    if (!root) {
      return 0;  // 特殊情况处理
    }
    getDepth(root, 1);
    sort(depth.begin(), depth.end(), less<int>());
    return depth.back();
>>>>>>> 00483d32a1f382d95fbc7b5532cad8f36527b7d7
  }
};

int main() {
  Solution sol;

  stringstream sstr;
<<<<<<< HEAD
  sstr << "3,4,11,3,null,null,8,7,null,null,null,null,null,5";
=======
  sstr << "3,4,11,3,null,null,8,7,null,5";
>>>>>>> 00483d32a1f382d95fbc7b5532cad8f36527b7d7
  vector<string> vec;
  string s;
  while (getline(sstr, s, ',')) {
    vec.push_back(s);
  }
  for_each(vec.begin(), vec.end(), [](const string str) { cout << str << endl; });
  cout << "vec size: " << vec.size() << endl;
  int treeDepth = log2(vec.size() + 1);
  cout << "treeDepth: " << treeDepth << endl;

  TreeNode *root = constructBinaryTree(vec, 0);  // 递归构建完全/满二叉树

<<<<<<< HEAD
  sstr.clear();
  sstr << "6,2,9,7,9";
  vector<int> target;
  while (getline(sstr, s, ',')) {
    target.push_back(stoi(s));
  }
  // for_each(target.begin(), target.end(), [](const int x) { cout << x << endl; });

  vector<int> ans = sol.ValueDepth(target, root);
  for_each(ans.begin(), ans.end(), [](const int x) { cout << x << endl; });

=======
  // sol.getDepth(root, 1);
  // cout << sol.maxDepth(root) << "====" << endl;

  ;
  sstr.clear();
  sstr << "6,2,9,7,9";
  vector<int> target;
  while (getline(sstr, s, ',')) {
    target.push_back(stoi(s));
  }
  for_each(target.begin(), target.end(), [](const int x) { cout << x << endl; });
  // vector<int> ans = sol.ValueDepth(target, root);
  // for_each(ans.begin(), ans.end(), [](const int x) { cout << x << endl; });
>>>>>>> 00483d32a1f382d95fbc7b5532cad8f36527b7d7
  return 0;
}
