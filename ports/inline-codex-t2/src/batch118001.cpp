#include "ff.h"
extern "C" void THISCALL ext_5e93f0(u8*,u32,u32);
extern "C" void THISCALL ext_516620(u8*,u32*);
extern "C" void THISCALL ext_4e09b0(u32*);
extern "C" void FASTCALL ext_451890(u32*,u32*,float);
extern "C" void THISCALL recycle(u8* s) {
 float now=(float)G(s32,G(u32,0x70039c)+0x40)*G(float,0x6785e4);
 for(u32 i=0;i!=*(u32*)(s+0x48);++i) {
  u8* entry=s+0x4c+8*i;void* weapon=*(void**)entry;
  if(weapon && now>*(float*)(entry+4)) {
   vcall<void>(weapon,0x2e8);
   u8* mgr=G(u8*,0x7003b8);void* id=*(void**)entry;
   u32* count=(u32*)(mgr+0x8b4);
   for(u32 j=0;j<*count;++j) if(*(void**)(mgr+0x8b8+4*j)==id) {
    *(u32*)(mgr+0x8b8+4*j)=*(u32*)(mgr+0x8b4+4*(*count));
    --*count;break;
   }
   if(*(void**)entry) vcall<void>(*(void**)entry,0x210,1u);
   *(u32*)entry=0;
  }
 }
 ext_5e93f0(s,0,1);
}
PCREG(5e9150,recycle);
extern "C" void THISCALL age_entries(u8* s) {
 for(u32 i=0;i!=*(u32*)s;++i) {u16* age=(u16*)(s+4+16*i+12);*age=(u16)(*age+1);}
 u32 i=0;
 while(*(u32*)s && i+1<*(u32*)s) {
  u8* p=s+4+16*i;s16 limit=(s8)p[14];
  if(p[14] && limit<=*(s16*)(p+12)) {
   for(u32 j=i;j+1<*(u32*)s;++j) _mm_storeu_ps((float*)(s+4+16*j),_mm_loadu_ps((float*)(s+4+16*(j+1))));
   --*(u32*)s;
  } else ++i;
 }
}
PCREG(5a01e0,age_entries);
extern "C" void THISCALL anchors(u8* s) {
 for(s32 i=0;i<*(s32*)(s+0x8c);++i) {
  u32 vec[3];for(u32 k=0;k<3;++k) vec[k]=*(u32*)(s+0x7c9+0x163*i+4*k);
  vcall<void>(*(void**)(s+0x88),0x84,vec);
  ext_516620(s+0xbd+0xde*i,vec);
 }
 for(s32 i=0;i<*(s32*)(s+0x90);++i) {
  u32 vec[3];for(u32 k=0;k<3;++k) vec[k]=*(u32*)(s+0xd55+0x133*i+4*k);
  vcall<void>(*(void**)(s+0x88),0x84,vec);
  ext_516620(s+0x435+0xde*i,vec);
 }
}
PCREG(526360,anchors);
extern "C" void THISCALL place_user(u8* s) {
 u8* sys=G(u8*,0x70039c);
 void* gun=vcall<void*>(*(void**)(sys+0x9b),0x58,*(u32*)(s+0x74));
 u32 matrix[9],pos[3];vcall<void>(gun,0x80,matrix,pos);
 for(u32 i=0;i<3;++i){u32 t=matrix[3+i];matrix[3+i]=matrix[6+i];matrix[6+i]=t;}
 ext_4e09b0(matrix);
 ext_451890(pos,matrix,bitsf(0x426a999a));
 ext_451890(pos,matrix+3,bitsf(0xc2d40000));
 ext_451890(pos,matrix+6,bitsf(0xc06a3d71));
 sys=G(u8*,0x70039c);
 void* user=vcall<void*>(*(void**)(sys+0x9b),0x58,*(u32*)(s+0x70));
 void* iface=vcall<void*>(user,0x2f4);
 if(iface) vcall<void>(iface,0x370,matrix,pos);
}
PCREG(5c8650,place_user);
