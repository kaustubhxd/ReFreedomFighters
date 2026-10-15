#include "ff.h"
static void THISCALL update_channels(u8* me){
 ((void(*)())G(void*,0x7003b0))();
 vcall<void>(me,0x380);
 vcall<void>(me+0x39f,8,me+0x236);
 vcall<void>(me+0x3c8,8,me+0x22e);
 for(int i=0;i<2;i++){
  u8* channel=me+(i?0x3c8:0x39f);
  if(vcall<u8>(channel,0x20)){
   u8* vt=*(u8**)channel;
   long double random=vcall<long double>(G(void*,0x70039c),0x1c4,0x69f8b8,i?0x2c2:0x2bd);
   float product=(float)(random*(long double)*(float*)(me+(i?0x346:0x342)));
   float value=*(float*)(me+(i?0x232:0x23a))+product;
   typedef void(THISCALL *Fn)(void*,float,float,u32);
   (*(Fn*)(vt+4))(channel,*(float*)(me+(i?0x22e:0x236)),value,0);
  }
 }
}
PCREG(51e340,update_channels);
