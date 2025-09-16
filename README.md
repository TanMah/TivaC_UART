# UART Hello World (Tiva C LaunchPad)

This is a simple embedded C project for the **Tiva C Series TM4C123GXL LaunchPad** that sends 'Hello World' message from the board to the computer via the UART module.

---

## ⚙️ Technical Overview/Steps

| Component | Pin on MCU | 
| --------- | ---------- | 
| UART 0    | Port A     | 
| U0 TX     | PA1        | 
| U0 RX     | PA0        |

![alt text](https://github.com/TanMah/TivaC_UART/blob/main/fifo.png "UART FIFO")

### UART Protocol
- UART - Universal Asynchronous Receiver-Transmitter protocol
- It is a simple, serial, device-to-device communication, using two main wires for data (TX and RX) and a common ground connection. 
- UART supports simplex, half-duplex and full-duplex communication, allowing simultaneous two-way data transfer.
- It is "asynchronous" because it doesn't use a separate clock line; instead, both devices must agree on a shared baud rate (data speed) and use start bits, stop bits, and an optional parity bit to synchronize data transmission.
- A FIFO (first-in-first-out) buffer in UART is a hardware implemented queue of received or transmitted data.

![alt text](https://github.com/TanMah/TivaC_UART/blob/main/uart.png "UART Frame")

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
  - Tera Term for serial console







