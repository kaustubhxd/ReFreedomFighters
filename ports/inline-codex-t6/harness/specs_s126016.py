from pilot import S
from recruits_util import rnd,clear_hooks,pystub
import struct

def gen(c):
 clear_hooks(c);r=c.rng;e=c.emu
 def node():
  p=rnd(c,0x60);e.wbytes(p,struct.pack('<15f',*[r.uniform(-2,2) for _ in range(15)]));return p
 src=node();ref=node();dest=rnd(c,0x40);nodes=[src]+[node() for _ in range(r.randrange(4))]
 for i,p in enumerate(nodes):
  e.w32(p+0x3c,0x40000 if i==len(nodes)-1 else 0);e.w32(p+0x50,nodes[i+1] if i+1<len(nodes) else 0)
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 return [dest,src,ref]
S(0x64a700,'GUESS hierarchy world transform record','stdcall',None,ret=None,gen=gen)
