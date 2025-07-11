#!/bin/bash
echo -e "\033[1;34m[X-Chlaws BFA Installer for Kali Linux]\033[0m"
sudo apt update && sudo apt install -y aircrack-ng wifite git g++ libncurses5-dev
git clone https://github.com/TheXChlaws/X-Chlaws-BFA.git
cd X-Chlaws-BFA
g++ src/*.cpp -o X-Chlaws-BFA -lncurses
chmod +x X-Chlaws-BFA
./scripts/update_wordlists.sh
echo -e "\n\033[1;32mInstallation complete! Run with: ./X-Chlaws-BFA\033[0m"