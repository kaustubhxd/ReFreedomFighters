#include "ff.h"
static void assertion(){typedef void(*A)();auto a=G(A,0x7003b0);if(a)a();else asm volatile("int3");}
static void THISCALL count(void*,u8*args){
 u32 total=0;auto mgr=G(u8*,0x7003b8);u8*slot=mgr+8;while(slot!=mgr+8+4*(*(u32*)(mgr+4))){auto actor=*(u8**)slot;if(!vcall<u8>(actor,0x438)){auto team=*(u8**)(actor+0x54);if(team&&*(u32*)(team+4)==1)++total;}mgr=G(u8*,0x7003b8);slot+=4;}
 auto output=*(u8**)(args+8);auto header=*(u8**)output;u8*value;
 if(*(u32*)(output+8)){u32 index=*(u32*)(output+4);if(index>=*(u32*)(header+8))assertion();value=*(u8**)header+index*8;}
 else{assertion();header=*(u8**)output;if(!*(u32*)(header+8))assertion();value=*(u8**)header;}
 if(value[4]>1){auto lo=vcall<void*>(G(void*,0x700390),0x20,(u32)0x69c8e0,0x104);typedef void(*P)(void*,u32,u32);(*(P*)(*(u8**)lo+0x2c))(lo,0x69c6b0,0x69c938);assertion();}
 *(u32*)value=total;value[4]=1;
}
PCREG(554d40,count);
