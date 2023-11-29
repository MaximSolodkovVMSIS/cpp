#include "header.h"
#include "exclusion.h"

Title::Title() {
    name[0] = '\0';
    duration = 0;
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
    if (newName[0] == '\0') {
        throw CharArrayException("Name can not be empty");
    }
    size_t len = strlen(newName) + 1;

    strcpy_s(name, len, newName);
}

void Title::setDuration(int duration) {

    this->duration = duration;
}

Title& Title::operator=(const Title& other) {
    if (this != &other) {
        size_t len = strlen(name) + 1;
        strcpy_s(name, len, other.name);
        duration = other.duration;
    }
    return *this;
}

Movie::Movie() {
    movieDuration = 0;
}

int Movie::getMovieDuration() const {
    return movieDuration;
}

void Movie::setMovieDuration(int movieDuration){
    this->movieDuration = movieDuration;
}

Movie& Movie::operator=(const Movie& other) {
    if (this != &other) {
        Title::operator=(other);
        movieDuration = other.movieDuration;
    }
    return *this;
}

Comic::Comic() {
    numTitle = 0;
    pageInTitle = 0;
}

int Comic::getNumTitle() const {
    return numTitle;
}

int Comic::getPageInTitle() const {
    return pageInTitle;
}

void Comic::setNumTitle(int numTitle){
    this->numTitle = numTitle;
}

void Comic::setGetPageInTitle(int pageInTitle){
    this->pageInTitle = pageInTitle;
}

Comic& Comic::operator=(const Comic& other) {
    if (this != &other) {
        Title::operator=(other);
        numTitle = other.numTitle;
        pageInTitle = other.pageInTitle;
    }
    return *this;
}


Show::Show() {
    numSeries = 0;
}

void Show::setNumSeries(int numSeries){
    this->numSeries = numSeries;
}

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


MultiSeasonShow::MultiSeasonShow() {
    numSeason = 0;
}

void MultiSeasonShow::setNumSeason(int numSeason){
    this->numSeason = numSeason;
}

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


