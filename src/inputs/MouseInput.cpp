#include "pch.h"

#include "inputs/MouseInput.h"

MouseInput::MouseInput()
    :coord(0,0)
{}

void MouseInput::Update(SDL_Event e)
{
    isPushUp = false;
    isPushDown = false;

    switch(e.type)
    {
    case SDL_MOUSEBUTTONDOWN:
        {
            try
            {
                m_isButtonDown.at(e.button.button) = true;
            }
            catch(const std::out_of_range& exeption)
            {
                m_isButtonDown.insert( std::pair<int, bool>{e.button.button, true});
            }
            std::unique_ptr<Event> event{ std::make_unique<MouseButtonEvent>(e)};
            EventHandler::addEvent(std::move(event));

            isPushDown = true;
            key = e.button.button;
        }
        break;
    case SDL_MOUSEBUTTONUP:
        {
            try
            {
                m_isButtonDown.at(e.button.button) = false;
            }
            catch(const std::out_of_range& exeption)
            {
                m_isButtonDown.insert( std::pair<int, bool>{e.button.button, false});
            }
            std::unique_ptr<Event> event{ std::make_unique<MouseButtonEvent>(e)};
            EventHandler::addEvent(std::move(event));

            isPushUp = true;
            key = e.button.button;
        }
        break;
    case SDL_MOUSEMOTION:
        {
            coord.position.first = e.motion.x;
            coord.position.second = e.motion.y;
            std::unique_ptr<Event> event{std::make_unique<MouseMotionEvent>(e)};
            EventHandler::addEvent(std::move(event));
        }
        break;
    case SDL_MOUSEWHEEL:
        {
            std::unique_ptr<Event> event{std::make_unique<MouseWheelEvent>(e)};
            EventHandler::addEvent(std::move(event));
        }
        break;
    default:
        // std::cerr << "Mouse event unandled : " << e.type << std::endl;
        break;
    }


}

bool MouseInput::isDown(int key)
{
    try
    {
        return m_isButtonDown.at(key);
    }
    catch(const std::out_of_range& e)
    {
        m_isButtonDown.at(key) = false; //assume that the key is up at the start of the program
        return false;
    }
}

bool MouseInput::isBeeingPushDown() const
{
    return isPushDown;
}

bool MouseInput::isBeeingPushUp() const
{
    return isPushUp;
}

int MouseInput::keyBeeingPush() const
{
    return key;
}

MouseMotionEvent::MouseMotionEvent(SDL_Event e)
{
    m_type = Et::MouseMotionEvent;
    event = e.motion;
}

MouseButtonEvent::MouseButtonEvent(SDL_Event e)
{
    m_type = Et::MouseButtonEvent;
    event = e.button;
}

MouseWheelEvent::MouseWheelEvent(SDL_Event e)
{
    m_type = Et::MouseWheelEvent;
    event = e.wheel;
}