from pilot import S
from recruits_util import rnd,obj,pystub,clear_hooks

def gen(c):
 clear_hooks(c);me=rnd(c,0x80)
 stream=obj(c,16,{i:pystub(c,1,this=True) for i in [0x40,0x44,0x4c,0x60]})
 return [me,stream]
S(0x4c27c0,'GUESS serialize packed properties and clear dirty flag','thiscall',None,ret='al',gen=gen)
