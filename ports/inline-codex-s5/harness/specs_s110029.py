from pilot import S
from recruits_util import clear_hooks,rnd,obj,pystub

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 sys=rnd(c,0x50);e.w32(0x70039c,sys)
 anims=[rnd(c,0x80),rnd(c,0x80)];choice=r.choice([0,anims[0]]);w=r.uniform(-1,2)
 def pick(em,n):em.w32(em.arg32(0),choice)
 ctl=obj(c,0x40,{0x24:pystub(c,5,this=True,nullflag=(0,),side=pick,st0=w),0x30:pystub(c,1,this=True,st0=r.uniform(-1,2)),0x28:pystub(c,0,this=True,ret=r.choice([0,1,256,257]))})
 t=obj(c,0x700,{0x324:pystub(c,1,this=True,ret=r.choice([0,1,256,257])),0x320:pystub(c,1,this=True,ret=r.getrandbits(32)),0x268:pystub(c,2,this=True),0x244:pystub(c,5,this=True),0x5f8:pystub(c,1,this=True),0x3e0:pystub(c,0,this=True)})
 e.w32(t+0x455,ctl);e.w32(t+0x6c,rnd(c,0x260));e.wf32(t+0x612,r.choice([w,r.uniform(-1,2)]));e.w32(t+0x424,r.choice([0,*anims]));e.w32(t+0x417,r.choice([0,0,0x40000]))
 args=[t]
 for i in range(4):
  p=rnd(c,0x30)
  for j in range(9):e.wf32(p+4*j,r.uniform(-2,2))
  args.append(p)
 return args
S(0x481570,'ZPlayer CalcBonesFromMotion','thiscall',None,ret=None,gen=gen)
