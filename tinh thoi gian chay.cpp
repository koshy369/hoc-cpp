#include <iostream>
#include <chrono>

int main() {
    // 1. Lấy mốc bắt đầu
    auto start = std::chrono::high_resolution_clock::now();

    // 2. Thực hiện code
    for(int i = 0; i < 1000000; ++i);

    // 3. Lấy mốc kết thúc
    auto end = std::chrono::high_resolution_clock::now();

    // 4. Tính toán độ lệch
    std::chrono::duration<double> duration = end - start;
    std::cout << "Thời gian: " << duration.count() << " giây" << std::endl;
    
    return 0;
}