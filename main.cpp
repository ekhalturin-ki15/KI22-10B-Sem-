#include <iostream>
#include <fstream>
#include <memory>
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

class Player {
public:
    ifstream input_;
    explicit Player(const string& file_path) {
        input_.open(file_path);
        print(input_, cout);
    }
};

class Game {
public:
    shared_ptr<Player> p1, p2;
    explicit Game(const string& path1="players/player1.txt", const string& path2="players/player2.txt")  {
        p1 = make_shared<Player>(path1);
        p2 = make_shared<Player>(path2);
    }
};


int main() {
    Game game;
    return 0;
}