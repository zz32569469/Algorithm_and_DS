#include<bits/extc++.h>

using namespace __gnu_pbds;
tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> t; 
/*
定義一顆紅黑樹
int 關鍵字類型
null_type無映射
less<int> 從小到大排序（去重）
greater<int> 從大到小排序（去重）
less_equal<int> 從小到大排序
greater_equal<int> 從大到小排序
rb_tree_tag 紅黑樹（splay_tree_tag）
tree_order_statistics_node_update結點更新
插入t.insert();
刪除t.erase();
求k在樹中是第幾大: t.order_of_key();
求樹中的第k大: t.find_by_order();
t.lower_bound();
t.upper_bound();
a.join(b) b 併入 a 前提是兩棵樹的 key 的取值範圍不相交
a.split(v,b) key 小於等於v的元素屬於 a，其餘的屬於 b
*/
