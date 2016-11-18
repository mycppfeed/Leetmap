/* Problem Description
 * You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.

Define a pair (u,v) which consists of one element from the first array and one element from the second array.

Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.

Example 1:
Given nums1 = [1,7,11], nums2 = [2,4,6],  k = 3

Return: [1,2],[1,4],[1,6]

The first 3 pairs are returned from the sequence:
[1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
Example 2:
Given nums1 = [1,1,2], nums2 = [1,2,3],  k = 2

Return: [1,1],[1,1]

The first 2 pairs are returned from the sequence:
[1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
Example 3:
Given nums1 = [1,2], nums2 = [3],  k = 3 

Return: [1,3],[2,3]

All possible pairs are returned from the sequence:
[1,3],[2,3]
*/

#include"header.h"

class Node {
  private:
    int a, b;
    int V;
  public:
    Node(){}
    Node(int i, int j): a(i), b(j), V(i+j)  {
    }
    bool operator() (Node& a, Node& b) {
      return a.V < b.V;
    }
    pair<int, int> getP() const {
      return make_pair(a, b);
    }
    int getV() const {
      return a+b;
    }
};

class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        priority_queue<Node, vector<Node>, Node> Q;
        size_t s1 = std::min(nums1.size(), (size_t)k);
        size_t s2 = std::min(nums2.size(), (size_t)k);
        for(int i = 0 ; i < s1; i++) {
            for(int j = 0 ; j < s2; j++) {
                if(Q.size() < k) {
                    Q.push(Node(nums1[i], nums2[j]));
                } else {
                    if(nums1[i] + nums2[j] < Q.top().getV()) {
                        Q.push(Node(nums1[i], nums2[j]));
                        Q.pop();
                    }
                }
            }
        }

      
      vector<pair<int, int>> R;
      while(Q.empty() == false) {    
          Node p = Q.top();
          Q.pop();
          R.push_back(p.getP());
      }

      return R;
    }
};

int main() {
  Solution S;

  vector<int> nums1({1,7,11});
  vector<int> nums2({2,4,6});

  cout << S.kSmallestPairs(nums1, nums2, 3);

  return 0;
}
