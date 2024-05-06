#ifndef _COMPUTERPLAYER_H_
#define _COMPUTERPLAYER_H_
#include "player.h"
#include "board.h"
#include <iostream>

class ComputerPlayer : public Player
{
    PlayerType playerType;
    int level;
    std::string getMove(int playerToMove, Board &b);

public:
    ComputerPlayer(PlayerType playerType, int level);
    ~ComputerPlayer();
    PlayerType getPlayerType() override;
    std::string nextMove(int playerToMove, Board &b);
};
#endif
