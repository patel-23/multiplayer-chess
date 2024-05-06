#ifndef _HUMANPLAYER_H_
#define _HUMANPLAYER_H_
#include "player.h"
class HumanPlayer : public Player
{
    PlayerType playerType;

public:
    HumanPlayer(PlayerType playerType);
    ~HumanPlayer();
    PlayerType getPlayerType() override;
};
#endif
