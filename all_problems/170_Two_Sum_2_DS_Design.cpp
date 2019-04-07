/* Problem Description
   Design and implement a TwoSum class. It should support the following operations: add and find.

add - Add the number to an internal data structure.
find - Find if there exists any pair of numbers which sum is equal to the value.

For example,

add(1); 
add(3); 
add(5);
find(4) -> true
find(7) -> false

Using unordered map
*/

#include"header.h"
class TwoSum {
  private:
    unordered_map<int, int> M;
  public:
    void add(int a) {
      M[a] ++;
    }


    bool find(int k) {
      int S = M.size();

      unordered_map<int, int>::iterator  F = M.begin();

      for(; F != M.end(); F++) {
        auto i = M.find(k - F->first);
        if(i != M.end()) {
          if(F != i) {
            return true;
          } else {
            if (i->second > 1) {
              return true;
            } else {
              return false;
            }
          }
        }
      }
      return false;
    }
};
int main() {
  TwoSum S;
  S.add(3);
  S.add(5);
  S.add(5);
  S.add(1);

  //S.print();
  cout << S.find(4) << "\n";
  cout << S.find(7) << "\n";
  cout << S.find(10) << "\n";

  return 0;
}
