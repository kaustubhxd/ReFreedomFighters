from pilot import S
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub

def g(c):
 clear_hooks(c)
 r,e=c.rng,c.emu
 me=rnd(c,0x2300)
 def slotread(slot,size):
  values=[r.randbytes(size) for _ in range(32)]
  def side(em,k):
   p=em.arg32(0);em.calllog.append(('read',slot,p));em.wbytes(p,values[k%32])
  return pystub(c,1,this=True,side=side)
 refs=[r.getrandbits(32) for _ in range(3)];resolved=[r.getrandbits(32) for _ in range(3)]
 def ref(em,k):
  em.calllog.append(('ref',em.r32(em.arg32(0))));em.w32(em.arg32(0),refs[k%3])
 slots={slot:slotread(slot,size) for slot,size in [(0x6c,12),(0x74,36),(0x50,4),(0x48,4),(0x68,1)]}
 slots[0x40]=pystub(c,1,this=True,stackmark=(0,),side=ref)
 stream=obj(c,32,slots)
 sysobj(c,table_slots={0x58:pystub(c,1,this=True,ret=lambda em,k:resolved[k%3])})
 def helper(addr,size):
  values=[r.randbytes(size) for _ in range(16)]
  def side(em,k):
   em.calllog.append(('subrecord',addr,em.reg('ecx'),em.arg32(0)));em.wbytes(em.reg('ecx'),values[k%16])
  hook_rec(c,addr,1,this=True,side=side)
 helper(0x516470,0xde);helper(0x529d70,0x133);helper(0x516d10,0x79)
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 return [me,stream]
S(0x528740,'GUESS load structured record arrays','thiscall',None,ret='al',gen=g,note='batch128022')
