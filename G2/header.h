#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<unordered_set>
#include<unordered_map>
#include<map>
#include<iostream>
#include<climits>
#include <algorithm>
#include <sstream> // isstringstream
#include <iterator> //istream_iterator


using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

  struct TreeLinkNode {
   int val;
   TreeLinkNode *left, *right, *next;
   TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
   TreeLinkNode(int xx, TreeLinkNode* x, TreeLinkNode *y, TreeLinkNode *z) : val(xx), left(x), right(y), next(z) {}
  };

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      int count; // leftsubtree + 1 + rightsubtree
      TreeNode(int x) : val(x), left(NULL), right(NULL), count(0) {}
      TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r), count(0) {}
      TreeNode(int x, TreeNode* l, TreeNode* r, int c) : val(x), left(l), right(r), count(c) {}
    public:
 };

template <typename T>
ostream& operator << (ostream& OS, vector<T> V) {
  for(int i = 0 ; i < V.size(); i ++) {
    OS << V[i] << " " ;
  }
  OS << "\n" ;
}

template <typename T>
ostream& operator << (ostream& OS, vector<vector<T> > V) {
  for(int i = 0 ; i < V.size(); i ++) {
    OS << V[i] << " " ;
  }
  OS << "\n" ;
}

template <typename T>
ostream& operator << (ostream& OS, pair<T,T>  P) {
  OS << P.first << " " << P.second ;
  OS << "\n" ;
}
ostream& operator << (ostream& OS, ListNode* root) {
  while(root) {
    OS << root->val << " " ;
    root = root->next;
  }
  OS << "\n" ;
}

ostream& operator<< (ostream& OS, TreeNode *BT) {

  if(NULL  == BT) return OS;

  vector<TreeNode*> Buffer1; 
  vector<TreeNode*> Buffer2; 

  Buffer1.push_back(BT);

  while(false == Buffer1.empty()) {
    for(int i = 0 ; i < Buffer1.size(); i++) {
      OS << Buffer1[i]->val << " " ;  
      if(NULL != Buffer1[i]->left) {
        Buffer2.push_back(Buffer1[i]->left);
      }
      if(NULL != Buffer1[i]->right) {
        Buffer2.push_back(Buffer1[i]->right);
      }
    }

    Buffer1 = Buffer2;
    Buffer2.clear();
    OS <<  "\n " ;  
  }
}
 
const char C = ' ';

template <typename T>
class Stack {
  private:
    vector<T> V;
    int sp;

  public:
    Stack() {
         sp = -1;
    }

    void push(T val) {
      V.push_back(val);
      sp++;
    }

    void pop() {
      if(-1 == sp) {
        cerr << "Cannot pop\n";
        return;
      }
      V.pop_back();
      sp--;
    }

     T top() {
      if(-1 == sp) {
        cerr << "Cannot top\n";
        return T();
      }
      return V[sp];
    }

    bool isempty() {
      return sp == -1;
    }
};
