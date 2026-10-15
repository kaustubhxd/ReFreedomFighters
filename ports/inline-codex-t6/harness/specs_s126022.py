from pilot import S
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub
import struct

def gen(c):
 clear_hooks(c);r=c.rng;e=c.emu
 matrix=struct.pack('<9f',*[r.uniform(-10,10) for _ in range(9)]);pos=struct.pack('<3f',*[r.uniform(-10,10) for _ in range(3)])
 def get(em,k):em.wbytes(em.arg32(0),matrix);em.wbytes(em.arg32(1),pos)
 me=obj(c,0x2700,{0x80:pystub(c,2,this=True,deref={0:9,1:3},side=get)});ref=rnd(c,0x30);e.w32(me+0x5c,ref);e.wbytes(ref+8,pos)
 e.wbytes(me+0x133,bytes([r.randrange(2)]));e.wbytes(me+0x60,pos);e.wbytes(me+0x6c,matrix)
 embedded=obj(c,0x20,{4:pystub(c,2,this=True,deref={0:3,1:3})});e.w32(me+0x263c,e.r32(embedded))
 vec=struct.pack('<3f',*[r.uniform(-10,10) for _ in range(3)])
 def v(em,k):em.wbytes(em.arg32(0),vec)
 hook_rec(c,0x523330,1,this=True,nullflag=(0,),side=v);hook_rec(c,0x520e40,1,this=True,deref={0:3})
 hook_rec(c,0x528100,2,this=True,deref={0:3,1:3})
 def final(em,k):em.wbytes(em.arg32(0),matrix);em.wbytes(em.arg32(1),pos)
 hook_rec(c,0x525380,2,this=True,deref={0:9,1:3},side=final)
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 return [me,r.choice([0,1,256,0xffffffff])]
S(0x520f20,'GUESS tank initial position and direction','thiscall',None,ret=None,gen=gen)
