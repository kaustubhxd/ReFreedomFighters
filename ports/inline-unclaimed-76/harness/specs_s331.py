"""specs_s331.py - gap band, batch 331: 0x61cb70 (cdecl, one argument). The object's +0xc is a cdecl stub returning a buffer (or 0) and
logging its argument. The emitter 0x61cbe0 is hooked by address (recorded: its five arguments with the cursor cells read back)."""
import struct
from pilot import S


def _rec(em, r):
    # 0x61cbe0 (cdecl, five arguments): recorded by address; the two cursor cells are logged as the values they hold
    a = [em.arg32(k) for k in range(5)]
    cur = struct.unpack('<I', bytes(em.mu.mem_read(a[4], 4)))[0]
    base = struct.unpack('<I', bytes(em.mu.mem_read(a[3], 4)))[0]
    em.calllog.append(('h61cbe0', 0, None, (a[0], a[1], a[2], ('base', base), ('cur', cur))))
    em.ret(eax=0, argbytes=0)


def _gen(c):
    e = c.emu
    rng = c.rng
    e.hook(0x61cbe0, _rec)
    buf = e.alloc(0x200, 4)
    e.wbytes(buf, rng.randbytes(0x200))
    rv = buf if rng.random() < 0.8 else 0

    def stub(em, r):
        em.calllog.append(('cb', 0xc, None, (em.arg32(0),)))
        em.ret(eax=rv, argbytes=0)

    vt = e.fake_vtable('cb331', 0x10, {0: stub})
    A = e.alloc(0x200, 4)
    e.wbytes(A, rng.randbytes(0x200))
    e.w32(A + 0xc, vt)     # not used as a function pointer: the stub address is read from the vtable below
    fn = struct.unpack('<I', bytes(e.rbytes(vt, 4)))[0]
    e.w32(A + 0xc, fn)
    e.w32(A + 0x1f4, rng.randrange(0, 4))
    table = e.alloc(0x400, 4)
    e.wbytes(table, rng.randbytes(0x400))
    e.w32(A + 0x1ec, table)
    return [A]


S(0x61cb70, 'build61cb70 (GUESS)', 'cdecl', None, ret='eax', gen=_gen, note='batch331; plain ret; emitter 0x61cbe0 hooked')
