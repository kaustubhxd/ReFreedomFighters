import struct
from pilot import S,EDGE_F
from recruits_util import rnd,clear_hooks,hook_rec,pystub

def gen(c):
 clear_hooks(c);r=c.rng;e=c.emu
 me=rnd(c,0x70);m=rnd(c,0x40);e.w32(me+0x4b,r.choice([0,m,m,m]))
 for off in (0x20,0x53):e.wf32(me+off,r.choice([0.,.5,1.,-1.,r.uniform(-10,10)]))
 vecs=[[r.choice([0.,1.,-1.,r.uniform(-10,10)]) for _ in range(3)] for _ in range(5)]
 def sample(em,k):
  em.wbytes(em.arg32(0),struct.pack('<fff',*vecs[0]));em.wbytes(em.arg32(1),struct.pack('<fff',*vecs[1+k%2]))
 hook_rec(c,0x460af0,3,this=True,nullflag=(0,1),side=sample)
 def dot(em,k):em.calllog.append(('dot-inputs',em.rbytes(em.reg('ecx'),12).hex(),em.rbytes(em.reg('edx'),12).hex()))
 hook_rec(c,0x4e0030,0,side=dot,st0=r.choice(EDGE_F+[r.uniform(-10,10)]))
 vecs[3]=[r.choice([0.,1.,-1.,r.uniform(-10,10)]) for _ in range(3)]
 def cross(em,k):
  em.calllog.append(('cross-inputs',em.rbytes(em.reg('edx'),12).hex(),em.rbytes(em.arg32(0),12).hex()))
  em.wbytes(em.reg('ecx'),struct.pack('<fff',*vecs[3]))
 hook_rec(c,0x446ee0,1,nullflag=(0,),side=cross)
 hook_rec(c,0x633654,0)
 e.w32(0x7003b0,pystub(c,0))
 def fb():return struct.unpack('<I',struct.pack('<f',r.choice(EDGE_F+[r.uniform(-2,2)])))[0]
 return [me,fb(),fb()]
S(0x522f60,'sample signed map angle','thiscall',None,ret='st0',gen=gen)
