#include <iostream>
#include <ncurses.h>
#include <vector>
#include "tui.h"
#include "disk.h"

bool running = true;

tui::MainMenuChoice menu_choice;
tui::ListDisksChoice list_menu_choice;

int main() {
    tui::tui_init();
    while(running) {
        // list drive
        // exit disktastic
        menu_choice = tui::draw_main_menu();
        switch(menu_choice) {
            case tui::MainMenuChoice::MENU_LIST:
            //===list disks===
            list_menu_choice = tui::draw_list_menu();
            switch(list_menu_choice) {
                case tui::ListDisksChoice::MENU_HOME: break;
                case tui::ListDisksChoice::MENU_EXIT:
                running = false;
                break;
            }
            break;
            //===list disks===
            case tui::MainMenuChoice::MENU_EXIT:
            //===exit app===
            running = false;
            break;
            //===exit app===
        }
    }
    tui::tui_exit();
}
