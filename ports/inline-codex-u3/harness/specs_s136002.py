import struct
from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 s=rnd(c,0x18240);base=rnd(c,0x80);e.w32(s+8,base)
 for p,n in [(base+8,12),(s+0x181f9,12)]:e.wbytes(p,struct.pack('<'+'f'*n,*(r.uniform(-5,5) for _ in range(n))))
 count=r.choice([0,1,2,3,8,12]);arr=rnd(c,max(4,count*4))
 for i in range(count):
  p=rnd(c,0x60);e.w32(p+0x3c,r.choice([0,0,1,0x10402c00,0x400,0x80000000]));e.w32(arr+i*4,p)
 opt=rnd(c,0x30);e.w32(opt+8,base)
 def rec(em,k):
  p=em.arg32(1);b=em.rbytes(p,64);em.wbytes(em.arg32(0),b)
 hook_rec(c,0x64a700,3,this=True,stackmark=(0,),side=rec)
 def render(em,k):
  n=em.reg('edx');em.calllog.append(('records',n,em.rbytes(em.reg('ecx'),n*64)))
  mask=em.arg32(3);em.wbytes(mask,bytes((i+n)&255 for i in range(128)))
 hook_rec(c,0x660c00,6,this='mark',deref={3:32,4:9,5:3},side=render)
 hook_rec(c,0x648fb0,4,this=True,deref={0:32})
 def fill(em,k):em.wbytes(em.arg32(0),bytes([em.arg32(1)&255])*em.arg32(2))
 hook_rec(c,0x634d10,3,pop=0,stackmark=(0,),side=fill)
 hook_rec(c,0x7003b0,0,pop=0,ret=r.getrandbits(32))
 return [s,arr,arr+count*4,r.getrandbits(32),opt]
S(0x64a280,'GUESS compact and submit geometry records','thiscall',None,ret=None,gen=gen)
