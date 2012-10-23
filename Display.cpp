/**
 * File:   Display.cpp
 * @author: Michal Haták
 *
 * Created on 20. prosinec 2011, 4:29
 */

#include "Display.h"
#include <string>
//#include<stdio.h>

/**
 * contructor
 */
Display::Display() {
    }

/**
 * clean console display (doesn't works on linux-based OS)
 */
void Display::clean() {
    if (system("CLS")) system("clear");
    }

/**
 * write stream into file
 */
void Display::streamWrite() {
    /**
     * @not implement yet
     * open file for write
     * write stream(buffer) int file
     * close file
     * clean buffer
     */
    }

/**
 * get count of racers
 */
void Display::printString(string item,bool intoFile) { // intoFile = false
    this->buffer << item << endl;

    if(intoFile) {
        this->streamWrite();
        }
    else {
        this->streamFlush();
        }
    }

/**
 * write stram(buffer) on std:out and clean buffer
 */
void Display::streamFlush() {
    cout << buffer.str();
    buffer.str("");
    }

/**
 * write Help on std:out
 */
void Display::showHelp() {
    cout << "Napoveda: " << endl
    << "Program pro zpracovani vysledku zavodu " << endl
    << "Ovladani pomoci klavesnice" <<endl;
    }

/**
 * show program head via buffer
 */
void Display::showHead(bool intoFile) {  // intoFile = false
    this->buffer
    << "------------------------------------------" << endl
    << "  {_}" << endl
    << " *-=\\           Michal Hatak, hatak@inizio.cz" << endl
    << "     \\____(     AVC - Semestralni prace" << endl
    << "    _|/---\\_" << endl
    << "    \\       \\   Vysledkova listina zavodníku" << endl
    << "" << endl
    << "------------------------------------------" << endl;

    if(intoFile) {
        this->streamWrite();
        }
    else {
        this->streamFlush();
        }

    }

/**
 * show program menu
 */
void Display::showMenu() {
    cout << endl << endl << "Menu" << endl
         << "> 1 <| Pridani zavodnika" << endl
         << "> 2 <| Pridani pokusu" << endl
         << "> 3 <| Vypis zavodniku" << endl
         << "> 0 <| Konec programu" << endl
         << " - - -" << endl;
    }

/**
 * show racers
 */
void Display::printLeaders(string score) {
    cout << "ID   " << "  Jmeno " << "  Skore  " << "   Prum. Skore  " << "  pokusu" << endl;
    cout << score << endl;
    }

