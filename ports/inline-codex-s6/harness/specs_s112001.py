from pilot import S
from recruits_util import rnd,obj,clear_hooks,pystub,hook_rec

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 def vectors(addr,n,mode):
  def h(em,res):
   dst=em.reg('ecx');src=em.reg('edx');a=[em.r32(src+4*i) for i in range(3)]
   b=[em.r32(em.arg32(0)+4*i) for i in range(3)] if n else []
   old=[em.r32(dst+4*i) for i in range(3)] if mode=='update' else []
   em.calllog.append((addr,tuple(a),tuple(b),tuple(old)))
   for i in range(3):em.w32(dst+4*i,(a[i] ^ (b[i] if b else 0x10203040) ^ (old[i] if old else 0))&0xffffffff)
   em.ret(0,4*n)
  e.hook(addr,h)
  from recruits_util import _HOOKED
  _HOOKED.add(addr)
 for addr,n,mode in [(0x43e920,1,'set'),(0x43e8e0,1,'set'),(0x4dfd80,0,'update'),(0x441940,0,'update'),(0x4e0900,0,'update'),(0x4e08d0,0,'update')]:vectors(addr,n,mode)
 hook_rec(c,0x4e0d00,1,this=True)
 flags={}
 hook_rec(c,0x4db9a0,1,this=True,ret=lambda em,k:flags[em.reg('ecx')][em.arg32(0)])
 tail=0
 for j in range(r.randrange(0,5)):
  matrix=rnd(c,12)
  def out(em,k):
   for i in range(2):em.wbytes(em.arg32(i),bytes(range(12)))
  o=obj(c,0x20,{0x2d4:pystub(c,2,this=True,stackmark=(0,1),side=out),0x268:pystub(c,0,this=True,ret=matrix)})
  p=rnd(c,0x70);e.w32(p+0x60,tail);e.w32(p+0x54,o);e.w32(p+0x3c,r.choice([0,0x400,0x800,0x1000]));flags[p]={0x10002e:r.randrange(2),0x20002c:r.randrange(2)};tail=p
 me=rnd(c,0x80);e.w32(me+0x50,tail)
 return [me,rnd(c,12),rnd(c,12)]
S(0x4eeed0,'GUESS aggregate_bounds','thiscall',None,ret=None,gen=gen)
