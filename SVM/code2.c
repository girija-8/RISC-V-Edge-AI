/* Copyright 2019 SiFive, Inc */
/* SPDX-License-Identifier: Apache-2.0 */

#include <stdio.h>
#include <math.h>
#include "svm_model.h"
#include "scaler.h"

void scale_input(double *x) {
    for (int i = 0; i < NUM_FEATURES; i++) {
        x[i] = (x[i] - mean[i]) / scale[i];
    }
}

int predict(float *x) {
    float score = bias[0];
    for (int i=0; i< NUM_FEATURES; i++){
        score+= weights[0][i] * x[i];
    }
    if (score<=0){
        return 0;}
    return 1;
}

int main() {
    float input[2] = {
        20, 19000
    };

    int label = predict(input);
    printf("predicted output :- %d", label);
    return 0;
}
/* Copyright 2019 SiFive, Inc */
/* SPDX-License-Identifier: Apache-2.0 */

#include <stdio.h>
#include <math.h>
#include "svm_model.h"
#include "scaler.h"

void scale_input(double *x) {
    for (int i = 0; i < NUM_FEATURES; i++) {
        x[i] = (x[i] - mean[i]) / scale[i];
    }
}

int predict(float *x) {
    float score = bias[0];
    for (int i=0; i< NUM_FEATURES; i++){
        score+= weights[0][i] * x[i];
    }
    if (score<=0){
        return 0;}
    return 1;
}

int main() {
    float input[2] = {
        20, 19000
    };

    int label = predict(input);
    printf("predicted output :- %d", label);
    return 0;
}
