from pilot import S
from recruits_util import rnd,obj,clear_hooks,pystub
import struct

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 sizes=[r.choice([-10.,0.,1.,10.,50.,100.,200.,300.,r.uniform(-10,500)]) for _ in range(3)]
 def size(em,k):em.wbytes(em.arg32(0),struct.pack('<3f',*sizes))
 def geometry(em,k):em.wbytes(em.arg32(0),struct.pack('<3f',1,2,3));em.wbytes(em.arg32(1),struct.pack('<3f',*sizes))
 me=obj(c,0x40,{0x2bc:pystub(c,3,this=True,nullflag=(0,1),side=geometry)})
 shape=rnd(c,0x80);e.wbytes(shape+0x40,struct.pack('<3f',*sizes));e.w32(me+8,shape);flags=rnd(c,0x40);e.w32(flags+0x23,r.choice([0,0x100000,0xffffffff]));e.w32(me+0xc,flags)
 vectors=[]
 for i in range(4):
  p=rnd(c,12);e.wbytes(p,struct.pack('<3f',*[r.uniform(-10,10) for _ in range(3)]));vectors.append(p)
 if r.random()<0.25:vectors[3]=vectors[0]
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 return [me]+vectors
S(0x53fd10,'GUESS scale four vectors by clamped geometry size','fastcall',None,ret=None,gen=gen)
