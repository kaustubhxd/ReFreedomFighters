from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub,logger,reftab

def text(c,b):
 p=rnd(c,len(b)+1);c.emu.wbytes(p,b+b'\0');return p

def ring(c):
 clear_hooks(c);e=c.emu;r=c.rng;sysobj(c);s=rnd(c,0x10090);manager=rnd(c,0x8300);tab=rnd(c,0x4000);e.w32(s+0x1005d,manager);e.w32(s+0x10071,tab);index=r.choice([0,1,2046,2047,r.randrange(2048)]);e.w32(manager+0x268,manager+0x270+4*index)
 p=rnd(c,0x20);listobj=rnd(c,0x20);e.w32(p+8,listobj)
 for i in range(8):
  ch=rnd(c,0x20);o=rnd(c,0x20);e.w8(o+8,r.choice([0,1,2,255]));e.w32(ch+8,o);e.w32(ch+0xc,r.choice([0,1,1,2,3]));e.w32(tab+4*i,ch)
 entries=[]
 for i in range(r.randrange(7)):
  q=rnd(c,0x44);e.w16(q+0x40,r.randrange(8)|(r.randrange(16)<<12));entries.append(r.choice([0,q]))
 hook_rec(c,0x658f50,0,this=True,ret=len(entries));hook_rec(c,0x658f10,1,this=True,ret=lambda em,k:entries[em.arg32(0)]);hook_rec(c,0x63ef00,1,this=True)
 return [s,p]

def reader(c):
 clear_hooks(c);e=c.emu;r=c.rng;out=rnd(c,0x20);stream=rnd(c,0x20);n=r.choice([-1,0,1,5]);count=r.choice([-1,0,1,2,5]);vals=[n,count]+[r.choice([-1,0,1,7]) for _ in range(max(0,count))]+[r.choice([0,1,2])]
 hook_rec(c,0x410de0,2,pop=0,ret=lambda em,k:vals[k])
 blocks=[rnd(c,0x80) for _ in range(12)]
 def clear(em,k):em.wbytes(blocks[k],bytes(em.arg32(0)*em.arg32(1)))
 hook_rec(c,0x634df4,2,pop=0,ret=lambda em,k:blocks[k],side=clear)
 payload=bytes(r.getrandbits(8) for _ in range(16))
 hook_rec(c,0x401320,3,pop=0,side=lambda em,k:em.wbytes(em.arg32(1),payload[:em.arg32(2)]))
 hook_rec(c,0x401020,1,pop=0,deref={0:4},side=lambda em,k:em.wbytes(em.arg32(0),bytes(16)))
 return [out,stream]

def named(c):
 clear_hooks(c);e=c.emu;r=c.rng;elems=[]
 for i in range(r.randrange(7)):
  base=rnd(c,0x14);p=base+4;e.w32(p,r.choice([0,1,2,0xffffffff]));e.w32(p+4,text(c,r.choice([b'alpha',b'BETA',b''])));elems.append(r.choice([0,p]))
 t=reftab(c,elems);s=rnd(c,0x30);e.w32(s+0x19,r.choice([0,t]));e.w32(s+0x11,obj(c,0x20,{0x30:pystub(c,2,this=True,ret=r.getrandbits(32)),0x34:pystub(c,2,this=True,ret=r.getrandbits(32))}))
 def read(em,p):
  b=bytearray()
  while em.r8(p):b.append(em.r8(p));p+=1
  return bytes(b).lower()
 def cmp(em,k):
  a=read(em,em.arg32(0));b=read(em,em.arg32(1));em.calllog.append(('cmp',a,b));em.ret(eax=(a>b)-(a<b),argbytes=0)
 e.stub_import('_stricmp',cmp);return [s,text(c,r.choice([b'ALPHA',b'beta',b'',b'missing']))]

def spans(c):
 clear_hooks(c);e=c.emu;r=c.rng;logger(c)
 block=rnd(c,0x300);head=block+0x100;size=r.choice([4,16,32,64]);e.w32(head,size);n=r.randrange(5);table=rnd(c,0x80);s=rnd(c,0x10);e.w32(s,table);e.w32(s+4,r.choice([n,n+1,max(0,n-1)]));e.w32(s+8,n)
 candidates=[(head-64,64),(head+size,96),(head-128,32),(head+size+128,16)]
 r.shuffle(candidates)
 for i in range(n):a,z=candidates[i];e.w32(table+8*i,a);e.w32(table+8*i+4,z)
 return [s,r.choice([0,head+4,head+4,head+4])]
S(0x64d6b0,'GUESS enqueue and release references','thiscall',None,ret=None,gen=ring,note='batch130007')
S(0x401430,'GUESS read counted string arrays','cdecl',None,ret='eax',gen=reader,note='batch130007')
S(0x437c90,'GUESS named entry dispatch','thiscall',None,ret='al',gen=named,note='batch130007')
S(0x4d1140,'GUESS coalesce freed span','thiscall',None,ret=None,gen=spans,note='batch130007')
