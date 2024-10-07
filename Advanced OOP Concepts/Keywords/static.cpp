#include <iostream>

class Player {
private:
    static int playerCount;  // Static member variable

public:
    Player() {
        ++playerCount;  // Increment player count when a new object is created
    }

    static void showPlayerCount() {  // Static member function
        std::cout << "Total players: " << playerCount << std::endl;
    }
};

// Define and initialize static member
int Player::playerCount = 0;

int main() {
    Player p1;  // Player count = 1
    Player p2;  // Player count = 2

    Player::showPlayerCount();  // Output: Total players: 2
    return 0;
}

/*
    Total players: 2
*/