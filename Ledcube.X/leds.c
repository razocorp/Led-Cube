// =============================================================================
// Include statements
// =============================================================================
#include "leds.h"
#include "gpio.h"
#include <xc.h>
#include <stdint.h>
// =============================================================================
// Private type definitions
// =============================================================================

// =============================================================================
// Global variables
// =============================================================================
bool volatile animation_flag = 0;
// =============================================================================
// Private constants
// =============================================================================
typedef enum
{
    UPDOWN = 0
} animation_state_t;
// =============================================================================
// Private variables
// =============================================================================
static uint16_t leds[NBR_OF_LAYERS];
static animation_state_t animation_state;
// =============================================================================
// Private function declarations
// =============================================================================
static uint16_t leds_get_layer(uint8_t layer_nbr);
static void animation_updown();
// =============================================================================
// Public function definitions
// =============================================================================

void leds_init(void) {
    leds[0] = 0x5a5a;
    leds[1] = 0xa5a5;
    leds[2] = 0x5a5a;
    leds[3] = 0xa5a5;
}


void set_lights(uint8_t gate) {
    uint16_t lights = leds_get_layer(gate);
    TRANS_GATE_1 = 0;
    TRANS_GATE_2 = 0;
    TRANS_GATE_3 = 0;
    TRANS_GATE_4 = 0;
    uint16_t a = 1;
    for(uint8_t j = 0; j != 16; ++j){
        SHIFT_REG_CLK = 0;
        SHIFT_REG_DATA = (0u != (lights & (1u << j)));
        SHIFT_REG_CLK = 1;
    }
    SHIFT_REG_LATCH = 1;
    SHIFT_REG_CLK = 0;
    SHIFT_REG_LATCH = 0;
    
    TRANS_GATE_1 = (0 == gate);
    TRANS_GATE_2 = (1 == gate);
    TRANS_GATE_3 = (2 == gate);
    TRANS_GATE_4 = (3 == gate);
}

void update_animation(){
    switch (animation_state){
        case UPDOWN:
            animation_updown();
            break;
    }
}
// =============================================================================
// Private function definitions
// =============================================================================

static uint16_t leds_get_layer(uint8_t layer_nbr) {
    return leds[layer_nbr];
}

static void animation_updown(){
    static uint8_t l = 0;
    for(uint8_t i = 0; i != NBR_OF_LAYERS; ++i){
        if(i == l){
            leds[i] = 0xffff;
        } else {
            leds[i] = 0x0000;
        }
    }
    if(++l == NBR_OF_LAYERS)
        l = 0;   
}