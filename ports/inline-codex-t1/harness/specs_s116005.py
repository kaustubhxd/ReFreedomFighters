import struct
from pilot import S,F,EDGE_F
from recruits_util import rnd,obj,sysobj,clear_hooks,pystub,hook_rec

def put(e,p,v):e.wbytes(p,struct.pack('<f',v))
def g558(c):
 clear_hooks(c);r=c.rng;e=c.emu
 cells=[rnd(c,8) for _ in range(3)]
 hook_rec(c,0x5003d0,1,this=True,ret=lambda em,k:cells[em.arg32(0)%3])
 values=[r.getrandbits(32) for _ in range(3)]
 def side(em,k):
  for i,v in enumerate(values):em.w32(em.arg32(0)+4*i,v)
 source=obj(c,32,{0x84:pystub(c,1,this=True,nullflag=(0,),side=side)})
 service=obj(c,32,{0x218:pystub(c,3,this=True,deref={0:3,1:3})})
 render=rnd(c,0xb00);e.w32(render+0xadc,service)
 sys=sysobj(c,slots={0x1bc:pystub(c,2,this=True,ret=r.getrandbits(32))});e.w32(sys+0x9b,render)
 s=rnd(c,32);e.w32(s+0x1c,source);args=rnd(c,16);e.w32(args+4,rnd(c,16))
 return [s,args]

def g65c(c):
 clear_hooks(c);r=c.rng;e=c.emu
 normal=rnd(c,12);extent=normal if r.random()<0.1 else rnd(c,12)
 for p in [normal,extent]:
  for i in range(3):put(e,p+4*i,r.choice(EDGE_F) if r.random()<0.2 else r.uniform(-100,100))
 return [normal,extent,F(r.choice(EDGE_F) if r.random()<0.25 else r.uniform(-100,100))]

def g521(c):
 clear_hooks(c);r=c.rng;e=c.emu;sys=sysobj(c)
 s=rnd(c,0x400);source=rnd(c,0x20);e.w32(s+0x5c,source)
 e.wbytes(s+0x133,bytes([r.choice([0,0,1,255])]))
 for off in [8,12,16]:put(e,source+off,r.choice(EDGE_F) if r.random()<0.2 else r.uniform(-100,100))
 now=r.choice([0,1,1024,0x7fffffff,0x80000000,0xffffffff,r.getrandbits(32)])
 e.w32(sys+0x40,now);e.w32(s+0x382,r.choice([now,(now-1)&0xffffffff,(now+1)&0xffffffff,r.getrandbits(32)]))
 hook_rec(c,0x528100,2,this=True,deref={0:3,1:3})
 values=[r.getrandbits(32) for _ in range(6)]
 def side(em,k):
  for i in range(3):em.w32(em.arg32(0)+4*i,values[i]);em.w32(em.arg32(1)+4*i,values[3+i])
 hook_rec(c,0x525380,2,this=True,side=side)
 return [s]
S(0x558cb0,'GUESS emit script vector at position','thiscall',None,ret=None,gen=g558,note='batch116005')
S(0x65cb80,'GUESS plane extent intersection','fastcall',None,ret='al',gen=g65c,note='batch116005')
S(0x5212f0,'GUESS tank camera entry','thiscall',None,ret=None,gen=g521,note='batch116005')
