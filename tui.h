#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <ncurses.h>

int center_x(int, const std::string&);

namespace tui{
    void tui_init();
    void tui_exit();

    enum class MainMenuChoice {
        MENU_LIST,
        MENU_MOUNT,
        MENU_FORMAT,
        MENU_PARTITION,
        MENU_RENAME,
        MENU_BACKUP,
        MENU_SYNC,
        MENU_EXIT
    };

    enum class ListDisksChoice {
        MENU_HOME,
        MENU_EXIT
    };
}

namespace tui{
    MainMenuChoice draw_main_menu();
    ListDisksChoice draw_list_menu();
}
