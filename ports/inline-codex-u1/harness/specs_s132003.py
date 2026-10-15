from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec,obj,pystub

def gen(c):
 clear_hooks(c);r=c.rng;hook_rec(c,0x7003b0,0,ret=r.getrandbits(32),pop=0)
 slots={s:pystub(c,2 if s==0x58 else 1,this=True,ret=r.getrandbits(32)) for s in [8,0x58,0x54,0x4c,0x3c,0x44,0x60]}
 return [rnd(c,0x1b60),obj(c,0x20,slots)]
S(0x42f8c0,'GUESS serialize scalar settings','thiscall',None,ret=None,gen=gen)
