#include "header.h"

Title::Title(const char* name, int duration) : duration(duration) {
    size_t len = strlen(name) + 1;
    strcpy_s(this->name, len, name);
}

Title::Title(const Title& other) : duration(other.duration) {
    size_t len = strlen(name) + 1;
    strcpy_s(this->name, len, other.name);
}

Title::~Title() {
}

char* Title::getName() {
    return name;
}

int Title::getDuration() const {
    return duration;
}

void Title::setName(const char* newName) {
    size_t len = strlen(newName) + 1;
    strcpy_s(name, len, newName);
}

void Title::setDuration(int newDuration) {
    duration = newDuration;
}

Title& Title::operator=(const Title& other) {
    if (this != &other) {
        size_t len = strlen(name) + 1;
        strcpy_s(name, len, other.name);
        duration = other.duration;
    }
    return *this;
}

Movie::Movie(const char* name, int duration, int movieDuration) : Title(name, duration), movieDuration(movieDuration) {}

Movie::Movie(const Movie& other) : Title(other), movieDuration(other.movieDuration) {}

int Movie::getMovieDuration() const {
    return movieDuration;
}

Movie& Movie::operator=(const Movie& other) {
    if (this != &other) {
        Title::operator=(other);
        movieDuration = other.movieDuration;
    }
    return *this;
}

Comic::Comic(const char* name, int duration, int numTitle, int pageInTitle) : Title(name, duration), numTitle(numTitle), pageInTitle(pageInTitle) {}

Comic::Comic(const Comic& other) : Title(other), numTitle(other.numTitle), pageInTitle(other.pageInTitle) {}

int Comic::getNumTitle() const {
    return numTitle;
}

int Comic::getPageInTitle() const {
    return pageInTitle;
}

Comic& Comic::operator=(const Comic& other) {
    if (this != &other) {
        Title::operator=(other);
        numTitle = other.numTitle;
        pageInTitle = other.pageInTitle;
    }
    return *this;
}


Show::Show(const char* name, int duration, int movieDuration, int numSeries) : Movie(name, duration, movieDuration), numSeries(numSeries) {}

Show::Show(const Show& other) : Movie(other), numSeries(other.numSeries) {}

int Show::getNumSeries() const {
    return numSeries;
}

Show& Show::operator=(const Show& other) {
    if (this != &other) {
        Movie::operator=(other);
        numSeries = other.numSeries;
    }
    return *this;
}


MultiSeasonShow::MultiSeasonShow(const char* name, int duration, int movieDuration, int numSeries, int numSeason) : Show(name, duration, movieDuration, numSeries), numSeason(numSeason) {}

MultiSeasonShow::MultiSeasonShow(const MultiSeasonShow& other) : Show(other), numSeason(other.numSeason) {}

int MultiSeasonShow::getNumSeason() const {
    return numSeason;
}

MultiSeasonShow& MultiSeasonShow::operator=(const MultiSeasonShow& other) {
    if (this != &other) {
        Show::operator=(other);
        numSeason = other.numSeason;
    }
    return *this;
}


