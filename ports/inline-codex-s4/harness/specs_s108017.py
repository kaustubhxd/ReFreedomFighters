from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub

def base(c):
 clear_hooks(c);c.emu.w32(0x7003b0,pystub(c,0,ret=c.rng.getrandbits(32),pop=0))

def g7a10(c):
 base(c);e=c.emu;r=c.rng
 me=rnd(c,0x3c);n=r.choice([0,1,2,3,5,-1]);count=rnd(c,4);e.w32(count,n&0xffffffff);e.w32(me+0x10,count)
 for group in range(3):
  descriptors=rnd(c,4*max(n,1));values=rnd(c,4*max(n,1))
  for i in range(max(n,0)):
   d=rnd(c,0x18);e.w32(d+0x14,pystub(c,1,pop=0));e.w32(descriptors+4*i,d)
  e.w32(me+0x28+4*group,descriptors);e.w32(me+0x14+4*group,values)
 a=rnd(c,0x20);b=rnd(c,0x20);e.w32(me+0x20,r.choice([0,a]));e.w32(me+0x24,r.choice([0,a,b]))
 hook_rec(c,0x40fa40,1,pop=0);hook_rec(c,0x403ee0,1,pop=0)
 # Log content before freeing the structure so its final 60-byte clear is checked too.
 def freeing(em,k):
  if em.arg32(0)==me:em.calllog.append(('cleared_struct',em.rbytes(me,0x3c)))
 hook_rec(c,0x634d52,1,pop=0,side=freeing)
 return [r.choice([0,me,me,me])]

def g20e0(c):
 base(c);e=c.emu;r=c.rng
 category=r.choice([0,1,2,0x42,0x42,3,4,0xffff]);index=r.randrange(24);key=(category<<16)|index
 config=rnd(c,0x30)
 for i in range(3):
  e.w32(config+16*i,r.choice([0,3,7,14,0xfffffffc]));e.w32(config+16*i+8,rnd(c,0x100));e.w32(config+16*i+12,r.choice([0,1,3,8,0xffffffff]))
 system=sysobj(c);e.w32(system+0x190b,config)
 self=obj(c,0x20,{0x10:pystub(c,1,this=True,ret=key)})
 return [self,r.choice([0,1,4,12,20,0xffffffff])]
S(0x407a10,'GUESS destroy three parallel arrays and clear structure','cdecl',None,ret=None,gen=g7a10)
S(0x4320e0,'GUESS extract input record by category or range','thiscall',None,ret='eax',gen=g20e0)
