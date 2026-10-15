from pilot import S
from recruits_util import rnd,obj,pystub,clear_hooks,hook_rec

def gen(c):
 clear_hooks(c);r=c.rng
 s=rnd(c,0x90)
 writer=obj(c,0x20,{off:pystub(c,1,this=True,ret=r.getrandbits(32),deref={0:3} if off==0x68 else None) for off in [0x64,0x3c,0x4c,0x60,0x68]})
 hook_rec(c,0x7003b0,0,ret=r.getrandbits(32))
 return [s,writer]
S(0x516e20,'GUESS serializeSettings','thiscall',None,ret='al',gen=gen)
