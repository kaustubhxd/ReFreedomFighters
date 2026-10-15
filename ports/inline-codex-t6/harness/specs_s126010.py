from pilot import S
from recruits_util import obj,rnd,sysobj,clear_hooks,hook_rec,pystub
import struct,math
from unicorn.x86_const import UC_X86_REG_XMM0,UC_X86_REG_XMM1

def gen(c):
 clear_hooks(c);r=c.rng;e=c.emu
 me=obj(c,0x180,{0x58:pystub(c,0,this=True)});so=sysobj(c)
 def wf(a,v):e.wbytes(a,struct.pack('<f',v))
 e.wbytes(me+0x10f,bytes([r.choice([0,1,1,1])]))
 e.w32(me+0x66,r.choice([0,1,1,5]));e.wbytes(me+0x149,bytes([r.randrange(2)]))
 wf(so+0x48,r.choice([0,-0.1,0.001,0.02,0.05,0.1,1]));wf(me+0xfb,r.uniform(-100,100));wf(me+0xff,r.uniform(-100,100))
 def side(em,k):
  if r.randrange(2):em.wbytes(me+0x10f,b'\x00')
 hook_rec(c,0x53fe30,1,this=True,st0=r.uniform(-50,50),side=side)
 hook_rec(c,0x53e900,0,this=True)
 hook_rec(c,0x634db2,0)
 def power(em,res):
  def read(reg):return struct.unpack('<d',(em.mu.reg_read(reg)&((1<<64)-1)).to_bytes(8,'little'))[0]
  a,b=read(UC_X86_REG_XMM0),read(UC_X86_REG_XMM1);em.calllog.append(('pow',a,b));v=math.pow(a,b)
  em.mu.reg_write(UC_X86_REG_XMM0,int.from_bytes(struct.pack('<d',v),'little'));em.ret()
 e.hook(0x634db2,power);e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 return [me]
S(0x53e970,'GUESS rigidbody active frame decay','thiscall',None,ret=None,gen=gen)
