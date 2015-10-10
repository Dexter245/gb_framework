#include "sound.h"

void initialize_sound(){
    NR50_REG = 0x77;//enable sound on both speakers
    NR51_REG = 0xFF;//enable all sound channels on both speakers
    NR52_REG = 0x80;//enable sound in general
}

//sound 2

void sound2(UINT8 volume, UINT16 frequency){
    sound2_envelope_length(volume, frequency, 0, 0, 64);
}

void sound2_envelope(UINT8 volume, UINT16 frequency,
        UINT8 envInc, UINT8 envIntensity){
    sound2_envelope_length(volume, frequency, envInc, envIntensity, 64);
}

void sound2_length(UINT8 volume, UINT16 frequency, UINT8 length){
    sound2_envelope_length(volume, frequency, 0, 0, length);
}

void sound2_envelope_length(UINT8 volume, UINT16 frequency,
        UINT8 envInc, UINT8 envIntensity, UINT8 length){

    UINT16 freqNum = (UINT16) ( 2048-(131072 / frequency) );

    if(length < 64)
        NR21_REG = 0x80 | (63 - length);
    else
        NR21_REG = 0x80;
    NR22_REG = (volume << 4) | (envInc << 3) | (envIntensity);
    NR23_REG = (UINT8) freqNum;
    if(length < 64)
        NR24_REG = 0x80 | 0x40 | (freqNum >> 8 );
    else
        NR24_REG = 0x80 | 0x00 | (freqNum >> 8 );

}

//sound 1

void sound1(UINT8 volume, UINT16 frequency){
    sound1_envelope_length_swee(volume, frequency,
            0, 0, 64,
            0, 0, 0);
}

void sound1_sweep(UINT8 volume, UINT16 frequency,
        UINT8 sweepTime, UINT8 freqDec, UINT8 sweepIntensity){
    sound1_envelope_length_swee(volume, frequency,
            0, 0, 64,
            sweepTime, freqDec, sweepIntensity);
}


void sound1_envelope(UINT8 volume, UINT16 frequency,
        UINT8 envInc, UINT8 envIntensity){
    sound1_envelope_length_swee(volume, frequency,
            envInc, envIntensity, 64,
            0, 0, 0);
}

void sound1_envelope_sweep(UINT8 volume, UINT16 frequency,
        UINT8 envInc, UINT8 envIntensity,
        UINT8 sweepTime, UINT8 freqDec, UINT8 sweepIntensity){
    sound1_envelope_length_swee(volume, frequency,
            envInc, envIntensity, 64,
            sweepTime, freqDec, sweepIntensity);
}


void sound1_length(UINT8 volume, UINT16 frequency, UINT8 length){
    sound1_envelope_length_swee(volume, frequency,
            0, 0, length,
            0, 0, 0);
}

void sound1_length_sweep(UINT8 volume, UINT16 frequency, UINT8 length,
        UINT8 sweepTime, UINT8 freqDec, UINT8 sweepIntensity){

    sound1_envelope_length_swee(volume, frequency,
            0, 0, length,
            sweepTime, freqDec, sweepIntensity);
}


void sound1_envelope_length(UINT8 volume, UINT16 frequency,
        UINT8 envInc, UINT8 envIntensity, UINT8 length){
    sound1_envelope_length_swee(volume, frequency,
            envInc, envIntensity, length,
            0, 0, 0);
}

void sound1_envelope_length_swee(UINT8 volume, UINT16 frequency,
        UINT8 envInc, UINT8 envIntensity, UINT8 length,
        UINT8 sweepTime, UINT8 freqDec, UINT8 sweepIntensity){

    UINT16 freqNum = (UINT16) ( 2048-(131072 / frequency) );

    NR10_REG = (sweepTime << 4) | (freqDec << 3) | sweepIntensity;

    if(length < 64)
        NR11_REG = 0x80 | (63 - length);
    else
        NR11_REG = 0x80;
    NR12_REG = (volume << 4) | (envInc << 3) | (envIntensity);
    NR13_REG = (UINT8) freqNum;
    if(length < 64)
        NR14_REG = 0x80 | 0x40 | (freqNum >> 8 );
    else
        NR14_REG = 0x80 | 0x00 | (freqNum >> 8 );

}


//sound 4

void sound4(UINT8 volume, UINT8 shiftClFreq, UINT8 counterStepWidth,
        UINT8 divRatio){
    sound4_envelope_length(volume, shiftClFreq, counterStepWidth, divRatio,
            0, 0, 64);
}

void sound4_length(UINT8 volume, UINT8 shiftClFreq, UINT8 counterStepWidth,
        UINT8 divRatio, UINT8 length){
    sound4_envelope_length(volume, shiftClFreq, counterStepWidth, divRatio,
            0, 0, length);
}

void sound4_envelope(UINT8 volume, UINT8 shiftClFreq, UINT8 counterStepWidth,
        UINT8 divRatio, UINT8 envInc, UINT8 envIntensity){
    sound4_envelope_length(volume, shiftClFreq, counterStepWidth,
            divRatio, envInc, envIntensity, 64);
}

void sound4_envelope_length(UINT8 volume, UINT8 shiftClFreq,
        UINT8 counterStepWidth, UINT8 divRatio,
        UINT8 envInc, UINT8 envIntensity,
        UINT8 length){

    NR41_REG = 63 - length;

    NR42_REG = (volume << 4) | (envInc << 3) | envIntensity;
    NR43_REG = (shiftClFreq << 4) | (counterStepWidth << 3) | divRatio;
    if(length < 64)
        NR44_REG = 0xC0;
    else
        NR44_REG = 0x80;


}





