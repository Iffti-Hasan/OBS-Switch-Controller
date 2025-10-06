#include <BleKeyboard.h>

BleKeyboard bleKeyboard("OBSSwitch", "ESP32", 100);

// GPIO pins for 10 buttons
const int buttonPins[10] = {4, 5, 12, 13, 14, 15, 16, 17, 18, 19};
bool buttonStates[10] = {false};
unsigned long lastDebounceTime[10] = {0};
const unsigned long debounceDelay = 50;

// LED Pins
const int RED_LED = 21;
const int YELLOW_LED = 22;
const int GREEN_LED = 23;

bool wasConnected = false;

void setup() {
  Serial.begin(115200);
  Serial.println("Starting OBSSwitch BLE Keyboard...");

  // Setup button pins
  for (int i = 0; i < 10; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }

  // Setup LED pins
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

  // All LEDs off initially
  digitalWrite(RED_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(GREEN_LED, LOW);

  bleKeyboard.begin();
}

void loop() {
  bool isConnected = bleKeyboard.isConnected();

  // Handle Green LED on connection
  if (isConnected && !wasConnected) {
    Serial.println("Bluetooth Connected");
    digitalWrite(GREEN_LED, HIGH);
  } else if (!isConnected && wasConnected) {
    Serial.println("Bluetooth Disconnected");
    digitalWrite(GREEN_LED, LOW);
  }
  wasConnected = isConnected;

  if (isConnected) {
    unsigned long currentTime = millis();

    for (int i = 0; i < 10; i++) {
      bool pressed = digitalRead(buttonPins[i]) == LOW;

      if (pressed != buttonStates[i] && (currentTime - lastDebounceTime[i]) > debounceDelay) {
        lastDebounceTime[i] = currentTime;
        buttonStates[i] = pressed;

        if (pressed) {
          handleShortcut(i);
        }
      }
    }
  }

  delay(10);
}

void handleShortcut(int index) {
  switch (index) {
    case 0:  // Start/Stop Streaming
      Serial.println("Start/Stop Streaming — Ctrl + Shift + S");
      bleKeyboard.press(KEY_LEFT_CTRL);
      bleKeyboard.press(KEY_LEFT_SHIFT);
      bleKeyboard.press('s');
      delay(100);
      bleKeyboard.releaseAll();
      toggleLED(RED_LED);
      break;

    case 1:  // Start/Stop Recording
      Serial.println("Start/Stop Recording — Ctrl + Shift + R");
      bleKeyboard.press(KEY_LEFT_CTRL);
      bleKeyboard.press(KEY_LEFT_SHIFT);
      bleKeyboard.press('r');
      delay(100);
      bleKeyboard.releaseAll();
      toggleLED(RED_LED);
      break;

    case 2:  // Pause/Resume Recording
      Serial.println("Pause/Resume Recording — Ctrl + Shift + P");
      bleKeyboard.press(KEY_LEFT_CTRL);
      bleKeyboard.press(KEY_LEFT_SHIFT);
      bleKeyboard.press('p');
      delay(100);
      bleKeyboard.releaseAll();
      toggleLED(YELLOW_LED);
      break;

    case 3:  // Mute/Unmute Audio Input Capture
      Serial.println("Mute/Unmute Audio Input Capture — Ctrl + Shift + A");
      bleKeyboard.press(KEY_LEFT_CTRL);
      bleKeyboard.press(KEY_LEFT_SHIFT);
      bleKeyboard.press('a');
      delay(100);
      bleKeyboard.releaseAll();
      break;

    case 4:  // Mute/Unmute Microphone
      Serial.println("Mute/Unmute Microphone — Ctrl + Shift + M");
      bleKeyboard.press(KEY_LEFT_CTRL);
      bleKeyboard.press(KEY_LEFT_SHIFT);
      bleKeyboard.press('m');
      delay(100);
      bleKeyboard.releaseAll();
      break;

    case 5:  // Mute/Unmute Desktop Audio
      Serial.println("Mute/Unmute Desktop Audio — Ctrl + Shift + D");
      bleKeyboard.press(KEY_LEFT_CTRL);
      bleKeyboard.press(KEY_LEFT_SHIFT);
      bleKeyboard.press('d');
      delay(100);
      bleKeyboard.releaseAll();
      break;

    case 6:  // Take Screenshot
      Serial.println("Take Screenshot of Output — Shift + S");
      bleKeyboard.press(KEY_LEFT_SHIFT);
      bleKeyboard.press('s');
      delay(100);
      bleKeyboard.releaseAll();
      break;

    case 7:  // Show/Hide Display Capture
      Serial.println("Show/Hide Display Capture — Shift + D");
      bleKeyboard.press(KEY_LEFT_SHIFT);
      bleKeyboard.press('d');
      delay(100);
      bleKeyboard.releaseAll();
      break;

    case 8:  // Show/Hide Video Capture
      Serial.println("Show/Hide Video Capture — Shift + V");
      bleKeyboard.press(KEY_LEFT_SHIFT);
      bleKeyboard.press('v');
      delay(100);
      bleKeyboard.releaseAll();
      break;

    case 9:  // Open OBS Studio
      Serial.println("Open OBS Studio — Ctrl + Shift + O");
      bleKeyboard.press(KEY_LEFT_CTRL);
      bleKeyboard.press(KEY_LEFT_SHIFT);
      bleKeyboard.press('o');
      delay(100);
      bleKeyboard.releaseAll();
      break;
  }
}

// Toggle a given LED pin
void toggleLED(int pin) {
  digitalWrite(pin, !digitalRead(pin));
}
