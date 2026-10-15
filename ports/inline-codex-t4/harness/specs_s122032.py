from pilot import S
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub
import struct

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng
 hook_rec(c,0x7003b0,4,pop=0,ret=r.getrandbits(32))
 e.w32(0x7003b0,pystub(c,0))
 log=obj(c,0x20,{0x2c:pystub(c,3,pop=0)})
 logger=obj(c,0x20,{0x20:pystub(c,2,this=True,ret=log)});e.w32(0x700390,logger)
 s=rnd(c,0x20);buf=rnd(c,100);out=rnd(c,32);n=r.randrange(1,8);p=buf
 for i in range(n):
  typ=r.choice([1,2,3,4,255]);tag=typ if typ==255 else typ|(r.randrange(4)<<6);e.wbytes(p,bytes([tag]))
  if typ==1:data=struct.pack('<d',r.choice([0.,-0.,1.,-1.,r.uniform(-1.e30,1.e30),float('inf'),float('nan')]))
  else:data=r.getrandbits(32).to_bytes(4,'little')
  e.wbytes(p+1,data);p+=len(data)+1
 e.w32(s+8,buf)
 def size(em,k):
  typ=em.rbytes(em.r32(em.reg('ecx')+8),1)[0]&63
  return 8 if typ==1 else 4
 hook_rec(c,0x4e1590,0,this=True,ret=size)
 return [s,out,n]
S(0x4e12f0,'GUESS read typed float array','thiscall',None,ret=None,gen=gen,nan_heap=True)
