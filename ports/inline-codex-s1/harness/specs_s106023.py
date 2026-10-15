from pilot import S,EDGE_F
from recruits_util import rnd,clear_hooks,hook_rec,pystub

def gen(c):
 clear_hooks(c);r=c.rng;e=c.emu
 me=rnd(c,0x20);out=rnd(c,0x50);data=rnd(c,0x80);e.w32(me+0x14,data);e.w32(data,r.randrange(0x40))
 for off in (4,8,12,16):e.wf32(me+off,r.choice(EDGE_F+[r.uniform(-10,10)]))
 a=rnd(c,12);b=rnd(c,12)
 for p in (a,b):
  for i in range(3):e.wf32(p+4*i,r.choice(EDGE_F+[r.uniform(-10,10)]))
 stable=[rnd(c,12),rnd(c,12)]
 def query(em,k):
  p=em.arg32(0)
  for off,dst in zip((0x30,0x34),stable):
   v=em.rbytes(em.r32(p+off),12);em.calllog.append(('vector',v.hex()));em.wbytes(dst,v);em.w32(p+off,dst)
 hook_rec(c,0x4e3630,5,this=True,side=query)
 hook_rec(c,0x633654,0);e.w32(0x7003b0,pystub(c,0))
 return [me,out,a,b]
S(0x4e39e0,'transform spatial query endpoints','thiscall',None,ret=None,gen=gen,nan_heap=True)
