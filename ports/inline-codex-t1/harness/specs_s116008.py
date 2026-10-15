import struct
from pilot import S,EDGE_F
from recruits_util import rnd,obj,sysobj,clear_hooks,pystub,hook_rec

def put(e,p,v):e.wbytes(p,struct.pack('<f',v))
def g486(c):
 clear_hooks(c);r=c.rng;e=c.emu
 actor=obj(c,32,{0x144:pystub(c,1,this=True),0x1e0:pystub(c,1,this=True,ret=r.choice([0,1,0x100,0x101,r.getrandbits(32)])),0x2d0:pystub(c,2,this=True),0x2f0:pystub(c,3,this=True)})
 hand=obj(c,32,{8:pystub(c,2,this=True)})
 sysobj(c,table_slots={0x4c:pystub(c,1,this=True,ret=r.getrandbits(32))})
 hook_rec(c,0x467410,6,this=True)
 s=rnd(c,32);e.w32(s+8,actor);e.w32(s+0x10,hand)
 return [s]

def g40c(c):
 clear_hooks(c);r=c.rng;e=c.emu
 data=rnd(c,256)
 for i in range(64):put(e,data+4*i,r.choice(EDGE_F) if r.random()<0.2 else r.uniform(-100,100))
 for i in range(256):put(e,0x6f1f58+4*i,r.choice(EDGE_F) if r.random()<0.1 else r.uniform(-5,5))
 x0=r.randrange(16);x1=x0+r.randrange(1,33);y0=r.randrange(256);y1=r.randrange(256)
 return [x0,x1,y0,y1,data]

def g551(c):
 clear_hooks(c);r=c.rng;e=c.emu
 cells=[rnd(c,8) for _ in range(6)]
 hook_rec(c,0x5003d0,1,this=True,ret=lambda em,k:cells[em.arg32(0)%6])
 def side(em,k):em.w32(em.reg('ecx'),em.arg32(0))
 hook_rec(c,0x500360,1,this=True,side=side)
 ptr=rnd(c,16);o=obj(c,32,{0x4c:pystub(c,0,this=True,ret=ptr)})
 a=obj(c,32,{0x18:pystub(c,1,this=True,ret=r.choice([0,o,o,o]))})
 return [a,r.getrandbits(32),rnd(c,24)]
S(0x4860b0,'GUESS pickup item callback','thiscall',None,ret='al',gen=g486,note='batch116008')
S(0x40c320,'GUESS table scaled span','cdecl',None,ret=None,gen=g40c,note='batch116008',nan_heap=True)
S(0x551160,'GUESS set six float cells','stdcall',None,ret='eax',gen=g551,note='batch116008')
