"""specs_s901.py - gap-band slice, batch 901: 0x41eee0 (ZSysMem::NewWithRef, thiscall, one stack arg (n), ret 4, returns a pointer).
Stand-ins: the CRT malloc import (stub_import 'malloc', cdecl: logs its size, returns a fresh block drawn at generation time), and
0x4d0700 (thiscall, ECX = this+0x31, one argument, ret 4; logs its size, returns a fresh block). The block headers are compared in the
heap. Both branches (this+0x30 zero and nonzero) run."""
from pilot import S
from anim_common import only_hooks, rnd


def _gen(c):
    e, r = c.emu, c.rng
    blk_malloc = rnd(c, 0x200)
    blk_4d07 = rnd(c, 0x200)

    def malloc(e, rr):
        e.calllog.append(('malloc', e.arg32(0)))
        e.ret(eax=blk_malloc, argbytes=0)          # cdecl: the caller pops the size

    def h_4d07(e, rr):
        e.calllog.append(('h.4d0700', e.reg('ecx') != 0, e.arg32(0)))
        e.ret(eax=blk_4d07, argbytes=4)

    only_hooks(c, {0x4d0700: h_4d07})
    e.stub_import('malloc', malloc)
    self = rnd(c, 0x100)
    e.w8(self + 0x30, r.choice([0, 1, 0x80, r.getrandbits(8)]))
    e.w32(self + 0x31, rnd(c, 0x20))
    n = r.choice([0, 1, 0x10, 0x100, r.getrandbits(20)])
    return [self, n]


S(0x41eee0, 'ZSysMem::NewWithRef(unsigned int) (named)', 'thiscall', None, ret='eax', gen=_gen, note='area50 batch901 (band slice)')
