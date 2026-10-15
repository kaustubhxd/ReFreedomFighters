import struct
from pilot import S,EDGE_F
from recruits_util import rnd,obj,sysobj,clear_hooks,pystub,hook_rec

def put(e,p,v):e.wbytes(p,struct.pack('<f',v))
def g47a(c):
 clear_hooks(c);r=c.rng;e=c.emu
 vals=[r.uniform(-100,100) for _ in range(3)]
 def position(em,k):
  for i,v in enumerate(vals):put(em,em.arg32(0)+4*i,v)
 s=obj(c,0x780,{0x84:pystub(c,1,this=True,deref={0:3},side=position),0x624:pystub(c,1,this=True),0x634:pystub(c,2,this=True,deref={0:3}),0x5e8:pystub(c,1,this=True),0x128:pystub(c,3,this=True)})
 e.wbytes(s+0x74e,bytes([r.choice([0,1,1,255])]))
 for i in range(3):put(e,s+0x742+4*i,r.uniform(-100,100))
 record=rnd(c,12)
 def side(em,k):em.wbytes(record,em.rbytes(em.reg('edx'),12))
 constants=[struct.unpack('<f',e.rbytes(a,4))[0] for a in [0x680a8c,0x68af1c,0x67da2c,0x68af14]]
 hook_rec(c,0x4e0870,0,this=True,st0=r.choice(constants+[-1.,0.,float('nan'),float('inf'),r.uniform(0,10)]),side=side)
 return [s,r.getrandbits(32)]

def g5d4(c):
 clear_hooks(c);r=c.rng;e=c.emu;objp=rnd(c,16);config=rnd(c,0x60);e.w32(objp+8,config)
 matrix=rnd(c,36);out=matrix if r.random()<0.1 else rnd(c,12)
 for i in range(3):put(e,config+0x40+4*i,r.uniform(-10,10))
 for p,n in [(matrix,9),(out,3)]:
  for i in range(n):put(e,p+4*i,r.choice(EDGE_F) if r.random()<0.1 else r.uniform(-10,10))
 sysobj(c,slots={0x1c0:pystub(c,2,this=True,st0=lambda em,k:r.uniform(-2,2))})
 return [rnd(c,16),objp,matrix,out]
S(0x47a500,'GUESS actor path request','thiscall',None,ret=None,gen=g47a,note='batch116013')
S(0x5d4e80,'GUESS random spread along matrix axes','thiscall',None,ret=None,gen=g5d4,note='batch116013',nan_heap=True)
