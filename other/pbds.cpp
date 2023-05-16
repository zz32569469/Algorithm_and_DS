#include<bits/extc++.h>

using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
				pbds; //rb_tree

//less_equal<int>//upper_bound<=>lower_bound

pbds s;//s.find_by_order(k);s.order_by_key(x);
