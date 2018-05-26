/*
mvxxx 2018
https://github.com/mvxxx
*/

#pragma once

#include "GraphicManager/GraphicManager.hpp"
#include "OneArmedBandit/oneArmedBandit.hpp"
#include "ecs/component/ProperBody.hpp"
#include "ecs/component/text/Text.hpp"
#include "ecs/entity/Entity.hpp"
#include "scene/Scene.hpp"

class UILoader
{
	/* ===Methods=== */
public:
  void LoadUI(std::vector<std::shared_ptr<mv::Entity>>& entities, const std::shared_ptr<Loader>& loader, 
    const std::shared_ptr<GraphicManager>& graphicManager, const std::shared_ptr<Scene>& scene, const std::shared_ptr<OneArmedBandit>& banditMachine);
private:
  void loadButtons(std::vector<std::shared_ptr<mv::Entity>>& entities, const Vector2<float>& windowSize,
    const std::shared_ptr<GraphicManager>& graphicManager, const std::shared_ptr<Scene>& scene);

  void loadTextBoxes(std::vector<std::shared_ptr<mv::Entity>>& entities, const Vector2<float>& windowSize,
    const std::shared_ptr<GraphicManager>& graphicManager, const std::shared_ptr<Scene>& scene);

  void loadRolls(std::vector<std::shared_ptr<mv::Entity>>& entities, const std::shared_ptr<Loader>& loader,
    const Vector2<float>& windowSize, const std::shared_ptr<GraphicManager>& graphicManager, const std::shared_ptr<Scene>& scene, const std::shared_ptr<OneArmedBandit>& banditMachine);

  void loadBackground(std::vector<std::shared_ptr<mv::Entity>>& entities, const Vector2<float>& windowSize,
    const std::shared_ptr<GraphicManager>& graphicManager, const std::shared_ptr<Scene>& scene);

  void checkDimensions(std::shared_ptr<mv::Entity> exampleSymbol, const Vector2<float>& delta, const std::shared_ptr<Loader>& loader);
};