"""specs_c1080.py - camera batch 1080: ZCameraOverlay::ClassInit (0x457c30).

The operator new (0x41e290) returns two blocks prepared here: the 8-byte header (for the size 8 request) and the count * 0x44
array (for the other request). The global manager (sys +0x1aa3) has an object at +0x18 whose slot 0xf8 returns a record (or 0).
The counts are small, so the arrays are small."""
from pilot import S
from camgen import rnd, Log, sys_with_mgr


def _ci(c):
    r = c.rng
    self_ = rnd(c, 0x100)
    obj = rnd(c, 0x80)
    c.emu.w32(self_ + 8, obj)
    c.emu.w32(obj + 0x6c, r.getrandbits(32))
    n88 = r.randint(0, 3)
    n8c = r.randint(0, 3)
    c.emu.w32(self_ + 0x88, n88)
    c.emu.w32(self_ + 0x8c, n8c)
    count = n88 * n8c
    hdr = rnd(c, 0x10)
    arr = rnd(c, 0x44 * count + 0x10)
    rec = 0
    if r.random() < 0.8:
        rec = rnd(c, 0x20)
        c.emu.w8(rec + 0xc, r.getrandbits(8))
        c.emu.w8(rec + 0xd, r.getrandbits(8))
        c.emu.w8(rec + 0xe, r.getrandbits(8))
        c.emu.w8(rec + 0xf, r.getrandbits(8))
    log = Log(c, 64)

    def new(e, res):
        log.put(0x41e290, e.arg32(0))
        e.ret(eax=hdr if e.arg32(0) == 8 else arr, argbytes=0)

    c.emu.hook(0x41e290, new)
    sub = rnd(c, 0x40)
    c.emu.w32(sub, c.emu.fake_vtable('sub', 0xfc // 4, {
        0xf8: lambda e, res: (log.put(0xf8, e.arg32(0)), e.ret(eax=rec, argbytes=4)),
    }))
    s = sys_with_mgr(c, 0x2000)
    m = rnd(c, 0x40)
    c.emu.w32(m + 0x18, sub)
    c.emu.w32(s + 0x1aa3, m)
    return [self_]


S(0x457c30, 'ZCameraOverlay::ClassInit', 'thiscall', gen=_ci)
