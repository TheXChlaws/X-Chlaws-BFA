#!/bin/bash
echo -e "\033[1;34m[X-Chlaws BFA Installer for Termux]\033[0m"
pkg update && pkg install -y git aircrack-ng wifite root-repo unstable-repo clang
git clone https://github.com/TheXChlaws/X-Chlaws-BFA.git
cd X-Chlaws-BFA
clang++ src/*.cpp -o Script-Kid -lncurses
chmod +x Script-Kid
./scripts/update_wordlists.sh
echo -e "\n\033[1;32mInstallation complete! Run with: ./Script-Kid\033[0m"