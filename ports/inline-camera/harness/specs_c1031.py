"""specs_c1031.py - camera batch 1031: ZCamHelper::Load. The load object writes random data to each destination
(float / byte / vector / matrix / dword by slot) and logs each call; the manager resolves handles by slot 0x58."""
import struct
from pilot import S
from camgen import rnd, fbits, Log, handler, sys_with_mgr

SIZES = {0x50: 4, 0x68: 1, 0x6c: 12, 0x74: 36, 0x40: 4, 0x44: 4}


def _ld(c):
    r = c.rng
    log = Log(c, 1024)

    def mk(slot):
        def h(e, res):
            a = e.arg32(0)
            log.put(slot, a - 0 if False else 0)  # the destination address differs by frame layout: log the slot only
            if slot == 0x50:
                e.w32(a, fbits(c))
            else:
                e.wbytes(a, bytes(r.getrandbits(8) for _ in range(SIZES[slot])))
            e.ret(argbytes=4)
        return h
    lg = c.emu.fake_object('lg', 0x10, slots={s: mk(s) for s in SIZES})
    self_ = rnd(c, 0xf00)
    s = sys_with_mgr(c, 0x100)
    m = c.emu.fake_object('mgr', 0x140, slots={0x58: handler(log, 0x58, 1, eax=lambda e: r.getrandbits(32))})
    c.emu.w32(s + 0x9b, m)
    return [self_, lg]


S(0x5d0600, 'ZCamHelper::Load', 'thiscall', ret='al', gen=_ld)
