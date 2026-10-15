from pilot import S
from recruits_util import rnd,clear_hooks,pystub,obj,sysobj,hook_rec

def update(c):
 clear_hooks(c);e,r=c.emu,c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 def exception(em,regs):
  em.calllog.append(('CRT_except1',tuple(em.arg32(i) for i in range(7))))
  em.ret(st0=0.0,argbytes=0)
 e.stub_import('_except1',exception)
 self=e.alloc(0x13300,4);e.wbytes(self,r.randbytes(0x13300))
 for off in (0x103b,0x103c,0x103e,0x103f):e.w8(self+off,r.choice([0,1,255]))
 e.wbytes(self+0x4a,r.choice([b'2R',b'2X',b'XR',b'XX']))
 e.w32(self+0x132c7,r.choice([0,r.getrandbits(32)]))
 e.wf32(self+0x1060,r.choice([0.0,-0.0,-1.0,1.0,128.5,1e20,float('nan'),float('inf'),r.uniform(-100,100)]))
 sys=sysobj(c,table_slots={0xb8:pystub(c,0,this=True)})
 e.w32(sys+0x1907,obj(c,0x20,{0x2c:pystub(c,2,this=True,ret=(r.getrandbits(24)<<8)|r.choice([0,1]))}))
 e.w32(0x7003b8,rnd(c,16))
 osd=rnd(c,0x1d20);e.w32(osd+0x1d0f,rnd(c,16))
 hook_rec(c,0x589c20,1,this=True,ret=osd)
 hook_rec(c,0x59b6d0,0,this=True,ret=r.randrange(10))
 for a in (0x59cc60,0x5ae020,0x59ce00,0x59ce70,0x59cbc0):hook_rec(c,a,0,this=True)
 hook_rec(c,0x5ab020,8,this=True)
 hook_rec(c,0x597fc0,2,this=True)
 hook_rec(c,0x59b120,1,this=True)
 return [self]
S(0x59b1c0,'ZFFLevelController::FrameUpdate','thiscall',None,ret=None,gen=update)
