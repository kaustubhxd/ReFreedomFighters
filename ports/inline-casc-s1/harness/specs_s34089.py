"""specs_s34089.py - six call wrappers; callees are recorders (this recorded); 0x41e290 returns null in a third."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _g64f910(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x63fd80, 1, this=True, ret=r.getrandbits(32))
    me = rnd(c, 0xd0)
    c.emu.wbytes(me + 0xbd, rnd(c, 0x20).to_bytes(4, 'little'))
    return [me]


def _g4d3cd0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4d24e0, 4, this=True, ret=r.getrandbits(32))
    return [rnd(c, 0x40), r.getrandbits(32), r.getrandbits(32)]


def _g4e66a0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x634273, 2, pop=0)
    me = rnd(c, 0x20)
    if r.random() < 0.3:
        c.emu.w32(me + 4, 0)
    return [me]


def _g5f3410(c):
    clear_hooks(c)
    r = c.rng
    blk = rnd(c, 0x20)
    hook_rec(c, 0x41e290, 1, pop=0, ret=lambda em, k: 0 if r.random() < 0.33 else blk)
    hook_rec(c, 0x5f12d0, 0, this=True, pop=0, ret=r.getrandbits(32))
    return [r.getrandbits(32)] if False else []


def _g473fc0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4666d0, 0, this=True, pop=0, ret=lambda em, k: r.choice([0, 1, r.getrandbits(32)]))
    return [rnd(c, 0x300), rnd(c, 0x10)]


def _g537880(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4690b0, 0, this=True, pop=0, ret=r.getrandbits(32))
    me = obj(c, 0x5300, {0x194: pystub(c, 1, ret=r.getrandbits(32), this=True)}, nslots=0x198 // 4)
    c.emu.wbytes(me + 0x52fa, (0 if r.random() < 0.3 else rnd(c, 0x20)).to_bytes(4, 'little'))
    return [me, r.getrandbits(32)]


S(0x64f910, 'GUESS call member then clear flag', 'thiscall', None, ret=None, gen=_g64f910, note='batch34089')
S(0x4d3cd0, 'GUESS forward with constants', 'thiscall', None, ret='eax', gen=_g4d3cd0, note='batch34089')
S(0x4e66a0, 'GUESS release buffer in destructor', 'thiscall', None, ret=None, gen=_g4e66a0, note='batch34089')
S(0x5f3410, 'GUESS allocate and construct', 'cdecl', None, ret='eax', gen=_g5f3410, note='batch34089')
S(0x473fc0, 'GUESS fetch flag and store', 'thiscall', None, ret='al', gen=_g473fc0, note='batch34089')
S(0x537880, 'GUESS release member then slot 0x194', 'thiscall', None, ret='eax', gen=_g537880, note='batch34089')
