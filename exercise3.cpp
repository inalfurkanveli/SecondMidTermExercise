#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Movie {
private:
    string title;
    int watchCount;

public:
    Movie() {
        title = "";
        watchCount = 1;
    }

    Movie(string title, int watchCount) {
        this->title = title;
        this->watchCount = watchCount;
    }

    Movie &operator++() {
        watchCount++;
        return *this;
    }

    Movie &operator--() {
        if (watchCount > 0) {
            watchCount--;
        }
        return *this;
    }

    string getTitle() const {
        return title;
    }

    bool operator==(const Movie &other) const {
        return this->title == other.title;
    }

    int getWatchCount() const {
        return watchCount;
    }
};

ostream &operator<<(ostream &out, const Movie &movie) {
    //Title: [title], Times Watched: [watchCount]
    return out << "Title: " << movie.getTitle() << ", Times Watched: " << movie.getWatchCount()<<endl;
}

istream &operator>>(istream &in, Movie &movie) {
    string title;
    int watchCount;
    in >> title >> watchCount;
    movie = Movie(title, watchCount);
    return in;
}

class MovieCollection {
private:
    string collectionName;
    vector<Movie> movies;

    bool hasMovieWithTitle(const Movie &m) const {
        for (size_t i = 0; i < movies.size(); i++) {
            if (movies[i] == m) {
                return true;
            }
        }
        return false;
    }

public:
    MovieCollection(string collectionName = "") {
        this->collectionName = collectionName;
    }

    string getCollectionName() const {
        return collectionName;
    }

    MovieCollection &operator+=(const Movie &m) {
        if (!hasMovieWithTitle(m)) {
            movies.push_back(m);
        }
        return *this;
    }

    MovieCollection &operator-=(const Movie &m) {
        movies.erase(remove(movies.begin(), movies.end(), m),
                     movies.end()
        );
        movies.shrink_to_fit();
        return *this;
    }
    MovieCollection &operator++() {
        for (size_t i=0; i<movies.size(); i++) {
            ++movies[i];
        }
        return *this;
    }
    MovieCollection &operator--() {
        for (size_t i = 0; i < movies.size(); i++) {
            --movies[i];
        }
        return *this;
    }
    void setCollectionName(string collectionName) {
        this->collectionName = collectionName;
    }

    const vector<Movie> &getMovies() const {
        return movies;
    }
};
    ostream &operator<<(ostream &out,const MovieCollection &m){
    out<< m.getCollectionName() << endl;
    const vector<Movie> &movies=m.getMovies();
    for (size_t i=0; i<movies.size();i++) {
        out<< movies[i]<<endl;
    }
    out<<endl;
    return out;
}
    istream &operator>>(istream &in ,MovieCollection &m) {
        string collectionName;
        in>>collectionName;
        m.setCollectionName(collectionName);
        return in;
    }

//DO NOT CHANGE MAIN FUNCTION

int main() {
    int testCase;
    cin >> testCase;

    string title;
    int watchCount;
    string collectionName;

    switch (testCase) {
        case 1: {
            cout << "TESTING CONSTRUCTORS" << endl;
            Movie m1;
            MovieCollection c1;
            cin >> title >> watchCount;
            cin >> collectionName;
            Movie m2(title, watchCount);
            MovieCollection c2(collectionName);
            cout << "TEST PASSED" << endl;
            break;
        }
        case 2: {
            cout << "TESTING MOVIE OPERATOR >>" << endl;
            Movie m;
            cin >> m;
            cout << "TEST PASSED" << endl;
            break;
        }
        case 3: {
            cout << "TESTING MOVIE OPERATOR <<" << endl;
            cin >> title >> watchCount;
            Movie m(title, watchCount);
            cout << m;
            cout << "TEST PASSED" << endl;
            break;
        }
        case 4: {
            cout << "TESTING MOVIE OPERATORS >> AND << " << endl;
            Movie m;
            cin >> m;
            cout << m;
            cout << "TEST PASSED" << endl;
            break;
        }
        case 5: {
            cout << "TESTING MOVIE OPERATOR ++" << endl;
            cin >> title >> watchCount;
            Movie m(title, watchCount);
            ++m;
            cout << m;
            cout << "TEST PASSED" << endl;
            break;
        }
        case 6: {
            cout << "TESTING MOVIE OPERATOR --" << endl;
            cin >> title >> watchCount;
            Movie m(title, watchCount);
            --m;
            cout << m;
            cout << "TEST PASSED" << endl;
            break;
        }
        case 7: {
            cout << "TESTING MOVIE COLLECTION OPERATOR << " << endl;
            cin >> collectionName;
            MovieCollection c(collectionName);
            cout << c;
            cout << "TEST PASSED" << endl;
            break;
        }
        case 8: {
            cout << "TESTING MOVIE COLLECTION OPERATOR +=" << endl;
            cin >> collectionName;
            int n;
            cin >> n;
            MovieCollection c(collectionName);
            for (int i = 0; i < n; i++) {
                cin >> title >> watchCount;
                c += Movie(title, watchCount);
            }
            cout << c;
            cout << "TEST PASSED" << endl;
            break;
        }
        case 9: {
            cout << "TESTING MOVIE COLLECTION OPERATOR -=" << endl;
            cin >> collectionName;
            int n;
            cin >> n;
            MovieCollection c(collectionName);
            for (int i = 0; i < n; i++) {
                cin >> title >> watchCount;
                c += Movie(title, watchCount);
            }

            cin >> title >> watchCount;
            c -= Movie(title, watchCount);
            cout << c;
            cout << "TEST PASSED" << endl;
            break;
        }
    }
}
