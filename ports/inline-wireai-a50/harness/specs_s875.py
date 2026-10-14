"""specs_s875.py - area 50, batch 875: 0x5ffd10 (GUESS name), thiscall, one stack arg (a 16-bit key), ret 4, int result.
The table (count at +8, pointer at +0xc) is a generated dword array; the base key is a word at +0; the logger (0x700390) and its sink
are fake and logged; the assert hook is a logged stub (the exe traps on a null hook), so eax is the stub's result on the failure path."""
from pilot import S
from anim_common import only_hooks, rnd


def _gen(c):
    e, r = c.emu, c.rng
    only_hooks(c, {})
    n = r.randint(0, 8)
    tab = rnd(c, 4 * max(n, 1))
    for i in range(n):
        e.w32(tab + 4 * i, r.getrandbits(32))
    self = rnd(c, 0x40)
    e.w16(self + 0, r.randint(0, 60000))
    e.w32(self + 8, n)
    e.w32(self + 0xc, tab)
    e.w32(self + 0x10, r.getrandbits(32))
    hookstub_addr = e.stub_fn('assert_hook', lambda e, rr: (e.calllog.append(('assert.hook',)), e.ret(eax=0, argbytes=0)))
    e.w32(0x7003b0, hookstub_addr)

    def l20(e, rr):
        e.calllog.append(('log.20', e.arg32(0), e.arg32(1)))
        e.ret(eax=sink, argbytes=8)

    def s2c(e, rr):
        e.calllog.append(('sink.2c', e.arg32(1), e.arg32(2)))
        e.ret(eax=0, argbytes=0)

    sink = e.fake_object('sink', 0x10, nslots=0x20, slots={0x2c: s2c})
    logger = e.fake_object('logger', 0x10, nslots=9, slots={0x20: l20})
    e.w32(0x700390, logger)
    base = int.from_bytes(e.rbytes(self, 2), 'little')
    key = r.choice([r.randint(0, 65535), (base + r.randint(0, max(n, 1))) & 0xffff])
    return [self, key]


S(0x5ffd10, 'Lookup5ffd10 (GUESS name)', 'thiscall', None, ret='eax', gen=_gen, note='area50 batch875')
