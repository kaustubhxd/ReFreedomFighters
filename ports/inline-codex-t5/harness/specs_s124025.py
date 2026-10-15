from pilot import S
from pe_emu import STACK_TOP
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub
import struct

def g(c):
 clear_hooks(c);r=c.rng;e=c.emu;e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 hook_rec(c,0x633654,0,pop=0,ret=lambda em,k:em.reg('eax'))
 frame=STACK_TOP-0x210
 e.w32(frame,STACK_TOP-0x80);e.w32(frame+4,e.RET_ADDR);e.w32(frame-4,e.r32(0x6f5630)^frame)
 box=rnd(c,0x30);e.w32(frame+8,box)
 for off in [0x11,0x15,0x19,0x21,0x25]:e.wbytes(box+off,struct.pack('<f',r.choice([-10.,-1.,0.,1.,10.,r.uniform(-100,100)])))
 vals=[r.uniform(-2,2) for _ in range(3)]
 def geometry(em,k):
  em.wbytes(em.arg32(0),struct.pack('<3f',*vals))
  em.wbytes(em.arg32(1),struct.pack('<9f',*[r.uniform(-2,2) for _ in range(9)]))
 geom=obj(c,16,{0x80:pystub(c,2,this=True,stackmark=[0,1],side=geometry)})
 actor=rnd(c,0x50);e.w32(actor+0x44,geom)
 context=rnd(c,16);hook_rec(c,0x591ae0,0,this=True,ret=actor)
 def rotate(em,k):
  em.calllog.append(('rotate',tuple(em.r32(em.reg('ecx')+4*i) for i in range(3)),tuple(em.r32(em.reg('edx')+4*i) for i in range(3))))
  em.wbytes(em.reg('ecx'),struct.pack('<3f',*(r.choice([[1.,0.,1.],[-1.,0.,1.],[0.,0.,1.],[1.,0.,0.]]) )))
 hook_rec(c,0x4e0be0,0,this=True,side=rotate)
 words=[r.getrandbits(32) for _ in range(128)]
 words[123]=e.r32(0x6f5630)^frame;words[124]=STACK_TOP-0x80;words[125]=e.RET_ADDR;words[126]=box
 return [context,frame,frame-0x84]+words
S(0x5be83f,'GUESS split body box camera wedge test',('regs',['ecx','ebp','esp']+['s']*128),None,ret='al',gen=g,note='batch124025; split body entry from prologue 0x5be810',tries=3)
