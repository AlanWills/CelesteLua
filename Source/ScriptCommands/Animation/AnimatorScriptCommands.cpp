#include "ScriptCommands/Animation/AnimatorScriptCommands.h"
#include "ScriptCommands/ScriptCommandUtils.h"

#include "Animation/Animator.h"


namespace sol
{
  template <>
  struct is_to_stringable<Celeste::Animation::Animator> : std::false_type {};
}

namespace Celeste::Lua::Animation::AnimatorScriptCommands
{
  namespace Internals
  {
    //------------------------------------------------------------------------------------------------
    void setLooping(Celeste::Animation::Animator& animator, bool isLooping)
    {
      animator.setLooping(isLooping ? Celeste::Animation::LoopMode::kLooping :
        Celeste::Animation::LoopMode::kOneTime);
    }
  }

  //------------------------------------------------------------------------------------------------
  void initialize(sol::state& state)
  {
    using Animator = Celeste::Animation::Animator;

    registerUserType<Animator>(
      state,
      Animator::type_name(),
      sol::base_classes, sol::bases<Component, Entity, Object>(),
      "getSpriteSheetDimensions", &Animator::getSpriteSheetDimensions,
      "setSpriteSheetDimensions", &Animator::setSpriteSheetDimensions,
      "getSecondsPerFrame", &Animator::getSecondsPerFrame,
      "setSecondsPerFrame", &Animator::setSecondsPerFrame,
      "isLooping", &Animator::isLooping,
      "setLooping", &Internals::setLooping,
      "play", &Animator::play,
      "pause", &Animator::pause,
      "stop", &Animator::stop,
      "restart", &Animator::restart);
  }
}