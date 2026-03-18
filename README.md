# Mini Hypervisor

Educational Type-2 hypervisor written in C targeting Windows kernel mode.

## Goals

- Learn CPU virtualization fundamentals
- Detect and use Intel VT-x (VMX)
- Transition from user-mode experiments to kernel-mode driver
- Eventually run a minimal guest

## Current Status

- [x] CPUID-based VMX detection (MSVC intrinsics)
- [ ] MSR access (planned for kernel driver)
- [ ] VMXON setup
- [ ] VM launch

## Architecture

Host OS (Windows) → Hypervisor Driver → Guest

## Build

This project uses Visual Studio and MSVC.

### Requirements

- Visual Studio (C++ workload)
- Windows Driver Kit (WDK)
- x86-64 CPU with Intel VT-x support

## Build Instructions

1. Install Visual Studio with C++ workload
2. Open `MiniHypervisor.sln`
3. Select `x64` and `Debug`
4. Click Build → Build Solution

## Notes

- Inline assembly has been replaced with MSVC intrinsics (`__cpuid`, etc.)
- VMX/MSR instructions cannot be executed in user mode
- Kernel driver development is required for further progress

## Future Work

- Implement Windows kernel driver
- Enable VMX operation (VMXON)
- Create VMCS and launch a guest