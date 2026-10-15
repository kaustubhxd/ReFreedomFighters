from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub,logger

def text(c,b):
 p=rnd(c,len(b)+1);c.emu.wbytes(p,b+b'\0');return p

def read(e,p):
 b=bytearray()
 while e.r8(p):b.append(e.r8(p));p+=1
 return bytes(b)

def make_object(c):
 clear_hooks(c);e=c.emu;r=c.rng
 mat=[r.getrandbits(32) for _ in range(9)];v=[r.getrandbits(32) for _ in range(3)];w=[r.getrandbits(32) for _ in range(3)]
 def side(em,k):
  for j,x in enumerate(mat):em.w32(em.arg32(0)+4*j,x)
  for j,x in enumerate(v):em.w32(em.arg32(1)+4*j,x)
 def sidew(em,k):
  for j,x in enumerate(w):em.w32(em.arg32(0)+4*j,x)
 o=obj(c,0x20,{0x80:pystub(c,2,this=True,nullflag=(0,1),side=side),0x20:pystub(c,0,this=True,ret=r.getrandbits(32))});e.w32(o+8,rnd(c,0x20))
 hook_rec(c,0x4db7c0,1,this=True,nullflag=(0,),side=sidew)
 maker=obj(c,0x20,{0x364:pystub(c,4,this=True,ret=r.choice([0,r.getrandbits(32)]),deref={1:9,2:3,3:3})})
 sys=sysobj(c,table_size=0xb00,table_slots={0x58:pystub(c,1,this=True,ret=r.choice([0,o])),0x4c:pystub(c,1,this=True,ret=r.getrandbits(32))});e.w32(e.r32(sys+0x9b)+0xadc,maker)
 a=rnd(c,8);b=rnd(c,8);tin=rnd(c,0x10);tout=rnd(c,0x10)
 hook_rec(c,0x5003d0,1,this=True,ret=lambda em,k:b if em.reg('ecx')==tout else a)
 hook_rec(c,0x5002f0,1,this=True);hook_rec(c,0x50d7b0,1,this=True,deref={0:1})
 p=rnd(c,0x10);e.w32(p+4,tin);e.w32(p+8,tout);return [rnd(c,0x10),p]

def remove(c):
 clear_hooks(c);e=c.emu;r=c.rng;s=rnd(c,0x10140);count=r.randrange(9);key=r.randrange(5)
 e.w32(s+0x1005d,obj(c,0x20,{0x60:pystub(c,0,this=True)}));e.w32(s+0x10089,count)
 for i in range(count):
  o=rnd(c,0x80);p=rnd(c,0x20);e.w32(p+0xc,r.randrange(5));e.w32(o+0xc,p);e.w32(s+0x1008d+4*i,o)
 hook_rec(c,0x64a120,1,this=True);e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 def copy(em,k):
  d,src,n=em.arg32(0),em.arg32(1),em.arg32(2);em.calllog.append(('memcpy',d,src,n));em.wbytes(d,em.rbytes(src,n));em.ret(eax=d,argbytes=0)
 e.stub_import('memcpy',copy);return [s,key]

def parse(c):
 clear_hooks(c);e=c.emu;r=c.rng;logger(c,3)
 b=r.choice([b'',b'key=value',b'key==value',b' \t\r\nvalue ',b'abc',b'a'*509,b'a'*510,b'a'*511,b'a'*512]);src=text(c,b);dst=rnd(c,0x300);arg=r.getrandbits(32);offset=r.randrange(len(b)+1)
 def find(em,k):
  p=em.arg32(0);s=read(em,p);i=s.find(bytes([em.arg32(1)&255]));em.ret(eax=p+i if i>=0 else 0,argbytes=0)
 e.stub_import('strchr',find)
 def record(em,k):em.calllog.append(('parse',em.reg('ecx'),read(em,em.reg('edx'))))
 hook_rec(c,0x42c130,0,this=True,side=record,ret=lambda em,k:em.reg('edx')+offset)
 def trim(em,k):
  p=em.reg('ecx');s=read(em,p);em.calllog.append(('trim',s));em.wbytes(p,s.rstrip(b' \t\r\n')+b'\0')
 hook_rec(c,0x42f840,0,this=True,side=trim)
 return [rnd(c,0x10),src,arg,dst]

def vectors(c):
 clear_hooks(c);e=c.emu;r=c.rng;values=[[r.getrandbits(32) for _ in range(3)] for _ in range(4)];deltas=[r.getrandbits(32) for _ in range(3)]
 def transform(em,k):
  em.calllog.append(('transform',em.rbytes(em.reg('edx'),12),em.arg32(0)))
  for i,x in enumerate(values[k]):em.w32(em.reg('ecx')+4*i,x)
 hook_rec(c,0x441970,1,this='mark',side=transform)
 def translate(em,k):
  p=em.reg('ecx');em.calllog.append(('translate',em.rbytes(p,12),em.reg('edx')))
  for i in range(3):em.w32(p+4*i,(em.r32(p+4*i)+deltas[i])&0xffffffff)
 hook_rec(c,0x441940,0,this='mark',side=translate)
 s=rnd(c,0x60);o=obj(c,0x20,{0x14:pystub(c,0,this=True,ret=r.randrange(2))});e.w32(s+0x52,r.choice([0,o]));e.w8(s+0x14,r.randrange(4))
 draw=obj(c,0x20,{0x8c:pystub(c,4,this=True,deref={0:3,1:3,2:3})})
 return [s,draw,r.getrandbits(32),rnd(c,0x40),rnd(c,0x10)]

def transfer(c):
 clear_hooks(c);e=c.emu;r=c.rng;logger(c,4)
 base=rnd(c,0x10);name=rnd(c,0x10)
 owner=obj(c,0x20,{0x20:pystub(c,0,this=True,ret=base),0x548:pystub(c,2,this=True),0x54c:pystub(c,2,this=True)})
 child=obj(c,0x20,{0x2f4:pystub(c,0,this=True,ret=r.choice([owner,base,rnd(c,0x10)])),0x2e8:pystub(c,0,this=True,ret=name),0xbc:pystub(c,1,this=True),0x2c:pystub(c,0,this=True)})
 s=obj(c,0x20,{0x4c:pystub(c,1,this=True,ret=r.choice([0,owner,owner])),0x48:pystub(c,1,this=True,ret=r.choice([0,child,child]))})
 tin=rnd(c,0x10);tout=rnd(c,0x10);a=[rnd(c,8),rnd(c,8)];out=rnd(c,8)
 hook_rec(c,0x5003d0,1,this=True,ret=lambda em,k:out if em.reg('ecx')==tout else a[em.arg32(0)])
 hook_rec(c,0x5002f0,1,this=True)
 p=rnd(c,0x10);e.w32(p+4,tin);e.w32(p+8,tout);return [s,p]
S(0x50db50,'GUESS create transformed object output','thiscall',None,ret=None,gen=make_object,note='batch130005')
S(0x64dbb0,'GUESS remove keyed list object','thiscall',None,ret=None,gen=remove,note='batch130005')
S(0x42dd30,'GUESS parse trim string','thiscall',None,ret=None,gen=parse,note='batch130005')
S(0x453290,'GUESS transform and draw quad','thiscall',None,ret=None,gen=vectors,note='batch130005')
S(0x50b9b0,'GUESS transfer via slot 548','thiscall',None,ret=None,gen=transfer,note='batch130005')
S(0x50bab0,'GUESS transfer via slot 54c','thiscall',None,ret=None,gen=transfer,note='batch130005')
