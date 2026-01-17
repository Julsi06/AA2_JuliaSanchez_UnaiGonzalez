#pragma once
#include <string>
#include "InputManager.h"

class NameInput
{
private:
    std::string _name;
    bool _finished = false;
    SDL_Window* _window = nullptr;

public:
    void Start()
    {
        SDL_StartTextInput(_window);
    }

    void Stop()
    {
        SDL_StopTextInput(_window);
    }

    void HandleEvents()
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_EVENT_QUIT)
                _finished = true;

            else if (event.type == SDL_EVENT_KEY_DOWN)
            {
                if (event.key.key == SDL_SCANCODE_BACKSPACE && !_name.empty())
                    _name.pop_back();
                else if (event.key.key == SDL_SCANCODE_RETURN)
                    _finished = true;
            }

            else if (event.type == SDL_EVENT_TEXT_INPUT)
            {
                if (_name.size() < 15)
                    _name += event.text.text;
            }
        }
    }

    bool Finished() const { return _finished; }
    const std::string& GetName() const { return _name; }
};
