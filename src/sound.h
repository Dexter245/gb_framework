#ifndef SOUND_H_
#define SOUND_H_

#include <gb/gb.h>

//ranges:
//length: 0-63
//volume: 0-15
//envInc: 0-1, 0=decrease, 1=increase
//envIntensity: 0-7
//freqNum: 0-2047
//frequency: ~ 1-18k
//sweepTime: 0-7
//freqDec: 0-1, 1=frequency decreases, 0=increases
//sweepIntensity: 0-7
//shiftClFreq: 0-15
//counterStepWidth: 0-1
//divRatio: 0-7

void initialize_sound();


void sound2(UINT8 volume, UINT16 frequency);
void sound2_envelope(UINT8 volume, UINT16 frequency,
        UINT8 envInc, UINT8 envIntensity);
void sound2_length(UINT8 volume, UINT16 frequency, UINT8 length);
void sound2_envelope_length(UINT8 volume, UINT16 frequency,
        UINT8 envInc, UINT8 envIntensity, UINT8 length);


void sound1(UINT8 volume, UINT16 frequency);
void sound1_sweep(UINT8 volume, UINT16 frequency,
        UINT8 sweepTime, UINT8 freqDec, UINT8 sweepIntensity);

void sound1_envelope(UINT8 volume, UINT16 frequency,
        UINT8 envInc, UINT8 envIntensity);
void sound1_envelope_sweep(UINT8 volume, UINT16 frequency,
        UINT8 envInc, UINT8 envIntensity,
        UINT8 sweepTime, UINT8 freqDec, UINT8 sweepIntensity);

void sound1_length(UINT8 volume, UINT16 frequency, UINT8 length);
void sound1_length_sweep(UINT8 volume, UINT16 frequency, UINT8 length,
        UINT8 sweepTime, UINT8 freqDec, UINT8 sweepIntensity);

void sound1_envelope_length(UINT8 volume, UINT16 frequency,
        UINT8 envInc, UINT8 envIntensity, UINT8 length);
void sound1_envelope_length_swee(UINT8 volume, UINT16 frequency,
        UINT8 envInc, UINT8 envIntensity, UINT8 length,
        UINT8 sweepTime, UINT8 freqDec, UINT8 sweepIntensity);


void sound4(UINT8 volume, UINT8 shiftClFreq, UINT8 counterStepWidth,
        UINT8 divRatio);
void sound4_length(UINT8 volume, UINT8 shiftClFreq, UINT8 counterStepWidth,
        UINT8 divRatio, UINT8 length);
void sound4_envelope(UINT8 volume, UINT8 shiftClFreq, UINT8 counterStepWidth,
        UINT8 divRatio, UINT8 envInc, UINT8 envIntensity);
void sound4_envelope_length(UINT8 volume, UINT8 shiftClFreq,
        UINT8 counterStepWidth, UINT8 divRatio,
        UINT8 envInc, UINT8 envIntensity,
        UINT8 length);



#endif
