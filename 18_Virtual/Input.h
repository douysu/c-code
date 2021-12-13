#pragma once
#include <iostream>
using namespace std;
class Input
{
public:
    inline static bool IsKeyPressed(int keycode) { return s_Instance->IsKeyPressedImpl(keycode); }

protected:
    virtual bool IsKeyPressedImpl(int keycode) = 0;

private:
    static Input* s_Instance;
};