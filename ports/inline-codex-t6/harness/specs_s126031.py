from pilot import S,F
from recruits_util import rnd,clear_hooks,hook_rec,pystub
import struct

def gen(c):
 clear_hooks(c);r=c.rng;e=c.emu;me=rnd(c,0x3d0);parent=rnd(c,0x430);basis=rnd(c,0x30);output=rnd(c,12);speed=rnd(c,8)
 e.w32(me+4,parent);e.w32(parent+0x417,r.randrange(32));e.w32(me+0x21,r.choice([0,speed]))
 for off in [0x3ad,0x3bb,0x3bc,0x3be]:e.wbytes(me+off,bytes([r.randrange(2)]))
 e.wbytes(me+0x3af,struct.pack('<3f',*[r.uniform(-10,10) for _ in range(3)]));e.wbytes(basis+0xc,struct.pack('<3f',*[r.uniform(-10,10) for _ in range(3)]));e.wbytes(speed+4,struct.pack('<f',r.uniform(-10,10)))
 def base(em,k):em.wbytes(em.arg32(2),struct.pack('<3f',11,22,33))
 hook_rec(c,0x487c70,4,this=True,side=base)
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 return [me,basis,r.getrandbits(32),output,F(r.uniform(-10,10))]
S(0x487e50,'GUESS movement guide speed composition','thiscall',None,ret=None,gen=gen)
