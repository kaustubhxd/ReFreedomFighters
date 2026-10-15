"""HealthSet: complete self heap compared; exact heap receiver + scalar args logged for sprite setters.
Color dependency executes original strict 0x5a5d00, not a random return hook. No pointer/out masks.
"""
from pilot import S
import struct

def bits(x): return struct.unpack('<I',struct.pack('<f',x))[0]
def gen(c):
 e=c.emu;r=c.rng
 me=e.alloc(0x670,4);e.wbytes(me,bytes(r.getrandbits(8) for _ in range(0x670)))
 sprite=e.alloc(0x40,4);e.wbytes(sprite,bytes(r.getrandbits(8) for _ in range(0x40)))
 e.w32(me+0x434,sprite)
 cur=r.choice([0.,1.,.5,-1.,r.random()]);cur_bits=r.choice([bits(cur),0x7fc00000,r.getrandbits(32)]);e.w32(me+0x2fc,cur_bits);e.w8(me+0x658,r.choice([0,1,255]))
 x=r.choice([cur,0.,-0.,1.,.5,.25,.001,1.5,-3.,.999,.375,1/55,1/119,r.uniform(-1,2)])
 def setter(addr):
  def hook(em,res):
   em.calllog.append((addr,em.reg('ecx'),em.arg32(0),em.arg32(1)))
   em.ret(eax=0,argbytes=8)
  e.hook(addr,hook)
 setter(0x5ec090);setter(0x5ec340)
 return [me,r.choice([bits(x),cur_bits,0x7fc00000,0x7f800000,0xff800000,r.getrandbits(32)])]
S(0x5a83e0,'ZOnScreenDisplay::HealthSet','thiscall',None,ret=None,gen=gen,reg_values=True,note='Exact sprite receiver pointers; strict original color callee; full self and sprite heap comparison')
