#include <iostream>
#include <thread>
#include <vector>

void busy_wait() {
    while (true) {
        // Busy-wait loop to keep the CPU busy
        for (volatile int i = 0; i < 1000000; ++i);
    }
}

int main() {
    const int num_threads = std::thread::hardware_concurrency(); // Number of CPU cores
    std::vector<std::thread> threads;

    std::cout << "Starting " << num_threads << " threads to increase CPU usage..." << std::endl;

    // Create threads that run the busy_wait function
    for (int i = 0; i < num_threads; ++i) {
        threads.emplace_back(busy_wait);
    }

    // Join threads (this will never actually happen because busy_wait runs indefinitely)
    for (auto& thread : threads) {
        thread.join();
    }

    return 0;
}
