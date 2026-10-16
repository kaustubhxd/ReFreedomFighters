"""specs_s210043.py - Sonnet-w3a: stream reader with stack out-params and engine lookups; slots log the written values."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _r(c): return c.rng.getrandbits(32)


def _ub(c, a, v): c.emu.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))


def g5eb530(c):
    clear_hooks(c)

    def out(emu, k):
        v = c.rng.getrandbits(32)
        emu.w32(emu.arg32(0), v)
        emu.calllog.append(('out', k, v))
    a = obj(c, 0x40, {0x40: pystub(c, 1, ret=_r(c), this=True, stackmark=(0,), side=out),
                      0x48: pystub(c, 1, ret=_r(c), this=True, stackmark=(0,), side=out),
                      0x50: pystub(c, 1, ret=_r(c), this=True), 0x68: pystub(c, 1, ret=_r(c), this=True),
                      0x18: pystub(c, 2, ret=_r(c), this=True)}, nslots=0x20)
    mg = obj(c, 0x60, {0x58: pystub(c, 1, ret=lambda e, k: c.rng.getrandbits(32), this=True)}, nslots=0x20)
    c.emu.w32(mg + 0x44, _r(c))
    eng = rnd(c, 0x100); _ub(c, eng + 0x9b, mg)
    c.emu.w32(0x70039c, eng)
    return [rnd(c, 0x60), a]


S(0x5eb530, 'read_stream_outparams', 'thiscall', None, ret='eax', gen=g5eb530, note='batch210043')
