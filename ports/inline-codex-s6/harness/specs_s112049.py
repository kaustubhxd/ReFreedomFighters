from pilot import S
from recruits_util import rnd,obj,clear_hooks,pystub,logger

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)));logger(c,3)
 mgr=rnd(c,0x100);n=r.randrange(0,9);e.w32(mgr+4,n);e.w32(0x7003b8,mgr)
 for i in range(n):
  actor=obj(c,0x60,{0x438:pystub(c,0,this=True,ret=r.choice([0,1,255,256]))});team=rnd(c,16);e.w32(team+4,r.choice([0,1,2]));e.w32(actor+0x54,team if r.randrange(3) else 0);e.w32(mgr+8+4*i,actor)
 values=rnd(c,8*8)
 for i in range(8):e.wbytes(values+8*i+4,bytes([r.choice([0,1,2,255])]))
 header=rnd(c,12);e.w32(header,values);e.w32(header+8,r.randrange(0,9));out=rnd(c,12);e.w32(out,header);e.w32(out+4,r.randrange(0,5));e.w32(out+8,r.randrange(2));args=rnd(c,16);e.w32(args+8,out)
 return [rnd(c,16),args]
S(0x554d40,'GUESS count_active_team_one','thiscall',None,ret=None,gen=gen)
