//
//  Stage.h
//  Yuzu
//
//  Created by Haruki Nakano on 2015/07/13.
//
//

#ifndef __Yuzu__Stage__
#define __Yuzu__Stage__

#include "cocos2d.h"
#include "Constants.h"
#include "JSONPacker.h"

class Bullet;
class Player;

class Stage : public cocos2d::Node {
public:
    CREATE_FUNC(Stage);

    void step(float dt);
    void addBullet(Bullet *);

    Player *getPlayer();
    Player *getOpponent();
    void setState(JSONPacker::GameState state);
    void initializePlayersPosition(bool isHost);

private:
    bool init() override;
    void onEnter() override;

    cocos2d::Vec2 convertPositionToTileCoordinate(cocos2d::Vec2 position);
    bool isCorrectTileCoordinate(cocos2d::Vec2 tileCoordinate);

    cocos2d::experimental::TMXTiledMap *_map;
    cocos2d::experimental::TMXLayer *_backgroundLayer;
    cocos2d::Size _size;
    std::vector<Player *> _players;
    std::vector<Bullet *> _bullets;
};

#endif /* defined(__Yuzu__Stage__) */
