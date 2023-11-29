#include "header.h"
#include "exclusion.h"


//шаблонная функция для обработки сключений
template <typename T, typename ExceptionType>
T getInput(const std::string& prompt, const std::string& errorMessage) {
    T value;
    std::cout << prompt;
    std::cin >> value;
    if (std::cin.fail()) {
        throw ExceptionType(errorMessage.c_str());
    }
    std::cin.ignore();
    return value;
}
/*код без этой функции выглядел бы так
    try {
        std::cout << "Enter Title Duration: ";
        std::cin >> titleDuration;
        if (std::cin.fail()) {
            throw IntException("Invalid input for Title Duration.");
        }
        std::cin.ignore();
        title.setDuration(titleDuration);
    } catch (IntException& e) {
        e.show();

        пришлось бы так расписывать каждую переменную
*/
int main() {
    char titleName[200];
    int titleDuration;
    int movieDuration;
    int numTitle;
    int pageInTitle;
    int numSeries;
    int numSeason;

    Title title;
    Movie movie;
    Comic comic;
    Show show;
    MultiSeasonShow multiSeasonShow;


    std::cout << "Enter Title Name: ";
    std::cin.getline(titleName, 200);

    try {
        title.setName(titleName);
    }
    catch (CharArrayException& e) {
        e.show();
        return 0;
    }
    
    try {
        titleDuration = getInput<int, IntException>("Enter Title Duration: ", "Invalid input for Title Duration.");
        title.setDuration(titleDuration);

        movieDuration = getInput<int, IntException>("Enter Movie Duration: ", "Invalid input for Movie Duration.");
        movie.setMovieDuration(movieDuration);

        numTitle = getInput<int, IntException>("Enter Number of Titles: ", "Invalid input for Number of Titles.");
        comic.setNumTitle(numTitle);

        pageInTitle = getInput<int, IntException>("Enter Number of Pages in Title: ", "Invalid input for Number of Pages in Title.");
        comic.setGetPageInTitle(pageInTitle);

        numSeries = getInput<int, IntException>("Enter Number of Series: ", "Invalid input for Number of Series.");
        show.setNumSeries(numSeries);

        numSeason = getInput<int, IntException>("Enter Number of Seasons: ", "Invalid input for Number of Seasons.");
        multiSeasonShow.setNumSeason(numSeason);
    }
    catch (IntException& e) {
        e.show();
        return 0;
    }

 
    /*
    title.setDuration(titleDuration);
    movie.setDuration(movieDuration);
    comic.setNumTitle(numTitle);
    comic.setGetPageInTitle(pageInTitle);
    show.setNumSeries(numSeries);
    multiSeasonShow.setNumSeason(numSeason);
    */

    std::cout << "Title Name: " << title.getName() << std::endl;
    std::cout << "Title Duration: " << title.getDuration() << " minutes" << std::endl;

    std::cout << "Movie Duration: " << movie.getMovieDuration() << " minutes" << std::endl;

    std::cout << "Number of Titles in Comic: " << comic.getNumTitle() << std::endl;
    std::cout << "Number of Pages in Title: " << comic.getPageInTitle() << std::endl;

    std::cout << "Number of Series in Show: " << show.getNumSeries() << std::endl;

    std::cout << "Number of Seasons in Multi-Season Show: " << multiSeasonShow.getNumSeason() << std::endl;

    return 0;
}
