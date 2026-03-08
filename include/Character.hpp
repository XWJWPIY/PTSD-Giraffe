#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>

#include "Util/GameObject.hpp"

class Character : public Util::GameObject {
public:
    explicit Character(const std::string& ImagePath);

    Character(const Character&) = delete;

    Character(Character&&) = delete;

    Character& operator=(const Character&) = delete;

    Character& operator=(Character&&) = delete;

    [[nodiscard]] const std::string& GetImagePath() const { return m_ImagePath; }

    [[nodiscard]] const glm::vec2& GetPosition() const { return m_Transform.translation; }

    [[nodiscard]] bool GetVisibility() const { return m_Visible; }

    void SetImage(const std::string& ImagePath);

    void SetPosition(const glm::vec2& Position) { m_Transform.translation = Position; }

    // TODO: Implement the collision detection
    [[nodiscard]] bool IfCollides(const std::shared_ptr<Character>& other) const {
        glm::vec2 pos1 = this->GetPosition();
        glm::vec2 size1 = this->GetScaledSize();
        glm::vec2 pos2 = other->GetPosition();
        glm::vec2 size2 = other->GetScaledSize();

        // 計算自身的上下左右邊界 (假設 Y 軸正向朝上)
        float left1 = pos1.x - (size1.x / 2.0f);
        float right1 = pos1.x + (size1.x / 2.0f);
        float top1 = pos1.y + (size1.y / 2.0f);
        float bottom1 = pos1.y - (size1.y / 2.0f);

        // 計算目標的上下左右邊界
        float left2 = pos2.x - (size2.x / 2.0f);
        float right2 = pos2.x + (size2.x / 2.0f);
        float top2 = pos2.y + (size2.y / 2.0f);
        float bottom2 = pos2.y - (size2.y / 2.0f);

        // AABB 碰撞偵測邏輯：當所有方向的投影都有重疊時，即代表發生碰撞
        if (right1 >= left2 && left1 <= right2 && top1 >= bottom2 && bottom1 <= top2) {
            return true;
        }
        return false;
    }
    // TODO: Add and implement more methods and properties as needed to finish Giraffe Adventure.

private:
    void ResetPosition() { m_Transform.translation = {0, 0}; }

    std::string m_ImagePath;
};


#endif //CHARACTER_HPP
