#include <iostream>
#include <vector>
#include <limits>

int main() {
    // 1. Determine Your Memory Limit:
    const size_t maxMemoryBytes = 1024 * 1024 * 1000; // Example: 1000 MB

    // 2. Track Memory Usage:
    size_t usedMemory = 0;
    std::vector<int*> allocatedPointers; // Store pointers to allocated memory

    while (true) {
        // 3. Check Available Memory:
        if (usedMemory >= maxMemoryBytes) {
            std::cerr << "Memory limit reached!" << std::endl;
            break; 
        }

        // 4. Allocate Memory (If Possible):
        int* a = new int;
        usedMemory += sizeof(int); // Update memory usage

        // Store the pointer for later deallocation:
        allocatedPointers.push_back(a);
        
        // Rest of your logic...
    }

    // 5. Deallocate Memory When Done:
    for (int* ptr : allocatedPointers) {
        delete ptr;
    }
    
    return 0;
}
