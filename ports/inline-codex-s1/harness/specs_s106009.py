from pilot import S,EDGE_F
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub
import struct

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 handle=r.getrandbits(32);result=r.choice([0,r.getrandbits(32)])
 def initialize(em,k):
  p=em.arg32(0);em.w32(p,em.r32(p)^0x12345678)
 service=obj(c,16,{0x38:pystub(c,2,this=True,ret=handle,side=initialize),0x3c:pystub(c,7,this=True,ret=result)})
 manager=obj(c,16,{0x20:pystub(c,0,this=True,ret=service)})
 so=sysobj(c);e.w32(so+0x190f,manager)
 me=rnd(c,0x60);e.w32(me+0x44,r.choice([0xffffffff,r.getrandbits(32)]));e.w32(me+0x40,rnd(c,64))
 hook_rec(c,0x45b620,0,this=True,ret=r.randrange(16))
 e.w32(0x7003b0,e.stub_fn('assert',lambda em,k:em.ret(eax=0)))
 def fb():return struct.unpack('<I',struct.pack('<f',r.choice(EDGE_F+[r.uniform(-10,10)])))[0]
 return [me,rnd(c,0x60),r.getrandbits(32),fb(),fb(),r.getrandbits(32)]
S(0x45bb10,'submit service request','thiscall',None,ret='eax',gen=gen)
