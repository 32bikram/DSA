# Min Heap
  Each node is less than or equal to the values of its children.
# Max Heap
  Each node is greater than or equal to the values of its children.
Additionally, a heap is a complete binary tree, meaning all levels are fully filled except possibly the last level, which is filled from left to right.
# Heap Operations in C++
There are several essential operations used with heaps:
1. **Insert:** Adds a new element to the heap while maintaining the heap property (either min or max heap ordering).
2. **Extract Min/Max:** Removes and returns the minimum/maximum element from the heap.
3. **Peek:** Returns the minimum/maximum element without removing it.
4. **Heapify:** Reorganizes a subtree for a given node to ensure the heap property holds.
5. **Delete:** Removes a specific element from the heap.
6. **Increase/Decrease Key:** Changes the value of an existing element in the heap.
7. **Build Heap:** Converts an array into a proper min or max heap.
<img width="751" height="467" alt="image" src="https://github.com/user-attachments/assets/e37bafd8-b6be-4496-9339-344dfcfb50f4" />
# Building a heap from array STL
    // Initializing a vector
    vector<int> v1 = { 20, 30, 40, 25, 15 };

    // Converting vector into a heap
    // using make_heap()
    make_heap(v1.begin(), v1.end());

    // Displaying the maximum element of heap
    // using front()
    cout << "The maximum element of heap is : ";
    cout << v1.front() << endl;
    
| Function          | Purpose                                          |
| ----------------- | ------------------------------------------------ |
| `make_heap()`     | Convert a range into a heap                      |
| `push_heap()`     | Add the last element into an existing heap       |
| `pop_heap()`      | Move the top element to the end and restore heap |
| `sort_heap()`     | Sort a heap                                      |
| `is_heap()`       | Check whether a range is a heap                  |
| `is_heap_until()` | Find where the heap property stops               |

    vector<int> v = {5, 3, 4};
    make_heap(v.begin(), v.end());
    
    v.push_back(2);                  // just adds 2
    push_heap(v.begin(), v.end());   // restores heap property

    pop_heap(...);        // moves max/min to the end + fixes heap
    v.pop_back();         // actually removes it
