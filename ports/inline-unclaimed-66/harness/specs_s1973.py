"""specs_s1973.py - slice-5 batches 104 and 105 (GUESS names).
0x427d90: the import pointer at 0x676068 is a stub (STDCALL, seven arguments, callee cleans); it logs them and returns a value chosen per case
(sometimes -1). 0x43e810: this's vtable +0x74 (two arguments, callee cleans) logs; 0x4690b0 (THISCALL, no arguments) is a stub by address; the
argument block at c is 12 random bytes."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen_427d90(c):
    rv = -1 if c.rng.random() < 0.3 else c.rng.getrandbits(32)

    def h(e, r):
        e.calllog.append(('import 0x676068 (stub)', 0x676068, None, tuple(e.arg32(i) for i in range(7))))
        e.ret(eax=rv & 0xffffffff, argbytes=28)
    c.emu.w32(0x676068, c.emu.stub_fn('batch104 import', h))
    return [c.rng.getrandbits(32)]


def _gen_43e810(c):
    def h74(e, r):
        e.calllog.append(('this vtable +0x74 (stub)', 0x74, e.reg('ecx'), (e.arg32(0), e.arg32(1))))
        e.ret(eax=0, argbytes=8)
    vt = c.emu.fake_vtable('batch105 self', 0x74 // 4 + 1, slots={0x74: h74})
    self = _rnd(c, 0x80)
    c.emu.w32(self, vt)
    c.emu.w8(self + 0x18, c.rng.getrandbits(8))
    other = _rnd(c, 0x40)
    c.emu.w32(self + 8, other)

    def h469(e, r):
        e.calllog.append(('0x4690b0 (GUESS stub)', 0x4690b0, e.reg('ecx'), ()))
        e.ret(eax=0, argbytes=0)
    c.emu.hook(0x4690b0, h469)
    cblock = _rnd(c, 12)
    return [self, c.rng.getrandbits(32), c.rng.getrandbits(32), cblock, c.rng.getrandbits(32)]


S(0x427d90, 'GUESS FUN_00427d90 (import pointer 0x676068 with seven arguments; -1 becomes 0)', 'stdcall', None, ret='eax',
  gen=_gen_427d90, note='slice-5 batch 1973 (104); import pointer stub')
S(0x43e810, 'GUESS FUN_0043e810 (flag 2: vtable +0x74, copy three words, store d, 0x4690b0)', 'thiscall', None, ret=None,
  gen=_gen_43e810, note='slice-5 batch 1973 (105); 0x4690b0 GUESS stub')
