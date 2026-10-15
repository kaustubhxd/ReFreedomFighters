from pilot import S
from recruits_util import clear_hooks,rnd,obj,sysobj,hook_rec,_HOOKED

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng
 def basic(slot,nargs,ret=None):
  def h(em,_):em.calllog.append(('call',slot,em.reg('ecx'),*[em.arg32(i) for i in range(nargs)]));em.ret(eax=r.getrandbits(32) if ret is None else ret,argbytes=nargs*4)
  return e.stub_fn('call',h)
 s=obj(c,0x1000,{0x57c:basic(0x57c,1),0x100:basic(0x100,1)})
 e.w32(s+0x684,r.randrange(6));e.w32(s+8,rnd(c,0x80));e.w32(s+0x85a,r.choice([0,r.getrandbits(32)]));e.w32(s+0x852,r.choice([0,rnd(c,256)]))
 def integer(em,_):
  em.calllog.append(('integer',em.arg32(0),em.r32(em.arg32(1))));em.w32(em.arg32(1),r.choice([0,1,3,5]));em.ret(eax=0,argbytes=8)
 query=obj(c,32,{0x9c:basic(0x9c,2),0x88:e.stub_fn('integer',integer),0x60:basic(0x60,3)})
 def getquery(off):return e.stub_fn('query',lambda em,_:(em.calllog.append(('query',off)),em.ret(eax=query,argbytes=0)))
 resource=rnd(c,32);e.w32(resource+8,rnd(c,0x80));loader=obj(c,32,{0x25c:basic(0x25c,2,resource)})
 manager=obj(c,32,{0x64:basic(0x64,1,r.choice([0,rnd(c,32)]))})
 system=sysobj(c,table_slots={0x134:getquery(0x134),0x138:getquery(0x138),0x4c:basic(0x4c,1)},table_size=0xb00);t=e.r32(system+0x9b);e.w32(t+0xadc,loader);e.w32(system+0x1b5d,r.randrange(3));e.w32(system+0x1a9f,r.choice([0,manager]))
 for i in range(6):e.w32(0x6ed188+i*28,r.getrandbits(32));e.w32(0x6ed17c+i*28,r.getrandbits(32))
 registry=rnd(c,0x3000);e.w32(0x7003b8,registry);e.w32(registry+0xd8d,r.randrange(4));scenario=rnd(c,0x60);e.w8(scenario+0x4a,r.choice([49,50,51,255]));e.w8(scenario+0x4b,r.choice([65,66]));e.w32(registry+0x2c15,r.choice([0,scenario]))
 for addr in [0x4824c0,0x58b930]:hook_rec(c,addr,nargs=0,this=True,ret=0)
 def ctor(em,_):
  p=em.reg('ecx');data=bytes(r.getrandbits(8) for _ in range(244));em.wbytes(p,data);em.calllog.append(('ctor',em.arg32(0),data));em.ret(eax=p,argbytes=4)
 def copy(em,_):
  p=em.reg('ecx');data=em.rbytes(em.arg32(0),244);em.wbytes(p,data);em.calllog.append(('copy',p,data));em.ret(eax=p,argbytes=4)
 def setting(em,_):
  p=em.reg('ecx');em.calllog.append(('setting',em.r32(p),em.r32(p+4)));em.ret(eax=r.randrange(2),argbytes=0)
 for addr,fn in [(0x5889c0,ctor),(0x589710,copy),(0x58b6a0,setting)]:e.hook(addr,fn);_HOOKED.add(addr)
 return [s]
S(0x58e720,'GUESS initialize hero class resources','thiscall',None,ret=None,gen=gen)
