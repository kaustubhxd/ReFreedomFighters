#include "ff.h"
extern "C" u32* THISCALL ext_4e6bc0(void*);
extern "C" void THISCALL ext_44edd0(void*,void*);
extern "C" void THISCALL ext_4e12e0(void*,void*,u32);
extern "C" void THISCALL ext_4e1440(void*,void*);
extern "C" u32 THISCALL ext_4e1600(void*);
extern "C" void THISCALL ext_4e1b30(void*);
static u32 THISCALL fn49c310(u8*s,u32 idx,u32*src,u32 count){u32**slot=G(u32**,s+0x1d)+idx;u32*node=*slot;bool fresh=false;
 if(!node){node=ext_4e6bc0(s+4);if(!node)return 0;*slot=node;fresh=true;}else{while(node[3])node=(u32*)node[3];if(node[2]){u32*n=ext_4e6bc0(s+4);node[3]=(u32)n;if(!n)return 0;node=n;fresh=true;}}
 if(fresh){node[0]=0;node[1]=0;node[2]=0;node[3]=0;}
 u32 pos=node[1]?2:node[0]?1:0;u32 left=count;
 while(left){while(pos<3){node[pos]=src[left-1];left--;if(!left)break;pos++;}if(!left)break;u32*n=ext_4e6bc0(s+4);node[3]=(u32)n;if(!n)return count-left;node=n;node[0]=0;node[1]=0;node[2]=0;node[3]=0;pos=0;}
 return count;}
PCREG(49c310,fn49c310);
static void THISCALL fn4f5b70(u8*s,void*p){ext_44edd0(s,p);for(u32 off=0x60;off<=0x6c;off+=4)ext_4e12e0(p,s+off,1);if((u8)ext_4e1600(p)==8)ext_4e12e0(p,s+0x70,1);else G(u32,s+0x70)=0;for(u32 off=0x74;off<=0x94;off+=4)ext_4e12e0(p,s+off,1);ext_4e1440(p,s+0x98);ext_4e1440(p,s+0x9c);ext_4e1b30(p);}
PCREG(4f5b70,fn4f5b70);
