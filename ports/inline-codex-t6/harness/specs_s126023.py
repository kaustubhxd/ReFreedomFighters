from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub
import struct

def gen(c):
 clear_hooks(c);r=c.rng;e=c.emu;me=rnd(c,0x1d40);state=rnd(c,0x70);timer=rnd(c,0x30)
 def wf(a,v):e.wbytes(a,struct.pack('<f',v))
 e.wbytes(me+0x60,bytes([r.choice([0,1,1,1])]))
 e.w32(me+0x58,r.choice([0,state,state,state]));e.w32(state+0x48,r.randrange(2))
 for off in [0x58,0x59]:e.wbytes(state+off,bytes([r.randrange(2)]))
 e.wbytes(state+0x50,e.rbytes(0x6785d0,4) if r.random()<0.4 else struct.pack('<f',r.uniform(-100,10000)))
 wf(timer+0xe,r.uniform(-100,10000));e.wbytes(timer,bytes([r.randrange(2)]))
 e.w32(me+0x1d0f,r.choice([0,rnd(c,0x20)]))
 for off in [0x1d1b,0x1d1f,0x1d23,0x1d27]:wf(me+off,r.uniform(-10,10))
 def fmt(em,k):em.wbytes(em.arg32(1),b'formatted timer text\0'.ljust(32,b'\0'))
 formatter=obj(c,0x20,{0x198:pystub(c,5,pop=0,nullflag=(1,),side=fmt)})
 sysobj(c,slots={0x190:pystub(c,0,this=True,ret=formatter)})
 hook_rec(c,0x5a4690,1,this=True,ret=timer);hook_rec(c,0x5a45c0,1,this=True);hook_rec(c,0x5aaa80,3,this=True,deref={2:8})
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 return [me]
S(0x5ea960,'GUESS HUD timer text and position','thiscall',None,ret=None,gen=gen)
