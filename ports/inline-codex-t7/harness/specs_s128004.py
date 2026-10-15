from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec,pystub

def g(c):
 clear_hooks(c)
 r,e=c.rng,c.emu
 def string(b):
  p=rnd(c,len(b)+1);e.wbytes(p,b+b'\0');return p
 def read(em,p):
  b=bytearray()
  for i in range(4096):
   x=em.rbytes(p+i,1)[0]
   if not x:return bytes(b)
   b.append(x)
  raise ValueError('no terminator')
 def api(addr,n,ret=0,**kw):e.w32(addr,pystub(c,n,ret=ret,**kw))
 e.w32(0x6fcd80,r.getrandbits(32));e.w32(0x6fcd40,r.getrandbits(32))
 lineno=r.choice([0,1,2,3,4,8,12]);context=r.choice([0,1,2,4,15,0xffffffff])
 primary=string(b'C:\\src\\game.cpp');fallback=string(r.choice([b'C:\\root\\src\\file.cpp',b'/root/project/file.cpp',b'one.cpp',b'/one.cpp']))
 symok=r.choice([0,1,1,1]);fallbackok=r.randrange(2)
 def symbol(em,k):
  ptr=em.arg32(3);em.calllog.append(('symbol',em.arg32(0),em.arg32(1),[em.r32(ptr+i*4) for i in range(5)]))
  em.w32(ptr+8,lineno);em.w32(ptr+12,primary if k==0 else fallback)
 api(0x6fcd5c,4,ret=lambda em,k:symok if k==0 else fallbackok,stackmark=(2,3),side=symbol)
 firstok=r.randrange(2);secondok=r.randrange(2);handle=r.randrange(1,0xfffffffe)
 def opened(em,k):em.calllog.append(('open',read(em,em.arg32(0)),[em.arg32(i) for i in range(1,7)]))
 api(0x676068,7,ret=lambda em,k:handle if (firstok if k==0 else secondok) else 0xffffffff,stackmark=(0,),side=opened)
 def module(em,k):em.wbytes(em.arg32(1),b'X:\\bin\\game.exe\0')
 api(0x67607c,3,ret=15,stackmark=(1,),side=module)
 hook_rec(c,0x41d500,0,this='mark',ret=lambda em,k:em.reg('ecx')+7)
 lines=[r.choice([b'alpha',b'beta',b'',b'hello'])+r.choice([b'\n',b'\r\n']) for _ in range(r.randrange(1,15))]
 data=b''.join(lines)+r.choice([b'',b'tail',b'\r'])+b'\0'
 size=r.choice([len(data),len(data),0xffffffff]);mem=rnd(c,len(data)+16)
 api(0x67608c,2,ret=size)
 api(0x6760a8,2,ret=lambda em,k:(0xabc000+em.arg32(1))&0xffffffff)
 allocok=r.choice([0,1,1,1]);api(0x6760a0,1,ret=mem if allocok else 0)
 api(0x6760a4,1,ret=r.getrandbits(32))
 readok=r.choice([0,1,1,1])
 def rd(em,k):em.wbytes(em.arg32(1),data);em.w32(em.arg32(3),len(data))
 api(0x676094,5,ret=readok,stackmark=(3,),side=rd)
 api(0x676070,1,ret=r.getrandbits(32))
 def strchr(em,k):
  p,ch=em.arg32(0),em.arg32(1)&255;em.calllog.append(('find',p,ch));ix=(read(em,p)+b'\0').find(bytes([ch]));em.ret(p+ix if ix>=0 else 0,0)
 e.hook(0x41e170,strchr)
 from recruits_util import _HOOKED
 _HOOKED.add(0x41e170)
 def sprintf(em,k):
  dst,f,n=em.arg32(0),em.arg32(1),em.arg32(2)
  em.calllog.append(('sprintf',f,n));b=(hex(f)+':'+str(n)).encode();em.wbytes(dst,b+b'\0');em.ret(len(b),0)
 e.w32(0x6761e4,e.stub_fn('sprintf',sprintf))
 def output(em,k):
  fmt=em.arg32(0)
  if fmt==0x677098:args=[]
  elif fmt==0x6770e0:args=[read(em,em.arg32(1)),em.arg32(2),em.arg32(3)]
  else:args=[read(em,em.arg32(1))]
  em.calllog.append(('print',read(em,fmt),args));em.ret(0,0)
 e.hook(0x41e010,output);_HOOKED.add(0x41e010)
 hook_rec(c,0x41dd90,0);hook_rec(c,0x41dd70,0)
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 return [r.getrandbits(32),context]
S(0x41d6a0,'GUESS print source context','fastcall',None,ret=None,gen=g,note='batch128004')
