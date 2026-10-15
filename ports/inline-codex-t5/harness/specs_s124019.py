from pilot import S
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub
import struct

def g(c):
 clear_hooks(c);r=c.rng;e=c.emu;e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 hook_rec(c,0x428870,1,this=True)
 block=bytearray(r.getrandbits(8) for _ in range(20))
 for off in range(12,16):block[off]=r.choice([0,1,0x80,0xff])
 result=r.choice([0,0,0x8007001e,0x80070005,1])
 def read(em,k):em.wbytes(em.arg32(2),block)
 seq=[r.choice([1,0x8007001e]) for _ in range(r.randrange(4))]+[r.choice([0,0x80070005])]
 device=obj(c,16,{0x24:pystub(c,3,ret=result,side=read,stackmark=[2]),0x1c:pystub(c,1,ret=lambda em,k:seq[min(k,len(seq)-1)])})
 me=rnd(c,0x50);e.wbytes(me+0xc,bytes([r.choice([0,1,2])]));e.wbytes(me+0x45,bytes([r.choice([0,1,1,2])]));e.w32(me+0xd,r.choice([0,device,device,device]))
 sys=rnd(c,0xa10);e.w32(0x70039c,sys)
 for off in [0x9e7,0x9eb,0x9ef]:e.wbytes(sys+off,struct.pack('<f',r.choice([0.,1.,-1.,float('nan'),r.uniform(-100,100)])))
 return [me]
S(0x42a340,'GUESS poll relative input and accumulate deltas','thiscall',None,ret=None,gen=g,nan_heap=True,note='batch124019')
