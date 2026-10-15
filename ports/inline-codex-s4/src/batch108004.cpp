#include "ff.h"
static u32 rd4x(void* p,u32 o){return *(u32*)((u8*)p+o);}
static void* p4x(void* p,u32 o){return (void*)rd4x(p,o);}
static void wr4x(void* p,u32 o,u32 v){*(u32*)((u8*)p+o)=v;}
extern "C" void THISCALL ext_65f070(void*,void*);
extern "C" void THISCALL ext_65e3b0(void*,void*);
extern "C" void THISCALL ext_65f210(void*,void*);
extern "C" void THISCALL f65f2f0(void* self){
 if(!rd4x(self,0xc8))return;
 s32 budget=(s32)rd4x(self,0xc4);
 u32 i=0;
 while(i!=rd4x(self,0xcc)){
  void* item=p4x(self,0xd0+4*i);
  u32 flags=rd4x(item,0x24);
  if(flags){
   if(flags&4){
    ext_65f070(self,item);
    u32 count=rd4x(self,0xcc)-1;
    wr4x(self,0xcc,count);
    wr4x(self,0xd0+4*i,rd4x(self,0xd0+4*count));
    u8* pool=(u8*)self+0x2d0;
    *(u16*)(pool+0x3400)-=1;
    *(u16*)item=*(u16*)(pool+0x3402);
    *(u16*)(pool+0x3402)=(u16)((s32)((u32)item-(u32)pool)/104);
    i--; 
   }else{
    bool skip=false;
    if(flags&2){
     s32 old=budget;budget=(s32)((u32)budget-1);
     if(old<=0)skip=true;
     else{wr4x(item,0x24,flags&~2u);ext_65e3b0(self,item);}
    }
    if(!skip){
     flags=rd4x(item,0x24);
     if(flags&1){wr4x(item,0x24,flags&~1u);ext_65f210(self,item);}
    }
   }
  }
  i++;
 }
 wr4x(self,0xc4,1);
}
PCREG(65f2f0,f65f2f0);
extern "C" void THISCALL f49a160(void* self,u32 ref){
 u32 kind=0,value=0;
 if(!ref)kind=1;
 else{
  void* sys=G(void*,0x70039c);void* table=p4x(sys,0x9b);
  u32 first=rd4x(table,0x1c5d);
  u32 second=rd4x(table,0x44);
  if(ref>=first && first && ref<first+(G(u32,first-8)&0x1fffffff)){
   kind=2;value=ref-vcall<u32>(table,0x17c);
  }else if(ref>=second && second && ref<second+(G(u32,second-8)&0x1fffffff)){
   kind=3;value=ref-vcall<u32>(table,0x180);
  }else{
   void* manager=p4x(p4x(sys,0x1aa3),0x18);
   if((u8)vcall<u32>(manager,0x14,ref)){
    kind=4;value=vcall<u32>(p4x(p4x(G(void*,0x70039c),0x1aa3),0x18),0x10,ref);
   }
  }
 }
 vcall<void>(self,0xc,kind);
 vcall<void>(self,0xc,value);
}
PCREG(49a160,f49a160);
