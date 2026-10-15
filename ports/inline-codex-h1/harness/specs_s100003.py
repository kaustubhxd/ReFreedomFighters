from pilot import S,F
from recruits_util import rnd

def g526540(c):
    e=c.emu;r=c.rng
    me=rnd(c,0x1800)
    e.w32(me+0x8c,r.randrange(0,4))
    e.w32(me+0x90,r.randrange(0,4))
    return [me,F(r.uniform(-20.0,20.0))]

S(0x526540,'GUESS initialize repeated coordinate records','thiscall',None,ret=None,gen=g526540,note='batch100003')
