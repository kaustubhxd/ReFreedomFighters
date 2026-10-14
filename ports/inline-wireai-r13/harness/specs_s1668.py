"""specs_s1668.py - residue 13 batch 1668: 0x4762a0 (no stack arguments). The system tick count (sys+0x40) gates the call,
and +0x52 is set equal to, one below, or one above it; the mode word at +0x4e picks the path; the object at +0x44 records
its slots 0x210, 0x28, 0x1e0 (random eax), and the tail target ZAllocMany::Free (0x476bd0) is hooked with random eax."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks, hook, sysobj


def _gen(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    sys_ = sysobj(c, t=r.randint(0, 1 << 22))
    tick = c.emu.r32(sys_ + 0x40)
    hook(c, seq, 0x476bd0, 0, ret=r.getrandbits(32), this=True, pop=True)
    o = obj(c, 0x100, {0x210: stub(c, seq, 1), 0x28: stub(c, seq, 0), 0x1e0: stub(c, seq, 1, ret=r.choice([r.getrandbits(32) & ~0xff, r.getrandbits(32)]))})
    me = obj(c, 0x100, {0x68: stub(c, seq, 2)})
    mode = r.choice([0, 1, 2, r.getrandbits(32)])
    c.emu.w32(me + 0x44, o if (mode == 0 or r.random() < 0.9) else 0)   # the main path dereferences +0x44 (no null case there)
    c.emu.w32(me + 0x52, r.choice([tick, tick - 1, tick + 1, r.randint(0, 1 << 22), r.getrandbits(32)]))
    c.emu.w32(me + 0x4e, mode)
    return [me]


S(0x4762a0, 'GUESS FUN_4762a0', 'thiscall', None, ret='eax', gen=_gen,
  note='batch1668; no stack args; tail to 0x476bd0 hooked; eax modelled on every path')
