#include "ff.h"

STDCALL int func_465870(int param1) {
  if (param1 == 1) {
    return 0x465710;
  }
  return 0;
}

THISCALL int func_63eab0(void* ecx, int param1) {
  void* arr = *(void**)((char*)ecx + 0x68);
  int idx = param1 & 0xfff;
  return *(int*)((char*)arr + idx*4);
}

THISCALL void func_651010(void* ecx, int param1, int param2) {
  *(int*)((char*)ecx + 0x84) = param1;
  *(int*)((char*)ecx + 0x88) = param2;
}

PCREG(465870, func_465870);
PCREG(63eab0, func_63eab0);
PCREG(651010, func_651010);
