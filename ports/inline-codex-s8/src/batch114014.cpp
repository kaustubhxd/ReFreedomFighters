#include "ff.h"
#define U(p,o) (*(u32 *)((u8 *)(p)+(o)))
extern "C" void THISCALL ext_4dc030(void *);extern "C" u32 THISCALL ext_4db9a0(void *,u32);extern "C" u32 THISCALL ext_4dc110(void *);extern "C" void THISCALL ext_4db860(void *,u32);extern "C" u8 *THISCALL ext_4b48c0(void *,void *);extern "C" void THISCALL ext_4b3a70(void *);extern "C" void THISCALL ext_4d9430(void *);extern "C" void ext_4d9590(void *);
static void *table4b(){return (void *)U(G(void *,0x70039c),0x9b);}
static u8 *find4b(u8 *s,u32 id){u32 it[3];vcall<void>(s+0xf2,0x4c,it);u8 *p;while((p=vcall<u8 *>(s+0xf2,0x64,it)))if(U(p,0)==id)return p;return 0;}
static void THISCALL remove4b6e00(u8 *s,u8 *node,u32 active) {
 u8 *owner=(u8 *)U(node,0x54);
 if(owner&&U(U(owner,12),0x23)==0x80000d) {
  u32 id=vcall<u32>(table4b(),0x50,node);u8 *entry=find4b(s,id);
  if(entry&&!U(entry,16)){void *p=vcall<void *>(table4b(),0x54,U(entry,12));if(p)ext_4dc030(p);}
 }
 if(!(active&255))return;
 if(ext_4db9a0(node,0x200015)&255) {
  u8 *entry=find4b(s,vcall<u32>(table4b(),0x50,node));
  if(entry)vcall<void>((void *)U(node,0x54),U(entry,4)?0x22c:0x228);return;
 }
 u8 *data=(u8 *)U(s,0x12a);u32 it[3];
 if(data&&U(data,24)) {
  void *list=(void *)U(data,24);vcall<void>(list,0x4c,it);u32 id=vcall<u32>((void *)U(U(s,0x12a),24),0x5c,it);
  while(it[0]) {
   u8 *other=vcall<u8 *>(table4b(),0x54,id);
   if(other) {
    u32 a=ext_4dc110(other),b=ext_4dc110(node);typedef u32(*Cmp)(u32,u32);
    if(!((Cmp)G(u32,0x676414))(b,a)) {
     ext_4db860(other,0);u8 *target=ext_4b48c0(s,(void *)U(other,0x54));u8 *source=ext_4b48c0(s,(void *)U(node,0x54));
     if(target&&source) {
      u8 matrix[36],position[12];void *geom=vcall<void *>(source,0x20);vcall<void>(geom,0x80,matrix,position);
      vcall<void>(target,0x370,matrix,position);vcall<void>(target,0x2d4,source);vcall<void>(target,0xbc,0);
     }
    }
   }
   id=vcall<u32>((void *)U(U(s,0x12a),24),0x5c,it);
  }
 }
 if((ext_4db9a0(node,0x400003)&255)&&vcall<u32>(table4b(),0x50,node)==U(s,0x84))ext_4b3a70(s);
 u8 allowed=1;owner=(u8 *)U(node,0x54);
 if(owner){vcall<void>(owner,0x128,(u32)*(u16 *)(s+0x68),&allowed,0);if(!allowed)return;}
 ext_4d9430(node);ext_4d9590(node);
}
PCREG(4b6e00,remove4b6e00);
