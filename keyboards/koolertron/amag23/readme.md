# amag23

![amag23](https://i.imgur.com/rgYQzGZ.jpg)

A 23 key mechanical keyboard made by Koolertron. It uses an Atmel ATmega32A, USB-C, and it is a ps2avrGB based board. 

The particular model shown in the photo above uses "red" (linear) switches and has RGB LED zoned backlighting. There are 7 lighting zones on the keyboard that are directly accessible. See image above, the zones are the diagonal bands of color indexed from zero starting from the top-left of the keyboard.

There are also other variations with different shells, blue (clicky) switches, backlight capabilities (solid/rgb), and keycap colors.

Note: that I am not affliated or associated with Koolertron. Using QMK may void your warrenty for this product. 

Warning: Once you upload a QMK firmware to your keyboard, you will lose the original firmware this keyboard came with.

* Keyboard Maintainer: [Kevin Ta](https://github.com/kevinta893)
* Hardware Supported: ATmega32A using bootloadHID
* Hardware Availability: [Koolertron](http://www.koolertron.com/koolertron-one-handed-macro-mechanical-keyboard-rgb-led-backlit-portable-mini-onehanded-mechanical-gaming-keypad-23-fully-programmable-keys-blue-switches-p-874.html)

Make example for this keyboard (after setting up your build environment):

    make amag23:default

Flashing example for this keyboard ([after setting up the bootloadHID flashing environment](https://docs.qmk.fm/#/flashing_bootloadhid))

    make amag23:default:bootloadHID

**Reset Key**: Hold down the *ESC* key located at the *top-left most* with the keyboard oriented with the USB-C port side facing away from you. It is commonly programmed as *ESC* while plugging in the keyboard.

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).
