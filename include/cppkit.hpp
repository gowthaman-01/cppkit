#pragma once

// ==================================================
// Includes
// ==================================================

// I/O
#include <iostream>

// Containers
#include <array>
#include <deque>
#include <forward_list>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <string_view>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// Strings
#include <string>

// Algorithms & Utilities
#include <algorithm>
#include <cmath>
#include <functional>
#include <iterator>
#include <limits>
#include <numeric>
#include <tuple>
#include <utility>

// Memory
#include <memory>
#include <thread>

// ==================================================
// Using declarations
// ==================================================

using ll = long long;

// I/O
using std::cin;
using std::cout;
using std::endl;

// Containers
using std::array;
using std::deque;
using std::forward_list;
using std::list;
using std::map;
using std::multimap;
using std::multiset;
using std::priority_queue;
using std::queue;
using std::set;
using std::stack;
using std::string;
using std::string_view;
using std::unordered_map;
using std::unordered_multimap;
using std::unordered_multiset;
using std::unordered_set;
using std::vector;

// Algorithms & Utilities
using std::abs;
using std::accumulate;
using std::advance;
using std::all_of;
using std::any_of;
using std::begin;
using std::clamp;
using std::count;
using std::distance;
using std::end;
using std::fill;
using std::find;
using std::function;
using std::gcd;
using std::iota;
using std::lcm;
using std::log;
using std::make_pair;
using std::make_tuple;
using std::max;
using std::min;
using std::next;
using std::numeric_limits;
using std::pair;
using std::partial_sum;
using std::prev;
using std::reverse;
using std::sort;
using std::sqrt;
using std::swap;
using std::tie;
using std::tuple;

// Memory & Concurrency
using std::make_shared;
using std::make_unique;
using std::shared_ptr;
using std::thread;
using std::unique_ptr;

// ==================================================
// Type Traits to Detect Containers
// ==================================================

#include <type_traits>

// Primary template: assume T is NOT a container by default.
// This will be selected if no better match is found.
template <typename T, typename = void>
// This defines a struct is_container<T> with a default second parameter = void
// It inherits from std::false_type, which means: is_container<T>::value = false
struct is_container : std::false_type {};

// Specialization: selected ONLY if T has both begin() and end() functions.
// If the expressions inside std::void_t compiles, this version is used.
template <typename T>
// This struct is used instead of the default when begin() / end() are valid
// It inherits from std::true_type → so: is_container<T>::value = true
struct is_container<T, std::void_t<
    decltype(std::begin(std::declval<T>())),  // checks if T has begin()
    decltype(std::end(std::declval<T>()))     // checks if T has end()
>> : std::true_type {};

// Helper variable template for easier syntax
template <typename T>
// Now you can write: if constexpr (is_container_v<T>) { ... }
// instead of the longer: if constexpr (is_container<T>::value) { ... }
constexpr bool is_container_v = is_container<T>::value;


// ==================================================
// Debug Printing
// ==================================================

template <typename T>
std::enable_if_t<!is_container_v<T>> print_inline(const T& val) {
    cout << val;
}

template <typename T, typename U>
void print_inline(const pair<T, U>& p) {
    cout << '{';
    print_inline(p.first);
    cout << ", ";
    print_inline(p.second);
    cout << '}';
}

void print_inline(const string& s) {
    cout << s;
}

void print_inline(const std::string_view& sv) {
    cout << sv;
}

template <typename T>
std::enable_if_t<is_container_v<T>> print_inline(const T& container) {
    cout << '{';
    bool first = true;
    for (const auto& elem : container) {
        if (!first) cout << ", ";
        print_inline(elem);
        first = false;
    }
    cout << '}';
}

template <typename T>
void print_inline(const priority_queue<T>& pq) {
    auto pq_copy = pq;
    cout << '{';
    
    while (!pq_copy.empty()) {
        auto top = pq_copy.top();
        print_inline(top);
        pq_copy.pop();
        
        if (!pq_copy.empty()) {
            cout << ", ";
        }
    }
    
    cout << "}";
}

template <typename T>
void print_inline(const queue<T>& q) {
    auto q_copy = q;
    cout << '{';
    
    while (!q_copy.empty()) {
        auto front = q_copy.front();
        print_inline(front);
        q_copy.pop();
        
        if (!q_copy.empty()) {
            cout << ", ";
        }
    }
    
    cout << "}";
}

template <typename T>
void print_inline(const stack<T>& st) {
    auto st_copy = st;
    cout << '{';
    
    while (!st_copy.empty()) {
        auto top = st_copy.top();
        print_inline(top);
        st_copy.pop();
        
        if (!st_copy.empty()) {
            cout << ", ";
        }
    }
    
    cout << "}";
}

template <typename T>
void print(const T& val) {
    print_inline(val);
    cout << '\n';
}
