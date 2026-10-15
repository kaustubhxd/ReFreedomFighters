from pilot import S
from recruits_util import clear_hooks,rnd,obj,pystub,hook_rec,sysobj

def gen(c):
 clear_hooks(c)
 e,r=c.emu,c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 hook_rec(c,0x467410,6,this=True)
 sysobj(c,table_slots={0x4c:pystub(c,1,this=True,ret=r.getrandbits(32))})
 def item():return obj(c,0x40,{0x2d0:pystub(c,2,this=True)})
 new=r.choice([0,item(),item()]);cur=r.choice([0,item(),new])
 t=obj(c,0x600,{0x514:pystub(c,0,this=True,ret=r.choice([0,1,2,3])),0x524:pystub(c,1,this=True),0x46c:pystub(c,1,this=True)})
 vt=e.alloc(0x20,4);e.w32(vt+0x10,pystub(c,0,this=True,ret=cur));e.w32(vt+8,pystub(c,2,this=True));e.w32(t+0x34f,vt)
 left=r.choice([0,item(),new]);vt2=e.alloc(0x20,4);e.w32(vt2+0x10,pystub(c,0,this=True,ret=left));e.w32(vt2+8,pystub(c,2,this=True));e.w32(t+0x2e7,vt2)
 return [t,new,r.choice([0,1,0x100,0x101,0xffffffff])]
S(0x473b70,'ZLNKWHANDS ForceLHandItem','thiscall',None,ret=None,gen=gen)
