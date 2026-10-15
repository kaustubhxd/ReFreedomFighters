#include "ff.h"
extern "C" void THISCALL focal_point(u8* s,u32* out){
 if(vcall<u8>(s,0x438)){
  u32 mat[9];void* p=vcall<void*>(s,0x3a8,mat,out);vcall<void>(s,0x390,p);return;
 }
 u32 flags=*(u32*)(s+0x417);float target;
 if(flags&0x400){bool alt=vcall<u8>(s,0x4d0)!=0;
  if(flags&3)target=alt?G(float,0x6ad21c):G(float,0x6ad218);
  else target=alt?G(float,0x6ad214):G(float,0x68c74c);
 }else target=G(float,0x67da28);
 flags=*(u32*)(s+0x417);if(flags&0x8000000)target=G(float,0x6ad220);
 float rate=G(float,0x680a8c);
 if((flags&0x400) && (*(u8**)(s+0x85a))[0xb45])rate=G(float,0x68af1c);
 float step=G(float,G(u32,0x70039c)+0x48)*rate;
 float value=*(float*)(s+0x81f);
 if(value>target){value=value-step;*(float*)(s+0x81f)=value;if(target>value)*(float*)(s+0x81f)=target;}
 else if(target>value){value=value+step;*(float*)(s+0x81f)=value;if(value>target)*(float*)(s+0x81f)=target;}
 out[0]=0;out[1]=*(u32*)(s+0x81f);out[2]=*(u32*)(s+0x823);
}
PCREG(591bb0,focal_point);
extern "C" void FASTCALL ext_43e960(void*,void*);
struct PickupCallback{u32 a,b,c,d;};
extern "C" u8 THISCALL pickup(u8* s){
 u32 mat[12],pos[3],actorpos[3];
 vcall<void>(*(void**)(s+8),0x2e0,mat,pos);
 vcall<void>(*(void**)(s+8),0x98,mat,pos);
 vcall<void>(*(void**)(s+0xc),0x94,mat,pos);
 PickupCallback cb={0x465708,0,0,0};
 vcall<void>(*(void**)(s+0x10),0x1c,*(void**)(s+0xc),mat,pos,bitsf(0x3f570a3d),cb);
 void* result=vcall<void*>(*(void**)(s+0xc),0x3a8,actorpos);
 vcall<void>(*(void**)(s+0xc),0x398,result);
 ext_43e960(actorpos,pos);float height=bitsf(actorpos[1]);u32 from,to;
 if(height>G(float,0x68ced0)){from=0;to=0x41f80000;}
 else if(height>G(float,0x680a84)){from=0x42380000;to=0x42980000;}
 else if(height>G(float,0x67da20)){from=0x42b60000;to=0x42f20000;}
 else if(height>G(float,0x68ced4)){from=0x43080000;to=0x43260000;}
 else {from=0x43350000;to=0x43640000;}
 vcall<void>(*(void**)(s+0xc),0x228,*(u32*)(s+0x14),1u,bitsf(from),bitsf(to),1.0f);
 return 1;
}
PCREG(4865a0,pickup);
extern "C" u32 THISCALL ext_644df0(void*,u32);
extern "C" u8 THISCALL read_frames(u8* s,void* reader){
 vcall<void>(reader,0x68,s+0x295);vcall<void>(reader,0x40,s+0x11);
 u32 count;vcall<void>(reader,0x40,&count);vcall<void>(reader,0x68,s+4);*(u32*)(s+0x69)=0;
 for(u32 i=0;i!=count;++i){
  u8 frame[56];vcall<void>(reader,0x40,frame);vcall<void>(reader,0x40,frame+4);
  vcall<void>(reader,0x6c,frame+44);vcall<void>(reader,0x74,frame+8);
  if(*(u32*)(s+0x69)+1>8){typedef void(*fn)();G(fn,0x7003b0)();}
  u8* dst=s+0x6d+56**(u32*)(s+0x69);
  for(u32 j=0;j<56;++j)dst[j]=frame[j];++*(u32*)(s+0x69);
 }
 u32 handle;vcall<void>(reader,0x48,&handle);*(u32*)(s+0x291)=ext_644df0(*(void**)(s+0x28d),handle);
 return 1;
}
PCREG(6471a0,read_frames);
extern "C" u32 THISCALL ext_516250(void*);
extern "C" void THISCALL ext_52a070(void*,u32);
extern "C" void THISCALL ext_516f40(void*,void*);
extern "C" void THISCALL wheel_dust(u8* s){
 u32 vec[3]={0,0x3f000000,0xbf800000};
 float product=*(float*)(s+0x78)**(float*)(s+0x68);
 float speed=bitsf(fbits(*(float*)(s+0x7c))&0x7fffffff);float amplitude=0;
 float roll=vcall<float>(G(void*,0x70039c),0x1c0,0x6a0b90u,0x280u);u32 id=0;
 if(G(float,0x67a284)>=roll)id=ext_516250(s+0x785);
 if(speed>G(float,0x680a70))amplitude=G(float,0x67da1c)/speed;
 if(0.0f>product)vec[2]=0x3f800000;
 for(s32 i=0;i<*(s32*)(s+0x8d);++i){
  u8* entry=s+0xec2+0x133*i;
  if(id)ext_52a070(entry-0x4d,id);
  *(float*)entry=amplitude;*(float*)(entry+0x79)=amplitude;ext_516f40(entry+0x69,vec);
 }
 for(s32 i=0;i<*(s32*)(s+0x91);++i){
  u8* entry=s+0x185a+0x133*i;
  if(id)ext_52a070(entry-0x4d,id);
  *(float*)entry=amplitude;*(float*)(entry+0x79)=amplitude;ext_516f40(entry+0x69,vec);
 }
}
PCREG(5292c0,wheel_dust);
extern "C" void THISCALL save_chamber(u8* s,void* writer){
 vcall<void>(writer,0x4c,*(float*)(s+0x2c));
 u32 current=*(u32*)(s+0x28);if(!current){vcall<void>(writer,0x60,0u);return;}
 vcall<void>(writer,0x60,1u);
 const u32 offsets[6]={0x10,0x14,0x1c,0x18,0x20,0x24};
 for(u32 i=0;i<6;++i)if(current==*(u32*)(s+offsets[i])){vcall<void>(writer,0x3c,i+1);return;}
 typedef void(*fn)();G(fn,0x7003b0)();vcall<void>(writer,0x3c,(u32)writer);
}
PCREG(486f30,save_chamber);
