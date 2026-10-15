#include "ff.h"
static u32 rd7(void* p,u32 o){return *(u32*)((u8*)p+o);}
static void* ptr7(void* p,u32 o){return (void*)rd7(p,o);}
static void wr7(void* p,u32 o,u32 v){*(u32*)((u8*)p+o)=v;}
extern "C" void ext_4248e0();
extern "C" void THISCALL ext_5f56f0(void*);
extern "C" void* ext_5fa630();
extern "C" void THISCALL ext_5fd2a0(void*,void*);
extern "C" void THISCALL ext_5f3b00(void*);
extern "C" void ext_634273(void*,u32);
extern "C" void THISCALL f5fd6f0(void* self){
 void* callback=ptr7(self,0x30);
 if(callback){vcall<void>(callback,0,(u8*)self+0x18);return;}
 for(u32 i=0;i<rd7(self,0x20);i++){
  void* item=((void**)ptr7(self,0x18))[i];
  ext_4248e0();
  wr7(self,0x38,(u32)item);
  ext_5f56f0(item);
  if(*(u16*)((u8*)item+0xac)&0x4000){
   u32 n=rd7(self,0x20),index=0;
   while(index<n&&((void**)ptr7(self,0x18))[index]!=item)index++;
   if(index==n)continue;
   if(index<n-1){
    typedef void*(*Move)(void*,void*,u32);
    u8* at=(u8*)ptr7(self,0x18)+4*index;
    ((Move)G(u32,0x676278))(at,at+4,4*(n-index));
   }
   wr7(self,0x20,rd7(self,0x20)-1);
   vcall<void>(ext_5fa630(),0x24,item);
   ext_5fd2a0(ptr7(self,4),item);
   ext_5f3b00(item);
   ext_634273(item,0xad2);
  }
 }
}
PCREG(5fd6f0,f5fd6f0);
extern "C" void* ext_631810(void*,u32,u32);
extern "C" void STDCALL ext_62f980(void*);
extern "C" void STDCALL ext_62fad0(void*);
extern "C" void* ext_632230(void*,u32,u32);
extern "C" s32 STDCALL f62f9d0(void* stream,s32 window,const u8* version,u32 size){
 if(!version||version[0]!=0x31||size!=0x38)return -6;
 if(!stream)return -2;
 wr7(stream,0x18,0);
 if(!rd7(stream,0x20)){wr7(stream,0x20,(u32)ext_631810);wr7(stream,0x28,0);}
 if(!rd7(stream,0x24))wr7(stream,0x24,0x631840);
 typedef void*(*Alloc)(void*,u32,u32);
 void* state=((Alloc)rd7(stream,0x20))(ptr7(stream,0x28),1,0x18);
 wr7(stream,0x1c,(u32)state);
 if(!state)return -4;
 wr7(state,0x14,0);wr7(state,0xc,0);
 u32 bits=(u32)window;
 if(window<0){bits=0u-bits;wr7(state,0xc,1);}
 if(bits-8>7){ext_62f980(stream);return -2;}
 wr7(state,0x10,bits);
 void* memory=ext_632230(stream,rd7(state,0xc)?0:0x6316e0,1u<<bits);
 state=ptr7(stream,0x1c);wr7(state,0x14,(u32)memory);
 if(!memory){ext_62f980(stream);return -4;}
 ext_62fad0(stream);return 0;
}
PCREG(62f9d0,f62f9d0);
