from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub

def base(c):
 clear_hooks(c);e=c.emu;e.w32(0x7003b0,pystub(c,0,ret=c.rng.getrandbits(32),pop=0))
 e.hook(0x633654,lambda em,rr:em.ret(eax=em.reg('eax'),argbytes=0))

def g26a0(c):
 base(c);e=c.emu;r=c.rng
 me=obj(c,0x20,{0x314:pystub(c,0,this=True,ret=r.choice([0,rnd(c,0x20),rnd(c,0x20)]))})
 owner=rnd(c,0x50);e.w32(owner+0x3c,r.choice([0,1,0x400,0x401,0x800]));e.w32(me+8,owner)
 entries=[r.getrandbits(32) for _ in range(r.randrange(7))]
 def transform(em,k):
  em.calllog.append(('transform',em.reg('edx'),em.arg32(0)))
  for i in range(3):em.w32(em.reg('ecx')+4*i,(em.reg('edx')+em.arg32(0)+i*7)&0xffffffff)
 hook_rec(c,0x43e8e0,1,this='mark',side=transform)
 def build(em,k):
  ctx=em.arg32(0);t=em.arg32(2)
  em.calllog.append(('context',em.r32(ctx),em.r32(ctx+4),em.r32(ctx+0x64),em.r32(ctx+0x68),em.r32(ctx+0x60)==t))
  for i,v in enumerate(entries):em.w32(em.r32(ctx+0x5c)+4*i,v)
  em.w32(ctx+0x64,len(entries))
 hook_rec(c,0x4e4520,3,this=True,stackmark=(0,),deref={2:3},side=build)
 rets=[r.choice([0,1,2,128,255,0x100,0x101,r.getrandbits(32)]) for _ in entries]
 def dispatch(em,k):em.calllog.append(('entry_ref',em.reg('edx')))
 hook_rec(c,0x442420,5,this=True,side=dispatch,ret=lambda em,k:rets[k])
 return [me]+[r.getrandbits(32) for _ in range(7)]

def g69b0(c):
 base(c);e=c.emu;r=c.rng
 def printf(em,rr):
  fmt=em.arg32(1);n=3 if fmt==0x682e94 else 5
  em.calllog.append(('print',tuple(em.arg32(i) for i in range(n))))
  em.ret(eax=0,argbytes=0)
 log=obj(c,0x20,{0x188:e.stub_fn('printf-varargs',printf)})
 me=rnd(c,0x830);pool=rnd(c,6*0x94c);e.w32(me+0x81d,pool)
 for i in range(6):e.w32(pool+i*0x94c,i+2 if i<5 and r.randrange(2) else 0);e.w32(pool+i*0x94c+4,r.getrandbits(32))
 n=r.choice([0,1,2,3,5,256]);mapping={}
 for i in range(n):
  ident=i+1;actor=rnd(c,0x60);e.w32(actor+0x51,r.choice([0,1,2]));e.w32(actor+4,r.choice([0,rnd(c,0x10)]));mapping[ident]=actor
  e.w32(me+0x1d+8*i,ident);e.w32(me+0x21+8*i,r.randrange(7))
 if n<256:e.w32(me+0x1d+8*n,0)
 sysobj(c,slots={0x190:pystub(c,0,this=True,ret=log)},table_slots={0x58:pystub(c,1,this=True,ret=lambda em,k:mapping[em.arg32(0)])})
 return [me]
S(0x4426a0,'GUESS dispatch gathered entries and OR result bytes','thiscall',None,ret='al',gen=g26a0)
S(0x4569b0,'GUESS print actor allocation chain totals','thiscall',None,ret=None,gen=g69b0)
