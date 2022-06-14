import vgamepad as vg
import time
imort serial 


ser = serial.Serial("COM"+input(">>"), 9600)

gamepad = vg.VX360Gamepad()

gamepad.press_button(button=vg.XUSB_BUTTON.XUSB_GAMEPAD_A)
gamepad.update()
time.sleep(0.5)
gamepad.release_button(button=vg.XUSB_BUTTON.XUSB_GAMEPAD_A)
gamepad.update()
time.sleep(0.5)

while True:
    ser.reset_input_buffer()
    data = ser.readline()

    gamepad.reset()
    if(data):
        print(data.decode().strip())
        if data.decode().strip() == "0":
            gamepad.press_button(button=vg.XUSB_BUTTON.XUSB_GAMEPAD_X)
            gamepad.update()
            time.sleep(0.1)
            gamepad.release_button(button=vg.XUSB_BUTTON.XUSB_GAMEPAD_X)
            gamepad.update()
            time.sleep(0.1)

        if data.decode().strip() == "1":
            gamepad.press_button(button=vg.XUSB_BUTTON.XUSB_GAMEPAD_GUIDE)
            gamepad.update()
            time.sleep(0.1)
            gamepad.release_button(button=vg.XUSB_BUTTON.XUSB_GAMEPAD_GUIDE)
            gamepad.update()
            time.sleep(0.1)

        if data.decode().strip() == "2":
            gamepad.press_button(button=vg.XUSB_BUTTON.XUSB_GAMEPAD_A)
            gamepad.update()
            time.sleep(0.1)
            gamepad.release_button(button=vg.XUSB_BUTTON.XUSB_GAMEPAD_A)
            gamepad.update()
            time.sleep(0.1)

        if data.decode().strip() == "3":
            gamepad.press_button(button=vg.XUSB_BUTTON.XUSB_GAMEPAD_Y)
            gamepad.update()
            time.sleep(0.1)
            gamepad.release_button(button=vg.XUSB_BUTTON.XUSB_GAMEPAD_Y)
            gamepad.update()
            time.sleep(0.1)

        if data.decode().strip() == "4":
            gamepad.press_button(button=vg.XUSB_BUTTON.XUSB_GAMEPAD_DPAD_DOWN)
            gamepad.update()
            time.sleep(0.1)
            gamepad.release_button(
                button=vg.XUSB_BUTTON.XUSB_GAMEPAD_DPAD_DOWN)
            gamepad.update()
            time.sleep(0.1)

        if data.decode().strip() == "5":
            gamepad.press_button(button=vg.XUSB_BUTTON.XUSB_GAMEPAD_DPAD_UP)
            gamepad.update()
            time.sleep(0.1)
            gamepad.release_button(button=vg.XUSB_BUTTON.XUSB_GAMEPAD_DPAD_UP)
            gamepad.update()
            time.sleep(0.1)

        if data.decode().strip() == "6":
            gamepad.press_button(button=vg.XUSB_BUTTON.XUSB_GAMEPAD_LEFT_SHOULDER)
            gamepad.update()
            time.sleep(1.5)
            gamepad.release_button(
                button=vg.XUSB_BUTTON.XUSB_GAMEPAD_LEFT_SHOULDER)
            gamepad.update()
            time.sleep(0.1)

        if data.decode().strip() == "7":
            gamepad.press_button(button=vg.XUSB_BUTTON.XUSB_GAMEPAD_RIGHT_SHOULDER)
            gamepad.update()
            time.sleep(0.1)
            gamepad.release_button(
                button=vg.XUSB_BUTTON.XUSB_GAMEPAD_RIGHT_SHOULDER)
            gamepad.update()
            time.sleep(0.1)

        if data.decode().strip() == "8":
            gamepad.press_button(button=vg.XUSB_BUTTON.XUSB_GAMEPAD_LEFT_THUMB)
            gamepad.update()
            time.sleep(0.1)
            gamepad.release_button(
                button=vg.XUSB_BUTTON.XUSB_GAMEPAD_LEFT_THUMB)
            gamepad.update()
            time.sleep(0.1)

        if data.decode().strip() == "9":
            gamepad.press_button(
                button=vg.XUSB_BUTTON.XUSB_GAMEPAD_RIGHT_THUMB)
            gamepad.update()
            time.sleep(0.1)
            gamepad.release_button(
                button=vg.XUSB_BUTTON.XUSB_GAMEPAD_RIGHT_THUMB)
            gamepad.update()
            time.sleep(0.1)

        if data.decode().strip() == "A":
            gamepad.press_button(
                button=vg.XUSB_BUTTON.XUSB_GAMEPAD_DPAD_LEFT)
            gamepad.update()
            time.sleep(0.1)
            gamepad.release_button(
                button=vg.XUSB_BUTTON.XUSB_GAMEPAD_DPAD_LEFT)
            gamepad.update()
            time.sleep(0.1)

        if data.decode().strip() == "B":
            gamepad.press_button(
                button=vg.XUSB_BUTTON.XUSB_GAMEPAD_DPAD_RIGHT)
            gamepad.update()
            time.sleep(0.1)
            gamepad.release_button(
                button=vg.XUSB_BUTTON.XUSB_GAMEPAD_DPAD_RIGHT)
            gamepad.update()
            time.sleep(0.1)

