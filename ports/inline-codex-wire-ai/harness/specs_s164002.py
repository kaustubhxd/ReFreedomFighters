from pilot import S
from ai_kit import _rnd

def _team(c):
 a=_rnd(c,0x40)
 c.emu.w32(a+4,c.rng.choice([0,1,2,3,4,5,6,7,8,9,0xffffffff,c.rng.getrandbits(32)]))
 c.emu.w32(a+8,c.rng.choice([0,1,2,3,4]))
 return a

def _set(c): return [_team(c), c.rng.choice([0,1,2,3,4,5,6,7,8,9,0xffffffff,c.rng.getrandbits(32)])]
def _mask(c): return [_team(c)]
S(0x59d430,'GameEntity::SetEntityTeam','thiscall',None,ret=None,gen=_set,note='child0x59d450 runs original, separately verified without stubs')
S(0x59d450,'GameEntity::SetMasks','thiscall',None,ret=None,gen=_mask,note='pure full-heap output comparison; no callees')
