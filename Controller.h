/**
 * File:   Controller.h
 * @author: Michal Haták
 *
 * Created on 29. prosinec 2011, 4:16
 */

#ifndef CONTROLLER_H
#define	CONTROLLER_H

#include "TScoreboard.h"
#include "Display.h"

#include <string>

class Controller {
    private:
        enum state { RUN ,STOP} state;
        bool first;

        TScoreboard* model;
        Display* view;
    protected:

    public:
        Controller(class TScoreboard *scoreboard,class Display *display);
        int run(void);

        int readInt();
        int getInt();
        float readFloat();
        string readString();

        void callAction(int opt);

        void setModel(class TScoreboard *scoreboard);  // set Model
        void setView(class Display *display);       // set Viewer

        bool isRun(void) {
            return this->state == RUN ? true : false;
            }

        void setExit(void) {
            this->state = STOP;
            }

        void doFirst();
        void doAdd();
        void getList();

        void doNewTry();

        //string getLeaders(int count);

        void keyPress(bool msg = true);
    };


#endif	/* CONTROLLER_H */

