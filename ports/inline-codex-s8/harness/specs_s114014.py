from pilot import S
from recruits_util import clear_hooks,rnd,obj,sysobj,hook_rec,_HOOKED

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng;s=rnd(c,0x150);node=rnd(c,0x80);other=rnd(c,0x80);entries=[rnd(c,24) for _ in range(3)]
 def noarg(slot):
  return e.stub_fn('owner',lambda em,_:(em.calllog.append(('owner',slot,em.reg('ecx'))),em.ret(eax=0,argbytes=0)))
 def allowed(em,_):
  em.calllog.append(('allow',em.reg('ecx'),em.arg32(0),em.rbytes(em.arg32(1),1),em.arg32(2)));em.w8(em.arg32(1),r.randrange(2));em.ret(eax=0,argbytes=12)
 owners=[obj(c,32,{0x228:noarg(0x228),0x22c:noarg(0x22c),0x128:e.stub_fn('allow',allowed)}) for _ in range(2)]
 for p in owners:d=rnd(c,64);e.w32(p+12,d);e.w32(d+0x23,r.choice([0,0x80000d]))
 e.w32(node+0x54,r.choice([0,owners[0],owners[0]]));e.w32(other+0x54,owners[1]);e.w32(s+0x84,r.randrange(3))
 for i,p in enumerate(entries):e.w32(p,r.choice([0,1,2]));e.w32(p+4,r.randrange(2));e.w32(p+12,r.randrange(4));e.w32(p+16,r.randrange(2))
 def listmake(values,integer=False):
  def begin(em,_):
   ip=em.arg32(0);em.w32(ip,len(values)+1);em.w32(ip+4,0);em.w32(ip+8,0);em.calllog.append(('begin',em.reg('ecx')));em.ret(eax=0,argbytes=4)
  def next(em,_):
   ip=em.arg32(0);i=em.r32(ip+4);v=values[i] if i<len(values) else 0;em.w32(ip,len(values)-i if i<len(values) else 0);em.w32(ip+4,i+1);em.calllog.append(('next',em.reg('ecx'),v));em.ret(eax=v,argbytes=4)
  return obj(c,32,{0x4c:e.stub_fn('begin',begin),0x5c:e.stub_fn('next',next),0x64:e.stub_fn('next',next)})
 lst=listmake(r.sample(entries,r.randrange(4)));e.w32(s+0xf2,e.r32(lst))
 lst2=listmake([r.randrange(4) for _ in range(r.randrange(4))]);data=rnd(c,32);e.w32(data+24,r.choice([0,lst2]));e.w32(s+0x12a,r.choice([0,data]))
 def table(slot):
  def h(em,_):
   a=em.arg32(0);em.calllog.append(('table',slot,a));em.ret(eax=r.randrange(3) if slot==0x50 else r.choice([0,other]),argbytes=4)
  return e.stub_fn('table',h)
 sysobj(c,table_slots={0x50:table(0x50),0x54:table(0x54)})
 def geom(em,_):
  p,q=em.arg32(0),em.arg32(1);a=bytes(r.getrandbits(8) for _ in range(36));b=bytes(r.getrandbits(8) for _ in range(12));em.wbytes(p,a);em.wbytes(q,b);em.calllog.append(('geom',a,b));em.ret(eax=0,argbytes=8)
 geometry=obj(c,16,{0x80:e.stub_fn('geom',geom)})
 def getgeom(em,_):em.calllog.append(('getgeom',em.reg('ecx')));em.ret(eax=geometry,argbytes=0)
 def transform(em,_):em.calllog.append(('transform',em.rbytes(em.arg32(0),36),em.rbytes(em.arg32(1),12)));em.ret(eax=0,argbytes=8)
 def targetcall(slot):return e.stub_fn('targetcall',lambda em,_:(em.calllog.append(('target',slot,em.reg('ecx'),em.arg32(0))),em.ret(eax=0,argbytes=4)))
 actors=[obj(c,32,{0x20:e.stub_fn('getgeom',getgeom),0x370:e.stub_fn('transform',transform),0x2d4:targetcall(0x2d4),0xbc:targetcall(0xbc)}) for _ in range(2)]
 def find(em,_):em.calllog.append(('find',em.reg('ecx'),em.arg32(0)));em.ret(eax=r.choice(actors+[0]),argbytes=4)
 e.hook(0x4b48c0,find);_HOOKED.add(0x4b48c0)
 for addr,narg in [(0x4dc030,0),(0x4db860,1),(0x4b3a70,0),(0x4d9430,0)]:hook_rec(c,addr,nargs=narg,this=True,ret=0)
 hook_rec(c,0x4d9590,nargs=1,pop=0,ret=0)
 hook_rec(c,0x4db9a0,nargs=1,this=True,ret=lambda em,k:0 if em.arg32(0)==0x200015 and not em.r32(node+0x54) else r.randrange(2))
 hook_rec(c,0x4dc110,nargs=0,this=True,ret=lambda em,k:r.getrandbits(32))
 def cmp(em,_):em.calllog.append(('cmp',em.arg32(0),em.arg32(1)));em.ret(eax=r.randrange(2),argbytes=0)
 e.w32(0x676414,e.stub_fn('cmp',cmp))
 return [s,node,r.choice([0,1,2,0x100])]
S(0x4b6e00,'GUESS detach node and transfer matching transforms','thiscall',None,ret=None,gen=gen)
