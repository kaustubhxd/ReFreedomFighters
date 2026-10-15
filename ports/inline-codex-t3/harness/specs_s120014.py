from pilot import S
from recruits_util import rnd,clear_hooks,pystub,obj

def display(c):
 clear_hooks(c);e,r=c.emu,c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 self=rnd(c,0x900);sys=rnd(c,0x50);e.w32(0x70039c,sys)
 for off in (0x872,0x876):
  w=obj(c,0x20,{0xbc:pystub(c,1,this=True),0x284:pystub(c,1,this=True)})
  e.w32(self+off,0 if off==0x876 and r.random()<0.4 else w)
 owner=obj(c,0x20,{0x12c:pystub(c,3,this=True)});e.w32(self+0x44,owner)
 cnt=r.randint(0,100);idx=r.randint(0,cnt+2)
 e.w32(self+0x85c,cnt);e.w32(self+0x860,idx)
 for i in range(cnt+3):e.w8(self+0x5c+i,r.choice([0,0,65,66,255]))
 e.w32(self+0x86e,r.choice([0,r.getrandbits(32)]))
 e.wf32(self+0x54,r.choice([0.0,-0.0,1.0,-1.0,float('nan'),float('inf'),r.uniform(-100,100)]))
 return [self]
S(0x572720,'CSubtitle::DisplayNextLines','thiscall',None,ret=None,gen=display)
