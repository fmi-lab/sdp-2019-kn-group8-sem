#include <iostream>
#include <chrono>
#include <ctime>
#include <thread>
#include <queue>

class RecentCounter {
private:
    int duration_seconds;
    std::queue<int> invocations;
public:
    RecentCounter(int duration_seconds) {
        this->duration_seconds = duration_seconds;
    }

    int ping() {
        // time in seconds
        auto current_time = std::time(nullptr);
        this->invocations.push(current_time);

        while (!this->invocations.empty() &&
            current_time - this->invocations.front() > this->duration_seconds) {
            std::cout << "pop \n";
            this->invocations.pop();
        }
        // return number of pings in last duration seconds
        return this->invocations.size();
    }
};

int main() {
    RecentCounter counter(3);
    std::cout << counter.ping() << std::endl;  // 1
    std::cout << counter.ping() << std::endl;  //2
    std::cout << counter.ping() << std::endl; // 3
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    std::cout << counter.ping() << std::endl; // 4
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    std::cout << counter.ping() << std::endl; // 2
}
 