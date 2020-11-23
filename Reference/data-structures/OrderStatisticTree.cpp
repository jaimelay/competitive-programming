#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

Tree<int> ord_s;
ord_s.insert(2);
ord_s.insert(5);
ord_s.insert(7);
ord_s.insert(9);

// find_by_order returns an iterator to the element at a given position
auto x = ord_s.find_by_order(2);
cout << *x << "\n"; // 7

// order_of_key returns the position of a given element
cout << ord_s.order_of_key(7) << "\n"; // 2

// If the element does not appear in the set, we get the position that the element would have in the set
cout << ord_s.order_of_key(6) << "\n"; // 2
cout << ord_s.order_of_key(8) << "\n"; // 3