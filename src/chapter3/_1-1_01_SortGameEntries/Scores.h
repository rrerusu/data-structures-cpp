#include "GameEntry.h"
#include <exception>

#pragma once

class IndexOutOfBounds {
    public:
        IndexOutOfBounds(const std::string & err) : errorMsg(err) {}
        std::string getMessage() const { return errorMsg; }
    private:
        std::string errorMsg;
};

class Scores {
    public:
        Scores(int);
        ~Scores();
        void add(const GameEntry &);
        GameEntry remove(int);
        std::string toString();
    private:
        int maxEntries;
        int numEntries;
        GameEntry * entries;
};