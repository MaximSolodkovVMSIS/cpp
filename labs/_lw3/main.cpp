#include "header.h"


int main() {
    char titleName[200];
    int titleDuration;
    int movieDuration;
    int numTitle;
    int pageInTitle;
    int numSeries;
    int numSeason;

    std::cout << "Enter Title Name: ";
    std::cin.getline(titleName, 200);

    std::cout << "Enter Title Duration: ";
    std::cin >> titleDuration;
    std::cin.ignore();

    std::cout << "Enter Movie Duration: ";
    std::cin >> movieDuration;
    std::cin.ignore();

    std::cout << "Enter Number of Titles: ";
    std::cin >> numTitle;
    std::cin.ignore();

    std::cout << "Enter Number of Pages in Title: ";
    std::cin >> pageInTitle;
    std::cin.ignore();

    std::cout << "Enter Number of Series: ";
    std::cin >> numSeries;
    std::cin.ignore();

    std::cout << "Enter Number of Seasons: ";
    std::cin >> numSeason;
    std::cin.ignore();


    Title title(titleName, titleDuration);
    Movie movie(titleName, titleDuration, movieDuration);
    Comic comic(titleName, titleDuration, numTitle, pageInTitle);
    Show show(titleName, titleDuration, movieDuration, numSeries);
    MultiSeasonShow multiSeasonShow(titleName, titleDuration, movieDuration, numSeries, numSeason);

    std::cout << "Title Name: " << title.getName() << std::endl;
    std::cout << "Title Duration: " << title.getDuration() << " minutes" << std::endl;

    std::cout << "Movie Duration: " << movie.getMovieDuration() << " minutes" << std::endl;

    std::cout << "Number of Titles in Comic: " << comic.getNumTitle() << std::endl;
    std::cout << "Number of Pages in Title: " << comic.getPageInTitle() << std::endl;

    std::cout << "Number of Series in Show: " << show.getNumSeries() << std::endl;

    std::cout << "Number of Seasons in Multi-Season Show: " << multiSeasonShow.getNumSeason() << std::endl;

    return 0;
}
