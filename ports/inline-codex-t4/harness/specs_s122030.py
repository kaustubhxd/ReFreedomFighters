from pilot import S
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub
import struct

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng
 hook_rec(c,0x7003b0,4,pop=0,ret=r.getrandbits(32))
 data=struct.pack('<12f',*[r.uniform(-10,10) for _ in range(12)])
 def change(em,k):em.wbytes(em.arg32(0),data[:36]);em.wbytes(em.arg32(1),data[36:])
 s=obj(c,0x20,{0x80:pystub(c,2,this=True,deref={0:9,1:3},side=change),0xdc:pystub(c,4,this=True,deref={2:9,3:3})})
 draw=obj(c,0x20,{0x94:pystub(c,2,this=True,deref={0:9,1:3})})
 matrices=[]
 for _ in range(2):
  a=rnd(c,48)
  for j in range(12):e.wbytes(a+4*j,struct.pack('<f',r.uniform(-3,3)))
  matrices.append(a)
 view=obj(c,0x20,{0x3c:pystub(c,0,this=True,ret=matrices[0]),0x40:pystub(c,0,this=True,ret=matrices[1])})
 return [s,view,draw]
S(0x4599e0,'GUESS particle draw view transform','thiscall',None,ret='al',gen=gen)
