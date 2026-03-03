#include "game.h"

Game::Game(unsigned int width, unsidned int height)
      : state(GAME_ACTIVE), keys(), width(width), height(height), currentLevel(1) {

}

Game::~Game() {
}

void Game::Init() {
}

void Game::ProcessInput(float dt) {
}

void Game::Update(float dt) {
}

void Game::Render() {
}

void Game::restartGame() {
}

void Game::saveCheckpoint() {
}

void Game::updateHUD() {
}