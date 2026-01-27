#include <iostream>
#include <ncurses.h>
#include <vector>
#include "tui.h"
#include "disk.h"

int main() {
    bool running = true;

    tui::MainMenuChoice menu_choice;
    tui::ListDisksChoice list_menu_choice;

    tui::tui_init();
    while(running) {

        menu_choice = tui::draw_main_menu();
        switch(menu_choice) {

            case tui::MainMenuChoice::MENU_LIST:
            list_menu_choice = tui::draw_list_menu();
            switch(list_menu_choice) {
                case tui::ListDisksChoice::MENU_HOME: break;
                case tui::ListDisksChoice::MENU_EXIT: running = false; break;
                default: break;
            }
            break;

            case tui::MainMenuChoice::MENU_EXIT: running = false; break;

            default: break;
        }
    }
    tui::tui_exit();
    return 0;
}
