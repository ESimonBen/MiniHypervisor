#include <stdio.h>
#include <stdint.h>
#include <intrin.h>

// Read MSR (To be placed in a Windows kernel driver)
uint64_t read_msr(uint32_t msr) {
    return __readmsr(msr);
}

int main(){
    int cpuInfo[4]; // Stores the resulting values from the eax (index 0), ebx (index 1), ecx (index 2), and edx (index 3s) registers in this array

    __cpuid(cpuInfo, 1); // Calls the cpuid instruction intrinsically, and places the value 1 in the eax register before calling the instruction

    if (cpuInfo[2] & (1 << 5)) {
        printf("Intel VT-x supported\n"); // If the value in ECX is 32 (which is the value of 1 bit-shifted to the left 5 times), Intel VT-x is supported
    }
    else {
        printf("Intel VT-x NOT supported\n"); // Otherwise, it is not supported
    }

    return 0;
}