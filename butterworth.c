// Butterworth.c
#include "Butterworth.h"

void init_butterworth(ButterworthFilter* filter, const float coeff_num[3], const float coeff_den[3]) {
   // Initialize a_n and b_n to zeros
   filter->a_n[0] = filter->a_n[1] = filter->a_n[2] = 0.0;
   filter->b_n[0] = filter->b_n[1] = filter->b_n[2] = 0.0;

   // Initialize coeff_num and coeff_den based on provided values
   for (int i = 0; i < 3; ++i) {
       filter->coeff_num[i] = coeff_num[i];
       filter->coeff_den[i] = coeff_den[i];
   }
}

float butter_BP(ButterworthFilter* filter, int ADC_Value) {
   filter->b_n[0] = filter->coeff_num[0] * ADC_Value + filter->coeff_num[1] * filter->a_n[0] + filter->coeff_num[2] * filter->a_n[1] - filter->coeff_den[1] * filter->b_n[1] - filter->coeff_den[2] * filter->b_n[2];
   filter->b_n[0] /= filter->coeff_den[0];

   filter->a_n[2] = filter->a_n[1];
   filter->a_n[1] = ADC_Value;
   
   filter->b_n[2] = filter->b_n[1];
   filter->b_n[1] = filter->b_n[0];

   return filter->b_n[0];
}
