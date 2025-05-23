# C++ Interview Boilerplate

A compact and powerful header-only utility for C++ interviews.

## Features
- Clean debug output for STL containers, including:
  - Sequential containers 
  `std::vector`, `std::array`, `std::deque`, `std::list`, `std::forward_list`

  - Associative containers  
  `std::set`, `std::multiset`, `std::map`, `std::multimap`

  - Unordered containers (hash-based)  
  `std::unordered_set`, `std::unordered_multiset`, `std::unordered_map`, `std::unordered_multimap`

  - Adaptors  
  `std::stack`, `std::queue`, `std::priority_queue`

  - Strings  
  `std::string`, `std::string_view`

  - Nested containers  
  e.g., `std::vector<std::vector<int>>`, `std::map<int, std::vector<string>>`, `std::pair<T, U>`

- Header-only: just include and go

- STL-wide `using` declarations for fast prototyping
  
- Supports all C++17-compliant compilers

## Usage
Download the header file (`cppkit.hpp`) and include it into your source file:
```cpp
#include "cppkit.hpp"

int main() {
    print(vector<int>{1, 2, 3});                           // {1, 2, 3}

    print(map<int, int>{{1, 10}, {2, 20}});                // {{1, 10}, {2, 20}}

    vector<int> v = {5, 2, 8};
    print(priority_queue<int>(v.begin(), v.end()));

    print(stack<int>(deque<int>{9, 8, 7}));                // {7, 8, 9}

    print(string("hello"));                                // hello

    print(unordered_set<int>{10, 11, 12});                 // {12, 11, 10} (order not guaranteed)

    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6}
    };
    print(matrix);                                         // {{1, 2, 3}, {4, 5, 6}}
}
