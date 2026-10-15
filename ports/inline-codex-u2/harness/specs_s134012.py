from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,pystub
import struct

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 def put(p,vs):e.wbytes(p,struct.pack('<'+'f'*len(vs),*vs))
 p=[r.choice([-0.,0.,-1.,1.,-10.,10.,r.uniform(-20,20)]) for _ in range(3)]
 def pos(em,k):em.wbytes(em.arg32(0),struct.pack('<3f',*p))
 def transform(em,k):
  ptr=em.arg32(0);em.wf32(ptr+4,struct.unpack('<f',em.rbytes(ptr+4,4))[0]+0.25)
 def direction(em,k):
  ptr=em.arg32(0);em.wf32(ptr+8,struct.unpack('<f',em.rbytes(ptr+8,4))[0]*2)
 actor=obj(c,0x40,{0x84:pystub(c,1,this=True,deref={0:3},side=pos)})
 me=obj(c,0x400,{0x8c:pystub(c,1,this=True,deref={0:3},side=transform),0x88:pystub(c,1,this=True,deref={0:3},side=direction),0x130:pystub(c,3,this=True,deref={2:8})})
 shape=rnd(c,0x80);put(shape+0x24,[r.uniform(-100,100)]);e.w32(me+0x5c,shape);e.w32(me+0x2af,actor)
 for off in [0x21b,0x22b,0x223]:put(me+off,[r.choice([-1,0,1,10,20,100])])
 put(me+0x29b,[r.uniform(-100,100) for _ in range(3)])
 sysobj(c,table_slots={0x4c:pystub(c,1,this=True,ret=r.getrandbits(32))});e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 return [me]
S(0x515100,'GUESS push actor within vehicle bounds','thiscall',None,ret='al',gen=gen)
