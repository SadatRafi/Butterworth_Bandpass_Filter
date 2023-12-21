// Butterworth.h

#ifndef BUTTERWORTH_H
#define BUTTERWORTH_H

// Structure to hold filter parameters
typedef struct {
    float a_n[3];
    float b_n[3];
    float coeff_num[3];
    float coeff_den[3];
} ButterworthFilter;

void init_butterworth(ButterworthFilter* filter, const float coeff_num[3], const float coeff_den[3]);
float butter_BP(ButterworthFilter* filter, int ADC_Value);

#endif // BUTTERWORTH_H
