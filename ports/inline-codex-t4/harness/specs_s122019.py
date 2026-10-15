from pilot import S
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng
 hook_rec(c,0x7003b0,4,pop=0,ret=r.getrandbits(32))
 hook_rec(c,0x45f960,1,this=True)
 allargs=e.alloc(16*4,4)
 def save(em,k):em.w32(allargs+4*k,em.arg32(0))
 stream=obj(c,0x20,{0x3c:pystub(c,1,this=True,side=save),0x44:pystub(c,1,this=True),0x4c:pystub(c,1,this=True)})
 return [rnd(c,0x60),stream]
S(0x4550f0,'GUESS save material descriptor','thiscall',None,ret='al',gen=gen)
