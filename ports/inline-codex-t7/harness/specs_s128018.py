from pilot import S
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub

def g(c):
 clear_hooks(c)
 r,e=c.rng,c.emu
 me=obj(c,0x2340,{0x14:pystub(c,0,this=True)})
 ctx=rnd(c,0x80);e.w32(me+5,ctx);e.wbytes(me+0x2315,bytes([r.choice([0,0,0,1,255])]))
 e.w32(me+0x2316,r.randrange(1,8192));e.w32(me+0x21fd,r.randrange(1,9))
 def write(em,k):
  p=em.arg32(0);em.w32(p,em.r32(p)^0xabcdef)
 hook_rec(c,0x410470,1,pop=0,side=write);hook_rec(c,0x4104c0,2,pop=0,ret=r.getrandbits(32))
 count=r.randrange(8192)
 hook_rec(c,0x54e1f0,4,this=True,stackmark=(2,),ret=r.choice([0,1,2]),side=lambda em,k:em.w32(em.arg32(2),count))
 hook_rec(c,0x410540,2,pop=0)
 pages=[r.choice([0,1,2]) for _ in range(6)]
 pages[0]=r.choice([0,1,1,2])
 def page(em,k):
  p=em.arg32(1);em.w32(p+4,k+3);em.w32(p+12,k*7+5)
 hook_rec(c,0x4106b0,2,pop=0,ret=lambda em,k:pages[k] if k<len(pages) else 1,side=page)
 hook_rec(c,0x410220,1,pop=0,ret=r.getrandbits(32))
 hook_rec(c,0x410280,2,pop=0,ret=r.choice([0,1,0xffffffff]))
 hook_rec(c,0x401090,1,pop=0,side=write);hook_rec(c,0x401000,1,pop=0,side=write)
 hook_rec(c,0x4106f0,2,pop=0,ret=r.choice([0,1,0xffffffff]))
 packets=[r.choice([0,1,2,0xffffffff]) for _ in range(5)]
 hook_rec(c,0x410a00,2,pop=0,ret=lambda em,k:packets[k] if k<len(packets) else 1)
 hook_rec(c,0x401220,3,pop=0,ret=r.choice([0,1,0xffffffff]))
 hook_rec(c,0x401ef0,2,pop=0,side=write);hook_rec(c,0x4017c0,2,pop=0,side=write)
 lg=obj(c,32,{0x2c:pystub(c,2,pop=0),0x30:pystub(c,2,pop=0)})
 e.w32(0x700390,obj(c,32,{0x20:pystub(c,2,this=True,ret=lg)}))
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 return [me]
S(0x54a260,'GUESS initialize streaming decoder','thiscall',None,ret='al',gen=g,note='batch128018')
