from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,pystub

def gen(c):
 clear_hooks(c);r=c.rng;e=c.emu
 ints=[r.getrandbits(32) for _ in range(4)]
 def integer(em,k):em.w32(em.arg32(1),ints[0])
 def floating(em,k):em.w32(em.arg32(1),ints[1+k%2])
 rgb=rnd(c,12)
 cfg=obj(c,16,{0x88:pystub(c,2,this=True,nullflag=(1,),side=integer),0x84:pystub(c,2,this=True,nullflag=(1,),side=floating),0x9c:pystub(c,2,this=True,ret=rgb)})
 first=rnd(c,0x680);final=obj(c,16,{0x100:pystub(c,1,this=True,ret=ints[3])})
 sysobj(c,table_slots={0x138:pystub(c,0,this=True,ret=cfg),0x58:pystub(c,1,this=True,ret=lambda em,k:[first,final][k%2])})
 e.w32(0x7003b0,pystub(c,0))
 return [rnd(c,0x150)]
S(0x5de260,'load effect configuration','thiscall',None,ret=None,gen=gen,nan_heap=True)
