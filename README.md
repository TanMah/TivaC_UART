# 🔴🟢🔵 UART Project (Tiva C LaunchPad)

This is a simple embedded C project for the **Tiva C Series TM4C123GXL LaunchPad** that blinks the onboard **red, green, and blue LEDs** using the TivaWare peripheral driver library.

---

## 🚀 Features

- Blinks the onboard RGB LEDs sequentially.
- Demonstrates use of `GPIOPinWrite()` and `GPIOPinTypeGPIOOutput()` from TivaWare.
- Includes a reusable `blinkColor()` function that takes a character input (`'r'`, `'g'`, `'b'`) to control individual LEDs.

---

## ⚙️ Technical Overview/Steps

The Tiva C Series TM4C123GXL LaunchPad connects its onboard RGB LED to Port F pins:

| LED Color | Pin on MCU | GPIO Pin     | Notes      |
| --------- | ---------- | ------------ | ---------- |
| Red       | PF1        | GPIO\_PIN\_1 | Active low |
| Blue      | PF2        | GPIO\_PIN\_2 | Active low |
| Green     | PF3        | GPIO\_PIN\_3 | Active low |

insert pic

### UART Protocol
- UART - Universal Asynchronous Receiver-Transmitter protocol
- It is a simple, serial, device-to-device communication, using two main wires for data (TX and RX) and a common ground connection. 
- UART supports simplex, half-duplex and full-duplex communication, allowing simultaneous two-way data transfer.
- It is "asynchronous" because it doesn't use a separate clock line; instead, both devices must agree on a shared baud rate (data speed) and use start bits, stop bits, and an optional parity bit to synchronize data transmission.
- A FIFO (first-in-first-out) buffer in UART is a hardware implemented queue of received or transmitted data.

insert pic

- Tiva C has 8 UART modules
- Programmable baud generator allows up to 5 Mbps (divide by 16) for regular speeds and 10 Mbps (divide by 8) for high speed.
- FIFO can trigger interrupts when buffer is 1/8 or 1/4 or 1/2 or 3/4 or 7/8th full.
- Payload can be programmed to be 5or 6 or 7 or 8 bits.
- Even/Odd or no parity generation.

1. Provide clock to the clock gating circuit of UART 0.
2. Provide clock to the clock gating circuit of GPIO Port A module because UART0 is connected to GPIO A.
3. Configure the GPIO pins at TX and RX.
4. Configure UART baud rate, word length, parity bit and stop bit(s).
5. Print a message in TeraTerm console.

## 📦 Requirements

- **Hardware**:  
  - TI Tiva C Series LaunchPad (TM4C123G)
- **Software**:  
  - [TivaWare](https://www.ti.com/tool/SW-TM4C) driver library
  - Code Composer Studio (CCS) or any compatible ARM GCC toolchain

---

## 🔧 Setup & Build Instructions

1. Clone or download this repository.
2. Open the project in **Code Composer Studio**.
3. Make sure **TivaWare** is properly installed and linked.
4. Connect the Tiva C LaunchPad to your PC via USB.
5. Build and flash the code to the board.
6. The RGB LEDs should begin blinking in sequence (Red → Blue → Green), 10 times.

---



