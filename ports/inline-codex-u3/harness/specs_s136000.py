import struct
from pilot import S
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 def put(p,vals):e.wbytes(p,struct.pack('<3f',*vals))
 def vals():return [r.uniform(-50,50) for _ in range(3)]
 a,b,d=vals(),vals(),vals()
 def vt(em,k):put(em.arg32(0),a);put(em.arg32(1),b)
 s=obj(c,0x1660,{0x80:pystub(c,2,this=True,stackmark=(0,1),side=vt)})
 p=rnd(c,0x30);e.w32(s+0x5c,p);put(p+8,vals());put(s+0x60,vals());put(s+0x6c,vals())
 e.wbytes(s+0x378,struct.pack('<2f',r.uniform(-10,10),r.uniform(-10,10)))
 e.wbytes(s+0x133,bytes([r.randrange(2)]));e.wbytes(s+0x1614,bytes([r.randrange(2)]))
 def direction(em,k):put(em.arg32(0),d)
 hook_rec(c,0x523330,1,this=True,stackmark=(0,),side=direction)
 # Normalize real input through a deterministic observable hook; preserve a nonzero y input check.
 def norm(em,k):
  q=em.reg('ecx');v=struct.unpack('<3f',em.rbytes(q,12));em.calllog.append(('norm',v));
  length=sum(x*x for x in v)**0.5
  if length:em.wbytes(q,struct.pack('<3f',*(x/length for x in v)))
 hook_rec(c,0x44c840,0,this='mark',side=norm,st0=1.0)
 def flip(em,k):
  q=em.reg('ecx');em.calllog.append(('flip',em.rbytes(q,12)));em.w32(q,em.r32(q)^0x80000000);em.w32(q+8,em.r32(q+8)^0x80000000)
 hook_rec(c,0x4e09b0,0,this='mark',side=flip)
 hook_rec(c,0x525640,2,this=True,deref={0:3,1:3})
 hook_rec(c,0x525380,2,this=True,deref={0:3,1:3})
 hook_rec(c,0x7003b0,0,pop=0,ret=r.getrandbits(32))
 return [s,r.getrandbits(32) if r.randrange(2) else 0]
S(0x517d50,'GUESS initialize car position and direction','thiscall',None,ret=None,gen=gen)
