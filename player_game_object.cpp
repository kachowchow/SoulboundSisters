#include "player_game_object.h"

#include <iostream>
#include <cmath>

namespace game
{

      PlayerGameObject::PlayerGameObject(const glm::vec3 &position, Geometry *geom, Shader *shader, GLuint texture)
          : GameObject(position, geom, shader, texture),
            killCount(0), soulCount(0), ultimateBar(0), shieldHealth(0), health(100),
            isDashing(false), dashSpeed(60.0f), dashTimeLeft(0.0f), dashCooldown(2.0f), currentDashCooldown(0.0f), empoweredAttacksLeft(0),
            invulnerability(false), invulnerabilityTimer(0.0f)
      {
            velocity_ = glm::vec2(0.0f, 0.0f);
            in_air_ = true;
      }

      void PlayerGameObject::Dash(glm::vec2 mouse_world_pos)
      {
            if (currentDashCooldown <= 0.0f && !isDashing)
            {
                  isDashing = true;
                  dashTimeLeft = 0.15f;
                  currentDashCooldown = dashCooldown;

                  float dashDirX = (mouse_world_pos.x < position_.x) ? -1.0f : 1.0f;
                  velocity_.x = dashDirX * dashSpeed;
                  velocity_.y = 0.0f;

                  dashAttack();
            }
      }

      void PlayerGameObject::Update(double delta_time, GLFWwindow *window, glm::vec2 mouse_world_pos)
      {
            glm::vec2 player_pos(position_.x, position_.y);
            glm::vec2 direction = mouse_world_pos - player_pos;
            angle_ = atan2(direction.y, direction.x);

            // Invulnerability Timer Management
            if (isInvulnerable)
            {
                  invulnerabilityTimer -= (float)delta_time;
                  if (invulnerabilityTimer <= 0.0f)
                  {
                        invulnerabilityTimer = 0.0f;
                        isInvulnerable = false;
                  }
            }

            // Manage Dash Cooldowns
            if (currentDashCooldown > 0.0f)
            {
                  currentDashCooldown -= (float)delta_time;
            }

            // Handle Dashing State
            if (isDashing)
            {
                  dashTimeLeft -= (float)delta_time;
                  if (dashTimeLeft <= 0.0f)
                  {
                        isDashing = false;
                  }
                  else
                  {
                        // Apply dash velocity and skip normal physics
                        position_ += glm::vec3(velocity_.x * (float)delta_time, velocity_.y * (float)delta_time, 0.0f);
                        GameObject::Update(delta_time);
                        return;
                  }
            }

            float gravity = 30.0f;
            float jump_power = 12.0f;
            float horizontal_accel = 80.0f;
            float ground_y = -1.8f;
            float k = 0.4f;

            // Trigger Dash
            if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
            {
                  Dash();
            }

            if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
                  velocity_.x -= horizontal_accel * (float)delta_time;
            if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
                  velocity_.x += horizontal_accel * (float)delta_time;

            velocity_.x *= 0.90f;

            if (in_air_)
            {
                  velocity_.y -= gravity * (float)delta_time;

                  if (position_.y + (velocity_.y * (float)delta_time) <= ground_y)
                  {
                        position_.y = ground_y;

                        if (std::abs(velocity_.y) > 2.5f)
                        {
                              velocity_.y = -velocity_.y * k;
                        }
                        else
                        {
                              velocity_.y = 0.0f;
                              in_air_ = false;
                        }
                  }
            }
            else
            {
                  velocity_.y = 0.0f;
                  position_.y = ground_y;

                  if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
                  {
                        velocity_.y = jump_power;
                        in_air_ = true;
                  }
            }

            position_ += glm::vec3(velocity_.x * (float)delta_time, velocity_.y * (float)delta_time, 0.0f);
            GameObject::Update(delta_time);
      }

      void PlayerGameObject::attack()
      {
            if (empoweredAttacksLeft > 0)
            {
                  std::cout << "Player performs an empowered attack!" << std::endl;
                  empoweredAttacksLeft--;

                  // TODO: Implement Empowered Damage Logic !!
            }
            else
            {
                  std::cout << "Player performs a normal attack." << std::endl;

                  // TODO: Implement Normal Attack Logic !!
            }
      }
      void PlayerGameObject::dashAttack()
      {
            empoweredAttacksLeft = 5;
      }

      void PlayerGameObject::consumeSoul(SoulEffect effect)
      {
            if (soulCount > 0)
            {
                  soulCount--;

                  if (effect == SoulEffect::Healing)
                  {
                        if (health >= 80)
                        {
                              health = 100;
                        }
                        else
                        {
                              health += 20; // TEMP Value
                        }
                  }
                  else if (effect == SoulEffect::Invulnerability)
                  {
                        invulernability = true;
                        invulnerabilityTimer = 3.0f; // TEMP duration
                  }
            }
      }
      void PlayerGameObject::triggerUltimate() {}
      void PlayerGameObject::takeDamage(int damage) {}
      void PlayerGameObject::die() {}

} // namespace game