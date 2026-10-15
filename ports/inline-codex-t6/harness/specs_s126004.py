from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec,pystub
import struct

def gen(c):
 clear_hooks(c);r=c.rng;e=c.emu;me=rnd(c,0x18240);rec=rnd(c,0x40);src=rnd(c,0x60);dest=rnd(c,0x40)
 e.w32(rec+8,src);e.wbytes(src+0x40,r.choice([0,1,15,16,17,255,65535,r.randrange(65536)]).to_bytes(2,'little'))
 for p,n in [(src+8,9),(src+0x2c,3),(me+0x181f9,9),(me+0x1821d,3)]:e.wbytes(p,struct.pack('<'+'f'*n,*[r.uniform(-10,10) for _ in range(n)]))
 hook_rec(c,0x660c00,6)
 def render(em,res):
  em.calllog.append(('packet',em.reg('ecx'),em.reg('edx'),tuple(em.arg32(i) for i in range(4)),em.rbytes(em.arg32(4),36),em.rbytes(em.arg32(5),12)))
  em.w32(em.arg32(3),0x12345678);em.ret(eax=0,argbytes=24)
 e.hook(0x660c00,render)
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 return [me,dest,r.getrandbits(32),r.getrandbits(32),rec,r.getrandbits(32)]
S(0x64a1b0,'GUESS transformed render packet','thiscall',None,ret='eax',gen=gen)
