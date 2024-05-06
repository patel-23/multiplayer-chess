#ifndef __GAME_H__
#define __GAME_H__
#include <vector>
#include <memory>
#include "board.h"
#include "humanPlayer.h"
#include "computerPlayer.h"
#include "piece.h"
// #include "move.h"
class Game
{
    std::unique_ptr<Board> board;
    size_t playerToMove;
    std::vector<std::unique_ptr<Player>> players;
    // std::vector<std::unique_ptr<Piece>> capturedPieces;
    float blackScore;
    float whiteScore;
    // std::vector<Move> moves;

public:
    Game();
    ~Game();
    void init();
    void setUpBoard();
    void setPlayerWhite(std::string player);
    void setPlayerBlack(std::string player);
    bool nextMove(bool isResigned);
    float getBlackScore() const;
    float getWhiteScore() const;
    bool isSetupValid();
};
#endif
