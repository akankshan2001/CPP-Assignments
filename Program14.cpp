//INHERITANCE AND CONTAINERS
/*
Description
Problem Statement:
Design a Song interface having Play function, and Duration function. 
Duration function returns duration of song in seconds. 
Design classes Jazz classes which implement Song interface. 
Design Playlist class, which maintain a list of songs. 
Write a program to create a playlist for user. 
Accept name of playlist, few song details from user. For each song, accept name, duration from user. 
At the end play the whole playlist with all details of the song and duration in mm: ss format.
 (To play a song, you may choose to make beep sound, or simply display the song details on screen).
Use appropriate containers like vectors, multimaps or sets.

Note: please go for late and early binding and Virtual destructor.

*/

#include <iostream>
#include <vector>
#include <string>

/*
This is an abstract base class Song which is an interface. 
It defines two pure virtual functions Play() and Duration(). 
It also has a virtual destructor to allow proper cleanup when objects are destroyed.
*/

class Song {
public:
    virtual void Play() const = 0;  //pure virtual function
    virtual int Duration() const = 0;  //pure virtual function
    virtual ~Song() {}  //virtual destructor
};

/*
These classes (Jazz, Rock, and Ghazal) are derived from the Song base class. 
Each of these classes implements the Play() and Duration() functions according to their specific requirements.
*/

class Jazz : public Song {
private:
    std::string name;
    int duration;

public:
    Jazz(const std::string& n, int d) : name(n), duration(d) {}

    void Play() const override {
        std::cout << "Playing Jazz song: " << name << std::endl;
    }

    int Duration() const override {
        return duration;
    }
};

class Rock : public Song {
private:
    std::string name;
    int duration;

public:
    Rock(const std::string& n, int d) : name(n), duration(d) {}

    void Play() const override {
        std::cout << "Playing Rock song: " << name << std::endl;
    }

    int Duration() const override {
        return duration;
    }
};

class Ghazal : public Song {
private:
    std::string name;
    int duration;

public:
    Ghazal(const std::string& n, int d) : name(n), duration(d) {}

    void Play() const override {
        std::cout << "Playing Ghazal song: " << name << std::endl;
    }

    int Duration() const override {
        return duration;
    }
};


/*
The Playlist class maintains a list of Song objects (using a std::vector<Song*>). 
It has methods to add a song to the playlist and play all the songs in the playlist. 
The destructor is responsible for freeing the dynamically allocated Song objects.

*/

class Playlist {
private:
    std::string playlistName;
    std::vector<const Song*> songs;

public:
    Playlist(const std::string& name) : playlistName(name) {}

    void AddSong(const Song* song) {
        songs.push_back(song);
    }

    const std::vector<const Song*>& GetSongs() const {
        return songs;
    }

    void PlayAll() const {
        std::cout << "Playing playlist: " << playlistName << std::endl;

        int totalDuration = 0;
        for (const Song* song : songs) {
            song->Play();
            totalDuration += song->Duration();
        }

        int minutes = totalDuration / 60;
        int seconds = totalDuration % 60;

        std::cout << "Total duration: " << minutes << "m : " << seconds << "s" << std::endl;
    }

    ~Playlist() {
        for (const Song* song : songs) {
            delete song;
        }
    }
};

int main() {
    std::string playlistName;
    int numSongs;

    // Get playlist name and number of songs from user
    std::cout << "Enter playlist name: ";
    std::cin >> playlistName;

    std::cout << "Enter number of songs: ";
    std::cin >> numSongs;

    Playlist myPlaylist(playlistName);

    for (int i = 0; i < numSongs; ++i) {
        std::string songName;
        int songDuration;

        // Get song details from user
        std::cout << "Enter name of song " << i + 1 << ": ";
        std::cin.ignore(); // Clear the newline character from previous input
        std::getline(std::cin, songName);

        std::cout << "Enter duration of song " << i + 1 << " (in seconds): ";
        std::cin >> songDuration;

        // Create and add the song to the playlist
        Song* newSong = new Jazz(songName, songDuration);
        myPlaylist.AddSong(newSong);
    }

    // Play the playlist
    myPlaylist.PlayAll();

    return 0;
}
