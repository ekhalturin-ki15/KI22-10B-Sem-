#include <iostream>
#include <fstream>
#include <memory>
#include <string>
using namespace std;

/*
 * Камень ножницы бумага с прокачкой
 * два игрока
 */

#define DEBUG 1

void print(istream &in, ostream &out) {
#ifdef DEBUG
    string s;
    getline(in, s);
    out << s << "\n";
#endif
}

enum Items : int {
    EIT_rock = 0,
    EIT_paper,
    EIT_scissors,
    EIT_size
};


class Player {
public:
    ifstream input_;
    explicit Player(const string& file_path) {
        input_.open(file_path);
        print(input_, cout);
    }


    Items pTurn_ = 0;

    bool Turn() {
        int iTurn;

        input_ >> iTurn;

        pTurn_ = Items(iTurn);


    }
};

class Game {
public:
    shared_ptr<Player> p1, p2;
    explicit Game(const string& path1="players/player1.txt", const string& path2="players/player2.txt")  {
        p1 = make_shared<Player>(path1);
        p2 = make_shared<Player>(path2);
    }

    bool GameLoop() {
        p1.Turn();
        p2.Turn();
    }
};


int main() {
    Game game;

    game.GameLoop();

    return 0;
}