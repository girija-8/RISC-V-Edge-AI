/* Copyright 2019 SiFive, Inc */
/* SPDX-License-Identifier: Apache-2.0 */

#include <stdio.h>
#include <math.h>
#include "svm_model.h"
#include "scaler.h"

void scale_input(float *x) {
    for (int i = 0; i < NUM_FEATURES; i++) {
        x[i] = (x[i] - mean[i]) / scale[i];
    }
}

int predict(float *x) {
    float score = bias[0];
    for (int i =0; i< NUM_FEATURES; i++){
        score+= weights[0][i] * x[i];
    }
    if (score<=0){
        return 0;}
    return 1;
}

void print_float(float val)
{
    int int_part = (int)val;
    int frac_part = (int)((val - int_part) * 100); // 2 decimal places
    if (frac_part < 0) frac_part *= -1;
    printf("%d.%02d \n", int_part, frac_part);
}

int main() {
    float input[2] = {
        60, 190000
    };

    scale_input(input);
    int label = predict(input);
    printf("predicted output :- %d", label);
    return 0;
}
