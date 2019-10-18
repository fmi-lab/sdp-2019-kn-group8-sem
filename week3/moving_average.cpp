#include <iostream>
#include <chrono>
#include <ctime>
#include <thread>
#include <queue>

class MovingAverage {
    long window_size;
    std::queue<double> elements;
    double current_sum = 0;
public:
    MovingAverage(int window_size) {
        this->window_size = window_size;
    }
    
    double next(double element) {
        this->elements.push(element);
        this->current_sum += element;
        while (this->elements.size() > this->window_size) {
            current_sum = current_sum - this->elements.front();
            this->elements.pop();
        }
        return current_sum / elements.size();
    }
};

int main() {
    MovingAverage m(2);
    std::cout << m.next(1) << std::endl;
    std::cout << m.next(2) << std::endl;
    std::cout << m.next(3) << std::endl;
    std::cout << m.next(4) << std::endl;
    std::cout << m.next(5) << std::endl;
}

