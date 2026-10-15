from pilot import S
from recruits_util import rnd,clear_hooks,pystub,obj,sysobj,hook_rec

def ray(c):
 clear_hooks(c);e,r=c.emu,c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 vals=[r.uniform(-20,20) for _ in range(12)]
 def frame(em,k):
  for i in range(9):em.wf32(em.arg32(0)+4*i,vals[i])
  for i in range(3):em.wf32(em.arg32(1)+4*i,vals[9+i])
 owner=obj(c,0x20,{0x80:pystub(c,2,this=True,stackmark=(0,1),side=frame)})
 self=rnd(c,0x30);e.w32(self+0x14,owner)
 inp=rnd(c,16);out=rnd(c,16);cells=[rnd(c,8) for _ in range(4)]
 for p in cells[:3]:e.wf32(p,r.uniform(-20,20))
 def cell(em,k):return cells[3] if em.reg('ecx')==out else cells[em.arg32(0)]
 hook_rec(c,0x5003d0,1,this=True,ret=cell)
 hook_rec(c,0x5002f0,1,this=True,side=lambda em,k:em.w32(em.reg('ecx'),em.arg32(0)))
 def capture(em,k):
  p=em.arg32(0);em.calllog.append(('ray_fields',tuple(em.r32(p+i) for i in (0,4,8,12,16,20,0x34,0x44)),em.r8(p+0x6c)))
 phys=obj(c,0x20,{0x2e0:pystub(c,6,this=True,stackmark=(0,),side=capture,ret=r.getrandbits(32))})
 sys=sysobj(c,table_size=0xb00);e.w32(e.r32(sys+0x9b)+0xadc,phys)
 args=rnd(c,16);e.w32(args+4,inp);e.w32(args+8,out)
 return [self,args]
S(0x504e70,'GUESS_script_ray_test','thiscall',None,ret=None,gen=ray)
