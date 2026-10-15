from pilot import S
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub

def gen(c):
 clear_hooks(c);r=c.rng;e=c.emu;data=rnd(c,32);entries=rnd(c,64);listobj=rnd(c,0x20)
 item=obj(c,0x20,{0x4c:pystub(c,0,this=True,ret=listobj)})
 factory=obj(c,0x20,{0x18:pystub(c,1,this=True,ret=r.choice([0,item,item,item]))})
 def getter(em,k):
  a=data+4*em.arg32(0);em.w32(a,em.r32(a)^0x12345678)
 hook_rec(c,0x5003d0,1,this=True,ret=lambda em,k:entries+8*em.arg32(0),side=getter)
 def value(em,k):em.w32(em.reg('ecx'),em.arg32(0))
 hook_rec(c,0x500360,1,this=True,side=value);hook_rec(c,0x5002f0,1,this=True,side=value)
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 return [factory,r.getrandbits(32),data]
S(0x500540,'GUESS populate eight typed parameters','stdcall',None,ret='eax',gen=gen)
