from pilot import S,EDGE_F
from recruits_util import rnd,clear_hooks,hook_rec,pystub

def gen(c):
 clear_hooks(c);r=c.rng;e=c.emu
 reader=rnd(c,16);first=rnd(c,4);second=rnd(c,4)
 tag=r.choice([2,0x42,3,0xff,0x23]);e.wbytes(first,bytes([tag]));e.wbytes(second,bytes([r.choice([3,0x43,0xff,2])]))
 e.w32(reader,r.choice([first,first,first,0]))
 stop=3 if tag!=0xff and tag&0x3f==2 else 4
 values=[r.choice([0,1,0x100,0xffffffff,r.getrandbits(32)]) for _ in range(12)]
 def advance(em,k):
  if k==stop:em.w32(em.reg('ecx'),second)
 hook_rec(c,0x4e5e60,0,this=True,ret=lambda em,k:values[k%12],side=advance)
 hook_rec(c,0x4e5e80,0,this=True,st0=r.choice(EDGE_F+[r.uniform(-10,10)]))
 hook_rec(c,0x4e5e40,0,this=True,ret=r.getrandbits(32))
 e.w32(0x7003b0,pystub(c,0))
 return [rnd(c,0x80),reader]
S(0x4a4ad0,'copy typed event data block','thiscall',None,ret=None,gen=gen,nan_heap=True)
