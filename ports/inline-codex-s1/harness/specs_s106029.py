from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 lists=[obj(c,0x40,{0x10:pystub(c,0,this=True,ret=r.choice([0,r.getrandbits(32)])),8:pystub(c,2,this=True)}) for _ in range(2)]
 init=[r.getrandbits(32),r.getrandbits(32)]
 def initialize(em,k):em.w32(em.reg('ecx'),init[k%2])
 hook_rec(c,0x467410,6,this=True,side=initialize)
 sysobj(c,table_slots={0x4c:pystub(c,1,this=True,ret=r.getrandbits(32))})
 me=rnd(c,0x20);e.w32(me+0xc,lists[0]);e.w32(me+0x10,lists[1]);e.w32(0x7003b0,pystub(c,0))
 return [me]
S(0x4862b0,'initialize and exchange list results','thiscall',None,ret='al',gen=gen)
