from pilot import S
from recruits_util import rnd,clear_hooks,pystub,hook_rec

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng;e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)));hook_rec(c,0x4e6bf0,1,this=True)
 needle=r.choice([0,r.getrandbits(32)]);tail=0
 for _ in range(r.randrange(6)):
  p=rnd(c,16)
  for i in range(3):e.w32(p+4*i,r.choice([0,needle,r.getrandbits(32)]))
  e.w32(p+12,tail);tail=p
 table=rnd(c,16);idx=r.randrange(4);e.w32(table+4*idx,tail);me=rnd(c,0x30);e.w32(me+0x1d,table);return [me,idx,needle,r.choice([0,1,2,256])]
S(0x49cbb0,'GUESS remove_packed_list_value','thiscall',None,ret='eax',gen=gen)
