from pilot import S
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub

def g(c):
 clear_hooks(c);r=c.rng;e=c.emu;e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 hook_rec(c,0x633654,0,pop=0)
 values=[r.getrandbits(32) for _ in range(3)]
 def position(em,k):
  for i,v in enumerate(values):em.w32(em.arg32(0)+4*i,v)
 sender=obj(c,16,{0x84:pystub(c,1,this=True,stackmark=[0],side=position),0x130:pystub(c,3,this=True,deref={2:5})})
 me=rnd(c,0x70);e.w32(me+0x44,sender)
 for off in [0x55,0x59,0x5d,0x61]:
  camera=obj(c,16,{0x230:pystub(c,0,this=True,ret=r.choice([0,r.getrandbits(32)]))})
  e.w32(me+off,r.choice([0,camera,camera]))
 return [me]
S(0x5d3780,'GUESS dispatch shake to optional cameras','thiscall',None,ret=None,gen=g,note='batch124021')
