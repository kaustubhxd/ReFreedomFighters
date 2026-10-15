"""specs_s35201.py - 0x5b6b70 (thiscall, no args, ret=None, nan_heap). Engine (sysobj): floats +0x9c7 / +0x9c3 (unaligned; each zero in 1/3), slot 0x1c8 (Python handler returning a 64-bit value in EDX:EAX), slots 0x178 / 0x17c (3 args recorded).
this: 0x80 random bytes with [+0x48] = collection (null in 1/5; reftab_vt iterator stubs, destructor and remove-current recorded) of 0..3 entries; entry e: 0x40 random bytes, [e+4] = sub-collection of 0..3 dummy items (null in 1/3), [e+8] = object with destructor slot 0 (null in 1/3). 0x5b5d60 (al true in 1/2), 0x5b6110 (1 arg), 0x5b7420 hooked."""
import struct
from pilot import S
from pe_emu import REGS
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub, sysobj, reftab_vt


def _fb(v):
    return struct.unpack('<I', struct.pack('<f', v))[0]


def _g5b6b70(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    so = sysobj(c, table_size=0x20)
    for off in (0x9c7, 0x9c3):
        e.wbytes(so + off, (0 if r.random() < 1 / 3 else _fb(c.fv(-5, 5) if True else 1.0)).to_bytes(4, 'little'))
    ts = r.getrandbits(64)

    def h1c8(em, res_):
        em.calllog.append(('1c8', em.reg('ecx'), em.arg32(0), em.arg32(1)))
        em.mu.reg_write(REGS['edx'], ts >> 32)
        em.ret(eax=ts & 0xffffffff, argbytes=8)
    vt = e.r32(so)
    e.w32(vt + 0x1c8, e.stub_fn('1c8', h1c8))
    e.w32(vt + 0x178, pystub(c, 3, this=True))
    e.w32(vt + 0x17c, pystub(c, 3, this=True))
    entries = []
    for _ in range(r.choice([0, 1, 2, 3])):
        ent = rnd(c, 0x40)
        if r.random() < 2 / 3:
            coll = rnd(c, 0x20)
            e.w32(coll, reftab_vt(c, [rnd(c, 0x10) for _ in range(r.choice([0, 1, 2, 3]))]))
            e.w32(ent + 4, coll)
        else:
            e.w32(ent + 4, 0)
        if r.random() < 2 / 3:
            e.w32(ent + 8, obj(c, 0x20, {0: pystub(c, 1, this=True)}, nslots=0x10))
        else:
            e.w32(ent + 8, 0)
        entries.append(ent)
    me = rnd(c, 0x80)
    if r.random() < 1 / 5:
        e.w32(me + 0x48, 0)
    else:
        mainc = rnd(c, 0x20)
        e.w32(mainc, reftab_vt(c, entries))
        e.w32(me + 0x48, mainc)
    hook_rec(c, 0x5b5d60, 1, this=True, pop=4, ret=lambda em, k: (r.getrandbits(24) << 8) | 1 if r.random() < 0.5 else (r.getrandbits(24) << 8))
    hook_rec(c, 0x5b6110, 1, this=True, pop=4)
    hook_rec(c, 0x5b7420, 0, this=True, pop=0)
    return [me]


S(0x5b6b70, 'GUESS per-frame update of effect list', 'thiscall', None, ret=None, gen=_g5b6b70, nan_heap=True, note='batch35201')
