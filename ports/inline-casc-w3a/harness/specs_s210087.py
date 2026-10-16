"""specs_s210087.py - Sonnet-w3a: 0x5bda50. Manager slot 0x4c is a custom stub: with this[0x74] set its first call takes 1 argument (callee pops 4), every other call takes 2 (pops 8); targets' slots 0x130 (3 args) / 0x128 (2 args) are recorders."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _r(c): return c.rng.getrandbits(32)


def g5bda50(c):
    clear_hooks(c)
    e = c.emu
    flag = c.rng.choice([0, 1, 1, 2])
    cnt = [0]
    ids = [_r(c) for _ in range(3)]

    def s4c(emu, res):
        k = cnt[0]; cnt[0] += 1
        one = bool(flag) and k == 0
        if one:
            emu.calllog.append(('s4c1', emu.reg('ecx'), emu.arg32(0)))
            emu.ret(eax=ids[0], argbytes=4)
        else:
            emu.calllog.append(('s4c2', emu.reg('ecx'), emu.arg32(0), emu.arg32(1)))
            emu.ret(eax=ids[min(k, 2)], argbytes=8)
    t = obj(c, 0x40, {0x130: pystub(c, 3, ret=_r(c), this=True), 0x128: pystub(c, 2, ret=_r(c), this=True)}, nslots=0x60)
    o = 0 if c.rng.random() < 0.3 else obj(c, 0x40, {0x128: pystub(c, 2, ret=_r(c), this=True)}, nslots=0x60)
    mg = obj(c, 0x40, {0x4c: e.stub_fn('s4c', s4c), 0x58: pystub(c, 1, ret=o, this=True)}, nslots=0x30)
    so = rnd(c, 0x200)
    e.wbytes(so + 0x9b, mg.to_bytes(4, 'little'))
    e.w32(0x70039c, so)
    s = rnd(c, 0x90)
    e.wbytes(s + 0x74, bytes([flag]))
    e.w32(s + 0x44, t)
    e.wbytes(s + 0x7d, _r(c).to_bytes(4, 'little'))
    return [s, _r(c), _r(c)]


S(0x5bda50, 'forward_command', 'thiscall', None, ret=None, gen=g5bda50, note='batch210087')
