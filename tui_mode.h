#include "tui.h"

tui::MainMenuChoice tui::draw_main_menu() {
    std::vector<std::string> items = {
        "List Disks        [ l ]",
        "Mount / Unmount   [ m ]",
        "Format Drive      [ f ]",
        "Partitioning      [ p ]",
        "Rename Drive      [ n ]",
        "Backup Files      [ b ]",
        "Sync Files        [ s ]",
        "Exit Disktastic   [ q ]"
    };

    int highlight = 0;
    //int choice = -1;
    int ch;

    while(true) {
        clear();

        int h, w;
        getmaxyx(stdscr, h, w);
        int title_pos = 6, note_pos = h - 1, menu_pos = 16;

        std::string note = " Use arrows or symbols to navigate ";

        attron(COLOR_PAIR(4) | A_BOLD);
        box(stdscr, 0, 0);
        mvprintw(note_pos, center_x(w, note), "%s", note.c_str());
        attroff(COLOR_PAIR(4) | A_BOLD);

        int title_separation = center_x(w, "    ___  _     __   __           __  _    ");
        attron(COLOR_PAIR(1) | A_BOLD);
        mvprintw(title_pos, title_separation, "%s",     "    ___  _     __   __           __  _");
        mvprintw(title_pos + 1, title_separation, "%s", "   / _ \\(_)__ / /__/ /____ ____ / /_(_)___");
        mvprintw(title_pos + 2, title_separation, "%s", "  / // / (_-</  '_/ __/ _ `(_-</ __/ / __/");
        mvprintw(title_pos + 3, title_separation, "%s", " /____/_/___/_/\\_\\\\__/\\_,_/___/\\__/_/\\__/");
        attroff(COLOR_PAIR(1) | A_BOLD);

        for (size_t i = 0; i < items.size(); ++i) {
            if((int)i == highlight) attron(COLOR_PAIR(3) | A_BOLD);

            mvprintw(menu_pos + i, center_x(w, items[0]), items[i].c_str());

            if((int)i == highlight) attroff(COLOR_PAIR(3) | A_BOLD);
        }

        refresh();
        ch = getch();

        switch(ch) {
            case KEY_UP:
                highlight--;
                if(highlight < 0) highlight = static_cast<int>(items.size()) - 1;
                break;

            case KEY_DOWN:
                highlight++;
                if(highlight >= static_cast<int>(items.size())) highlight = 0;
                break;

            case 10:
                if(highlight == 0) return tui::MainMenuChoice::MENU_LIST;
                if(highlight == 1) return tui::MainMenuChoice::MENU_MOUNT;
                if(highlight == 2) return tui::MainMenuChoice::MENU_FORMAT;
                if(highlight == 3) return tui::MainMenuChoice::MENU_PARTITION;
                if(highlight == 4) return tui::MainMenuChoice::MENU_RENAME;
                if(highlight == 5) return tui::MainMenuChoice::MENU_BACKUP;
                if(highlight == 6) return tui::MainMenuChoice::MENU_SYNC;
                if(highlight == 7) return tui::MainMenuChoice::MENU_EXIT;
            break;

            case 'l': return tui::MainMenuChoice::MENU_LIST;
            case 'm': return tui::MainMenuChoice::MENU_MOUNT;
            case 'f': return tui::MainMenuChoice::MENU_FORMAT;
            case 'p': return tui::MainMenuChoice::MENU_PARTITION;
            case 'n': return tui::MainMenuChoice::MENU_RENAME;
            case 'b': return tui::MainMenuChoice::MENU_BACKUP;
            case 's': return tui::MainMenuChoice::MENU_SYNC;
            case 'q': return tui::MainMenuChoice::MENU_EXIT;
            default: break;
        }
    }
}

tui::ListDisksChoice tui::draw_list_menu() {
    int highlight = 0;
    int ch;

    while(true) {
        clear();

        int h, w;
        getmaxyx(stdscr, h, w);
        int title_pos = 5, note_pos = h - 1, menu_pos = 16;

        std::string title = " List Disks ";
        std::string note_left = " [ x ] Menu ";
        std::string note_right = " [ q ] Quit ";
        int total_len = note_left.length() + 8 + note_right.length();
        int start = center_x(w, std::string(total_len, ' '));
        attron(COLOR_PAIR(4) | A_BOLD);
        box(stdscr, 0, 0);
        mvprintw(0, center_x(w, title), "%s", title.c_str());
        mvprintw(note_pos, start, "%s", note_left.c_str());
        mvhline(note_pos, start + note_left.length(), ACS_HLINE, 8);
        mvprintw(note_pos, start + note_left.length() + 8, "%s", note_right.c_str());
        attroff(COLOR_PAIR(4) | A_BOLD);

        std::string pager1 = "Page ", pager2 = " of ";
        int page_current = 1, page_count = 1;
        std::stringstream pager;
        pager << pager1 << page_current << pager2 << page_count;
        attron(COLOR_PAIR(1) | A_BOLD);
        mvprintw(2, title_pos, "Reachable Disks:");
        mvprintw(2, w - pager.str().length() - title_pos, "%s", pager.str().c_str());
        attroff(COLOR_PAIR(1) | A_BOLD);

        refresh();
        ch = getch();

        switch(ch) {
            case 'x': return tui::ListDisksChoice::MENU_HOME;
            case 'q': return tui::ListDisksChoice::MENU_EXIT;
            default: break;
        }
    }
}
