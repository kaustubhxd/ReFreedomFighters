#include "ff.h"
extern "C" void THISCALL ext_4e6bf0(void*,void*);
static u32 THISCALL remove(u8*me,u32 index,u32 value,u32 erase){auto head=(*(u32***)(me+0x1d))+index;u32*node=*head,*prev=0;u32 pos=0;
 while(node){for(pos=0;pos<3;++pos)if(node[pos]==value)goto found;prev=node;node=(u32*)node[3];}return 1;
found:if(!(u8)erase)return 0;u32*hole=node+pos;*hole=0;u32*source=node+pos+1;u32 next=pos+1;
 for(;;){if(next==3){auto n=(u32*)node[3];if(!n)break;prev=node;node=n;source=node;next=0;}while(next<3){*hole=*source;hole=source++;++next;}}
 *hole=0;if(!node[0]&&!node[1]&&!node[2]){if(prev)prev[3]=0;else *head=0;ext_4e6bf0(me+4,node);}return 0;}
PCREG(49cbb0,remove);
