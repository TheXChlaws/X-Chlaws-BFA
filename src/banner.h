#ifndef BANNER_H
#define BANNER_H

#include <iostream>

void displayBanner(bool isTermux) {
    if (isTermux) {
        std::cout << R"(
\033[1;36m
  _____           _    _____ _    ___  
 / ____|         | |  / ____| |  |__ \ 
| (___   ___ ___| |_| |    | |__   ) |
 \___ \ / __/ __| __| |    | '_ \ / / 
 ____) | (_| (__| |_| |____| | | |_|  
|_____/ \___\___|\__|\_____|_| |_(_)  
\033[0m
\033[1;33mScript-Kid </> BFA Script\033[0m
)";
    } else {
        std::cout << R"(
\033[1;35m
__  __  ___  _   _ ____ _    ___ _   _ ____  
\ \/ / / _ \| | | / ___| |  |_ _| \ | / ___| 
 \  / | | | | | | \___ \ |   | ||  \| \___ \ 
 /  \ | |_| | |_| |___) | |___| || |\  |__) |
/_/\_\_\___/ \___/|____/|_____|___|_| \_|____/ 
\033[0m
\033[1;32mBruteforce Attack WiFi Assessment Tool\033[0m
)";
    }
    std::cout << "\n\033[1;33mDesigned by X-Chlaws\033[0m\n\n";
}

#endif
