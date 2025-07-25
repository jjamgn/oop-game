#pragma once
#include <SFML/Graphics.hpp>

#define screenWidth 1208
#define screenHeight 720
#define title "TankShoot"

//-------------------- Player --------------------//
#define PlayerSpeed 300.0f
#define PlayerShootCooldown 0.5f
#define PlayerSkillCooldown 60.0f
#define PlayerInvincibleTime 3.0f
constexpr sf::Vector2f PlayerScale(0.5f, 0.5f);
constexpr sf::Vector2f PlayerStartPosition(500.f, 500.f);
#define NormalDamage 1

//-------------------- MineTrap --------------------//
constexpr sf::Vector2f MineTrapScale(0.5f, 0.5f);
#define MineTrapSpeed 200.0f
#define MineTrapHP 1

//-------------------- TankEnemy --------------------//
constexpr sf::Vector2f TankEnemyScale(0.5f, 0.5f);
#define TankEnemySpeed 200.0f
#define TankEnemyHP 5
#define TankEnemyShootCooldown 4.0f

//-------------------- Plane --------------------//
constexpr sf::Vector2f PlaneScale(0.5f, 0.5f);
#define PlaneSpeed 200.0f
#define PlaneHP 3
#define PlaneShootCooldown 2.0f

//-------------------- ArmoredTank --------------------//
constexpr sf::Vector2f ArmoredTankScale(0.75f, 0.75f);
#define ArmoredTankSpeed 150.0f
#define ArmoredTankHP 12 
#define ArmoredTankShootCooldown 4.0f

//-------------------- AirCraft --------------------//
constexpr sf::Vector2f AirCraftScale(3.0f, 3.0f);
#define AirCraftSpeed 150.0f
#define AirCraftHP 12 
#define AirCraftShootCooldown 4.0f
constexpr sf::Vector2f AirCraftStartPosition(screenWidth / 2.0f, screenHeight / 5.0f);
constexpr sf::Vector2f SizeLazerWarningLine(10.0f, 10.0f);
constexpr sf::Color ColorLazerWarningLine(255,0,0,120); 

//-------------------- Bullet --------------------//
#define BulletSpeed 100.0f
#define LazerWarningTime 5.0f



