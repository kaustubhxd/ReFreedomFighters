from pilot import S
from recruits_util import obj,sysobj,clear_hooks,hook_rec,pystub
import struct

def gen(c):
 clear_hooks(c);r=c.rng;e=c.emu;me=obj(c,0x240,{0x378:pystub(c,0,this=True)});so=sysobj(c)
 e.wbytes(so+0x48,struct.pack('<f',r.choice([0,0.016,0.1,1,-0.1])))
 for off in [0x216,0x222]:e.wbytes(me+off,struct.pack('<3f',*[r.uniform(-10,10) for _ in range(3)]))
 hook_rec(c,0x4e0030,0)
 def angle(em,res):
  em.calllog.append(('angle',em.reg('ecx'),em.reg('edx')));em.ret(eax=0,st0=a)
 a=r.uniform(-3,3);e.hook(0x4e0030,angle)
 hook_rec(c,0x4e0130,2)
 vec=r.choice([[0,0,0],[1,0,0],[0,0,-1],[r.uniform(-10,10) for _ in range(3)]])
 def interp(em,res):
  em.calllog.append(('interp',em.reg('ecx'),em.reg('edx'),em.arg32(0),em.arg32(1)))
  em.wbytes(em.reg('ecx'),struct.pack('<3f',*vec));em.ret(eax=0,argbytes=8)
 e.hook(0x4e0130,interp);e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 return [me]
S(0x51da80,'GUESS helicopter direction interpolation','thiscall',None,ret=None,gen=gen)
