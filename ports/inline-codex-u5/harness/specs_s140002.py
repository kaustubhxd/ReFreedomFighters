import struct
from pilot import S
from recruits_util import rnd,obj,clear_hooks,pystub,sysobj

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 def floats(a,v):e.wbytes(a,struct.pack('<'+'f'*len(v),*v))
 # Event types distinguish short 3-word event and 7-word sweep event.
 t1=r.randrange(1,32768);t2=r.randrange(32768,65536)
 rec=e.alloc(8*40+4,4)
 def event(em,rr):
  k=em.r32(rec+320);p=rec+40*min(k,7);typ=em.arg32(1);n=3 if typ==t1 else 7
  em.w32(p,em.reg('ecx'));em.w32(p+4,em.arg32(0));em.w32(p+8,typ)
  em.wbytes(p+12,em.rbytes(em.arg32(2),4*n));em.w32(rec+320,k+1)
  em.calllog.append(('event',typ));em.ret(eax=0,argbytes=12)
 me=obj(c,0x300,{0x130:e.stub_fn('vehicle event',event)})
 mode=r.randrange(7)
 origin=[r.uniform(-10,10) for _ in range(3)]
 delta=[r.choice([-2.,-1.,0.,1.,2.]) for _ in range(3)]
 extent=[r.choice([0.,1.,2.,3.]) for _ in range(3)]
 matrix=r.choice([[1.,0,0,0,1.,0,0,0,1.],[0.,1.,0,-1.,0,0,0,0,1.]])
 floats(me+0x26b,matrix);floats(me+0x28f,origin)
 floats(me+0x2b3,[origin[i]+delta[i] for i in range(3)])
 if mode==0:extent=[100.,100.,100.]
 if mode==1:extent=[-1.,-1.,-1.]
 if mode==2:extent[r.randrange(3)]=float('nan')
 floats(me+0x227,extent)
 e.wbytes(me+0x2d4,struct.pack('<H',t1));e.wbytes(me+0x2d2,struct.pack('<H',t2))
 sysobj(c,table_slots={0x4c:pystub(c,1,this=True,ret=r.getrandbits(32))})
 return [me]
S(0x514d80,'GUESS vehicle local bounds event','thiscall',None,ret='al',gen=gen,nan_heap=True)
