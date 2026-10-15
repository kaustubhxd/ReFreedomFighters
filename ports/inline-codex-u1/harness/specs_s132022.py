import struct
from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec

def fb(x):return struct.unpack('<I',struct.pack('<f',x))[0]
def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng;hook_rec(c,0x7003b0,0,ret=r.getrandbits(32),pop=0)
 p=rnd(c,0xe0);source=rnd(c,16);e.w32(p+0xcf,source);point=rnd(c,12);out=rnd(c,24)
 for k in range(3):e.w32(point+4*k,fb(r.uniform(-50,50)))
 vertices=[[fb(r.uniform(-30,30)) for _ in range(3)] for _ in range(4)];other=[[r.getrandbits(32) for _ in range(3)] for _ in range(4)];ids=[r.getrandbits(32) for _ in range(4)]
 def fetch(e,k):
  i=e.arg32(0)-1
  for j in range(3):e.w32(e.arg32(1)+4*j,vertices[i][j]);e.w32(e.arg32(2)+4*j,other[i][j])
  e.w32(e.arg32(3),ids[i])
 hook_rec(c,0x545d10,4,this=True,stackmark=(1,2,3),side=fetch)
 coeff=[fb(r.uniform(-3,3)) for _ in range(3)];rec=rnd(c,48)
 def solve(e,k):
  e.wbytes(rec,e.rbytes(e.reg('ecx'),36));e.wbytes(rec+36,e.rbytes(e.reg('edx'),12))
  for j,x in enumerate(coeff):e.w32(e.arg32(0)+4*j,x)
 hook_rec(c,0x547860,1,this='mark',stackmark=(0,),side=solve,ret=r.randrange(2))
 def store(e,k):
  for j in range(5):e.w32(e.arg32(0)+4*j,e.arg32(j+1))
 hook_rec(c,0x53f3b0,6,this=True,side=store)
 return [p,point,out]
S(0x53f230,'GUESS tetrahedron interpolation weight dispatch','thiscall',None,ret=None,gen=gen)
