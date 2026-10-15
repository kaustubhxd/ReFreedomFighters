#include "ff.h"
extern "C" void* THISCALL ext_4d0590(void*,u32);
extern "C" void THISCALL ext_4d0c70(void*,void*,void*);
extern "C" u8* THISCALL ext_4d0840(void*,void*,u32);
extern "C" u8* THISCALL ext_4d08c0(void*,void*,u32);
static void assertion(){typedef void(*Fn)();auto fn=G(Fn,0x7003b0);if(fn)fn();else asm volatile("int3");}
static u8* THISCALL allocate(u8*me,u32 size){
 ++*(u32*)(me+0x20b);if(!size)return 0;
 size=(size+15)&0xfffffff0;
 if(me[0x1e9]||size>0x1fffd0){
 typedef u8*(*Malloc)(u32);u8*base=G(Malloc,0x6762f0)(size+0x30);u8*p=(u8*)(((u32)base+0x13)&0xfffffff0);
 *(u32*)(p+8)=0-size;*(u8**)(p-4)=base;*(u32*)(p+12)=0xffffffff;return p+16;
 }
 me[0x1e9]=1;auto owner=(u8*)ext_4d0590(me,size);auto block=*(u8**)(owner+0x11);
 if(*(s32*)(block+8)<(s32)size)assertion();
 ext_4d0c70(me,block,owner);s32 length=*(s32*)(block+8);u8*next=block+16+length;
 if(*(s32*)(next+12)!=length)assertion();if(*(s32*)(next+12)<0)assertion();
 if(!*(u32*)(block+12)&&!*(u32*)(next+8)){
 u8*head=*(u8**)(me+0x8220);u8*node=block-16;*(u8**)(node+4)=head;*(u32*)node=0;if(head)*(u8**)head=node;
 ++*(u32*)(me+0x8224);*(u8**)(me+0x8220)=node;
 }
 auto result=me[0x821b]?ext_4d0840(me,block,size):ext_4d08c0(me,block,size);return result?result+16:0;
}
PCREG(4d0700,allocate);
