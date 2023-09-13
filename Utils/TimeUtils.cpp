#include "TimeUtils.hpp"

double TimeUtils::UpdateDeltaTime()
{
    currentFrameTime = glfwGetTime();
    deltaTime = currentFrameTime - prevFrameTime;
    prevFrameTime = currentFrameTime;
    timePassed += deltaTime;
    return deltaTime;
}