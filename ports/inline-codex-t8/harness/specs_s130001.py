from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub,logger,reftab,reftab_vt

def string(c,b):
 a=rnd(c,len(b)+1);c.emu.wbytes(a,b+b'\0');return a

def imports(c):
 def read(e,a):
  v=bytearray()
  while e.r8(a):v.append(e.r8(a));a+=1
  return bytes(v)
 def comp(e,r):
  a=read(e,e.arg32(0)).lower();b=read(e,e.arg32(1)).lower();e.ret(eax=(a>b)-(a<b),argbytes=0)
 c.emu.stub_import('_stricmp',comp)
 return read

def module(c):
 clear_hooks(c);e=c.emu;r=c.rng;read=imports(c)
 def last(e,r):
  a=e.arg32(0);b=read(e,a);i=b.rfind(bytes([e.arg32(1)&255]));e.ret(eax=a+i if i>=0 else 0,argbytes=0)
 e.stub_import('strrchr',last)
 path=r.choice([b'a.dll',b'C:\\bin\\b.dll',b'x\\A.DLL',b'empty\\',b'\\c.dll']);p=string(c,path);name=path.split(b'\\')[-1]
 entries=[]
 for i in range(r.randrange(5)):
  q=rnd(c,0x10);e.w32(q,string(c,r.choice([name,name.upper(),b'other.dll'])));entries.append(q)
 out=rnd(c,0x10);allocated=rnd(c,0x100)
 hook_rec(c,0x41e290,1,pop=0,ret=allocated)
 h=r.getrandbits(32)
 def load(e,r):e.calllog.append(('LoadLibraryA',read(e,e.arg32(0))));e.ret(eax=h,argbytes=4)
 e.stub_import('LoadLibraryA',load)
 t=reftab(c,entries);e.w32(e.r32(t)+4,pystub(c,1,this=True,ret=out,deref={0:-len(name)-1}))
 s=rnd(c,0x120);e.w32(s+0x10c,t);return [s,p]

def toggle(c):
 clear_hooks(c);e=c.emu;r=c.rng
 owner=rnd(c,0x20);o=rnd(c,0x10);e.w32(o+8,rnd(c,0x20))
 s=obj(c,0x90,{0x330:pystub(c,0,this=True),0x310:pystub(c,0,this=True,ret=r.choice([0,1,0x100,0x101])),0x20:pystub(c,0,this=True,ret=r.choice([0,o]))})
 hook_rec(c,0x4db7e0,0,this=True,ret=r.choice([0,owner]));hook_rec(c,0x442050,1,this=True);hook_rec(c,0x443c80,1,this=True)
 count=r.randrange(6);p=rnd(c,4+4*count);e.w16(p,count);e.w32(s+0x7b,r.choice([0,p]));e.w8(s+0x75,r.choice([0,1,2,255]));return [s,r.choice([0,1,2,255,256,r.getrandbits(32)])]

def fields(c):
 clear_hooks(c);e=c.emu;r=c.rng
 s=obj(c,0x60,{0x214:pystub(c,0,this=True)});e.w32(s+8,rnd(c,0x20));p=rnd(c,0x20)
 hook_rec(c,0x610100,1,this=True);hook_rec(c,0x4e1b30,0,this=True);hook_rec(c,0x4dc630,2,this=True)
 values=[r.getrandbits(32) for _ in range(12)]
 def side(e,k):e.w32(e.arg32(0),values[k])
 for addr in [0x4e12e0,0x4e12f0,0x4e11e0]:hook_rec(c,addr,2,this=True,side=side)
 kinds=[r.choice([8,0,0x108,7,9]) for _ in range(4)];hook_rec(c,0x4e1600,0,this=True,ret=lambda e,k:kinds[k])
 return [s,p]

def matrix(c):
 clear_hooks(c);e=c.emu;r=c.rng;logger(c)
 a=[r.getrandbits(32) for _ in range(9)];b=[r.getrandbits(32) for _ in range(3)]
 def side(e,k):
  for i,x in enumerate(a):e.w32(e.arg32(0)+4*i,x)
  for i,x in enumerate(b):e.w32(e.arg32(1)+4*i,x)
 hook_rec(c,0x4db6c0,2,this=True,nullflag=(0,1),side=side)
 ch=obj(c,0x20,{0x7c:pystub(c,2,this=True,deref={0:9,1:3})});base=rnd(c,0x20)
 sysobj(c,table_slots={0x54:pystub(c,1,this=True,ret=r.choice([0,base])),0x58:pystub(c,1,this=True,ret=r.choice([0,ch]))})
 s=rnd(c,0x110);e.w32(s+0x4a,reftab_vt(c,[r.getrandbits(32) for _ in range(r.randrange(6))]));key=r.randrange(65536);e.w16(s+0x48,key)
 return [s,r.choice([key,key|0xaabb0000,(key+1)&65535]),r.getrandbits(32)]

def match(c):
 clear_hooks(c);e=c.emu;r=c.rng;imports(c)
 base=rnd(c,0x20);other=rnd(c,0x20);names={base:string(c,b'alpha'),other:string(c,r.choice([b'alpha',b'ALPHA',b'beta']))}
 hook_rec(c,0x4dc110,0,this=True,ret=lambda e,k:names[e.reg('ecx')])
 elems=[r.getrandbits(32) for _ in range(r.randrange(6))];tab=reftab(c,elems);owner=rnd(c,0x30);e.w32(owner+0x18,r.choice([0,tab]));s=rnd(c,0x140);e.w32(s+0x12a,r.choice([0,owner]));e.w32(s+0x44,obj(c,0x20,{0x130:pystub(c,2,this=True)}));key=r.getrandbits(32)
 def lookup(e,k):return base if k==0 else other if e.arg32(0)&1 else 0
 out=r.choice([key,0,r.getrandbits(32)])
 def change(e,k):e.w32(e.arg32(4),out)
 sysobj(c,table_slots={0x54:pystub(c,1,this=True,ret=lookup),0x114:pystub(c,5,this=True,ret=r.getrandbits(32),nullflag=(4,),side=change)})
 return [s,key]
S(0x4279c0,'GUESS cache module by basename','thiscall',None,ret='eax',gen=module,note='batch130001')
S(0x4438a0,'GUESS toggle owner membership','thiscall',None,ret=None,gen=toggle,note='batch130001')
S(0x454e10,'GUESS deserialize fields','thiscall',None,ret=None,gen=fields,note='batch130001')
S(0x4b1570,'GUESS propagate matrix on key','thiscall',None,ret='eax',gen=matrix,note='batch130001')
S(0x4b5500,'GUESS match names or dispatch','thiscall',None,ret='eax',gen=match,note='batch130001')
