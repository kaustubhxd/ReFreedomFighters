from pilot import S
from pe_emu import STACK_TOP
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub
import struct

def g(c):
 clear_hooks(c);r=c.rng;e=c.emu;e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 hook_rec(c,0x633654,0,pop=0,ret=lambda em,k:em.reg('eax'))
 frame=STACK_TOP-0x210
 e.w32(frame,STACK_TOP-0x80);e.w32(frame+4,e.RET_ADDR);e.w32(frame-4,e.r32(0x6f5630)^frame)
 inp=rnd(c,12);e.wbytes(inp,struct.pack('<3f',*[r.uniform(-100,100) for _ in range(3)]));e.w32(frame+8,inp)
 def vecout(em,k):em.wbytes(em.arg32(0),struct.pack('<3f',*[r.uniform(-100,100) for _ in range(3)]))
 source=obj(c,16,{0x8c:pystub(c,1,this=True,deref={0:3},side=vecout)})
 records=[]
 for i in range(4):
  o=obj(c,0x10,{0x2d4:pystub(c,2,this=True,deref={0:9,1:3}),0x6c:pystub(c,1,this=True,deref={0:9})})
  data=rnd(c,0x30);e.wbytes(data+0x24,struct.pack('<3f',*[r.uniform(-100,100) for _ in range(3)]));e.w32(o+8,data);records.append(o)
 table=obj(c,16,{0x58:pystub(c,1,this=True,ret=lambda em,k:records[em.arg32(0)-101])})
 sys=rnd(c,0xb0);e.w32(0x70039c,sys);e.w32(sys+0x9b,table)
 me=rnd(c,0x90);e.w32(me+0x44,source)
 for off,i in zip([0x74,0x78,0x70,0x6c],[101,102,103,r.choice([0,104])]):e.w32(me+off,i)
 hook_rec(c,0x5c88c0,2,this=True,deref={0:3},ret=r.choice([0,1,2,0x100,0x101]))
 matrix=[r.uniform(-2,2) for _ in range(9)]
 def mkmat(em,k):
  em.calllog.append(('matrix-input',tuple(em.r32(em.reg('edx')+4*i) for i in range(3))))
  em.wbytes(em.reg('ecx'),struct.pack('<9f',*matrix))
 hook_rec(c,0x4de040,1,this=True,side=mkmat)
 def transform(em,k):
  em.calllog.append(('transform-input',tuple(em.r32(em.reg('ecx')+4*i) for i in range(3)),tuple(em.r32(em.reg('edx')+4*i) for i in range(9))))
  em.wbytes(em.reg('ecx'),struct.pack('<3f',*[r.uniform(-10,10) for _ in range(3)]))
 hook_rec(c,0x4419f0,0,this=True,side=transform)
 def normalize(em,k):
  em.calllog.append(('normalize-input',tuple(em.r32(em.reg('ecx')+4*i) for i in range(3))))
  em.wbytes(em.reg('ecx'),struct.pack('<3f',*[r.uniform(-1,1) for _ in range(3)]))
 hook_rec(c,0x4e09b0,0,this=True,side=normalize)
 words=[r.getrandbits(32) for _ in range(128)]
 words[123]=e.r32(0x6f5630)^frame;words[124]=STACK_TOP-0x80;words[125]=e.RET_ADDR;words[126]=inp
 return [me,frame,frame-0x88,inp,frame-0x34]+words
S(0x5c82b9,'GUESS split body aim mounted weapon',('regs',['ecx','ebp','esp','eax','edx']+['s']*128),None,ret='al',gen=g,note='batch124026; split body entry from prologue 0x5c82a0')
