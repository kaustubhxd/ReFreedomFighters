#include "ff.h"
extern "C" void THISCALL ext_563510(void*,u32);
extern "C" void THISCALL ext_563610(void*,u32);
extern "C" void THISCALL ext_572240(void*,u32,u32);
static void THISCALL init(u8*me){
 ext_563510(me,0x6a6f98);ext_563610(me,0x6a6fa0);
 auto parent=vcall<void*>(*(void**)(me+0x54),0x25c,(u32)0x6a8960,0);
 const u32 names[3]={0x6a8950,0x693188,0x6a8958};
 for(u32 i=0;i<3;++i){auto o=vcall<void*>(parent,0x25c,names[i],0);*(void**)(me+0x180+4*i)=o;auto table=*(void**)(G(u8*,0x70039c)+0x9b);auto id=vcall<u32>(table,0x4c,*(void**)(me+0x44));vcall<void>(o,0x2e8,id);}
 auto settings=vcall<void*>(G(void*,0x70039c),0xbc);
 ext_572240(me,0,vcall<u32>(settings,0x7c));ext_572240(me,1,vcall<u32>(settings,0x84));ext_572240(me,2,vcall<u32>(settings,0x8c));
 const u32 slots[3]={0x7c,0x84,0x8c};for(u32 i=0;i<3;++i){auto o=*(void**)(me+0x180+4*i);auto val=vcall<u32>(settings,slots[i],1);vcall<void>(o,0x36c,val);}
}
PCREG(571f20,init);
