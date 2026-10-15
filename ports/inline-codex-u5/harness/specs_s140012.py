import struct
from pilot import S
from recruits_util import rnd,obj,clear_hooks,pystub,hook_rec,sysobj

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 w=r.randrange(1,20);h=r.randrange(1,10)
 me=obj(c,0x80,{0xec:pystub(c,0,this=True,ret=w),0xf0:pystub(c,0,this=True,ret=h)})
 data=rnd(c,w*h+32)
 for i in range(w*h):
  if r.randrange(8)==0:e.wbytes(data+i,b'\0')
 e.w32(me+0x74,r.choice([0,data,data]))
 hook_rec(c,0x41e290,1,pop=0,ret=data)
 def zero(em,k):em.wbytes(em.arg32(0),bytes(em.arg32(2)))
 hook_rec(c,0x634d10,3,pop=0,side=zero,ret=lambda em,k:em.arg32(0))
 text=rnd(c,64);n=r.randrange(0,40);e.wbytes(text,bytes(r.randrange(1,256) for _ in range(n))+b'\0')
 so=sysobj(c);e.wbytes(so+0x9c7,struct.pack('<f',r.choice([0.,1.,-1.,float('nan')])))
 return [me,r.choice([-1,0,w-1,w,r.randrange(w)]),r.choice([-1,0,h-1,h,r.randrange(h)]),text]
S(0x651230,'GUESS write bounded text grid','cdecl',None,ret=None,gen=gen)
