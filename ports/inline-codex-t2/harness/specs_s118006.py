from pilot import S,F
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub
import struct

def start(c):clear_hooks(c);c.emu.w32(0x7003b0,pystub(c,0,ret=c.rng.getrandbits(32)))
def fv(r,n,scale=10):return struct.pack('<%df'%n,*[r.uniform(-scale,scale) for _ in range(n)])
def dynamics(c):
 start(c);r=c.rng;e=c.emu;s=rnd(c,0x2200);sys=sysobj(c)
 e.w32(sys+0x40,r.choice([0,1,1024,100000,0x7fffffff,0x80000000,r.getrandbits(32)]))
 e.wbytes(s+0x48,struct.pack('<f',r.choice([0.,1.,-1.,100.,-100.,r.uniform(-100,100)])))
 for off in [0x30,0x38]:e.wbytes(s+off,fv(r,1))
 e.wbytes(s+0x4c,fv(r,3))
 hook_rec(c,0x527b30,0,this=True);hook_rec(c,0x529760,0,this=True);hook_rec(c,0x527710,0,this=True)
 for addr,nargs,nwords in [(0x4de040,1,3),(0x4ddcb0,1,3),(0x4de480,0,9)]:
  rec=e.alloc(4*(nwords+1)*8);payload=bytes(r.getrandbits(8) for _ in range(36))
  def effect(em,k,rec=rec,payload=payload,nwords=nwords,addr=addr):
   src=em.reg('edx');dst=em.reg('ecx');row=rec+4*(nwords+1)*min(k,7)
   em.wbytes(row,em.rbytes(src,4*nwords));em.w32(row+4*nwords,k+1)
   if addr==0x4de480:
    for i in range(9):em.w32(dst+4*i,em.r32(dst+4*i)^em.r32(src+4*i))
   else:em.wbytes(dst,payload)
  hook_rec(c,addr,nargs,this='mark',side=effect)
 return [s]
S(0x527bd0,'GUESS_dynamics_update','thiscall',None,ret=None,gen=dynamics)

def tetra(c):
 start(c);r=c.rng;e=c.emu;point=rnd(c,12);verts=rnd(c,48)
 if r.randrange(2):e.wbytes(verts,fv(r,12));e.wbytes(point,fv(r,3))
 else:
  scale=r.uniform(0.1,100);vertices=[0.,0.,0.,scale,0.,0.,0.,scale,0.,0.,0.,scale]
  e.wbytes(verts,struct.pack('<12f',*vertices));e.wbytes(point,struct.pack('<3f',*[r.choice([0.,scale/8,scale/4,scale,scale*2,-scale]) for _ in range(3)]))
 return [rnd(c,4),point,verts]
S(0x451ba0,'GUESS_inside_tetrahedron','thiscall',None,ret='al',gen=tetra)

def end(c):
 start(c);r=c.rng;e=c.emu;s=rnd(c,4);grid=rnd(c,0x60);e.w32(s,grid)
 low=[r.uniform(-100,100) for _ in range(3)];high=[v+r.uniform(0.1,100) for v in low]
 e.wbytes(grid+6,struct.pack('<3f',*low));e.wbytes(grid+0x12,struct.pack('<3f',*high))
 for off in [0x3c,0x40,0x44]:e.w32(grid+off,r.choice([1,2,10,100,0x7fffffff,0xffffffff]))
 point=rnd(c,12);e.wbytes(point,fv(r,3,150));out=rnd(c,6);flag=rnd(c,4)
 same=r.randrange(2);returns=[r.choice([0,1,r.getrandbits(32)]) for _ in range(2)]
 def fill(em,k):
  p=em.arg32(0);src=em.arg32(1)
  for i in range(3):em.w16(p+2*i,int.from_bytes(em.rbytes(src+2*i,2),'little') if same else ((int.from_bytes(em.rbytes(src+2*i,2),'little')+1)&65535))
 hook_rec(c,0x530e80,5,this=True,stackmark=(0,),deref={1:-6},side=fill,ret=lambda em,k:returns[k%2])
 return [s,out,point,flag]
S(0x530ca0,'GUESS_path_end_cell','thiscall',None,ret='eax',gen=end)

def nearest(c):
 start(c);r=c.rng;e=c.emu;grid=rnd(c,0x60);out=rnd(c,6);coord=rnd(c,6)
 rec=e.alloc(64);values=[r.getrandbits(32) for _ in range(3)];dist=r.choice([0.,1.,1000.,1e6,float('nan'),float('inf')])
 def search(em,k):
  ctx=em.arg32(0);box=em.r32(ctx);query=em.r32(ctx+12)
  em.wbytes(rec,em.rbytes(box,28));em.wbytes(rec+28,em.rbytes(query,36))
  em.w32(rec+60,em.r32(ctx+4)|em.r32(ctx+8)|(em.r32(ctx+16)&255))
  for i,v in enumerate(values):em.w32(query+16+4*i,v)
  em.wbytes(query+28,struct.pack('<f',dist))
 hook_rec(c,0x52d750,9,this=True,stackmark=(0,),side=search)
 return [grid,out,coord,r.getrandbits(32),r.getrandbits(32),F(r.uniform(-10,10))]
S(0x530e80,'GUESS_nearest_walkable_cell','thiscall',None,ret='eax',gen=nearest)
