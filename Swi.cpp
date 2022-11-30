#include "Main.h"
#include <WinUser.h>

INPUT inputs[8] = {};
INPUT reserve;
int c = 0;
void Switch() {
	ZeroMemory(inputs, sizeof(inputs));
	if (GetState().Gamepad.wButtons & XINPUT_GAMEPAD_START)
	{
		Vibrate(0, 65535);
	}
	if (GetState().Gamepad.wButtons & XINPUT_GAMEPAD_A & XINPUT_GAMEPAD_RIGHT_SHOULDER) {
		//Enter
		inputs[0].type = INPUT_KEYBOARD;
		inputs[0].ki.wVk = VK_RETURN;
		inputs[1].type = INPUT_KEYBOARD;
		inputs[1].ki.wVk = VK_RETURN;
		inputs[1].ki.dwFlags = KEYEVENTF_KEYUP;

		c = 2;
		for (int i = c; i < 8;i++)
			inputs[i] = reserve;

		UINT uSent = SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));
		if (uSent != ARRAYSIZE(inputs))
		{
			Vibrate(65535, 0);
		}
	}
	if (GetState().Gamepad.wButtons & XINPUT_GAMEPAD_B) {
		//Esc
		inputs[0].type = INPUT_KEYBOARD;
		inputs[0].ki.wVk = VK_ESCAPE;
		inputs[1].type = INPUT_KEYBOARD;
		inputs[1].ki.wVk = VK_ESCAPE;
		inputs[1].ki.dwFlags = KEYEVENTF_KEYUP;

		c = 2;
		for (int i = c; i < 8; i++)
			inputs[i] = reserve;

		UINT uSent = SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));
		if (uSent != ARRAYSIZE(inputs))
		{
			Vibrate(65535, 0);
		}
	}
	if (GetState().Gamepad.wButtons & XINPUT_GAMEPAD_X) {
		//Space
		inputs[0].type = INPUT_KEYBOARD;
		inputs[0].ki.wVk = VK_ESCAPE;
		inputs[1].type = INPUT_KEYBOARD;
		inputs[1].ki.wVk = VK_ESCAPE;
		inputs[1].ki.dwFlags = KEYEVENTF_KEYUP;

		UINT uSent = SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));
		if (uSent != ARRAYSIZE(inputs))
		{
			Vibrate(65535, 0);
		}
	}
	if (GetState().Gamepad.wButtons & XINPUT_GAMEPAD_Y & XINPUT_GAMEPAD_LEFT_SHOULDER) {
		//ctrl+tab
		inputs[0].type = INPUT_KEYBOARD;
		inputs[0].ki.wVk = VK_CONTROL;
		inputs[1].type = INPUT_KEYBOARD;
		inputs[1].ki.wVk = VK_TAB;

		inputs[2].type = INPUT_KEYBOARD;
		inputs[2].ki.wVk = VK_CONTROL;
		inputs[2].ki.dwFlags = KEYEVENTF_KEYUP;
		inputs[3].type = INPUT_KEYBOARD;
		inputs[3].ki.wVk = VK_TAB;
		inputs[3].ki.dwFlags = KEYEVENTF_KEYUP;

		c = 4;
		for (int i = c; i < 8; i++)
			inputs[i] = reserve;

		UINT uSent = SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));
		if (uSent != ARRAYSIZE(inputs))
		{
			Vibrate(65535, 0);
		}
	}
	if (GetState().Gamepad.wButtons & XINPUT_GAMEPAD_Y & XINPUT_GAMEPAD_LEFT_THUMB) {
		//Move object held
		inputs[0].type = INPUT_KEYBOARD;
		inputs[0].ki.wVk = VK_MENU;
		inputs[1].type = INPUT_KEYBOARD;
		inputs[1].ki.wVk = VK_SPACE;
		inputs[2].type = INPUT_KEYBOARD;
		inputs[2].ki.wVk = VK_DOWN;
		inputs[3].type = INPUT_KEYBOARD;
		inputs[3].ki.wVk = VK_RETURN;

		inputs[4].type = INPUT_KEYBOARD;
		inputs[4].ki.wVk = VK_MENU;
		inputs[4].ki.dwFlags = KEYEVENTF_KEYUP;
		inputs[5].type = INPUT_KEYBOARD;
		inputs[5].ki.wVk = VK_SPACE;
		inputs[5].ki.dwFlags = KEYEVENTF_KEYUP;
		inputs[6].type = INPUT_KEYBOARD;
		inputs[6].ki.wVk = VK_DOWN;
		inputs[6].ki.dwFlags = KEYEVENTF_KEYUP;
		inputs[7].type = INPUT_KEYBOARD;
		inputs[7].ki.wVk = VK_RETURN;
		inputs[7].ki.dwFlags = KEYEVENTF_KEYUP;

		c = 8;
		for (int i = c; i < 8; i++) {
			try {
				inputs[i] = reserve;
				throw inputs[8];
			}catch (int number) {
				Vibrate(0, 65535);
			}
		}

		UINT uSent = SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));
		if (uSent != ARRAYSIZE(inputs))
		{
			Vibrate(65535, 0);
		}
	}
	if (GetState().Gamepad.wButtons & (XINPUT_GAMEPAD_RIGHT_SHOULDER & VK_PAD_RTRIGGER)) {
		//End
		inputs[0].type = INPUT_KEYBOARD;
		inputs[0].ki.wVk = VK_END;

		inputs[1].type = INPUT_KEYBOARD;
		inputs[1].ki.wVk = VK_END;
		inputs[1].ki.dwFlags = KEYEVENTF_KEYUP;

		c = 2;
		for (int i = c; i < 8; i++)
			inputs[i] = reserve;

		UINT uSent = SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));
		if (uSent != ARRAYSIZE(inputs))
		{
			Vibrate(65535, 0);
		}
	}
	if (GetState().Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER) {
		//Ctrl
		inputs[0].type = INPUT_KEYBOARD;
		inputs[0].ki.wVk = VK_CONTROL;

		inputs[1].type = INPUT_KEYBOARD;
		inputs[1].ki.wVk = VK_CONTROL;
		inputs[1].ki.dwFlags = KEYEVENTF_KEYUP;

		c = 2;
		for (int i = c; i < 8; i++)
			inputs[i] = reserve;

		UINT uSent = SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));
		if (uSent != ARRAYSIZE(inputs))
		{
			Vibrate(65535, 0);
		}
	}
	if (GetState().Gamepad.wButtons & VK_PAD_LTRIGGER) {
		//Shift
		//VK_PAD_LTRIGGER
		inputs[0].type = INPUT_KEYBOARD;
		inputs[0].ki.wVk = VK_SHIFT;

		inputs[1].type = INPUT_KEYBOARD;
		inputs[1].ki.wVk = VK_SHIFT;
		inputs[1].ki.dwFlags = KEYEVENTF_KEYUP;

		c = 2;
		for (int i = c; i < 8; i++)
			inputs[i] = reserve;

		UINT uSent = SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));
		if (uSent != ARRAYSIZE(inputs))
		{
			Vibrate(65535, 0);
		}
	}
	if (GetState().Gamepad.wButtons & (XINPUT_GAMEPAD_LEFT_SHOULDER & VK_PAD_LTRIGGER)) {
		//Home
		inputs[0].type = INPUT_KEYBOARD;
		inputs[0].ki.wVk = VK_HOME;

		inputs[1].type = INPUT_KEYBOARD;
		inputs[1].ki.wVk = VK_HOME;
		inputs[1].ki.dwFlags = KEYEVENTF_KEYUP;

		c = 2;
		for (int i = c; i < 8; i++)
			inputs[i] = reserve;

		UINT uSent = SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));
		if (uSent != ARRAYSIZE(inputs))
		{
			Vibrate(65535, 0);
		}
	}
	if (GetState().Gamepad.wButtons & XINPUT_GAMEPAD_BACK) {
		//Alt+F4/ close,shutdown etc.
		inputs[0].type = INPUT_KEYBOARD;
		inputs[0].ki.wVk = VK_CONTROL;
		inputs[1].type = INPUT_KEYBOARD;
		inputs[1].ki.wVk = VK_F4;

		inputs[2].type = INPUT_KEYBOARD;
		inputs[2].ki.wVk = VK_CONTROL;
		inputs[2].ki.dwFlags = KEYEVENTF_KEYUP;
		inputs[3].type = INPUT_KEYBOARD;
		inputs[3].ki.wVk = VK_F4;
		inputs[3].ki.dwFlags = KEYEVENTF_KEYUP;

		c = 4;
		for (int i = c; i < 8; i++)
			inputs[i] = reserve;

		UINT uSent = SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));
		if (uSent != ARRAYSIZE(inputs))
		{
			Vibrate(65535, 0);
		}
	}
	if (GetState().Gamepad.wButtons & XINPUT_GAMEPAD_START) {
		//Windows Logo Button
		inputs[0].type = INPUT_KEYBOARD;
		inputs[0].ki.wVk = VK_LWIN;

		inputs[1].type = INPUT_KEYBOARD;
		inputs[1].ki.wVk = VK_LWIN;
		inputs[1].ki.dwFlags = KEYEVENTF_KEYUP;

		c = 2;
		for (int i = c; i < 8; i++)
			inputs[i] = reserve;

		UINT uSent = SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));
		if (uSent != ARRAYSIZE(inputs))
		{
			Vibrate(65535, 0);
		}
	}
	if (GetState().Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_THUMB) {
		//Page Scrolling Left,Right,Up,Down:
		/*
		VK_PAD_RTHUMB_PRESS:
			VK_PAD_RTHUMB_<UP,DOWN,LEFT,RIGHT,UPLEFT,UPRIGHT,DOWNRIGHT,DOWNLEFT>
			*/
		
			/*
		VK_PAD_RTHUMB:no pressing
			VK_PAD_RTHUMB_UP, VK_PAD_RTHUMB_DOWN : page up/down
		*/
		// up
		inputs[0].type = INPUT_KEYBOARD;
		inputs[0].ki.wVk = SB_PAGEUP;

		inputs[1].type = INPUT_KEYBOARD;
		inputs[1].ki.wVk = SB_PAGEUP;
		inputs[1].ki.dwFlags = KEYEVENTF_KEYUP;

		c = 2;
		for (int i = c; i < 8; i++)
			inputs[i] = reserve;

		UINT uSent = SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));
		if (uSent != ARRAYSIZE(inputs))
		{
			Vibrate(65535, 0);
		}
		// left
		inputs[0].type = INPUT_KEYBOARD;
		inputs[0].ki.wVk = SB_PAGELEFT;

		inputs[1].type = INPUT_KEYBOARD;
		inputs[1].ki.wVk = SB_PAGELEFT;
		inputs[1].ki.dwFlags = KEYEVENTF_KEYUP;

		c = 2;
		for (int i = c; i < 8; i++)
			inputs[i] = reserve;

		UINT uSent = SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));
		if (uSent != ARRAYSIZE(inputs))
		{
			Vibrate(65535, 0);
		}

		// right
		inputs[0].type = INPUT_KEYBOARD;
		inputs[0].ki.wVk = SB_PAGERIGHT;

		inputs[1].type = INPUT_KEYBOARD;
		inputs[1].ki.wVk = SB_PAGERIGHT;
		inputs[1].ki.dwFlags = KEYEVENTF_KEYUP;

		c = 2;
		for (int i = c; i < 8; i++)
			inputs[i] = reserve;

		UINT uSent = SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));
		if (uSent != ARRAYSIZE(inputs))
		{
			Vibrate(65535, 0);
		}

		// down
		inputs[0].type = INPUT_KEYBOARD;
		inputs[0].ki.wVk = SB_PAGEDOWN;

		inputs[1].type = INPUT_KEYBOARD;
		inputs[1].ki.wVk = SB_PAGEDOWN;
		inputs[1].ki.dwFlags = KEYEVENTF_KEYUP;

		c = 2;
		for (int i = c; i < 8; i++)
			inputs[i] = reserve;

		UINT uSent = SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));
		if (uSent != ARRAYSIZE(inputs))
		{
			Vibrate(65535, 0);
		}
	}
	if (GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP) {
		//Arrow Up
		inputs[0].type = INPUT_KEYBOARD;
		inputs[0].ki.wVk = VK_UP;

		inputs[1].type = INPUT_KEYBOARD;
		inputs[1].ki.wVk = VK_UP;
		inputs[1].ki.dwFlags = KEYEVENTF_KEYUP;

		c = 2;
		for (int i = c; i < 8; i++)
			inputs[i] = reserve;

		UINT uSent = SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));
		if (uSent != ARRAYSIZE(inputs))
		{
			Vibrate(65535, 0);
		}
	}
	if (GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN) {
		//Arrow Down
		inputs[0].type = INPUT_KEYBOARD;
		inputs[0].ki.wVk = VK_DOWN;

		inputs[1].type = INPUT_KEYBOARD;
		inputs[1].ki.wVk = VK_DOWN;
		inputs[1].ki.dwFlags = KEYEVENTF_KEYUP;

		c = 2;
		for (int i = c; i < 8; i++)
			inputs[i] = reserve;

		UINT uSent = SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));
		if (uSent != ARRAYSIZE(inputs))
		{
			Vibrate(65535, 0);
		}
	}
	if (GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT) {
		//Arrow Left
		inputs[0].type = INPUT_KEYBOARD;
		inputs[0].ki.wVk = VK_LEFT;
		inputs[1].type = INPUT_KEYBOARD;
		inputs[1].ki.wVk = VK_LEFT;
		inputs[1].ki.dwFlags = KEYEVENTF_KEYUP;

		c = 2;
		for (int i = c; i < 8; i++)
			inputs[i] = reserve;

		UINT uSent = SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));
		if (uSent != ARRAYSIZE(inputs))
		{
			Vibrate(65535, 0);
		}
	}
	if (GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT) {
		//Arrow Right
		inputs[0].type = INPUT_KEYBOARD;
		inputs[0].ki.wVk = VK_RIGHT;

		inputs[1].type = INPUT_KEYBOARD;
		inputs[1].ki.wVk = VK_RIGHT;
		inputs[1].ki.dwFlags = KEYEVENTF_KEYUP;

		c = 2;
		for (int i = c; i < 8; i++)
			inputs[i] = reserve;

		UINT uSent = SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));
		if (uSent != ARRAYSIZE(inputs))
		{
			Vibrate(65535, 0);
		}
	}
}
int main(int argc, char** argv) {
	GamepadUpdate();
	if (IsConnected()) {
		if (GetState().Gamepad.wButtons & XINPUT_GAMEPAD_START)
		{
			Vibrate(0, 65535);
		}
		while (true) {
			Switch();
		}
	}
	return 0;
}