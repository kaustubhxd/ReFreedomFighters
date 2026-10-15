from pilot import S
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub
import struct

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng
 hook_rec(c,0x7003b0,4,pop=0,ret=r.getrandbits(32))
 code=bytes.fromhex('d9c9d9f8dfe066a9000475f6ddd9c3');f=e.alloc(32,16);e.wbytes(f,code);e.mu.ctl_flush_tb();e.w32(0x676358,f)
 s=rnd(c,0x2a0);n=r.randrange(1,7);e.w32(s+0x11,n);e.w32(s+0x291,r.choice([0,0,0,1]));e.wbytes(s+0x295,bytes([r.choice([0,0,0,1])]))
 data=rnd(c,24*n);o=obj(c,0x30,{0x2cc:pystub(c,0,this=True)});e.w32(o+0x1c,data)
 for i in range(1,n):
  p=data+24*i;e.wbytes(p+4,bytes([r.randrange(4)]));a=rnd(c,0x40);e.w32(p+20,a);e.w32(p+16,r.choice([0,r.getrandbits(32)]));frames=r.randrange(1,20);e.w32(a+12,frames)
  for off,v in [(24,r.choice([float(frames),float(frames)+5,float(frames)-0.5])),(8,r.uniform(0,40)),(32,1./frames)]:e.wbytes(a+off,struct.pack('<f',v))
 return [s,o,rnd(c,29*n)]
S(0x646220,'GUESS fill active bone animation records','thiscall',None,ret=None,gen=gen)
