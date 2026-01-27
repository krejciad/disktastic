//#include <iostream>
//#include <sstream>
//#include <string>
//#include <vector>
#include "tui.h"
//#include <ncurses.h>

void tui::tui_init() {
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    curs_set(0);

    if(has_colors()) {
        start_color();
        use_default_colors();
        init_pair(1, COLOR_CYAN, -1); // header
        init_pair(2, COLOR_WHITE, -1); // text
        init_pair(3, COLOR_MAGENTA, -1); // highlight
        init_pair(4, COLOR_BLUE, -1); // frame
    }
}

void tui::tui_exit() {
    endwin();
}

int center_x(int width, const std::string& text) {
    int pos = (width - text.length()) / 2;
    return pos < 0 ? : pos;
}

#include "tui_mode.h"
