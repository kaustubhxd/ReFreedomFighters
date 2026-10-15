import struct
from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng;s=rnd(c,0x300)
 for k in range(5):
  slot=s+0x228+0x24*k;o=rnd(c,0x20);g=rnd(c,0x60);e.w32(o+8,g);e.w32(slot+0x18,r.choice([0,o,o]))
  for off in [0x24,0x30,0x40]:e.wbytes(g+off,struct.pack('<3f',*(r.uniform(-20,20) for _ in range(3))))
  aux=rnd(c,0x20);e.w32(aux+8,g);e.w32(slot-4,r.choice([0,aux]))
 def project(em,k):
  p=em.arg32(1);v=struct.unpack('<3f',em.rbytes(p,12));em.wbytes(p,struct.pack('<3f',*(v[i]*scale[i]+shift[i] for i in range(3))))
 scale=[r.choice([-2.,-1.,0.,1.,2.]) for _ in range(3)];shift=[r.uniform(-10,10) for _ in range(3)]
 hook_rec(c,0x573c70,2,this=True,deref={1:3},side=project)
 hook_rec(c,0x7003b0,0,pop=0,ret=r.getrandbits(32))
 return [s]
S(0x574ff0,'GUESS project five map bounds','thiscall',None,ret=None,gen=gen)
