// UART Code

#ifndef UART_H_
#define UART_H_

#define BRW_VAL 13 // Calculated values for SMCLK = 24MHz and 115200 baud rate
#define BRF_VAL 0
#define BRS_VAL 0x25

#define PUART P1 // UART port: P1
#define RX BIT2 // RX: P1.2
#define TX BIT3 // TX: P1.3
#define NULL '\0' // Null character to indicate end of phrase
#define ESC 0x1B // Escape code to enable escape commands
#define BOLD "[1m" // Bold font
#define TOPLEFT "[H" // Moves cursor to the top left of the screen
#define GREEN "[32m" // Green font
#define LEFT "[100D" // Make value large enough such that cursor will always move to the very left of the terminal screen
#define NEWLINE "[1B" // Skips line on terminal
#define WHITE "[37m" // White font
#define CLEARSCREEN "[2J" // Clears the entire terminal screen
#define CLEARDOWN "[0J" // Clears the terminal screen from the cursor down

void UART_init(void); // Define UART.c functions
void UART_print(char write_string[]);
void UART_esc_code(char write_string[]);

#endif /* UART_H_ */
