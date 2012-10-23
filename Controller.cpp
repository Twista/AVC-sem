/**
 * File:   Controller.cpp
 * @author: Michal Haták
 *
 * Created on 29. prosinec 2011, 4:16
 */

#include "Display.h"
#include "Controller.h"
#include <string>
#include "conio.h"
#include  "functions.h"

/**
 * constructor
 */
Controller::Controller(class TScoreboard *scoreboard,class Display *display) {
    this->setModel(scoreboard);
    this->setView(display);
    this->state = RUN;
    this->first = true;
    }

/**
 * set model (collection class)
 */
void Controller::setModel(class TScoreboard *scoreboard) {
    this->model = scoreboard;
    }

/**
 * set viewer (display class)
 */
void Controller::setView(class Display *display) {
    this->view = display;
    }

/**
 * read integer from keyboard
 * @return int
 */
int Controller::readInt() {
    int opt;
    cin >> opt;
    return opt;
    }

/**
 * read integer(0-9), without enter
 * @return int
 */
int Controller::getInt() {
    char chr = getch();
    cout << static_cast<int>(chr)-48;
    return static_cast<int>(chr)-48;
    }

/**
 * read float from keyboard
 * @return float
 */
float Controller::readFloat() {
    float opt;
    cin >> opt;
    return opt;
    }

/**
 * read string from keyboard
 * @return string
 */
string Controller::readString() {
    string opt;
    cin >> opt;
    return opt;
    }

/**
 * wait for key press,optional show key press msg
 */
void Controller::keyPress(bool msg) { // msg = false
    if(msg)
        this->view->printString(KEY_PRESS);
    getch();
    }

/**
 * insert new racer
 */
void Controller::doAdd() {
    this->view->printString(INSERT_NAME);
    this->model->Add(this->readString());
    this->view->printString(RACER_ADDED);
    }

/**
 * get list of racers
 */
void Controller::getList() {
    this->view->printString(RACER_LIST);

    if(this->model->Count() != 0) {
        cout << RACER_COUNT << this->model->Count() << endl;
        this->view->printLeaders(this->model->List(SEPARATOR));
        }
    else {
        this->view->printString(SORRY_EMPTY);

        }
    }

/**
 * add new try(score) of racer
 */
void Controller::doNewTry() {
    this->getList();
    this->view->printString(ZADEJ_ID);
    int id = readInt();
    this->view->printString(ZADEJ_SCORE);
    float skore = this->readFloat();

    this->model->newScore(id,skore);
    }

/**
 * set action by param(option)
 */
void Controller::callAction(int opt) {
    this->view->clean();
    switch(opt) {
        case 0:
            this->setExit();
            break;
        case 1 : // add new racer
            this->doAdd();
            break;
        case 2 :
            this->doNewTry(); // new try
            break;
        case 3 :
            this->getList(); // get List of racers
            break;
        default:
            // handle error
            this->view->printString("spatná volba");

            break;
        }
    this->keyPress();
    this->view->clean();
    }

/**
 * first-run action - show head, help etc.
 */
void Controller::doFirst() {
    this->view->showHead();
    this->view->showHelp();
    this->first = false;
    this->keyPress();
    this->view->clean();

    }

/**
 * main function of controller, read int in while and call actions vie callAction(int) function
 * @return int
 */
int Controller::run() {
    while(this->isRun()) {

        if(this->first) this->doFirst();
        this->getList();

        this->view->showMenu();
        this->callAction(this->getInt());
        }
    return 0;
    }
