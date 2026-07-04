#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include <vector>
#include <cctype> // Thư viện chứa hàm tolower

bool isValidUsername(const std::string& username) {
    if (username.empty()) return false;
    
    for (char c : username) {
        if (!(c >= 'a' && c <= 'z') && 
            !(c >= '0' && c <= '9') && 
            c != '_' && 
            c != '.') {
            return false;
        }
    }
    return true;
}

void trimRegistry(std::string& s) {
    if (!s.empty() && s.back() == '\r') s.pop_back();
}

int main() {
    const std::string pathFollowers  = "D:\\CHECK FOLLOWER\\Followers.txt",
                    pathFollowing = "D:\\CHECK FOLLOWER\\Following.txt",
                    pathOldData  = "D:\\CHECK FOLLOWER\\OldData.txt";
/*  
    [FILE OldData.txt]: Nếu một Username tồn tại trong 'OldData.txt' (quá khứ có theo dõi) 
    nhưng KHÔNG tồn tại trong 'Followers.txt' (hiện tại đã biến mất) -> Xác định người đó đã Unfollow.
 */
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

    // --------------------------Tìm người không follow lại------------------------
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
    char choice;
    std::cout << "Would you like to save changes? (Y/N): ";
    while (std::cin >> choice) {
        choice = std::tolower(choice);
        if (choice == 'y' || choice == 'n') {
            break;
        }
        std::cout << "[ERROR] Invalid input. Please only type Y or N: ";
    }

    if (choice == 'y') {
        std::ofstream fUpdateOld(pathOldData, std::ios::trunc);
        if (fUpdateOld.is_open()) {
            for (const auto& user : validFollowersList) {
                fUpdateOld << user << "\n";
            }
            fUpdateOld.close();
            std::cout << "[INFO] The update was successful !!" << std::endl;
        } else {
            std::cout << "[ERROR] Cannot open file to write. " << std::endl;
        }
    } else {
        std::cout << "[INFO] File save operation canceled." << std::endl;
    }
    std::cout<<" \n\n\n\n\n\n";
    return 0;
}