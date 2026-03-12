#ifndef PLAYER_GAME_OBJECT_H_
#define PLAYER_GAME_OBJECT_H_

#include "game_object.h"
#include <GLFW/glfw3.h>

namespace game {
    class PlayerGameObject : public GameObject {
        private:
            glm::vec2 velocity_;
            bool in_air_;

            // --- Soulbound Sisters Player Stats ---
            int killCount; 
            int soulCount; 
            int ultimateBar;
            int shieldHealth;
            int health;

            // --- Dash Mechanics ---
            bool isDashing;
            float dashSpeed;
            float dashTimeLeft;
            float dashCooldown;
            float currentDashCooldown;

            int empoweredAttacksLeft;

            // --- Invulnerability State ---
            bool invulnerability;
            float invulnerabilityTimer;

        public:
            PlayerGameObject(const glm::vec3 &position, Geometry *geom, Shader *shader, GLuint texture);

            void Update(double delta_time, GLFWwindow* window, glm::vec2 mouse_world_pos);
            
            // --- New Mechanics ---
            void Dash(glm::vec2 mouse_world_pos);
            void attack();
            void dashAttack();

            enum class SoulEffect {
                  Healing, 
                  Invulnerability
            };

            void consumeSoul(SoulEffect effect);
            void triggerUltimate();
            void takeDamage(int damage);
            void die();

            // Getters
            bool getIsDashing() const { return isDashing; }

    }; // class PlayerGameObject

} // namespace game

#endif // PLAYER_GAME_OBJECT_H_