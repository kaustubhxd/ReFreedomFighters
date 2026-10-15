#include "ff.h"
static u8* THISCALL resolve(u32 id){
 u32 type=id>>16,index=id&0xffff;
 if(type==0x42){
 for(u32 group=0;;++group){
 auto p=vcall<u8*>(*(void**)(G(u8*,0x70039c)+0x1907),0x9c,group);if(!p)return 0;
 while(*(u32*)p){if(!index--)return p;p+=12;}--index;
 }
 }
 u8*p;
 if(type<=2)p=vcall<u8*>(*(void**)(G(u8*,0x70039c)+0x1907),0x9c,type);
 else {asm volatile("mov -4(%%ebp), %0":"=r"(p));}
 while(*(u32*)p){if(!index--)return p;p+=12;}return 0;
}
PCREG(57dde0,resolve);
