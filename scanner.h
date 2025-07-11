#ifndef SCANNER_H
#define SCANNER_H

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

std::vector<std::string> scanNetworks() {
    std::cout << "\n[+] Scanning for available WiFi networks...\n" << std::endl;
    
    // Using airodump-ng to scan networks
    system("airodump-ng wlan0 --output-format csv -w scan_results --write-interval 1 > /dev/null 2>&1 & sleep 10");
    system("killall airodump-ng");
    
    // Parse the scan results (simplified for example)
    std::vector<std::string> networks;
    // In a real implementation, you would parse the scan_results-01.csv file
    networks.push_back("HomeWiFi");
    networks.push_back("OfficeNetwork");
    networks.push_back("PublicWiFi");
    networks.push_back("NeighborAP");
    
    return networks;
}

void displayNetworks(const std::vector<std::string>& networks) {
    std::cout << "\nAvailable Networks:\n";
    for (size_t i = 0; i < networks.size(); ++i) {
        std::cout << "[" << i + 1 << "] " << networks[i] << std::endl;
    }
    std::cout << std::endl;
}

#endif