#include "engine.h"

Engine::Engine() = default;

void Engine::start() { m_running = true; }

void Engine::update(float deltaTime) {
  if (!m_running) {
    return;
  }
}

void Engine::stop() { m_running = false; }

bool Engine::isRunning() const { return m_running; }
