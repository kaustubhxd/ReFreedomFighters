"""specs_s934.py - unclaimed-09 batch 26 (docs/20-unclaimed-09.md, claim 28): ZPlayer::CopyDataBlock(DBLK*).

The ZPlayer object is 0x1000 random bytes (the dword at +0x60e lies well inside). Its vtable: slot 0x40 (logs) and slot
0x20 (returns o, a 0x40-byte object whose +8 is a sub-object). The block d is 0x40 random bytes. Hooks (unverified
callees, each logs its ecx and arguments): 0x473370 (one argument, the block); 0x4e1600 (returns a byte: 0xb in about one
case in three, so the branch runs); 0x4e12e0 (two arguments); 0x4e1b30 (no arguments); 0x4dc630 (two arguments, called
twice). Each hook returns with ret matching the argument count, as the original callee is assumed to do."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    e = c.emu
    rng = c.rng
    al = 0xb if rng.random() < 0.34 else rng.getrandbits(8)

    def h473370(e2, r):
        e2.calllog.append(('B473370', e2.reg('ecx'), e2.arg32(0)))
        e2.ret(argbytes=4)

    def h1600(e2, r):
        e2.calllog.append(('E1600', e2.reg('ecx')))
        e2.ret(eax=al, argbytes=0)

    def h12e0(e2, r):
        e2.calllog.append(('E12e0', e2.reg('ecx'), e2.arg32(0), e2.arg32(1)))
        e2.ret(argbytes=8)

    def h1b30(e2, r):
        e2.calllog.append(('E1b30', e2.reg('ecx')))
        e2.ret(argbytes=0)

    def hdc630(e2, r):
        e2.calllog.append(('Dc630', e2.reg('ecx'), e2.arg32(0), e2.arg32(1)))
        e2.ret(argbytes=8)

    for addr, h in ((0x473370, h473370), (0x4e1600, h1600), (0x4e12e0, h12e0), (0x4e1b30, h1b30), (0x4dc630, hdc630)):
        e.hook(addr, h)

    def hvt40(e2, r):
        e2.calllog.append(('Vt40',))
        e2.ret(argbytes=0)

    def hvt20(e2, r):
        e2.calllog.append(('Vt20',))
        e2.ret(eax=o, argbytes=0)

    sub = _rnd(c, 0x40)
    o = e.fake_object('playerblk_o', 0x40, slots={})
    e.w32(o + 8, sub)
    player = e.fake_object('playerblk_player', 0x1000, slots={0x40: hvt40, 0x20: hvt20})
    e.wbytes(player + 4, bytes(rng.getrandbits(8) for _ in range(0x1000 - 4)))
    e.w32(player + 8, _rnd(c, 0x40))
    d = _rnd(c, 0x40)
    return [player, d]


S(0x482800, 'ZPlayer::CopyDataBlock (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-09 b26; five exe callees hooked, ZPlayer vtable slots 0x20/0x40 stubbed (unverified callees)')
