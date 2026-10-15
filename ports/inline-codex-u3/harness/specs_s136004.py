import struct
from pilot import S
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 s=rnd(c,0x40);rec=rnd(c,0x50);mat=rnd(c,36);pos=rnd(c,12)
 for p,n in [(rec+0xc,12),(mat,9),(pos,3)]:e.wbytes(p,struct.pack('<'+'f'*n,*(r.uniform(-25,25) for _ in range(n))))
 e.wbytes(rec+0x40,bytes([r.randrange(2)]))
 distance=r.choice([0.0,0.25,1.0,2.0,10.0,16.0,32.0,100.0,1000.0])
 def dist(em,k):em.calllog.append(('distance',em.rbytes(em.reg('ecx'),12),em.rbytes(em.reg('edx'),12)))
 hook_rec(c,0x4e0870,0,this=True,st0=distance,side=dist)
 hook_rec(c,0x44d250,2,this=True,ret=r.choice([rec,rec,rec,0]))
 def blend(em,k):
  old=struct.unpack('<9f',em.rbytes(em.reg('edx'),36));new=struct.unpack('<9f',em.rbytes(em.arg32(0),36));t=struct.unpack('<f',struct.pack('<I',em.arg32(1)))[0]
  em.calllog.append(('blend',old,new,t));em.wbytes(em.reg('ecx'),struct.pack('<9f',*(a+(b-a)*t for a,b in zip(old,new))))
 hook_rec(c,0x4de520,2,this='mark',deref={0:9},side=blend)
 def draw(em,k):em.calllog.append(('draw',em.rbytes(em.arg32(1),36),em.rbytes(em.arg32(2),12)))
 render=obj(c,0x30,{0x30:pystub(c,4,this=True,deref={1:9,2:3},side=draw)})
 hook_rec(c,0x7003b0,0,pop=0,ret=r.getrandbits(32))
 return [s,render,r.choice([0,1,1,2]),mat,pos]
S(0x44d070,'GUESS interpolate render samples and update cache','thiscall',None,ret=None,gen=gen)
