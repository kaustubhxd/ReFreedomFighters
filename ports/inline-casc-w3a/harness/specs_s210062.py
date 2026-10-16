"""specs_s210062.py - Sonnet-w3a: 0x4831d0. Flags at this+0x417 (unaligned) select the path; the manager slot 0x114 stub takes 5 args on the first path and 6 on the second (chosen from the flags at gen time), slot 0x4c is a custom stub (2 args then 1)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _r(c): return c.rng.getrandbits(32)


def _ub(c, a, v): c.emu.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))


def g4831d0(c):
    clear_hooks(c)
    e = c.emu
    flags = c.rng.choice([0, 0x800, 0x1000, 0x1800, 0x7ff, _r(c), _r(c) & ~0x1800])
    second = bool(flags & 0x1800)
    p = 0 if c.rng.random() < 0.2 else obj(c, 0x40, {0x128: pystub(c, 1, ret=_r(c), this=True)}, nslots=0x60)
    tgt = 0 if c.rng.random() < 0.2 else obj(c, 0x40, {0x128: pystub(c, 1, ret=_r(c), this=True)}, nslots=0x60)
    cnt = [0]
    ids = [_r(c), _r(c)]

    def s4c(emu, res):
        k = cnt[0]; cnt[0] += 1
        if k == 0:
            emu.calllog.append(('s4c', emu.reg('ecx'), emu.arg32(0) if emu.arg32(0) < 0x20000000 else 1, emu.arg32(1)))
            emu.ret(eax=ids[0], argbytes=8)
        else:
            emu.calllog.append(('s4c1', emu.reg('ecx'), emu.arg32(0)))
            emu.ret(eax=ids[1], argbytes=4)
    mg = obj(c, 0x40, {0x4c: e.stub_fn('s4c', s4c),
                       0x114: pystub(c, 6 if second else 5, ret=lambda emu, k: _r(c) if False else ids[0] ^ 0x12340000, this=True),
                       0x58: pystub(c, 1, ret=tgt, this=True)}, nslots=0x60)
    so = rnd(c, 0x200)
    e.wbytes(so + 0x9b, mg.to_bytes(4, 'little'))
    e.w32(0x70039c, so)
    s = obj(c, 0x440, {0x514: pystub(c, 0, ret=_r(c), this=True), 0x594: pystub(c, 1, ret=_r(c), this=True)}, nslots=0x180)
    _ub(c, s + 0x417, flags); _ub(c, s + 0x413, _r(c))
    return [s, p]


S(0x4831d0, 'toggle_pending_lookup', 'thiscall', None, ret=None, gen=g4831d0, note='batch210062')
