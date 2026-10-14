#include "ff.h"

THISCALL void func_5aedb0(void* ecx) {
  *(int*)((char*)ecx + 0) = 0;
  *(int*)((char*)ecx + 4) = 0;
  *(int*)((char*)ecx + 8) = 0;
  *(int*)((char*)ecx + 0xc) = 0;
  *(int*)((char*)ecx + 0x10) = 0;
}

THISCALL void func_64fc20(void* ecx, int* param1) {
  int* ptr = (int*)((char*)ecx + 0x60);
  param1[0] = ptr[0];
  param1[1] = ptr[1];
}

THISCALL int func_410100(int* param1) {
  void* ptr = (void*)*param1;
  return *(unsigned char*)((char*)ptr + 4);
}

PCREG(5aedb0, func_5aedb0);
PCREG(64fc20, func_64fc20);
PCREG(410100, func_410100);
