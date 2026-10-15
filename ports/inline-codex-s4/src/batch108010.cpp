#include "s4_mem.h"
extern "C" void THISCALL ext_5af5b0(void*,u32*,u32*,u32);
extern "C" void* THISCALL ext_5af130(void*,u32);
extern "C" void THISCALL ext_5af7c0(void*,u32,u32,u32);
extern "C" u8 THISCALL f5afd00(void* self,u32* weapon0,u32* ammo0,u32* weapon1,u32* ammo1){
 void* list=(u8*)self+0x18;
 ext_5af5b0(list,weapon0,ammo0,1);ext_5af5b0(list,weapon1,ammo1,0);
 u32 ids[2]={*weapon0,*weapon1},ammo[2]={*ammo0,*ammo1};u8 changed=0;
 for(u32 i=0;i<2;i++)if(ids[i]){
  void* record=ext_5af130(s4p(self,0x14),ids[i]);
  u32 cap=s4r(record,0xc);
  if(ammo[i]<cap){
   u32 total=ammo[i]+s4r(record,8)/3;
   if(total>cap)total=cap;
   ammo[i]=total;
   ext_5af7c0(list,ids[i],total,0);changed=1;
  }
 }
 *ammo0=ammo[0]-*ammo0;*ammo1=ammo[1]-*ammo1;
 return changed;
}
PCREG(5afd00,f5afd00);
extern "C" void* ext_41e290(u32);
extern "C" void THISCALL ext_5fe3b0(void*,u32,void*);
extern "C" void THISCALL f5ebe00(void* self,void* info,u32 a,u32 b,u32 c,u32 d){
 s4w(self,0x36,s4r(info,0));s4w(self,0x52,s4r(info,4));s4w(self,0x56,s4r(info,8));
 for(u32 i=0;i<s4r(self,0x3e);i++){
  void* record=ext_41e290(0x2c);
  s4w16(record,0,a);s4w16(record,2,b);s4w16(record,4,c);s4w16(record,6,d);
  s4w(record,8,0x3f800000);s4w(record,0xc,0x3f800000);s4w(record,0x10,0);
  s4w(record,0x14,0x3f800000);s4w(record,0x18,0x3f800000);s4w(record,0x1c,0);s4w(record,0x28,0);
  if(!c)s4w16(record,4,s4r16(self,0x52));
  if(!d)s4w16(record,6,s4r16(self,0x56));
  u32 cursor=s4r(self,0x66);
  if(cursor!=s4r(self,0x6a)){
   if(cursor)s4w((void*)cursor,0,(u32)record);
   s4w(self,0x66,cursor+4);
  }else ext_5fe3b0((u8*)self+0x62,cursor,&record);
 }
 u64 size=(u64)s4r(self,0x3e)*0x28;
 void* backing=ext_41e290(size>0xffffffffULL?0xffffffffu:(u32)size);
 s4w(s4p(self,0x3a),4,(u32)backing);
 vcall<void>(self,0x18);
}
PCREG(5ebe00,f5ebe00);
