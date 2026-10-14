"""specs_s34091.py - six call wrappers; callees are recorders (this recorded)."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec
from unicorn.x86_const import UC_X86_REG_ECX


def _g4c31b0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4c3740, 1, this=True, ret=r.getrandbits(32))
    me = rnd(c, 0x60)
    c.emu.w32(me + 0x44, rnd(c, 0x20))
    return [me, r.choice([0x401, 0x401, 0x400, 0x10401, 0x402, r.getrandbits(32)]), r.getrandbits(32)]


def _g628e70(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x628c80, 6, pop=0, ret=r.getrandbits(32))
    return [r.getrandbits(32), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


def _g451a00(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x634273, 2, pop=0, side=lambda em, k: em.mu.reg_write(UC_X86_REG_ECX, r.getrandbits(32)))
    hook_rec(c, 0x43de70, 0, this=True, pop=0, ret=r.getrandbits(32))
    me = rnd(c, 0x50)
    if r.random() < 0.3:
        c.emu.w32(me + 0x3c, 0)
    return [me]


def _g55ffb0(c):
    clear_hooks(c)
    r = c.rng
    cell = rnd(c, 0x10)
    c.emu.w32(cell, r.choice([0, 0, 1, r.getrandbits(32)]))
    hook_rec(c, 0x5003d0, 1, this=True, ret=cell)
    so = rnd(c, 0x2c30)
    c.emu.wbytes(so + 0x2c21, rnd(c, 0x80).to_bytes(4, 'little'))
    c.emu.w32(0x7003b8, so)
    return [rnd(c, 0x20)]


def _g626d70(c):
    clear_hooks(c)
    r = c.rng
    blk = rnd(c, 0x90)
    hook_rec(c, 0x626b00, 4, pop=0, ret=lambda em, k: 0 if r.random() < 0.3 else blk)
    return [r.getrandbits(32), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


def _g51e910(c):
    clear_hooks(c)
    r = c.rng
    cell = rnd(c, 0x10)
    hook_rec(c, 0x5003d0, 1, this=True, ret=cell)
    me = rnd(c, 0x30)
    c.emu.w32(me + 0x18, rnd(c, 0x280))
    return [me, rnd(c, 0x20)]


S(0x4c31b0, 'GUESS forward on message 0x401', 'thiscall', None, ret='eax', gen=_g4c31b0, note='batch34091')
S(0x628e70, 'GUESS forward with constants', 'cdecl', None, ret='eax', gen=_g628e70, note='batch34091')
S(0x451a00, 'GUESS release buffer then tail', 'thiscall', None, ret='eax', gen=_g451a00, note='batch34091')
S(0x55ffb0, 'GUESS store flag in engine object', 'stdcall', None, ret='eax', gen=_g55ffb0, note='batch34091')
S(0x626d70, 'GUESS call then tag result', 'cdecl', None, ret='eax', gen=_g626d70, note='batch34091')
S(0x51e910, 'GUESS copy cell value', 'thiscall', None, ret='eax', gen=_g51e910, note='batch34091')
