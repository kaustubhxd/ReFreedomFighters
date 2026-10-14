"""specs_s34073.py - 0x466400 (unaligned member +0x1ce -> block with +4 object or null, slot 4 tail), 0x4c1e00 (chain +0x44, +8, flags +0x3c; hooked tail target 0x4c3070),
0x4db2a0 (36-byte copy; this and a distinct random blocks, eax = dword +0x20), 0x466340 (hooked 0x462040 with arg, 0x4e1b30 with this)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _g466400(c):
    clear_hooks(c)
    r = c.rng
    me = rnd(c, 0x1e0)
    blk = rnd(c, 0x20)
    inner = 0 if r.random() < 0.3 else obj(c, 0x40, {4: pystub(c, 0, ret=r.getrandbits(32), this=True)}, nslots=2)
    c.emu.w32(blk + 4, inner)
    c.emu.wbytes(me + 0x1ce, blk.to_bytes(4, 'little'))
    return [me]


def _g4c1e00(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4c3070, 0, ret=r.getrandbits(32), this=True, pop=0)
    me = rnd(c, 0x60)
    mid = rnd(c, 0x20)
    leaf = rnd(c, 0x60)
    c.emu.w32(leaf + 0x3c, r.getrandbits(32) if r.random() < 0.5 else (r.getrandbits(32) | 0x400))
    c.emu.w32(mid + 8, leaf)
    c.emu.w32(me + 0x44, mid)
    return [me]


def _g4db2a0(c):
    clear_hooks(c)
    return [rnd(c, 0x40), rnd(c, 0x40)]


def _g466340(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x462040, 1, this=True, stackmark=())
    hook_rec(c, 0x4e1b30, 0, ret=r.getrandbits(32), this=True, pop=0)
    return [rnd(c, 0x40), rnd(c, 0x40)]


S(0x466400, 'GUESS forward through nested member slot 4', 'thiscall', None, ret='eax', gen=_g466400, note='batch34073')
S(0x4c1e00, 'GUESS tail to 0x4c3070 when flag bit 10 clear', 'thiscall', None, ret='eax', gen=_g4c1e00, note='batch34073')
S(0x4db2a0, 'GUESS copy 0x24 bytes into arg', 'thiscall', None, ret='eax', gen=_g4db2a0, note='batch34073')
S(0x466340, 'GUESS two-step call wrapper', 'thiscall', None, ret='eax', gen=_g466340, note='batch34073')
