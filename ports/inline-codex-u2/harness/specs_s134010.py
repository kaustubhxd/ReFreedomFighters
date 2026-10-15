from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub,logger
import struct

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 matrices=[]
 for k in range(2):
  matrices.append([r.uniform(-2,2) for _ in range(9)])
 if r.random()<0.5:matrices[1]=matrices[0][:]
 def transform(em,k):
  mat=matrices[min(k,1)];em.wbytes(em.arg32(0),struct.pack('<9f',*mat));em.wbytes(em.arg32(1),struct.pack('<3f',1,2,3))
 tr=pystub(c,2,this=True,nullflag=(0,1),side=transform)
 me=obj(c,0x300,{0x80:tr});source=obj(c,0x80,{0x80:tr})
 for o in [me,source]:
  e.w32(o+4,r.choice([0,rnd(c,16)]));shape=rnd(c,0x80);e.w32(o+8,shape);e.wbytes(shape+0x40,struct.pack('<3f',*[r.uniform(-10,10) for _ in range(3)]))
 e.w32(me+0x123,r.choice([0,1,0xffffffff]));sysobj(c,table_slots={0x58:pystub(c,1,this=True,ret=source)})
 threshold=struct.unpack('<f',e.rbytes(0x69eb54,4))[0]
 angles=[r.choice([0.,threshold,threshold+0.01,1.,3.]) for _ in range(3)]
 def angle_inputs(em,k):em.calllog.append(('angle',em.rbytes(em.reg('ecx'),12),em.rbytes(em.reg('edx'),12)))
 hook_rec(c,0x4e0030,0,this='mark',side=angle_inputs,st0=lambda em,k:angles[k%3])
 hook_rec(c,0x512590,0,this=True);logger(c,4);e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 return [me]
S(0x515630,'GUESS initialize vehicle aligned bounds','thiscall',None,ret=None,gen=gen)
