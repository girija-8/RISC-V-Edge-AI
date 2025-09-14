
/* Copyright 2019 SiFive, Inc */
/* SPDX-License-Identifier: Apache-2.0 */

#include <stdio.h>
#include <metal/cpu.h>
#include <metal/led.h>
#include <metal/button.h>
#include <metal/switch.h>

#define RTC_FREQ    32768
#define x1 0.77884104f
#define x2 0.0293919f
#define x3 0.03471025f

#define b 42989.00816508669f

float predict(float inp1, float inp2, float inp3){
	return x1* inp1 +x2* inp2 + x3*inp3 + b;

}

void print_float(float val)
{
	int int_part = (int)val;
	int frac_part = (int)((val - int_part)* 100);
	if (frac_part < 0) frac_part *= -1;
	printf("%.%02d",int_part,frac_part);
}
int main (void)
{
	float rDSpend=165349.2f;
	float aDSpend=136897.8f;
	float mKSpend=471784.1f;
	float profit;
	profit=predict(rDSpend,aDSpend,mKSpend);
	printf("profit is :- " );
	print_float(profit);
	
	return 0;
}
