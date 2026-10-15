from pilot import S
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub
import struct

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng
 hook_rec(c,0x7003b0,4,pop=0,ret=r.getrandbits(32))
 sys=obj(c,0x20,{0x1c0:pystub(c,2,this=True,st0=r.choice([0.,0.5,1.,float('nan'),r.uniform(-1,2)]))});e.w32(0x70039c,sys)
 s=obj(c,0x80,{0x84:pystub(c,0,this=True),0x68:pystub(c,2,this=True)})
 parent=obj(c,0x30,{0x210:pystub(c,1,this=True)});e.w32(parent+0x18,rnd(c,0x90));e.w32(s+0x44,parent)
 e.wbytes(s+0x51,bytes([r.randrange(2)]))
 for off in [0x59,0x65,0x6d]:e.wbytes(s+off,struct.pack('<f',r.choice([0.,-0.,0.5,1.,float('nan'),r.uniform(-2,2)])))
 return [s]
S(0x4c3070,'GUESS initialize probabilistic effect','thiscall',None,ret=None,gen=gen,nan_heap=True)
