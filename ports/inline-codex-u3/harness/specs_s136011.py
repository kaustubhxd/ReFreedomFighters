import struct
from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec

def gen(c):
 clear_hooks(c);r=c.rng;e=c.emu
 s=rnd(c,0x160);group=rnd(c,0x20);geo=rnd(c,0x60);e.w32(s+0x44,group);e.w32(group+8,geo)
 e.wbytes(geo+0x40,struct.pack('<3f',*(r.uniform(-10,20) for _ in range(3))))
 target=rnd(c,0x50);arg=rnd(c,4);e.w32(arg,target)
 v=r.choice([[0.,0.,0.],[1.,0.,0.],[0.,-1.,0.],[r.uniform(-50,50) for _ in range(3)]])
 e.wbytes(target+0xc,struct.pack('<3f',*v));e.wbytes(0x6ec390,struct.pack('<f',r.choice([0.,1.,-1.,r.uniform(-30,30)])))
 hook_rec(c,0x53f230,2,this=True,deref={1:3})
 def finish(em,k):em.calllog.append(('state',em.rbytes(s+0xf7,0x1a),em.r32(s+0x13d)))
 hook_rec(c,0x634e90,1,this=True,side=finish)
 hook_rec(c,0x7003b0,0,pop=0,ret=r.getrandbits(32))
 return [s,arg]
S(0x53f0e0,'GUESS initialize rigid body directed impulse','thiscall',None,ret=None,gen=gen)
