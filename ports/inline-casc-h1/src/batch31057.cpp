#include "ff.h"

THISCALL void func_4c62c0(void* ecx, int param1, int param2) {
  int word_val = *(unsigned short*)((char*)ecx + 0x48);
  if (word_val != 0 && (unsigned short)param1 == word_val && param2 != 0) {
    *(int*)param2 = *(int*)((char*)ecx + 0x4a);
  }
}

THISCALL void func_5ad2b0(void* ecx, unsigned char* param1) {
  *(unsigned char*)((char*)ecx + 0x48) = param1[0];
  *(unsigned char*)((char*)ecx + 0x49) = param1[1];
  *(unsigned char*)((char*)ecx + 0x4a) = param1[2];
  *(unsigned char*)((char*)ecx + 0x4b) = param1[3];
  *(unsigned char*)((char*)ecx + 0x4c) = 0;
}

THISCALL void func_5df720(void* ecx, int param1, int param2, int param3) {
  *(int*)((char*)ecx + 4) = param1;
  *(int*)((char*)ecx + 8) = param2;
  *(int*)((char*)ecx + 0xc) = param3;
  *(int*)((char*)ecx + 0) = 0x6b7360;
}

PCREG(4c62c0, func_4c62c0);
PCREG(5ad2b0, func_5ad2b0);
PCREG(5df720, func_5df720);
