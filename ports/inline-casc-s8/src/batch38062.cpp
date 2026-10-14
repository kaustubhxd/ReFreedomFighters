// batch38062.cpp - cascade s8 batch 38062: 0x58be30 (resolve the page's named string / sound ids).
#include "ff.h"

extern "C" void THISCALL ext_481530(u8 *self);   // base initialisation, plain ret
typedef u32(THISCALL *v1_t)(void *, u32);
#define SLOT(o, off, T) ((T)(*(u8 **)(*(u8 **)(o) + (off))))

// 0x58be30, thiscall, no args, plain ret. Runs the base initialiser 0x481530, stores slot 0x21c(0x6acbac) at +0x724, then resolves 36 more names with slot 0x35c(name) into the matching dwords
// (+0x22a, +0x236, +0x25e, ... up to +0x758). The table below is in call order (0x6acdcc is looked up twice, for +0x74c and +0x750).
static void THISCALL fn58be30(u8 *self) {
  ext_481530(self);
  *(u32 *)(self + 0x724) = SLOT(self, 0x21c, v1_t)(self, 0x6acbac);
  static const struct {
    u32 name;
    u32 off;
  } tab[] = {
    {0x6acbb8, 0x22a},
    {0x6acbcc, 0x236},
    {0x6acbdc, 0x25e},
    {0x6acbf0, 0x720},
    {0x6acc00, 0x75c},
    {0x6acc18, 0x780},
    {0x6acc24, 0x784},
    {0x6acc2c, 0x788},
    {0x6899f8, 0x734},
    {0x6acc44, 0x72c},
    {0x6acc50, 0x730},
    {0x68adf8, 0x78c},
    {0x6acc5c, 0x790},
    {0x6acc74, 0x794},
    {0x6acc84, 0x798},
    {0x6acc94, 0x79c},
    {0x6acca0, 0x7a0},
    {0x6accb0, 0x7a4},
    {0x6accc0, 0x738},
    {0x6acccc, 0x7ac},
    {0x6accdc, 0x7a8},
    {0x6acce8, 0x73c},
    {0x6accf4, 0x760},
    {0x6acd08, 0x764},
    {0x6acd1c, 0x768},
    {0x6acd30, 0x76c},
    {0x6acd48, 0x770},
    {0x6acd64, 0x774},
    {0x6acd80, 0x778},
    {0x6acd90, 0x77c},
    {0x6acda4, 0x740},
    {0x6acdb4, 0x744},
    {0x6acdcc, 0x74c},
    {0x6acdcc, 0x750},
    {0x6acde8, 0x754},
    {0x6ace04, 0x758}
  };
  for (unsigned i = 0; i < sizeof(tab) / sizeof(tab[0]); i++) *(u32 *)(self + tab[i].off) = SLOT(self, 0x35c, v1_t)(self, tab[i].name);
}
PCREG(58be30, fn58be30);
