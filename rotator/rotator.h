/*
 * rotator.h
 *
 * Created: 23.02.2016 19:38:45
 *  Author: UB4LAG Vasily Afanasyev
 */ 


#ifndef ROTATOR_H_
#define ROTATOR_H_

#define UART_UBRR 416 /* 1200 bps at 8MHz (0.2% error) */
#define TOP_TIMER2 249 /* 2mS at 8000000/64 */
#define KEY_HOLD_T 255U

#define ANGLE_MAX 450U
#define ANGLE_FULL_CIRCLE 360U
#define ANGLE_NORTH 45U /* 0-45 */
#define ANGLE_EAST ANGLE_NORTH + 90U
#define ANGLE_SOUTH ANGLE_EAST + 90U
#define ANGLE_WEST ANGLE_SOUTH + 90U

#define SetBit(port,bit) port |=  _BV(bit)
#define ClrBit(port,bit) port &= ~_BV(bit)
#define Port4Out(port,bit) port |=  _BV(bit)
#define Port4Inp(port,bit) port &= ~_BV(bit)
#define Bit(bit) _BV(bit)

#define LED PINB5
#define LED_PIN PINB
#define LED_PORT PORTB
#define LED_DDR DDRB

#define R_NORTH PIND2
#define R_NORTH_PIN PIND
#define R_NORTH_PORT PORTD
#define R_NORTH_DDR DDRD

#define R_EAST PIND3
#define R_EAST_PIN PIND
#define R_EAST_PORT PORTD
#define R_EAST_DDR DDRD

#define R_SOUTH PIND4
#define R_SOUTH_PIN PIND
#define R_SOUTH_PORT PORTD
#define R_SOUTH_DDR DDRD

#define R_WEST PIND5
#define R_WEST_PIN PIND
#define R_WEST_PORT PORTD
#define R_WEST_DDR DDRD

#define KEY_NORTH PIND6
#define KEY_NORTH_PIN PIND
#define KEY_NORTH_PORT PORTD
#define KEY_NORTH_DDR DDRD

#define KEY_EAST PIND7
#define KEY_EAST_PIN PIND
#define KEY_EAST_PORT PORTD
#define KEY_EAST_DDR DDRD

#define KEY_SOUTH PINB0
#define KEY_SOUTH_PIN PINB
#define KEY_SOUTH_PORT PORTB
#define KEY_SOUTH_DDR DDRB

#define KEY_WEST PINB1
#define KEY_WEST_PIN PINB
#define KEY_WEST_PORT PORTB
#define KEY_WEST_DDR DDRB

typedef struct
{
	uint32_t	quot;
	uint8_t		rem;
}divmod10_t;

enum Directions {north, east, south, west, disconnect};

enum Errors {err_azimuth_invalid_range, err_bad_command, err_bad_digits};

void ioinit(void);
void uart_send(char);
void uart_send_hex_byte(uint8_t);
void uart_send_pstr(const char *);
void uart_send_error(enum Errors);
void tick_2ms(void);
uint8_t get_key(void);
void ant_switch(enum Directions);
enum Directions def_direction(uint16_t);
uint32_t str_to_num_ul(char *);
void azimuth_find(char);

#endif /* ROTATOR_H_ */