#ifndef ENGINE_H
#define ENGINE_H

class Engine {
 public:
  Engine();

  void start();
  void update(float deltaTime);
  void stop();

  bool isRunning() const;

 private:
  bool m_running = false;
};

#endif  // ENGINE_H
