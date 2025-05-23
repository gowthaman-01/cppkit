#include "../include/cppkit.hpp"

void test_print() {
    print(array<int, 3>{1, 2, 3});
    
    print(deque<int>{4, 5, 6});
    
    print(forward_list<int>{7, 8, 9});
    
    print(list<int>{10, 11, 12});
    
    print(map<int, int>{{1, 10}, {2, 20}});
    
    print(multimap<int, int>{{1, 100}, {1, 200}, {2, 300}});
    
    print(multiset<int>{1, 2, 2, 3});
    
    vector<int> v = {5, 2, 8};
    print(priority_queue<int>(v.begin(), v.end()));
    
    print(queue<int>(deque<int>{6, 7, 8}));
    
    print(set<int>{9, 10, 11});
    
    print(stack<int>(deque<int>{12, 13, 14}));
    
    print(string("hello"));
    
    print(string_view("world"));
    
    print(unordered_map<int, int>{{3, 30}, {4, 40}});
    
    print(unordered_multimap<int, int>{{5, 50}, {5, 55}});
    
    print(unordered_multiset<int>{6, 6, 7});
    
    print(unordered_set<int>{8, 9, 10});
    
    print(vector<int>{11, 12, 13});
    
    // 2d matrix
    vector<vector<int>> matrix(3, vector<int>(4, 0));
    int val = 1;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 4; ++j)
            matrix[i][j] = val++;
    print(matrix);
}
