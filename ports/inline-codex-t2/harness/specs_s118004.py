from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub,logger
import struct

def start(c):clear_hooks(c);c.emu.w32(0x7003b0,pystub(c,0,ret=c.rng.getrandbits(32)))
def remove(c):
 start(c);r=c.rng;e=c.emu;s=rnd(c,0xc00);n=r.randrange(8);follower=rnd(c,0x20);e.w32(follower+4,r.choice([0,rnd(c,0x10)]));e.w32(s+0xa16,n)
 for i in range(n):e.w32(s+0xa1a+48*i,r.choice([follower,rnd(c,0x20)]))
 logger(c,nargs=3);hook_rec(c,0x5a2860,0,this=True)
 return [s,follower]
S(0x594460,'GUESS_remove_follower','thiscall',None,ret=None,gen=remove)

def ramp(c):
 start(c);r=c.rng;e=c.emu
 s=obj(c,0x80,{0x68:pystub(c,2,this=True)})
 sub=rnd(c,0x30);channel=rnd(c,0x100);e.w32(sub+0x18,channel);e.w32(s+0x44,sub)
 sys=sysobj(c);e.w32(sys+0x40,r.choice([0,1,1024,10000,100000,0x7fffffff,0x80000000]));e.wbytes(sys+0x48,struct.pack('<f',r.choice([0.001,0.016,1.,10.])))
 e.w8(s+0x4c,r.choice([0,1,1,1]));e.w8(s+0x4d,r.randrange(2))
 for off in (0x4e,0x52,0x56,0x5a,0x5e,0x62):e.wbytes(s+off,struct.pack('<f',r.choice([0.,-0.,-1.,1.,10.,100.,r.uniform(-100,100)])))
 e.wbytes(channel+0x84,struct.pack('<f',r.uniform(0.1,100)))
 # Vectorcall CRT hooks capture both XMM arguments into compared heap records.
 rec1=e.alloc(8);rec2=e.alloc(16)
 def one(em,regs):
  x=em.reg('xmm0')&((1<<64)-1);em.wbytes(rec1,struct.pack('<Q',x));v=struct.unpack('<d',struct.pack('<Q',x))[0]
  em.mu.reg_write(__import__('unicorn.x86_const',fromlist=['UC_X86_REG_XMM0']).UC_X86_REG_XMM0,int.from_bytes(struct.pack('<d',v*0.125),'little'));em.ret()
 def two(em,regs):
  x=em.reg('xmm0')&((1<<64)-1);y=em.reg('xmm1')&((1<<64)-1);em.wbytes(rec2,struct.pack('<QQ',x,y))
  em.mu.reg_write(__import__('unicorn.x86_const',fromlist=['UC_X86_REG_XMM0']).UC_X86_REG_XMM0,int.from_bytes(struct.pack('<d',0.625),'little'));em.ret()
 from recruits_util import _HOOKED
 e.hook(0x634dd6,one);_HOOKED.add(0x634dd6);e.hook(0x634db2,two);_HOOKED.add(0x634db2)
 return [s]
S(0x4c0010,'GUESS_volume_ramp','thiscall',None,ret=None,gen=ramp,nan_heap=True)

def unpack(c):
 start(c);r=c.rng;e=c.emu;logger(c,nargs=3)
 args=rnd(c,0x10);inp=rnd(c,0x20);out=rnd(c,0x20);e.w32(args+4,inp);e.w32(args+8,out)
 key=rnd(c,8);rec=rnd(c,20);nodes=[rnd(c,8) for _ in range(5)]
 for p in nodes:e.w8(p+4,r.choice([0,1,2,3,255]))
 hook_rec(c,0x5003d0,1,this=True,ret=lambda em,k:key if em.reg('ecx')==inp else nodes[em.arg32(0)%5])
 mgr=rnd(c,0x2c40);e.w32(0x7003b8,mgr);e.w32(mgr+0x2c21,rnd(c,0x20))
 hook_rec(c,0x5a46f0,1,this=True,ret=rec)
 def write(em,k):em.w32(em.reg('ecx'),em.arg32(0));em.w8(em.reg('ecx')+4,1)
 hook_rec(c,0x5002f0,1,this=True,side=write)
 return [args]
S(0x55fd40,'GUESS_unpack_record','stdcall',None,ret=None,gen=unpack)
