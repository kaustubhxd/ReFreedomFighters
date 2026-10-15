from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub,logger,stub_memset

def ctor(c):
 clear_hooks(c);r=c.rng
 hook_rec(c,0x4e7d90,0,this=True,side=lambda e,k:e.w32(e.reg('ecx')+4,0xdead0010+k))
 hook_rec(c,0x4cfb30,2,this=True);stub_memset(c);logger(c)
 return [rnd(c,0x12150),r.getrandbits(32),r.choice([0xffffffff,0,1,8191,8192,8193,0x7fffffff,0x80000000,r.getrandbits(32)]),r.choice([0,1,2,100,r.getrandbits(32)])]

def script(n):
 def gen(c):
  clear_hooks(c);r=c.rng;e=c.emu;logger(c,3)
  e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
  entries=[]
  for i in range(6):
   a=rnd(c,8);kind=r.choice([3,4,0,2,5]);value=r.getrandbits(32)
   if kind==4:value=obj(c,0x20,{0x34:pystub(c,0,this=True,ret=r.getrandbits(32))})
   e.w32(a,value);e.w8(a+4,kind);entries.append(a)
  hook_rec(c,0x5003d0,1,this=True,ret=lambda em,k:entries[em.arg32(0)])
  sysobj(c,table_slots={0x114:pystub(c,5 if n==2 else 4,ret=r.getrandbits(32),this=True,deref={4:4} if n==2 else {})})
  child=obj(c,0x20,{0x12c:pystub(c,n,this=True,ret=r.getrandbits(32))})
  s=rnd(c,0x20);p=rnd(c,0x10);e.w32(s+0xc,child);e.w32(p+4,rnd(c,0x20))
  return [s,p]
 return gen
S(0x4cf940,'GUESS pool initialization','thiscall',None,ret='eax',gen=ctor,note='batch130000')
S(0x5030f0,'GUESS script four-word dispatch','thiscall',None,ret='eax',gen=script(2),note='batch130000')
S(0x5028e0,'GUESS script pair dispatch','thiscall',None,ret='eax',gen=script(3),note='batch130000')
