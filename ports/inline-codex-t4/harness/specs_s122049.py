from pilot import S
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub
import struct

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng
 hook_rec(c,0x7003b0,4,pop=0,ret=r.getrandbits(32));e.w32(0x7003b0,pystub(c,0))
 log=obj(c,0x20,{0x2c:pystub(c,3,pop=0)});logger=obj(c,0x20,{0x20:pystub(c,2,this=True,ret=log)});e.w32(0x700390,logger)
 args=rnd(c,16);input=rnd(c,0x20);output=rnd(c,0x20);e.w32(args+4,input);e.w32(args+8,output)
 vals=[rnd(c,8) for _ in range(3)];ident=r.choice([0,-1,-100,1,4,16]);e.w32(vals[0],ident&0xffffffff)
 for p in vals[1:]:e.wbytes(p,struct.pack('<f',r.uniform(-100,100)));e.wbytes(p+4,bytes([r.choice([0,2,1,3])]))
 out=rnd(c,8)
 hook_rec(c,0x5003d0,1,this=True,ret=lambda em,k:out if em.reg('ecx')==output else vals[em.arg32(0)])
 hook_rec(c,0x5002f0,1,this=True);hook_rec(c,0x5057e0,2,this=True)
 s=obj(c,0x20,{0x60:pystub(c,5,this=True,ret=r.getrandbits(32))})
 data=rnd(c,0x100);tab=rnd(c,0x100);sys=rnd(c,0x100);e.w32(tab+0x44,data);e.w32(sys+0x9b,tab);e.w32(0x70039c,sys)
 return [s,args]
S(0x504960,'GUESS dispatch indexed rectangle query','thiscall',None,ret=None,gen=gen)
