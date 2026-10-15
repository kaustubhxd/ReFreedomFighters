from pilot import S
from recruits_util import rnd,clear_hooks,pystub,obj,sysobj

def stand(c):
 clear_hooks(c);e,r=c.emu,c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 vals=[r.uniform(-100,100) for _ in range(12)];centerid=r.getrandbits(32)
 def frame(em,k):
  for i in range(9):em.wf32(em.arg32(0)+4*i,vals[i])
  for i in range(3):em.wf32(em.arg32(1)+4*i,vals[9+i])
 center=obj(c,0x20,{0x80:pystub(c,2,this=True,stackmark=(0,1),side=frame)})
 nest=obj(c,0x20,{0x128:pystub(c,3,this=True,stackmark=(1,),side=lambda em,k:em.w32(em.arg32(1),centerid))})
 sys=sysobj(c,table_slots={0x58:pystub(c,1,this=True,ret=lambda em,k:nest if k==0 else center),0x114:pystub(c,4,this=True,ret=r.getrandbits(32))})
 return [r.getrandbits(32),r.getrandbits(32),rnd(c,12)]
S(0x5520c0,'CFFTools_if::CalcMachineGunStandPosition','stdcall',None,ret=None,gen=stand)
