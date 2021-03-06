// By Korey Conway and Tanzeel Rana

#include <hcs12dp256.h>

#define	STEPPER_DELAY				0XF000
#define STEPPER_STEPS_PER_QUARTER	5
#define STEPPER_STEPS_PER_TURN		STEPPER_STEPS_PER_QUARTER*4

static void stepper_init(void);
void stepper_turn_cw(int steps);
void stepper_turn_ccw(int steps);
static void stepper_set_step(int step);
static void stepper_delay(unsigned int delay);

/*
	Turn clock-wise a given number of steps
*/
void stepper_turn_cw(int steps)
{
	stepper_init();
	for ( ; steps > 0; steps-- ) {
		stepper_set_step(3 - (steps % 4));
	}
}

/*
	Turn clock-wise a given number of steps
*/
void stepper_turn_ccw(int steps)
{
	stepper_init();
	for ( ; steps > 0; steps-- ) {
		stepper_set_step(steps % 4);
	}
}

/*
	Perform a step (used internally)
*/
static void stepper_set_step(int step)
{
	int coded_step = 0;
	
	// Get the coded step value for this step
	if ( step == 2 ) {
		coded_step = 3;
	} else if ( step == 3 ) {
		coded_step = 2;
	} else {
		coded_step = step;
	}

	// Set the bits in port T
	PTT = (PTT & ~0x60) | (coded_step << 5);
	
	//printf("Instruction: %X\nShifted Instruction: %X\nPTT: %X\n\n", instruction, shifted_instruction, PTT);
	
	// Delay to allow enough time for the step to take place
	stepper_delay(STEPPER_DELAY);
} 

/*
	Initialize ports for the stepper motor
*/
static void stepper_init()
{
	DDRP |= 0x20; // Enable output for the enable bit
	DDRT |= 0x60; // Enable output to the stepper motor
	PTP  |= 0x20; // Enable the stepper motor
}

/*
	Add delays for the stepper, based on given parameter
*/
static void stepper_delay(unsigned int delay)
{
	for ( ; delay > 0 ; delay-- ) {}
}
