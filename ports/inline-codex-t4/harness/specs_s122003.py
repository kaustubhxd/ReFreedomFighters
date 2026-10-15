from pilot import S
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub

def gen(c):
 clear_hooks(c)
 e,r=c.emu,c.rng
 hook_rec(c,0x7003b0,4,ret=r.getrandbits(32),pop=0)
 s=rnd(c,0x60);a=rnd(c,8);cfg=rnd(c,0x30)
 mgr=obj(c,0x20,{4:pystub(c,1,this=True)})
 e.w32(s+0x44,cfg);e.w32(cfg+0x18,mgr)
 last=rnd(c,24) if r.randrange(2) else 0;e.w32(s+0x4c,last)
 n=rnd(c,24)
 bits=r.choice([0,0x80000000,0x3f800000,0xbf800000,0x7fc00000,0x7f800000,r.getrandbits(32)])
 e.w32(a+4,bits);e.w32(n+4,bits if r.randrange(2) else r.choice([0,0x7fc00000,0x3f800000]))
 hook_rec(c,0x41e290,1,pop=0,ret=n if r.randrange(4) else 0)
 hook_rec(c,0x4fdb70,0,this=True)
 return [s,a]
S(0x4fbb20,'GUESS append timed list node','thiscall',None,ret='eax',gen=gen)
