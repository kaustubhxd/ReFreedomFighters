"""specs_s911.py - residue-9 slice, batch 911: 0x626e10 (cdecl UTF-8 encoder: value, output pointer; returns the byte count) and
0x4bb350 (thiscall, no args, returns this; base constructor 0x469870 stood in, logs its ECX). Values are drawn across all the
encoder's boundaries (negative, 0x7f/0x80, 0x7ff/0x800, 0xffff/0x10000, 0x10ffff/0x110000)."""
from pilot import S
from anim_common import only_hooks, rnd


def _gen_utf(c):
    e, r = c.emu, c.rng
    v = r.choice([-1, 0, 0x7f, 0x80, 0x7ff, 0x800, 0xffff, 0x10000, 0x10ffff, 0x110000, 0x1234, r.randint(-5, 0x120000)])
    out = rnd(c, 0x8)
    return [v & 0xffffffff, out]


def _gen_init(c):
    e, r = c.emu, c.rng

    def h469(e, rr):
        e.calllog.append(('base.469870', e.reg('ecx') != 0))
        e.ret(eax=0, argbytes=0)

    only_hooks(c, {0x469870: h469})
    self = rnd(c, 0x80)
    e.w32(self + 4, r.getrandbits(32))
    e.w32(self + 0x44, r.getrandbits(32))
    return [self]


S(0x626e10, 'utf8 encoder (no name in map)', 'cdecl', None, ret='eax', gen=_gen_utf, note='area50 batch911 (residue-9 slice)')
S(0x4bb350, 'init (no name in map)', 'thiscall', None, ret='eax', gen=_gen_init, note='area50 batch911 (residue-9 slice)')
