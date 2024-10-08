#include <iostream>
#include <string>

// Target interface (MediaPlayer)
class MediaPlayer {
public:
    virtual void play(const std::string& fileName) = 0; // Pure virtual function
    virtual ~MediaPlayer() {}
};

// Adaptee class (third-party MP4 player)
class MP4Player {
public:
    void playMP4(const std::string& fileName) const {
        std::cout << "Playing MP4 file: " << fileName << "\n";
    }
};

// Adapter class (adapts MP4Player to MediaPlayer interface)
class MP4Adapter : public MediaPlayer {
private:
    const MP4Player& mp4Player; // The Adaptee (MP4 player)
public:
    MP4Adapter(const MP4Player& player) : mp4Player(player) {}

    // Implements the Target interface and adapts the call to the Adaptee
    void play(const std::string& fileName) override {
        mp4Player.playMP4(fileName); // Call the Adaptee's method
    }
};

// Client code (expects a MediaPlayer interface)
void playMedia(MediaPlayer& player, const std::string& fileName) {
    player.play(fileName); // Use the Target interface
}

int main() {
    MP4Player mp4Player; // Adaptee (incompatible MP4 player)
    MP4Adapter adapter(mp4Player); // Adapter for MP4 player

    // Client can play MP4 files using the adapter
    playMedia(adapter, "example.mp4");

    return 0;
}

/*
    Playing MP4 file: example.mp4
*/
