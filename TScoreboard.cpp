/**
 * File:   TScoreboard.cpp
 * @author: Michal Haták
 *
 * Created on 29. prosinec 2011, 4:07
 */

#include "TScoreboard.h"
#include "Racer.h"

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

/**
 * constructor
 */
TScoreboard::TScoreboard() {
    };

/**
 * add new racer into collection
 * @return int
 */
int TScoreboard::Add(string name) {
    Racer item(name);
    m_items.push_back(item);
    return (m_items.size()-1);
    }

/**
 * get pointer on racer
 * @return *Racer
 */
Racer* TScoreboard::getItem(int ItemKey) {
    return &(m_items[ItemKey]);
    }

/**
 * clear collection - delete all racers
 */
void TScoreboard::Clear(void) {
    m_items.clear();
    }

/**
 * get count of racers
 * @return int
 */
int TScoreboard::Count(void) {
    return m_items.size();
    }

/**
 * get racer / enable acces to racer via []
 * @return Racer
 */
Racer& TScoreboard::operator [](int ItemKey) {
    return m_items[ItemKey];
    }

/**
 * swap 2 racer in collection
 */
void TScoreboard::Swap(int a, int b) {
    Racer tmp("tst");
    tmp = m_items[a];
    m_items[a] = m_items[b];
    m_items[b] = tmp;
    }

/**
 * compare score of 2 racers
 * @return bool
 */
bool TScoreboard::Cmp(int a, int b) {
    if(this->getItem(a)->getScore() > this->getItem(b)->getScore())
        return true;
    else
        return false;
    }

/**
 * quicksort algoritm
 */
void TScoreboard::quicksort(int left, int right) {
    if(left < right) {
        int boundary = left;
        for(int i = left + 1; i < right; i++) {
            if(this->Cmp(i,left)) {
                this->Swap( i, ++boundary);
                }
            }
        this->Swap( left, boundary);
        this->quicksort( left, boundary);
        this->quicksort( boundary + 1, right);
        }
    }

/**
 * sort collection
 * @return bool
 */
bool TScoreboard::Sort(void) {
    if(this->Count() <= 1)
        return false;

    this->quicksort(0,this->Count());
    /*    Bubble sort
    for(int i = 0; i < (this->Count()-1); i++) {
        for(int j = 0; j < (this->Count()-i-1); j++)

            if(!this->Cmp(j,j+1))
                this->Swap(j,j+1);

           // cout << "\ni " << i << " a j " << j;
        }
    */
    return true;

    }

/**
 * get list of racers in collection
 * @return string
 */
string TScoreboard::List(string delimiter) {
    stringstream buf;
    this->Sort();
    for(int i = 0; i < (this->Count()); i++) {
        buf << i << delimiter << this->getItem(i)->getName() << delimiter << this->getItem(i)->getScore() << delimiter << this->getItem(i)->getAvgScore() << delimiter << this->getItem(i)->getCount() << endl;

        }
    return buf.str();
    }

/**
 * set new score to the racer in collection
 * @return bool
 */
bool TScoreboard::newScore(int id, float skore) {
    if(id > this->Count() || id < 0)
        return false;

    this->getItem(id)->newScore(skore);
    return true;
    }







