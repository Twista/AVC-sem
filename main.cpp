/**
 * File:   main.cpp
 * @author: Michal Haták
 *
 * Created on 28. prosinec 2011, 22:36
 */

/* CS-locales */
#include <clocale>
#include <locale>

/* Standart Libraries */
#include <cstdlib>
#include <iostream>
#include <string>

/* Program class */
#include "functions.h"      // tools
#include "Racer.h"
#include "Display.h"      // viewer
#include "TScoreboard.h"  // model
#include "Controller.h"   // controller


using namespace std;

int main() {
    /* set console locale to cs*/
    setlocale(LC_ALL, "");

    return Controller(new TScoreboard(),new Display()).run();;

    }
