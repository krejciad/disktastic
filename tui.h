#pragma once

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

    MainMenuChoice draw_main_menu();
    ListDisksChoice draw_list_menu();
}
