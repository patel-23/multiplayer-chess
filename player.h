#ifndef _PLAYER_H_
#define _PLAYER_H_

enum class PlayerType
{
    Human,
    Computer
};

class Player
{
public:
    virtual ~Player() = default;
    virtual PlayerType getPlayerType() = 0;
};
#endif
