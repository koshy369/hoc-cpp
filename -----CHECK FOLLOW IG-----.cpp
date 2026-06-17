#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include <vector>
#include <cctype> // Thư viện chứa hàm tolower

bool isValidUsername(const std::string& username) {
    if (username.empty()) return false;
    for (char c : username) {
        if (!(c >= 'a' && c <= 'z') && c != '_' && c != '.') return false;
    }
    return true;
}

void trimRegistry(std::string& s) {
    if (!s.empty() && s.back() == '\r') s.pop_back();
}

int main() {
    const std::string pathFollowers = "D:\\nguoi_theo_doi.txt";
    const std::string pathFollowing = "D:\\dang_theo_doi.txt";
    const std::string pathOldData   = "D:\\old_data.txt";

    std::ifstream fFollowers(pathFollowers);
    std::ifstream fFollowing(pathFollowing);
    std::ifstream fOldData(pathOldData);

    std::unordered_set<std::string> currentFollowers;
    std::vector<std::string> validFollowersList;

    // 1. Nạp danh sách N
    if (fFollowers.is_open()) {
        std::string line;
        while (std::getline(fFollowers, line)) {
            trimRegistry(line);
            if (isValidUsername(line)) {
                currentFollowers.insert(line);
                validFollowersList.push_back(line);
            }
        }
        fFollowers.close();
    }

    // 2. Tìm người Unfollow
    int unfollowCount = 0;
    if (fOldData.is_open()) {
        std::cout << "----------- Link to unfollowers' accounts-----------" << std::endl;
        std::string line;
        while (std::getline(fOldData, line)) {
            trimRegistry(line);
            if (isValidUsername(line) && currentFollowers.find(line) == currentFollowers.end()) {
                std::cout << "https://www.instagram.com/" << line << std::endl;
                unfollowCount++;
            }
        }
        fOldData.close();
    }
    std::cout << "Number of unfollowers: " << unfollowCount << "\n" << std::endl;

    // 3. Tìm người không follow lại
    int notFollowingBackCount = 0;
    if (fFollowing.is_open()) {
        std::cout << "--- Non-followers ---" << std::endl;
        std::string line;
        while (std::getline(fFollowing, line)) {
            trimRegistry(line);
            if (isValidUsername(line) && currentFollowers.find(line) == currentFollowers.end()) {
                std::cout << "https://www.instagram.com/" << line << "/" << std::endl;
                notFollowingBackCount++;
            }
        }
        fFollowing.close();
    }
    std::cout << "Number of non-followers: " << notFollowingBackCount << "\n" << std::endl;

    // 4. Cổng kiểm soát cập nhật dữ liệu
    char choice;
    std::cout << "Would you like to save changes to old_data.txt? (Y/N): \n\n\n\n\n\n";
    while (std::cin >> choice) {
        choice = std::tolower(choice); // Ép về chữ thường để triệt tiêu sai số do Caps Lock
        if (choice == 'y' || choice == 'n') {
            break; // Thoát vòng lặp nếu nhập chuẩn
        }
        std::cout << "[ERROR] Invalid input. Please only type Y or N: ";
    }

    // 5. Rẽ nhánh thực thi
    if (choice == 'y') {
        std::ofstream fUpdateOld(pathOldData, std::ios::trunc);
        if (fUpdateOld.is_open()) {
            for (const auto& user : validFollowersList) {
                fUpdateOld << user << "\n";
            }
            fUpdateOld.close();
            std::cout << "[INFO] The update was successful. D:\\old_data.txt. " << std::endl;
        } else {
            std::cout << "[ERROR] Cannot open file D:\\old_data.txt to write. " << std::endl;
        }
    } else {
        std::cout << "[INFO] File save operation canceled." << std::endl;
    }

    return 0;
}