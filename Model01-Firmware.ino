// -*- mode: c++ -*-
// Copyright 2016 Keyboardio, inc. <jesse@keyboard.io>
// See "LICENSE" for license details

#ifndef BUILD_INFORMATION
#define BUILD_INFORMATION "locally built"
#endif

// The Kaleidoscope core
#include "Kaleidoscope.h"

// #include <kaleidoscope/hid.h>

// // Support for papageno features
// #define KALEIDOSCOPE_PAPAGENO_POSTPONE_INITIALIZATION
// #include "Kaleidoscope-Papageno.h"

// Support for keys that move the mouse
// #include "Kaleidoscope-MouseKeys.h"

#include <Kaleidoscope-Qukeys.h>

// Support for macros
#include "Kaleidoscope-Macros.h"

// Support for controlling the keyboard's LEDs
#include "Kaleidoscope-LEDControl.h"

#include "Kaleidoscope-LED-ActiveModColor.h"
#include <Kaleidoscope-LED-ActiveLayerColor.h>

// Support for an "LED off mode"
#include "LED-Off.h"

// #include "Kaleidoscope-OneShot.h"

// Support for the "Boot greeting" effect, which pulses the 'LED' button for 10s
// when the keyboard is connected to a computer (or that computer is powered on)
#include "Kaleidoscope-LEDEffect-BootGreeting.h"

enum { MACRO_VERSION_INFO,
       MACRO_ANY,
       MACRO_SEARCH_WORD_UNDER_CURSOR,
       MACRO_FILE_SEARCH
     };

enum { NORMAN, M1, M2, M3, M4 }; // layers

const Key keymaps[][ROWS][COLS] PROGMEM = {

  [NORMAN] = KEYMAP_STACKED
  (___,  ___,   ___, ___, ___,      ___,      LCTRL(Key_X),
   ___,      Key_Q,         Key_W,       Key_D,       Key_F,    Key_K,    LCTRL(Key_C),
   ___,      Key_A,         Key_S,       Key_E,       Key_T,    Key_G, // home row
   ___,Key_Z,         Key_X,       Key_C,       Key_V,    Key_B,    LCTRL(Key_V),
   Key_Escape,          Key_Backspace, Key_Enter, LCTRL(Key_F),
   RightAlt,

   ___,          ___,           ___,         ___, ___,     ___, ___,
   ___,          Key_J,         Key_U,       Key_R,       Key_L,    Key_Semicolon, ___,
                 Key_Y,         Key_N,       Key_I,       Key_O,    Key_H,    ___,
   ___,          Key_P,         Key_M,       Key_Comma,   Key_Period,Key_Slash,___,
   Key_Tab,          OSL(M1),      Key_Space,    ___,
   RightAlt),
   
   [M1] = KEYMAP_STACKED
   (___,         ___,           ___,         ___,         ___,      ___,      ___,
    ___,         LSHIFT(Key_2),        LSHIFT(Key_Minus), Key_LeftBracket, Key_RightBracket, LSHIFT(Key_6), ___,
    ___,         Key_Backslash, Key_Backtick,   LSHIFT(Key_LeftBracket), LSHIFT(Key_RightBracket), LSHIFT(Key_8),
    ___,         LSHIFT(Key_3),      LSHIFT(Key_Backtick),   Key_Pipe,    LSHIFT(Key_4), RALT(Key_5), ___,
    ___,         ___,           ___,         M(MACRO_SEARCH_WORD_UNDER_CURSOR),        
    ___,
    
    ___,         ___,           ___,         ___,         ___,      ___,      ___,
    ___,         LSHIFT(Key_1), LSHIFT(Key_Comma),  LSHIFT(Key_Period),    Key_Equals, LSHIFT(Key_7), ___,
                 LSHIFT(Key_Slash), LSHIFT(Key_9), LSHIFT(Key_0), Key_Minus, LSHIFT(Key_Semicolon), ___,
    ___,         LSHIFT(Key_Equals),      LSHIFT(Key_5), LSHIFT(Key_Quote), Key_Quote, Key_Semicolon, ___,
    LCTRL(LSHIFT(I)),         ___,           ___,         ___,
    ___),
    
    
   [M2] = KEYMAP_STACKED
   (___,         ___,           ___,         ___,         ___,      ___,      ___,
    ___,         Key_PageUp,    Key_Backspace, Key_UpArrow,    Key_Delete,  Key_PageDown, ___,
    ___,         Key_Home,      Key_LeftArrow,    Key_DownArrow,    Key_RightArrow, Key_End,
    ___,         XXX,       Key_Tab,     XXX,     Key_Enter, XXX, ___,
    ___,         ___,           ___,         M(MACRO_FILE_SEARCH),
    ___,
    
    ___,         ___,           ___,         ___,         ___,      ___,      ___,
    ___,         XXX,       Key_7,       Key_8,       Key_9,    XXX,  ___,
                 XXX,       Key_4,       Key_5,       Key_6,    Key_Period,___,
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
    ___,         XXX,       Key_F7,      Key_F8,      Key_F9,   Key_F12,  ___,
                 XXX,        Key_F4,      Key_F5,      Key_F6,   Key_F11,  ___,
    ___,         XXX,        Key_F1,      Key_F2,      Key_F3,   Key_F10,  ___,   
    ___,         ___,           ___,         ___,
    ___) 
    
   [M4] = KEYMAP_STACKED
   (___,         ___,           ___,         ___,         ___,      ___,      ___,
    ___,         ___,           ___,         ___,         ___,      ___,      ___,
    ___,         ___,           RALT(Key_S),         RALT(Key_A),         ___,      ___,    
    ___,         ___,           ___,         ___,         ___,      ___,      ___,
    ___,         ___,           ___,         ___,
    ___,
    
    ___,         ___,           ___,         ___,         ___,      ___,      ___,
    ___,         ___,           ___,         ___,         ___,      ___,      ___,
                 ___,           ___,         RALT(Key_U),         RALT(Key_O),      ___,      ___,
    ___,         ___,           ___,         ___,         ___,      ___,      ___,   
    ___,         ___,           ___,         ___,
    ___) 

};

static void versionInfoMacro(uint8_t keyState) {
  if (keyToggledOn(keyState)) {
    Macros.type(PSTR("Keyboardio Model 01 - Kaleidoscope "));
    Macros.type(PSTR(BUILD_INFORMATION));
  }
}

const macro_t *macroAction(uint8_t macroIndex, uint8_t keyState) {
  switch (macroIndex) {

  case MACRO_VERSION_INFO:
    versionInfoMacro(keyState);
    break;
   }
  return MACRO_NONE;
}

KALEIDOSCOPE_INIT_PLUGINS(
   Qukeys, 
   Macros, 
   ActiveLayerColor,
   BootGreetingEffect,
   ActiveModColor
);

/** The 'setup' function is one of the two standard Arduino sketch functions.
  * It's called when your keyboard first powers up. This is where you set up
  * Kaleidoscope and any plugins.
  */

void setup() {
    
   static const cRGB layerColormap[] PROGMEM = {
      CRGB(0, 0, 0),
      CRGB(255, 0, 0),
      CRGB(0, 255, 0),
      CRGB(0, 0, 255),
      CRGB(255, 255, 0)
   };
   
   LEDActiveLayerColorEffect.setColormap(layerColormap);
   
   ActiveModColorEffect.highlight_color = CRGB(200, 200, 200);
  
   QUKEYS(
      
      // Both Hands have the modifier keys in the home-row (axis-symmetric)
      
      kaleidoscope::plugin::Qukey(0, 2, 1, Key_LeftGui),
      kaleidoscope::plugin::Qukey(0, 2, 2, Key_LeftAlt),
      kaleidoscope::plugin::Qukey(0, 2, 3, Key_LeftControl),
      kaleidoscope::plugin::Qukey(0, 2, 4, Key_LeftShift),

      kaleidoscope::plugin::Qukey(0, 2, 14, Key_RightGui),
      kaleidoscope::plugin::Qukey(0, 2, 13, Key_RightAlt),
      kaleidoscope::plugin::Qukey(0, 2, 12, Key_RightControl),
      kaleidoscope::plugin::Qukey(0, 2, 11, Key_RightShift),
            
      kaleidoscope::plugin::Qukey(0, 3, 4, ShiftToLayer(1)),  
      kaleidoscope::plugin::Qukey(0, 3, 3, ShiftToLayer(2)),  
      kaleidoscope::plugin::Qukey(0, 3, 2, ShiftToLayer(3)),
      kaleidoscope::plugin::Qukey(0, 3, 11, ShiftToLayer(1)),  
      kaleidoscope::plugin::Qukey(0, 3, 12, ShiftToLayer(2)),  
      kaleidoscope::plugin::Qukey(0, 3, 13, ShiftToLayer(3))   
   )
   Qukeys.setTimeout(200);
   Qukeys.setReleaseDelay(20);

   Kaleidoscope.setup();
}

// void loop() {
//   Papageno.loop();
// }

inline
void pressKey(const Key &k) {
   handleKeyswitchEvent(k, UNKNOWN_KEYSWITCH_LOCATION, IS_PRESSED);
   kaleidoscope::hid::sendKeyboardReport();
}

inline
void releaseKey(const Key &k) {
   handleKeyswitchEvent(k, UNKNOWN_KEYSWITCH_LOCATION, WAS_PRESSED);
   kaleidoscope::hid::sendKeyboardReport();
}

inline 
void tapKey(const Key &k) {
   pressKey(k);
   releaseKey(k);
}


/*
#define NG_CALLBACK_NO_REPEAT \
   if(activation_flags & PPG_Action_Activation_Flags_Repeated) { return; }
   
#define NG_CALLBACK_ONLY_ACTIVATION \
   if(!(activation_flags & PPG_Action_Activation_Flags_Active)) { return; }
   
// User callback the emulates double tab for
// shell auto completion
//
void doubleTabCB(PPG_Count activation_flags, void *user_data)
{
   NG_CALLBACK_NO_REPEAT
   NG_CALLBACK_ONLY_ACTIVATION
   
   tapKey(Key_Tab);
   tapKey(Key_Tab);
}

// User callback that repeats the most recent shell
// command
//
void repeatLastCommandCB(PPG_Count activation_flags, void *user_data)
{
   NG_CALLBACK_NO_REPEAT
   NG_CALLBACK_ONLY_ACTIVATION
   
   tapKey(Key_UpArrow);
   tapKey(Key_Enter);
}

// Issues a search command that can be used with
// any editor that is configured in a way that F1
// opens the search entry with the string that the cursor
// currently rests on.
//
void ordinarySearchCB(PPG_Count activation_flags, void *user_data)
{
   NG_CALLBACK_NO_REPEAT
   NG_CALLBACK_ONLY_ACTIVATION
   
   tapKey(LCTRL(Key_F));
   tapKey(Key_Enter);
}
*/

const macro_t *macroAction(uint8_t macro_index, uint8_t key_state) {
  
   switch (macro_index) {
  }
  return MACRO_NONE;
}


// Similar the search callback above, but for a search
// in multiple files. This works with editors
// that have been customized to feature Shift+F1
// as command to open the search-in-files menu.
//
const macro_t *macroAction(uint8_t macro_index, uint8_t key_state) {
  
   switch (macro_index) {
      case MACRO_SEARCH_WORD_UNDER_CURSOR:
         tapKey(LCTRL(Key_LeftArrow));
         tapKey(LCTRL(LSHIFT(Key_RightArrow));
         tapKey(LCTRL(Key_F));
         tapKey(Key_Enter);
         break;
      case MACRO_FILE_SEARCH:
         tapKey(LSHIFT(Key_F1));
         tapKey(Key_Enter);
         break;
  }
  return MACRO_NONE;
}

/*
void umlautCB(PPG_Count activation_flags, void *user_data)
{
//    NG_CALLBACK_NO_REPEAT
   
   Key k;
   k.raw = (uint16_t)user_data;
   
   PPG_LOG("umlautCB\n")
   
   // Note, as we might be dealing with one-shot shift, we cannot
   // inject the keys (as one-shot does not deal with injected stuff)
   //
   if(activation_flags & PPG_Action_Activation_Flags_Active) {
      handleKeyswitchEvent(RALT(k), UNKNOWN_KEYSWITCH_LOCATION, IS_PRESSED);
   }
   else {    
      PPG_LOG("releasing umlaut\n") 
      handleKeyswitchEvent(RALT(k), UNKNOWN_KEYSWITCH_LOCATION, WAS_PRESSED);
   }
}

void rebootCB(PPG_Count activation_flags, void *user_data)
{
   #ifndef ARDUINO_VIRTUAL
   KeyboardHardware.rebootBootloader();
   #endif 
}

// TODO: Add a mode of operation where Papageno only tracks events
//       but passes them on instead of swallowing them.

// TODO: Enable Glockenspiel optimization flags by default.

extern "C" {
#include "Kaleidoscope-Papageno-Sketch.hpp"
}*/
