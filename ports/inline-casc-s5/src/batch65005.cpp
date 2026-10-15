#include "ff.h"
extern "C" u8 THISCALL ext_4bb6b0(u8 *self, u32 arg);
extern "C" u32 THISCALL ext_4db3b0(u8 *self);
typedef u8 *(THISCALL *look65005)(void *, u32);
typedef void (THISCALL *iter65005)(void *, u32 *);
typedef u32 (THISCALL *next65005)(void *, u32 *);
static void THISCALL f5146c0(u8 *self) {
  u32 id = *(u32 *)(self+0x1d1);
  if (id) { u8 *eng=G(u8*,0x70039c); u8 *o=(*(look65005 **) *(u8 **)(eng+0x9b))[0x60/4]( *(u8 **)(eng+0x9b), id );
    if(o){ float v=*(float *)(*(u8 **)(self+0x5c)+0x24)* *(float *)(self+0x1e1); s32 t=(s32)v+*(s32 *)(self+0x1dd); *(s32 *)(o+0x60)=t-*(s32 *)(o+0x64); *(s32 *)(o+0x64)=t; }}
  id=*(u32 *)(self+0x1d9);
  if (id) { u8 *eng=G(u8*,0x70039c); u8 *o=(*(look65005 **) *(u8 **)(eng+0x9b))[0x60/4]( *(u8 **)(eng+0x9b), id );
    if(o){ float v=*(float *)(*(u8 **)(self+0x5c)+0x24)* *(float *)(self+0x1e9); s32 t=(s32)v+*(s32 *)(self+0x1e5); *(s32 *)(o+0x60)=t-*(s32 *)(o+0x64); *(s32 *)(o+0x64)=t; }}
  u8 *a=*(u8 **)(self+0x1f9);
  if(a && *(u32 *)(self+0x1f5)) {
    u32 x=ext_4db3b0(*(u8 **)(a+8)); u32 y=ext_4db3b0(*(u8 **)(self+8));
    float threshold=*(float *)(G(u8*,0x70039c)+0x48)*2.0f+G(float,0x678858);
    if(ext_4bb6b0(*(u8 **)(self+0x1f5),x)) {
      if(!ext_4bb6b0(*(u8 **)(self+0x1f5),y)) { float q=*(float *)(self+0x1f1)/threshold; *(float *)(self+0x1f1)=q; if(G(float,0x67a288)>q) *(float *)(self+0x1f1)=0.25f; }
    } else { float q=threshold * *(float *)(self+0x1f1); *(float *)(self+0x1f1)=q; if(q>G(float,0x678858)) *(float *)(self+0x1f1)=1.0f; }
  } else *(float *)(self+0x1f1)=0.5f;
  u8 *list=*(u8 **)(self+0x1ed);
  if(list){ u32 it[4]={}; (*(iter65005 **)list)[0x4c/4](list,it); u32 item=(*(next65005 **)list)[0x5c/4](list,it); while(it[0]) { u8 *eng=G(u8*,0x70039c); u8 *o=(*(look65005 **) *(u8 **)(eng+0x9b))[0x60/4]( *(u8 **)(eng+0x9b), item ); if(o) *(u32 *)(o+0x84)=*(u32 *)(self+0x1f1); item=(*(next65005 **)list)[0x5c/4](list,it); }}
}
PCREG(5146c0,f5146c0);
