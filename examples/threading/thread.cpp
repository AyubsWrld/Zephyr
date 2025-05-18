#include <iostream>
#include <thread>
#include <chrono>
 
long Fibonacci(unsigned n)
{
    return n < 2 ? n : Fibonacci(n - 1) + Fibonacci(n - 2);
}
 
int main()
{
    const auto start{std::chrono::steady_clock::now()};
    const auto fb{Fibonacci(42)};
    const auto finish{std::chrono::steady_clock::now()};
    const std::chrono::duration<double> elapsed_seconds{finish - start};
 
    std::cout << "Fibonacci(42): " << fb << "\nElapsed time: ";
//  std::cout << elapsed_seconds.count() << "s\n"; // Before C++20
    std::cout << elapsed_seconds << '\n'; // C++20's chrono::duration operator<<
 
    // Prints UTC and local time.
    const auto tp_utc{std::chrono::system_clock::now()};
    std::cout << "Current time 'UTC' is: " << tp_utc << "\n"
                 "Current time 'Local' is: "
              << std::chrono::current_zone()->to_local(tp_utc) << '\n';
}
