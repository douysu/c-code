#include "WInput.h"

Input* Input::s_Instance = new WInput();

bool WInput::IsKeyPressedImpl(int keycode)
{
	return false;
}
