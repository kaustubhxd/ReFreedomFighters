import struct
from pilot import S,F,EDGE_F
from recruits_util import rnd,obj,sysobj,clear_hooks,pystub,hook_rec

def put(e,p,v):e.wbytes(p,struct.pack('<f',v))
def g4a2(c):
 clear_hooks(c);r=c.rng;e=c.emu;s=rnd(c,0x140);reader=rnd(c,16)
 buf=rnd(c,8);e.w32(reader,r.choice([0,buf,buf,buf]))
 hook_rec(c,0x4e5e60,0,this=True,ret=lambda em,k:r.choice([0,1,r.getrandbits(32)]))
 hook_rec(c,0x4e5e80,0,this=True,st0=lambda em,k:r.uniform(-1000,1000))
 hook_rec(c,0x4e5e40,0,this=True,ret=r.getrandbits(32))
 # Reader calls can advance the next token, like the real DBREAD.
 kinds=[r.choice([2,0x42,0x82,10,0x4a,255,0,1]) for _ in range(7)]
 e.wbytes(buf,bytes([kinds[0]]))
 def side(em,k):e.wbytes(buf,bytes([kinds[(k+1)%len(kinds)]]))
 hook_rec(c,0x4e5e60,0,this=True,ret=lambda em,k:r.choice([0,1,r.getrandbits(32)]),side=side)
 return [s,reader]

def g436(c):
 clear_hooks(c);r=c.rng;e=c.emu;s=rnd(c,0x80);delta=rnd(c,8)
 for p in [s+0x64,s+0x68,delta,delta+4]:put(e,p,r.choice(EDGE_F) if r.random()<0.15 else r.uniform(-100,100))
 input=obj(c,32,{0x10:pystub(c,0,this=True,ret=r.choice([0,delta,delta]))});e.w32(s+0x10,input);e.w32(s+0x1c,r.choice([0,1,2,0xffffffff]))
 dims=[r.choice([0,1,50,100,0x7fffffff,0xffffffff]),r.choice([0,1,50,100,0x7fffffff,0xffffffff])]
 service=obj(c,32,{0xd8:pystub(c,0,this=True,ret=dims[0]),0xdc:pystub(c,0,this=True,ret=dims[1])})
 sys=sysobj(c);e.w32(sys+0x190f,service);e.wbytes(sys+0x6d,bytes([r.choice([0,1])]))
 for p in [sys+0x9e7,sys+0x9eb,sys+0x9ef,0x6ff958,0x6ff95c,0x6ff960]:put(e,p,r.uniform(-100,100))
 return [s]

def g516(c):
 clear_hooks(c);r=c.rng;e=c.emu;s=rnd(c,0xb0);box=rnd(c,32)
 for off in [0,4,8,0x41]:put(e,s+off,r.uniform(-100,100))
 height=r.uniform(-100,100)
 def side_box(em,k):put(em,em.arg32(0)+8,height)
 hook_rec(c,0x4e8c00,4,this=True,nullflag=(0,),deref={1:3,2:3},ret=r.choice([0,1,0x100,0x101]),side=side_box)
 def side_ray(em,k):put(em,s+0x95,height)
 service=obj(c,32,{0x2e0:pystub(c,6,this=True,deref={0:14},ret=r.choice([0,1,0x100,0x101]),side=side_ray)})
 render=rnd(c,0xb00);e.w32(render+0xadc,service);sys=sysobj(c);e.w32(sys+0x9b,render)
 return [s,F(r.uniform(-100,100)),r.choice([0,box,box])]
S(0x4a24a0,'GUESS read animation event data','thiscall',None,ret=None,gen=g4a2,note='batch116010')
S(0x4362f0,'GUESS pointer delta and screen clamp','thiscall',None,ret=None,gen=g436,note='batch116010',nan_heap=True)
S(0x516130,'GUESS damper ground probe','thiscall',None,ret='st0',gen=g516,note='batch116010')
