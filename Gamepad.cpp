#include "Gamepad.h"

int _controllerNum;
XINPUT_STATE _controllerState;

XINPUT_STATE GetState()
{
	// Zeroise the state
	ZeroMemory(&_controllerState, sizeof(XINPUT_STATE));

	// Get the state
	XInputGetState(_controllerNum, &_controllerState);

	return _controllerState;
}

bool IsConnected(int _controllerNum)
{
	// Zeroise the state
	ZeroMemory(&_controllerState, sizeof(XINPUT_STATE));

	// Get the state
	DWORD Result = XInputGetState(_controllerNum, &_controllerState);

	if (Result == ERROR_SUCCESS)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void Vibrate(int leftVal, int rightVal) {
	// Create a Vibraton State
	XINPUT_VIBRATION Vibration;

	// Zeroise the Vibration
	ZeroMemory(&Vibration, sizeof(XINPUT_VIBRATION));

	// Set the Vibration Values
	Vibration.wLeftMotorSpeed = leftVal;
	Vibration.wRightMotorSpeed = rightVal;

	// Vibrate the controller
	XInputSetState(_controllerNum, &Vibration);
}

void GamepadUpdate()
{
	// Get the pad state.
	XINPUT_STATE pInputState;
	XInputGetState(0, &pInputState);
	unsigned short pads = pInputState.Gamepad.wButtons;
	
	// If there is at least 1 pad.
	if (pads != 0)
	{
		Vibrate(65535, 65535);
	}
}

