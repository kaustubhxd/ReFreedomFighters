"""specs_s321.py - gap band, batch 321: two forwarders (thiscall, two stack arguments). The object at this+0x14 (60ef50) or this+0x2c
(60ef80) has a vtable whose slot 0x2c is a stdcall stub (obj, a, b, &out, 0x1000). The stub writes out (chosen per run) and logs
the arguments with the out pointer replaced by the value written."""
from pilot import S


def _gen_for(off):
    def gen(c):
        e = c.emu
        rng = c.rng
        outv = rng.getrandbits(32)

        def h(em, r):
            a = [em.arg32(k) for k in range(5)]
            em.w32(a[3], outv)
            em.calllog.append(('slot2c321', 0x2c, None, (a[0], a[1], a[2], ('out', outv), a[4])))
            em.ret(eax=0, argbytes=20)

        obj = e.alloc(0x40, 4)
        e.w32(obj, e.fake_vtable('obj321', 0x40, {0x2c: h}))
        self_ = e.alloc(0x60, 4)
        e.wbytes(self_, bytes(rng.getrandbits(8) for _ in range(0x60)))
        e.w32(self_ + off, obj)
        return [self_, rng.getrandbits(32), rng.getrandbits(32)]
    return gen


S(0x60ef50, 'fwd60ef50 (GUESS)', 'thiscall', None, ret='eax', gen=_gen_for(0x14), note='batch321; ret 8; slot 0x2c stubbed')
S(0x60ef80, 'fwd60ef80 (GUESS)', 'thiscall', None, ret='eax', gen=_gen_for(0x2c), note='batch321; ret 8; slot 0x2c stubbed')
