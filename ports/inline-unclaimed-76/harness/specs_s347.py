"""specs_s347.py - gap band, batch 347: 0x602d30 (cdecl, no arguments). Globals: 0x724694 (flag: nonzero returns it), 0x700390 (logger: slot
0x20 is a thiscall stub with two arguments, returns a report object; that object's slot 0x2c is a cdecl stub, recorded), 0x7003b0 (the callback:
a cdecl stub with no arguments, recorded without ECX, returns a per-run value)."""
from pilot import S


def _gen(c):
    e = c.emu
    rng = c.rng
    rv = rng.getrandbits(32)
    cbv = rng.getrandbits(32)

    def s2c(em, r):
        em.calllog.append(('rep2c', 0x2c, None, tuple(em.arg32(k) for k in range(3))))
        em.ret(eax=0, argbytes=0)

    rep = e.alloc(0x40, 4)
    e.w32(rep, e.fake_vtable('rep347', 0x40, {0x2c: s2c}))

    def s20(em, r):
        em.calllog.append(('log20', 0x20, em.reg('ecx'), (em.arg32(0), em.arg32(1))))
        em.ret(eax=rep, argbytes=8)

    lg = e.alloc(0x40, 4)
    e.w32(lg, e.fake_vtable('log347', 0x40, {0x20: s20}))
    e.w32(0x700390, lg)

    def cb(em, r):
        em.calllog.append(('callback347', 0, None, ()))
        em.ret(eax=cbv, argbytes=0)

    cbaddr = e.fake_vtable('cb347', 0x10, {0: cb})
    e.w32(0x7003b0, struct_u32(e, cbaddr))
    e.w32(0x724694, rng.choice([0, 0, rng.getrandbits(32) | 1]))
    return []


def struct_u32(e, addr):
    import struct
    return struct.unpack('<I', bytes(e.rbytes(addr, 4)))[0]


S(0x602d30, 'debugThunk602d30 (GUESS)', 'cdecl', None, ret='eax', gen=_gen, note='batch347; callback tail call as a plain call')
