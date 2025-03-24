// Ultrasonic_func.h
// Step: 

// Click 3 Dot Select "New Tab" Rename File to "Ultrasonic_func.h"
// Then Copy Code Below Into you New .h File
// After That You Can do this Below as i Said
// in Another File you can include "Ultrasonic_func.h" Which Has Builtin UltraSonic Function
// is Simple You Can View The Soucre
#ifndef ULTRASONIC_FUNC_H
#define ULTRASONIC_FUNC_H

// Setting
const uint8_t DelayM = 10;
#define SOUND_SPEED_CM_PER_US 0.0351; 

long UltraSonic_DistanceCM(const uint8_t Tri, const uint8_t Echo)
{
    pinMode(Tri, OUTPUT);
    digitalWrite(Tri, LOW);
    delayMicroseconds(2);
    digitalWrite(Tri, HIGH);
    delayMicroseconds(DelayM);
    digitalWrite(Tri, LOW);

    pinMode(Echo, INPUT);
    long duration = pulseIn(Echo, HIGH);

    return (duration * SOUND_SPEED_CM_PER_US) / 2;
}

bool UltraSonic_IsObjectNear(const uint8_t Tri, const uint8_t Echo, unsigned long thresholdCM)
{
    return UltraSonic_DistanceCM(Tri, Echo) <= thresholdCM;
}

#endif  // ULTRASONIC_FUNC_H
