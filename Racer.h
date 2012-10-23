/**
 * File:   Racer.h
 * @author: Michal Haták
 *
 * Created on 29. prosinec 2011, 4:07
 */

#ifndef RACER_H
#define	RACER_H

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Racer {
    private:
        string name;
        vector<float> score;

    public:
        /**
          * constructor
          */
        Racer(string n) {
            this->name = n;
            }

        /**
         * set races name
         */
        void setName(string n) {
            this->name = n;
            }

        /**
         * get count of scores
         * @return int
         */
        int getCount(void) {
            return this->score.size();
            }

        /**
         * get name of racer
         * @return string
         */
        string getName(void) {
            return this->name;
            }

        /**
         * insert new score
         */
        void newScore(float value) {
            this->score.push_back(value);
            }

        /**
         * get total score
         * @return float
         */
        float getScore() {
            if(this->score.empty())
                return 0;

            float temp = 0;
            for(int i = 0; i < static_cast<signed int>(this->score.size()); i++) {
                temp += score[i];
                }
            return temp;
            }

        /**
         * get total average score
         * @return float
         */
        float getAvgScore() {
            if(this->getScoreCount() == 0)
                return 0;
            return this->getScore()/this->getScoreCount();
            }

        /**
         * get score count
         * @return int
         */
        int getScoreCount() {
            return this->score.size();
            }

    };

#endif	/* RACER_H */
