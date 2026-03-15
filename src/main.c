#include <stdio.h>
#include <stdint.h>

uint64_t rdmsr(uint32_t msr) {
    uint32_t low, high;
    __asm__ volatile (
        "rdmsr"
        : "=a"(low), "=d"(high)
        : "c"(msr)
    );

    return ((uint64_t)high << 32) | low; // Shifts the 32 bit number "high" 32 bits up (putting it into the 32 highest bits) and combining it with the 32 lowest bits from "low"
}

int main(){
    uint32_t eax, ebx, ecx, edx;                     // Variables to store registers' values
    __asm__ volatile (                               // __asm__ for inline assembly, volatile for the GCC compiler to tell it to not optimize
        "cpuid"                                      // assembly instruction to be called after input
        : "=a"(eax), "=b"(ebx), "=c"(ecx), "=d"(edx) // output registers ("=a" = EAX/RAX register) being mapped to variables
        : "a"(1)                                     // Input register (place 1 into EAX register)
    );

    if (ecx & (1 << 5)) {
        printf("Intel VT-x supported\n");
    }
    else {
        printf("Intel VT-x NOT supported\n");
    }

    return 0;
}