#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>
#include "banner.h"
#include "scanner.h"
#include "cracker.h"

bool isTermux() {
    const char* termuxEnv = std::getenv("PREFIX");
    return (termuxEnv != nullptr && std::string(termuxEnv).find("com.termux") != std::string::npos);
}

void showLegalWarning() {
    std::cout << "\n\033[1;31m[!] LEGAL NOTICE:\033[0m\n";
    std::cout << "This tool is for EDUCATIONAL and AUTHORIZED penetration testing ONLY.\n";
    std::cout << "Unauthorized access to wireless networks is ILLEGAL.\n\n";
    std::cout << "Press Enter to continue...";
    std::cin.ignore();
    std::cin.get();
}

int main() {
    bool termux = isTermux();
    displayBanner(termux);
    showLegalWarning();

    std::vector<std::string> networks = scanNetworks();
    if (networks.empty()) {
        std::cout << "\n\033[1;31m[!] No networks found. Exiting...\033[0m\n";
        return 1;
    }

    displayNetworks(networks);

    std::cout << "Enter network number to target (0 to exit): ";
    int choice;
    std::cin >> choice;

    if (choice > 0 && choice <= static_cast<int>(networks.size())) {
        crackNetwork(networks[choice - 1]);
    }

    std::cout << "\n\033[1;32m[+] Operation completed. Check cracked_passwords.txt\033[0m\n";
    return 0;
}
