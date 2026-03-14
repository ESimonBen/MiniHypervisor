# Mini Hypervisor Design Notes

## Goal
Build a minimal Type-2 hypervisor written in C and x86-64 assembly.

## Initial Milestones
1. Project skeleton and build system
2. Detect CPU virtualization support
3. Enter VMX operation
4. Launch minimal guest code
5. Handle VM exits