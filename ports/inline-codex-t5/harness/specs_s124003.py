from pilot import S
from recruits_util import rnd,obj,clear_hooks,pystub

def g(c):
 clear_hooks(c);r=c.rng;e=c.emu
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 writer=obj(c,0x20,{off:pystub(c,1,this=True,ret=r.getrandbits(32)) for off in [0x40,0x60,0x4c,0x44]})
 return [rnd(c,0x70),writer]
S(0x4c28e0,'GUESS save sound segment pitch','thiscall',None,ret='al',gen=g,note='batch124003')
