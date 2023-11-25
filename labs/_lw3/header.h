#include <iostream>
#include <string>
#include <cstring>



class Title {
public:
    Title(const char* name, int duration);
    Title(const Title& other);
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
    Movie(const char* name, int duration, int movieDuration);
    Movie(const Movie& other);
    int getMovieDuration() const;
    Movie& operator=(const Movie& other);

private:
    int movieDuration;
};

class Comic : public Title {
public:
    Comic(const char* name, int duration, int numTitle, int pageInTitle);
    Comic(const Comic& other);
    int getNumTitle() const;
    int getPageInTitle() const;
    Comic& operator=(const Comic& other);

private:
    int numTitle;
    int pageInTitle;
};

class Show : public Movie {
public:
    Show(const char* name, int duration, int movieDuration, int numSeries);
    Show(const Show& other);
    int getNumSeries() const;
    Show& operator=(const Show& other);

private:
    int numSeries;
};

class MultiSeasonShow : public Show {
public:
    MultiSeasonShow(const char* name, int duration, int movieDuration, int numSeries, int numSeason);
    MultiSeasonShow(const MultiSeasonShow& other);
    int getNumSeason() const;
    MultiSeasonShow& operator=(const MultiSeasonShow& other);

private:
    int numSeason;
};
