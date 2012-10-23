/**
 * File:   Display.h
 * @author: Michal Haták
 *
 * Created on 20. prosinec 2011, 4:16
 */


#ifndef DISPLAY_H
#define	DISPLAY_H

#ifdef __cplusplus__
#include <cstdlib>
#else
#include <stdlib.h>
#endif

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

class Display {
    private:
        stringstream buffer;

    protected:

    public:
        Display();

        void clean();

        /* string stream operations */
        void streamFlush();
        void streamWrite(); /* not implement yet*/

        /* print basics */
        void showHelp();
        void showHead(bool intoFile = false);
        void showMenu();

        /* print specify data */
        void printString(string item, bool intoFile = false);
        void printLeaders(string score);
    };

#endif	/* DISPLAY_H */


