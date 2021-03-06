// -*- mode: c++ -*-
// Copyright 2016 Keyboardio, inc. <jesse@keyboard.io>
// See "LICENSE" for license details

#ifndef BUILD_INFORMATION
#define BUILD_INFORMATION "locally built"
#endif


/**
 * These #include directives pull in the Kaleidoscope firmware core,
 * as well as the Kaleidoscope plugins we use in the Model 01's firmware
 */

// avr-gcc compiles files with .c ending with C name mangling
//
//extern "C" {
//#include "papageno.h"
//}

// The Kaleidoscope core
#include "Kaleidoscope.h"

// Support for papageno features
#include "Kaleidoscope-Papageno.h"
#include "ppg_debug.h"

// Support for keys that move the mouse
#include "Kaleidoscope-MouseKeys.h"

// Support for macros
#include "Kaleidoscope-Macros.h"

// Support for controlling the keyboard's LEDs
#include "Kaleidoscope-LEDControl.h"

// Support for "Numpad" mode, which is mostly just the Numpad specific LED mode
// #include "Kaleidoscope-NumPad.h"

// Support for an "LED off mode"
#include "LED-Off.h"

// Support for the "Boot greeting" effect, which pulses the 'LED' button for 10s
// when the keyboard is connected to a computer (or that computer is powered on)
#include "Kaleidoscope-LEDEffect-BootGreeting.h"

// Support for LED modes that set all LEDs to a single color
//#include "Kaleidoscope-LEDEffect-SolidColor.h"

// Support for an LED mode that makes all the LEDs 'breathe'
#include "Kaleidoscope-LEDEffect-Breathe.h"

// Support for an LED mode that makes a red pixel chase a blue pixel across the keyboard
//#include "Kaleidoscope-LEDEffect-Chase.h"

// Support for LED modes that pulse the keyboard's LED in a rainbow pattern
//#include "Kaleidoscope-LEDEffect-Rainbow.h"

// Support for an LED mode that lights up the keys as you press them
//#include "Kaleidoscope-LED-Stalker.h"

// Support for an LED mode that prints the keys you press in letters 4px high
//#include "Kaleidoscope-LED-AlphaSquare.h"

// Support for Keyboardio's internal keyboard testing mode
//#include "Kaleidoscope-Model01-TestMode.h"

// Support for host power management (suspend & wakeup)
// #include "Kaleidoscope-HostPowerManagement.h"


/** This 'enum' is a list of all the macros used by the Model 01's firmware
  * The names aren't particularly important. What is important is that each
  * is unique.
  *
  * These are the names of your macros. They'll be used in two places.
  * The first is in your keymap definitions. There, you'll use the syntax
  * `M(MACRO_NAME)` to mark a specific keymap position as triggering `MACRO_NAME`
  *
  * The second usage is in the 'switch' statement in the `macroAction` function.
  * That switch statement actually runs the code associated with a macro when
  * a macro key is pressed.
  */

enum { MACRO_VERSION_INFO,
       MACRO_ANY
     };



/** The Model 01's key layouts are defined as 'keymaps'. By default, there are three
  * keymaps: The standard QWERTY keymap, the "Function layer" keymap and the "Numpad"
  * keymap.
  *
  * Each keymap is defined as a list using the 'KEYMAP_STACKED' macro, built
  * of first the left hand's layout, followed by the right hand's layout.
  *
  * Keymaps typically consist mostly of `Key_` definitions. There are many, many keys
  * defined as part of the USB HID Keyboard specification. You can find the names
  * (if not yet the explanations) for all the standard `Key_` defintions offered by
  * Kaleidoscope in these files:
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/key_defs_keyboard.h
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/key_defs_consumerctl.h
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/key_defs_sysctl.h
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/key_defs_keymaps.h
  *
  * Additional things that should be documented here include
  *   using ___ to let keypresses fall through to the previously active layer
  *   using XXX to mark a keyswitch as 'blocked' on this layer
  *   using ShiftToLayer() and LockLayer() keys to change the active keymap.
  *   the special nature of the PROG key
  *   keeping NUM and FN consistent and accessible on all layers
  *
  *
  * The "keymaps" data structure is a list of the keymaps compiled into the firmware.
  * The order of keymaps in the list is important, as the ShiftToLayer(#) and LockLayer(#)
  * macros switch to key layers based on this list.
  *
  *

  * A key defined as 'ShiftToLayer(FUNCTION)' will switch to FUNCTION while held.
  * Similarly, a key defined as 'LockLayer(NUMPAD)' will switch to NUMPAD when tapped.
  */

/**
  * Layers are "0-indexed" -- That is the first one is layer 0. The second one is layer 1.
  * The third one is layer 2.
  * This 'enum' lets us use names like QWERTY, FUNCTION, and NUMPAD in place of
  * the numbers 0, 1 and 2.
  *
  */

enum { NORMAN, M1, M2, M3 }; // layers

/* This comment temporarily turns off astyle's indent enforcement
 *   so we can make the keymaps actually resemble the physical key layout better
 */
// *INDENT-OFF*

const Key keymaps[][ROWS][COLS] PROGMEM = {

  [NORMAN] = KEYMAP_STACKED
  (LCTL(Key_X),  LCTL(Key_C),   LCTL(Key_V), LCTL(Key_F), ___,      ___,      ___,
   OSL(M3),      Key_Q,         Key_W,       Key_D,       Key_F,    Key_K,    ___,
   OSL(M2),      Key_A,         Key_S,       Key_E,       Key_T,    Key_G, // home row
   OSM(MOD_LCTL),Key_Z,         Key_X,       Key_C,       Key_V,    Key_B,    ___,
   ___,          ___,           Key_Backspace, OSM(MOD_LSFT),
   OSL(M1),

   ___,          ___,           ___,         OSM(MOD_ALT), ___,     LCTL(Key_S), Key_Escape,
   ___,          Key_J,         Key_U,       Key_R,       Key_L,    Key_Semicolon, OSL(M3),
                 Key_Y,         Key_N,       Key_I,       Key_O,    Key_H,    OSL(M2),
   ___,          Key_P,         Key_M,       Key_Comma,   Key_Period,Key_Slash,OSM(MOD_LCTL),
   OSL(M1),      Key_Space,     ___,         ___,
   OSL(M1)),
   
   [M1] = KEYMAP_STACKED
   (___,         ___,           ___,         ___,         ___,      ___,      ___,
    ___,         Key_At,        Key_Underscore, Key_LeftBrace, Key_RightBrace, Key_Circle, ___,
    ___,         Key_Backslash, Key_Grave,   Gey_LeftCurlyBrace, Key_RightCurlyBrace, Key_Asterisk,
    ___,         Key_Hash,      Key_Tilda,   Key_Pipe,    Key_Dollar, ALTG(KC_5), ___,
    ___,         ___,           ___,         ___,        
    ___,
    
    ___,         ___,           ___,         ___,         ___,      ___,      ___,
    ___,         Key_Exclamation, Key_Less,  Key_More,    Key_Equal, Key_Ampersand, ___,
                 SHIFT(KC_SLASH), Key_LeftBrace, Key_RightBrace, Key_Minus, Key_Colon, ___,
    ___,         Key_Plus,      Key_Percentage, SHIFT(Key_Quote), Key_Quote, Key_Semicolon, ___,
    ___,         ___,           ___,         ___,
    ___),
    
   [M2] = KEYMAP_STACKED
   (___,         ___,           ___,         ___,         ___,      ___,      ___,
    ___,         Key_PageUp,    Key_Backspace, Key_Up,    Key_Del,  Key_PageDown, ___,
    ___,         Key_Home,      Key_Left,    Key_Down,    Key_Right, Key_End,
    ___,         Nothing,       Key_Tab,     Nothing,     Key_Enter, Nothing, ___,
    ___,         ___,           ___,         ___,
    ___,
    
    ___,         ___,           ___,         ___,         ___,      ___,      ___,
    ___,         Nothing,       Key_7,       Key_8,       Key_9,    Nothing,  ___,
                 Nothing,       Key_4,       Key_5,       Key_6,    Key_Colon,___,
    ___,         Key_0,         Key_1,       Key_2,       Key_3,    Key_Comma,___,
    ___,         ___,           ___,         ___,
    ___),
    
   [M3] = KEYMAP_STACKED
   (___,         ___,           ___,         ___,         ___,      ___,      ___,
    ___,         ___,           ___,         ___,         ___,      ___,      ___,
    ___,         ___,           ___,         ___,         ___,      ___,    
    ___,         ___,           ___,         ___,         ___,      ___,      ___,
    ___,         ___,           ___,         ___,
    ___,
    
    ___,         ___,           ___,         ___,         ___,      ___,      ___,
    ___,         Nothing,       Key_F7,      Key_F8,      Key_F9,   Key_F12,  ___,
                 DE_SQ3,        Key_F4,      Key_F5,      Key_F6,   Key_F11,  ___,
    ___,         DE_SQ2,        Key_F1,      Key_F2,      Key_F3,   Key_F10,  ___,   
    ___,         ___,           ___,         ___,
    ___) 

 
};

/* Re-enable astyle's indent enforcement */
// *INDENT-ON*

/** versionInfoMacro handles the 'firmware version info' macro
 *  When a key bound to the macro is pressed, this macro
 *  prints out the firmware build information as virtual keystrokes
 */

static void versionInfoMacro(uint8_t keyState) {
  if (keyToggledOn(keyState)) {
    Macros.type(PSTR("Keyboardio Model 01 - Kaleidoscope "));
    Macros.type(PSTR(BUILD_INFORMATION));
  }
}

/** anyKeyMacro is used to provide the functionality of the 'Any' key.
 *
 * When the 'any key' macro is toggled on, a random alphanumeric key is
 * selected. While the key is held, the function generates a synthetic
 * keypress event repeating that randomly selected key.
 *
 */

static void anyKeyMacro(uint8_t keyState) {
  static Key lastKey;
  if (keyToggledOn(keyState))
    lastKey.keyCode = Key_A.keyCode + (uint8_t)(millis() % 36);

  if (keyIsPressed(keyState))
    kaleidoscope::hid::pressKey(lastKey);
}


/** macroAction dispatches keymap events that are tied to a macro
    to that macro. It takes two uint8_t parameters.

    The first is the macro being called (the entry in the 'enum' earlier in this file).
    The second is the state of the keyswitch. You can use the keyswitch state to figure out
    if the key has just been toggled on, is currently pressed or if it's just been released.

    The 'switch' statement should have a 'case' for each entry of the macro enum.
    Each 'case' statement should call out to a function to handle the macro in question.

 */

const macro_t *macroAction(uint8_t macroIndex, uint8_t keyState) {
  switch (macroIndex) {

  case MACRO_VERSION_INFO:
    versionInfoMacro(keyState);
    break;

  case MACRO_ANY:
    anyKeyMacro(keyState);
    break;
  }
  return MACRO_NONE;
}



// These 'solid' color effect definitions define a rainbow of
// LED color modes calibrated to draw 500mA or less on the
// Keyboardio Model 01.


//static kaleidoscope::LEDSolidColor solidRed(160, 0, 0);
//static kaleidoscope::LEDSolidColor solidOrange(140, 70, 0);
//static kaleidoscope::LEDSolidColor solidYellow(130, 100, 0);
//static kaleidoscope::LEDSolidColor solidGreen(0, 160, 0);
//static kaleidoscope::LEDSolidColor solidBlue(0, 70, 130);
//static kaleidoscope::LEDSolidColor solidIndigo(0, 0, 170);
//static kaleidoscope::LEDSolidColor solidViolet(130, 0, 120);

/** toggleLedsOnSuspendResume toggles the LEDs off when the host goes to sleep,
 * and turns them back on when it wakes up.
 */
// void toggleLedsOnSuspendResume(kaleidoscope::HostPowerManagement::Event event) {
//   switch (event) {
//   case kaleidoscope::HostPowerManagement::Suspend:
//     LEDControl.paused = true;
//     LEDControl.set_all_leds_to({0, 0, 0});
//     LEDControl.syncLeds();
//     break;
//   case kaleidoscope::HostPowerManagement::Resume:
//     LEDControl.paused = false;
//     LEDControl.refreshAll();
//     break;
//   case kaleidoscope::HostPowerManagement::Sleep:
//     break;
//   }
// }

/** hostPowerManagementEventHandler dispatches power management events (suspend,
 * resume, and sleep) to other functions that perform action based on these
 * events.
 */
// void hostPowerManagementEventHandler(kaleidoscope::HostPowerManagement::Event event) {
//   toggleLedsOnSuspendResume(event);
// }

/** The 'setup' function is one of the two standard Arduino sketch functions.
  * It's called when your keyboard first powers up. This is where you set up
  * Kaleidoscope and any plugins.
  */

void setup() {
  // First, call Kaleidoscope's internal setup function
  Kaleidoscope.setup();

  // Next, tell Kaleidoscope which plugins you want to use.
  // The order can be important. For example, LED effects are
  // added in the order they're listed here.
  Kaleidoscope.use(

    &Papageno,
   
#if 0
    // The boot greeting effect pulses the LED button for 10 seconds after the keyboard is first connected
    &BootGreetingEffect,

    // The hardware test mode, which can be invoked by tapping Prog, LED and the left Fn button at the same time.
    //&TestMode,

    // LEDControl provides support for other LED modes
    &LEDControl,

    // We start with the LED effect that turns off all the LEDs.
    &LEDOff,

    // The rainbow effect changes the color of all of the keyboard's keys at the same time
    // running through all the colors of the rainbow.
    //&LEDRainbowEffect,

    // The rainbow wave effect lights up your keyboard with all the colors of a rainbow
    // and slowly moves the rainbow across your keyboard
    //&LEDRainbowWaveEffect,

    // The chase effect follows the adventure of a blue pixel which chases a red pixel across
    // your keyboard. Spoiler: the blue pixel never catches the red pixel
    //&LEDChaseEffect,

    // These static effects turn your keyboard's LEDs a variety of colors
    //&solidRed, &solidOrange, &solidYellow, &solidGreen, &solidBlue, &solidIndigo, &solidViolet,

    // The AlphaSquare effect prints each character you type, using your
    // keyboard's LEDs as a display
    //&AlphaSquareEffect,

    // The stalker effect lights up the keys you've pressed recently
    //&StalkerEffect,

    // The numpad plugin is responsible for lighting up the 'numpad' mode
    // with a custom LED effect
    &NumPad,

    // The macros plugin adds support for macros
    //&Macros,

    // The MouseKeys plugin lets you add keys to your keymap which move the mouse.
    &MouseKeys

    // The HostPowerManagement plugin enables waking up the host from suspend,
    // and allows us to turn LEDs off when it goes to sleep.
//     &HostPowerManagement

#endif

    // The breathe effect slowly pulses all of the LEDs on your keyboard
    &LEDBreatheEffect
  );

  // While we hope to improve this in the future, the NumPad plugin
  // needs to be explicitly told which keymap layer is your numpad layer
//   NumPad.numPadLayer = NUMPAD;

  // We configure the AlphaSquare effect to use RED letters
  //AlphaSquare.color = { 255, 0, 0 };

  // We set the brightness of the rainbow effects to 150 (on a scale of 0-255)
  // This draws more than 500mA, but looks much nicer than a dimmer effect
  //LEDRainbowEffect.brightness(150);
  //LEDRainbowWaveEffect.brightness(150);

  // The LED Stalker mode has a few effects. The one we like is
  // called 'BlazingTrail'. For details on other options,
  // see https://github.com/keyboardio/Kaleidoscope-LED-Stalker
  //StalkerEffect.variant = STALKER(BlazingTrail);

  // We want the keyboard to be able to wake the host up from suspend.
//   HostPowerManagement.enableWakeup();

  // We want to make sure that the firmware starts with LED effects off
  // This avoids over-taxing devices that don't have a lot of power to share
  // with USB devices
  //LEDOff.activate();
}

/** loop is the second of the standard Arduino sketch functions.
  * As you might expect, it runs in a loop, never exiting.
  *
  * For Kaleidoscope-based keyboard firmware, you usually just want to
  * call Kaleidoscope.loop(); and not do anything custom here.
  */

void loop() {
  Kaleidoscope.loop();
}

#define NG_KEY_1 3, 7
#define NG_KEY_2 3, 8

#define PPG_KLS_KEYPOS(KEY_ALIAS, S) PPG_KLS_KEYPOS_HEX(KEY_ALIAS, S)

#define NG_TEST_KEY_1(S)               PPG_KLS_KEYPOS(NG_KEY_1, S)
#define NG_TEST_KEY_2(S)               PPG_KLS_KEYPOS(NG_KEY_2, S)

#define PPG_KLS_MATRIX_POSITION_INPUTS_ALPHABETIC(OP) \
__NL__      OP(NG_TEST_KEY_1) \
__NL__      OP(NG_TEST_KEY_2)

// Define a set of Papageno inputs that are associated with
// keyboard matrix positions.
//
// Important: - The macro must be named PPG_KLS_MATRIX_POSITION_INPUTS!
//            - If no inputs are supposed to be associated with
//              matrix positions, define an empty PPG_KLS_MATRIX_POSITION_INPUTS
//
#define PPG_KLS_MATRIX_POSITION_INPUTS(OP) \
\
__NL__      PPG_KLS_MATRIX_POSITION_INPUTS_ALPHABETIC(OP)

// Define a set of Papageno inputs that are associated with
// qmk keycodes.
//
// Important: - The macro must be named PPG_KLS_KEYCODE_INPUTS!
//            - If no inputs are supposed to be associated with
//              keycodes, define an empty PPG_KLS_KEYCODE_INPUTS
//
#define PPG_KLS_KEYCODE_INPUTS(OP)

// Initialize Papageno data structures for qmk
// This is based on the definitions of 
//
//    PPG_KLS_MATRIX_POSITION_INPUTS
//
// and
//
//    PPG_KLS_KEYCODE_INPUTS
//
PPG_KLS_INIT_DATA_STRUCTURES

void papageno_setup()
{
   PPG_KLS_INIT
   
   // Only list symbols here that are required after initialization
   //
   // Note: The functions passed as PPG_Leader_Functions are only required
   //       during setup.
   // 
   //PPG_KLS_COMPRESSION_REGISTER_SYMBOLS(NG_PPG_SYMBOLS)
   
   kaleidoscope::papageno::Papageno::setTimeoutMillis(200);
   
//    ppg_logging_set_enabled(true);

   PPG_KLS_KEYPOS_CLUSTER_ACTION_KEYCODE(
      0, // Layer
      (Key_Enter),
      NG_TEST_KEY_1,
      NG_TEST_KEY_2
   );

   PPG_KLS_COMPILE
}
