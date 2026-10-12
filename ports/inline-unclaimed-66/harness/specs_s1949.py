"""specs_s1949.py - unclaimed-66 batches 50 to 52 (gap band, GUESS names). STDCALL with one unread argument, ret 4.

Each routine: memset of a 0xc8-byte global buffer (CRT 0x634d10, a memset stub hooked by address: the original calls an import thunk), a flag word cleared, then the object global (random
set or 0) gets vtable +0 called with 1 (a logging stub), and the object global is cleared. The three globals are 0x7011fc, 0x70139c, 0x7014b4."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _memset_hook(c):
    def hmem(e, r):
        d, cv, n = e.arg32(0), e.arg32(1), e.arg32(2)
        e.calllog.append(('CRT memset 0x634d10 (stub)', 0x634d10, None, (d, cv, n)))
        e.wbytes(d, bytes([cv & 0xff]) * n)
        e.ret(eax=d, argbytes=0)
    c.emu.hook(0x634d10, hmem)


def _rel(c, glob, flag, buf):
    _memset_hook(c)
    flag_val = c.rng.getrandbits(32)
    c.emu.w32(flag, flag_val)
    c.emu.wbytes(buf, bytes(c.rng.getrandbits(8) for _ in range(0xc8)))
    if c.rng.random() < 0.3:
        obj = 0
    else:
        def h0(e, r):
            e.calllog.append(('release object vtable +0 (stub)', 0, e.reg('ecx'), (e.arg32(0),)))
            e.ret(eax=0, argbytes=4)
        vt = c.emu.fake_vtable('release obj', 1, slots={0: h0})
        obj = c.emu.fake_object('release obj', 0x40, vtable=vt)
    c.emu.w32(glob, obj)
    return [c.rng.getrandbits(32)]


def _rel50b4d0(c):
    return _rel(c, 0x7011fc, 0x7011f8, 0x701200)


def _rel510b90(c):
    return _rel(c, 0x70139c, 0x701398, 0x7013a0)


def _rel511720(c):
    return _rel(c, 0x7014b4, 0x7014b0, 0x7014b8)


S(0x50b4d0, 'GUESS FUN_0050b4d0 (memset 0x701200, release global 0x7011fc)', 'stdcall', None, ret=None, gen=_rel50b4d0,
  note='unclaimed-66 batch 1949; gap band; memset stub at 0x634d10 by address')
S(0x510b90, 'GUESS FUN_00510b90 (memset 0x7013a0, release global 0x70139c)', 'stdcall', None, ret=None, gen=_rel510b90,
  note='unclaimed-66 batch 1949; gap band; memset stub at 0x634d10 by address')
S(0x511720, 'GUESS FUN_00511720 (memset 0x7014b8, release global 0x7014b4)', 'stdcall', None, ret=None, gen=_rel511720,
  note='unclaimed-66 batch 1949; gap band; memset stub at 0x634d10 by address')
