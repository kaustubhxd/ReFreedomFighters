from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub

def gen(c):
 clear_hooks(c); e=c.emu;r=c.rng
 eng=sysobj(c); tick=r.getrandbits(32);e.w32(eng+0x40,tick)
 e.wf32(eng+0x48,r.choice([0.,1.,-1.,r.uniform(-50,50)]))
 def logmat(em,k):em.calllog.append(('matrix',em.rbytes(em.arg32(0),36)))
 child=obj(c,0x20,{0x6c:pystub(c,1,this=True,stackmark=(0,),side=logmat)})
 e.w32(child+8,rnd(c,0x20))
 me=obj(c,0x80,{0x68:pystub(c,2,this=True),0x84:pystub(c,1,this=True,stackmark=(0,),side=logmat)})
 e.w32(me+0x44,child);e.w8(me+0x58,r.randrange(2));e.w8(me+0x59,r.randrange(2))
 dt=r.choice([0,1023,1024,1025,2047,2048,2049,-1,0x7fffffff,-0x80000000,r.getrandbits(32)])
 e.w32(me+0x5b,(tick-dt)&0xffffffff)
 def scale(em,k):
  src=em.reg('edx');em.calllog.append(('scale',src,em.rbytes(src,12)))
  em.wbytes(em.reg('ecx'),bytes(r.getrandbits(8) for _ in range(12)))
 def matrix(em,k):em.wbytes(em.arg32(0),bytes(r.getrandbits(8) for _ in range(36)))
 def apply(em,k):
  em.calllog.append(('apply',em.rbytes(em.reg('ecx'),36),em.rbytes(em.reg('edx'),12)))
  em.wbytes(em.reg('ecx'),bytes(r.getrandbits(8) for _ in range(36)))
 hook_rec(c,0x4e0d40,1,this='mark',pop=4,side=scale)
 hook_rec(c,0x4db2a0,1,this=True,pop=4,stackmark=(0,),side=matrix)
 hook_rec(c,0x4de7e0,0,this='mark',pop=0,side=apply)
 hook_rec(c,0x633654,0,pop=0)
 return [me]
S(0x4c95a0,'GUESS timed flags and transformed motion matrix','thiscall',None,ret=None,gen=gen,note='batch34169')
