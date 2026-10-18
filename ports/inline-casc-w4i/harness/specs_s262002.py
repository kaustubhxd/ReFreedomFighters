"""specs_s262002.py - Sonnet-w4i hand specs."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub, seh_record, seh_chain
import zlib


def g420fd0(c):
    clear_hooks(c)
    r = c.rng
    em = c.emu
    DEST = rnd(c, 0x40)
    def keyname(emu, k):
        buf = emu.arg32(1)
        emu.calllog.append(('kn', emu.arg32(0), emu.arg32(2)))
        n = r.randrange(1, 0x30)
        emu.wbytes(buf, bytes(r.randrange(1, 256) for _ in range(n)) + b'\0')
    em.w32(0x6761a8, pystub(c, 3, ret=lambda emu, k: r.choice([0, 1, 5]), stackmark=(1,), side=keyname))
    em.w32(0x67609c, pystub(c, 0, ret=lambda emu, k: r.getrandbits(32)))
    # stack buffer: log content up to NUL; the pointer itself is only compared when it is an exe constant
    def side2(emu, k):
        p = emu.arg32(0)
        data = emu.rbytes(p, 0x64)
        emu.calllog.append(('s', data.split(b'\0')[0], p if 0x400000 <= p < 0x800000 else 0))
    hook_rec(c, 0x4cbe80, 1, ret=lambda emu, k: r.getrandbits(32), pop=4, this=True, stackmark=(0,), side=side2)
    code = r.choice([0xfd, 0xfe, 0xff, 0x1c, 0x39, 0x100, r.getrandbits(8), r.getrandbits(16)])
    return [DEST, code]


S(0x420fd0, 'hand key name text', 'stdcall', None, ret='eax', gen=g420fd0, note='batch262002')
