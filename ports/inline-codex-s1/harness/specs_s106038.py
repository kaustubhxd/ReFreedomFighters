import struct,math
from pilot import S,EDGE_F
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub

def gen(c):
 clear_hooks(c);r=c.rng;e=c.emu
 me=rnd(c,0xa0);count=r.randrange(6)
 target=obj(c,16,{0x14:pystub(c,0,this=True,ret=count),0x30:pystub(c,1,this=True,ret=lambda em,k:0x100+k)})
 e.w32(me+0x6d,r.choice([target,target,target,0]));e.w32(me+0x89,r.choice([0,1,255,0x7fffffff,0x80000000,0xffffff00,r.getrandbits(32)]))
 e.wf32(me+0x79,r.choice([0.,.5,1.,-1.,r.uniform(-10,10)]))
 records=[]
 for i in range(max(count,1)):
  p=rnd(c,0x30);e.wf32(p+0x20,r.choice(EDGE_F+[r.uniform(-100,100)]));records.append(r.choice([0,p,p]))
 sysobj(c,table_slots={0x58:pystub(c,1,this=True,ret=lambda em,k:records[k%len(records)])})
 def cvt(em,k):
  bits=em.reg('xmm0')&0xffffffff;em.calllog.append(('convert',bits));x=struct.unpack('<f',struct.pack('<I',bits))[0]
  return (int(round(x))&0xffffffff) if math.isfinite(x) else 0
 hook_rec(c,0x633910,0,ret=cvt);e.w32(0x7003b0,pystub(c,0))
 return [me,r.getrandbits(32)]
S(0x4c1f80,'update scaled counter and return shifted value',('regs',['ecx','eax']),None,ret='eax',gen=gen,nan_heap=True)
