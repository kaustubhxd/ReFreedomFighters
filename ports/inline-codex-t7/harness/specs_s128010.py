from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec,pystub

def g(c):
 clear_hooks(c)
 r,e=c.rng,c.emu
 out=rnd(c,0x80);arg=rnd(c,0x30);src=rnd(c,0x960)
 n=r.randrange(4);m=r.randrange(4);channels=r.randrange(3)
 e.w32(arg+0x1c,src);e.w32(arg+4,channels)
 e.w32(src,r.getrandbits(32));e.w32(src+4,r.getrandbits(32));e.w32(src+8,n);e.w32(src+28,m)
 for i in range(n):
  item=rnd(c,32);e.w32(item+12,i);e.w32(src+36+i*4,item);e.w32(src+0x124+i*4,i)
  tab=rnd(c,12);e.w32(tab+8,pystub(c,3,pop=0,ret=r.getrandbits(32)));e.w32(0x6f1dd8+i*4,tab)
 # Preallocate maximum callback storage, and use per-call offsets deterministically.
 pool=rnd(c,0x18000);cursor=[0]
 def alloc(em,k):
  a,b=em.arg32(0),em.arg32(1);size=a*b;pos=cursor[0];cursor[0]=(pos+max(size,4)+15)&~15
  assert cursor[0]<0x18000
  em.calllog.append(('calloc',a,b));em.wbytes(pool+pos,bytes(size));return pool+pos
 hook_rec(c,0x634df4,2,pop=0,ret=alloc)
 def malloc(em,k):
  size=em.arg32(0);pos=cursor[0];cursor[0]=(pos+max(size,4)+15)&~15;em.calllog.append(('malloc',size));return pool+pos
 hook_rec(c,0x634d58,1,pop=0,ret=malloc)
 hook_rec(c,0x407ed0,1,pop=0,ret=r.getrandbits(32))
 def write(em,k):em.w32(em.arg32(0),em.arg32(1)^0x12345678)
 hook_rec(c,0x406590,2,pop=0,side=write)
 hook_rec(c,0x406470,4,pop=0,ret=lambda em,k:(em.arg32(1)^em.arg32(2)^((em.arg32(3)*3)&0xffffffff)))
 hook_rec(c,0x405710,2,pop=0,side=write);hook_rec(c,0x4057b0,2,pop=0,side=write)
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 return [out,arg,r.choice([0,1,0xffffffff])]
S(0x401970,'GUESS initialize codec context','cdecl',None,ret='eax',gen=g,note='batch128010')
