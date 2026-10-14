"""specs_s1656.py - residue 13 batch 1656: 0x476350 and 0x476a20 (both: this, obj with one stack argument). The object
obj records its slot calls (0x54, 0x60, 0x1e0; returns a random value for 0x1e0); ZGROUP::CopyData (0x43f8c0) is hooked."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks, hook


def _gen_obj(c, seq, r):
    o = obj(c, 0x100, {0x54: stub(c, seq, 1), 0x60: stub(c, seq, 1), 0x1e0: stub(c, seq, 1, ret=r.getrandbits(32))})
    return o


def _gen350(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    me = rnd(c, 0x100)
    o = _gen_obj(c, seq, r)
    return [me, o]


def _gen_a20(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    hook(c, seq, 0x43f8c0, 1, ret=0, this=True, pop=True)
    me = rnd(c, 0x100)
    o = _gen_obj(c, seq, r)
    return [me, o]


S(0x476350, 'GUESS FUN_476350', 'thiscall', None, ret='al', gen=_gen350, note='batch1656; ret 4')
S(0x476a20, 'GUESS FUN_476a20', 'thiscall', None, ret='eax', gen=_gen_a20, note='batch1656; ZGROUP::CopyData hooked; ret 4')
