#include "App.hpp"

#include "Util/Input.hpp"
#include "Util/Keycode.hpp"

void App::Update() {

  // TODO: Add your own logics to finish the tasks in README.md

  /*
   *  Do not touch the code below as they serve the purpose for validating the
   * tasks, rendering the frame, and exiting the game.
   */
  if (m_Giraffe->GetVisibility()) {
    float speed = 4.0;
    if (Util::Input::IsKeyPressed(Util::Keycode::UP)) {
      m_Giraffe->SetPosition(m_Giraffe->GetPosition() + glm::vec2(0.0f, speed));
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::DOWN)) {
      m_Giraffe->SetPosition(m_Giraffe->GetPosition() +
                             glm::vec2(0.0f, -speed));
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::LEFT)) {
      m_Giraffe->SetPosition(m_Giraffe->GetPosition() +
                             glm::vec2(-speed, 0.0f));
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::RIGHT)) {
      m_Giraffe->SetPosition(m_Giraffe->GetPosition() + glm::vec2(speed, 0.0));
    }
  }

  if (m_Giraffe->GetVisibility() == true && m_Chest->GetVisibility() == true) {
    if (m_Giraffe->IfCollides(m_Chest)) {
      m_Chest->SetVisible(false);
    }
  }

  // Phase 4
  m_Bee->SetLooping(true);
  m_Bee->Play();

  if (Util::Input::IsKeyPressed(Util::Keycode::ESCAPE) ||
      Util::Input::IfExit()) {
    m_CurrentState = State::END;
  }

  // Phase 5
  if (m_Doors[0]->GetVisibility() == true) {
    for (auto &door : m_Doors) {
      if (m_Giraffe->IfCollides(door)) {
        door->SetImage(GA_RESOURCE_DIR "/Image/Character/door_open.png");
      }
    }
  }

  // Phase 6
  static bool isFirst = true;
  if (m_Phase == Phase::COUNTDOWN && isFirst) {
    m_Ball->SetVisible(true);
    m_Ball->Play();
    isFirst = false;
  }

  if (m_EnterDown) {
    if (!Util::Input::IsKeyPressed(Util::Keycode::RETURN)) {
      ValidTask();
    }
  }
  m_EnterDown = Util::Input::IsKeyPressed(Util::Keycode::RETURN);

  m_Root.Update();
}
