"""specs_s1708.py - residue 13 batch 1708: four functions. 0x498700 is hooked (no arguments). The argument objects have slots
0x68 and 0x50 (one argument each, recorded, random eax); the byte pointer is a heap block."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks, hook


def _gen_493(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    hook(c, seq, 0x498700, 0, ret=0, this=True, pop=True)
    me = rnd(c, 0x1000)
    c.emu.w8(me + 0xbc2, r.choice([0, 0, 1]))
    c.emu.w32(me + 8, r.choice([0, rnd(c, 0x40)]))
    return [me]


def _gen_obj(slot):
    def gen(c):
        seq = Seq(c)
        r = c.rng
        clear_hooks(c)
        o = obj(c, 0x40, {slot: stub(c, seq, 1, ret=r.getrandbits(32))})
        me = rnd(c, 0x100)
        c.emu.w32(me + 4, r.getrandbits(32))
        return [me, o]
    return gen


def _gen_645(c):
    r = c.rng
    clear_hooks(c)
    me = rnd(c, 0x300)
    c.emu.w8(me + 0x266, r.choice([0, 1, 0x80]))
    c.emu.w8(me + 0x267, r.getrandbits(8))
    return [me, rnd(c, 0x10)]


S(0x493110, 'GUESS FUN_493110', 'thiscall', None, ret=None, gen=_gen_493, note='batch1708; tail to 0x498700 (hooked)')
S(0x4c59d0, 'GUESS FUN_4c59d0', 'thiscall', None, ret='eax', gen=_gen_obj(0x68), note='batch1708; slot 0x68; returns with low byte 1')
S(0x4cbdd0, 'GUESS FUN_4cbdd0', 'thiscall', None, ret='eax', gen=_gen_obj(0x50), note='batch1708; slot 0x50; returns with low byte 1')
S(0x645c10, 'GUESS FUN_645c10', 'thiscall', None, ret=None, gen=_gen_645, note='batch1708; byte copy under a flag')
