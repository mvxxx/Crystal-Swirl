/*
mvxxx 2018
https://github.com/mvxxx
*/

#pragma once

#include <SDL.h>
#include <SDL_image.h>

#include "GraphicManager/GraphicManager.hpp"
#include "wrappers/Vector2.hpp"
#include "cache/Cache.hpp"
#include "Config.hpp"

class ProperBody
{
  /* ===Objects=== */
public:
protected:
private:
  using type_id = mv::constants::texture::TEXTURE_ID;
  SDL_Rect rect;
  type_id type;
  SDL_Texture* texture;
  /* ===Methods=== */
public:
  void setType(const std::shared_ptr<GraphicManager>& graphicManager, type_id id, const std::shared_ptr<SDL_Renderer>& renderer);
  SDL_Texture* getTexture();
  type_id getType();
  void setPosition(const Vector2<float>& position);
  void setSize(const Vector2<float>& size);
  void move(const Vector2<float>& vector);
  const Vector2<float>& getPosition();
  const SDL_Rect& getRect();

protected:
private:
  void loadTexture(const std::shared_ptr<GraphicManager>& graphicManager, const std::shared_ptr<SDL_Renderer>& renderer);
};

inline void ProperBody::setType(const std::shared_ptr<GraphicManager>& graphicManager, type_id id, const std::shared_ptr<SDL_Renderer>& renderer)
{
  type = id;
  loadTexture(graphicManager, renderer);
}

inline SDL_Texture* ProperBody::getTexture()
{
  return texture;
}

inline mv::constants::texture::TEXTURE_ID ProperBody::getType()
{
  return type;
}

inline void ProperBody::loadTexture(const std::shared_ptr<GraphicManager>& graphicManager, const std::shared_ptr<SDL_Renderer>& renderer)
{
  texture = graphicManager->get(type);
}

inline void ProperBody::setPosition(const Vector2<float>& position)
{
  rect.x = position.x - rect.w / 2.f;
  rect.y = position.y - rect.h / 2.f;
}

inline void ProperBody::setSize(const Vector2<float>& size)
{
  rect.w = size.x;
  rect.h = size.y;
}

inline void ProperBody::move(const Vector2<float>& vector)
{
  auto pos = this->getPosition();
  this->setPosition({ pos.x + vector.x, pos.y + vector.y });
}

inline const Vector2<float>& ProperBody::getPosition()
{
  return{ rect.x + rect.w / 2.f, rect.y + rect.h / 2.f };
}

inline const SDL_Rect & ProperBody::getRect()
{
  return rect;
}
