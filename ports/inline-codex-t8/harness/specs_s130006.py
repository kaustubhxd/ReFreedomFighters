from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub

def lifetime(c):
 clear_hooks(c);e=c.emu;r=c.rng;first=[0]
 ctors=[0x4ee210,0x4f3c00,0x4f1890,0x4f4080,0x4f4390,0x4f5960,0x4f6250,0x4f4ec0,0x4f4a30,0x4f6ab0,0x4f7960,0x4f8630]
 def ctor(addr):
  def side(em,k):
   p=em.reg('ecx')
   if addr==0x4ee210:first[0]=p
   em.calllog.append(('ctor',addr,p-first[0]));em.w32(p,addr^0x55aa1234)
  return side
 for a in ctors:hook_rec(c,a,3,this='mark',side=ctor(a))
 def dtor(addr):
  def side(em,k):
   p=em.reg('ecx');em.calllog.append(('dtor',addr,p-first[0]))
   if addr not in [0x4ccf60,0x4cbec0]:em.calllog.append(('contents',em.r32(p)))
  return side
 for a in [0x43ea20,0x4f3c30,0x4f1a10,0x4ee4e0,0x4f43d0,0x4f5990,0x4f6b80,0x4f7a00,0x4ccf60,0x4cbec0]:hook_rec(c,a,0,this='mark',side=dtor(a))
 return []

def setup(c):
 clear_hooks(c);e=c.emu;r=c.rng
 hook_rec(c,0x562440,0,this=True);hook_rec(c,0x563610,1,this=True,side=lambda em,k:em.w32(em.reg('ecx')+0x58,em.arg32(0)));hook_rec(c,0x5613a0,2,this=True)
 cfg=obj(c,0x20,{0x60:pystub(c,3,this=True)})
 child=obj(c,0x20,{0x258:pystub(c,2,this=True,deref={0:2})})
 root=obj(c,0x20,{0x25c:pystub(c,2,this=True,ret=r.getrandbits(32))})
 sysobj(c,table_slots={0x138:pystub(c,0,this=True,ret=cfg),0x4c:pystub(c,1,this=True,ret=lambda em,k:(em.arg32(0)^0xaaaabbbb)),0x58:pystub(c,1,this=True,ret=r.choice([0,child]))})
 s=rnd(c,0x220);e.w32(s+0x54,obj(c,0x20,{0x25c:pystub(c,2,this=True,ret=root)}));e.w32(s+0x94,r.choice([0,rnd(c,0x1060)]));return [s]

def hierarchy(c):
 clear_hooks(c);e=c.emu;r=c.rng
 nodes=[rnd(c,0x70) for _ in range(4)];objects=[]
 for i,p in enumerate(nodes):
  o=obj(c,0x30,{0x2a8:pystub(c,0,this=True,ret=(0 if i==3 else r.choice([0,0x1000000]))) });objects.append(o)
  e.w32(p+0x50,nodes[i+1] if i+1<len(nodes) else 0);e.w32(p+0x54,o);e.w32(p+0x3c,r.choice([0,0x40000000,0x40000]));e.w16(p+0x5c,r.choice([0,1,2,300]))
 special=rnd(c,0x30);e.w8(special+0x1c,r.randrange(2));sysobj(c,table_size=0x20)
 sys=e.r32(0x70039c);tab=e.r32(sys+0x9b);e.w32(tab+8,obj(c,0x20,{0x5c:pystub(c,1,this=True,ret=r.choice([0,special]))}))
 hook_rec(c,0x4db580,1,this=True,ret=r.choice(objects+[r.getrandbits(32)]))
 n=r.choice([0,1,2,5,-1]);a=rnd(c,max(4,n*4))
 for i in range(max(0,n)):e.w32(a+4*i,r.choice(objects+[r.getrandbits(32)]))
 return [nodes[0],n,a]

def indices(c):
 clear_hooks(c);e=c.emu;r=c.rng;s=rnd(c,0x1410);count=r.choice([0,1,2,3,7]);out=rnd(c,0x100);offset=r.getrandbits(32)
 resource=obj(c,0x20,{0x30:pystub(c,1)})
 buf=rnd(c,0x20);e.w32(buf,r.choice([0,resource]));e.w8(buf+0xc,r.randrange(2));e.w32(s+0x13f6,buf)
 device=obj(c,0x20,{0x154:pystub(c,3),0x11c:pystub(c,6) });e.w32(s+0x1377,device);e.w32(0x724a00,device);e.w32(0x7249f0,r.choice([0,e.r32(buf),r.getrandbits(32)]));e.w32(0x7249f4,r.randrange(2))
 for j in range(6):e.w16(0x6efce0+2*j,r.randrange(65536))
 def side(em,k):em.w32(em.arg32(1),offset)
 hook_rec(c,0x60ed80,2,this=True,deref={0:1},nullflag=(1,),ret=out,side=side)
 return [s,count,r.choice([0,1,65534,65535,0xffffffff,r.getrandbits(32)])]
S(0x4edef0,'GUESS register temporary object types','cdecl',None,ret=None,gen=lifetime,note='batch130006')
S(0x56ddc0,'GUESS setup pair and child parameters','thiscall',None,ret=None,gen=setup,note='batch130006')
S(0x4dba00,'GUESS hierarchy list membership','fastcall',None,ret='al',gen=hierarchy,note='batch130006')
S(0x60bfc0,'GUESS build quad indices and draw','thiscall',None,ret=None,gen=indices,note='batch130006')
