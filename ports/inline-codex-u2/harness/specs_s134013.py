from pilot import S
from recruits_util import rnd,clear_hooks,pystub
import struct

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng;me=rnd(c,0x100);out=rnd(c,36)
 basis=r.choice([[1.,0.,0.],[0.,1.,0.],[0.,0.,1.],[r.uniform(-1,1) for _ in range(3)]])
 coeff=[r.uniform(-3,3) for _ in range(3)];lens=[r.choice([0.,1.,2.,r.uniform(-3,3)]) for _ in range(3)]
 e.wbytes(me+0x5f,struct.pack('<3f',*coeff));e.wbytes(me+0x6b,struct.pack('<3f',*lens));e.wbytes(me+0x77,struct.pack('<3f',*basis))
 values=[r.uniform(-3,3) for _ in range(9)]
 if r.random()<0.25:values[6:9]=[x*coeff[0] for x in basis]
 e.wbytes(out,struct.pack('<9f',*values));e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 return [me,out]
S(0x4c9780,'GUESS adjust matrix axes around a basis','thiscall',None,ret=None,gen=gen,nan_heap=True)
