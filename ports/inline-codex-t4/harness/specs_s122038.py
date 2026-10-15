from pilot import S
from specs_s122027 import gen as basegen

def gen(c):
 s,stream=basegen(c)
 return [s,c.rng.getrandbits(32),stream]
S(0x4bd040,'GUESS initialize clamped float state','thiscall',None,ret=None,gen=gen,nan_heap=True)
