from pilot import S
from recruits_util import rnd,obj,clear_hooks,pystub
import struct

def gen(c):
 clear_hooks(c);r=c.rng;e=c.emu;e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 cap=r.randrange(6);count=r.randrange(cap+1);out=rnd(c,4*max(cap,1));record=e.alloc(4*31)
 rooms=[obj(c,0x20,{0x378:pystub(c,2,this=True,ret=r.getrandbits(32))}) for _ in range(count)]
 def visit(em,k):
  ctx=em.arg32(0)
  em.w32(record,em.r32(ctx));em.w32(record+4,em.r32(ctx+4))
  em.wbytes(record+8,em.rbytes(ctx+23*4,28*4))
  target=em.r32(ctx+24*4)
  for i,room in enumerate(rooms):em.w32(target+4*i,room)
  em.w32(ctx+26*4,count)
 table=obj(c,0x30,{0x1c:pystub(c,3,this=True,stackmark=(0,),deref={1:3,2:3},side=visit)})
 matrix=rnd(c,36);center=rnd(c,12);extent=rnd(c,12)
 for p,n,scale in [(matrix,9,2),(center,3,100),(extent,3,10)]:e.wbytes(p,struct.pack('<%df'%n,*[r.uniform(-scale,scale) for _ in range(n)]))
 return [rnd(c,4),out,cap,table,matrix,center,extent]
S(0x4ed390,'GUESS_rooms_in_box','thiscall',None,ret='eax',gen=gen)
