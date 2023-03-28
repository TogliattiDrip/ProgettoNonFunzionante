
#include <ncurses/ncurses.h>
#include <iostream>
#include "second.hpp"
using namespace std;

int sg(int argc, char ** argv) {

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
    //i caratteri digitati ignorano loadings ed altro
    //utile per digitare cose che interrompono istantaneamente il
    //programma, come CTRL-C se non uso il raw

    attron(COLOR_PAIR(1));
    mvprintw(2,2, "cribbio");
    attroff(COLOR_PAIR(1));

    WINDOW* win = newwin(height, width, start_y, start_x);
    //crea una finestra

    keypad(win, true);

    refresh(); // aggiorna lo schermo
    //in questo caso aggiunge la finestra
    //da questo momento in poi, per aggiornare la finestra dovrebbe
    //bastare l'uso di wrefersh(win );

    char l='l';


    //wborder(win, left, right, top, bottom, tlc, trc, blc, brc);
    //crea sempre una box ma permettendo di scegliere i singoli caratteri per i bordi


    box(win, (int)l, 4);	//crea una semplice "scatola" ai confini della finestra "win"
    //win è la finestra che prende in input, con le sue dimensioni
    //il primo zero è la codifica del carattere usato per le bande laterali
    //il secondo carattere codifica le bande top-bottom
    //se non si sa la codifica del carattere, si può usare un casting


    wrefresh(win);	//aggiorna la finestra corrente
    //aggiorna i dati della finestra
    //necessario ogni volta che si altera la finestra


    //move(x,y);//muove il cursore dove indicato, qui comprariranno nuovi elementi in aggiunta

    int x=1, y=1;

    //i precedenti sono attributi legati al testo
    //per attivare un attributo
    attron(A_INVIS);
    attron(COLOR_PAIR(1));
    //NOTA: non sembra andare internamente alle finestre
    mvwprintw(win, x, y, " RULES OF NATURE ");
    //per disattivare un attributo
    attroff(A_INVIS);
    attroff(COLOR_PAIR(1));


    //printw("text");
    //mvprintw(x, y, "text");
    //mvwprintw(window, window-x, window-y, "text");

    wrefresh(win);

    //cbreak();		//CTRL C chiuderà il programma immediatamente
    noecho();	//il prossimo carattere ad essere digitato non verrà stampato a schermo
    //raw();	//prende ogni carattere digitato come carattere e non come comando (ex CTRL C non chiude il prompt ma ritorna ^C)

    getch();//prende il valore intero del carattere
    //singolo digitato dall'utente.
    //ha anche return del valore

    x++;
    mvwprintw(win, x,y,"And they'll run when the sun comes up");
    wrefresh(win);

    //raw();
    noecho();
    getch();
    x++;
    mvwprintw(win, x,y,"with their lives on the line (ALIVE)");
    wrefresh(win);

    //raw();
    noecho();
    getch();
    x++;
    mvwprintw(win, x,y,"For all the I've (NO CHOICE)");
    wrefresh(win);

    //raw();
    noecho();
    getch();
    x++;
    mvwprintw(win, x,y,"Gotta follow the laws of the wild (ALIVE)");
    wrefresh(win);

    //raw();
    noecho();
    getch();
    x++;
    mvwprintw(win, x,y,"With their lives on the line (NO CHOICE)");
    wrefresh(win);

    //raw();
    noecho();
    getch();
    x++;
    mvwprintw(win, x,y,"Out here only the strong survives");
    wrefresh(win);


    int winy, winx, begy, begx;
    /*
     * getyx(<window>, <var1>, <var2>);
     * ottiene la posizione del cursore e la salva in var1=y, var2=x
     *
     * getbegyx(<window>, var1, var2);
     * stessa cosa del predecessore ma prende la posizione nell'angolo in alto a sinistra
     * della finestra specificata
     *
     * getMaxyx(<window>, var1, var2);
     * simile, restituisce le dimensioni / angolo basso-destro
	*/
    getyx(win, winy, winx);
    getbegyx(win, begy, begx);

    getch();


    endwin();
    return 1;
}



/*
Per compilare il file
g++ -I/mingw64/include/ncurses -o <Progetto> <Progetto.cpp> -lncurses -L/mingw64/bin -static

Per lanciarlo
<nomeprogetto>

*/
