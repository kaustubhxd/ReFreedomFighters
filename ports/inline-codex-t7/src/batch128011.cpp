#include "ff.h"
extern "C" void THISCALL ext_4dc2b0(void*,void*);
extern "C" u8* THISCALL ext_4dc110(void*);
extern "C" u8 THISCALL ext_41e650(void*,void*);
extern "C" void THISCALL ext_499670(void*,void*,void*);
static inline u32 &w12(u8*p,u32 off){return *(u32*)(p+off);}
static inline u8*p12(u8*p,u32 off){return *(u8**)(p+off);}
static void wr12(u8*arg,void*p,u32 n){vcall<void>(p12(arg,0),0x10,p,n);}
static void THISCALL serialize12(u8*self,u8*arg,u8*item){
 u32 delta=(u32)item-w12(p12(self,0x14),4);u32 idx=delta/112;
 p12(arg,8)[idx>>3]&=(u8)~(1u<<(idx&7));
 vcall<void>(p12(arg,0),8,12u);vcall<void>(p12(arg,0),0x28,0x47454f4du);
 ext_4dc2b0(item,p12(arg,0));
 vcall<void>(p12(arg,0),8,11u);
 s32 signedidx=(s32)((u32)item-w12(p12(self,0x14),4))/112;
 wr12(arg,&signedidx,4);vcall<void>(p12(arg,0),8,6u);
 p12(arg,4)[idx>>3]|=(u8)(1u<<(idx&7));
 u8*desc=p12(item,0x54);
 if(!(w12(item,0x3c)&0x8000000)){
  wr12(arg,&signedidx,4);
  s32 pos=(s32)((u32)item-w12(p12(self,0x14),4))/112-(w12(self,0x28)/112);
  u32 value=((u32*)w12(self,0x5d))[pos];wr12(arg,&value,4);
  u8*name=ext_4dc110(item);u8*table=p12(G(u8*,0x70039c),0x9b);u8*base=p12(table,0x1c5d);
  if((u32)name>=(u32)base && base && (u32)name<(u32)base+(w12(base,0xfffffff8)&0x1fffffff)){
   u32 origin=vcall<u32>(table,0x17c);u32 off=(u32)ext_4dc110(item)-origin;wr12(arg,&off,4);
  }else{
   u32 absent=0xffffffff;wr12(arg,&absent,4);
   u8*str=ext_4dc110(item);
   int equal=(*(int (**)(u8*,u32))0x676414)(str,0x67c8e8);
   if(!equal){u32 one=1;u8 zero=0;wr12(arg,&one,2);wr12(arg,&zero,1);}
   else{
    str=ext_4dc110(item);u32 len=0;while(str[len])++len;u32 small=(u16)(len+1);wr12(arg,&small,2);
    str=ext_4dc110(item);u32 count=0;while(str[count])++count;++count;
    str=ext_4dc110(item);wr12(arg,str,count);
   }
  }
  u32 type=desc?w12(p12(desc,12),0x23):0;wr12(arg,&type,4);
  u8*ref=0;
  if(desc && p12(desc,16))ref=p12(p12(desc,16),12);
  if(ref){table=p12(G(u8*,0x70039c),0x9b);if(ext_41e650(table,ref)){u32 off=(u32)ref-w12(table,0x1c5d);wr12(arg,&off,4);}else ((void(*)())G(u32,0x7003b0))();}
  else {u32 absent=0xffffffff;wr12(arg,&absent,4);}
 }
 desc=p12(item,0x54);u32 type=desc?w12(p12(desc,12),0x23):0x200002;
 if(type&0x100000){ext_499670(self,arg,desc);u8*child=p12(desc,0x50);while(child){serialize12(self,arg,child);child=p12(child,0x60);}}
}
PCREG(499360,serialize12);
