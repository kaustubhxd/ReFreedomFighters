from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub,logger

def text(c,b):
 p=rnd(c,len(b)+1);c.emu.wbytes(p,b+b'\0');return p

def chain(c):
 clear_hooks(c);r=c.rng;e=c.emu
 for a,n in [(0x562440,0),(0x563510,1),(0x561f10,1)]:hook_rec(c,a,n,this=True)
 limit=r.choice([-10,0,1,10,100]);p=text(c,str(limit).encode())
 def atoi(em,k):em.ret(eax=limit,argbytes=0)
 e.stub_import('atoi',atoi)
 nodes=[]
 for i in range(r.randrange(6)):
  n=rnd(c,0x70);flags=r.choice([0x100000,0x100001,0,0x200002]);o=obj(c,0x20,{0x1e0:pystub(c,1,this=True,ret=r.choice([0,1,0x100,0x101])),0x310:pystub(c,0,this=True,ret=r.choice([-20,0,1,10,99])),0x2dc:pystub(c,0,this=True)})
  f=rnd(c,0x30);e.w32(f+0x23,flags);e.w32(o+0xc,f);e.w32(n+0x54,r.choice([0,o]));nodes.append(n)
 for i,n in enumerate(nodes):e.w32(n+0x60,nodes[i+1] if i+1<len(nodes) else 0)
 root=rnd(c,0x60);e.w32(root+0x50,nodes[0] if nodes else 0)
 cfg=obj(c,0x20,{0x60:pystub(c,2,this=True,ret=r.randrange(2)),0x64:pystub(c,2,this=True)})
 sysobj(c,slots={0x5c:pystub(c,2,this=True,ret=r.randrange(2),nullflag=(1,),side=lambda em,k:em.w32(em.arg32(1),p)),0xbc:pystub(c,0,this=True,ret=cfg)})
 s=rnd(c,0x80);e.w32(s+0x44,obj(c,0x20,{0xbc:pystub(c,1,this=True)}));e.w32(s+0x54,obj(c,0x20,{0x25c:pystub(c,2,this=True,ret=root)}));return [s]

def bits(c):
 clear_hooks(c);r=c.rng;e=c.emu;s=rnd(c,0x20);old=rnd(c,0x200);new=rnd(c,0x300);off=r.randrange(64);cap=r.choice([off+4,off+5,max(0,off-1),128]);bit=r.randrange(8)
 e.w32(s,off);e.w32(s+4,bit);e.w32(s+8,old);e.w32(s+0xc,old+off);e.w32(s+0x10,cap)
 hook_rec(c,0x634dee,2,pop=0,ret=new,side=lambda em,k:em.wbytes(new,em.rbytes(em.arg32(0),cap)))
 return [s,r.getrandbits(32),r.choice([0,1,7,8,15,16,23,24,31,32,r.randrange(33)])]

def resource(c):
 clear_hooks(c);r=c.rng;e=c.emu;logger(c)
 desc=[]
 o=obj(c,0x20,{0x2c:pystub(c,2,ret=r.randrange(3)),0x34:pystub(c,3,ret=r.randrange(3)),0x18:pystub(c,3,ret=r.randrange(3),deref={2:5})})
 s=obj(c,0x200,{0x28:pystub(c,0,this=True)})
 dev=obj(c,0x20,{0xc:pystub(c,4,ret=r.randrange(3),side=lambda em,k:em.w32(em.arg32(2),o))})
 sysobj(c);return [s,dev]

def label(c):
 clear_hooks(c);r=c.rng;e=c.emu
 o=obj(c,0x20,{0x1e0:pystub(c,1,this=True,ret=r.randrange(2)),0x354:pystub(c,0,this=True,ret=r.choice([0,1,2,3,4,0xffffffff]))})
 s=rnd(c,0x110);e.w32(s+0xf4,r.choice([0,o]));buf=rnd(c,0x200);e.wbytes(buf,r.choice([b'',b'name',b'abc def'])+b'\0')
 t=obj(c,0x20,{0:pystub(c,2,this=True,ret=text(c,r.choice([b'',b'a$b$c$d',b'no dollars',b'$$$',b'$one$two$three$four'])))})
 sys=sysobj(c,table_size=0xb00);e.w32(e.r32(sys+0x9b)+0xae4,t);return [s,buf]

def modes(c):
 clear_hooks(c);r=c.rng;e=c.emu;v=r.getrandbits(32)
 target=obj(c,0x20,{0x2f0:pystub(c,0,this=True,ret=r.getrandbits(32))})
 s=obj(c,0x1a0,{0xd8:pystub(c,0,this=True,ret=r.choice([0,0,0,1,0x100])),0x84:pystub(c,0,this=True,ret=target)})
 for off in [0x180,0x184,0x188,0x190]:e.w32(s+off,r.choice([v,r.getrandbits(32)]))
 sysobj(c,table_slots={0x4c:pystub(c,1,this=True,ret=v)})
 for a in [0x578e30,0x578db0,0x578eb0,0x578d30]:hook_rec(c,a,0,this=True,ret=r.choice([0,1,0x100,0x101]))
 for a in [0x579bd0,0x579b20,0x579ca0,0x579a60]:hook_rec(c,a,1,this=True)
 hook_rec(c,0x579d20,0,this=True);hook_rec(c,0x562d90,1,this=True,ret=r.getrandbits(32))
 return [s,r.choice([0x102,0x103,0,1,r.getrandbits(32)])]
S(0x573180,'GUESS linked object limit pass','thiscall',None,ret=None,gen=chain,note='batch130003')
S(0x410bf0,'GUESS pack bits with buffer growth','cdecl',None,ret=None,gen=bits,note='batch130003')
S(0x429230,'GUESS create and configure resource','thiscall',None,ret='al',gen=resource,note='batch130003')
S(0x571a40,'GUESS append selected label','thiscall',None,ret=None,gen=label,note='batch130003')
S(0x579880,'GUESS toggle selected mode','thiscall',None,ret='al',gen=modes,note='batch130003')
