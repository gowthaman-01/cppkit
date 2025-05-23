void test_print();

/*
Expected Output (order may vary for unordered containers):

{1, 2, 3}                                       // std::array
{4, 5, 6}                                       // std::deque
{7, 8, 9}                                       // std::forward_list
{10, 11, 12}                                    // std::list
{{1, 10}, {2, 20}}                              // std::map
{{1, 100}, {1, 200}, {2, 300}}                  // std::multimap
{1, 2, 2, 3}                                    // std::multiset
{8, 5, 2}                                       // std::priority_queue (max-heap order)
{6, 7, 8}                                       // std::queue
{9, 10, 11}                                     // std::set
{14, 13, 12}                                    // std::stack
hello                                           // std::string
world                                           // std::string_view
{{3, 30}, {4, 40}}                              // std::unordered_map (order not guaranteed)
{{5, 50}, {5, 55}}                              // std::unordered_multimap (order not guaranteed)
{6, 6, 7}                                       // std::unordered_multiset (order not guaranteed)
{8, 9, 10}                                      // std::unordered_set (order not guaranteed)
{11, 12, 13}                                    // std::vector
{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}}   // std::vector<std::vector> (2D vector)
*/

int main(int argc, const char * argv[]) {
    test_print();
}
