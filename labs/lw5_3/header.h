#include <iostream>
#include <string>
#include <cstring>

class Title {
public:
    Title();
    ~Title();
    char* getName();
    int getDuration() const;
    void setName(const char* newName);
    void setDuration(int newDuration);
    Title& operator=(const Title& other);

private:
    char name[256];
    int duration;
};

class Movie : public Title {
public:
    Movie();
    int getMovieDuration() const;
    void setMovieDuration(int movieDuration);
    Movie& operator=(const Movie& other);

private:
    int movieDuration;
};

class Comic : public Title {
public:
    Comic();
    int getNumTitle() const;
    int getPageInTitle() const;
    void setNumTitle(int numTitle);
    void setGetPageInTitle(int pageInTitle);
    Comic& operator=(const Comic& other);

private:
    int numTitle;
    int pageInTitle;
};

class Show : public Movie {
public:
    Show();
    void setNumSeries(int numSeries);
    int getNumSeries() const;
    Show& operator=(const Show& other);

private:
    int numSeries;
};

class MultiSeasonShow : public Show {
public:
    MultiSeasonShow();
    void setNumSeason(int numSeason);
    int getNumSeason() const;
    MultiSeasonShow& operator=(const MultiSeasonShow& other);

private:
    int numSeason;
};
