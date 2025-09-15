#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "driverlib/debug.h"
#include "driverlib/fpu.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom.h"
#include "driverlib/rom_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"

void UARTIntHandler(void) {}

void UARTSend(const uint8_t *pui8Buffer, uint32_t ui32Count) {}

// UART Module 0 UORx -> PA0
// UART Module 0 U0Tx -> PA1

void UARTInit(void){

    // Enable UART 0 module and also enable GPIO A since UART 0 is connected to GPIO A
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);

    // Configure GPIO pins for UART

    // By default GPIO pins are set up for digital function. Alternate functions need to be set using GPIOPinConfigure
    // Alternate functions include ADC, PWM, UART
    GPIOPinConfigure(GPIO_PA0_U0RX);
    GPIOPinConfigure(GPIO_PA1_U0TX);

    GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);

    // Configure UART (baud rate, start/top bit, etc)
    // Baud rate = 115200
    // Config: WLEN = 8 word length 8 bit, STOP_ONE = use one bit to indicate stop (use 2 for high speed communication)
    // PAR_EVEN = use even parity
    UARTConfigSetExpClk(UART0_BASE, SysCtlClockGet(), 115200, 
    (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_EVEN));

}

void UARTPrint(const char *message){
    while(*message != '\0'){
        UARTCharPut(UART0_BASE, *message);
        message++;
    }
}


int main(void)
{
    // Set clock
    SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_OSC | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);

    // Initialize UART module
    UARTInit();
    
    while(1)
    {   
        // Print a message via UART
        UARTPrint("Hello World \r\n");
        SysCtlDelay(1600000);
    }
}

