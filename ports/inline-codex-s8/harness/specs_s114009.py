from pilot import S
from recruits_util import clear_hooks,rnd,obj

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng;s=rnd(c,64);dd=rnd(c,16);nodes=rnd(c,112*4);e.w32(dd+4,nodes);e.w32(s+20,dd)
 def stream(slot):
  def h(em,_):
   if slot==16:em.calllog.append(('write',em.arg32(1),em.r32(em.arg32(0))))
   else:em.calllog.append(('stream',slot,em.arg32(0)))
   em.ret(eax=r.getrandbits(32),argbytes=8 if slot==16 else 4)
  return e.stub_fn('stream',h)
 st=obj(c,32,{off:stream(off) for off in [8,16,0x28,0x5c]})
 ctx=rnd(c,16);e.w32(ctx,st);e.w32(ctx+8,rnd(c,16))
 def action(slot):
  def h(em,_):
   p=em.reg('ecx');em.calllog.append(('action',slot,p,em.arg32(0)))
   if r.randrange(2):em.w32(p+4,em.r32(p+4)&~0x40)
   em.ret(eax=0,argbytes=4)
  return e.stub_fn('action',h)
 items=[obj(c,0x50,{0x24:action(0x24),0x1c:action(0x1c)}) for _ in range(4)]
 for p in items:e.w32(p+0x40,rnd(c,8));e.w32(p+28,r.randrange(2))
 def resolve(em,_):em.calllog.append(('resolve',em.arg32(0)));em.ret(eax=items[em.arg32(0)%4],argbytes=4)
 manager=obj(c,32,{0xcc:e.stub_fn('resolve',resolve)});e.w32(0x70038c,manager)
 def log(em,_):em.calllog.append(('log',*[em.arg32(i) for i in range(3)]));em.ret(eax=0,argbytes=0)
 lo=obj(c,16,{0x2c:e.stub_fn('log',log)})
 def logger(em,_):em.calllog.append(('logger',em.arg32(0),em.arg32(1)));em.ret(eax=lo,argbytes=8)
 e.w32(0x700390,obj(c,16,{0x20:e.stub_fn('logger',logger)}))
 e.w32(0x7003b0,e.stub_fn('assert',lambda em,_:(em.calllog.append(('assert',)),em.ret(eax=0,argbytes=0))))
 for i in range(4):
  node=nodes+112*i;owner=rnd(c,0x60);d=rnd(c,0x40);e.w32(d+0x23,r.choice([0,0x100000]));e.w32(owner+12,d)
  e.w32(owner+0x50,nodes+112*(i+1) if i<3 and r.randrange(2) else 0);e.w32(node+0x60,0)
  n=r.randrange(4)
  def active(em,_):em.calllog.append(('active',em.reg('ecx')));em.ret(eax=r.randrange(2),argbytes=0)
  def begin(em,_,n=n):
   p=em.arg32(0);em.w32(p,n);em.w32(p+4,0);em.w32(p+8,0);em.calllog.append(('begin',em.reg('ecx')));em.ret(eax=0,argbytes=4)
  def next(em,_):
   p=em.arg32(0);remaining=em.r32(p);em.w32(p,remaining-1 if remaining else 0);v=r.randrange(4);em.calllog.append(('next',em.reg('ecx'),remaining,v));em.ret(eax=v,argbytes=4)
  lst=obj(c,16,{20:e.stub_fn('active',active),0x4c:e.stub_fn('begin',begin),0x5c:e.stub_fn('next',next)})
  link=rnd(c,16);e.w32(link+8,lst if r.randrange(5) else 0);e.w32(owner+16,link if r.randrange(5) else 0);e.w32(node+0x54,owner if r.randrange(5) else 0)
 return [s,ctx,nodes]
S(0x498f00,'GUESS serialize selected node tree','thiscall',None,ret=None,gen=gen)
