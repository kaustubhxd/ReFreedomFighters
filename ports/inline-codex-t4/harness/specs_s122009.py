from pilot import S
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub
import struct

def gen(c):
 clear_hooks(c)
 e,r=c.emu,c.rng
 hook_rec(c,0x7003b0,4,ret=r.getrandbits(32),pop=0)
 # Variable argument printer: observe fixed args always and double only for float formats.
 rec=e.alloc(8*32,4)
 def save(em,k):
  for j in range(4):em.w32(rec+32*k+4*j,em.arg32(j))
  if em.arg32(2) in (11,12):
   em.w32(rec+32*k+16,em.arg32(4));em.w32(rec+32*k+20,em.arg32(5))
 printer=obj(c,0x20,{0x184:pystub(c,0,pop=0,side=save)})
 sys=obj(c,0x20,{0x190:pystub(c,0,this=True,ret=printer)})
 e.w32(0x70039c,sys)
 s=rnd(c,0xe0);e.w32(s+0x60,r.choice([0,1,2,0xffffffff]))
 for off in [0xd1,0xd5]:e.wbytes(s+off,struct.pack('<f',r.choice([0.,-0.,1.,-1.,r.uniform(-1.e20,1.e20),float('inf')])))
 return [s]
S(0x4bcc60,'GUESS print mode and float settings','thiscall',None,ret=None,gen=gen)
