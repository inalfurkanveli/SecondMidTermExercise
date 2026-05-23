//
// Created by FURKAN on 23.05.2026.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Song {
private:
    string name;
    int playCount;

public:
    Song(string name = "", int playCount = 1) {
        this->name = name;
        this->playCount = playCount;
    }

    Song &operator++() {
        playCount++;
        return *this;
    }

    Song &operator--() {
        if (playCount > 0) {
            playCount--;
        }
        return *this;
    }

    bool operator==(const Song &other) const {
        return this->name == other.name;
    }

    string getName() const {
        return name;
    }

    int getPlayCount() const { return playCount; }
};

istream &operator>>(istream &in, Song &s) {
    string name;
    int playCount;
    in >> name >> playCount;
    s = Song(name, playCount);
    return in;
}

ostream &operator<<(ostream &out,const Song &s) {
    //Name: [name], Times Played: [playCount]
    out << "Name: " << s.getName() << ", Times played: " << s.getPlayCount() << endl;
    return out;
}

class Playlist {
private:
    string playlistName;
    vector<Song> song;

    bool hasWithName(const Song &s) const {
        for (size_t i = 0; i < song.size(); i++) {
            if (song[i] == s) {
                return true;
            }
        }
        return false;
    }

public:
    Playlist(string playlistName = "") {
        this->playlistName = playlistName;
    }

    Playlist &operator+=(const Song &s) {
        if (!hasWithName(s)) {
            song.push_back(s);
        }
        return *this;
    }

    Playlist &operator-=(const Song &s) {
        song.erase(remove(song.begin(), song.end(), s)
                   , song.end()
        );
        song.shrink_to_fit();
        return *this;
    }

    Playlist &operator++() {
        for (size_t i = 0; i < song.size(); i++) {
            ++song[i];
        }
        return *this;
    }

    Playlist &operator--() {
        for (size_t i = 0; i < song.size(); i++) {
            --song[i];
        }
        return *this;
    }

    string getPlaylistName() const {
        return playlistName;
    }

    void setPlaylistName(string playlistName) {
        this->playlistName = playlistName;
    }

    const vector<Song> &getSong() const {
        return song;
    }

    string getPlaylist() const { return playlistName; }
};

istream &operator>>(istream &in, Playlist &play) {
    string playlistName;
    in >> playlistName;
    play.setPlaylistName(playlistName);
    return in;
}

ostream &operator<<(ostream &out, const Playlist &play) {
    out << play.getPlaylist() << endl;
    const vector<Song> &song = play.getSong();
    for (size_t i = 0; i < song.size(); i++) {
        out << song[i] << endl;
    }
    return out;
}

//DO NOT CHANGE MAIN FUNCTION

int main() {
    int testCase;
    cin >> testCase;

    string name;
    int playCount;
    string playlistName;

    switch (testCase) {
        case 1: {
            cout << "TESTING CONSTRUCTORS" << endl;
            Song s1;
            Playlist p1;
            cin >> name >> playCount;
            cin >> playlistName;
            Song s2(name, playCount);
            Playlist p2(playlistName);
            cout << "TEST PASSED" << endl;
            break;
        }
        case 2: {
            cout << "TESTING SONG OPERATOR >>" << endl;
            Song s;
            cin >> s;
            cout << "TEST PASSED" << endl;
            break;
        }
        case 3: {
            cout << "TESTING SONG OPERATOR <<" << endl;
            cin >> name >> playCount;
            Song s(name, playCount);
            cout << s;
            cout << "TEST PASSED" << endl;
            break;
        }
        case 4: {
            cout << "TESTING SONG OPERATORS >> AND << " << endl;
            Song s;
            cin >> s;
            cout << s;
            cout << "TEST PASSED" << endl;
            break;
        }
        case 5: {
            cout << "TESTING SONG OPERATOR ++" << endl;
            cin >> name >> playCount;
            Song s(name, playCount);
            ++s;
            cout << s;
            cout << "TEST PASSED" << endl;
            break;
        }
        case 6: {
            cout << "TESTING SONG OPERATOR --" << endl;
            cin >> name >> playCount;
            Song s(name, playCount);
            --s;
            cout << s;
            cout << "TEST PASSED" << endl;
            break;
        }
        case 7: {
            cout << "TESTING PLAYLIST OPERATOR << " << endl;
            cin >> playlistName;
            Playlist p(playlistName);
            cout << p;
            cout << "TEST PASSED" << endl;
            break;
        }
        case 8: {
            cout << "TESTING PLAYLIST OPERATOR +=" << endl;
            cin >> playlistName;
            int n;
            cin >> n;
            Playlist p(playlistName);
            for (int i = 0; i < n; i++) {
                cin >> name >> playCount;
                p += Song(name, playCount);
            }
            cout << p;
            cout << "TEST PASSED" << endl;
            break;
        }
        case 9: {
            cout << "TESTING PLAYLIST OPERATOR -=" << endl;
            cin >> playlistName;
            int n;
            cin >> n;
            Playlist p(playlistName);
            for (int i = 0; i < n; i++) {
                cin >> name >> playCount;
                p += Song(name, playCount);
            }

            cin >> name >> playCount;
            p -= Song(name, playCount);
            cout << p;
            cout << "TEST PASSED" << endl;
            break;
        }
    }
}
