#include <ncurses/ncurses.h>
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

int kek(int argc, char ** argv) {

	//lista attributi
	/*
	    A_NORMAL
	    A_STANDOUT
	    A_REVERSE
	    A_BLINK
	    A_DIM
	    A_BOLD
	    A_PROTECT
	    A_INVIS
	    A_ALTCHARSET
	    A_CHARTEXT
	*/

	//lista colori (da usarsi come attributo)

	/*
	 * COLOR_PAIR(n) sceglia la coppia creata con ID n
	 * COLOR_BLACK
	 * COLOR_RED
	 * COLOR_GREEN
	 * COLOR_YELLOW
	 * COLOR_BLUE
	 * COLOR_MAGENTA
	 * COLOR_CYAN
	 * COLOR_WHITE
	 */

	//init_color(<COLOR_CYAN>,<0-999 RED>,<0-999 GREEN>, <0-999 BLUE>)
	//modifica un colore sulla base di quello inserito

	//initi_pair(<n>, <background_color>, <text_color>);


	initscr();

	if(!has_colors())
	{
		printw("looks like your terminal doesn't support colors");
		mvprintw(1, 1, "too bad, it's going to be a tad more depressing from now on");
		getch();
	}


	start_color();		//inizializza i colori per il terminale

	init_pair(1,COLOR_CYAN, COLOR_RED);


	int height=10, width=50, start_y=10, start_x=10;

	cbreak();

    WINDOW* winMenu = newwin(height, width, start_y, start_x);
    keypad(winMenu, true);

    refresh();

    char l='l';

    box(winMenu, (int)l, 4);


    wrefresh(winMenu);

    int breaker=0;

    int y1, x1;

    getbegyx(winMenu, y1, x1);


    string a="Choose your favourite song";

    x1=(x1-a.size())/2;	//menu text

    y1+=1;		//menu text

    string songsArray[7]= {"RULES OF NATURE", "A STRANGER I REMAIN", "THE STAINS OF TIME", "RED SUN", "THE ONLY THING I KNOW FOR REAL", "COLLECTIVE CONSCIOUSCENSS", "IT HAS TO BE THIS WAY"};

    int choice;

    while(breaker!=10)
    {
    	mvwprintw(winMenu, 1, 1, a.c_str());


    	 y1=1;
    	for(int i=0; i<7; i++)	//prints the menu items, hilights the selected one
    	{
    		if(breaker==i)
    			wattron(winMenu, A_STANDOUT);
    		mvwprintw(winMenu, y1+i+1, 1, songsArray[i].c_str());
    		wattroff(winMenu, A_STANDOUT);
    	}

    	wrefresh(winMenu);
    	noecho();
    	choice = wgetch(winMenu);


    	switch(choice)
    	{
    	case (KEY_UP):
    			if(breaker>0)
    			breaker--;
    			else
    				breaker=6;
		break;

    	case (KEY_DOWN):
    			if(breaker<6)
    				breaker++;
    			else
    				breaker=0;
		break;

    	case (10):
    			breaker=choice;
		break;
    	default:
    		break;
    	}
    }


    getch();

    endwin();

    return 0;
}



/*
Per compilare il file
g++ -I/mingw64/include/ncurses -o <Progetto> <Progetto.cpp> -lncurses -L/mingw64/bin -static

Per lanciarlo
<nomeprogetto>

*/
