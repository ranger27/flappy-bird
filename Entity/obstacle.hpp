#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP

#include <SFML/Graphics.hpp>
#include "../randomLib/random.hpp"

using Random = effolkronium::random_static;

class Obstacle : public sf::Drawable
{
public:
    typedef std::vector<std::vector<sf::Sprite>> ObstacleType;

    Obstacle(const sf::Vector2u &windowSize);
    ~Obstacle();
    // updates position of obstacle &
    // makes new obstacle &
    // deletes obstacles out of screen
    void updateObs(float dt, float baseHeight);

    ObstacleType getObstacles() const;

private:
    void createNewObstacle(float baseHeight);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const;

private:
    // struct Pipe{
    //     sf::Sprite s;

    // };

    // data storage part
    // ninv = non-inverted, inv = inverted
    enum PipeType
    {
        NINV,
        INV
    };
    std::map<Obstacle::PipeType, sf::Texture> mObsTextureMap = {
        {Obstacle::NINV, sf::Texture()},
        {Obstacle::INV, sf::Texture()}};

    // collection of all the obstacles shown in screen
    ObstacleType mObstacles;

    // logic part
    bool mIsThisInitialTime = true;
    const float mInitialWaitingTime = 3.0f; // 3 seconds
    float mGenDuration = 3.6f;              // 2 seconds initially, this will   change
    float mSpeed = 100.0f;                   // i.e 70px/seconds of velocity/speed.
    float mCurrDuration = 0.0f;

    // other essential data
    const sf::Vector2u &mWindowSize;
    float baseHeight;
};

#endif
