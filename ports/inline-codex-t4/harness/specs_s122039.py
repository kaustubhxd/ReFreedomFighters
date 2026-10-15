from pilot import S
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub
import struct

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng
 hook_rec(c,0x7003b0,4,pop=0,ret=r.getrandbits(32));e.w32(0x7003b0,pystub(c,0))
 log=obj(c,0x20,{0x2c:pystub(c,3,pop=0)});logger=obj(c,0x20,{0x20:pystub(c,2,this=True,ret=log)});e.w32(0x700390,logger)
 args=rnd(c,16);inp=rnd(c,8);out=rnd(c,8);e.wbytes(inp+4,bytes([r.choice([3,4,0,1,255])]))
 text=obj(c,0x20,{0x34:pystub(c,0,this=True,ret=r.getrandbits(32))})
 if e.rbytes(inp+4,1)==b'\x04':e.w32(inp,text)
 e.wbytes(out+4,bytes([r.choice([0,2,1,3,255])]))
 first=rnd(c,0x20);second=rnd(c,0x20);e.w32(args+4,first);e.w32(args+8,second)
 hook_rec(c,0x5003d0,1,this=True,ret=lambda em,k:inp if k==0 else out)
 value=struct.pack('<f',r.choice([0.,-0.,1.,r.uniform(-100,100)]))
 def fill(em,k):em.wbytes(em.arg32(1),value)
 query=obj(c,0x20,{0x84:pystub(c,2,this=True,stackmark=(1,),side=fill)})
 tab=obj(c,0x20,{0x134:pystub(c,0,this=True,ret=query)});sys=rnd(c,0x100);e.w32(0x70039c,sys);e.w32(sys+0x9b,tab)
 return [rnd(c,0x20),args]
S(0x50a670,'GUESS query named float into typed value','thiscall',None,ret=None,gen=gen)
