#include "ff.h"

THISCALL void func_4eb060(void* ecx, int param1, int param2) {
  *(int*)((char*)ecx + 0xc) = param1;
  *(int*)((char*)ecx + 0x10) = param2;
}

THISCALL void func_5c7ed0(void* ecx) {
  *(int*)((char*)ecx + 0) = 0x6b48f0;
  *(int*)((char*)ecx + 4) = 0;
  *(int*)((char*)ecx + 9) = 0;
  *(int*)((char*)ecx + 0x29) = 0;
  *(int*)((char*)ecx + 0x2d) = 0;
  *(int*)((char*)ecx + 0x31) = 0;
}

extern "C" void func_62c9b0(void* param1) {
  *(int*)param1 = 0x62dfa0;
  *(int*)((char*)param1 + 0xc) = 1;
  *(int*)((char*)param1 + 8) = 0;
}

THISCALL void func_5df6c0(void* ecx, int param1, int param2, int param3) {
  *(int*)((char*)ecx + 4) = param1;
  *(int*)((char*)ecx + 0xc) = param2;
  *(int*)((char*)ecx + 0x10) = param3;
  *(int*)((char*)ecx + 0) = 0x6b7310;
  *(int*)((char*)ecx + 8) = 0;
}

PCREG(4eb060, func_4eb060);
PCREG(5c7ed0, func_5c7ed0);
PCREG(62c9b0, func_62c9b0);
PCREG(5df6c0, func_5df6c0);
