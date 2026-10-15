from pilot import S,F
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub
import struct

def start(c):
 clear_hooks(c);c.emu.w32(0x7003b0,pystub(c,0,ret=c.rng.getrandbits(32)))
def floats(r,n,scale=10):return struct.pack('<%df'%n,*[r.uniform(-scale,scale) for _ in range(n)])

def begin(c):
 start(c);r=c.rng;e=c.emu
 s=obj(c,0x80,{0x68:pystub(c,2,this=True),0x58:pystub(c,0,this=True)})
 sub=obj(c,0x30,{0x40:pystub(c,0,this=True),0x3c:pystub(c,1,this=True)})
 e.w32(sub+0x10,rnd(c,0x30));e.w32(sub+8,rnd(c,0x80));e.w32(s+0x44,sub)
 e.w8(s+0x64,r.randrange(2));e.w8(s+0x5e,r.randrange(2))
 outputs=[r.choice([0,1,0x7fffffff,0x80000000,0xffffffff,r.getrandbits(32)]) for _ in range(3)]
 def fill(em,k):
  for i,x in enumerate(outputs):em.w32(em.arg32(i+1),x)
 mgr=obj(c,0x20,{0xd4:pystub(c,4,this=True,stackmark=(1,2,3),side=fill,ret=r.choice([0,1,0x100,0x101,0xffffffff]))})
 sys=sysobj(c);root=rnd(c,0x30);e.w32(root+0x18,mgr);e.w32(sys+0x1aa3,root)
 return [s]
S(0x4a4db0,'GUESS_begin_effect','thiscall',None,ret=None,gen=begin)

def overlay(c):
 start(c);r=c.rng;e=c.emu;s=rnd(c,0xe0);reader=rnd(c,0x30)
 hook_rec(c,0x451d00,1,this=True)
 # Reader hooks write deterministic payloads of the appropriate width and record all addresses/counts.
 def read(addr,width):
  values=[r.getrandbits(32) for _ in range(8)]
  def effect(em,k):
   p=em.arg32(0);n=em.arg32(1)
   for i in range(n):
    val=values[(k+i)%8]
    if addr==0x4e11e0:val=ranges[(k+i)%len(ranges)]
    if width==1:em.w8(p+i,val&255)
    else:em.w32(p+4*i,val)
  hook_rec(c,addr,2,this=True,side=effect)
 ranges=[r.choice([0,1,2,0xffffffff]) for _ in range(4)]
 read(0x4e14a0,1);read(0x4e12f0,4);read(0x4e11e0,4);read(0x4e12e0,4)
 # Finite float payloads avoid depending on NaN canonicalization in the heap comparison.
 fs=floats(r,4,1000)
 def end(em,k):em.wbytes(s+0x90,fs)
 hook_rec(c,0x4e1b30,0,this=True,side=end)
 return [s,reader]
S(0x4583d0,'GUESS_read_camera_overlay','thiscall',None,ret=None,gen=overlay)

def impact(c):
 start(c);r=c.rng;e=c.emu;s=rnd(c,0x2000);point=rnd(c,12);sysobj(c)
 e.w32(s+0x8c,r.choice([-1,0,1,2,3,4])&0xffffffff);e.w32(s+0x90,r.choice([-1,0,1,2,3,4])&0xffffffff)
 rec=e.alloc(4*9);dist=r.choice([0.,0.001,0.1,1.,100.,float('inf'),-1.])
 def logpoint(em,k):em.w32(rec+4*min(k,8),em.reg('edx'))
 hook_rec(c,0x4e0870,0,this=True,side=logpoint,st0=dist)
 hook_rec(c,0x516040,1,this=True)
 return [s,F(r.choice([0.,-0.,1.,-1.,r.uniform(-100,100)])),point]
S(0x525e20,'GUESS_receive_impact','thiscall',None,ret=None,gen=impact)

def bounds(c):
 start(c);r=c.rng;e=c.emu;target=rnd(c,0x20)
 mat=floats(r,9,2);center=floats(r,3,100);extent=floats(r,3,10)
 mat2=floats(r,9,2);center2=floats(r,3,100)
 def transform(em,k):em.wbytes(em.arg32(0),mat2);em.wbytes(em.arg32(1),center2)
 s=obj(c,0x30,{0x314:pystub(c,0,this=True,ret=target),0x94:pystub(c,2,this=True,deref={0:9,1:3},side=transform)})
 geometry=rnd(c,0x80);e.w32(geometry+0x64,r.choice([0,r.getrandbits(32)]))
 hook_rec(c,0x4daf90,1,this=True,stackmark=(0,),side=lambda em,k:em.wbytes(em.arg32(0),center))
 hook_rec(c,0x4db600,2,this=True,stackmark=(0,),deref={1:3},side=lambda em,k:em.wbytes(em.arg32(0),mat))
 hook_rec(c,0x4db7c0,1,this=True,stackmark=(0,),side=lambda em,k:em.wbytes(em.arg32(0),extent))
 hook_rec(c,0x4e4ef0,3,this=True,deref={1:3,2:3})
 return [s,geometry]
S(0x4439b0,'GUESS_update_geometry_bounds','thiscall',None,ret=None,gen=bounds)

def aim(c):
 start(c);r=c.rng;e=c.emu;s=rnd(c,0x1000);sys=sysobj(c)
 e.wbytes(sys+0x48,struct.pack('<f',r.choice([0.,0.001,0.016,1.,100.,-0.016])))
 e.wbytes(s+0xaed,struct.pack('<f',r.choice([-5.,-1.22173047,0.,1.,5.,r.uniform(-3,3)])))
 e.wbytes(s+0xae9,struct.pack('<f',r.uniform(-3,3)))
 e.w32(s+0xb54,rnd(c,0x20));e.w32(s+0xe18,r.choice([0,rnd(c,0x20)]))
 hook_rec(c,0x5cc880,1,this=True);hook_rec(c,0x5a7530,1,this=True)
 rec=e.alloc(12)
 def matrix(em,k):
  vec=em.rbytes(em.reg('edx'),12);em.wbytes(rec,vec);em.wbytes(em.reg('ecx'),vec*3)
 hook_rec(c,0x4de040,1,this='mark',side=matrix)
 return [s]
S(0x5cff20,'GUESS_relax_aim','thiscall',None,ret=None,gen=aim)
