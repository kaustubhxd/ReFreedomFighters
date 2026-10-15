#include "ff.h"
static void THISCALL advance_two_emitter_channels(u8* self) {
  u8* first=self+0x39f;
  u8* second=self+0x3c8;
  vcall<void>(first,8,(u32)(self+0x236));
  vcall<void>(second,8,(u32)(self+0x22e));
  if(vcall<u8>(first,0x20)) {
    float r=vcall<float>(g_pSysInterface,0x1c4,0x69f8b8,0x2bd);
    float y=G(float,self+0x23a)+r*G(float,self+0x342);
    vcall<void>(first,4,G(float,self+0x236),y,0.0f);
  }
  if(vcall<u8>(second,0x20)) {
    float r=vcall<float>(g_pSysInterface,0x1c4,0x69f8b8,0x2c2);
    float y=G(float,self+0x232)+r*G(float,self+0x346);
    vcall<void>(second,4,G(float,self+0x22e),y,0.0f);
  }
}
PCREG(51e340,advance_two_emitter_channels);
