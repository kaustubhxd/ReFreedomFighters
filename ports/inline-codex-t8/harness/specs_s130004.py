from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub,logger

def text(c,b):
 p=rnd(c,len(b)+1);c.emu.wbytes(p,b+b'\0');return p

def compare(c,stack=False):
 def read(e,p):
  b=bytearray()
  while e.r8(p):b.append(e.r8(p));p+=1
  return bytes(b)
 def cmp(e,k):
  a=read(e,e.arg32(0)).lower();b=read(e,e.arg32(1)).lower();e.calllog.append(('stricmp',a,b));e.ret(eax=(a>b)-(a<b),argbytes=0)
 c.emu.stub_import('_stricmp',cmp)

def descriptors(c):
 clear_hooks(c);r=c.rng
 cfg=obj(c,0x20,{0x60:pystub(c,2,this=True)})
 sysobj(c,table_slots={0x138:pystub(c,0,this=True,ret=cfg),0x50:pystub(c,2,this=True,ret=r.getrandbits(32))})
 return [rnd(c,0x1400)]

def records(c):
 clear_hooks(c);r=c.rng;e=c.emu;compare(c,True)
 s=rnd(c,0x30);root=rnd(c,0x400);e.w32(s+0x11,root);flags=r.choice([0,0x40000000,0x80000000,0xc0000000]);count=r.randrange(6);extra=r.randrange(4)
 e.w32(root+4,flags);e.w32(root+0xc,count);e.w32(root+0x10,extra)
 start=0x14+extra*4 if flags&0x40000000 else 0x10
 names=[r.choice([b'a\\b',b'ALPHA',b'beta',b'']) for _ in range(count)]
 for i,name in enumerate(names):
  p=root+start+i*0x60;kind=r.choice([0,0x40000000,0x80000000,0xc0000000]);e.w32(p+4,kind|0x60)
  if kind:e.w32(p+8,0x10)
  e.wbytes(p+(0x10 if kind else 8),name+b'\0')
 query=r.choice(names+[b'missing',b'A/B',b'alpha']);return [s,text(c,query)]

def script(c):
 clear_hooks(c);r=c.rng;e=c.emu;logger(c,3);e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 entries=[]
 for i in range(7):
  a=rnd(c,8);kind=r.choice([3,4,0,5]);val=r.getrandbits(32)
  if kind==4:val=obj(c,0x20,{0x34:pystub(c,0,this=True,ret=r.getrandbits(32))})
  e.w32(a,val);e.w8(a+4,kind);entries.append(a)
 hook_rec(c,0x5003d0,1,this=True,ret=lambda em,k:entries[em.arg32(0)])
 sysobj(c,table_slots={0x114:pystub(c,5,this=True,ret=r.getrandbits(32),deref={4:5})})
 s=rnd(c,0x20);p=rnd(c,0x10);e.w32(s+0xc,obj(c,0x20,{0x12c:pystub(c,2,this=True,ret=r.getrandbits(32))}));e.w32(p+4,rnd(c,0x20));return [s,p]

def inherited(c):
 clear_hooks(c);r=c.rng;e=c.emu;compare(c);logger(c,3);e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 query=text(c,r.choice([b'alpha',b'BETA',b'missing',b'']));nodes=[rnd(c,0x100) for _ in range(r.randrange(1,4))]
 hook_rec(c,0x5ffb00,1,this=True,ret=text(c,r.choice([b'alpha',b'beta',b'other'])))
 log=obj(c,0x20,{0xc:pystub(c,3,pop=0)});hook_rec(c,0x5fa630,0,pop=0,ret=log)
 for i,p in enumerate(nodes):
  e.w32(p+0x9c,nodes[i+1] if i+1<len(nodes) else 0);n=r.randrange(5);base=r.randrange(4);count=r.randrange(5);e.w32(p+0xa0,base);e.w32(p+0xa8,count);e.w32(p+0xd0,n)
  blob=rnd(c,0x100);offsets=rnd(c,0x20);keys=rnd(c,max(4,n*2));out=rnd(c,max(4,n*4));e.w32(p+0xb0,blob);e.w32(p+0xac,offsets);e.w32(p+0xf0,keys);e.w32(p+0xe0,out)
  for j in range(count):e.w32(offsets+4*j,0x20*j);e.wbytes(blob+0x20*j,r.choice([b'alpha',b'beta',b'other',b''])+b'\0')
  for j in range(n):e.w16(keys+2*j,r.randrange(9))
 return [r.choice([0,nodes[0],nodes[0],nodes[0]]),query]

def ranges(c):
 clear_hooks(c);r=c.rng;e=c.emu;logger(c,slot=0x30)
 s=rnd(c,0x30);owner=rnd(c,0x20);count=r.choice([0,1,2,3,5]);packed=rnd(c,0x200);e.w16(packed,count);p=packed+2
 for i in range(count):n=r.randrange(9);e.w16(p,n);p+=2+2*n
 data=rnd(c,max(8,count*8));e.w32(data+4,r.choice([0,r.getrandbits(32)]));e.w32(s+0x14,r.choice([0,r.getrandbits(32)]))
 hook_rec(c,0x41e290,1,pop=0,ret=data);hook_rec(c,0x4cd9b0,2,this=True,ret=r.choice([0xffffffff,0,1,0x7ffffffe,r.getrandbits(32)]));hook_rec(c,0x4ce1c0,2,this=True);hook_rec(c,0x634273,2,pop=0)
 return [s,packed,owner]
S(0x44ce80,'GUESS initialize eight descriptors','thiscall',None,ret=None,gen=descriptors,note='batch130004')
S(0x4d4de0,'GUESS normalized record lookup','thiscall',None,ret='eax',gen=records,note='batch130004')
S(0x503330,'GUESS script five-word dispatch','thiscall',None,ret='eax',gen=script,note='batch130004')
S(0x5ffe80,'GUESS inherited name lookup','thiscall',None,ret='eax',gen=inherited,note='batch130004')
S(0x659220,'GUESS load packed ranges','thiscall',None,ret=None,gen=ranges,note='batch130004')
