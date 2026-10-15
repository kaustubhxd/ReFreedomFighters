from pilot import S
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub
import struct

def gen(c):
 clear_hooks(c);r=c.rng;e=c.emu;me=rnd(c,0x30);inp=rnd(c,0x20);values=rnd(c,16)
 e.w32(inp+4,values)
 for i in range(4):e.wbytes(values+4*i,struct.pack('<f',r.uniform(-2,2)))
 matrix=struct.pack('<9f',*[r.uniform(-5,5) for _ in range(9)]);pos=struct.pack('<3f',*[r.uniform(-5,5) for _ in range(3)])
 def side(em,k):em.wbytes(em.arg32(0),matrix);em.wbytes(em.arg32(1),pos)
 o=obj(c,0x20,{0x80:pystub(c,2,this=True,nullflag=(0,1),side=side),0x7c:pystub(c,2,this=True,deref={0:9,1:3})})
 e.w32(me+0xc,o);hook_rec(c,0x5003d0,1,this=True,ret=lambda em,k:values+4*em.arg32(0))
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 return [me,inp]
S(0x501cd0,'GUESS apply quaternion rotation','thiscall',None,ret=None,gen=gen)
