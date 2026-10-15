from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub
import struct

def gen(c):
 clear_hooks(c);r=c.rng;e=c.emu;me=obj(c,0x26a0,{0x384:pystub(c,0,this=True)});so=sysobj(c)
 def wf(a,v):e.wbytes(a,struct.pack('<f',v))
 wf(so+0x48,r.choice([0,0.016,0.1,1,-0.1]));v=r.uniform(-10,10);wf(me+0x268d,v);wf(me+0x2691,r.choice([v,r.uniform(-10,10)]))
 e.w32(me+0x2610,r.randrange(2));e.w32(me+0x2620,r.randrange(2));wf(me+0x261c,r.uniform(0,10))
 matrix=struct.pack('<9f',*[r.uniform(-5,5) for _ in range(9)])
 hook_rec(c,0x4ddcb0,1)
 def rotation(em,res):
  em.calllog.append(('rotation',em.rbytes(em.reg('edx'),12),em.arg32(0)));em.wbytes(em.reg('ecx'),matrix);em.ret(eax=0,argbytes=4)
 e.hook(0x4ddcb0,rotation);hook_rec(c,0x4e0830,0)
 distance=r.uniform(0,10)
 def dist(em,res):em.calllog.append(('distance',em.reg('ecx'),em.reg('edx')));em.ret(eax=0,st0=distance)
 e.hook(0x4e0830,dist);hook_rec(c,0x514890,6,this=True)
 def submit(em,res):
  em.calllog.append(('submit',em.reg('ecx'),em.arg32(0),em.arg32(1),em.rbytes(em.arg32(2),36),em.arg32(3),em.arg32(4)&255,em.arg32(5)&255));em.ret(eax=0,argbytes=24)
 e.hook(0x514890,submit);e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 return [me]
S(0x521ab0,'GUESS tank cannon interpolation and firing','thiscall',None,ret=None,gen=gen)
