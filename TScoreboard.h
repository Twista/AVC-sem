/**
 * File:   TScoreboard.h
 * @author: Michal Haták
 *
 * Created on 29. prosinec 2011, 4:07
 */


#ifndef DISPLAY_H
#define	DISPLAY_H

#include "Display.h"

#endif

#include "Racer.h"

#ifndef TSCOREBOARD_H
#define	TSCOREBOARD_H

#include <vector>

using namespace std;

class TScoreboard {   // model
    private:

    protected:
        vector<Racer> m_items;

    public:
        TScoreboard(void);

        int Add(string name);

        Racer* getItem(int ItemKey);

        void Clear(void);

        int Count(void);

        void Swap(int a, int b);

        bool Cmp(int a, int b);

        bool Sort(void);
        void quicksort(int left, int right);

        bool newScore(int id, float score);

        Racer& operator [](int ItemKey);

        string List(string delimiter);
    };

#endif	/* TSCOREBOARD_H */

