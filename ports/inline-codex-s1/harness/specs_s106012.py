from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 enabled=r.choice([0,1,2,0xff])
 def flag(em,k):em.wbytes(em.arg32(1),bytes([enabled]))
 conf=obj(c,16,{0x90:pystub(c,2,this=True,nullflag=(1,),side=flag)})
 vals=[r.getrandbits(32) for _ in range(4)]
 def value(em,k):em.w32(em.arg32(1),vals[k%4])
 values=obj(c,16,{0x88:pystub(c,2,this=True,nullflag=(1,),side=value)})
 child=obj(c,16,{0x12c:pystub(c,2,this=True)})
 me=rnd(c,0x60);e.w32(me+0x44,child)
 ids=[r.getrandbits(32) for _ in range(4)]
 sysobj(c,table_slots={0x134:pystub(c,0,this=True,ret=conf),0x138:pystub(c,0,this=True,ret=values),0x4c:pystub(c,1,this=True,ret=r.getrandbits(32)),0x114:pystub(c,5,this=True,ret=lambda em,k:ids[k%4])})
 hook_rec(c,0x633654,0)
 e.w32(0x7003b0,pystub(c,0))
 return [me]
S(0x5d6af0,'bind conditional configuration set','thiscall',None,ret=None,gen=gen)
