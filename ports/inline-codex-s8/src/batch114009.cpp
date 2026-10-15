#include "ff.h"
#define U(p,o) (*(u32 *)((u8 *)(p)+(o)))
#define B(p,o) (*((u8 *)(p)+(o)))
static void put498(void *st,u32 v){vcall<void>(st,16,&v,4);}
static void mark498(void *st,u32 v){vcall<void>(st,8,v);}
static void THISCALL save498f00(u8 *s,u8 *ctx,u8 *node) {
 u32 delta=(u32)node-U(U(s,20),4),index=delta/112;
 u8 *mask=(u8 *)U(ctx,8);mask[index>>3]&=~(1u<<(index&7));
 u8 *owner=(u8 *)U(node,0x54);void *st=(void *)U(ctx,0);
 if(owner && U(owner,16) && U(U(owner,16),8)) {
  void *list=(void *)U(U(owner,16),8);
  if(vcall<u32>(list,20)) {
   bool any=false;u32 it[3];
   list=(void *)U(U(owner,16),8);
   if(list) {
    vcall<void>(list,0x4c,it);u32 value=vcall<u32>((void *)U(U(owner,16),8),0x5c,it);
    while(it[0]) {
     any=true;u8 *item=vcall<u8 *>(G(void *,0x70038c),0xcc,value);
     mark498(st,17);vcall<void>(st,0x28,0x45564e54);vcall<void>(item,0x24,st);
     if(!(B(item,4)&4)&&(B(item,20)&1))put498(st,0);
     else {
      put498(st,1);U(item,4)|=0x40;vcall<void>(item,0x1c,st);
      if(B(item,4)&0x40) {
       void *logger=vcall<void *>(G(void *,0x700390),0x20,0x68e36c,0x336);
       typedef void (*Log)(void *,u32,u32);((Log)U(U(logger,0),0x2c))(logger,0x68e398,U(U(item,0x40),0));
       ((void(*)())G(u32,0x7003b0))();
      }
     }
     mark498(st,16);
     if(B(item,4)&16) {
      put498(st,0x80000000);
      if(U(item,28)){put498(st,1);vcall<void>(st,16,item+20,4);vcall<void>(st,16,item+32,4);}
      else {put498(st,0);put498(st,U(item,4));vcall<void>(st,16,item+32,4);vcall<void>(st,0x5c,U(U(item,0x40),0));}
     } else put498(st,U(item,32));
     value=vcall<u32>((void *)U(U(owner,16),8),0x5c,it);
    }
   }
   mark498(st,16);put498(st,0xffffffff);
   if(any){mark498(st,13);put498(st,(s32)delta/112);}
  }
 }
 owner=(u8 *)U(node,0x54);u32 flags=owner?U(U(owner,12),0x23):0x200002;
 if((flags&0x100000)&&U(owner,0x50)) {
  u8 *child=(u8 *)U(owner,0x50);
  do {save498f00(s,ctx,child);child=(u8 *)U(child,0x60);}while(child);
 }
}
PCREG(498f00,save498f00);
