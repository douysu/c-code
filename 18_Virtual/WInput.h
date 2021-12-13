#pragma once
#include "Input.h"

class WInput : public Input
{
protected:
	virtual bool IsKeyPressedImpl(int keycode) override;
};

