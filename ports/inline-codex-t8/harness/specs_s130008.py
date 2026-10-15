from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub,logger,reftab

def keys(c):
 clear_hooks(c);e=c.emu;r=c.rng
 held={k:r.choice([0,1,0x100,0x101]) for k in [0x11,0x21,0x22]};pressed={k:r.choice([0,1,0x100,0x101]) for k in [0x38,0x39,0x30]}
 so=sysobj(c,slots={0xe4:pystub(c,1,this=True,ret=lambda em,k:held[em.arg32(0)]),0xe8:pystub(c,1,this=True,ret=lambda em,k:pressed[em.arg32(0)])});e.w32(so+0x1aa3,rnd(c,0x100));e.w8(0x7f6414,r.randrange(2));e.w8(0x7f6415,r.randrange(2));return [rnd(c,0x1170)]

def format(c):
 clear_hooks(c);e=c.emu;r=c.rng;out=rnd(c,0x20);other=rnd(c,0x20);buf=rnd(c,0x10)
 e.w32(out+8,r.choice([0,1]));e.w32(other+0xc,r.choice([0,1]));e.w32(buf+8,r.choice([0,1]));state=bytes(r.getrandbits(8) for _ in range(20))
 hook_rec(c,0x410bc0,3,pop=0,nullflag=(0,),side=lambda em,k:em.wbytes(em.arg32(0),state))
 hook_rec(c,0x410de0,2,pop=0,deref={0:5},ret=r.choice([0,1,2,3,4,5,255]))
 magic=e.rbytes(0x6efd38,6)
 if r.random()<0.25:magic=bytes([magic[0]^1])+magic[1:]
 hook_rec(c,0x401320,3,pop=0,deref={0:5},nullflag=(1,),side=lambda em,k:em.wbytes(em.arg32(1),magic))
 for a in [0x401350,0x401430,0x401510]:hook_rec(c,a,2,pop=0,deref={1:5},ret=r.getrandbits(32),side=lambda em,k:em.w32(em.arg32(0),0x12345678))
 return [out,other,r.choice([0,buf,buf,buf])]

def render(c):
 clear_hooks(c);e=c.emu;r=c.rng;s=rnd(c,0xb10);stream=rnd(c,0x100);e.w32(s+0xaec,r.choice([0,stream,stream]));e.w32(s+0xae8,0x80);e.w32(stream,r.randrange(2));e.w32(stream+0x60,0xffffffff)
 e.w32(0x70038c,obj(c,0x20,{0x48:pystub(c,1,this=True,ret=r.getrandbits(32))}))
 def draw(em,k):em.w32(em.arg32(0),0x55aaccdd)
 nodes=[]
 for i in range(r.randrange(6)):
  n=rnd(c,0x70);o=obj(c,0x20,{0x308:pystub(c,0,this=True,ret=r.choice([0,1,0x100])),0x32c:pystub(c,1,this=True,ret=lambda em,k:em.arg32(0)+4,side=draw)})
  f=rnd(c,0x30);e.w32(f+0x23,r.choice([0,0x100000,0x200002]));e.w32(o+0xc,f);e.w32(n+0x54,r.choice([0,o]));nodes.append(n)
 for i,n in enumerate(nodes):e.w32(n+0x60,nodes[i+1] if i+1<len(nodes) else 0)
 def nxt(em,k):p=em.arg32(0);em.w32(p,em.r32(em.r32(p)+0x60))
 manager=obj(c,0x20,{0x300:pystub(c,1,this=True),0x50:pystub(c,1,this=True,nullflag=(0,),side=nxt)});e.w32(manager+8,nodes[0] if nodes else 0)
 def remaining(em,k):em.calllog.append(('remaining',em.rbytes(em.arg32(0),em.arg32(1))))
 low=obj(c,0x20,{0x50:pystub(c,1,this=True,ret=lambda em,k:em.arg32(0)+4),0x40:pystub(c,2,this=True,side=remaining)})
 so=sysobj(c,table_size=0xb00);e.w32(e.r32(so+0x9b)+0xadc,manager);aux=rnd(c,0x30);e.w32(aux+0x1c,low);e.w32(so+0x1aa3,aux)
 hook_rec(c,0x4db9a0,1,this=True,ret=r.choice([0,1,0x101]));return [s]

def fields(c):
 clear_hooks(c);e=c.emu;r=c.rng;values=[r.getrandbits(32) for _ in range(10)]
 def side(size):
  def write(em,k):em.wbytes(em.arg32(0),(values[k]&((1<<(size*8))-1)).to_bytes(size,'little'))
  return write
 reader=obj(c,0x20,{off:pystub(c,1,this=True,side=side(size)) for off,size in [(0x48,4),(0x44,2),(0x68,1),(0x50,4)]})
 return [rnd(c,0x90),reader]

def child_count(c):
 clear_hooks(c);e=c.emu;r=c.rng;logger(c,3);e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 children=[obj(c,0x20,{0x1e0:pystub(c,1,this=True,ret=r.choice([0,1,0x100,0x101])),0x438:pystub(c,0,this=True,ret=r.choice([0,1,0x100,0x101]))}) for _ in range(3)]
 t=reftab(c,[r.randrange(100) for _ in range(r.randrange(7))]);owner=rnd(c,0x20);e.w32(owner+0x18,r.choice([0,t]));found=r.choice([0,owner])
 sysobj(c,table_slots={0x58:pystub(c,1,this=True,ret=lambda em,k:found if k==0 else children[em.arg32(0)%3])})
 tin=rnd(c,0x10);tout=rnd(c,0x10);a=rnd(c,8);out=rnd(c,8);e.w8(out+4,r.choice([0,1,2,255]))
 hook_rec(c,0x5003d0,1,this=True,ret=lambda em,k:out if em.reg('ecx')==tout else a)
 p=rnd(c,0x10);e.w32(p+4,tin);e.w32(p+8,tout);return [rnd(c,0x10),p]

def index_draw(c):
 clear_hooks(c);e=c.emu;r=c.rng;s=rnd(c,0x1410);count=r.choice([0,1,2,3,7]);out=rnd(c,0x100);offset=r.getrandbits(32)
 res=obj(c,0x20,{0x30:pystub(c,1)});buf=rnd(c,0x20);e.w32(buf,r.choice([0,res]));e.w8(buf+0xc,r.randrange(2));e.w32(s+0x13f6,buf)
 dev=obj(c,0x20,{0x154:pystub(c,3),0x11c:pystub(c,6)});e.w32(s+0x1377,dev);e.w32(0x724a00,dev);e.w32(0x7249f0,r.choice([0,e.r32(buf)]));e.w32(0x7249f4,r.randrange(2))
 for j in range(6):e.w16(0x6efd2c+2*j,r.randrange(65536))
 hook_rec(c,0x60ed80,2,this=True,deref={0:1},nullflag=(1,),ret=out,side=lambda em,k:em.w32(em.arg32(1),offset))
 return [rnd(c,0x10),count,r.choice([0,1,65534,65535,0xffffffff,r.getrandbits(32)]),s]
S(0x6553a0,'GUESS input speed and flag toggles','thiscall',None,ret=None,gen=keys,note='batch130008')
S(0x401220,'GUESS format header dispatch','cdecl',None,ret='eax',gen=format,note='batch130008')
S(0x48dcb0,'GUESS render object stream','thiscall',None,ret=None,gen=render,note='batch130008')
S(0x4c2280,'GUESS read packed fields','thiscall',None,ret='al',gen=fields,note='batch130008')
S(0x551fb0,'GUESS count eligible children','thiscall',None,ret=None,gen=child_count,note='batch130008')
S(0x61a520,'GUESS build template indices and draw','thiscall',None,ret=None,gen=index_draw,note='batch130008')
