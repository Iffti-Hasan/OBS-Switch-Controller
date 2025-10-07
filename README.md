**<h1>🎛️ OBS Switch Controller</h1>**
*A hardware-based HCI solution designed to simplify and enhance live broadcasting control in OBS Studio using an ESP32 microcontroller.
The OBS Switch Controlle replaces complex keyboard shortcuts with a dedicated hardware interface. It allows streamers to control essential OBS functions such as start/stop streaming, recording, muting audio or switching scenes  all through physical buttons with LED feedback.
This project focuses on Human–Computer Interaction (HCI) principles to improve efficiency, usability and focus during live streaming sessions.*

<p align="center"><kbd>
  <img src="https://github.com/Iffti-Hasan/OBS-Switch-Controller/blob/main/Prototype_Pictures/IMG_5775.jpg" alt="OBS Switch Prototype 1" width="300" height="500" />
  <img src="https://github.com/Iffti-Hasan/OBS-Switch-Controller/blob/main/Prototype_Pictures/IMG_5778.jpg" alt="OBS Switch Prototype 2" width="300" height="400" />
  <img src="https://github.com/Iffti-Hasan/OBS-Switch-Controller/blob/main/Prototype_Pictures/IMG_5766.jpg" alt="OBS Switch Prototype 3" width="300" height="500" />
  <img src="https://github.com/Iffti-Hasan/OBS-Switch-Controller/blob/main/Prototype_Pictures/IMG_5779.jpg" alt="OBS Switch Prototype 4" width="300" height="432" /></kbd>
</p>


## ⚙️ Features
- **10 Physical Buttons** mapped to OBS Studio shortcuts  
- **LED Indicators** for real-time visual feedback  
- **Rechargeable Battery (TP4056 module)** for portability  
- **ESP32 microcontroller** for USB HID control  
- **Simple plug-and-play design** (no extra software needed)

## 🧩 Hardware Components
| Component | Quantity | Description |
|------------|-----------|-------------|
| ESP32 | 1 | Main microcontroller |
| LED Indicators | 3 | Status indicators for power, streaming, and recording |
| Push Buttons | 10 | Control buttons for OBS actions |
| TP4056 | 1 | Lithium battery charging module (Type-C) |
| Li-ion Battery | 1 | Rechargeable power source |
| ON/OFF Switch | 1 | Power control |
| Wires | – | Circuit connections |

---

## 🧮 Button Mapping
| Button | Function | Shortcut |
|--------|-----------|-----------|
| 1 | Start/Stop Streaming | `Ctrl + Shift + S` |
| 2 | Pause/Resume Recording | `Ctrl + Shift + P` |
| 3 | Start/Stop Recording | `Ctrl + Shift + R` |
| 4 | Mute/Unmute Audio Input Capture | `Ctrl + Shift + A` |
| 5 | Mute/Unmute Microphone | `Ctrl + Shift + M` |
| 6 | Mute/Unmute Desktop Audio | `Ctrl + Shift + D` |
| 7 | Show/Hide Display Capture | `Shift + D` |
| 8 | Show/Hide Video Capture | `Shift + V` |
| 9 | Take Screenshot of Output | `Shift + S` |
| 10 | Open OBS Studio | `Ctrl + Shift + O` |


