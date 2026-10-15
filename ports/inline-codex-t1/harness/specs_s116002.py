import struct, math
from pilot import S,F,EDGE_F
from recruits_util import rnd,obj,sysobj,clear_hooks,pystub,hook_rec

def put(e,p,v):e.wbytes(p,struct.pack('<f',v))
def ceil_stub(e,r):
 raw=e.rbytes(e.reg('esp')+4,8);x=struct.unpack('<d',raw)[0]
 y=x if not math.isfinite(x) else float(math.ceil(x))
 if y==0:y=math.copysign(0.,x)
 e.calllog.append(('ceil',raw.hex()))
 e.ret(st0=y)
def g530(c):
 c.emu.stub_import('ceil',ceil_stub)
 clear_hooks(c);r=c.rng;e=c.emu;s=rnd(c,0x60);v=rnd(c,12);out=rnd(c,12)
 for i in range(3):
  lo=r.uniform(-100,100);hi=lo+r.uniform(0.01,100)
  if r.random()<0.1:hi=lo
  put(e,s+6+4*i,lo);put(e,s+0x12+4*i,hi)
  put(e,v+4*i,r.choice(EDGE_F) if r.random()<0.15 else r.uniform(-1000,1000))
  e.w32(s+0x3c+4*i,r.choice([0,1,2,10,100,0xffffffff,r.getrandbits(32)]))
 return [s,out,v]

def g451(c):
 clear_hooks(c);r=c.rng;e=c.emu
 # First triple sometimes exactly zero after subtracting 0.5; following triples terminate.
 prefix=[0.5]*3 if r.random()<0.3 else []
 vals=prefix+[r.uniform(0,1),r.uniform(0,1),r.uniform(0,1)]+[0.,1.,0.]
 sysobj(c,slots={0x1c0:pystub(c,2,this=True,st0=lambda em,k:vals[min(k,len(vals)-1)])})
 return [rnd(c,16)]

def g516(c):
 clear_hooks(c);r=c.rng;e=c.emu;s=rnd(c,0xe0)
 for off in [0xc,0x11,0x15,0x19,0x1d,0x41,0x55]:put(e,s+off,r.uniform(-10,10))
 values=[r.uniform(-10,10),r.uniform(-10,10)]
 hook_rec(c,0x5243a0,0,this=True,st0=lambda em,k:values[k%2])
 hook_rec(c,0x5246a0,1,this=True,st0=r.uniform(-10,10))
 for addr in [0x5245c0,0x524540]:
  val=r.choice([-10.,-1.,0.,1.,10.,r.uniform(-10,10),float('nan')])
  def side(em,k,v=val):put(em,em.reg('ecx'),v)
  hook_rec(c,addr,1,this=True,side=side)
 hook_rec(c,0x524370,0,this=True,ret=r.getrandbits(32))
 return [s,F(r.uniform(-1,1))]

def g5d9(c):
 clear_hooks(c);r=c.rng;e=c.emu
 sys=sysobj(c)
 child=obj(c,32,{0x23c:pystub(c,1,this=True,deref={0:4}),0x250:pystub(c,0,this=True)})
 s=rnd(c,0x80);e.w32(s+0x44,child)
 a,b=r.randrange(65536),r.randrange(65536);e.wbytes(s+0x50,struct.pack('<HH',a,b))
 for off in [0x58,0x5c,0x60,0x64]:put(e,s+off,r.choice(EDGE_F) if r.random()<0.2 else r.uniform(-100,100))
 return [s,r.choice([a,b,r.randrange(65536)])|(r.getrandbits(16)<<16),r.getrandbits(32)]
S(0x530db0,'GUESS local vector ceil conversion','thiscall',None,ret=None,gen=g530,note='batch116002')
S(0x451250,'GUESS random unit direction','thiscall',None,ret=None,gen=g451,note='batch116002')
S(0x516070,'GUESS damper physics step','thiscall',None,ret=None,gen=g516,note='batch116002',nan_heap=True)
S(0x5d90c0,'GUESS event rectangle update','thiscall',None,ret='eax',gen=g5d9,note='batch116002',nan_heap=True)
