#define FUNCONF_SYSTICK_USE_HCLK 1
#include "ch32v003fun.h"
#define WS2812BSIMPLE_IMPLEMENTATION
#include "ws2812b_simple.h"

#define NUM_PIXELS 14
#define LED_PIN    0        // change to match your data pin
#define LED_PORT   GPIOC    // change to match your data port

// Byte order is G, R, B (matches your original {0x00, 0xFF, 0x00} = green example)
#define YELLOW  0xFF, 0xFF, 0x00   // G, R, B
#define WHITE   0xFF, 0xFF, 0xFF
#define ORANGE  0x8C, 0xFF, 0x00   // approx RGB(255,140,0)
#define OFF     0x00, 0x00, 0x00
#define BRIGHTNESS 64

uint8_t leds[NUM_PIXELS * 3];

__attribute__((noinline)) void busywait(int x) {
    for (volatile int i = 0; i < x; i++) {
    }
}

static inline uint8_t scale8(uint8_t val, uint8_t scale) {
    return ((uint16_t)val * (uint16_t)scale) >> 8;
}

void set_pixel(int index, uint8_t g, uint8_t r, uint8_t b) {
    leds[index * 3 + 0] = scale8(g, BRIGHTNESS);
    leds[index * 3 + 1] = scale8(r, BRIGHTNESS);
    leds[index * 3 + 2] = scale8(b, BRIGHTNESS);
}

void fill(uint8_t g, uint8_t r, uint8_t b) {
    for (int i = 0; i < NUM_PIXELS; i++) {
        set_pixel(i, g, r, b);
    }
}

void show(void) {
    WS2812BSimpleSend(LED_PORT, LED_PIN, leds, sizeof(leds));
}

void color_chase(uint8_t g, uint8_t r, uint8_t b, int wait_ms) {
    fill(OFF);
    for (int i = 0; i < NUM_PIXELS; i++) {
        set_pixel(i, g, r, b);
        show();
        Delay_Ms(wait_ms);
    }
    Delay_Ms(500);
}

// Cycles smoothly between yellow -> white -> orange -> back to yellow
void warm_cycle(int wait_ms) {
    // yellow -> white
    for (int step = 0; step <= 255; step += 5) {
        uint8_t g = 255;
        uint8_t r = 255;
        uint8_t b = step;
        fill(g, r, b);
        show();
        Delay_Ms(wait_ms);
    }
    // white -> orange
    for (int step = 0; step <= 255; step += 5) {
        uint8_t g = 255 - ((step * (255 - 140)) / 255);
        uint8_t r = 255;
        uint8_t b = 255 - step;
        fill(g, r, b);
        show();
        Delay_Ms(wait_ms);
    }
    // orange -> yellow
    for (int step = 0; step <= 255; step += 5) {
        uint8_t g = 140 + ((step * (255 - 140)) / 255);
        uint8_t r = 255;
        uint8_t b = 0;
        fill(g, r, b);
        show();
        Delay_Ms(wait_ms);
    }
}

int main()
{
    SystemInit();

    while (1) {
        fill(ORANGE);
        show();
        Delay_Ms(1000);
    }
}
