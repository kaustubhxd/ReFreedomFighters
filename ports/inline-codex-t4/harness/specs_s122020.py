from pilot import S,F
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub
import struct

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng
 hook_rec(c,0x7003b0,4,pop=0,ret=r.getrandbits(32))
 def fmt(em,k):
  text=str(em.arg32(3)).encode()+b'\0';em.wbytes(em.arg32(1),text+bytes(32-len(text)))
 out=obj(c,0x20,{0x198:pystub(c,4,pop=0,stackmark=(1,),side=fmt)})
 sys=obj(c,0x20,{0x190:pystub(c,0,this=True,ret=out)});e.w32(0x70039c,sys)
 s=rnd(c,0x1d40);e.w32(s+0x1d0f,rnd(c,0x20) if r.randrange(4) else 0)
 for off in [0x1d1b,0x1d1f,0x1d23,0x1d27]:e.wbytes(s+off,struct.pack('<f',r.uniform(-100,100)))
 hook_rec(c,0x5a5c50,0,this=True);hook_rec(c,0x5a5c60,0,this=True)
 hook_rec(c,0x5a5c80,3,this=True,deref={2:8})
 return [s,F(r.choice([struct.unpack('<f',e.rbytes(0x679540,4))[0],-100.,-1.,0.,1.,0.5,100.,1.e9,4294967040.,r.uniform(0,100000)]))]
S(0x5ea870,'GUESS update numeric display','thiscall',None,ret=None,gen=gen)
