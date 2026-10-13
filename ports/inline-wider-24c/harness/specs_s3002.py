"""specs_s3002.py - unclaimed-30 batch 2 (docs/20-unclaimed-30.md, claim 1): ZGEOM::DeactivateEvents (0x45d9d0). The gate
(0x4da3a0, exe code) reads this+8 -> +0x54 -> +0x10 -> +8, so the chain is built valid. The inner list has a begin (+0x4c),
next (+0x5c) and remove (+0x44); the allocator's slot 0xcc (logged) returns 0 or an object for each element; this's slot
0x120 is logged. Every call is logged, so the call sequence is compared as well."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S


def _obj(c, n):
    a = c.emu.alloc(n)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _deact(c):
    e = c.emu
    r = c.rng
    n = r.randint(0, 4)
    elems = [r.getrandbits(32) | 1 for _ in range(n)]
    pick_res = [r.random() < 0.6 for _ in range(16)]
    res_vals = [r.getrandbits(32) | 1 for _ in range(16)]

    def log(em, name, off, extra=None):
        em.calllog.append((name, off) + (tuple(extra) if extra else ()))

    # the inner list: begin, next, remove
    def begin(em, rr):
        em.w32(em.arg32(0) + 4, 0)
        log(em, 'list', 0x4c)
        em.ret(argbytes=4)

    def nxt(em, rr):
        it = em.arg32(0)
        idx = em.r32(it + 4)
        valid = 1 if idx < n else 0
        em.w32(it, valid)
        em.w32(it + 4, idx + 1)
        log(em, 'list', 0x5c)
        em.ret(eax=elems[idx] if valid else 0, argbytes=4)

    def remove(em, rr):
        log(em, 'list', 0x44)
        em.ret(argbytes=4)
    lvt = e.fake_vtable('deact_list', 0x20, {0x44: remove, 0x4c: begin, 0x5c: nxt})
    ilist = _obj(c, 0x20)
    e.w32(ilist, lvt)
    # the owner chain: this+0x10 -> list holder (+8 = ilist); this+8 -> object (+0x54 -> (+0x10 -> (+8 non-zero)))
    holder = _obj(c, 0x20)
    e.w32(holder + 8, ilist)
    gate = _obj(c, 0x80)
    z = _obj(c, 0x20)
    e.w32(z + 8, 1)
    y = _obj(c, 0x40)
    e.w32(y + 0x10, z)
    e.w32(gate + 0x54, y)
    geom = _obj(c, 0x100)
    e.w32(geom + 8, gate)
    e.w32(geom + 0x10, holder)

    # this's slot 0x120 (two args, logged)
    def virt(em, rr):
        log(em, 'geom', 0x120, (em.arg32(0), em.arg32(1)))
        em.ret(argbytes=8)
    gvt = e.fake_vtable('deact_geom', 0x60, {0x120: virt})
    e.w32(geom, gvt)

    # the allocator: slot 0xcc (one arg) returns an object or 0; logged
    def cc(em, rr):
        k = len([t for t in em.calllog if t[0] == 'alloc' and len(t) > 1 and t[1] == 0xcc])
        em.calllog.append(('alloc', 0xcc))
        em.ret(eax=res_vals[k % 16] if pick_res[k % 16] else 0, argbytes=4)
    avt = e.fake_vtable('deact_alloc', 0x40, {0xcc: cc})
    alloc = _obj(c, 0x10)
    e.w32(alloc, avt)
    e.w32(0x70038c, alloc)

    flag = r.choice([0, 1, 1, 0x12345678])
    return [geom, flag]


S(0x45d9d0, 'ZGEOM::DeactivateEvents', 'thiscall', None, gen=_deact)
