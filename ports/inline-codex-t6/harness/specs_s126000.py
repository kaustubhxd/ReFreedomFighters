from pilot import S, F
from recruits_util import rnd, sysobj, clear_hooks, hook_rec, pystub
import struct

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 so=sysobj(c);me=rnd(c,0x30);link=rnd(c,0x20);out=rnd(c,0x40)
 e.w32(me+0x18,link);e.w32(link+8,out)
 def wf(a,v):e.wbytes(a,struct.pack('<f',v))
 wf(so+0x48,r.choice([0,0.001,0.016,0.1,1,10,-0.01]))
 v=r.uniform(-10,10);wf(me+0x10,v);wf(me+0x14,r.choice([v,0,r.uniform(-10,10)]))
 vals=[r.getrandbits(32) for _ in range(9)]
 def matrix(em,k):
  p=em.reg('ecx')
  for i,v in enumerate(vals):em.w32(p+4*i,v)
 def build(em,res):
  em.calllog.append(('matrix',em.rbytes(em.reg('edx'),12),em.arg32(0)))
  matrix(em,0);em.ret(eax=0,argbytes=4)
 e.hook(0x4ddcb0,build)
 # tracked by clear_hooks via hook_rec before replacing with custom fastcall recorder
 hook_rec(c,0x4ddcb0,1);e.hook(0x4ddcb0,build)
 hook_rec(c,0x4dcb90,1,this=True,deref={0:9})
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 return [me,F(r.uniform(-10,10))]
S(0x52a0b0,'GUESS steering interpolation and transform','thiscall',None,ret=None,gen=gen)
